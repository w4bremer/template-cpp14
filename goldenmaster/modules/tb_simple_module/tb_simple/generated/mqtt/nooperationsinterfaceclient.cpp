#include "tb_simple/generated/mqtt/nooperationsinterfaceclient.h"
#include "tb_simple/generated/core/nooperationsinterface.publisher.h"
#include "tb_simple/generated/core/tb_simple.json.adapter.h"

using namespace Test::TbSimple;
using namespace Test::TbSimple::MQTT;

NoOperationsInterfaceClient::NoOperationsInterfaceClient(std::shared_ptr<ApiGear::MQTT::Client> client)
    : m_isReady(false)
    , m_client(client)
    , m_publisher(std::make_unique<NoOperationsInterfacePublisher>())
{
    m_client->subscribeTopic(ApiGear::MQTT::Topic("tb.simple","NoOperationsInterface",ApiGear::MQTT::Topic::TopicType::Property,"propBool"), std::bind(&NoOperationsInterfaceClient::onPropertyChanged, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->subscribeTopic(ApiGear::MQTT::Topic("tb.simple","NoOperationsInterface",ApiGear::MQTT::Topic::TopicType::Property,"propInt"), std::bind(&NoOperationsInterfaceClient::onPropertyChanged, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->subscribeTopic(ApiGear::MQTT::Topic("tb.simple","NoOperationsInterface",ApiGear::MQTT::Topic::TopicType::Signal,"sigVoid"), std::bind(&NoOperationsInterfaceClient::onSignal, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->subscribeTopic(ApiGear::MQTT::Topic("tb.simple","NoOperationsInterface",ApiGear::MQTT::Topic::TopicType::Signal,"sigBool"), std::bind(&NoOperationsInterfaceClient::onSignal, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
}

NoOperationsInterfaceClient::~NoOperationsInterfaceClient()
{
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("tb.simple","NoOperationsInterface",ApiGear::MQTT::Topic::TopicType::Property,"propBool"), std::bind(&NoOperationsInterfaceClient::onPropertyChanged, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("tb.simple","NoOperationsInterface",ApiGear::MQTT::Topic::TopicType::Property,"propInt"), std::bind(&NoOperationsInterfaceClient::onPropertyChanged, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("tb.simple","NoOperationsInterface",ApiGear::MQTT::Topic::TopicType::Signal,"sigVoid"), std::bind(&NoOperationsInterfaceClient::onSignal, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("tb.simple","NoOperationsInterface",ApiGear::MQTT::Topic::TopicType::Signal,"sigBool"), std::bind(&NoOperationsInterfaceClient::onSignal, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
}

void NoOperationsInterfaceClient::applyState(const nlohmann::json& fields) 
{
    if(fields.contains("propBool")) {
        setPropBoolLocal(fields["propBool"].get<bool>());
    }
    if(fields.contains("propInt")) {
        setPropIntLocal(fields["propInt"].get<int>());
    }
}

void NoOperationsInterfaceClient::setPropBool(bool propBool)
{
    if(m_client == nullptr) {
        return;
    }
    static const auto topic = ApiGear::MQTT::Topic("tb.simple","NoOperationsInterface",ApiGear::MQTT::Topic::TopicType::Operation,"_setpropBool");
    m_client->setRemoteProperty(topic, nlohmann::json(propBool).dump());
}

void NoOperationsInterfaceClient::setPropBoolLocal(bool propBool)
{
    if (m_data.m_propBool != propBool) {
        m_data.m_propBool = propBool;
        m_publisher->publishPropBoolChanged(propBool);
    }
}

bool NoOperationsInterfaceClient::getPropBool() const
{
    return m_data.m_propBool;
}

void NoOperationsInterfaceClient::setPropInt(int propInt)
{
    if(m_client == nullptr) {
        return;
    }
    static const auto topic = ApiGear::MQTT::Topic("tb.simple","NoOperationsInterface",ApiGear::MQTT::Topic::TopicType::Operation,"_setpropInt");
    m_client->setRemoteProperty(topic, nlohmann::json(propInt).dump());
}

void NoOperationsInterfaceClient::setPropIntLocal(int propInt)
{
    if (m_data.m_propInt != propInt) {
        m_data.m_propInt = propInt;
        m_publisher->publishPropIntChanged(propInt);
    }
}

int NoOperationsInterfaceClient::getPropInt() const
{
    return m_data.m_propInt;
}

void NoOperationsInterfaceClient::onSignal(const ApiGear::MQTT::Topic& topic, const std::string& args, const ApiGear::MQTT::Topic&, const std::string&)
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

void NoOperationsInterfaceClient::onPropertyChanged(const ApiGear::MQTT::Topic& topic, const std::string& args, const ApiGear::MQTT::Topic&, const std::string&)
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    const std::string& name = topic.getEntityName();
    applyState({ {name, json_args} });
    return;
}

bool NoOperationsInterfaceClient::isReady() const
{
    return m_isReady;
}

INoOperationsInterfacePublisher& NoOperationsInterfaceClient::_getPublisher() const
{
    return *m_publisher;
}
