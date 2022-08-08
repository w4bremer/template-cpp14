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
#include "testbed1/generated/olink/structinterfaceadapter.h"

//#include "../api/agent.h"
#include "testbed1/generated/core/testbed1.json.adapter.h"

using namespace Test::Testbed1;

OLinkStructInterfaceAdapter::OLinkStructInterfaceAdapter(IStructInterface* impl, ApiGear::ObjectLink::RemoteRegistry& registry)
    : m_impl(impl)
    , m_node(nullptr)
    , m_registry(&registry)
{
    m_impl->_getPublisher()->subscribeToStructInterfaceInterface(*this);
    m_registry->addObjectSource(this);
}

OLinkStructInterfaceAdapter::~OLinkStructInterfaceAdapter()
{
    m_registry->removeObjectSource(this);
    m_impl->_getPublisher()->unsubscribeFromStructInterfaceInterface(*this);
}

nlohmann::json OLinkStructInterfaceAdapter::captureState()
{
    return nlohmann::json::object({
        { "propBool", m_impl->propBool() },
        { "propInt", m_impl->propInt() },
        { "propFloat", m_impl->propFloat() },
        { "propString", m_impl->propString() }
    });
}

void OLinkStructInterfaceAdapter::applyState(const nlohmann::json& state)
{
    if(state.contains("propBool")) {
        m_impl->setPropbool(state["propBool"]);
    }
    if(state.contains("propInt")) {
        m_impl->setPropint(state["propInt"]);
    }
    if(state.contains("propFloat")) {
        m_impl->setPropfloat(state["propFloat"]);
    }
    if(state.contains("propString")) {
        m_impl->setPropstring(state["propString"]);
    }
}


std::string OLinkStructInterfaceAdapter::olinkObjectName() {
    return "testbed1.StructInterface";
}

nlohmann::json OLinkStructInterfaceAdapter::olinkInvoke(std::string fcnName, nlohmann::json fcnArgs) {
    std::clog << fcnName << std::endl;
    std::string path = ApiGear::ObjectLink::Name::pathFromName(fcnName);
    if(path == "funcBool") {
        const StructBool& paramBool = fcnArgs.at(0);
        StructBool result = m_impl->funcBool(paramBool);
        return result;
    }
    if(path == "funcInt") {
        const StructInt& paramInt = fcnArgs.at(0);
        StructBool result = m_impl->funcInt(paramInt);
        return result;
    }
    if(path == "funcFloat") {
        const StructFloat& paramFloat = fcnArgs.at(0);
        StructFloat result = m_impl->funcFloat(paramFloat);
        return result;
    }
    if(path == "funcString") {
        const StructString& paramString = fcnArgs.at(0);
        StructString result = m_impl->funcString(paramString);
        return result;
    }
    return nlohmann::json();
}

void OLinkStructInterfaceAdapter::olinkSetProperty(std::string name, nlohmann::json value) {
    std::clog << name << std::endl;
    std::string path = ApiGear::ObjectLink::Name::pathFromName(name);
    if(path == "propBool") {
        StructBool propBool = value.get<StructBool>();
        m_impl->setPropbool(propBool);
    }
    if(path == "propInt") {
        StructInt propInt = value.get<StructInt>();
        m_impl->setPropint(propInt);
    }
    if(path == "propFloat") {
        StructFloat propFloat = value.get<StructFloat>();
        m_impl->setPropfloat(propFloat);
    }
    if(path == "propString") {
        StructString propString = value.get<StructString>();
        m_impl->setPropstring(propString);
    } 
}

void OLinkStructInterfaceAdapter::olinkLinked(std::string name, ApiGear::ObjectLink::IRemoteNode *node) {
    std::clog << name << std::endl;
    m_node = node;
}

void OLinkStructInterfaceAdapter::olinkUnlinked(std::string name)
{
    std::clog << name << std::endl;
    m_node = nullptr;
}

nlohmann::json OLinkStructInterfaceAdapter::olinkCollectProperties()
{
    return captureState();
}
void OLinkStructInterfaceAdapter::OnSigBool(const StructBool& paramBool)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { paramBool };
        m_node->notifySignal("testbed1.StructInterface/sigBool", args);
    }
}
void OLinkStructInterfaceAdapter::OnSigInt(const StructInt& paramInt)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { paramInt };
        m_node->notifySignal("testbed1.StructInterface/sigInt", args);
    }
}
void OLinkStructInterfaceAdapter::OnSigFloat(const StructFloat& paramFloat)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { paramFloat };
        m_node->notifySignal("testbed1.StructInterface/sigFloat", args);
    }
}
void OLinkStructInterfaceAdapter::OnSigString(const StructString& paramString)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { paramString };
        m_node->notifySignal("testbed1.StructInterface/sigString", args);
    }
}
void OLinkStructInterfaceAdapter::OnPropBoolChanged(const StructBool& propBool)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("testbed1.StructInterface/propBool", propBool);
    }
}
void OLinkStructInterfaceAdapter::OnPropIntChanged(const StructInt& propInt)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("testbed1.StructInterface/propInt", propInt);
    }
}
void OLinkStructInterfaceAdapter::OnPropFloatChanged(const StructFloat& propFloat)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("testbed1.StructInterface/propFloat", propFloat);
    }
}
void OLinkStructInterfaceAdapter::OnPropStringChanged(const StructString& propString)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("testbed1.StructInterface/propString", propString);
    }
}

