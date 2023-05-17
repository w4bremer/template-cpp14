#include "tb_simple/generated/mqtt/nopropertiesinterfaceclient.h"
#include "tb_simple/generated/core/nopropertiesinterface.publisher.h"
#include "tb_simple/generated/core/tb_simple.json.adapter.h"

using namespace Test::TbSimple;
using namespace Test::TbSimple::MQTT;

NoPropertiesInterfaceClient::NoPropertiesInterfaceClient(std::shared_ptr<ApiGear::MQTT::Client> client)
    : m_isReady(false)
    , m_client(client)
    , m_publisher(std::make_unique<NoPropertiesInterfacePublisher>())
{
    m_client->subscribeTopic(ApiGear::MQTT::Topic("tb.simple","NoPropertiesInterface",ApiGear::MQTT::Topic::TopicType::Signal,"sigVoid"), this);
    m_client->subscribeTopic(ApiGear::MQTT::Topic("tb.simple","NoPropertiesInterface",ApiGear::MQTT::Topic::TopicType::Signal,"sigBool"), this);
    m_client->subscribeTopic(ApiGear::MQTT::Topic("tb.simple","NoPropertiesInterface",ApiGear::MQTT::Topic::TopicType::Operation,"funcVoid",m_client->getClientId()+"/result"), nullptr);
    m_client->subscribeTopic(ApiGear::MQTT::Topic("tb.simple","NoPropertiesInterface",ApiGear::MQTT::Topic::TopicType::Operation,"funcBool",m_client->getClientId()+"/result"), nullptr);
}

NoPropertiesInterfaceClient::~NoPropertiesInterfaceClient()
{
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("tb.simple","NoPropertiesInterface",ApiGear::MQTT::Topic::TopicType::Signal,"sigVoid"), this);
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("tb.simple","NoPropertiesInterface",ApiGear::MQTT::Topic::TopicType::Signal,"sigBool"), this);
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("tb.simple","NoPropertiesInterface",ApiGear::MQTT::Topic::TopicType::Operation,"funcVoid",m_client->getClientId()+"/result"), nullptr);
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("tb.simple","NoPropertiesInterface",ApiGear::MQTT::Topic::TopicType::Operation,"funcBool",m_client->getClientId()+"/result"), nullptr);
}

void NoPropertiesInterfaceClient::applyState(const nlohmann::json& fields) 
{// no properties to apply state
    (void) fields;
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
            static const auto topic = ApiGear::MQTT::Topic("tb.simple","NoPropertiesInterface",ApiGear::MQTT::Topic::TopicType::Operation,"funcVoid");
            m_client->invokeRemote(topic,
                nlohmann::json::array({}).dump(), [&resultPromise](ApiGear::MQTT::InvokeReplyArg arg) {
                    (void) arg;
                    resultPromise.set_value();
                });
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
            static const auto topic = ApiGear::MQTT::Topic("tb.simple","NoPropertiesInterface",ApiGear::MQTT::Topic::TopicType::Operation,"funcBool");
            m_client->invokeRemote(topic,
                nlohmann::json::array({paramBool}).dump(), [&resultPromise](ApiGear::MQTT::InvokeReplyArg arg) {
                    const bool& value = arg.value.get<bool>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

void NoPropertiesInterfaceClient::onSignal(const ApiGear::MQTT::Topic& topic, const std::string& args)
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    if(topic.getEntityName() == "sigVoid") {
        m_publisher->publishSigVoid();
        return;
    }
    if(topic.getEntityName() == "sigBool") {
        m_publisher->publishSigBool(json_args[0].get<bool>());
        return;
    }
}

void NoPropertiesInterfaceClient::onPropertyChanged(const ApiGear::MQTT::Topic& topic, const std::string& args)
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    const std::string& name = topic.getEntityName();
    applyState({ {name, json_args} });
    return;
}

bool NoPropertiesInterfaceClient::isReady() const
{
    return m_isReady;
}

INoPropertiesInterfacePublisher& NoPropertiesInterfaceClient::_getPublisher() const
{
    return *m_publisher;
}
