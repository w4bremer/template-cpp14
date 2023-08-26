#include "tb_simple/generated/mqtt/simplearrayinterfaceservice.h"
#include "tb_simple/generated/core/tb_simple.json.adapter.h"
#include "apigear/mqtt/mqtttopic.h"
#include <iostream>

using namespace Test::TbSimple;
using namespace Test::TbSimple::MQTT;

namespace {
    std::map<std::string, ApiGear::MQTT::CallbackFunction> createTopicMap(SimpleArrayInterfaceService* service)
    {
        return {
            {std::string("tb.simple/SimpleArrayInterface/set/propBool"), [service](const std::string&, const std::string& args, const std::string&, const std::string&){ service->onSetPropBool(args); } },
            {std::string("tb.simple/SimpleArrayInterface/set/propInt"), [service](const std::string&, const std::string& args, const std::string&, const std::string&){ service->onSetPropInt(args); } },
            {std::string("tb.simple/SimpleArrayInterface/set/propInt32"), [service](const std::string&, const std::string& args, const std::string&, const std::string&){ service->onSetPropInt32(args); } },
            {std::string("tb.simple/SimpleArrayInterface/set/propInt64"), [service](const std::string&, const std::string& args, const std::string&, const std::string&){ service->onSetPropInt64(args); } },
            {std::string("tb.simple/SimpleArrayInterface/set/propFloat"), [service](const std::string&, const std::string& args, const std::string&, const std::string&){ service->onSetPropFloat(args); } },
            {std::string("tb.simple/SimpleArrayInterface/set/propFloat32"), [service](const std::string&, const std::string& args, const std::string&, const std::string&){ service->onSetPropFloat32(args); } },
            {std::string("tb.simple/SimpleArrayInterface/set/propFloat64"), [service](const std::string&, const std::string& args, const std::string&, const std::string&){ service->onSetPropFloat64(args); } },
            {std::string("tb.simple/SimpleArrayInterface/set/propString"), [service](const std::string&, const std::string& args, const std::string&, const std::string&){ service->onSetPropString(args); } },
            {std::string("tb.simple/SimpleArrayInterface/rpc/funcBool"), [service](const std::string& topic, const std::string& args, const std::string& responseTopic, const std::string& correlationData) { service->onInvoke(topic, args, responseTopic, correlationData); } },
            {std::string("tb.simple/SimpleArrayInterface/rpc/funcInt"), [service](const std::string& topic, const std::string& args, const std::string& responseTopic, const std::string& correlationData) { service->onInvoke(topic, args, responseTopic, correlationData); } },
            {std::string("tb.simple/SimpleArrayInterface/rpc/funcInt32"), [service](const std::string& topic, const std::string& args, const std::string& responseTopic, const std::string& correlationData) { service->onInvoke(topic, args, responseTopic, correlationData); } },
            {std::string("tb.simple/SimpleArrayInterface/rpc/funcInt64"), [service](const std::string& topic, const std::string& args, const std::string& responseTopic, const std::string& correlationData) { service->onInvoke(topic, args, responseTopic, correlationData); } },
            {std::string("tb.simple/SimpleArrayInterface/rpc/funcFloat"), [service](const std::string& topic, const std::string& args, const std::string& responseTopic, const std::string& correlationData) { service->onInvoke(topic, args, responseTopic, correlationData); } },
            {std::string("tb.simple/SimpleArrayInterface/rpc/funcFloat32"), [service](const std::string& topic, const std::string& args, const std::string& responseTopic, const std::string& correlationData) { service->onInvoke(topic, args, responseTopic, correlationData); } },
            {std::string("tb.simple/SimpleArrayInterface/rpc/funcFloat64"), [service](const std::string& topic, const std::string& args, const std::string& responseTopic, const std::string& correlationData) { service->onInvoke(topic, args, responseTopic, correlationData); } },
            {std::string("tb.simple/SimpleArrayInterface/rpc/funcString"), [service](const std::string& topic, const std::string& args, const std::string& responseTopic, const std::string& correlationData) { service->onInvoke(topic, args, responseTopic, correlationData); } },
        };
    };
}

SimpleArrayInterfaceService::SimpleArrayInterfaceService(std::shared_ptr<ISimpleArrayInterface> impl, std::shared_ptr<ApiGear::MQTT::Service> service)
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

SimpleArrayInterfaceService::~SimpleArrayInterfaceService()
{
    m_impl->_getPublisher().unsubscribeFromAllChanges(*this);

    m_service->unsubscribeToConnectionStatus(m_connectionStatusRegistrationID);

    for (const auto& topic: m_topics)
    {
        m_service->unsubscribeTopic(topic. first);
    }
}

void SimpleArrayInterfaceService::onConnectionStatusChanged(bool connectionStatus)
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
void SimpleArrayInterfaceService::onSetPropBool(const std::string& args) const
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    if (json_args.empty())
    {
        return;
    }

    auto propBool = json_args.get<std::list<bool>>();
    m_impl->setPropBool(propBool);
}
void SimpleArrayInterfaceService::onSetPropInt(const std::string& args) const
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    if (json_args.empty())
    {
        return;
    }

    auto propInt = json_args.get<std::list<int>>();
    m_impl->setPropInt(propInt);
}
void SimpleArrayInterfaceService::onSetPropInt32(const std::string& args) const
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    if (json_args.empty())
    {
        return;
    }

    auto propInt32 = json_args.get<std::list<int32_t>>();
    m_impl->setPropInt32(propInt32);
}
void SimpleArrayInterfaceService::onSetPropInt64(const std::string& args) const
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    if (json_args.empty())
    {
        return;
    }

    auto propInt64 = json_args.get<std::list<int64_t>>();
    m_impl->setPropInt64(propInt64);
}
void SimpleArrayInterfaceService::onSetPropFloat(const std::string& args) const
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    if (json_args.empty())
    {
        return;
    }

    auto propFloat = json_args.get<std::list<float>>();
    m_impl->setPropFloat(propFloat);
}
void SimpleArrayInterfaceService::onSetPropFloat32(const std::string& args) const
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    if (json_args.empty())
    {
        return;
    }

    auto propFloat32 = json_args.get<std::list<float>>();
    m_impl->setPropFloat32(propFloat32);
}
void SimpleArrayInterfaceService::onSetPropFloat64(const std::string& args) const
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    if (json_args.empty())
    {
        return;
    }

    auto propFloat64 = json_args.get<std::list<double>>();
    m_impl->setPropFloat64(propFloat64);
}
void SimpleArrayInterfaceService::onSetPropString(const std::string& args) const
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    if (json_args.empty())
    {
        return;
    }

    auto propString = json_args.get<std::list<std::string>>();
    m_impl->setPropString(propString);
}

void SimpleArrayInterfaceService::onInvoke(const std::string& topic, const std::string& args, const std::string& responseTopic, const std::string& correlationData)
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    const std::string& name = ApiGear::MQTT::Topic(topic).getEntityName();


    if(name == "funcBool") {
        const std::list<bool>& paramBool = json_args.at(0).get<std::list<bool>>();
        auto result = m_impl->funcBool(paramBool);
        m_service->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
        return;
    }
    if(name == "funcInt") {
        const std::list<int>& paramInt = json_args.at(0).get<std::list<int>>();
        auto result = m_impl->funcInt(paramInt);
        m_service->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
        return;
    }
    if(name == "funcInt32") {
        const std::list<int32_t>& paramInt32 = json_args.at(0).get<std::list<int32_t>>();
        auto result = m_impl->funcInt32(paramInt32);
        m_service->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
        return;
    }
    if(name == "funcInt64") {
        const std::list<int64_t>& paramInt64 = json_args.at(0).get<std::list<int64_t>>();
        auto result = m_impl->funcInt64(paramInt64);
        m_service->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
        return;
    }
    if(name == "funcFloat") {
        const std::list<float>& paramFloat = json_args.at(0).get<std::list<float>>();
        auto result = m_impl->funcFloat(paramFloat);
        m_service->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
        return;
    }
    if(name == "funcFloat32") {
        const std::list<float>& paramFloat32 = json_args.at(0).get<std::list<float>>();
        auto result = m_impl->funcFloat32(paramFloat32);
        m_service->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
        return;
    }
    if(name == "funcFloat64") {
        const std::list<double>& paramFloat = json_args.at(0).get<std::list<double>>();
        auto result = m_impl->funcFloat64(paramFloat);
        m_service->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
        return;
    }
    if(name == "funcString") {
        const std::list<std::string>& paramString = json_args.at(0).get<std::list<std::string>>();
        auto result = m_impl->funcString(paramString);
        m_service->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
        return;
    }
}
void SimpleArrayInterfaceService::onSigBool(const std::list<bool>& paramBool)
{
    if(m_service != nullptr) {
        const nlohmann::json& args = { paramBool };
        static const auto topic = std::string("tb.simple/SimpleArrayInterface/sig/sigBool");
        m_service->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void SimpleArrayInterfaceService::onSigInt(const std::list<int>& paramInt)
{
    if(m_service != nullptr) {
        const nlohmann::json& args = { paramInt };
        static const auto topic = std::string("tb.simple/SimpleArrayInterface/sig/sigInt");
        m_service->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void SimpleArrayInterfaceService::onSigInt32(const std::list<int32_t>& paramInt32)
{
    if(m_service != nullptr) {
        const nlohmann::json& args = { paramInt32 };
        static const auto topic = std::string("tb.simple/SimpleArrayInterface/sig/sigInt32");
        m_service->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void SimpleArrayInterfaceService::onSigInt64(const std::list<int64_t>& paramInt64)
{
    if(m_service != nullptr) {
        const nlohmann::json& args = { paramInt64 };
        static const auto topic = std::string("tb.simple/SimpleArrayInterface/sig/sigInt64");
        m_service->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void SimpleArrayInterfaceService::onSigFloat(const std::list<float>& paramFloat)
{
    if(m_service != nullptr) {
        const nlohmann::json& args = { paramFloat };
        static const auto topic = std::string("tb.simple/SimpleArrayInterface/sig/sigFloat");
        m_service->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void SimpleArrayInterfaceService::onSigFloat32(const std::list<float>& paramFloa32)
{
    if(m_service != nullptr) {
        const nlohmann::json& args = { paramFloa32 };
        static const auto topic = std::string("tb.simple/SimpleArrayInterface/sig/sigFloat32");
        m_service->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void SimpleArrayInterfaceService::onSigFloat64(const std::list<double>& paramFloat64)
{
    if(m_service != nullptr) {
        const nlohmann::json& args = { paramFloat64 };
        static const auto topic = std::string("tb.simple/SimpleArrayInterface/sig/sigFloat64");
        m_service->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void SimpleArrayInterfaceService::onSigString(const std::list<std::string>& paramString)
{
    if(m_service != nullptr) {
        const nlohmann::json& args = { paramString };
        static const auto topic = std::string("tb.simple/SimpleArrayInterface/sig/sigString");
        m_service->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void SimpleArrayInterfaceService::onPropBoolChanged(const std::list<bool>& propBool)
{
    if(m_service != nullptr) {
        static const auto topic = std::string("tb.simple/SimpleArrayInterface/prop/propBool");
        m_service->notifyPropertyChange(topic, nlohmann::json(propBool).dump());
    }
}
void SimpleArrayInterfaceService::onPropIntChanged(const std::list<int>& propInt)
{
    if(m_service != nullptr) {
        static const auto topic = std::string("tb.simple/SimpleArrayInterface/prop/propInt");
        m_service->notifyPropertyChange(topic, nlohmann::json(propInt).dump());
    }
}
void SimpleArrayInterfaceService::onPropInt32Changed(const std::list<int32_t>& propInt32)
{
    if(m_service != nullptr) {
        static const auto topic = std::string("tb.simple/SimpleArrayInterface/prop/propInt32");
        m_service->notifyPropertyChange(topic, nlohmann::json(propInt32).dump());
    }
}
void SimpleArrayInterfaceService::onPropInt64Changed(const std::list<int64_t>& propInt64)
{
    if(m_service != nullptr) {
        static const auto topic = std::string("tb.simple/SimpleArrayInterface/prop/propInt64");
        m_service->notifyPropertyChange(topic, nlohmann::json(propInt64).dump());
    }
}
void SimpleArrayInterfaceService::onPropFloatChanged(const std::list<float>& propFloat)
{
    if(m_service != nullptr) {
        static const auto topic = std::string("tb.simple/SimpleArrayInterface/prop/propFloat");
        m_service->notifyPropertyChange(topic, nlohmann::json(propFloat).dump());
    }
}
void SimpleArrayInterfaceService::onPropFloat32Changed(const std::list<float>& propFloat32)
{
    if(m_service != nullptr) {
        static const auto topic = std::string("tb.simple/SimpleArrayInterface/prop/propFloat32");
        m_service->notifyPropertyChange(topic, nlohmann::json(propFloat32).dump());
    }
}
void SimpleArrayInterfaceService::onPropFloat64Changed(const std::list<double>& propFloat64)
{
    if(m_service != nullptr) {
        static const auto topic = std::string("tb.simple/SimpleArrayInterface/prop/propFloat64");
        m_service->notifyPropertyChange(topic, nlohmann::json(propFloat64).dump());
    }
}
void SimpleArrayInterfaceService::onPropStringChanged(const std::list<std::string>& propString)
{
    if(m_service != nullptr) {
        static const auto topic = std::string("tb.simple/SimpleArrayInterface/prop/propString");
        m_service->notifyPropertyChange(topic, nlohmann::json(propString).dump());
    }
}
