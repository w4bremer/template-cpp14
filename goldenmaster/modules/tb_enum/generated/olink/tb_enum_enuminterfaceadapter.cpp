/**
NO TITLE
Copyright (C) 2020 ApiGear UG

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/


#include <iostream>
#include "tb_enum_enuminterfaceadapter.h"

//#include "../api/agent.h"
#include "generated/core/tb_enum.json.adapter.h"

using namespace Test::TbEnum;

OLinkEnumInterfaceAdapter::OLinkEnumInterfaceAdapter(IEnumInterface* impl, ApiGear::ObjectLink::RemoteRegistry& registry)
    : m_impl(impl)
    , m_node(nullptr)
    , m_registry(&registry)
{
    m_impl->_getPublisher()->subscribeToEnumInterfaceInterface(*this);
    m_registry->addObjectSource(this);
}

OLinkEnumInterfaceAdapter::~OLinkEnumInterfaceAdapter()
{
    m_registry->removeObjectSource(this);
    m_impl->_getPublisher()->unsubscribeFromEnumInterfaceInterface(*this);
}

nlohmann::json OLinkEnumInterfaceAdapter::captureState()
{
    return nlohmann::json::object({
        { "prop0", m_impl->prop0() },
        { "prop1", m_impl->prop1() },
        { "prop2", m_impl->prop2() },
        { "prop3", m_impl->prop3() }
    });
}

void OLinkEnumInterfaceAdapter::applyState(const nlohmann::json& state)
{
    if(state.contains("prop0")) {
        m_impl->setProp0(state["prop0"]);
    }
    if(state.contains("prop1")) {
        m_impl->setProp1(state["prop1"]);
    }
    if(state.contains("prop2")) {
        m_impl->setProp2(state["prop2"]);
    }
    if(state.contains("prop3")) {
        m_impl->setProp3(state["prop3"]);
    }
}


std::string OLinkEnumInterfaceAdapter::olinkObjectName() {
    return "tb.enum.EnumInterface";
}

nlohmann::json OLinkEnumInterfaceAdapter::olinkInvoke(std::string fcnName, nlohmann::json fcnArgs) {
    std::clog << fcnName << std::endl;
    std::string path = ApiGear::ObjectLink::Name::pathFromName(fcnName);
    if(path == "func0") {
        const Enum0Enum& param0 = fcnArgs.at(0);
        Enum0Enum result = m_impl->func0(param0);
        return result;
    }
    if(path == "func1") {
        const Enum1Enum& param1 = fcnArgs.at(0);
        Enum1Enum result = m_impl->func1(param1);
        return result;
    }
    if(path == "func2") {
        const Enum2Enum& param2 = fcnArgs.at(0);
        Enum2Enum result = m_impl->func2(param2);
        return result;
    }
    if(path == "func3") {
        const Enum3Enum& param3 = fcnArgs.at(0);
        Enum3Enum result = m_impl->func3(param3);
        return result;
    }
    return nlohmann::json();
}

void OLinkEnumInterfaceAdapter::olinkSetProperty(std::string name, nlohmann::json value) {
    std::clog << name << std::endl;
    std::string path = ApiGear::ObjectLink::Name::pathFromName(name);
    if(path == "prop0") {
        Enum0Enum prop0 = value.get<Enum0Enum>();
        m_impl->setProp0(prop0);
    }
    if(path == "prop1") {
        Enum1Enum prop1 = value.get<Enum1Enum>();
        m_impl->setProp1(prop1);
    }
    if(path == "prop2") {
        Enum2Enum prop2 = value.get<Enum2Enum>();
        m_impl->setProp2(prop2);
    }
    if(path == "prop3") {
        Enum3Enum prop3 = value.get<Enum3Enum>();
        m_impl->setProp3(prop3);
    } 
}

void OLinkEnumInterfaceAdapter::olinkLinked(std::string name, ApiGear::ObjectLink::IRemoteNode *node) {
    std::clog << name << std::endl;
    m_node = node;
}

void OLinkEnumInterfaceAdapter::olinkUnlinked(std::string name)
{
    std::clog << name << std::endl;
    m_node = nullptr;
}

nlohmann::json OLinkEnumInterfaceAdapter::olinkCollectProperties()
{
    return captureState();
}
void OLinkEnumInterfaceAdapter::OnSig0(const Enum0Enum& param0)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { param0 };
        m_node->notifySignal("tb.enum.EnumInterface/sig0", args);
    }
}
void OLinkEnumInterfaceAdapter::OnSig1(const Enum1Enum& param1)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { param1 };
        m_node->notifySignal("tb.enum.EnumInterface/sig1", args);
    }
}
void OLinkEnumInterfaceAdapter::OnSig2(const Enum2Enum& param2)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { param2 };
        m_node->notifySignal("tb.enum.EnumInterface/sig2", args);
    }
}
void OLinkEnumInterfaceAdapter::OnSig3(const Enum3Enum& param3)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { param3 };
        m_node->notifySignal("tb.enum.EnumInterface/sig3", args);
    }
}
void OLinkEnumInterfaceAdapter::OnProp0Changed(const Enum0Enum& prop0)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("tb.enum.EnumInterface/prop0", prop0);
    }
}
void OLinkEnumInterfaceAdapter::OnProp1Changed(const Enum1Enum& prop1)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("tb.enum.EnumInterface/prop1", prop1);
    }
}
void OLinkEnumInterfaceAdapter::OnProp2Changed(const Enum2Enum& prop2)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("tb.enum.EnumInterface/prop2", prop2);
    }
}
void OLinkEnumInterfaceAdapter::OnProp3Changed(const Enum3Enum& prop3)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("tb.enum.EnumInterface/prop3", prop3);
    }
}

