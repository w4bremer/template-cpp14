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
#include "tb_same2_sameenum2interfaceadapter.h"

//#include "../api/agent.h"
#include "generated/core/tb_same2.json.adapter.h"

using namespace Test::TbSame2;

OLinkSameEnum2InterfaceAdapter::OLinkSameEnum2InterfaceAdapter(ISameEnum2Interface* impl, ApiGear::ObjectLink::RemoteRegistry& registry)
    : m_impl(impl)
    , m_node(nullptr)
    , m_registry(&registry)
{
    m_impl->_getPublisher()->subscribeToSameEnum2InterfaceInterface(*this);
    m_registry->addObjectSource(this);
}

OLinkSameEnum2InterfaceAdapter::~OLinkSameEnum2InterfaceAdapter()
{
    m_registry->removeObjectSource(this);
    m_impl->_getPublisher()->unsubscribeFromSameEnum2InterfaceInterface(*this);
}

nlohmann::json OLinkSameEnum2InterfaceAdapter::captureState()
{
    return nlohmann::json::object({
        { "prop1", m_impl->prop1() },
        { "prop2", m_impl->prop2() }
    });
}

void OLinkSameEnum2InterfaceAdapter::applyState(const nlohmann::json& state)
{
    if(state.contains("prop1")) {
        m_impl->setProp1(state["prop1"]);
    }
    if(state.contains("prop2")) {
        m_impl->setProp2(state["prop2"]);
    }
}


std::string OLinkSameEnum2InterfaceAdapter::olinkObjectName() {
    return "tb.same2.SameEnum2Interface";
}

nlohmann::json OLinkSameEnum2InterfaceAdapter::olinkInvoke(std::string fcnName, nlohmann::json fcnArgs) {
    std::clog << fcnName << std::endl;
    std::string path = ApiGear::ObjectLink::Name::pathFromName(fcnName);
    if(path == "func1") {
        const Enum1Enum& param1 = fcnArgs.at(0);
        Enum1Enum result = m_impl->func1(param1);
        return result;
    }
    if(path == "func2") {
        const Enum1Enum& param1 = fcnArgs.at(0);
        const Enum2Enum& param2 = fcnArgs.at(1);
        Enum1Enum result = m_impl->func2(param1, param2);
        return result;
    }
    return nlohmann::json();
}

void OLinkSameEnum2InterfaceAdapter::olinkSetProperty(std::string name, nlohmann::json value) {
    std::clog << name << std::endl;
    std::string path = ApiGear::ObjectLink::Name::pathFromName(name);
    if(path == "prop1") {
        Enum1Enum prop1 = value.get<Enum1Enum>();
        m_impl->setProp1(prop1);
    }
    if(path == "prop2") {
        Enum2Enum prop2 = value.get<Enum2Enum>();
        m_impl->setProp2(prop2);
    } 
}

void OLinkSameEnum2InterfaceAdapter::olinkLinked(std::string name, ApiGear::ObjectLink::IRemoteNode *node) {
    std::clog << name << std::endl;
    m_node = node;
}

void OLinkSameEnum2InterfaceAdapter::olinkUnlinked(std::string name)
{
    std::clog << name << std::endl;
    m_node = nullptr;
}

nlohmann::json OLinkSameEnum2InterfaceAdapter::olinkCollectProperties()
{
    return captureState();
}
void OLinkSameEnum2InterfaceAdapter::OnSig1(const Enum1Enum& param1)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { param1 };
        m_node->notifySignal("tb.same2.SameEnum2Interface/sig1", args);
    }
}
void OLinkSameEnum2InterfaceAdapter::OnSig2(const Enum1Enum& param1,const Enum2Enum& param2)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { param1, param2 };
        m_node->notifySignal("tb.same2.SameEnum2Interface/sig2", args);
    }
}
void OLinkSameEnum2InterfaceAdapter::OnProp1Changed(const Enum1Enum& prop1)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("tb.same2.SameEnum2Interface/prop1", prop1);
    }
}
void OLinkSameEnum2InterfaceAdapter::OnProp2Changed(const Enum2Enum& prop2)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("tb.same2.SameEnum2Interface/prop2", prop2);
    }
}

