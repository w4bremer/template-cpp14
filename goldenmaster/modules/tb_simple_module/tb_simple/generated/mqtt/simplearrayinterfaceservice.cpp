#include "tb_simple/generated/mqtt/simplearrayinterfaceservice.h"
#include "tb_simple/generated/core/tb_simple.json.adapter.h"
#include <iostream>

using namespace Test::TbSimple;
using namespace Test::TbSimple::MQTT;

SimpleArrayInterfaceService::SimpleArrayInterfaceService(std::shared_ptr<ISimpleArrayInterface> impl, std::shared_ptr<ApiGear::MQTT::Client> client)
    : m_impl(impl)
    , m_client(client)
{
    m_impl->_getPublisher().subscribeToAllChanges(*this);

    m_connectionStatusRegistrationID = m_client->subscribeToConnectionStatus(std::bind(&SimpleArrayInterfaceService::onConnectionStatusChanged, this, std::placeholders::_1));
    // subscribe to all property change request methods
    m_client->subscribeTopic(ApiGear::MQTT::Topic("tb.simple","SimpleArrayInterface",ApiGear::MQTT::Topic::TopicType::Operation,"_setpropBool"), this);
    m_client->subscribeTopic(ApiGear::MQTT::Topic("tb.simple","SimpleArrayInterface",ApiGear::MQTT::Topic::TopicType::Operation,"_setpropInt"), this);
    m_client->subscribeTopic(ApiGear::MQTT::Topic("tb.simple","SimpleArrayInterface",ApiGear::MQTT::Topic::TopicType::Operation,"_setpropInt32"), this);
    m_client->subscribeTopic(ApiGear::MQTT::Topic("tb.simple","SimpleArrayInterface",ApiGear::MQTT::Topic::TopicType::Operation,"_setpropInt64"), this);
    m_client->subscribeTopic(ApiGear::MQTT::Topic("tb.simple","SimpleArrayInterface",ApiGear::MQTT::Topic::TopicType::Operation,"_setpropFloat"), this);
    m_client->subscribeTopic(ApiGear::MQTT::Topic("tb.simple","SimpleArrayInterface",ApiGear::MQTT::Topic::TopicType::Operation,"_setpropFloat32"), this);
    m_client->subscribeTopic(ApiGear::MQTT::Topic("tb.simple","SimpleArrayInterface",ApiGear::MQTT::Topic::TopicType::Operation,"_setpropFloat64"), this);
    m_client->subscribeTopic(ApiGear::MQTT::Topic("tb.simple","SimpleArrayInterface",ApiGear::MQTT::Topic::TopicType::Operation,"_setpropString"), this);
    m_client->subscribeTopic(ApiGear::MQTT::Topic("tb.simple","SimpleArrayInterface",ApiGear::MQTT::Topic::TopicType::Operation,"funcBool"), this);
    m_client->subscribeTopic(ApiGear::MQTT::Topic("tb.simple","SimpleArrayInterface",ApiGear::MQTT::Topic::TopicType::Operation,"funcInt"), this);
    m_client->subscribeTopic(ApiGear::MQTT::Topic("tb.simple","SimpleArrayInterface",ApiGear::MQTT::Topic::TopicType::Operation,"funcInt32"), this);
    m_client->subscribeTopic(ApiGear::MQTT::Topic("tb.simple","SimpleArrayInterface",ApiGear::MQTT::Topic::TopicType::Operation,"funcInt64"), this);
    m_client->subscribeTopic(ApiGear::MQTT::Topic("tb.simple","SimpleArrayInterface",ApiGear::MQTT::Topic::TopicType::Operation,"funcFloat"), this);
    m_client->subscribeTopic(ApiGear::MQTT::Topic("tb.simple","SimpleArrayInterface",ApiGear::MQTT::Topic::TopicType::Operation,"funcFloat32"), this);
    m_client->subscribeTopic(ApiGear::MQTT::Topic("tb.simple","SimpleArrayInterface",ApiGear::MQTT::Topic::TopicType::Operation,"funcFloat64"), this);
    m_client->subscribeTopic(ApiGear::MQTT::Topic("tb.simple","SimpleArrayInterface",ApiGear::MQTT::Topic::TopicType::Operation,"funcString"), this);

}

SimpleArrayInterfaceService::~SimpleArrayInterfaceService()
{
    m_impl->_getPublisher().unsubscribeFromAllChanges(*this);

    m_client->unsubscribeToConnectionStatus(m_connectionStatusRegistrationID);
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("tb.simple","SimpleArrayInterface",ApiGear::MQTT::Topic::TopicType::Operation,"_setpropBool"), this);
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("tb.simple","SimpleArrayInterface",ApiGear::MQTT::Topic::TopicType::Operation,"_setpropInt"), this);
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("tb.simple","SimpleArrayInterface",ApiGear::MQTT::Topic::TopicType::Operation,"_setpropInt32"), this);
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("tb.simple","SimpleArrayInterface",ApiGear::MQTT::Topic::TopicType::Operation,"_setpropInt64"), this);
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("tb.simple","SimpleArrayInterface",ApiGear::MQTT::Topic::TopicType::Operation,"_setpropFloat"), this);
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("tb.simple","SimpleArrayInterface",ApiGear::MQTT::Topic::TopicType::Operation,"_setpropFloat32"), this);
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("tb.simple","SimpleArrayInterface",ApiGear::MQTT::Topic::TopicType::Operation,"_setpropFloat64"), this);
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("tb.simple","SimpleArrayInterface",ApiGear::MQTT::Topic::TopicType::Operation,"_setpropString"), this);
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("tb.simple","SimpleArrayInterface",ApiGear::MQTT::Topic::TopicType::Operation,"funcBool"), this);
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("tb.simple","SimpleArrayInterface",ApiGear::MQTT::Topic::TopicType::Operation,"funcInt"), this);
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("tb.simple","SimpleArrayInterface",ApiGear::MQTT::Topic::TopicType::Operation,"funcInt32"), this);
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("tb.simple","SimpleArrayInterface",ApiGear::MQTT::Topic::TopicType::Operation,"funcInt64"), this);
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("tb.simple","SimpleArrayInterface",ApiGear::MQTT::Topic::TopicType::Operation,"funcFloat"), this);
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("tb.simple","SimpleArrayInterface",ApiGear::MQTT::Topic::TopicType::Operation,"funcFloat32"), this);
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("tb.simple","SimpleArrayInterface",ApiGear::MQTT::Topic::TopicType::Operation,"funcFloat64"), this);
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("tb.simple","SimpleArrayInterface",ApiGear::MQTT::Topic::TopicType::Operation,"funcString"), this);
}

void SimpleArrayInterfaceService::onConnectionStatusChanged(bool connectionStatus)
{
    if(!connectionStatus)
    {
        return;
    }

    // send current values
    onPropBoolChanged(m_impl->getPropBool());
    onPropIntChanged(m_impl->getPropInt());
    onPropInt32Changed(m_impl->getPropInt32());
    onPropInt64Changed(m_impl->getPropInt64());
    onPropFloatChanged(m_impl->getPropFloat());
    onPropFloat32Changed(m_impl->getPropFloat32());
    onPropFloat64Changed(m_impl->getPropFloat64());
    onPropStringChanged(m_impl->getPropString());
}

void SimpleArrayInterfaceService::onInvoke(const ApiGear::MQTT::Topic& topic, const std::string& args, const ApiGear::MQTT::Topic& responseTopic, const std::string& correlationData)
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    const std::string& name = topic.getEntityName();
    if(name == "_setpropBool") {
        auto propBool = json_args.get<std::list<bool>>();
        m_impl->setPropBool(propBool);
        return;
    }
    if(name == "_setpropInt") {
        auto propInt = json_args.get<std::list<int>>();
        m_impl->setPropInt(propInt);
        return;
    }
    if(name == "_setpropInt32") {
        auto propInt32 = json_args.get<std::list<int32_t>>();
        m_impl->setPropInt32(propInt32);
        return;
    }
    if(name == "_setpropInt64") {
        auto propInt64 = json_args.get<std::list<int64_t>>();
        m_impl->setPropInt64(propInt64);
        return;
    }
    if(name == "_setpropFloat") {
        auto propFloat = json_args.get<std::list<float>>();
        m_impl->setPropFloat(propFloat);
        return;
    }
    if(name == "_setpropFloat32") {
        auto propFloat32 = json_args.get<std::list<float>>();
        m_impl->setPropFloat32(propFloat32);
        return;
    }
    if(name == "_setpropFloat64") {
        auto propFloat64 = json_args.get<std::list<double>>();
        m_impl->setPropFloat64(propFloat64);
        return;
    }
    if(name == "_setpropString") {
        auto propString = json_args.get<std::list<std::string>>();
        m_impl->setPropString(propString);
        return;
    }


    if(name == "funcBool") {
        const std::list<bool>& paramBool = json_args.at(0).get<std::list<bool>>();
        auto result = m_impl->funcBool(paramBool);
        m_client->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
        return;
    }
    if(name == "funcInt") {
        const std::list<int>& paramInt = json_args.at(0).get<std::list<int>>();
        auto result = m_impl->funcInt(paramInt);
        m_client->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
        return;
    }
    if(name == "funcInt32") {
        const std::list<int32_t>& paramInt32 = json_args.at(0).get<std::list<int32_t>>();
        auto result = m_impl->funcInt32(paramInt32);
        m_client->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
        return;
    }
    if(name == "funcInt64") {
        const std::list<int64_t>& paramInt64 = json_args.at(0).get<std::list<int64_t>>();
        auto result = m_impl->funcInt64(paramInt64);
        m_client->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
        return;
    }
    if(name == "funcFloat") {
        const std::list<float>& paramFloat = json_args.at(0).get<std::list<float>>();
        auto result = m_impl->funcFloat(paramFloat);
        m_client->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
        return;
    }
    if(name == "funcFloat32") {
        const std::list<float>& paramFloat32 = json_args.at(0).get<std::list<float>>();
        auto result = m_impl->funcFloat32(paramFloat32);
        m_client->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
        return;
    }
    if(name == "funcFloat64") {
        const std::list<double>& paramFloat = json_args.at(0).get<std::list<double>>();
        auto result = m_impl->funcFloat64(paramFloat);
        m_client->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
        return;
    }
    if(name == "funcString") {
        const std::list<std::string>& paramString = json_args.at(0).get<std::list<std::string>>();
        auto result = m_impl->funcString(paramString);
        m_client->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
        return;
    }
}
void SimpleArrayInterfaceService::onSigBool(const std::list<bool>& paramBool)
{
    if(m_client != nullptr) {
        const nlohmann::json& args = { paramBool };
        static const auto topic = ApiGear::MQTT::Topic("tb.simple","SimpleArrayInterface",ApiGear::MQTT::Topic::TopicType::Signal,"sigBool");
        m_client->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void SimpleArrayInterfaceService::onSigInt(const std::list<int>& paramInt)
{
    if(m_client != nullptr) {
        const nlohmann::json& args = { paramInt };
        static const auto topic = ApiGear::MQTT::Topic("tb.simple","SimpleArrayInterface",ApiGear::MQTT::Topic::TopicType::Signal,"sigInt");
        m_client->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void SimpleArrayInterfaceService::onSigInt32(const std::list<int32_t>& paramInt32)
{
    if(m_client != nullptr) {
        const nlohmann::json& args = { paramInt32 };
        static const auto topic = ApiGear::MQTT::Topic("tb.simple","SimpleArrayInterface",ApiGear::MQTT::Topic::TopicType::Signal,"sigInt32");
        m_client->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void SimpleArrayInterfaceService::onSigInt64(const std::list<int64_t>& paramInt64)
{
    if(m_client != nullptr) {
        const nlohmann::json& args = { paramInt64 };
        static const auto topic = ApiGear::MQTT::Topic("tb.simple","SimpleArrayInterface",ApiGear::MQTT::Topic::TopicType::Signal,"sigInt64");
        m_client->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void SimpleArrayInterfaceService::onSigFloat(const std::list<float>& paramFloat)
{
    if(m_client != nullptr) {
        const nlohmann::json& args = { paramFloat };
        static const auto topic = ApiGear::MQTT::Topic("tb.simple","SimpleArrayInterface",ApiGear::MQTT::Topic::TopicType::Signal,"sigFloat");
        m_client->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void SimpleArrayInterfaceService::onSigFloat32(const std::list<float>& paramFloa32)
{
    if(m_client != nullptr) {
        const nlohmann::json& args = { paramFloa32 };
        static const auto topic = ApiGear::MQTT::Topic("tb.simple","SimpleArrayInterface",ApiGear::MQTT::Topic::TopicType::Signal,"sigFloat32");
        m_client->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void SimpleArrayInterfaceService::onSigFloat64(const std::list<double>& paramFloat64)
{
    if(m_client != nullptr) {
        const nlohmann::json& args = { paramFloat64 };
        static const auto topic = ApiGear::MQTT::Topic("tb.simple","SimpleArrayInterface",ApiGear::MQTT::Topic::TopicType::Signal,"sigFloat64");
        m_client->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void SimpleArrayInterfaceService::onSigString(const std::list<std::string>& paramString)
{
    if(m_client != nullptr) {
        const nlohmann::json& args = { paramString };
        static const auto topic = ApiGear::MQTT::Topic("tb.simple","SimpleArrayInterface",ApiGear::MQTT::Topic::TopicType::Signal,"sigString");
        m_client->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void SimpleArrayInterfaceService::onPropBoolChanged(const std::list<bool>& propBool)
{
    if(m_client != nullptr) {
        static const auto topic = ApiGear::MQTT::Topic("tb.simple","SimpleArrayInterface",ApiGear::MQTT::Topic::TopicType::Property,"propBool");
        m_client->notifyPropertyChange(topic, nlohmann::json(propBool).dump());
    }
}
void SimpleArrayInterfaceService::onPropIntChanged(const std::list<int>& propInt)
{
    if(m_client != nullptr) {
        static const auto topic = ApiGear::MQTT::Topic("tb.simple","SimpleArrayInterface",ApiGear::MQTT::Topic::TopicType::Property,"propInt");
        m_client->notifyPropertyChange(topic, nlohmann::json(propInt).dump());
    }
}
void SimpleArrayInterfaceService::onPropInt32Changed(const std::list<int32_t>& propInt32)
{
    if(m_client != nullptr) {
        static const auto topic = ApiGear::MQTT::Topic("tb.simple","SimpleArrayInterface",ApiGear::MQTT::Topic::TopicType::Property,"propInt32");
        m_client->notifyPropertyChange(topic, nlohmann::json(propInt32).dump());
    }
}
void SimpleArrayInterfaceService::onPropInt64Changed(const std::list<int64_t>& propInt64)
{
    if(m_client != nullptr) {
        static const auto topic = ApiGear::MQTT::Topic("tb.simple","SimpleArrayInterface",ApiGear::MQTT::Topic::TopicType::Property,"propInt64");
        m_client->notifyPropertyChange(topic, nlohmann::json(propInt64).dump());
    }
}
void SimpleArrayInterfaceService::onPropFloatChanged(const std::list<float>& propFloat)
{
    if(m_client != nullptr) {
        static const auto topic = ApiGear::MQTT::Topic("tb.simple","SimpleArrayInterface",ApiGear::MQTT::Topic::TopicType::Property,"propFloat");
        m_client->notifyPropertyChange(topic, nlohmann::json(propFloat).dump());
    }
}
void SimpleArrayInterfaceService::onPropFloat32Changed(const std::list<float>& propFloat32)
{
    if(m_client != nullptr) {
        static const auto topic = ApiGear::MQTT::Topic("tb.simple","SimpleArrayInterface",ApiGear::MQTT::Topic::TopicType::Property,"propFloat32");
        m_client->notifyPropertyChange(topic, nlohmann::json(propFloat32).dump());
    }
}
void SimpleArrayInterfaceService::onPropFloat64Changed(const std::list<double>& propFloat64)
{
    if(m_client != nullptr) {
        static const auto topic = ApiGear::MQTT::Topic("tb.simple","SimpleArrayInterface",ApiGear::MQTT::Topic::TopicType::Property,"propFloat64");
        m_client->notifyPropertyChange(topic, nlohmann::json(propFloat64).dump());
    }
}
void SimpleArrayInterfaceService::onPropStringChanged(const std::list<std::string>& propString)
{
    if(m_client != nullptr) {
        static const auto topic = ApiGear::MQTT::Topic("tb.simple","SimpleArrayInterface",ApiGear::MQTT::Topic::TopicType::Property,"propString");
        m_client->notifyPropertyChange(topic, nlohmann::json(propString).dump());
    }
}
