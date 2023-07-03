#include "tb_simple/generated/mqtt/simpleinterfaceservice.h"
#include "tb_simple/generated/core/tb_simple.json.adapter.h"
#include <iostream>

using namespace Test::TbSimple;
using namespace Test::TbSimple::MQTT;

SimpleInterfaceService::SimpleInterfaceService(std::shared_ptr<ISimpleInterface> impl, std::shared_ptr<ApiGear::MQTT::Service> service)
    : m_impl(impl)
    , m_service(service)
{
    m_impl->_getPublisher().subscribeToAllChanges(*this);

    m_connectionStatusRegistrationID = m_service->subscribeToConnectionStatus(std::bind(&SimpleInterfaceService::onConnectionStatusChanged, this, std::placeholders::_1));
    // subscribe to all property change request methods
    m_service->subscribeTopic(ApiGear::MQTT::Topic("tb.simple","SimpleInterface",ApiGear::MQTT::Topic::TopicType::Operation,"_setpropBool"), std::bind(&SimpleInterfaceService::onInvoke, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_service->subscribeTopic(ApiGear::MQTT::Topic("tb.simple","SimpleInterface",ApiGear::MQTT::Topic::TopicType::Operation,"_setpropInt"), std::bind(&SimpleInterfaceService::onInvoke, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_service->subscribeTopic(ApiGear::MQTT::Topic("tb.simple","SimpleInterface",ApiGear::MQTT::Topic::TopicType::Operation,"_setpropInt32"), std::bind(&SimpleInterfaceService::onInvoke, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_service->subscribeTopic(ApiGear::MQTT::Topic("tb.simple","SimpleInterface",ApiGear::MQTT::Topic::TopicType::Operation,"_setpropInt64"), std::bind(&SimpleInterfaceService::onInvoke, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_service->subscribeTopic(ApiGear::MQTT::Topic("tb.simple","SimpleInterface",ApiGear::MQTT::Topic::TopicType::Operation,"_setpropFloat"), std::bind(&SimpleInterfaceService::onInvoke, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_service->subscribeTopic(ApiGear::MQTT::Topic("tb.simple","SimpleInterface",ApiGear::MQTT::Topic::TopicType::Operation,"_setpropFloat32"), std::bind(&SimpleInterfaceService::onInvoke, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_service->subscribeTopic(ApiGear::MQTT::Topic("tb.simple","SimpleInterface",ApiGear::MQTT::Topic::TopicType::Operation,"_setpropFloat64"), std::bind(&SimpleInterfaceService::onInvoke, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_service->subscribeTopic(ApiGear::MQTT::Topic("tb.simple","SimpleInterface",ApiGear::MQTT::Topic::TopicType::Operation,"_setpropString"), std::bind(&SimpleInterfaceService::onInvoke, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_service->subscribeTopic(ApiGear::MQTT::Topic("tb.simple","SimpleInterface",ApiGear::MQTT::Topic::TopicType::Operation,"funcBool"), std::bind(&SimpleInterfaceService::onInvoke, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_service->subscribeTopic(ApiGear::MQTT::Topic("tb.simple","SimpleInterface",ApiGear::MQTT::Topic::TopicType::Operation,"funcInt"), std::bind(&SimpleInterfaceService::onInvoke, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_service->subscribeTopic(ApiGear::MQTT::Topic("tb.simple","SimpleInterface",ApiGear::MQTT::Topic::TopicType::Operation,"funcInt32"), std::bind(&SimpleInterfaceService::onInvoke, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_service->subscribeTopic(ApiGear::MQTT::Topic("tb.simple","SimpleInterface",ApiGear::MQTT::Topic::TopicType::Operation,"funcInt64"), std::bind(&SimpleInterfaceService::onInvoke, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_service->subscribeTopic(ApiGear::MQTT::Topic("tb.simple","SimpleInterface",ApiGear::MQTT::Topic::TopicType::Operation,"funcFloat"), std::bind(&SimpleInterfaceService::onInvoke, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_service->subscribeTopic(ApiGear::MQTT::Topic("tb.simple","SimpleInterface",ApiGear::MQTT::Topic::TopicType::Operation,"funcFloat32"), std::bind(&SimpleInterfaceService::onInvoke, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_service->subscribeTopic(ApiGear::MQTT::Topic("tb.simple","SimpleInterface",ApiGear::MQTT::Topic::TopicType::Operation,"funcFloat64"), std::bind(&SimpleInterfaceService::onInvoke, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_service->subscribeTopic(ApiGear::MQTT::Topic("tb.simple","SimpleInterface",ApiGear::MQTT::Topic::TopicType::Operation,"funcString"), std::bind(&SimpleInterfaceService::onInvoke, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));

}

SimpleInterfaceService::~SimpleInterfaceService()
{
    m_impl->_getPublisher().unsubscribeFromAllChanges(*this);

    m_service->unsubscribeToConnectionStatus(m_connectionStatusRegistrationID);
    m_service->unsubscribeTopic(ApiGear::MQTT::Topic("tb.simple","SimpleInterface",ApiGear::MQTT::Topic::TopicType::Operation,"_setpropBool"), std::bind(&SimpleInterfaceService::onInvoke, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_service->unsubscribeTopic(ApiGear::MQTT::Topic("tb.simple","SimpleInterface",ApiGear::MQTT::Topic::TopicType::Operation,"_setpropInt"), std::bind(&SimpleInterfaceService::onInvoke, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_service->unsubscribeTopic(ApiGear::MQTT::Topic("tb.simple","SimpleInterface",ApiGear::MQTT::Topic::TopicType::Operation,"_setpropInt32"), std::bind(&SimpleInterfaceService::onInvoke, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_service->unsubscribeTopic(ApiGear::MQTT::Topic("tb.simple","SimpleInterface",ApiGear::MQTT::Topic::TopicType::Operation,"_setpropInt64"), std::bind(&SimpleInterfaceService::onInvoke, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_service->unsubscribeTopic(ApiGear::MQTT::Topic("tb.simple","SimpleInterface",ApiGear::MQTT::Topic::TopicType::Operation,"_setpropFloat"), std::bind(&SimpleInterfaceService::onInvoke, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_service->unsubscribeTopic(ApiGear::MQTT::Topic("tb.simple","SimpleInterface",ApiGear::MQTT::Topic::TopicType::Operation,"_setpropFloat32"), std::bind(&SimpleInterfaceService::onInvoke, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_service->unsubscribeTopic(ApiGear::MQTT::Topic("tb.simple","SimpleInterface",ApiGear::MQTT::Topic::TopicType::Operation,"_setpropFloat64"), std::bind(&SimpleInterfaceService::onInvoke, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_service->unsubscribeTopic(ApiGear::MQTT::Topic("tb.simple","SimpleInterface",ApiGear::MQTT::Topic::TopicType::Operation,"_setpropString"), std::bind(&SimpleInterfaceService::onInvoke, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_service->unsubscribeTopic(ApiGear::MQTT::Topic("tb.simple","SimpleInterface",ApiGear::MQTT::Topic::TopicType::Operation,"funcBool"), std::bind(&SimpleInterfaceService::onInvoke, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_service->unsubscribeTopic(ApiGear::MQTT::Topic("tb.simple","SimpleInterface",ApiGear::MQTT::Topic::TopicType::Operation,"funcInt"), std::bind(&SimpleInterfaceService::onInvoke, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_service->unsubscribeTopic(ApiGear::MQTT::Topic("tb.simple","SimpleInterface",ApiGear::MQTT::Topic::TopicType::Operation,"funcInt32"), std::bind(&SimpleInterfaceService::onInvoke, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_service->unsubscribeTopic(ApiGear::MQTT::Topic("tb.simple","SimpleInterface",ApiGear::MQTT::Topic::TopicType::Operation,"funcInt64"), std::bind(&SimpleInterfaceService::onInvoke, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_service->unsubscribeTopic(ApiGear::MQTT::Topic("tb.simple","SimpleInterface",ApiGear::MQTT::Topic::TopicType::Operation,"funcFloat"), std::bind(&SimpleInterfaceService::onInvoke, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_service->unsubscribeTopic(ApiGear::MQTT::Topic("tb.simple","SimpleInterface",ApiGear::MQTT::Topic::TopicType::Operation,"funcFloat32"), std::bind(&SimpleInterfaceService::onInvoke, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_service->unsubscribeTopic(ApiGear::MQTT::Topic("tb.simple","SimpleInterface",ApiGear::MQTT::Topic::TopicType::Operation,"funcFloat64"), std::bind(&SimpleInterfaceService::onInvoke, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_service->unsubscribeTopic(ApiGear::MQTT::Topic("tb.simple","SimpleInterface",ApiGear::MQTT::Topic::TopicType::Operation,"funcString"), std::bind(&SimpleInterfaceService::onInvoke, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
}

void SimpleInterfaceService::onConnectionStatusChanged(bool connectionStatus)
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

void SimpleInterfaceService::onInvoke(const ApiGear::MQTT::Topic& topic, const std::string& args, const ApiGear::MQTT::Topic& responseTopic, const std::string& correlationData)
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    const std::string& name = topic.getEntityName();
    if(name == "_setpropBool") {
        auto propBool = json_args.get<bool>();
        m_impl->setPropBool(propBool);
        return;
    }
    if(name == "_setpropInt") {
        auto propInt = json_args.get<int>();
        m_impl->setPropInt(propInt);
        return;
    }
    if(name == "_setpropInt32") {
        auto propInt32 = json_args.get<int32_t>();
        m_impl->setPropInt32(propInt32);
        return;
    }
    if(name == "_setpropInt64") {
        auto propInt64 = json_args.get<int64_t>();
        m_impl->setPropInt64(propInt64);
        return;
    }
    if(name == "_setpropFloat") {
        auto propFloat = json_args.get<float>();
        m_impl->setPropFloat(propFloat);
        return;
    }
    if(name == "_setpropFloat32") {
        auto propFloat32 = json_args.get<float>();
        m_impl->setPropFloat32(propFloat32);
        return;
    }
    if(name == "_setpropFloat64") {
        auto propFloat64 = json_args.get<double>();
        m_impl->setPropFloat64(propFloat64);
        return;
    }
    if(name == "_setpropString") {
        auto propString = json_args.get<std::string>();
        m_impl->setPropString(propString);
        return;
    }


    if(name == "funcBool") {
        const bool& paramBool = json_args.at(0).get<bool>();
        auto result = m_impl->funcBool(paramBool);
        m_service->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
        return;
    }
    if(name == "funcInt") {
        const int& paramInt = json_args.at(0).get<int>();
        auto result = m_impl->funcInt(paramInt);
        m_service->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
        return;
    }
    if(name == "funcInt32") {
        const int32_t& paramInt32 = json_args.at(0).get<int32_t>();
        auto result = m_impl->funcInt32(paramInt32);
        m_service->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
        return;
    }
    if(name == "funcInt64") {
        const int64_t& paramInt64 = json_args.at(0).get<int64_t>();
        auto result = m_impl->funcInt64(paramInt64);
        m_service->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
        return;
    }
    if(name == "funcFloat") {
        const float& paramFloat = json_args.at(0).get<float>();
        auto result = m_impl->funcFloat(paramFloat);
        m_service->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
        return;
    }
    if(name == "funcFloat32") {
        const float& paramFloat32 = json_args.at(0).get<float>();
        auto result = m_impl->funcFloat32(paramFloat32);
        m_service->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
        return;
    }
    if(name == "funcFloat64") {
        const double& paramFloat = json_args.at(0).get<double>();
        auto result = m_impl->funcFloat64(paramFloat);
        m_service->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
        return;
    }
    if(name == "funcString") {
        const std::string& paramString = json_args.at(0).get<std::string>();
        auto result = m_impl->funcString(paramString);
        m_service->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
        return;
    }
}
void SimpleInterfaceService::onSigBool(bool paramBool)
{
    if(m_service != nullptr) {
        const nlohmann::json& args = { paramBool };
        static const auto topic = ApiGear::MQTT::Topic("tb.simple","SimpleInterface",ApiGear::MQTT::Topic::TopicType::Signal,"sigBool");
        m_service->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void SimpleInterfaceService::onSigInt(int paramInt)
{
    if(m_service != nullptr) {
        const nlohmann::json& args = { paramInt };
        static const auto topic = ApiGear::MQTT::Topic("tb.simple","SimpleInterface",ApiGear::MQTT::Topic::TopicType::Signal,"sigInt");
        m_service->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void SimpleInterfaceService::onSigInt32(int32_t paramInt32)
{
    if(m_service != nullptr) {
        const nlohmann::json& args = { paramInt32 };
        static const auto topic = ApiGear::MQTT::Topic("tb.simple","SimpleInterface",ApiGear::MQTT::Topic::TopicType::Signal,"sigInt32");
        m_service->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void SimpleInterfaceService::onSigInt64(int64_t paramInt64)
{
    if(m_service != nullptr) {
        const nlohmann::json& args = { paramInt64 };
        static const auto topic = ApiGear::MQTT::Topic("tb.simple","SimpleInterface",ApiGear::MQTT::Topic::TopicType::Signal,"sigInt64");
        m_service->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void SimpleInterfaceService::onSigFloat(float paramFloat)
{
    if(m_service != nullptr) {
        const nlohmann::json& args = { paramFloat };
        static const auto topic = ApiGear::MQTT::Topic("tb.simple","SimpleInterface",ApiGear::MQTT::Topic::TopicType::Signal,"sigFloat");
        m_service->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void SimpleInterfaceService::onSigFloat32(float paramFloa32)
{
    if(m_service != nullptr) {
        const nlohmann::json& args = { paramFloa32 };
        static const auto topic = ApiGear::MQTT::Topic("tb.simple","SimpleInterface",ApiGear::MQTT::Topic::TopicType::Signal,"sigFloat32");
        m_service->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void SimpleInterfaceService::onSigFloat64(double paramFloat64)
{
    if(m_service != nullptr) {
        const nlohmann::json& args = { paramFloat64 };
        static const auto topic = ApiGear::MQTT::Topic("tb.simple","SimpleInterface",ApiGear::MQTT::Topic::TopicType::Signal,"sigFloat64");
        m_service->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void SimpleInterfaceService::onSigString(const std::string& paramString)
{
    if(m_service != nullptr) {
        const nlohmann::json& args = { paramString };
        static const auto topic = ApiGear::MQTT::Topic("tb.simple","SimpleInterface",ApiGear::MQTT::Topic::TopicType::Signal,"sigString");
        m_service->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void SimpleInterfaceService::onPropBoolChanged(bool propBool)
{
    if(m_service != nullptr) {
        static const auto topic = ApiGear::MQTT::Topic("tb.simple","SimpleInterface",ApiGear::MQTT::Topic::TopicType::Property,"propBool");
        m_service->notifyPropertyChange(topic, nlohmann::json(propBool).dump());
    }
}
void SimpleInterfaceService::onPropIntChanged(int propInt)
{
    if(m_service != nullptr) {
        static const auto topic = ApiGear::MQTT::Topic("tb.simple","SimpleInterface",ApiGear::MQTT::Topic::TopicType::Property,"propInt");
        m_service->notifyPropertyChange(topic, nlohmann::json(propInt).dump());
    }
}
void SimpleInterfaceService::onPropInt32Changed(int32_t propInt32)
{
    if(m_service != nullptr) {
        static const auto topic = ApiGear::MQTT::Topic("tb.simple","SimpleInterface",ApiGear::MQTT::Topic::TopicType::Property,"propInt32");
        m_service->notifyPropertyChange(topic, nlohmann::json(propInt32).dump());
    }
}
void SimpleInterfaceService::onPropInt64Changed(int64_t propInt64)
{
    if(m_service != nullptr) {
        static const auto topic = ApiGear::MQTT::Topic("tb.simple","SimpleInterface",ApiGear::MQTT::Topic::TopicType::Property,"propInt64");
        m_service->notifyPropertyChange(topic, nlohmann::json(propInt64).dump());
    }
}
void SimpleInterfaceService::onPropFloatChanged(float propFloat)
{
    if(m_service != nullptr) {
        static const auto topic = ApiGear::MQTT::Topic("tb.simple","SimpleInterface",ApiGear::MQTT::Topic::TopicType::Property,"propFloat");
        m_service->notifyPropertyChange(topic, nlohmann::json(propFloat).dump());
    }
}
void SimpleInterfaceService::onPropFloat32Changed(float propFloat32)
{
    if(m_service != nullptr) {
        static const auto topic = ApiGear::MQTT::Topic("tb.simple","SimpleInterface",ApiGear::MQTT::Topic::TopicType::Property,"propFloat32");
        m_service->notifyPropertyChange(topic, nlohmann::json(propFloat32).dump());
    }
}
void SimpleInterfaceService::onPropFloat64Changed(double propFloat64)
{
    if(m_service != nullptr) {
        static const auto topic = ApiGear::MQTT::Topic("tb.simple","SimpleInterface",ApiGear::MQTT::Topic::TopicType::Property,"propFloat64");
        m_service->notifyPropertyChange(topic, nlohmann::json(propFloat64).dump());
    }
}
void SimpleInterfaceService::onPropStringChanged(const std::string& propString)
{
    if(m_service != nullptr) {
        static const auto topic = ApiGear::MQTT::Topic("tb.simple","SimpleInterface",ApiGear::MQTT::Topic::TopicType::Property,"propString");
        m_service->notifyPropertyChange(topic, nlohmann::json(propString).dump());
    }
}