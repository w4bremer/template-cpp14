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
#include "testbed1/generated/olink/structarrayinterfaceadapter.h"

//#include "../api/agent.h"
#include "testbed1/generated/core/testbed1.json.adapter.h"

using namespace Test::Testbed1;

OLinkStructArrayInterfaceAdapter::OLinkStructArrayInterfaceAdapter(IStructArrayInterface* impl, ApiGear::ObjectLink::RemoteRegistry& registry)
    : m_impl(impl)
    , m_node(nullptr)
    , m_registry(&registry)
{
    m_impl->_getPublisher()->subscribeToStructArrayInterfaceInterface(*this);
    m_registry->addObjectSource(this);
}

OLinkStructArrayInterfaceAdapter::~OLinkStructArrayInterfaceAdapter()
{
    m_registry->removeObjectSource(this);
    m_impl->_getPublisher()->unsubscribeFromStructArrayInterfaceInterface(*this);
}

nlohmann::json OLinkStructArrayInterfaceAdapter::captureState()
{
    return nlohmann::json::object({
        { "propBool", m_impl->propBool() },
        { "propInt", m_impl->propInt() },
        { "propFloat", m_impl->propFloat() },
        { "propString", m_impl->propString() }
    });
}

void OLinkStructArrayInterfaceAdapter::applyState(const nlohmann::json& state)
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


std::string OLinkStructArrayInterfaceAdapter::olinkObjectName() {
    return "testbed1.StructArrayInterface";
}

nlohmann::json OLinkStructArrayInterfaceAdapter::olinkInvoke(std::string fcnName, nlohmann::json fcnArgs) {
    std::clog << fcnName << std::endl;
    std::string path = ApiGear::ObjectLink::Name::pathFromName(fcnName);
    if(path == "funcBool") {
        const std::list<StructBool>& paramBool = fcnArgs.at(0);
        StructBool result = m_impl->funcBool(paramBool);
        return result;
    }
    if(path == "funcInt") {
        const std::list<StructInt>& paramInt = fcnArgs.at(0);
        StructBool result = m_impl->funcInt(paramInt);
        return result;
    }
    if(path == "funcFloat") {
        const std::list<StructFloat>& paramFloat = fcnArgs.at(0);
        StructBool result = m_impl->funcFloat(paramFloat);
        return result;
    }
    if(path == "funcString") {
        const std::list<StructString>& paramString = fcnArgs.at(0);
        StructBool result = m_impl->funcString(paramString);
        return result;
    }
    return nlohmann::json();
}

void OLinkStructArrayInterfaceAdapter::olinkSetProperty(std::string name, nlohmann::json value) {
    std::clog << name << std::endl;
    std::string path = ApiGear::ObjectLink::Name::pathFromName(name);
    if(path == "propBool") {
        std::list<StructBool> propBool = value.get<std::list<StructBool>>();
        m_impl->setPropbool(propBool);
    }
    if(path == "propInt") {
        std::list<StructInt> propInt = value.get<std::list<StructInt>>();
        m_impl->setPropint(propInt);
    }
    if(path == "propFloat") {
        std::list<StructFloat> propFloat = value.get<std::list<StructFloat>>();
        m_impl->setPropfloat(propFloat);
    }
    if(path == "propString") {
        std::list<StructString> propString = value.get<std::list<StructString>>();
        m_impl->setPropstring(propString);
    } 
}

void OLinkStructArrayInterfaceAdapter::olinkLinked(std::string name, ApiGear::ObjectLink::IRemoteNode *node) {
    std::clog << name << std::endl;
    m_node = node;
}

void OLinkStructArrayInterfaceAdapter::olinkUnlinked(std::string name)
{
    std::clog << name << std::endl;
    m_node = nullptr;
}

nlohmann::json OLinkStructArrayInterfaceAdapter::olinkCollectProperties()
{
    return captureState();
}
void OLinkStructArrayInterfaceAdapter::OnSigBool(const std::list<StructBool>& paramBool)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { paramBool };
        m_node->notifySignal("testbed1.StructArrayInterface/sigBool", args);
    }
}
void OLinkStructArrayInterfaceAdapter::OnSigInt(const std::list<StructInt>& paramInt)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { paramInt };
        m_node->notifySignal("testbed1.StructArrayInterface/sigInt", args);
    }
}
void OLinkStructArrayInterfaceAdapter::OnSigFloat(const std::list<StructFloat>& paramFloat)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { paramFloat };
        m_node->notifySignal("testbed1.StructArrayInterface/sigFloat", args);
    }
}
void OLinkStructArrayInterfaceAdapter::OnSigString(const std::list<StructString>& paramString)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { paramString };
        m_node->notifySignal("testbed1.StructArrayInterface/sigString", args);
    }
}
void OLinkStructArrayInterfaceAdapter::OnPropBoolChanged(const std::list<StructBool>& propBool)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("testbed1.StructArrayInterface/propBool", propBool);
    }
}
void OLinkStructArrayInterfaceAdapter::OnPropIntChanged(const std::list<StructInt>& propInt)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("testbed1.StructArrayInterface/propInt", propInt);
    }
}
void OLinkStructArrayInterfaceAdapter::OnPropFloatChanged(const std::list<StructFloat>& propFloat)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("testbed1.StructArrayInterface/propFloat", propFloat);
    }
}
void OLinkStructArrayInterfaceAdapter::OnPropStringChanged(const std::list<StructString>& propString)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("testbed1.StructArrayInterface/propString", propString);
    }
}

