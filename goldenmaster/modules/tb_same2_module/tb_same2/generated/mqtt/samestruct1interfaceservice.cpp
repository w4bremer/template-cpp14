#include "tb_same2/generated/mqtt/samestruct1interfaceservice.h"
#include "tb_same2/generated/core/tb_same2.json.adapter.h"
#include <iostream>

using namespace Test::TbSame2;
using namespace Test::TbSame2::MQTT;

SameStruct1InterfaceService::SameStruct1InterfaceService(std::shared_ptr<ISameStruct1Interface> impl, std::shared_ptr<ApiGear::MQTT::Service> service)
    : m_impl(impl)
    , m_service(service)
    , m_topics(createTopicMap())
{
    m_impl->_getPublisher().subscribeToAllChanges(*this);

    m_connectionStatusRegistrationID = m_service->subscribeToConnectionStatus([this](bool connectionStatus){ onConnectionStatusChanged(connectionStatus); });

    for (const auto& topic: m_topics)
    {
        m_service->subscribeTopic(topic. first, topic.second);
    }
}

SameStruct1InterfaceService::~SameStruct1InterfaceService()
{
    m_impl->_getPublisher().unsubscribeFromAllChanges(*this);

    m_service->unsubscribeToConnectionStatus(m_connectionStatusRegistrationID);

    for (const auto& topic: m_topics)
    {
        m_service->unsubscribeTopic(topic. first);
    }
}

std::map<std::string, ApiGear::MQTT::CallbackFunction> SameStruct1InterfaceService::createTopicMap()
{
    return {
        {std::string("tb.same2/SameStruct1Interface/set/prop1"), [this](const std::string& args, const std::string&, const std::string&){ this->onSetProp1(args); } },
        {std::string("tb.same2/SameStruct1Interface/rpc/func1"), [this](const std::string& args, const std::string& responseTopic, const std::string& correlationData) { this->onInvokeFunc1(args, responseTopic, correlationData); } },
    };
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
void SameStruct1InterfaceService::onSetProp1(const std::string& args) const
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    if (json_args.empty())
    {
        return;
    }

    auto prop1 = json_args.get<Struct1>();
    m_impl->setProp1(prop1);
}
void SameStruct1InterfaceService::onInvokeFunc1(const std::string& args, const std::string& responseTopic, const std::string& correlationData) const
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    const Struct1& param1 = json_args.at(0).get<Struct1>();
    auto result = m_impl->func1(param1);
    m_service->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
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
