#include "tb_simple/generated/mqtt/simpleinterfaceservice.h"
#include "tb_simple/generated/core/tb_simple.json.adapter.h"
#include <iostream>

using namespace Test::TbSimple;
using namespace Test::TbSimple::MQTT;

namespace {
    std::map<std::string, ApiGear::MQTT::CallbackFunction> createTopicMap(SimpleInterfaceService* service)
    {
        return {
            {std::string("tb.simple/SimpleInterface/set/propBool"), [service](const std::string& args, const std::string&, const std::string&){ service->onSetPropBool(args); } },
            {std::string("tb.simple/SimpleInterface/set/propInt"), [service](const std::string& args, const std::string&, const std::string&){ service->onSetPropInt(args); } },
            {std::string("tb.simple/SimpleInterface/set/propInt32"), [service](const std::string& args, const std::string&, const std::string&){ service->onSetPropInt32(args); } },
            {std::string("tb.simple/SimpleInterface/set/propInt64"), [service](const std::string& args, const std::string&, const std::string&){ service->onSetPropInt64(args); } },
            {std::string("tb.simple/SimpleInterface/set/propFloat"), [service](const std::string& args, const std::string&, const std::string&){ service->onSetPropFloat(args); } },
            {std::string("tb.simple/SimpleInterface/set/propFloat32"), [service](const std::string& args, const std::string&, const std::string&){ service->onSetPropFloat32(args); } },
            {std::string("tb.simple/SimpleInterface/set/propFloat64"), [service](const std::string& args, const std::string&, const std::string&){ service->onSetPropFloat64(args); } },
            {std::string("tb.simple/SimpleInterface/set/propString"), [service](const std::string& args, const std::string&, const std::string&){ service->onSetPropString(args); } },
            {std::string("tb.simple/SimpleInterface/rpc/funcBool"), [service](const std::string& args, const std::string& responseTopic, const std::string& correlationData) { service->onInvokeFuncBool(args, responseTopic, correlationData); } },
            {std::string("tb.simple/SimpleInterface/rpc/funcInt"), [service](const std::string& args, const std::string& responseTopic, const std::string& correlationData) { service->onInvokeFuncInt(args, responseTopic, correlationData); } },
            {std::string("tb.simple/SimpleInterface/rpc/funcInt32"), [service](const std::string& args, const std::string& responseTopic, const std::string& correlationData) { service->onInvokeFuncInt32(args, responseTopic, correlationData); } },
            {std::string("tb.simple/SimpleInterface/rpc/funcInt64"), [service](const std::string& args, const std::string& responseTopic, const std::string& correlationData) { service->onInvokeFuncInt64(args, responseTopic, correlationData); } },
            {std::string("tb.simple/SimpleInterface/rpc/funcFloat"), [service](const std::string& args, const std::string& responseTopic, const std::string& correlationData) { service->onInvokeFuncFloat(args, responseTopic, correlationData); } },
            {std::string("tb.simple/SimpleInterface/rpc/funcFloat32"), [service](const std::string& args, const std::string& responseTopic, const std::string& correlationData) { service->onInvokeFuncFloat32(args, responseTopic, correlationData); } },
            {std::string("tb.simple/SimpleInterface/rpc/funcFloat64"), [service](const std::string& args, const std::string& responseTopic, const std::string& correlationData) { service->onInvokeFuncFloat64(args, responseTopic, correlationData); } },
            {std::string("tb.simple/SimpleInterface/rpc/funcString"), [service](const std::string& args, const std::string& responseTopic, const std::string& correlationData) { service->onInvokeFuncString(args, responseTopic, correlationData); } },
        };
    };
}

SimpleInterfaceService::SimpleInterfaceService(std::shared_ptr<ISimpleInterface> impl, std::shared_ptr<ApiGear::MQTT::Service> service)
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

SimpleInterfaceService::~SimpleInterfaceService()
{
    m_impl->_getPublisher().unsubscribeFromAllChanges(*this);

    m_service->unsubscribeToConnectionStatus(m_connectionStatusRegistrationID);

    for (const auto& topic: m_topics)
    {
        m_service->unsubscribeTopic(topic. first);
    }
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
void SimpleInterfaceService::onSetPropBool(const std::string& args) const
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    if (json_args.empty())
    {
        return;
    }

    auto propBool = json_args.get<bool>();
    m_impl->setPropBool(propBool);
}
void SimpleInterfaceService::onSetPropInt(const std::string& args) const
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    if (json_args.empty())
    {
        return;
    }

    auto propInt = json_args.get<int>();
    m_impl->setPropInt(propInt);
}
void SimpleInterfaceService::onSetPropInt32(const std::string& args) const
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    if (json_args.empty())
    {
        return;
    }

    auto propInt32 = json_args.get<int32_t>();
    m_impl->setPropInt32(propInt32);
}
void SimpleInterfaceService::onSetPropInt64(const std::string& args) const
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    if (json_args.empty())
    {
        return;
    }

    auto propInt64 = json_args.get<int64_t>();
    m_impl->setPropInt64(propInt64);
}
void SimpleInterfaceService::onSetPropFloat(const std::string& args) const
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    if (json_args.empty())
    {
        return;
    }

    auto propFloat = json_args.get<float>();
    m_impl->setPropFloat(propFloat);
}
void SimpleInterfaceService::onSetPropFloat32(const std::string& args) const
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    if (json_args.empty())
    {
        return;
    }

    auto propFloat32 = json_args.get<float>();
    m_impl->setPropFloat32(propFloat32);
}
void SimpleInterfaceService::onSetPropFloat64(const std::string& args) const
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    if (json_args.empty())
    {
        return;
    }

    auto propFloat64 = json_args.get<double>();
    m_impl->setPropFloat64(propFloat64);
}
void SimpleInterfaceService::onSetPropString(const std::string& args) const
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    if (json_args.empty())
    {
        return;
    }

    auto propString = json_args.get<std::string>();
    m_impl->setPropString(propString);
}
void SimpleInterfaceService::onInvokeFuncBool(const std::string& args, const std::string& responseTopic, const std::string& correlationData) const
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    const bool& paramBool = json_args.at(0).get<bool>();
    auto result = m_impl->funcBool(paramBool);
    m_service->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
}
void SimpleInterfaceService::onInvokeFuncInt(const std::string& args, const std::string& responseTopic, const std::string& correlationData) const
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    const int& paramInt = json_args.at(0).get<int>();
    auto result = m_impl->funcInt(paramInt);
    m_service->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
}
void SimpleInterfaceService::onInvokeFuncInt32(const std::string& args, const std::string& responseTopic, const std::string& correlationData) const
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    const int32_t& paramInt32 = json_args.at(0).get<int32_t>();
    auto result = m_impl->funcInt32(paramInt32);
    m_service->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
}
void SimpleInterfaceService::onInvokeFuncInt64(const std::string& args, const std::string& responseTopic, const std::string& correlationData) const
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    const int64_t& paramInt64 = json_args.at(0).get<int64_t>();
    auto result = m_impl->funcInt64(paramInt64);
    m_service->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
}
void SimpleInterfaceService::onInvokeFuncFloat(const std::string& args, const std::string& responseTopic, const std::string& correlationData) const
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    const float& paramFloat = json_args.at(0).get<float>();
    auto result = m_impl->funcFloat(paramFloat);
    m_service->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
}
void SimpleInterfaceService::onInvokeFuncFloat32(const std::string& args, const std::string& responseTopic, const std::string& correlationData) const
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    const float& paramFloat32 = json_args.at(0).get<float>();
    auto result = m_impl->funcFloat32(paramFloat32);
    m_service->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
}
void SimpleInterfaceService::onInvokeFuncFloat64(const std::string& args, const std::string& responseTopic, const std::string& correlationData) const
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    const double& paramFloat = json_args.at(0).get<double>();
    auto result = m_impl->funcFloat64(paramFloat);
    m_service->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
}
void SimpleInterfaceService::onInvokeFuncString(const std::string& args, const std::string& responseTopic, const std::string& correlationData) const
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    const std::string& paramString = json_args.at(0).get<std::string>();
    auto result = m_impl->funcString(paramString);
    m_service->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
}
void SimpleInterfaceService::onSigBool(bool paramBool)
{
    if(m_service != nullptr) {
        const nlohmann::json& args = { paramBool };
        static const auto topic = std::string("tb.simple/SimpleInterface/sig/sigBool");
        m_service->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void SimpleInterfaceService::onSigInt(int paramInt)
{
    if(m_service != nullptr) {
        const nlohmann::json& args = { paramInt };
        static const auto topic = std::string("tb.simple/SimpleInterface/sig/sigInt");
        m_service->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void SimpleInterfaceService::onSigInt32(int32_t paramInt32)
{
    if(m_service != nullptr) {
        const nlohmann::json& args = { paramInt32 };
        static const auto topic = std::string("tb.simple/SimpleInterface/sig/sigInt32");
        m_service->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void SimpleInterfaceService::onSigInt64(int64_t paramInt64)
{
    if(m_service != nullptr) {
        const nlohmann::json& args = { paramInt64 };
        static const auto topic = std::string("tb.simple/SimpleInterface/sig/sigInt64");
        m_service->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void SimpleInterfaceService::onSigFloat(float paramFloat)
{
    if(m_service != nullptr) {
        const nlohmann::json& args = { paramFloat };
        static const auto topic = std::string("tb.simple/SimpleInterface/sig/sigFloat");
        m_service->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void SimpleInterfaceService::onSigFloat32(float paramFloa32)
{
    if(m_service != nullptr) {
        const nlohmann::json& args = { paramFloa32 };
        static const auto topic = std::string("tb.simple/SimpleInterface/sig/sigFloat32");
        m_service->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void SimpleInterfaceService::onSigFloat64(double paramFloat64)
{
    if(m_service != nullptr) {
        const nlohmann::json& args = { paramFloat64 };
        static const auto topic = std::string("tb.simple/SimpleInterface/sig/sigFloat64");
        m_service->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void SimpleInterfaceService::onSigString(const std::string& paramString)
{
    if(m_service != nullptr) {
        const nlohmann::json& args = { paramString };
        static const auto topic = std::string("tb.simple/SimpleInterface/sig/sigString");
        m_service->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void SimpleInterfaceService::onPropBoolChanged(bool propBool)
{
    if(m_service != nullptr) {
        static const auto topic = std::string("tb.simple/SimpleInterface/prop/propBool");
        m_service->notifyPropertyChange(topic, nlohmann::json(propBool).dump());
    }
}
void SimpleInterfaceService::onPropIntChanged(int propInt)
{
    if(m_service != nullptr) {
        static const auto topic = std::string("tb.simple/SimpleInterface/prop/propInt");
        m_service->notifyPropertyChange(topic, nlohmann::json(propInt).dump());
    }
}
void SimpleInterfaceService::onPropInt32Changed(int32_t propInt32)
{
    if(m_service != nullptr) {
        static const auto topic = std::string("tb.simple/SimpleInterface/prop/propInt32");
        m_service->notifyPropertyChange(topic, nlohmann::json(propInt32).dump());
    }
}
void SimpleInterfaceService::onPropInt64Changed(int64_t propInt64)
{
    if(m_service != nullptr) {
        static const auto topic = std::string("tb.simple/SimpleInterface/prop/propInt64");
        m_service->notifyPropertyChange(topic, nlohmann::json(propInt64).dump());
    }
}
void SimpleInterfaceService::onPropFloatChanged(float propFloat)
{
    if(m_service != nullptr) {
        static const auto topic = std::string("tb.simple/SimpleInterface/prop/propFloat");
        m_service->notifyPropertyChange(topic, nlohmann::json(propFloat).dump());
    }
}
void SimpleInterfaceService::onPropFloat32Changed(float propFloat32)
{
    if(m_service != nullptr) {
        static const auto topic = std::string("tb.simple/SimpleInterface/prop/propFloat32");
        m_service->notifyPropertyChange(topic, nlohmann::json(propFloat32).dump());
    }
}
void SimpleInterfaceService::onPropFloat64Changed(double propFloat64)
{
    if(m_service != nullptr) {
        static const auto topic = std::string("tb.simple/SimpleInterface/prop/propFloat64");
        m_service->notifyPropertyChange(topic, nlohmann::json(propFloat64).dump());
    }
}
void SimpleInterfaceService::onPropStringChanged(const std::string& propString)
{
    if(m_service != nullptr) {
        static const auto topic = std::string("tb.simple/SimpleInterface/prop/propString");
        m_service->notifyPropertyChange(topic, nlohmann::json(propString).dump());
    }
}
