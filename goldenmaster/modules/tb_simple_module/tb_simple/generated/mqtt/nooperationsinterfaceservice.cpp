#include "tb_simple/generated/mqtt/nooperationsinterfaceservice.h"
#include "tb_simple/generated/core/tb_simple.json.adapter.h"
#include <iostream>

using namespace Test::TbSimple;
using namespace Test::TbSimple::MQTT;

NoOperationsInterfaceService::NoOperationsInterfaceService(std::shared_ptr<INoOperationsInterface> impl, std::shared_ptr<ApiGear::MQTT::Service> service)
    : m_impl(impl)
    , m_service(service)
{
    m_impl->_getPublisher().subscribeToAllChanges(*this);

    m_connectionStatusRegistrationID = m_service->subscribeToConnectionStatus(std::bind(&NoOperationsInterfaceService::onConnectionStatusChanged, this, std::placeholders::_1));
    // subscribe to all property change request methods
    m_service->subscribeTopic(ApiGear::MQTT::Topic("tb.simple","NoOperationsInterface",ApiGear::MQTT::Topic::TopicType::Operation,"_setpropBool"), this);
    m_service->subscribeTopic(ApiGear::MQTT::Topic("tb.simple","NoOperationsInterface",ApiGear::MQTT::Topic::TopicType::Operation,"_setpropInt"), this);

}

NoOperationsInterfaceService::~NoOperationsInterfaceService()
{
    m_impl->_getPublisher().unsubscribeFromAllChanges(*this);

    m_service->unsubscribeToConnectionStatus(m_connectionStatusRegistrationID);
    m_service->unsubscribeTopic(ApiGear::MQTT::Topic("tb.simple","NoOperationsInterface",ApiGear::MQTT::Topic::TopicType::Operation,"_setpropBool"), this);
    m_service->unsubscribeTopic(ApiGear::MQTT::Topic("tb.simple","NoOperationsInterface",ApiGear::MQTT::Topic::TopicType::Operation,"_setpropInt"), this);
}

void NoOperationsInterfaceService::onConnectionStatusChanged(bool connectionStatus)
{
    if(!connectionStatus)
    {
        return;
    }

    // send current values
    onPropBoolChanged(m_impl->getPropBool());
    onPropIntChanged(m_impl->getPropInt());
}

void NoOperationsInterfaceService::onInvoke(const ApiGear::MQTT::Topic& topic, const std::string& args, const ApiGear::MQTT::Topic& responseTopic, const std::string& correlationData)
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

    // no operations with return value
    (void) responseTopic;
    (void) correlationData;

}
void NoOperationsInterfaceService::onSigVoid()
{
    if(m_service != nullptr) {
        const nlohmann::json& args = {  };
        static const auto topic = ApiGear::MQTT::Topic("tb.simple","NoOperationsInterface",ApiGear::MQTT::Topic::TopicType::Signal,"sigVoid");
        m_service->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void NoOperationsInterfaceService::onSigBool(bool paramBool)
{
    if(m_service != nullptr) {
        const nlohmann::json& args = { paramBool };
        static const auto topic = ApiGear::MQTT::Topic("tb.simple","NoOperationsInterface",ApiGear::MQTT::Topic::TopicType::Signal,"sigBool");
        m_service->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void NoOperationsInterfaceService::onPropBoolChanged(bool propBool)
{
    if(m_service != nullptr) {
        static const auto topic = ApiGear::MQTT::Topic("tb.simple","NoOperationsInterface",ApiGear::MQTT::Topic::TopicType::Property,"propBool");
        m_service->notifyPropertyChange(topic, nlohmann::json(propBool).dump());
    }
}
void NoOperationsInterfaceService::onPropIntChanged(int propInt)
{
    if(m_service != nullptr) {
        static const auto topic = ApiGear::MQTT::Topic("tb.simple","NoOperationsInterface",ApiGear::MQTT::Topic::TopicType::Property,"propInt");
        m_service->notifyPropertyChange(topic, nlohmann::json(propInt).dump());
    }
}
