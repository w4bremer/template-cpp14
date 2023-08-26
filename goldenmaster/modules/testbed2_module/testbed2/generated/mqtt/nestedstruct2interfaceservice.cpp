#include "testbed2/generated/mqtt/nestedstruct2interfaceservice.h"
#include "testbed2/generated/core/testbed2.json.adapter.h"
#include <iostream>

using namespace Test::Testbed2;
using namespace Test::Testbed2::MQTT;

namespace {
    std::map<std::string, ApiGear::MQTT::CallbackFunction> createTopicMap(NestedStruct2InterfaceService* service)
    {
        return {
            {std::string("testbed2/NestedStruct2Interface/set/prop1"), [service](const std::string& args, const std::string&, const std::string&){ service->onSetProp1(args); } },
            {std::string("testbed2/NestedStruct2Interface/set/prop2"), [service](const std::string& args, const std::string&, const std::string&){ service->onSetProp2(args); } },
            {std::string("testbed2/NestedStruct2Interface/rpc/func1"), [service](const std::string& args, const std::string& responseTopic, const std::string& correlationData) { service->onInvokeFunc1(args, responseTopic, correlationData); } },
            {std::string("testbed2/NestedStruct2Interface/rpc/func2"), [service](const std::string& args, const std::string& responseTopic, const std::string& correlationData) { service->onInvokeFunc2(args, responseTopic, correlationData); } },
        };
    };
}

NestedStruct2InterfaceService::NestedStruct2InterfaceService(std::shared_ptr<INestedStruct2Interface> impl, std::shared_ptr<ApiGear::MQTT::Service> service)
    : m_impl(impl)
    , m_service(service)
    , m_topics(createTopicMap(this))
{
    m_impl->_getPublisher().subscribeToAllChanges(*this);

    m_connectionStatusRegistrationID = m_service->subscribeToConnectionStatus([this](bool connectionStatus){ onConnectionStatusChanged(connectionStatus); });

    for (const auto& topic: m_topics)
    {
        m_service->subscribeTopic(topic. first, topic.second);
    }
}

NestedStruct2InterfaceService::~NestedStruct2InterfaceService()
{
    m_impl->_getPublisher().unsubscribeFromAllChanges(*this);

    m_service->unsubscribeToConnectionStatus(m_connectionStatusRegistrationID);

    for (const auto& topic: m_topics)
    {
        m_service->unsubscribeTopic(topic. first);
    }
}

void NestedStruct2InterfaceService::onConnectionStatusChanged(bool connectionStatus)
{
    if(!connectionStatus)
    {
        return;
    }

    // send current values
    onProp1Changed(m_impl->getProp1());
    onProp2Changed(m_impl->getProp2());
}
void NestedStruct2InterfaceService::onSetProp1(const std::string& args) const
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    if (json_args.empty())
    {
        return;
    }

    auto prop1 = json_args.get<NestedStruct1>();
    m_impl->setProp1(prop1);
}
void NestedStruct2InterfaceService::onSetProp2(const std::string& args) const
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    if (json_args.empty())
    {
        return;
    }

    auto prop2 = json_args.get<NestedStruct2>();
    m_impl->setProp2(prop2);
}
void NestedStruct2InterfaceService::onInvokeFunc1(const std::string& args, const std::string& responseTopic, const std::string& correlationData) const
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    const NestedStruct1& param1 = json_args.at(0).get<NestedStruct1>();
    auto result = m_impl->func1(param1);
    m_service->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
}
void NestedStruct2InterfaceService::onInvokeFunc2(const std::string& args, const std::string& responseTopic, const std::string& correlationData) const
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    const NestedStruct1& param1 = json_args.at(0).get<NestedStruct1>();
    const NestedStruct2& param2 = json_args.at(1).get<NestedStruct2>();
    auto result = m_impl->func2(param1, param2);
    m_service->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
}
void NestedStruct2InterfaceService::onSig1(const NestedStruct1& param1)
{
    if(m_service != nullptr) {
        const nlohmann::json& args = { param1 };
        static const auto topic = std::string("testbed2/NestedStruct2Interface/sig/sig1");
        m_service->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void NestedStruct2InterfaceService::onSig2(const NestedStruct1& param1, const NestedStruct2& param2)
{
    if(m_service != nullptr) {
        const nlohmann::json& args = { param1, param2 };
        static const auto topic = std::string("testbed2/NestedStruct2Interface/sig/sig2");
        m_service->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void NestedStruct2InterfaceService::onProp1Changed(const NestedStruct1& prop1)
{
    if(m_service != nullptr) {
        static const auto topic = std::string("testbed2/NestedStruct2Interface/prop/prop1");
        m_service->notifyPropertyChange(topic, nlohmann::json(prop1).dump());
    }
}
void NestedStruct2InterfaceService::onProp2Changed(const NestedStruct2& prop2)
{
    if(m_service != nullptr) {
        static const auto topic = std::string("testbed2/NestedStruct2Interface/prop/prop2");
        m_service->notifyPropertyChange(topic, nlohmann::json(prop2).dump());
    }
}
