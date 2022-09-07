#include "testbed1/generated/mqtt/structinterfaceservice.h"
#include "testbed1/generated/core/testbed1.json.adapter.h"
#include <iostream>

using namespace Test::Testbed1;
using namespace Test::Testbed1::mqtt;

StructInterfaceService::StructInterfaceService(IStructInterface& impl, std::shared_ptr<ApiGear::MQTTImpl::Client> client)
    : m_impl(impl)
    , m_client(client)
{
    m_impl._getPublisher().subscribeToAllChanges(*this);

    m_client->registerSink(*this);
    // subscribe to all property change request methods
    m_client->subscribeTopic(ApiGear::MQTTImpl::Topic("testbed1","StructInterface",ApiGear::MQTTImpl::Topic::TopicType::Operation,"_setpropBool"), this);
    m_client->subscribeTopic(ApiGear::MQTTImpl::Topic("testbed1","StructInterface",ApiGear::MQTTImpl::Topic::TopicType::Operation,"_setpropInt"), this);
    m_client->subscribeTopic(ApiGear::MQTTImpl::Topic("testbed1","StructInterface",ApiGear::MQTTImpl::Topic::TopicType::Operation,"_setpropFloat"), this);
    m_client->subscribeTopic(ApiGear::MQTTImpl::Topic("testbed1","StructInterface",ApiGear::MQTTImpl::Topic::TopicType::Operation,"_setpropString"), this);
    m_client->subscribeTopic(ApiGear::MQTTImpl::Topic("testbed1","StructInterface",ApiGear::MQTTImpl::Topic::TopicType::Operation,"funcBool"), this);
    m_client->subscribeTopic(ApiGear::MQTTImpl::Topic("testbed1","StructInterface",ApiGear::MQTTImpl::Topic::TopicType::Operation,"funcInt"), this);
    m_client->subscribeTopic(ApiGear::MQTTImpl::Topic("testbed1","StructInterface",ApiGear::MQTTImpl::Topic::TopicType::Operation,"funcFloat"), this);
    m_client->subscribeTopic(ApiGear::MQTTImpl::Topic("testbed1","StructInterface",ApiGear::MQTTImpl::Topic::TopicType::Operation,"funcString"), this);

}

StructInterfaceService::~StructInterfaceService()
{
    m_impl._getPublisher().unsubscribeFromAllChanges(*this);

    m_client->unregisterSink(*this);
    m_client->unsubscribeTopic(ApiGear::MQTTImpl::Topic("testbed1","StructInterface",ApiGear::MQTTImpl::Topic::TopicType::Operation,"_setpropBool"), this);
    m_client->unsubscribeTopic(ApiGear::MQTTImpl::Topic("testbed1","StructInterface",ApiGear::MQTTImpl::Topic::TopicType::Operation,"_setpropInt"), this);
    m_client->unsubscribeTopic(ApiGear::MQTTImpl::Topic("testbed1","StructInterface",ApiGear::MQTTImpl::Topic::TopicType::Operation,"_setpropFloat"), this);
    m_client->unsubscribeTopic(ApiGear::MQTTImpl::Topic("testbed1","StructInterface",ApiGear::MQTTImpl::Topic::TopicType::Operation,"_setpropString"), this);
    m_client->unsubscribeTopic(ApiGear::MQTTImpl::Topic("testbed1","StructInterface",ApiGear::MQTTImpl::Topic::TopicType::Operation,"funcBool"), this);
    m_client->unsubscribeTopic(ApiGear::MQTTImpl::Topic("testbed1","StructInterface",ApiGear::MQTTImpl::Topic::TopicType::Operation,"funcInt"), this);
    m_client->unsubscribeTopic(ApiGear::MQTTImpl::Topic("testbed1","StructInterface",ApiGear::MQTTImpl::Topic::TopicType::Operation,"funcFloat"), this);
    m_client->unsubscribeTopic(ApiGear::MQTTImpl::Topic("testbed1","StructInterface",ApiGear::MQTTImpl::Topic::TopicType::Operation,"funcString"), this);
}

void StructInterfaceService::onConnected()
{
    // send current values
    onPropBoolChanged(m_impl.getPropBool());
    onPropIntChanged(m_impl.getPropInt());
    onPropFloatChanged(m_impl.getPropFloat());
    onPropStringChanged(m_impl.getPropString());
}

void StructInterfaceService::onInvoke(const ApiGear::MQTTImpl::Topic& topic, const std::string& args, const ApiGear::MQTTImpl::Topic& responseTopic, const std::string& correlationData)
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    const std::string& name = topic.getEntityName();
    if(name == "_setpropBool") {
        auto propBool = json_args.get<StructBool>();
        m_impl.setPropBool(propBool);
        return;
    }
    if(name == "_setpropInt") {
        auto propInt = json_args.get<StructInt>();
        m_impl.setPropInt(propInt);
        return;
    }
    if(name == "_setpropFloat") {
        auto propFloat = json_args.get<StructFloat>();
        m_impl.setPropFloat(propFloat);
        return;
    }
    if(name == "_setpropString") {
        auto propString = json_args.get<StructString>();
        m_impl.setPropString(propString);
        return;
    }


    if(name == "funcBool") {
        const StructBool& paramBool = json_args.at(0).get<StructBool>();
        auto result = m_impl.funcBool(paramBool);
        m_client->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
        return;
    }
    if(name == "funcInt") {
        const StructInt& paramInt = json_args.at(0).get<StructInt>();
        auto result = m_impl.funcInt(paramInt);
        m_client->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
        return;
    }
    if(name == "funcFloat") {
        const StructFloat& paramFloat = json_args.at(0).get<StructFloat>();
        auto result = m_impl.funcFloat(paramFloat);
        m_client->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
        return;
    }
    if(name == "funcString") {
        const StructString& paramString = json_args.at(0).get<StructString>();
        auto result = m_impl.funcString(paramString);
        m_client->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
        return;
    }
}
void StructInterfaceService::onSigBool(const StructBool& paramBool)
{
    if(m_client != nullptr) {
        const nlohmann::json& args = { paramBool };
        static const auto topic = ApiGear::MQTTImpl::Topic("testbed1","StructInterface",ApiGear::MQTTImpl::Topic::TopicType::Signal,"sigBool");
        m_client->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void StructInterfaceService::onSigInt(const StructInt& paramInt)
{
    if(m_client != nullptr) {
        const nlohmann::json& args = { paramInt };
        static const auto topic = ApiGear::MQTTImpl::Topic("testbed1","StructInterface",ApiGear::MQTTImpl::Topic::TopicType::Signal,"sigInt");
        m_client->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void StructInterfaceService::onSigFloat(const StructFloat& paramFloat)
{
    if(m_client != nullptr) {
        const nlohmann::json& args = { paramFloat };
        static const auto topic = ApiGear::MQTTImpl::Topic("testbed1","StructInterface",ApiGear::MQTTImpl::Topic::TopicType::Signal,"sigFloat");
        m_client->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void StructInterfaceService::onSigString(const StructString& paramString)
{
    if(m_client != nullptr) {
        const nlohmann::json& args = { paramString };
        static const auto topic = ApiGear::MQTTImpl::Topic("testbed1","StructInterface",ApiGear::MQTTImpl::Topic::TopicType::Signal,"sigString");
        m_client->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void StructInterfaceService::onPropBoolChanged(const StructBool& propBool)
{
    if(m_client != nullptr) {
        static const auto topic = ApiGear::MQTTImpl::Topic("testbed1","StructInterface",ApiGear::MQTTImpl::Topic::TopicType::Property,"propBool");
        m_client->notifyPropertyChange(topic, nlohmann::json(propBool).dump());
    }
}
void StructInterfaceService::onPropIntChanged(const StructInt& propInt)
{
    if(m_client != nullptr) {
        static const auto topic = ApiGear::MQTTImpl::Topic("testbed1","StructInterface",ApiGear::MQTTImpl::Topic::TopicType::Property,"propInt");
        m_client->notifyPropertyChange(topic, nlohmann::json(propInt).dump());
    }
}
void StructInterfaceService::onPropFloatChanged(const StructFloat& propFloat)
{
    if(m_client != nullptr) {
        static const auto topic = ApiGear::MQTTImpl::Topic("testbed1","StructInterface",ApiGear::MQTTImpl::Topic::TopicType::Property,"propFloat");
        m_client->notifyPropertyChange(topic, nlohmann::json(propFloat).dump());
    }
}
void StructInterfaceService::onPropStringChanged(const StructString& propString)
{
    if(m_client != nullptr) {
        static const auto topic = ApiGear::MQTTImpl::Topic("testbed1","StructInterface",ApiGear::MQTTImpl::Topic::TopicType::Property,"propString");
        m_client->notifyPropertyChange(topic, nlohmann::json(propString).dump());
    }
}
