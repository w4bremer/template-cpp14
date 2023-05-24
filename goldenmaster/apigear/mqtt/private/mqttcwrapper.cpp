#include <iostream>
#include "MQTTAsync.h"
#include "mqttcwrapper.h"
#include "../utilities/logger.h"
#include <chrono>
#include <random>
#include "mqttisink.h"

using namespace ApiGear::MQTT;
#define QOS         2

std::mt19937 randomNumberGenerator (std::random_device{}());

struct subscribeTopicContext {
    Topic topic;
    ISink* sink;
    CWrapper* client;
};

void onSendFailure(void* context, MQTTAsync_failureData5* response)
{
    CWrapper* client = static_cast<CWrapper*>(context);
    AG_LOG_ERROR("Send failed, ResponseCode " +  std::to_string(response->code));
}

void onSubscribeSuccess(void* context, MQTTAsync_successData5* response)
{
    subscribeTopicContext* ctx = static_cast<subscribeTopicContext*>(context);
    ctx->client->confirmSubscription(ctx->topic, *(ctx->sink));
    delete ctx;
}

void onSubscribeFailure(void* context, MQTTAsync_failureData5* response)
{
    subscribeTopicContext* ctx = static_cast<subscribeTopicContext*>(context);
    AG_LOG_ERROR("Subscribe failed, ResponseCode " +  std::to_string(response->code));
    delete ctx;
}

void onUnsubscribeSuccess(void* context, MQTTAsync_successData5* response)
{
    subscribeTopicContext* ctx = static_cast<subscribeTopicContext*>(context);
    ctx->client->removeSubscription(ctx->topic);
    delete ctx;
}

void onUnsubscribeFailure(void* context, MQTTAsync_failureData5* response)
{
    subscribeTopicContext* ctx = static_cast<subscribeTopicContext*>(context);
    AG_LOG_ERROR("Unsubscribe failed, ResponseCode " + std::to_string(response->code));
    delete ctx;
}

void onConnected(void* context, MQTTAsync_successData5* response)
{
    CWrapper* client = static_cast<CWrapper*>(context);
    client->onConnected();
}

void onConnectedFail(void* context,  MQTTAsync_failureData5* response)
{
    CWrapper* client = static_cast<CWrapper*>(context);
    AG_LOG_ERROR("Connect failed, ResponseCode " + std::to_string(response->code));
    client->onDisconnected();
}

void onDisconnected(void* context, MQTTAsync_successData5* response)
{
    CWrapper* client = static_cast<CWrapper*>(context);
    client->onDisconnected();
}


int OnMessageArrived(void *context, char *topicName, int topicLen, MQTTAsync_message *message)
{
    CWrapper* client = static_cast<CWrapper*>(context);
    Message mqtt_message {};
    mqtt_message.topic = Topic(std::string(topicName, topicLen));
    mqtt_message.content.assign(static_cast<char*>(message->payload), message->payloadlen);

    if(MQTTProperties_hasProperty(&(message->properties), MQTTPROPERTY_CODE_RESPONSE_TOPIC))
    {
        AG_LOG_INFO("response topic found");
        MQTTProperty* responseTopicProperty = MQTTProperties_getProperty(&(message->properties), MQTTPROPERTY_CODE_RESPONSE_TOPIC);
        mqtt_message.responseTopic = Topic(std::string(responseTopicProperty->value.data.data, responseTopicProperty->value.data.len));
    }

    if(MQTTProperties_hasProperty(&(message->properties), MQTTPROPERTY_CODE_CORRELATION_DATA))
    {
        AG_LOG_INFO("correlation data found");
        MQTTProperty* correlationDataProperty = MQTTProperties_getProperty(&(message->properties), MQTTPROPERTY_CODE_CORRELATION_DATA);
        mqtt_message.correlationData.assign(correlationDataProperty->value.data.data, correlationDataProperty->value.data.len);
    }

    MQTTAsync_freeMessage(&message);
    MQTTAsync_free(topicName);

    client->handleTextMessage(mqtt_message);

    return 1;
}

void OnConnectionLost(void *context, char *cause)
{
    CWrapper* client = static_cast<CWrapper*>(context);
    AG_LOG_ERROR("Connection lost");
    client->onDisconnected();
}

CWrapper::CWrapper(const std::string& clientID)
    : m_clientID(clientID)
    , m_client(nullptr)
    , m_disconnectRequested(false)
{
}

int CWrapper::subscribeToConnectionStatus(OnConnectionStatusChangedCallBackFunction callBack)
{
    auto randomId = 0;
    std::uniform_int_distribution<> distribution (0, 100000);
    m_onConnectionStatusChangedCallbacksMutex.lock();
    do {
        randomId = distribution(randomNumberGenerator);
    } while (m_onConnectionStatusChangedCallbacks.find(randomId) != m_onConnectionStatusChangedCallbacks.end());
    m_onConnectionStatusChangedCallbacks.insert(std::pair<int, OnConnectionStatusChangedCallBackFunction>(randomId, callBack));
    m_onConnectionStatusChangedCallbacksMutex.unlock();

    return randomId;
}

void CWrapper::unsubscribeToConnectionStatus(int subscriptionID)
{
    m_onConnectionStatusChangedCallbacksMutex.lock();
    if((m_onConnectionStatusChangedCallbacks.find(subscriptionID) != m_onConnectionStatusChangedCallbacks.end()))
    {
        m_onConnectionStatusChangedCallbacks.erase(subscriptionID);
    }
    m_onConnectionStatusChangedCallbacksMutex.unlock();
}

void CWrapper::run()
{
    do
    {
        std::unique_lock<std::mutex> lock{m_waitForWorkMutex};
        m_conditionVariable.wait(lock, [this]() { return !m_waitForWork; });
        m_waitForWork = true;
        lock.unlock();

        checkForNewSubscriptions();
        checkForOldSubscriptions();

    }
    while (m_connected && !m_disconnectRequested);

    unsubscribeAllTopics();
    waitForPendingMessages();
}

void CWrapper::checkForNewSubscriptions()
{
    m_toBeSubscribedTopicsMutex.lock();
    const auto toBeSubscribedTopics(std::move(m_toBeSubscribedTopics));
    m_toBeSubscribedTopics.clear();
    m_toBeSubscribedTopicsMutex.unlock();
    for (const auto& topic : toBeSubscribedTopics) {
        subscribeTopicContext* ctx = new subscribeTopicContext{topic.first, topic.second, this};

        MQTTAsync_responseOptions opts = MQTTAsync_responseOptions_initializer;
        opts.onSuccess5 = onSubscribeSuccess;
        opts.onFailure5 = onSubscribeFailure;
        opts.context = ctx;
        int responseCode = MQTTAsync_subscribe(*m_client.get(), topic.first.getEncodedTopic().c_str(), QOS, &opts);
        if (responseCode != MQTTASYNC_SUCCESS)
        {
            AG_LOG_ERROR("Failed to start subscribe, return code " + std::to_string(responseCode));
        }
    }
}

void CWrapper::checkForOldSubscriptions()
{
    m_toBeUnsubscribedTopicsMutex.lock();
    const auto toBeUnsubscribedTopics(std::move(m_toBeUnsubscribedTopics));
    m_toBeUnsubscribedTopics.clear();
    m_toBeUnsubscribedTopicsMutex.unlock();
    for (const auto& topic : toBeUnsubscribedTopics) {
        AG_LOG_INFO("Unsubscribing from " + topic.first.getEncodedTopic());

        subscribeTopicContext* ctx = new subscribeTopicContext{topic.first, topic.second, this};

        MQTTAsync_responseOptions opts = MQTTAsync_responseOptions_initializer;
        opts.onSuccess5 = onUnsubscribeSuccess;
        opts.onFailure5 = onUnsubscribeFailure;
        opts.context = ctx;
        int responseCode = MQTTAsync_unsubscribe(*m_client.get(), topic.first.getEncodedTopic().c_str(), &opts);
        if (responseCode != MQTTASYNC_SUCCESS)
        {
            AG_LOG_WARNING("Failed to start unsubscribe, return code " + std::to_string(responseCode));
        }
    }
}

void CWrapper::unsubscribeAllTopics()
{
    if(!m_connected)
    {
        return;
    }

    // unsubscribe from all topics
    m_subscribedTopicsMutex.lock();
    const auto subscribedTopics { m_subscribedTopics };
    m_subscribedTopicsMutex.unlock();
    for (const auto& topic : subscribedTopics) {
        AG_LOG_INFO("Unsubscribing from " + topic.first.getEncodedTopic());

        subscribeTopicContext* ctx = new subscribeTopicContext{topic.first, topic.second, this};

        MQTTAsync_responseOptions opts = MQTTAsync_responseOptions_initializer;
        opts.onSuccess5 = onUnsubscribeSuccess;
        opts.onFailure5 = onUnsubscribeFailure;
        opts.context = ctx;
        int responseCode = MQTTAsync_unsubscribe(*m_client.get(), topic.first.getEncodedTopic().c_str(), &opts);
        if (responseCode != MQTTASYNC_SUCCESS)
        {
            AG_LOG_WARNING("Failed to start unsubscribe, return code " + std::to_string(responseCode));
        }
    }
}

void CWrapper::waitForPendingMessages()
{
    // wait for unsubscription to complete
    while(true && m_connected)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(10));

        std::lock_guard<std::mutex> guard(m_subscribedTopicsMutex);
        if(m_subscribedTopics.empty())
        {
            break;
        }
    }
}

void CWrapper::connectToHost(const std::string& brokerURL)
{
    static bool connecting = false;

    if(brokerURL.empty()) {
        m_serverUrl = "tcp://localhost:1883";
    } else {
        m_serverUrl = brokerURL;
    }
    AG_LOG_DEBUG("Connecting to host " + m_serverUrl);
    
    if(m_client == nullptr && !connecting) {
        try {
            connecting = true;

            m_client = std::make_unique<MQTTAsync>();
            MQTTAsync_createOptions create_opts = MQTTAsync_createOptions_initializer5;
            MQTTAsync_createWithOptions(m_client.get(), m_serverUrl.c_str(), m_clientID.c_str(), MQTTCLIENT_PERSISTENCE_NONE, NULL, &create_opts);

            MQTTAsync_connectOptions conn_opts = MQTTAsync_connectOptions_initializer5;
            conn_opts.keepAliveInterval = 20;
            conn_opts.onSuccess5 = ::onConnected;
            conn_opts.onFailure5 = onConnectedFail;
            conn_opts.context = this;

            MQTTAsync_setCallbacks(*m_client.get(), this, OnConnectionLost, OnMessageArrived, NULL);
            int responseCode = MQTTAsync_connect(*m_client.get(), &conn_opts);
            if (responseCode != MQTTASYNC_SUCCESS)
            {
                AG_LOG_ERROR("Failed to connect, return code " + std::to_string(responseCode));
                connecting = false;
                MQTTAsync_destroy(m_client.get());
                m_client.reset();
                return;
            }

        } catch (std::exception &e) {
            m_client = nullptr;
            AG_LOG_ERROR("Exception " + std::string(e.what()));
        }
        connecting = false;
    }
}

void CWrapper::disconnect() {
    m_disconnectRequested = true;
    if (m_thread.joinable())
    {
        {
            std::lock_guard<std::mutex> l{m_waitForWorkMutex};
            m_waitForWork = false;
        }
        m_conditionVariable.notify_one();
        m_thread.join();
    }
    MQTTAsync_disconnectOptions disconn_opts = MQTTAsync_disconnectOptions_initializer5;
    disconn_opts.onSuccess5 = ::onDisconnected;
    disconn_opts.context = this;
    disconn_opts.timeout = 10;
    MQTTAsync_disconnect(*m_client.get(), &disconn_opts);
    m_onConnectionStatusChangedCallbacksMutex.lock();
    auto onConnectionStatusChangedCallbacks(std::move(m_onConnectionStatusChangedCallbacks));
    m_onConnectionStatusChangedCallbacks.clear();
    m_onConnectionStatusChangedCallbacksMutex.unlock();
    for (auto& callback: onConnectionStatusChangedCallbacks){
        callback.second(false);
    }
}

void CWrapper::onConnected()
{
    m_connected = true;
    AG_LOG_DEBUG("socket connected");
    m_onConnectionStatusChangedCallbacksMutex.lock();
    auto onConnectionStatusChangedCallbacks { m_onConnectionStatusChangedCallbacks };
    m_onConnectionStatusChangedCallbacksMutex.unlock();
    for (auto& callback: onConnectionStatusChangedCallbacks){
        callback.second(true);
    }
    m_thread = std::thread(&CWrapper::run, this);
}

void CWrapper::onDisconnected()
{
    m_connected = false;
    bool disconnectRequested = m_disconnectRequested;
    m_disconnectRequested = false;
    AG_LOG_DEBUG("socket disconnected");

    // if we have not waited for our thread to finish, do it now
    if (m_thread.joinable())
    {
        {
            std::lock_guard<std::mutex> l{m_waitForWorkMutex};
            m_waitForWork = false;
        }
        m_conditionVariable.notify_one();
        m_thread.join();
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::thread([this, disconnectRequested](){
        // we need to destroy the client outside of its own calling thread
        MQTTAsync_destroy(m_client.get());
        m_client.reset();

        // reconnect if the connection was not dropped intentionally by us
        if(!disconnectRequested)
        {
            // we need to re-subscribe to all topics on re-connection
            m_subscribedTopicsMutex.lock();
            m_toBeSubscribedTopicsMutex.lock();
            if(!m_subscribedTopics.empty())
            {
                m_subscribedTopics.insert(m_toBeSubscribedTopics.begin(),m_toBeSubscribedTopics.end());
                m_toBeSubscribedTopics = m_subscribedTopics;
                m_subscribedTopics.clear();
            }
            m_toBeSubscribedTopicsMutex.unlock();
            m_subscribedTopicsMutex.unlock();

            connectToHost("");
        }
    }).detach();
}

void CWrapper::handleTextMessage(const Message& message)
{
    AG_LOG_INFO("new msg: topic " + message.topic.getEncodedTopic() + " msg content: " + message.content);
    std::pair<std::multimap<Topic, ISink*, Topic>::iterator, std::multimap<Topic, ISink*, Topic>::iterator> topics = m_subscribedTopics.equal_range(message.topic);
    for (auto iter = topics.first; iter != topics.second; ++iter)
    {
        if(iter->second != nullptr)
        {
            if(message.topic.getTopicType() == Topic::TopicType::Signal)
            {
                iter->second->onSignal(message.topic, message.content);
            }
            else if(message.topic.getTopicType() == Topic::TopicType::Property)
            {
                iter->second->onPropertyChanged(message.topic, message.content);
            }
            else if(message.topic.getTopicType() == Topic::TopicType::Operation)
            {
                iter->second->onInvoke(message.topic, message.content, message.responseTopic, message.correlationData);
            }
        }
        else
        {
            // call locally
            const int randomId = std::stoi(message.correlationData);
            InvokeReplyFunc func {};
            m_invokeResultsMutex.lock();
            if((m_invokeResults.find(randomId) != m_invokeResults.end()))
            {
                func = m_invokeResults[randomId];
                m_invokeResults.erase(randomId);
            }
            m_invokeResultsMutex.unlock();
            if(func) {
                const InvokeReplyArg arg{nlohmann::json::parse(message.content)};
                func(arg);
            }
        }
    }
}

void CWrapper::invokeRemote(const Topic& topic, const std::string& value, InvokeReplyFunc func)
{
    const std::string responseTopic = topic.getEncodedTopic() + "/" + m_clientID + "/result" ;

    MQTTAsync_responseOptions opts = MQTTAsync_responseOptions_initializer;
    MQTTAsync_message pubmsg = MQTTAsync_message_initializer;

    MQTTProperty responseTopicProperty;
    responseTopicProperty.identifier = MQTTPROPERTY_CODE_RESPONSE_TOPIC;
    responseTopicProperty.value.data = { static_cast<int>(responseTopic.size()), const_cast<char*>(responseTopic.c_str()) };
    MQTTProperties_add(&(opts.properties), &responseTopicProperty);

    MQTTProperty correlationDataProperty;
    correlationDataProperty.identifier = MQTTPROPERTY_CODE_CORRELATION_DATA;
    std::uniform_int_distribution<> distribution (0, 100000);

    auto randomId = 0;
    m_invokeResultsMutex.lock();
    do {
        randomId = distribution(randomNumberGenerator);
    } while (m_invokeResults.find(randomId) != m_invokeResults.end());
    m_invokeResults.insert(std::pair<int, InvokeReplyFunc>(randomId, func));
    m_invokeResultsMutex.unlock();
    const std::string correlationData = { std::to_string(randomId) } ;
    correlationDataProperty.value.data = { static_cast<int>(correlationData.size()), const_cast<char*>(correlationData.c_str()) };
    MQTTProperties_add(&(opts.properties), &correlationDataProperty);

    opts.onFailure5 = onSendFailure;
    opts.context = this;
    pubmsg.payload = const_cast<void*>(static_cast<const void*>(value.c_str()));
    pubmsg.payloadlen = value.size();
    pubmsg.qos = QOS;
    pubmsg.retained = 0;

    // the responseOptions properties do get overwritten by the msg properties later
    pubmsg.properties = opts.properties;

    int responseCode = MQTTAsync_sendMessage(*m_client.get(), topic.getEncodedTopic().c_str(), &pubmsg, &opts);
    if (responseCode != MQTTASYNC_SUCCESS)
    {
        AG_LOG_ERROR("Failed to start sendMessage, return code " + std::to_string(responseCode));
    }
}

void CWrapper::notifyPropertyChange(const Topic& topic, const std::string& value)
{
    MQTTAsync_responseOptions opts = MQTTAsync_responseOptions_initializer;
    MQTTAsync_message pubmsg = MQTTAsync_message_initializer;

    opts.onFailure5 = onSendFailure;
    opts.context = this;
    pubmsg.payload = const_cast<void*>(static_cast<const void*>(value.c_str()));
    pubmsg.payloadlen = value.size();
    pubmsg.qos = QOS;
    // property changes shall be retained and automatically send to new clients
    pubmsg.retained = 1;
    int responseCode = MQTTAsync_sendMessage(*m_client.get(), topic.getEncodedTopic().c_str(), &pubmsg, &opts);
    if (responseCode != MQTTASYNC_SUCCESS)
    {
        AG_LOG_ERROR("Failed to start sendMessage, return code " + std::to_string(responseCode));
    }
}

void CWrapper::notifySignal(const Topic& topic, const std::string& args)
{
	MQTTAsync_responseOptions opts = MQTTAsync_responseOptions_initializer;
	MQTTAsync_message pubmsg = MQTTAsync_message_initializer;

	pubmsg.payload = const_cast<void*>(static_cast<const void*>(args.c_str()));
	pubmsg.payloadlen = args.size();
	pubmsg.qos = QOS;
	pubmsg.retained = 0;

    int responseCode = MQTTAsync_sendMessage(*m_client.get(), topic.getEncodedTopic().c_str(), &pubmsg, &opts);
	if (responseCode != MQTTASYNC_SUCCESS)
	{
        AG_LOG_ERROR("Failed to start sendMessage, return code " + std::to_string(responseCode));
	}
}

void CWrapper::notifyInvokeResponse(const Topic& responseTopic, const std::string& value, const std::string& correlationData)
{
    MQTTAsync_responseOptions opts = MQTTAsync_responseOptions_initializer;
    MQTTAsync_message pubmsg = MQTTAsync_message_initializer;

    MQTTProperty correlationDataProperty;
    correlationDataProperty.identifier = MQTTPROPERTY_CODE_CORRELATION_DATA;
    correlationDataProperty.value.data = { static_cast<int>(correlationData.size()), const_cast<char*>(correlationData.c_str()) };
    MQTTProperties_add(&(opts.properties), &correlationDataProperty);

    opts.onFailure5 = onSendFailure;
    opts.context = this;
    pubmsg.payload = const_cast<void*>(static_cast<const void*>(value.c_str()));
    pubmsg.payloadlen = value.size();
    pubmsg.qos = QOS;
    pubmsg.retained = 0;

    // the responseOptions properties do get overwritten by the msg properties later
    pubmsg.properties = opts.properties;
    int responseCode = MQTTAsync_sendMessage(*m_client.get(), responseTopic.getEncodedTopic().c_str(), &pubmsg, &opts);
    if (responseCode != MQTTASYNC_SUCCESS)
    {
        AG_LOG_ERROR("Failed to start sendMessage, return code " + std::to_string(responseCode));
    }
}

void CWrapper::setRemoteProperty(const Topic& topic, const std::string& value)
{
	MQTTAsync_responseOptions opts = MQTTAsync_responseOptions_initializer;
	MQTTAsync_message pubmsg = MQTTAsync_message_initializer;

	pubmsg.payload = const_cast<void*>(static_cast<const void*>(value.c_str()));
	pubmsg.payloadlen = value.size();
	pubmsg.qos = QOS;
	pubmsg.retained = 0;
    int responseCode = MQTTAsync_sendMessage(*m_client.get(), topic.getEncodedTopic().c_str(), &pubmsg, &opts);
	if (responseCode != MQTTASYNC_SUCCESS)
	{
        AG_LOG_ERROR("Failed to start sendMessage, return code " + std::to_string(responseCode));
	}
}

void CWrapper::subscribeTopic(const Topic& topic, ISink* sink)
{
    {
        std::lock_guard<std::mutex> guard(m_toBeSubscribedTopicsMutex);
        m_toBeSubscribedTopics.insert({topic, sink});
    }

    {
        std::lock_guard<std::mutex> l{m_waitForWorkMutex};
        m_waitForWork = false;
    }
    m_conditionVariable.notify_one();
}

void CWrapper::confirmSubscription(const Topic& topic, ISink& sink)
{
    std::lock_guard<std::mutex> guard(m_subscribedTopicsMutex);
    m_subscribedTopics.insert({topic, &sink});
}

void CWrapper::removeSubscription(const Topic& topic)
{
    std::lock_guard<std::mutex> guard(m_subscribedTopicsMutex);
    m_subscribedTopics.erase(topic);
}

void CWrapper::unsubscribeTopic(const Topic& topic, ISink* sink)
{
    {
        std::lock_guard<std::mutex> guard(m_toBeUnsubscribedTopicsMutex);
        m_toBeUnsubscribedTopics.insert({topic, sink});
    }

    {
        std::lock_guard<std::mutex> l{m_waitForWorkMutex};
        m_waitForWork = false;
    }
    m_conditionVariable.notify_one();
}
