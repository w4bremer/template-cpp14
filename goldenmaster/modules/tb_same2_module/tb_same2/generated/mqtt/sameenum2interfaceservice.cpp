#include "tb_same2/generated/mqtt/sameenum2interfaceservice.h"
#include "tb_same2/generated/core/tb_same2.json.adapter.h"
#include <iostream>

using namespace Test::TbSame2;
using namespace Test::TbSame2::MQTT;

namespace {
    std::map<std::string, ApiGear::MQTT::CallbackFunction> createTopicMap(SameEnum2InterfaceService* service)
    {
        return {
            {std::string("tb.same2/SameEnum2Interface/set/prop1"), [service](const std::string&, const std::string& args, const std::string&, const std::string&){ service->onSetProp1(args); } },
            {std::string("tb.same2/SameEnum2Interface/set/prop2"), [service](const std::string&, const std::string& args, const std::string&, const std::string&){ service->onSetProp2(args); } },
            {std::string("tb.same2/SameEnum2Interface/rpc/func1"), [service](const std::string&, const std::string& args, const std::string& responseTopic, const std::string& correlationData) { service->onInvokeFunc1(args, responseTopic, correlationData); } },
            {std::string("tb.same2/SameEnum2Interface/rpc/func2"), [service](const std::string&, const std::string& args, const std::string& responseTopic, const std::string& correlationData) { service->onInvokeFunc2(args, responseTopic, correlationData); } },
        };
    };
}

SameEnum2InterfaceService::SameEnum2InterfaceService(std::shared_ptr<ISameEnum2Interface> impl, std::shared_ptr<ApiGear::MQTT::Service> service)
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

SameEnum2InterfaceService::~SameEnum2InterfaceService()
{
    m_impl->_getPublisher().unsubscribeFromAllChanges(*this);

    m_service->unsubscribeToConnectionStatus(m_connectionStatusRegistrationID);

    for (const auto& topic: m_topics)
    {
        m_service->unsubscribeTopic(topic. first);
    }
}

void SameEnum2InterfaceService::onConnectionStatusChanged(bool connectionStatus)
{
    if(!connectionStatus)
    {
        return;
    }

    // send current values
    onProp1Changed(m_impl->getProp1());
    onProp2Changed(m_impl->getProp2());
}
void SameEnum2InterfaceService::onSetProp1(const std::string& args) const
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    if (json_args.empty())
    {
        return;
    }

    auto prop1 = json_args.get<Enum1Enum>();
    m_impl->setProp1(prop1);
}
void SameEnum2InterfaceService::onSetProp2(const std::string& args) const
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    if (json_args.empty())
    {
        return;
    }

    auto prop2 = json_args.get<Enum2Enum>();
    m_impl->setProp2(prop2);
}
void SameEnum2InterfaceService::onInvokeFunc1(const std::string& args, const std::string& responseTopic, const std::string& correlationData) const
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    const Enum1Enum& param1 = json_args.at(0).get<Enum1Enum>();
    auto result = m_impl->func1(param1);
    m_service->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
}
void SameEnum2InterfaceService::onInvokeFunc2(const std::string& args, const std::string& responseTopic, const std::string& correlationData) const
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    const Enum1Enum& param1 = json_args.at(0).get<Enum1Enum>();
    const Enum2Enum& param2 = json_args.at(1).get<Enum2Enum>();
    auto result = m_impl->func2(param1, param2);
    m_service->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
}
void SameEnum2InterfaceService::onSig1(Enum1Enum param1)
{
    if(m_service != nullptr) {
        const nlohmann::json& args = { param1 };
        static const auto topic = std::string("tb.same2/SameEnum2Interface/sig/sig1");
        m_service->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void SameEnum2InterfaceService::onSig2(Enum1Enum param1, Enum2Enum param2)
{
    if(m_service != nullptr) {
        const nlohmann::json& args = { param1, param2 };
        static const auto topic = std::string("tb.same2/SameEnum2Interface/sig/sig2");
        m_service->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void SameEnum2InterfaceService::onProp1Changed(Enum1Enum prop1)
{
    if(m_service != nullptr) {
        static const auto topic = std::string("tb.same2/SameEnum2Interface/prop/prop1");
        m_service->notifyPropertyChange(topic, nlohmann::json(prop1).dump());
    }
}
void SameEnum2InterfaceService::onProp2Changed(Enum2Enum prop2)
{
    if(m_service != nullptr) {
        static const auto topic = std::string("tb.same2/SameEnum2Interface/prop/prop2");
        m_service->notifyPropertyChange(topic, nlohmann::json(prop2).dump());
    }
}
