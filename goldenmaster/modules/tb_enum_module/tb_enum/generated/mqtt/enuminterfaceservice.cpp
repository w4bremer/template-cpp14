#include "tb_enum/generated/mqtt/enuminterfaceservice.h"
#include "tb_enum/generated/core/tb_enum.json.adapter.h"
#include "apigear/mqtt/mqtttopic.h"
#include <iostream>

using namespace Test::TbEnum;
using namespace Test::TbEnum::MQTT;

EnumInterfaceService::EnumInterfaceService(std::shared_ptr<IEnumInterface> impl, std::shared_ptr<ApiGear::MQTT::Service> service)
    : m_impl(impl)
    , m_service(service)
{
    m_impl->_getPublisher().subscribeToAllChanges(*this);

    m_connectionStatusRegistrationID = m_service->subscribeToConnectionStatus(std::bind(&EnumInterfaceService::onConnectionStatusChanged, this, std::placeholders::_1));
    // subscribe to all property change request methods
    m_service->subscribeTopic(std::string("tb.enum/EnumInterface/set/prop0"), std::bind(&EnumInterfaceService::onSetProperty, this, std::placeholders::_1, std::placeholders::_2));
    m_service->subscribeTopic(std::string("tb.enum/EnumInterface/set/prop1"), std::bind(&EnumInterfaceService::onSetProperty, this, std::placeholders::_1, std::placeholders::_2));
    m_service->subscribeTopic(std::string("tb.enum/EnumInterface/set/prop2"), std::bind(&EnumInterfaceService::onSetProperty, this, std::placeholders::_1, std::placeholders::_2));
    m_service->subscribeTopic(std::string("tb.enum/EnumInterface/set/prop3"), std::bind(&EnumInterfaceService::onSetProperty, this, std::placeholders::_1, std::placeholders::_2));
    m_service->subscribeTopic(std::string("tb.enum/EnumInterface/rpc/func0"), std::bind(&EnumInterfaceService::onInvoke, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_service->subscribeTopic(std::string("tb.enum/EnumInterface/rpc/func1"), std::bind(&EnumInterfaceService::onInvoke, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_service->subscribeTopic(std::string("tb.enum/EnumInterface/rpc/func2"), std::bind(&EnumInterfaceService::onInvoke, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_service->subscribeTopic(std::string("tb.enum/EnumInterface/rpc/func3"), std::bind(&EnumInterfaceService::onInvoke, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));

}

EnumInterfaceService::~EnumInterfaceService()
{
    m_impl->_getPublisher().unsubscribeFromAllChanges(*this);

    m_service->unsubscribeToConnectionStatus(m_connectionStatusRegistrationID);
    m_service->unsubscribeTopic(std::string("tb.enum/EnumInterface/set/prop0"));
    m_service->unsubscribeTopic(std::string("tb.enum/EnumInterface/set/prop1"));
    m_service->unsubscribeTopic(std::string("tb.enum/EnumInterface/set/prop2"));
    m_service->unsubscribeTopic(std::string("tb.enum/EnumInterface/set/prop3"));
    m_service->unsubscribeTopic(std::string("tb.enum/EnumInterface/rpc/func0"));
    m_service->unsubscribeTopic(std::string("tb.enum/EnumInterface/rpc/func1"));
    m_service->unsubscribeTopic(std::string("tb.enum/EnumInterface/rpc/func2"));
    m_service->unsubscribeTopic(std::string("tb.enum/EnumInterface/rpc/func3"));
}

void EnumInterfaceService::onConnectionStatusChanged(bool connectionStatus)
{
    if(!connectionStatus)
    {
        return;
    }

    // send current values
    onProp0Changed(m_impl->getProp0());
    onProp1Changed(m_impl->getProp1());
    onProp2Changed(m_impl->getProp2());
    onProp3Changed(m_impl->getProp3());
}

void EnumInterfaceService::onSetProperty(const std::string& topic, const std::string& args)
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    const std::string& name = ApiGear::MQTT::Topic(topic).getEntityName();
    if(name == "prop0") {
        auto prop0 = json_args.get<Enum0Enum>();
        m_impl->setProp0(prop0);
        return;
    }
    if(name == "prop1") {
        auto prop1 = json_args.get<Enum1Enum>();
        m_impl->setProp1(prop1);
        return;
    }
    if(name == "prop2") {
        auto prop2 = json_args.get<Enum2Enum>();
        m_impl->setProp2(prop2);
        return;
    }
    if(name == "prop3") {
        auto prop3 = json_args.get<Enum3Enum>();
        m_impl->setProp3(prop3);
        return;
    }
}

void EnumInterfaceService::onInvoke(const std::string& topic, const std::string& args, const std::string& responseTopic, const std::string& correlationData)
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    const std::string& name = ApiGear::MQTT::Topic(topic).getEntityName();


    if(name == "func0") {
        const Enum0Enum& param0 = json_args.at(0).get<Enum0Enum>();
        auto result = m_impl->func0(param0);
        m_service->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
        return;
    }
    if(name == "func1") {
        const Enum1Enum& param1 = json_args.at(0).get<Enum1Enum>();
        auto result = m_impl->func1(param1);
        m_service->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
        return;
    }
    if(name == "func2") {
        const Enum2Enum& param2 = json_args.at(0).get<Enum2Enum>();
        auto result = m_impl->func2(param2);
        m_service->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
        return;
    }
    if(name == "func3") {
        const Enum3Enum& param3 = json_args.at(0).get<Enum3Enum>();
        auto result = m_impl->func3(param3);
        m_service->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
        return;
    }
}
void EnumInterfaceService::onSig0(Enum0Enum param0)
{
    if(m_service != nullptr) {
        const nlohmann::json& args = { param0 };
        static const auto topic = std::string("tb.enum/EnumInterface/sig/sig0");
        m_service->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void EnumInterfaceService::onSig1(Enum1Enum param1)
{
    if(m_service != nullptr) {
        const nlohmann::json& args = { param1 };
        static const auto topic = std::string("tb.enum/EnumInterface/sig/sig1");
        m_service->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void EnumInterfaceService::onSig2(Enum2Enum param2)
{
    if(m_service != nullptr) {
        const nlohmann::json& args = { param2 };
        static const auto topic = std::string("tb.enum/EnumInterface/sig/sig2");
        m_service->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void EnumInterfaceService::onSig3(Enum3Enum param3)
{
    if(m_service != nullptr) {
        const nlohmann::json& args = { param3 };
        static const auto topic = std::string("tb.enum/EnumInterface/sig/sig3");
        m_service->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void EnumInterfaceService::onProp0Changed(Enum0Enum prop0)
{
    if(m_service != nullptr) {
        static const auto topic = std::string("tb.enum/EnumInterface/prop/prop0");
        m_service->notifyPropertyChange(topic, nlohmann::json(prop0).dump());
    }
}
void EnumInterfaceService::onProp1Changed(Enum1Enum prop1)
{
    if(m_service != nullptr) {
        static const auto topic = std::string("tb.enum/EnumInterface/prop/prop1");
        m_service->notifyPropertyChange(topic, nlohmann::json(prop1).dump());
    }
}
void EnumInterfaceService::onProp2Changed(Enum2Enum prop2)
{
    if(m_service != nullptr) {
        static const auto topic = std::string("tb.enum/EnumInterface/prop/prop2");
        m_service->notifyPropertyChange(topic, nlohmann::json(prop2).dump());
    }
}
void EnumInterfaceService::onProp3Changed(Enum3Enum prop3)
{
    if(m_service != nullptr) {
        static const auto topic = std::string("tb.enum/EnumInterface/prop/prop3");
        m_service->notifyPropertyChange(topic, nlohmann::json(prop3).dump());
    }
}
