

#include "tb_same2/generated/olink/samestruct2interfaceservice.adapter.h"
#include "tb_same2/generated/core/tb_same2.json.adapter.h"
#include <iostream>

using namespace Test::TbSame2;
using namespace Test::TbSame2::olink;

SameStruct2InterfaceServiceAdapter::SameStruct2InterfaceServiceAdapter(ISameStruct2Interface& SameStruct2Interface, ApiGear::ObjectLink::RemoteRegistry& registry)
    : m_SameStruct2Interface(SameStruct2Interface)
    , m_node(nullptr)
    , m_registry(registry)
{
    m_SameStruct2Interface._getPublisher().subscribeToAllChanges(*this);
    m_registry.addObjectSource(this);
}

SameStruct2InterfaceServiceAdapter::~SameStruct2InterfaceServiceAdapter()
{
    m_registry.removeObjectSource(this);
    m_SameStruct2Interface._getPublisher().unsubscribeFromAllChanges(*this);
}

std::string SameStruct2InterfaceServiceAdapter::olinkObjectName() {
    return "tb.same2.SameStruct2Interface";
}

nlohmann::json SameStruct2InterfaceServiceAdapter::olinkInvoke(std::string fcnName, nlohmann::json fcnArgs) {
    std::clog << fcnName << std::endl;
    std::string path = ApiGear::ObjectLink::Name::pathFromName(fcnName);
    if(path == "func1") {
        const Struct1& param1 = fcnArgs.at(0);
        Struct1 result = m_SameStruct2Interface.func1(param1);
        return result;
    }
    if(path == "func2") {
        const Struct1& param1 = fcnArgs.at(0);
        const Struct2& param2 = fcnArgs.at(1);
        Struct1 result = m_SameStruct2Interface.func2(param1, param2);
        return result;
    }
    return nlohmann::json();
}

void SameStruct2InterfaceServiceAdapter::olinkSetProperty(std::string name, nlohmann::json value) {
    std::clog << name << std::endl;
    std::string path = ApiGear::ObjectLink::Name::pathFromName(name);
    if(path == "prop1") {
        Struct2 prop1 = value.get<Struct2>();
        m_SameStruct2Interface.setProp1(prop1);
    }
    if(path == "prop2") {
        Struct2 prop2 = value.get<Struct2>();
        m_SameStruct2Interface.setProp2(prop2);
    } 
}

void SameStruct2InterfaceServiceAdapter::olinkLinked(std::string name, ApiGear::ObjectLink::IRemoteNode *node) {
    std::clog << name << std::endl;
    m_node = node;
}

void SameStruct2InterfaceServiceAdapter::olinkUnlinked(std::string name)
{
    std::clog << name << std::endl;
    m_node = nullptr;
}

nlohmann::json SameStruct2InterfaceServiceAdapter::olinkCollectProperties()
{
    return nlohmann::json::object({
        { "prop1", m_SameStruct2Interface.getProp1() },
        { "prop2", m_SameStruct2Interface.getProp2() }
    });
}
void SameStruct2InterfaceServiceAdapter::onSig1(const Struct1& param1)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { param1 };
        m_node->notifySignal("tb.same2.SameStruct2Interface/sig1", args);
    }
}
void SameStruct2InterfaceServiceAdapter::onSig2(const Struct1& param1,const Struct2& param2)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { param1, param2 };
        m_node->notifySignal("tb.same2.SameStruct2Interface/sig2", args);
    }
}
void SameStruct2InterfaceServiceAdapter::onProp1Changed(const Struct2& prop1)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("tb.same2.SameStruct2Interface/prop1", prop1);
    }
}
void SameStruct2InterfaceServiceAdapter::onProp2Changed(const Struct2& prop2)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("tb.same2.SameStruct2Interface/prop2", prop2);
    }
}

