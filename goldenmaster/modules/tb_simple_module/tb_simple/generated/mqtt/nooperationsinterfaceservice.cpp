#include "tb_simple/generated/mqtt/nooperationsinterfaceservice.h"
#include "tb_simple/generated/core/tb_simple.json.adapter.h"
#include "apigear/mqtt/mqtttopic.h"
#include <iostream>

using namespace Test::TbSimple;
using namespace Test::TbSimple::MQTT;

NoOperationsInterfaceService::NoOperationsInterfaceService(std::shared_ptr<INoOperationsInterface> impl, std::shared_ptr<ApiGear::MQTT::Service> service)
    : m_impl(impl)
    , m_service(service)
{
    m_impl->_getPublisher().subscribeToAllChanges(*this);

    m_connectionStatusRegistrationID = m_service->subscribeToConnectionStatus([this](bool connectionStatus){ onConnectionStatusChanged(connectionStatus); });
    // subscribe to all property change request methods
    m_service->subscribeTopic(std::string("tb.simple/NoOperationsInterface/set/propBool"), [this](const std::string& topic, const std::string& args, const std::string&, const std::string&){ onSetProperty(topic, args); });
    m_service->subscribeTopic(std::string("tb.simple/NoOperationsInterface/set/propInt"), [this](const std::string& topic, const std::string& args, const std::string&, const std::string&){ onSetProperty(topic, args); });

}

NoOperationsInterfaceService::~NoOperationsInterfaceService()
{
    m_impl->_getPublisher().unsubscribeFromAllChanges(*this);

    m_service->unsubscribeToConnectionStatus(m_connectionStatusRegistrationID);
    m_service->unsubscribeTopic(std::string("tb.simple/NoOperationsInterface/set/propBool"));
    m_service->unsubscribeTopic(std::string("tb.simple/NoOperationsInterface/set/propInt"));
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

void NoOperationsInterfaceService::onSetProperty(const std::string& topic, const std::string& args)
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    const std::string& name = ApiGear::MQTT::Topic(topic).getEntityName();
    if(name == "propBool") {
        auto propBool = json_args.get<bool>();
        m_impl->setPropBool(propBool);
        return;
    }
    if(name == "propInt") {
        auto propInt = json_args.get<int>();
        m_impl->setPropInt(propInt);
        return;
    }
}

void NoOperationsInterfaceService::onInvoke(const std::string& topic, const std::string& args, const std::string& responseTopic, const std::string& correlationData)
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    const std::string& name = ApiGear::MQTT::Topic(topic).getEntityName();

    // no operations with return value
    (void) responseTopic;
    (void) correlationData;
    (void) name;

}
void NoOperationsInterfaceService::onSigVoid()
{
    if(m_service != nullptr) {
        const nlohmann::json& args = {  };
        static const auto topic = std::string("tb.simple/NoOperationsInterface/sig/sigVoid");
        m_service->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void NoOperationsInterfaceService::onSigBool(bool paramBool)
{
    if(m_service != nullptr) {
        const nlohmann::json& args = { paramBool };
        static const auto topic = std::string("tb.simple/NoOperationsInterface/sig/sigBool");
        m_service->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void NoOperationsInterfaceService::onPropBoolChanged(bool propBool)
{
    if(m_service != nullptr) {
        static const auto topic = std::string("tb.simple/NoOperationsInterface/prop/propBool");
        m_service->notifyPropertyChange(topic, nlohmann::json(propBool).dump());
    }
}
void NoOperationsInterfaceService::onPropIntChanged(int propInt)
{
    if(m_service != nullptr) {
        static const auto topic = std::string("tb.simple/NoOperationsInterface/prop/propInt");
        m_service->notifyPropertyChange(topic, nlohmann::json(propInt).dump());
    }
}
