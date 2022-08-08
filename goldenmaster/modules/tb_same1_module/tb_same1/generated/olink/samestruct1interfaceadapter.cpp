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
#include "tb_same1/generated/olink/samestruct1interfaceadapter.h"

//#include "../api/agent.h"
#include "tb_same1/generated/core/tb_same1.json.adapter.h"

using namespace Test::TbSame1;

OLinkSameStruct1InterfaceAdapter::OLinkSameStruct1InterfaceAdapter(ISameStruct1Interface* impl, ApiGear::ObjectLink::RemoteRegistry& registry)
    : m_impl(impl)
    , m_node(nullptr)
    , m_registry(&registry)
{
    m_impl->_getPublisher()->subscribeToSameStruct1InterfaceInterface(*this);
    m_registry->addObjectSource(this);
}

OLinkSameStruct1InterfaceAdapter::~OLinkSameStruct1InterfaceAdapter()
{
    m_registry->removeObjectSource(this);
    m_impl->_getPublisher()->unsubscribeFromSameStruct1InterfaceInterface(*this);
}

nlohmann::json OLinkSameStruct1InterfaceAdapter::captureState()
{
    return nlohmann::json::object({
        { "prop1", m_impl->prop1() }
    });
}

void OLinkSameStruct1InterfaceAdapter::applyState(const nlohmann::json& state)
{
    if(state.contains("prop1")) {
        m_impl->setProp1(state["prop1"]);
    }
}


std::string OLinkSameStruct1InterfaceAdapter::olinkObjectName() {
    return "tb.same1.SameStruct1Interface";
}

nlohmann::json OLinkSameStruct1InterfaceAdapter::olinkInvoke(std::string fcnName, nlohmann::json fcnArgs) {
    std::clog << fcnName << std::endl;
    std::string path = ApiGear::ObjectLink::Name::pathFromName(fcnName);
    if(path == "func1") {
        const Struct1& param1 = fcnArgs.at(0);
        Struct1 result = m_impl->func1(param1);
        return result;
    }
    return nlohmann::json();
}

void OLinkSameStruct1InterfaceAdapter::olinkSetProperty(std::string name, nlohmann::json value) {
    std::clog << name << std::endl;
    std::string path = ApiGear::ObjectLink::Name::pathFromName(name);
    if(path == "prop1") {
        Struct1 prop1 = value.get<Struct1>();
        m_impl->setProp1(prop1);
    } 
}

void OLinkSameStruct1InterfaceAdapter::olinkLinked(std::string name, ApiGear::ObjectLink::IRemoteNode *node) {
    std::clog << name << std::endl;
    m_node = node;
}

void OLinkSameStruct1InterfaceAdapter::olinkUnlinked(std::string name)
{
    std::clog << name << std::endl;
    m_node = nullptr;
}

nlohmann::json OLinkSameStruct1InterfaceAdapter::olinkCollectProperties()
{
    return captureState();
}
void OLinkSameStruct1InterfaceAdapter::OnSig1(const Struct1& param1)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { param1 };
        m_node->notifySignal("tb.same1.SameStruct1Interface/sig1", args);
    }
}
void OLinkSameStruct1InterfaceAdapter::OnProp1Changed(const Struct1& prop1)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("tb.same1.SameStruct1Interface/prop1", prop1);
    }
}

