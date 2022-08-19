

#include "testbed2/generated/olink/nestedstruct1interfaceservice.adapter.h"
#include "testbed2/generated/core/testbed2.json.adapter.h"
#include <iostream>

using namespace Test::Testbed2;
using namespace Test::Testbed2::olink;

NestedStruct1InterfaceServiceAdapter::NestedStruct1InterfaceServiceAdapter(INestedStruct1Interface& NestedStruct1Interface, ApiGear::ObjectLink::RemoteRegistry& registry)
    : m_NestedStruct1Interface(NestedStruct1Interface)
    , m_node(nullptr)
    , m_registry(registry)
{
    m_NestedStruct1Interface._getPublisher().subscribeToAllChanges(*this);
    m_registry.addObjectSource(this);
}

NestedStruct1InterfaceServiceAdapter::~NestedStruct1InterfaceServiceAdapter()
{
    m_registry.removeObjectSource(this);
    m_NestedStruct1Interface._getPublisher().unsubscribeFromAllChanges(*this);
}

std::string NestedStruct1InterfaceServiceAdapter::olinkObjectName() {
    return "testbed2.NestedStruct1Interface";
}

nlohmann::json NestedStruct1InterfaceServiceAdapter::olinkInvoke(std::string fcnName, nlohmann::json fcnArgs) {
    std::clog << fcnName << std::endl;
    std::string path = ApiGear::ObjectLink::Name::pathFromName(fcnName);
    if(path == "func1") {
        const NestedStruct1& param1 = fcnArgs.at(0);
        NestedStruct1 result = m_NestedStruct1Interface.func1(param1);
        return result;
    }
    return nlohmann::json();
}

void NestedStruct1InterfaceServiceAdapter::olinkSetProperty(std::string name, nlohmann::json value) {
    std::clog << name << std::endl;
    std::string path = ApiGear::ObjectLink::Name::pathFromName(name);
    if(path == "prop1") {
        NestedStruct1 prop1 = value.get<NestedStruct1>();
        m_NestedStruct1Interface.setProp1(prop1);
    } 
}

void NestedStruct1InterfaceServiceAdapter::olinkLinked(std::string name, ApiGear::ObjectLink::IRemoteNode *node) {
    std::clog << name << std::endl;
    m_node = node;
}

void NestedStruct1InterfaceServiceAdapter::olinkUnlinked(std::string name)
{
    std::clog << name << std::endl;
    m_node = nullptr;
}

nlohmann::json NestedStruct1InterfaceServiceAdapter::olinkCollectProperties()
{
    return nlohmann::json::object({
        { "prop1", m_NestedStruct1Interface.getProp1() }
    });
}
void NestedStruct1InterfaceServiceAdapter::onSig1(const NestedStruct1& param1)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { param1 };
        m_node->notifySignal("testbed2.NestedStruct1Interface/sig1", args);
    }
}
void NestedStruct1InterfaceServiceAdapter::onProp1Changed(const NestedStruct1& prop1)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("testbed2.NestedStruct1Interface/prop1", prop1);
    }
}

