#include "tb_simple/generated/mqtt/nopropertiesinterfaceclient.h"
#include "tb_simple/generated/core/nopropertiesinterface.publisher.h"
#include "tb_simple/generated/core/tb_simple.json.adapter.h"
#include "apigear/mqtt/mqtttopic.h"
#include <random>

using namespace Test::TbSimple;
using namespace Test::TbSimple::MQTT;

namespace {
    std::mt19937 randomNumberGenerator (std::random_device{}());

    std::map<std::string, ApiGear::MQTT::CallbackFunction> createTopicMap(const std::string&clientId, NoPropertiesInterfaceClient* client)
    {
        return {
            { std::string("tb.simple/NoPropertiesInterface/sig/sigVoid"), [client](const std::string& topic, const std::string& args, const std::string&, const std::string&){ client->onSignal(topic, args); } },
            { std::string("tb.simple/NoPropertiesInterface/sig/sigBool"), [client](const std::string& topic, const std::string& args, const std::string&, const std::string&){ client->onSignal(topic, args); } },
            { std::string("tb.simple/NoPropertiesInterface/rpc/funcVoid/"+clientId+"/result"), [client](const std::string&, const std::string& args, const std::string&, const std::string& correlationData){ client->onInvokeReply(args, correlationData); } },
            { std::string("tb.simple/NoPropertiesInterface/rpc/funcBool/"+clientId+"/result"), [client](const std::string&, const std::string& args, const std::string&, const std::string& correlationData){ client->onInvokeReply(args, correlationData); } },
        };
    };
}

NoPropertiesInterfaceClient::NoPropertiesInterfaceClient(std::shared_ptr<ApiGear::MQTT::Client> client)
    : m_isReady(false)
    , m_client(client)
    , m_publisher(std::make_unique<NoPropertiesInterfacePublisher>())
    , m_topics(createTopicMap(m_client->getClientId(), this))
{
    for (const auto& topic: m_topics)
    {
        m_client->subscribeTopic(topic. first, topic.second);
    }
}

NoPropertiesInterfaceClient::~NoPropertiesInterfaceClient()
{
    for (const auto& topic: m_topics)
    {
        m_client->unsubscribeTopic(topic. first);
    }
}

void NoPropertiesInterfaceClient::funcVoid()
{
    if(m_client == nullptr) {
        return;
    }
}

std::future<void> NoPropertiesInterfaceClient::funcVoidAsync()
{
    if(m_client == nullptr) {
        throw std::runtime_error("Client is not initialized");
    }
    return std::async(std::launch::async, [this]()
        {
            std::promise<void> resultPromise;
            static const auto topic = std::string("tb.simple/NoPropertiesInterface/rpc/funcVoid");
            static const auto responseTopic = std::string(topic + "/" + m_client->getClientId() + "/result");
            ApiGear::MQTT::InvokeReplyFunc responseHandler = [&resultPromise](ApiGear::MQTT::InvokeReplyArg arg) {
                (void) arg;
                resultPromise.set_value();
            };
            auto responseId = registerResponseHandler(responseHandler);
            m_client->invokeRemote(topic, responseTopic,
                nlohmann::json::array({}).dump(), responseId);
            return resultPromise.get_future().get();
        }
    );
}

bool NoPropertiesInterfaceClient::funcBool(bool paramBool)
{
    if(m_client == nullptr) {
        return false;
    }
    bool value(funcBoolAsync(paramBool).get());
    return value;
}

std::future<bool> NoPropertiesInterfaceClient::funcBoolAsync(bool paramBool)
{
    if(m_client == nullptr) {
        throw std::runtime_error("Client is not initialized");
    }
    return std::async(std::launch::async, [this,
                    paramBool]()
        {
            std::promise<bool> resultPromise;
            static const auto topic = std::string("tb.simple/NoPropertiesInterface/rpc/funcBool");
            static const auto responseTopic = std::string(topic + "/" + m_client->getClientId() + "/result");
            ApiGear::MQTT::InvokeReplyFunc responseHandler = [&resultPromise](ApiGear::MQTT::InvokeReplyArg arg) {
                const bool& value = arg.value.get<bool>();
                resultPromise.set_value(value);
            };
            auto responseId = registerResponseHandler(responseHandler);
            m_client->invokeRemote(topic, responseTopic,
                nlohmann::json::array({paramBool}).dump(), responseId);
            return resultPromise.get_future().get();
        }
    );
}

void NoPropertiesInterfaceClient::onSignal(const std::string& topic, const std::string& args)
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    const std::string entityName = ApiGear::MQTT::Topic(topic).getEntityName();
    if(entityName == "sigVoid") {
        m_publisher->publishSigVoid();
        return;
    }
    if(entityName == "sigBool") {
        m_publisher->publishSigBool(json_args[0].get<bool>());
        return;
    }
}

int NoPropertiesInterfaceClient::registerResponseHandler(ApiGear::MQTT::InvokeReplyFunc handler)
{
    auto responseId = 0;
    std::uniform_int_distribution<> distribution (0, 100000);
    m_responseHandlerMutex.lock();
    do {
        responseId = distribution(randomNumberGenerator);
    } while (m_responseHandlerMap.find(responseId) != m_responseHandlerMap.end());
    m_responseHandlerMap.insert(std::pair<int, ApiGear::MQTT::InvokeReplyFunc>(responseId, handler));
    m_responseHandlerMutex.unlock();

    return responseId;
}

void NoPropertiesInterfaceClient::onInvokeReply(const std::string& args, const std::string& correlationData)
{
    const int randomId = std::stoi(correlationData);
    ApiGear::MQTT::InvokeReplyFunc responseHandler {};
    m_responseHandlerMutex.lock();
    if((m_responseHandlerMap.find(randomId) != m_responseHandlerMap.end()))
    {
        responseHandler = m_responseHandlerMap[randomId];
        m_responseHandlerMap.erase(randomId);
    }
    m_responseHandlerMutex.unlock();
    if(responseHandler) {
        const ApiGear::MQTT::InvokeReplyArg response{nlohmann::json::parse(args)};
        responseHandler(response);
    }
}

bool NoPropertiesInterfaceClient::isReady() const
{
    return m_isReady;
}

INoPropertiesInterfacePublisher& NoPropertiesInterfaceClient::_getPublisher() const
{
    return *m_publisher;
}
