#include "testbed2/generated/mqtt/manyparaminterfaceservice.h"
#include "testbed2/generated/core/testbed2.json.adapter.h"
#include "apigear/mqtt/mqtttopic.h"
#include <iostream>

using namespace Test::Testbed2;
using namespace Test::Testbed2::MQTT;

ManyParamInterfaceService::ManyParamInterfaceService(std::shared_ptr<IManyParamInterface> impl, std::shared_ptr<ApiGear::MQTT::Service> service)
    : m_impl(impl)
    , m_service(service)
{
    m_impl->_getPublisher().subscribeToAllChanges(*this);

    m_connectionStatusRegistrationID = m_service->subscribeToConnectionStatus(std::bind(&ManyParamInterfaceService::onConnectionStatusChanged, this, std::placeholders::_1));
    // subscribe to all property change request methods
    m_service->subscribeTopic(std::string("testbed2/ManyParamInterface/set/prop1"), std::bind(&ManyParamInterfaceService::onSetProperty, this, std::placeholders::_1, std::placeholders::_2));
    m_service->subscribeTopic(std::string("testbed2/ManyParamInterface/set/prop2"), std::bind(&ManyParamInterfaceService::onSetProperty, this, std::placeholders::_1, std::placeholders::_2));
    m_service->subscribeTopic(std::string("testbed2/ManyParamInterface/set/prop3"), std::bind(&ManyParamInterfaceService::onSetProperty, this, std::placeholders::_1, std::placeholders::_2));
    m_service->subscribeTopic(std::string("testbed2/ManyParamInterface/set/prop4"), std::bind(&ManyParamInterfaceService::onSetProperty, this, std::placeholders::_1, std::placeholders::_2));
    m_service->subscribeTopic(std::string("testbed2/ManyParamInterface/rpc/func1"), std::bind(&ManyParamInterfaceService::onInvoke, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_service->subscribeTopic(std::string("testbed2/ManyParamInterface/rpc/func2"), std::bind(&ManyParamInterfaceService::onInvoke, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_service->subscribeTopic(std::string("testbed2/ManyParamInterface/rpc/func3"), std::bind(&ManyParamInterfaceService::onInvoke, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_service->subscribeTopic(std::string("testbed2/ManyParamInterface/rpc/func4"), std::bind(&ManyParamInterfaceService::onInvoke, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));

}

ManyParamInterfaceService::~ManyParamInterfaceService()
{
    m_impl->_getPublisher().unsubscribeFromAllChanges(*this);

    m_service->unsubscribeToConnectionStatus(m_connectionStatusRegistrationID);
    m_service->unsubscribeTopic(std::string("testbed2/ManyParamInterface/set/prop1"));
    m_service->unsubscribeTopic(std::string("testbed2/ManyParamInterface/set/prop2"));
    m_service->unsubscribeTopic(std::string("testbed2/ManyParamInterface/set/prop3"));
    m_service->unsubscribeTopic(std::string("testbed2/ManyParamInterface/set/prop4"));
    m_service->unsubscribeTopic(std::string("testbed2/ManyParamInterface/rpc/func1"));
    m_service->unsubscribeTopic(std::string("testbed2/ManyParamInterface/rpc/func2"));
    m_service->unsubscribeTopic(std::string("testbed2/ManyParamInterface/rpc/func3"));
    m_service->unsubscribeTopic(std::string("testbed2/ManyParamInterface/rpc/func4"));
}

void ManyParamInterfaceService::onConnectionStatusChanged(bool connectionStatus)
{
    if(!connectionStatus)
    {
        return;
    }

    // send current values
    onProp1Changed(m_impl->getProp1());
    onProp2Changed(m_impl->getProp2());
    onProp3Changed(m_impl->getProp3());
    onProp4Changed(m_impl->getProp4());
}

void ManyParamInterfaceService::onSetProperty(const std::string& topic, const std::string& args)
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    const std::string& name = ApiGear::MQTT::Topic(topic).getEntityName();
    if(name == "prop1") {
        auto prop1 = json_args.get<int>();
        m_impl->setProp1(prop1);
        return;
    }
    if(name == "prop2") {
        auto prop2 = json_args.get<int>();
        m_impl->setProp2(prop2);
        return;
    }
    if(name == "prop3") {
        auto prop3 = json_args.get<int>();
        m_impl->setProp3(prop3);
        return;
    }
    if(name == "prop4") {
        auto prop4 = json_args.get<int>();
        m_impl->setProp4(prop4);
        return;
    }
}

void ManyParamInterfaceService::onInvoke(const std::string& topic, const std::string& args, const std::string& responseTopic, const std::string& correlationData)
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    const std::string& name = ApiGear::MQTT::Topic(topic).getEntityName();


    if(name == "func1") {
        const int& param1 = json_args.at(0).get<int>();
        auto result = m_impl->func1(param1);
        m_service->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
        return;
    }
    if(name == "func2") {
        const int& param1 = json_args.at(0).get<int>();
        const int& param2 = json_args.at(1).get<int>();
        auto result = m_impl->func2(param1, param2);
        m_service->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
        return;
    }
    if(name == "func3") {
        const int& param1 = json_args.at(0).get<int>();
        const int& param2 = json_args.at(1).get<int>();
        const int& param3 = json_args.at(2).get<int>();
        auto result = m_impl->func3(param1, param2, param3);
        m_service->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
        return;
    }
    if(name == "func4") {
        const int& param1 = json_args.at(0).get<int>();
        const int& param2 = json_args.at(1).get<int>();
        const int& param3 = json_args.at(2).get<int>();
        const int& param4 = json_args.at(3).get<int>();
        auto result = m_impl->func4(param1, param2, param3, param4);
        m_service->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
        return;
    }
}
void ManyParamInterfaceService::onSig1(int param1)
{
    if(m_service != nullptr) {
        const nlohmann::json& args = { param1 };
        static const auto topic = std::string("testbed2/ManyParamInterface/sig/sig1");
        m_service->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void ManyParamInterfaceService::onSig2(int param1, int param2)
{
    if(m_service != nullptr) {
        const nlohmann::json& args = { param1, param2 };
        static const auto topic = std::string("testbed2/ManyParamInterface/sig/sig2");
        m_service->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void ManyParamInterfaceService::onSig3(int param1, int param2, int param3)
{
    if(m_service != nullptr) {
        const nlohmann::json& args = { param1, param2, param3 };
        static const auto topic = std::string("testbed2/ManyParamInterface/sig/sig3");
        m_service->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void ManyParamInterfaceService::onSig4(int param1, int param2, int param3, int param4)
{
    if(m_service != nullptr) {
        const nlohmann::json& args = { param1, param2, param3, param4 };
        static const auto topic = std::string("testbed2/ManyParamInterface/sig/sig4");
        m_service->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void ManyParamInterfaceService::onProp1Changed(int prop1)
{
    if(m_service != nullptr) {
        static const auto topic = std::string("testbed2/ManyParamInterface/prop/prop1");
        m_service->notifyPropertyChange(topic, nlohmann::json(prop1).dump());
    }
}
void ManyParamInterfaceService::onProp2Changed(int prop2)
{
    if(m_service != nullptr) {
        static const auto topic = std::string("testbed2/ManyParamInterface/prop/prop2");
        m_service->notifyPropertyChange(topic, nlohmann::json(prop2).dump());
    }
}
void ManyParamInterfaceService::onProp3Changed(int prop3)
{
    if(m_service != nullptr) {
        static const auto topic = std::string("testbed2/ManyParamInterface/prop/prop3");
        m_service->notifyPropertyChange(topic, nlohmann::json(prop3).dump());
    }
}
void ManyParamInterfaceService::onProp4Changed(int prop4)
{
    if(m_service != nullptr) {
        static const auto topic = std::string("testbed2/ManyParamInterface/prop/prop4");
        m_service->notifyPropertyChange(topic, nlohmann::json(prop4).dump());
    }
}
