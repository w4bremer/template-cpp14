#include <iostream>
#include "MQTTAsync.h"
#include "mqttcppclient.h"
#include <chrono>
#include <random>

using namespace ApiGear::MQTTImpl;
#define QOS         2

std::mt19937 randomNumberGenerator (std::random_device{}());

struct subscribeTopicContext {
    Topic topic;
    ISink* sink;
    Client* client;
};

void onSendSuccess(void* context, MQTTAsync_successData5* response)
{
    Client* client = static_cast<Client*>(context);
    // client->confirmSubscription(ctx->topic, *(ctx->sink));
    // delete ctx;
}

void onSendFailure(void* context, MQTTAsync_failureData5* response)
{
    Client* client = static_cast<Client*>(context);
	// printf("Subscribe failed, rc %d\n", response->code);
    // delete ctx;
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
	printf("Subscribe failed, rc %d\n", response->code);
    delete ctx;
}

void onUnsubscribeSuccess(void* context, MQTTAsync_successData5* response)
{
    subscribeTopicContext* ctx = static_cast<subscribeTopicContext*>(context);
    ctx->client->removeSubscription(ctx->topic);
	// printf("Unsubscribe successful, rc %d\n", response->reasonCode);
    delete ctx;
}

void onUnsubscribeFailure(void* context, MQTTAsync_failureData5* response)
{
    subscribeTopicContext* ctx = static_cast<subscribeTopicContext*>(context);
	printf("Unsubscribe failed, rc %d\n", response->code);
    delete ctx;
}

void onConnected(void* context, MQTTAsync_successData5* response)
{
    Client* client = static_cast<Client*>(context);
    client->onConnected();
}

void onConnectedFail(void* context,  MQTTAsync_failureData5* response)
{
    Client* client = static_cast<Client*>(context);
	printf("Connect failed, rc %d\n", response->code);
    client->onDisconnected();
}

void onDisconnected(void* context, MQTTAsync_successData5* response)
{
    Client* client = static_cast<Client*>(context);
    client->onDisconnected();
}


int msgarrvd(void *context, char *topicName, int topicLen, MQTTAsync_message *message)
{
    Client* client = static_cast<Client*>(context);
    Message mqtt_message {};
    mqtt_message.topic = Topic(std::string(topicName, topicLen));
    mqtt_message.content.assign(static_cast<char*>(message->payload), message->payloadlen);

    if(MQTTProperties_hasProperty(&(message->properties), MQTTPROPERTY_CODE_RESPONSE_TOPIC))
    {
        std::clog << " response topic found "<<std::endl;
        MQTTProperty* responseTopicProperty = MQTTProperties_getProperty(&(message->properties), MQTTPROPERTY_CODE_RESPONSE_TOPIC);
        mqtt_message.responseTopic = Topic(std::string(responseTopicProperty->value.data.data, responseTopicProperty->value.data.len));
    }

    if(MQTTProperties_hasProperty(&(message->properties), MQTTPROPERTY_CODE_CORRELATION_DATA))
    {
        std::clog << " correlation data found "<<std::endl;
        MQTTProperty* correlationDataProperty = MQTTProperties_getProperty(&(message->properties), MQTTPROPERTY_CODE_CORRELATION_DATA);
        mqtt_message.correlationData.assign(correlationDataProperty->value.data.data, correlationDataProperty->value.data.len);
    }

    std::clog << "recv msg topic: " << mqtt_message.topic.getEncodedTopic() << " content: " << mqtt_message.content << " retained:" << message->retained << " props count " << message->properties.count << " responseTopic:" << mqtt_message.responseTopic << " correlationData: "<< mqtt_message.correlationData << std::endl;
    MQTTAsync_freeMessage(&message);
    MQTTAsync_free(topicName);

    client->handleTextMessage(mqtt_message);

    return 1;
}

void connlost(void *context, char *cause)
{
    Client* client = static_cast<Client*>(context);
    printf("\nConnection lost\n");
    client->onDisconnected();
}

Client::Client(const std::string& clientID)
    : m_clientID(clientID)
    , m_client(nullptr)
    , m_disconnectRequested(false)
{
}

void Client::registerSink(ISink& sink)
{
    m_linkedObjects.insert(&sink);
}

void Client::unregisterSink(ISink& sink)
{
    m_linkedObjects.erase(&sink);
}

void Client::run()
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

void Client::checkForNewSubscriptions()
{
    m_toBeSubscribedTopicsMutex.lock();
    const auto toBeSubscribedTopics { m_toBeSubscribedTopics };
    m_toBeSubscribedTopics.clear();
    m_toBeSubscribedTopicsMutex.unlock();
    for (const auto& topic : toBeSubscribedTopics) {
        subscribeTopicContext* ctx = new subscribeTopicContext{topic.first, topic.second, this};
        int rc = 0;

        MQTTAsync_responseOptions opts = MQTTAsync_responseOptions_initializer;
        opts.onSuccess5 = onSubscribeSuccess;
        opts.onFailure5 = onSubscribeFailure;
        opts.context = ctx;
        if ((rc = MQTTAsync_subscribe(*m_client.get(), topic.first.getEncodedTopic().c_str(), QOS, &opts)) != MQTTASYNC_SUCCESS)
        {
            printf("Failed to start subscribe, return code %d\n", rc);
        }
    }
}

void Client::checkForOldSubscriptions()
{
    m_toBeUnsubscribedTopicsMutex.lock();
    const auto toBeUnsubscribedTopics { m_toBeUnsubscribedTopics };
    m_toBeUnsubscribedTopics.clear();
    m_toBeUnsubscribedTopicsMutex.unlock();
    for (const auto& topic : toBeUnsubscribedTopics) {
        std::cout << "Unsubscribing from " << topic.first.getEncodedTopic() << std::endl;

        subscribeTopicContext* ctx = new subscribeTopicContext{topic.first, topic.second, this};
        int rc = 0;

        MQTTAsync_responseOptions opts = MQTTAsync_responseOptions_initializer;
        opts.onSuccess5 = onUnsubscribeSuccess;
        opts.onFailure5 = onUnsubscribeFailure;
        opts.context = ctx;
        if ((rc = MQTTAsync_unsubscribe(*m_client.get(), topic.first.getEncodedTopic().c_str(), &opts)) != MQTTASYNC_SUCCESS)
        {
            printf("Failed to start unsubscribe, return code %d\n", rc);
        }
    }
}

void Client::unsubscribeAllTopics()
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
        std::cout << "Unsubscribing from " << topic.first.getEncodedTopic() << std::endl;

        subscribeTopicContext* ctx = new subscribeTopicContext{topic.first, topic.second, this};
        int rc = 0;

        MQTTAsync_responseOptions opts = MQTTAsync_responseOptions_initializer;
        opts.onSuccess5 = onUnsubscribeSuccess;
        opts.onFailure5 = onUnsubscribeFailure;
        opts.context = ctx;
        if ((rc = MQTTAsync_unsubscribe(*m_client.get(), topic.first.getEncodedTopic().c_str(), &opts)) != MQTTASYNC_SUCCESS)
        {
            printf("Failed to start unsubscribe, return code %d\n", rc);
        }
    }
}

void Client::waitForPendingMessages()
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

void Client::connectToHost(const std::string& brokerURL)
{
    static bool connecting = false;

    if(brokerURL.empty()) {
        m_serverUrl = "tcp://localhost:1883";
    } else {
        m_serverUrl = brokerURL;
    }
    std::clog << "Connecting to host " << m_serverUrl << std::endl;
    
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

            MQTTAsync_setCallbacks(*m_client.get(), this, connlost, msgarrvd, NULL);
            int rc = -1;
            if ((rc = MQTTAsync_connect(*m_client.get(), &conn_opts)) != MQTTASYNC_SUCCESS)
            {
                std::cout << "Failed to connect, return code "<< rc << std::endl;
                connecting = false;
                MQTTAsync_destroy(m_client.get());
                m_client.reset();
                return;
            }

        } catch (std::exception &e) {
            m_client = nullptr;
            std::cerr << "Exception " << e.what() << std::endl;
        }
        connecting = false;
    }
}

void Client::disconnect() {
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
    for (auto& object: m_linkedObjects){
        (void) object;
    }
    m_linkedObjects.clear();
}

void Client::onConnected()
{
    m_connected = true;
    std::clog << " socket connected" << std::endl;
    for (auto& object: m_linkedObjects){
        object->onConnected();
    }
    // process();
    m_thread = std::thread(&Client::run, this);
}

void Client::onDisconnected()
{
    m_connected = false;
    bool disconnectRequested = m_disconnectRequested;
    m_disconnectRequested = false;
    std::clog << " socket disconnected" << std::endl;

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

void Client::handleTextMessage(const Message& message)
{
    // std::clog << "new msg topic: " << topic << " mqtt_message: " << message << std::endl;
    std::pair<std::multimap<Topic, ISink*, Topic>::iterator, std::multimap<Topic, ISink*, Topic>::iterator> topics = m_subscribedTopics.equal_range(message.topic);
    // for (auto test: m_subscribedTopics){
    //     std::cout << "topic " << test.first << " " << test.second << std::endl; 
    // }
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

void Client::invokeRemote(const Topic& topic, const std::string& value, InvokeReplyFunc func)
{
    const std::string responseTopic = topic.getEncodedTopic() + "/" + m_clientID + "/result" ;

    MQTTAsync_responseOptions opts = MQTTAsync_responseOptions_initializer;
    MQTTAsync_message pubmsg = MQTTAsync_message_initializer;
    int rc = 0;

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

    std::cout << "corrdata " << correlationData << std::endl;
    opts.onSuccess5 = onSendSuccess;
    opts.onFailure5 = onSendFailure;
    opts.context = this;
    // opts.properties = properties;
    pubmsg.payload = const_cast<void*>(static_cast<const void*>(value.c_str()));
    pubmsg.payloadlen = value.size();
    pubmsg.qos = QOS;
    pubmsg.retained = 0;

    // the responseOptions properties do get overwritten by the msg properties later
    pubmsg.properties = opts.properties;

    if ((rc = MQTTAsync_sendMessage(*m_client.get(), topic.getEncodedTopic().c_str(), &pubmsg, &opts)) != MQTTASYNC_SUCCESS)
    {
        printf("Failed to start sendMessage, return code %d\n", rc);
    }
}

void Client::notifyPropertyChange(const Topic& topic, const std::string& value)
{
    MQTTAsync_responseOptions opts = MQTTAsync_responseOptions_initializer;
    MQTTAsync_message pubmsg = MQTTAsync_message_initializer;
    int rc = 0;

    opts.onSuccess5 = onSendSuccess;
    opts.onFailure5 = onSendFailure;
    opts.context = this;
    pubmsg.payload = const_cast<void*>(static_cast<const void*>(value.c_str()));
    pubmsg.payloadlen = value.size();
    pubmsg.qos = QOS;
    // property changes shall be retained and automatically send to new clients
    pubmsg.retained = 1;
    if ((rc = MQTTAsync_sendMessage(*m_client.get(), topic.getEncodedTopic().c_str(), &pubmsg, &opts)) != MQTTASYNC_SUCCESS)
    {
        printf("Failed to start sendMessage, return code %d\n", rc);
    }
}

void Client::notifySignal(const Topic& topic, const std::string& args)
{
	MQTTAsync_responseOptions opts = MQTTAsync_responseOptions_initializer;
	MQTTAsync_message pubmsg = MQTTAsync_message_initializer;
	int rc = 0;

	// opts.onSuccess = onSend;
	// opts.onFailure = onSendFailure;
	// opts.context = client;
	pubmsg.payload = const_cast<void*>(static_cast<const void*>(args.c_str()));
	pubmsg.payloadlen = args.size();
	pubmsg.qos = QOS;
	pubmsg.retained = 0;

	if ((rc = MQTTAsync_sendMessage(*m_client.get(), topic.getEncodedTopic().c_str(), &pubmsg, &opts)) != MQTTASYNC_SUCCESS)
	{
		printf("Failed to start sendMessage, return code %d\n", rc);
	}
}

void Client::notifyInvokeResponse(const Topic& responseTopic, const std::string& value, const std::string& correlationData)
{
    MQTTAsync_responseOptions opts = MQTTAsync_responseOptions_initializer;
    MQTTAsync_message pubmsg = MQTTAsync_message_initializer;
    int rc = 0;

    MQTTProperty correlationDataProperty;
    correlationDataProperty.identifier = MQTTPROPERTY_CODE_CORRELATION_DATA;
    correlationDataProperty.value.data = { static_cast<int>(correlationData.size()), const_cast<char*>(correlationData.c_str()) };
    MQTTProperties_add(&(opts.properties), &correlationDataProperty);

    opts.onSuccess5 = onSendSuccess;
    opts.onFailure5 = onSendFailure;
    opts.context = this;
    pubmsg.payload = const_cast<void*>(static_cast<const void*>(value.c_str()));
    std::cout << "payload " << value << std::endl;
    pubmsg.payloadlen = value.size();
    pubmsg.qos = QOS;
    pubmsg.retained = 0;

    // the responseOptions properties do get overwritten by the msg properties later
    pubmsg.properties = opts.properties;
    if ((rc = MQTTAsync_sendMessage(*m_client.get(), responseTopic.getEncodedTopic().c_str(), &pubmsg, &opts)) != MQTTASYNC_SUCCESS)
    {
        printf("Failed to start sendMessage, return code %d\n", rc);
    }
}

void Client::setRemoteProperty(const Topic& topic, const std::string& value)
{
	MQTTAsync_responseOptions opts = MQTTAsync_responseOptions_initializer;
	MQTTAsync_message pubmsg = MQTTAsync_message_initializer;
	int rc = 0;

	// opts.onSuccess = onSend;
	// opts.onFailure = onSendFailure;
	// opts.context = client;
	pubmsg.payload = const_cast<void*>(static_cast<const void*>(value.c_str()));
	pubmsg.payloadlen = value.size();
	pubmsg.qos = QOS;
	pubmsg.retained = 0;
	if ((rc = MQTTAsync_sendMessage(*m_client.get(), topic.getEncodedTopic().c_str(), &pubmsg, &opts)) != MQTTASYNC_SUCCESS)
	{
		printf("Failed to start sendMessage, return code %d\n", rc);
	}
}

void Client::subscribeTopic(const Topic& topic, ISink* sink)
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

void Client::confirmSubscription(const Topic& topic, ISink& sink)
{
    std::lock_guard<std::mutex> guard(m_subscribedTopicsMutex);
    m_subscribedTopics.insert({topic, &sink});
}

void Client::removeSubscription(const Topic& topic)
{
    std::lock_guard<std::mutex> guard(m_subscribedTopicsMutex);
    m_subscribedTopics.erase(topic);
}

void Client::unsubscribeTopic(const Topic& topic, ISink* sink)
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
