

#include "tb_same1/generated/olink/samestruct1interfaceservice.adapter.h"
#include "tb_same1/generated/core/tb_same1.json.adapter.h"
#include <iostream>

using namespace Test::TbSame1;
using namespace Test::TbSame1::olink;

SameStruct1InterfaceServiceAdapter::SameStruct1InterfaceServiceAdapter(ISameStruct1Interface& SameStruct1Interface, ApiGear::ObjectLink::RemoteRegistry& registry)
    : m_SameStruct1Interface(SameStruct1Interface)
    , m_node(nullptr)
    , m_registry(registry)
{
    m_SameStruct1Interface._getPublisher().subscribeToAllChanges(*this);
    m_registry.addObjectSource(this);
}

SameStruct1InterfaceServiceAdapter::~SameStruct1InterfaceServiceAdapter()
{
    m_registry.removeObjectSource(this);
    m_SameStruct1Interface._getPublisher().unsubscribeFromAllChanges(*this);
}

std::string SameStruct1InterfaceServiceAdapter::olinkObjectName() {
    return "tb.same1.SameStruct1Interface";
}

nlohmann::json SameStruct1InterfaceServiceAdapter::olinkInvoke(std::string fcnName, nlohmann::json fcnArgs) {
    std::clog << fcnName << std::endl;
    std::string path = ApiGear::ObjectLink::Name::pathFromName(fcnName);
    if(path == "func1") {
        const Struct1& param1 = fcnArgs.at(0);
        Struct1 result = m_SameStruct1Interface.func1(param1);
        return result;
    }
    return nlohmann::json();
}

void SameStruct1InterfaceServiceAdapter::olinkSetProperty(std::string name, nlohmann::json value) {
    std::clog << name << std::endl;
    std::string path = ApiGear::ObjectLink::Name::pathFromName(name);
    if(path == "prop1") {
        Struct1 prop1 = value.get<Struct1>();
        m_SameStruct1Interface.setProp1(prop1);
    } 
}

void SameStruct1InterfaceServiceAdapter::olinkLinked(std::string name, ApiGear::ObjectLink::IRemoteNode *node) {
    std::clog << name << std::endl;
    m_node = node;
}

void SameStruct1InterfaceServiceAdapter::olinkUnlinked(std::string name)
{
    std::clog << name << std::endl;
    m_node = nullptr;
}

nlohmann::json SameStruct1InterfaceServiceAdapter::olinkCollectProperties()
{
    return nlohmann::json::object({
        { "prop1", m_SameStruct1Interface.getProp1() }
    });
}
void SameStruct1InterfaceServiceAdapter::onSig1(const Struct1& param1)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { param1 };
        m_node->notifySignal("tb.same1.SameStruct1Interface/sig1", args);
    }
}
void SameStruct1InterfaceServiceAdapter::onProp1Changed(const Struct1& prop1)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("tb.same1.SameStruct1Interface/prop1", prop1);
    }
}

