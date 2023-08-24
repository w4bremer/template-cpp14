#include "testbed1/generated/mqtt/structarrayinterfaceservice.h"
#include "testbed1/generated/core/testbed1.json.adapter.h"
#include "apigear/mqtt/mqtttopic.h"
#include <iostream>

using namespace Test::Testbed1;
using namespace Test::Testbed1::MQTT;

StructArrayInterfaceService::StructArrayInterfaceService(std::shared_ptr<IStructArrayInterface> impl, std::shared_ptr<ApiGear::MQTT::Service> service)
    : m_impl(impl)
    , m_service(service)
{
    m_impl->_getPublisher().subscribeToAllChanges(*this);

    m_connectionStatusRegistrationID = m_service->subscribeToConnectionStatus([this](bool connectionStatus){ onConnectionStatusChanged(connectionStatus); });
    // subscribe to all property change request methods
    m_service->subscribeTopic(std::string("testbed1/StructArrayInterface/set/propBool"), [this](const std::string& topic, const std::string& args, const std::string&, const std::string&){ onSetProperty(topic, args); });
    m_service->subscribeTopic(std::string("testbed1/StructArrayInterface/set/propInt"), [this](const std::string& topic, const std::string& args, const std::string&, const std::string&){ onSetProperty(topic, args); });
    m_service->subscribeTopic(std::string("testbed1/StructArrayInterface/set/propFloat"), [this](const std::string& topic, const std::string& args, const std::string&, const std::string&){ onSetProperty(topic, args); });
    m_service->subscribeTopic(std::string("testbed1/StructArrayInterface/set/propString"), [this](const std::string& topic, const std::string& args, const std::string&, const std::string&){ onSetProperty(topic, args); });
    m_service->subscribeTopic(std::string("testbed1/StructArrayInterface/rpc/funcBool"), [this](const std::string& topic, const std::string& args, const std::string& responseTopic, const std::string& correlationData) { onInvoke(topic, args, responseTopic, correlationData); });
    m_service->subscribeTopic(std::string("testbed1/StructArrayInterface/rpc/funcInt"), [this](const std::string& topic, const std::string& args, const std::string& responseTopic, const std::string& correlationData) { onInvoke(topic, args, responseTopic, correlationData); });
    m_service->subscribeTopic(std::string("testbed1/StructArrayInterface/rpc/funcFloat"), [this](const std::string& topic, const std::string& args, const std::string& responseTopic, const std::string& correlationData) { onInvoke(topic, args, responseTopic, correlationData); });
    m_service->subscribeTopic(std::string("testbed1/StructArrayInterface/rpc/funcString"), [this](const std::string& topic, const std::string& args, const std::string& responseTopic, const std::string& correlationData) { onInvoke(topic, args, responseTopic, correlationData); });

}

StructArrayInterfaceService::~StructArrayInterfaceService()
{
    m_impl->_getPublisher().unsubscribeFromAllChanges(*this);

    m_service->unsubscribeToConnectionStatus(m_connectionStatusRegistrationID);
    m_service->unsubscribeTopic(std::string("testbed1/StructArrayInterface/set/propBool"));
    m_service->unsubscribeTopic(std::string("testbed1/StructArrayInterface/set/propInt"));
    m_service->unsubscribeTopic(std::string("testbed1/StructArrayInterface/set/propFloat"));
    m_service->unsubscribeTopic(std::string("testbed1/StructArrayInterface/set/propString"));
    m_service->unsubscribeTopic(std::string("testbed1/StructArrayInterface/rpc/funcBool"));
    m_service->unsubscribeTopic(std::string("testbed1/StructArrayInterface/rpc/funcInt"));
    m_service->unsubscribeTopic(std::string("testbed1/StructArrayInterface/rpc/funcFloat"));
    m_service->unsubscribeTopic(std::string("testbed1/StructArrayInterface/rpc/funcString"));
}

void StructArrayInterfaceService::onConnectionStatusChanged(bool connectionStatus)
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

void StructArrayInterfaceService::onSetProperty(const std::string& topic, const std::string& args)
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    const std::string& name = ApiGear::MQTT::Topic(topic).getEntityName();
    if(name == "propBool") {
        auto propBool = json_args.get<std::list<StructBool>>();
        m_impl->setPropBool(propBool);
        return;
    }
    if(name == "propInt") {
        auto propInt = json_args.get<std::list<StructInt>>();
        m_impl->setPropInt(propInt);
        return;
    }
    if(name == "propFloat") {
        auto propFloat = json_args.get<std::list<StructFloat>>();
        m_impl->setPropFloat(propFloat);
        return;
    }
    if(name == "propString") {
        auto propString = json_args.get<std::list<StructString>>();
        m_impl->setPropString(propString);
        return;
    }
}

void StructArrayInterfaceService::onInvoke(const std::string& topic, const std::string& args, const std::string& responseTopic, const std::string& correlationData)
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    const std::string& name = ApiGear::MQTT::Topic(topic).getEntityName();


    if(name == "funcBool") {
        const std::list<StructBool>& paramBool = json_args.at(0).get<std::list<StructBool>>();
        auto result = m_impl->funcBool(paramBool);
        m_service->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
        return;
    }
    if(name == "funcInt") {
        const std::list<StructInt>& paramInt = json_args.at(0).get<std::list<StructInt>>();
        auto result = m_impl->funcInt(paramInt);
        m_service->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
        return;
    }
    if(name == "funcFloat") {
        const std::list<StructFloat>& paramFloat = json_args.at(0).get<std::list<StructFloat>>();
        auto result = m_impl->funcFloat(paramFloat);
        m_service->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
        return;
    }
    if(name == "funcString") {
        const std::list<StructString>& paramString = json_args.at(0).get<std::list<StructString>>();
        auto result = m_impl->funcString(paramString);
        m_service->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
        return;
    }
}
void StructArrayInterfaceService::onSigBool(const std::list<StructBool>& paramBool)
{
    if(m_service != nullptr) {
        const nlohmann::json& args = { paramBool };
        static const auto topic = std::string("testbed1/StructArrayInterface/sig/sigBool");
        m_service->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void StructArrayInterfaceService::onSigInt(const std::list<StructInt>& paramInt)
{
    if(m_service != nullptr) {
        const nlohmann::json& args = { paramInt };
        static const auto topic = std::string("testbed1/StructArrayInterface/sig/sigInt");
        m_service->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void StructArrayInterfaceService::onSigFloat(const std::list<StructFloat>& paramFloat)
{
    if(m_service != nullptr) {
        const nlohmann::json& args = { paramFloat };
        static const auto topic = std::string("testbed1/StructArrayInterface/sig/sigFloat");
        m_service->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void StructArrayInterfaceService::onSigString(const std::list<StructString>& paramString)
{
    if(m_service != nullptr) {
        const nlohmann::json& args = { paramString };
        static const auto topic = std::string("testbed1/StructArrayInterface/sig/sigString");
        m_service->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void StructArrayInterfaceService::onPropBoolChanged(const std::list<StructBool>& propBool)
{
    if(m_service != nullptr) {
        static const auto topic = std::string("testbed1/StructArrayInterface/prop/propBool");
        m_service->notifyPropertyChange(topic, nlohmann::json(propBool).dump());
    }
}
void StructArrayInterfaceService::onPropIntChanged(const std::list<StructInt>& propInt)
{
    if(m_service != nullptr) {
        static const auto topic = std::string("testbed1/StructArrayInterface/prop/propInt");
        m_service->notifyPropertyChange(topic, nlohmann::json(propInt).dump());
    }
}
void StructArrayInterfaceService::onPropFloatChanged(const std::list<StructFloat>& propFloat)
{
    if(m_service != nullptr) {
        static const auto topic = std::string("testbed1/StructArrayInterface/prop/propFloat");
        m_service->notifyPropertyChange(topic, nlohmann::json(propFloat).dump());
    }
}
void StructArrayInterfaceService::onPropStringChanged(const std::list<StructString>& propString)
{
    if(m_service != nullptr) {
        static const auto topic = std::string("testbed1/StructArrayInterface/prop/propString");
        m_service->notifyPropertyChange(topic, nlohmann::json(propString).dump());
    }
}
