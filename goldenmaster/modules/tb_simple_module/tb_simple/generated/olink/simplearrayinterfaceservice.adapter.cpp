

#include "tb_simple/generated/olink/simplearrayinterfaceservice.adapter.h"
#include "tb_simple/generated/core/tb_simple.json.adapter.h"
#include <iostream>

using namespace Test::TbSimple;
using namespace Test::TbSimple::olink;

SimpleArrayInterfaceServiceAdapter::SimpleArrayInterfaceServiceAdapter(ISimpleArrayInterface& SimpleArrayInterface, ApiGear::ObjectLink::RemoteRegistry& registry)
    : m_SimpleArrayInterface(SimpleArrayInterface)
    , m_node(nullptr)
    , m_registry(registry)
{
    m_SimpleArrayInterface._getPublisher().subscribeToAllChanges(*this);
    m_registry.addObjectSource(this);
}

SimpleArrayInterfaceServiceAdapter::~SimpleArrayInterfaceServiceAdapter()
{
    m_registry.removeObjectSource(this);
    m_SimpleArrayInterface._getPublisher().unsubscribeFromAllChanges(*this);
}

std::string SimpleArrayInterfaceServiceAdapter::olinkObjectName() {
    return "tb.simple.SimpleArrayInterface";
}

nlohmann::json SimpleArrayInterfaceServiceAdapter::olinkInvoke(std::string fcnName, nlohmann::json fcnArgs) {
    std::clog << fcnName << std::endl;
    std::string path = ApiGear::ObjectLink::Name::pathFromName(fcnName);
    if(path == "funcBool") {
        const std::list<bool>& paramBool = fcnArgs.at(0);
        std::list<bool> result = m_SimpleArrayInterface.funcBool(paramBool);
        return result;
    }
    if(path == "funcInt") {
        const std::list<int>& paramInt = fcnArgs.at(0);
        std::list<int> result = m_SimpleArrayInterface.funcInt(paramInt);
        return result;
    }
    if(path == "funcFloat") {
        const std::list<float>& paramFloat = fcnArgs.at(0);
        std::list<float> result = m_SimpleArrayInterface.funcFloat(paramFloat);
        return result;
    }
    if(path == "funcString") {
        const std::list<std::string>& paramString = fcnArgs.at(0);
        std::list<std::string> result = m_SimpleArrayInterface.funcString(paramString);
        return result;
    }
    return nlohmann::json();
}

void SimpleArrayInterfaceServiceAdapter::olinkSetProperty(std::string name, nlohmann::json value) {
    std::clog << name << std::endl;
    std::string path = ApiGear::ObjectLink::Name::pathFromName(name);
    if(path == "propBool") {
        std::list<bool> propBool = value.get<std::list<bool>>();
        m_SimpleArrayInterface.setPropBool(propBool);
    }
    if(path == "propInt") {
        std::list<int> propInt = value.get<std::list<int>>();
        m_SimpleArrayInterface.setPropInt(propInt);
    }
    if(path == "propFloat") {
        std::list<float> propFloat = value.get<std::list<float>>();
        m_SimpleArrayInterface.setPropFloat(propFloat);
    }
    if(path == "propString") {
        std::list<std::string> propString = value.get<std::list<std::string>>();
        m_SimpleArrayInterface.setPropString(propString);
    } 
}

void SimpleArrayInterfaceServiceAdapter::olinkLinked(std::string name, ApiGear::ObjectLink::IRemoteNode *node) {
    std::clog << name << std::endl;
    m_node = node;
}

void SimpleArrayInterfaceServiceAdapter::olinkUnlinked(std::string name)
{
    std::clog << name << std::endl;
    m_node = nullptr;
}

nlohmann::json SimpleArrayInterfaceServiceAdapter::olinkCollectProperties()
{
    return nlohmann::json::object({
        { "propBool", m_SimpleArrayInterface.getPropBool() },
        { "propInt", m_SimpleArrayInterface.getPropInt() },
        { "propFloat", m_SimpleArrayInterface.getPropFloat() },
        { "propString", m_SimpleArrayInterface.getPropString() }
    });
}
void SimpleArrayInterfaceServiceAdapter::onSigBool(const std::list<bool>& paramBool)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { paramBool };
        m_node->notifySignal("tb.simple.SimpleArrayInterface/sigBool", args);
    }
}
void SimpleArrayInterfaceServiceAdapter::onSigInt(const std::list<int>& paramInt)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { paramInt };
        m_node->notifySignal("tb.simple.SimpleArrayInterface/sigInt", args);
    }
}
void SimpleArrayInterfaceServiceAdapter::onSigFloat(const std::list<float>& paramFloat)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { paramFloat };
        m_node->notifySignal("tb.simple.SimpleArrayInterface/sigFloat", args);
    }
}
void SimpleArrayInterfaceServiceAdapter::onSigString(const std::list<std::string>& paramString)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { paramString };
        m_node->notifySignal("tb.simple.SimpleArrayInterface/sigString", args);
    }
}
void SimpleArrayInterfaceServiceAdapter::onPropBoolChanged(const std::list<bool>& propBool)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("tb.simple.SimpleArrayInterface/propBool", propBool);
    }
}
void SimpleArrayInterfaceServiceAdapter::onPropIntChanged(const std::list<int>& propInt)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("tb.simple.SimpleArrayInterface/propInt", propInt);
    }
}
void SimpleArrayInterfaceServiceAdapter::onPropFloatChanged(const std::list<float>& propFloat)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("tb.simple.SimpleArrayInterface/propFloat", propFloat);
    }
}
void SimpleArrayInterfaceServiceAdapter::onPropStringChanged(const std::list<std::string>& propString)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("tb.simple.SimpleArrayInterface/propString", propString);
    }
}

