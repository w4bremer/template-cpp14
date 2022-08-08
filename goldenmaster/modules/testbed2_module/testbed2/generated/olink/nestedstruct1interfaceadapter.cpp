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
#include "testbed2/generated/olink/nestedstruct1interfaceadapter.h"

//#include "../api/agent.h"
#include "testbed2/generated/core/testbed2.json.adapter.h"

using namespace Test::Testbed2;

OLinkNestedStruct1InterfaceAdapter::OLinkNestedStruct1InterfaceAdapter(INestedStruct1Interface* impl, ApiGear::ObjectLink::RemoteRegistry& registry)
    : m_impl(impl)
    , m_node(nullptr)
    , m_registry(&registry)
{
    m_impl->_getPublisher()->subscribeToNestedStruct1InterfaceInterface(*this);
    m_registry->addObjectSource(this);
}

OLinkNestedStruct1InterfaceAdapter::~OLinkNestedStruct1InterfaceAdapter()
{
    m_registry->removeObjectSource(this);
    m_impl->_getPublisher()->unsubscribeFromNestedStruct1InterfaceInterface(*this);
}

nlohmann::json OLinkNestedStruct1InterfaceAdapter::captureState()
{
    return nlohmann::json::object({
        { "prop1", m_impl->prop1() }
    });
}

void OLinkNestedStruct1InterfaceAdapter::applyState(const nlohmann::json& state)
{
    if(state.contains("prop1")) {
        m_impl->setProp1(state["prop1"]);
    }
}


std::string OLinkNestedStruct1InterfaceAdapter::olinkObjectName() {
    return "testbed2.NestedStruct1Interface";
}

nlohmann::json OLinkNestedStruct1InterfaceAdapter::olinkInvoke(std::string fcnName, nlohmann::json fcnArgs) {
    std::clog << fcnName << std::endl;
    std::string path = ApiGear::ObjectLink::Name::pathFromName(fcnName);
    if(path == "func1") {
        const NestedStruct1& param1 = fcnArgs.at(0);
        NestedStruct1 result = m_impl->func1(param1);
        return result;
    }
    return nlohmann::json();
}

void OLinkNestedStruct1InterfaceAdapter::olinkSetProperty(std::string name, nlohmann::json value) {
    std::clog << name << std::endl;
    std::string path = ApiGear::ObjectLink::Name::pathFromName(name);
    if(path == "prop1") {
        NestedStruct1 prop1 = value.get<NestedStruct1>();
        m_impl->setProp1(prop1);
    } 
}

void OLinkNestedStruct1InterfaceAdapter::olinkLinked(std::string name, ApiGear::ObjectLink::IRemoteNode *node) {
    std::clog << name << std::endl;
    m_node = node;
}

void OLinkNestedStruct1InterfaceAdapter::olinkUnlinked(std::string name)
{
    std::clog << name << std::endl;
    m_node = nullptr;
}

nlohmann::json OLinkNestedStruct1InterfaceAdapter::olinkCollectProperties()
{
    return captureState();
}
void OLinkNestedStruct1InterfaceAdapter::OnSig1(const NestedStruct1& param1)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { param1 };
        m_node->notifySignal("testbed2.NestedStruct1Interface/sig1", args);
    }
}
void OLinkNestedStruct1InterfaceAdapter::OnProp1Changed(const NestedStruct1& prop1)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("testbed2.NestedStruct1Interface/prop1", prop1);
    }
}

