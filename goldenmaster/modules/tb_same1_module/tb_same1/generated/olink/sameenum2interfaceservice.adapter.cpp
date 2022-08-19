

#include "tb_same1/generated/olink/sameenum2interfaceservice.adapter.h"
#include "tb_same1/generated/core/tb_same1.json.adapter.h"
#include <iostream>

using namespace Test::TbSame1;
using namespace Test::TbSame1::olink;

SameEnum2InterfaceServiceAdapter::SameEnum2InterfaceServiceAdapter(ISameEnum2Interface& SameEnum2Interface, ApiGear::ObjectLink::RemoteRegistry& registry)
    : m_SameEnum2Interface(SameEnum2Interface)
    , m_node(nullptr)
    , m_registry(registry)
{
    m_SameEnum2Interface._getPublisher().subscribeToAllChanges(*this);
    m_registry.addObjectSource(this);
}

SameEnum2InterfaceServiceAdapter::~SameEnum2InterfaceServiceAdapter()
{
    m_registry.removeObjectSource(this);
    m_SameEnum2Interface._getPublisher().unsubscribeFromAllChanges(*this);
}

std::string SameEnum2InterfaceServiceAdapter::olinkObjectName() {
    return "tb.same1.SameEnum2Interface";
}

nlohmann::json SameEnum2InterfaceServiceAdapter::olinkInvoke(std::string fcnName, nlohmann::json fcnArgs) {
    std::clog << fcnName << std::endl;
    std::string path = ApiGear::ObjectLink::Name::pathFromName(fcnName);
    if(path == "func1") {
        const Enum1Enum& param1 = fcnArgs.at(0);
        Enum1Enum result = m_SameEnum2Interface.func1(param1);
        return result;
    }
    if(path == "func2") {
        const Enum1Enum& param1 = fcnArgs.at(0);
        const Enum2Enum& param2 = fcnArgs.at(1);
        Enum1Enum result = m_SameEnum2Interface.func2(param1, param2);
        return result;
    }
    return nlohmann::json();
}

void SameEnum2InterfaceServiceAdapter::olinkSetProperty(std::string name, nlohmann::json value) {
    std::clog << name << std::endl;
    std::string path = ApiGear::ObjectLink::Name::pathFromName(name);
    if(path == "prop1") {
        Enum1Enum prop1 = value.get<Enum1Enum>();
        m_SameEnum2Interface.setProp1(prop1);
    }
    if(path == "prop2") {
        Enum2Enum prop2 = value.get<Enum2Enum>();
        m_SameEnum2Interface.setProp2(prop2);
    } 
}

void SameEnum2InterfaceServiceAdapter::olinkLinked(std::string name, ApiGear::ObjectLink::IRemoteNode *node) {
    std::clog << name << std::endl;
    m_node = node;
}

void SameEnum2InterfaceServiceAdapter::olinkUnlinked(std::string name)
{
    std::clog << name << std::endl;
    m_node = nullptr;
}

nlohmann::json SameEnum2InterfaceServiceAdapter::olinkCollectProperties()
{
    return nlohmann::json::object({
        { "prop1", m_SameEnum2Interface.prop1() },
        { "prop2", m_SameEnum2Interface.prop2() }
    });
}
void SameEnum2InterfaceServiceAdapter::onSig1(const Enum1Enum& param1)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { param1 };
        m_node->notifySignal("tb.same1.SameEnum2Interface/sig1", args);
    }
}
void SameEnum2InterfaceServiceAdapter::onSig2(const Enum1Enum& param1,const Enum2Enum& param2)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { param1, param2 };
        m_node->notifySignal("tb.same1.SameEnum2Interface/sig2", args);
    }
}
void SameEnum2InterfaceServiceAdapter::onProp1Changed(const Enum1Enum& prop1)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("tb.same1.SameEnum2Interface/prop1", prop1);
    }
}
void SameEnum2InterfaceServiceAdapter::onProp2Changed(const Enum2Enum& prop2)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("tb.same1.SameEnum2Interface/prop2", prop2);
    }
}

