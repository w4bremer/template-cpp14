#include "testbed1/generated/mqtt/structarrayinterfaceservice.h"
#include "testbed1/generated/core/testbed1.json.adapter.h"
#include <iostream>

using namespace Test::Testbed1;
using namespace Test::Testbed1::MQTT;

StructArrayInterfaceService::StructArrayInterfaceService(std::shared_ptr<IStructArrayInterface> impl, std::shared_ptr<ApiGear::MQTT::Client> client)
    : m_impl(impl)
    , m_client(client)
{
    m_impl->_getPublisher().subscribeToAllChanges(*this);

    m_client->registerSink(*this);
    // subscribe to all property change request methods
    m_client->subscribeTopic(ApiGear::MQTT::Topic("testbed1","StructArrayInterface",ApiGear::MQTT::Topic::TopicType::Operation,"_setpropBool"), this);
    m_client->subscribeTopic(ApiGear::MQTT::Topic("testbed1","StructArrayInterface",ApiGear::MQTT::Topic::TopicType::Operation,"_setpropInt"), this);
    m_client->subscribeTopic(ApiGear::MQTT::Topic("testbed1","StructArrayInterface",ApiGear::MQTT::Topic::TopicType::Operation,"_setpropFloat"), this);
    m_client->subscribeTopic(ApiGear::MQTT::Topic("testbed1","StructArrayInterface",ApiGear::MQTT::Topic::TopicType::Operation,"_setpropString"), this);
    m_client->subscribeTopic(ApiGear::MQTT::Topic("testbed1","StructArrayInterface",ApiGear::MQTT::Topic::TopicType::Operation,"funcBool"), this);
    m_client->subscribeTopic(ApiGear::MQTT::Topic("testbed1","StructArrayInterface",ApiGear::MQTT::Topic::TopicType::Operation,"funcInt"), this);
    m_client->subscribeTopic(ApiGear::MQTT::Topic("testbed1","StructArrayInterface",ApiGear::MQTT::Topic::TopicType::Operation,"funcFloat"), this);
    m_client->subscribeTopic(ApiGear::MQTT::Topic("testbed1","StructArrayInterface",ApiGear::MQTT::Topic::TopicType::Operation,"funcString"), this);

}

StructArrayInterfaceService::~StructArrayInterfaceService()
{
    m_impl->_getPublisher().unsubscribeFromAllChanges(*this);

    m_client->unregisterSink(*this);
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("testbed1","StructArrayInterface",ApiGear::MQTT::Topic::TopicType::Operation,"_setpropBool"), this);
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("testbed1","StructArrayInterface",ApiGear::MQTT::Topic::TopicType::Operation,"_setpropInt"), this);
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("testbed1","StructArrayInterface",ApiGear::MQTT::Topic::TopicType::Operation,"_setpropFloat"), this);
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("testbed1","StructArrayInterface",ApiGear::MQTT::Topic::TopicType::Operation,"_setpropString"), this);
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("testbed1","StructArrayInterface",ApiGear::MQTT::Topic::TopicType::Operation,"funcBool"), this);
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("testbed1","StructArrayInterface",ApiGear::MQTT::Topic::TopicType::Operation,"funcInt"), this);
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("testbed1","StructArrayInterface",ApiGear::MQTT::Topic::TopicType::Operation,"funcFloat"), this);
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("testbed1","StructArrayInterface",ApiGear::MQTT::Topic::TopicType::Operation,"funcString"), this);
}

void StructArrayInterfaceService::onConnected()
{
    // send current values
    onPropBoolChanged(m_impl->getPropBool());
    onPropIntChanged(m_impl->getPropInt());
    onPropFloatChanged(m_impl->getPropFloat());
    onPropStringChanged(m_impl->getPropString());
}

void StructArrayInterfaceService::onInvoke(const ApiGear::MQTT::Topic& topic, const std::string& args, const ApiGear::MQTT::Topic& responseTopic, const std::string& correlationData)
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    const std::string& name = topic.getEntityName();
    if(name == "_setpropBool") {
        auto propBool = json_args.get<std::list<StructBool>>();
        m_impl->setPropBool(propBool);
        return;
    }
    if(name == "_setpropInt") {
        auto propInt = json_args.get<std::list<StructInt>>();
        m_impl->setPropInt(propInt);
        return;
    }
    if(name == "_setpropFloat") {
        auto propFloat = json_args.get<std::list<StructFloat>>();
        m_impl->setPropFloat(propFloat);
        return;
    }
    if(name == "_setpropString") {
        auto propString = json_args.get<std::list<StructString>>();
        m_impl->setPropString(propString);
        return;
    }


    if(name == "funcBool") {
        const std::list<StructBool>& paramBool = json_args.at(0).get<std::list<StructBool>>();
        auto result = m_impl->funcBool(paramBool);
        m_client->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
        return;
    }
    if(name == "funcInt") {
        const std::list<StructInt>& paramInt = json_args.at(0).get<std::list<StructInt>>();
        auto result = m_impl->funcInt(paramInt);
        m_client->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
        return;
    }
    if(name == "funcFloat") {
        const std::list<StructFloat>& paramFloat = json_args.at(0).get<std::list<StructFloat>>();
        auto result = m_impl->funcFloat(paramFloat);
        m_client->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
        return;
    }
    if(name == "funcString") {
        const std::list<StructString>& paramString = json_args.at(0).get<std::list<StructString>>();
        auto result = m_impl->funcString(paramString);
        m_client->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
        return;
    }
}
void StructArrayInterfaceService::onSigBool(const std::list<StructBool>& paramBool)
{
    if(m_client != nullptr) {
        const nlohmann::json& args = { paramBool };
        static const auto topic = ApiGear::MQTT::Topic("testbed1","StructArrayInterface",ApiGear::MQTT::Topic::TopicType::Signal,"sigBool");
        m_client->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void StructArrayInterfaceService::onSigInt(const std::list<StructInt>& paramInt)
{
    if(m_client != nullptr) {
        const nlohmann::json& args = { paramInt };
        static const auto topic = ApiGear::MQTT::Topic("testbed1","StructArrayInterface",ApiGear::MQTT::Topic::TopicType::Signal,"sigInt");
        m_client->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void StructArrayInterfaceService::onSigFloat(const std::list<StructFloat>& paramFloat)
{
    if(m_client != nullptr) {
        const nlohmann::json& args = { paramFloat };
        static const auto topic = ApiGear::MQTT::Topic("testbed1","StructArrayInterface",ApiGear::MQTT::Topic::TopicType::Signal,"sigFloat");
        m_client->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void StructArrayInterfaceService::onSigString(const std::list<StructString>& paramString)
{
    if(m_client != nullptr) {
        const nlohmann::json& args = { paramString };
        static const auto topic = ApiGear::MQTT::Topic("testbed1","StructArrayInterface",ApiGear::MQTT::Topic::TopicType::Signal,"sigString");
        m_client->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void StructArrayInterfaceService::onPropBoolChanged(const std::list<StructBool>& propBool)
{
    if(m_client != nullptr) {
        static const auto topic = ApiGear::MQTT::Topic("testbed1","StructArrayInterface",ApiGear::MQTT::Topic::TopicType::Property,"propBool");
        m_client->notifyPropertyChange(topic, nlohmann::json(propBool).dump());
    }
}
void StructArrayInterfaceService::onPropIntChanged(const std::list<StructInt>& propInt)
{
    if(m_client != nullptr) {
        static const auto topic = ApiGear::MQTT::Topic("testbed1","StructArrayInterface",ApiGear::MQTT::Topic::TopicType::Property,"propInt");
        m_client->notifyPropertyChange(topic, nlohmann::json(propInt).dump());
    }
}
void StructArrayInterfaceService::onPropFloatChanged(const std::list<StructFloat>& propFloat)
{
    if(m_client != nullptr) {
        static const auto topic = ApiGear::MQTT::Topic("testbed1","StructArrayInterface",ApiGear::MQTT::Topic::TopicType::Property,"propFloat");
        m_client->notifyPropertyChange(topic, nlohmann::json(propFloat).dump());
    }
}
void StructArrayInterfaceService::onPropStringChanged(const std::list<StructString>& propString)
{
    if(m_client != nullptr) {
        static const auto topic = ApiGear::MQTT::Topic("testbed1","StructArrayInterface",ApiGear::MQTT::Topic::TopicType::Property,"propString");
        m_client->notifyPropertyChange(topic, nlohmann::json(propString).dump());
    }
}
