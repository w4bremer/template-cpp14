

#include "tb_enum/generated/olink/enuminterfaceservice.adapter.h"
#include "tb_enum/generated/core/tb_enum.json.adapter.h"
#include <iostream>

using namespace Test::TbEnum;
using namespace Test::TbEnum::olink;

EnumInterfaceServiceAdapter::EnumInterfaceServiceAdapter(IEnumInterface& EnumInterface, ApiGear::ObjectLink::RemoteRegistry& registry)
    : m_EnumInterface(EnumInterface)
    , m_node(nullptr)
    , m_registry(registry)
{
    m_EnumInterface._getPublisher().subscribeToAllChanges(*this);
    m_registry.addObjectSource(this);
}

EnumInterfaceServiceAdapter::~EnumInterfaceServiceAdapter()
{
    m_registry.removeObjectSource(this);
    m_EnumInterface._getPublisher().unsubscribeFromAllChanges(*this);
}

std::string EnumInterfaceServiceAdapter::olinkObjectName() {
    return "tb.enum.EnumInterface";
}

nlohmann::json EnumInterfaceServiceAdapter::olinkInvoke(std::string fcnName, nlohmann::json fcnArgs) {
    std::clog << fcnName << std::endl;
    std::string path = ApiGear::ObjectLink::Name::pathFromName(fcnName);
    if(path == "func0") {
        const Enum0Enum& param0 = fcnArgs.at(0);
        Enum0Enum result = m_EnumInterface.func0(param0);
        return result;
    }
    if(path == "func1") {
        const Enum1Enum& param1 = fcnArgs.at(0);
        Enum1Enum result = m_EnumInterface.func1(param1);
        return result;
    }
    if(path == "func2") {
        const Enum2Enum& param2 = fcnArgs.at(0);
        Enum2Enum result = m_EnumInterface.func2(param2);
        return result;
    }
    if(path == "func3") {
        const Enum3Enum& param3 = fcnArgs.at(0);
        Enum3Enum result = m_EnumInterface.func3(param3);
        return result;
    }
    return nlohmann::json();
}

void EnumInterfaceServiceAdapter::olinkSetProperty(std::string name, nlohmann::json value) {
    std::clog << name << std::endl;
    std::string path = ApiGear::ObjectLink::Name::pathFromName(name);
    if(path == "prop0") {
        Enum0Enum prop0 = value.get<Enum0Enum>();
        m_EnumInterface.setProp0(prop0);
    }
    if(path == "prop1") {
        Enum1Enum prop1 = value.get<Enum1Enum>();
        m_EnumInterface.setProp1(prop1);
    }
    if(path == "prop2") {
        Enum2Enum prop2 = value.get<Enum2Enum>();
        m_EnumInterface.setProp2(prop2);
    }
    if(path == "prop3") {
        Enum3Enum prop3 = value.get<Enum3Enum>();
        m_EnumInterface.setProp3(prop3);
    } 
}

void EnumInterfaceServiceAdapter::olinkLinked(std::string name, ApiGear::ObjectLink::IRemoteNode *node) {
    std::clog << name << std::endl;
    m_node = node;
}

void EnumInterfaceServiceAdapter::olinkUnlinked(std::string name)
{
    std::clog << name << std::endl;
    m_node = nullptr;
}

nlohmann::json EnumInterfaceServiceAdapter::olinkCollectProperties()
{
    return nlohmann::json::object({
        { "prop0", m_EnumInterface.prop0() },
        { "prop1", m_EnumInterface.prop1() },
        { "prop2", m_EnumInterface.prop2() },
        { "prop3", m_EnumInterface.prop3() }
    });
}
void EnumInterfaceServiceAdapter::onSig0(const Enum0Enum& param0)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { param0 };
        m_node->notifySignal("tb.enum.EnumInterface/sig0", args);
    }
}
void EnumInterfaceServiceAdapter::onSig1(const Enum1Enum& param1)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { param1 };
        m_node->notifySignal("tb.enum.EnumInterface/sig1", args);
    }
}
void EnumInterfaceServiceAdapter::onSig2(const Enum2Enum& param2)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { param2 };
        m_node->notifySignal("tb.enum.EnumInterface/sig2", args);
    }
}
void EnumInterfaceServiceAdapter::onSig3(const Enum3Enum& param3)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { param3 };
        m_node->notifySignal("tb.enum.EnumInterface/sig3", args);
    }
}
void EnumInterfaceServiceAdapter::onProp0Changed(const Enum0Enum& prop0)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("tb.enum.EnumInterface/prop0", prop0);
    }
}
void EnumInterfaceServiceAdapter::onProp1Changed(const Enum1Enum& prop1)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("tb.enum.EnumInterface/prop1", prop1);
    }
}
void EnumInterfaceServiceAdapter::onProp2Changed(const Enum2Enum& prop2)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("tb.enum.EnumInterface/prop2", prop2);
    }
}
void EnumInterfaceServiceAdapter::onProp3Changed(const Enum3Enum& prop3)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("tb.enum.EnumInterface/prop3", prop3);
    }
}

