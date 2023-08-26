#include "testbed1/generated/mqtt/structinterfaceservice.h"
#include "testbed1/generated/core/testbed1.json.adapter.h"
#include <iostream>

using namespace Test::Testbed1;
using namespace Test::Testbed1::MQTT;

namespace {
    std::map<std::string, ApiGear::MQTT::CallbackFunction> createTopicMap(StructInterfaceService* service)
    {
        return {
            {std::string("testbed1/StructInterface/set/propBool"), [service](const std::string& args, const std::string&, const std::string&){ service->onSetPropBool(args); } },
            {std::string("testbed1/StructInterface/set/propInt"), [service](const std::string& args, const std::string&, const std::string&){ service->onSetPropInt(args); } },
            {std::string("testbed1/StructInterface/set/propFloat"), [service](const std::string& args, const std::string&, const std::string&){ service->onSetPropFloat(args); } },
            {std::string("testbed1/StructInterface/set/propString"), [service](const std::string& args, const std::string&, const std::string&){ service->onSetPropString(args); } },
            {std::string("testbed1/StructInterface/rpc/funcBool"), [service](const std::string& args, const std::string& responseTopic, const std::string& correlationData) { service->onInvokeFuncBool(args, responseTopic, correlationData); } },
            {std::string("testbed1/StructInterface/rpc/funcInt"), [service](const std::string& args, const std::string& responseTopic, const std::string& correlationData) { service->onInvokeFuncInt(args, responseTopic, correlationData); } },
            {std::string("testbed1/StructInterface/rpc/funcFloat"), [service](const std::string& args, const std::string& responseTopic, const std::string& correlationData) { service->onInvokeFuncFloat(args, responseTopic, correlationData); } },
            {std::string("testbed1/StructInterface/rpc/funcString"), [service](const std::string& args, const std::string& responseTopic, const std::string& correlationData) { service->onInvokeFuncString(args, responseTopic, correlationData); } },
        };
    };
}

StructInterfaceService::StructInterfaceService(std::shared_ptr<IStructInterface> impl, std::shared_ptr<ApiGear::MQTT::Service> service)
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

StructInterfaceService::~StructInterfaceService()
{
    m_impl->_getPublisher().unsubscribeFromAllChanges(*this);

    m_service->unsubscribeToConnectionStatus(m_connectionStatusRegistrationID);

    for (const auto& topic: m_topics)
    {
        m_service->unsubscribeTopic(topic. first);
    }
}

void StructInterfaceService::onConnectionStatusChanged(bool connectionStatus)
{
    if(!connectionStatus)
    {
        return;
    }

    // send current values
    onPropBoolChanged(m_impl->getPropBool());
    onPropIntChanged(m_impl->getPropInt());
    onPropFloatChanged(m_impl->getPropFloat());
    onPropStringChanged(m_impl->getPropString());
}
void StructInterfaceService::onSetPropBool(const std::string& args) const
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    if (json_args.empty())
    {
        return;
    }

    auto propBool = json_args.get<StructBool>();
    m_impl->setPropBool(propBool);
}
void StructInterfaceService::onSetPropInt(const std::string& args) const
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    if (json_args.empty())
    {
        return;
    }

    auto propInt = json_args.get<StructInt>();
    m_impl->setPropInt(propInt);
}
void StructInterfaceService::onSetPropFloat(const std::string& args) const
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    if (json_args.empty())
    {
        return;
    }

    auto propFloat = json_args.get<StructFloat>();
    m_impl->setPropFloat(propFloat);
}
void StructInterfaceService::onSetPropString(const std::string& args) const
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    if (json_args.empty())
    {
        return;
    }

    auto propString = json_args.get<StructString>();
    m_impl->setPropString(propString);
}
void StructInterfaceService::onInvokeFuncBool(const std::string& args, const std::string& responseTopic, const std::string& correlationData) const
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    const StructBool& paramBool = json_args.at(0).get<StructBool>();
    auto result = m_impl->funcBool(paramBool);
    m_service->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
}
void StructInterfaceService::onInvokeFuncInt(const std::string& args, const std::string& responseTopic, const std::string& correlationData) const
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    const StructInt& paramInt = json_args.at(0).get<StructInt>();
    auto result = m_impl->funcInt(paramInt);
    m_service->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
}
void StructInterfaceService::onInvokeFuncFloat(const std::string& args, const std::string& responseTopic, const std::string& correlationData) const
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    const StructFloat& paramFloat = json_args.at(0).get<StructFloat>();
    auto result = m_impl->funcFloat(paramFloat);
    m_service->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
}
void StructInterfaceService::onInvokeFuncString(const std::string& args, const std::string& responseTopic, const std::string& correlationData) const
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    const StructString& paramString = json_args.at(0).get<StructString>();
    auto result = m_impl->funcString(paramString);
    m_service->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
}
void StructInterfaceService::onSigBool(const StructBool& paramBool)
{
    if(m_service != nullptr) {
        const nlohmann::json& args = { paramBool };
        static const auto topic = std::string("testbed1/StructInterface/sig/sigBool");
        m_service->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void StructInterfaceService::onSigInt(const StructInt& paramInt)
{
    if(m_service != nullptr) {
        const nlohmann::json& args = { paramInt };
        static const auto topic = std::string("testbed1/StructInterface/sig/sigInt");
        m_service->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void StructInterfaceService::onSigFloat(const StructFloat& paramFloat)
{
    if(m_service != nullptr) {
        const nlohmann::json& args = { paramFloat };
        static const auto topic = std::string("testbed1/StructInterface/sig/sigFloat");
        m_service->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void StructInterfaceService::onSigString(const StructString& paramString)
{
    if(m_service != nullptr) {
        const nlohmann::json& args = { paramString };
        static const auto topic = std::string("testbed1/StructInterface/sig/sigString");
        m_service->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void StructInterfaceService::onPropBoolChanged(const StructBool& propBool)
{
    if(m_service != nullptr) {
        static const auto topic = std::string("testbed1/StructInterface/prop/propBool");
        m_service->notifyPropertyChange(topic, nlohmann::json(propBool).dump());
    }
}
void StructInterfaceService::onPropIntChanged(const StructInt& propInt)
{
    if(m_service != nullptr) {
        static const auto topic = std::string("testbed1/StructInterface/prop/propInt");
        m_service->notifyPropertyChange(topic, nlohmann::json(propInt).dump());
    }
}
void StructInterfaceService::onPropFloatChanged(const StructFloat& propFloat)
{
    if(m_service != nullptr) {
        static const auto topic = std::string("testbed1/StructInterface/prop/propFloat");
        m_service->notifyPropertyChange(topic, nlohmann::json(propFloat).dump());
    }
}
void StructInterfaceService::onPropStringChanged(const StructString& propString)
{
    if(m_service != nullptr) {
        static const auto topic = std::string("testbed1/StructInterface/prop/propString");
        m_service->notifyPropertyChange(topic, nlohmann::json(propString).dump());
    }
}
