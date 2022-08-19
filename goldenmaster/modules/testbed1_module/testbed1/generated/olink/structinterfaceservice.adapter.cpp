

#include "testbed1/generated/olink/structinterfaceservice.adapter.h"
#include "testbed1/generated/core/testbed1.json.adapter.h"
#include <iostream>

using namespace Test::Testbed1;
using namespace Test::Testbed1::olink;

StructInterfaceServiceAdapter::StructInterfaceServiceAdapter(IStructInterface& StructInterface, ApiGear::ObjectLink::RemoteRegistry& registry)
    : m_StructInterface(StructInterface)
    , m_node(nullptr)
    , m_registry(registry)
{
    m_StructInterface._getPublisher().subscribeToAllChanges(*this);
    m_registry.addObjectSource(this);
}

StructInterfaceServiceAdapter::~StructInterfaceServiceAdapter()
{
    m_registry.removeObjectSource(this);
    m_StructInterface._getPublisher().unsubscribeFromAllChanges(*this);
}

std::string StructInterfaceServiceAdapter::olinkObjectName() {
    return "testbed1.StructInterface";
}

nlohmann::json StructInterfaceServiceAdapter::olinkInvoke(std::string fcnName, nlohmann::json fcnArgs) {
    std::clog << fcnName << std::endl;
    std::string path = ApiGear::ObjectLink::Name::pathFromName(fcnName);
    if(path == "funcBool") {
        const StructBool& paramBool = fcnArgs.at(0);
        StructBool result = m_StructInterface.funcBool(paramBool);
        return result;
    }
    if(path == "funcInt") {
        const StructInt& paramInt = fcnArgs.at(0);
        StructBool result = m_StructInterface.funcInt(paramInt);
        return result;
    }
    if(path == "funcFloat") {
        const StructFloat& paramFloat = fcnArgs.at(0);
        StructFloat result = m_StructInterface.funcFloat(paramFloat);
        return result;
    }
    if(path == "funcString") {
        const StructString& paramString = fcnArgs.at(0);
        StructString result = m_StructInterface.funcString(paramString);
        return result;
    }
    return nlohmann::json();
}

void StructInterfaceServiceAdapter::olinkSetProperty(std::string name, nlohmann::json value) {
    std::clog << name << std::endl;
    std::string path = ApiGear::ObjectLink::Name::pathFromName(name);
    if(path == "propBool") {
        StructBool propBool = value.get<StructBool>();
        m_StructInterface.setPropBool(propBool);
    }
    if(path == "propInt") {
        StructInt propInt = value.get<StructInt>();
        m_StructInterface.setPropInt(propInt);
    }
    if(path == "propFloat") {
        StructFloat propFloat = value.get<StructFloat>();
        m_StructInterface.setPropFloat(propFloat);
    }
    if(path == "propString") {
        StructString propString = value.get<StructString>();
        m_StructInterface.setPropString(propString);
    } 
}

void StructInterfaceServiceAdapter::olinkLinked(std::string name, ApiGear::ObjectLink::IRemoteNode *node) {
    std::clog << name << std::endl;
    m_node = node;
}

void StructInterfaceServiceAdapter::olinkUnlinked(std::string name)
{
    std::clog << name << std::endl;
    m_node = nullptr;
}

nlohmann::json StructInterfaceServiceAdapter::olinkCollectProperties()
{
    return nlohmann::json::object({
        { "propBool", m_StructInterface.getPropBool() },
        { "propInt", m_StructInterface.getPropInt() },
        { "propFloat", m_StructInterface.getPropFloat() },
        { "propString", m_StructInterface.getPropString() }
    });
}
void StructInterfaceServiceAdapter::onSigBool(const StructBool& paramBool)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { paramBool };
        m_node->notifySignal("testbed1.StructInterface/sigBool", args);
    }
}
void StructInterfaceServiceAdapter::onSigInt(const StructInt& paramInt)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { paramInt };
        m_node->notifySignal("testbed1.StructInterface/sigInt", args);
    }
}
void StructInterfaceServiceAdapter::onSigFloat(const StructFloat& paramFloat)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { paramFloat };
        m_node->notifySignal("testbed1.StructInterface/sigFloat", args);
    }
}
void StructInterfaceServiceAdapter::onSigString(const StructString& paramString)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { paramString };
        m_node->notifySignal("testbed1.StructInterface/sigString", args);
    }
}
void StructInterfaceServiceAdapter::onPropBoolChanged(const StructBool& propBool)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("testbed1.StructInterface/propBool", propBool);
    }
}
void StructInterfaceServiceAdapter::onPropIntChanged(const StructInt& propInt)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("testbed1.StructInterface/propInt", propInt);
    }
}
void StructInterfaceServiceAdapter::onPropFloatChanged(const StructFloat& propFloat)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("testbed1.StructInterface/propFloat", propFloat);
    }
}
void StructInterfaceServiceAdapter::onPropStringChanged(const StructString& propString)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("testbed1.StructInterface/propString", propString);
    }
}

