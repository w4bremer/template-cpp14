#include "tb_same2/generated/mqtt/samestruct1interfaceservice.h"
#include "tb_same2/generated/core/tb_same2.json.adapter.h"
#include "apigear/mqtt/mqtttopic.h"
#include <iostream>

using namespace Test::TbSame2;
using namespace Test::TbSame2::MQTT;

SameStruct1InterfaceService::SameStruct1InterfaceService(std::shared_ptr<ISameStruct1Interface> impl, std::shared_ptr<ApiGear::MQTT::Service> service)
    : m_impl(impl)
    , m_service(service)
{
    m_impl->_getPublisher().subscribeToAllChanges(*this);

    m_connectionStatusRegistrationID = m_service->subscribeToConnectionStatus([this](bool connectionStatus){ onConnectionStatusChanged(connectionStatus); });
    // subscribe to all property change request methods
    m_service->subscribeTopic(std::string("tb.same2/SameStruct1Interface/set/prop1"), [this](const std::string& topic, const std::string& args, const std::string&, const std::string&){ onSetProperty(topic, args); });
    m_service->subscribeTopic(std::string("tb.same2/SameStruct1Interface/rpc/func1"), [this](const std::string& topic, const std::string& args, const std::string& responseTopic, const std::string& correlationData) { onInvoke(topic, args, responseTopic, correlationData); });

}

SameStruct1InterfaceService::~SameStruct1InterfaceService()
{
    m_impl->_getPublisher().unsubscribeFromAllChanges(*this);

    m_service->unsubscribeToConnectionStatus(m_connectionStatusRegistrationID);
    m_service->unsubscribeTopic(std::string("tb.same2/SameStruct1Interface/set/prop1"));
    m_service->unsubscribeTopic(std::string("tb.same2/SameStruct1Interface/rpc/func1"));
}

void SameStruct1InterfaceService::onConnectionStatusChanged(bool connectionStatus)
{
    if(!connectionStatus)
    {
        return;
    }

    // send current values
    onProp1Changed(m_impl->getProp1());
}

void SameStruct1InterfaceService::onSetProperty(const std::string& topic, const std::string& args)
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    const std::string& name = ApiGear::MQTT::Topic(topic).getEntityName();
    if(name == "prop1") {
        auto prop1 = json_args.get<Struct1>();
        m_impl->setProp1(prop1);
        return;
    }
}

void SameStruct1InterfaceService::onInvoke(const std::string& topic, const std::string& args, const std::string& responseTopic, const std::string& correlationData)
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    const std::string& name = ApiGear::MQTT::Topic(topic).getEntityName();


    if(name == "func1") {
        const Struct1& param1 = json_args.at(0).get<Struct1>();
        auto result = m_impl->func1(param1);
        m_service->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
        return;
    }
}
void SameStruct1InterfaceService::onSig1(const Struct1& param1)
{
    if(m_service != nullptr) {
        const nlohmann::json& args = { param1 };
        static const auto topic = std::string("tb.same2/SameStruct1Interface/sig/sig1");
        m_service->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void SameStruct1InterfaceService::onProp1Changed(const Struct1& prop1)
{
    if(m_service != nullptr) {
        static const auto topic = std::string("tb.same2/SameStruct1Interface/prop/prop1");
        m_service->notifyPropertyChange(topic, nlohmann::json(prop1).dump());
    }
}
