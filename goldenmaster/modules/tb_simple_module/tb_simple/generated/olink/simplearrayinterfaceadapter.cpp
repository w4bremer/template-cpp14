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
#include "tb_simple/generated/olink/simplearrayinterfaceadapter.h"

//#include "../api/agent.h"
#include "tb_simple/generated/core/tb_simple.json.adapter.h"

using namespace Test::TbSimple;

OLinkSimpleArrayInterfaceAdapter::OLinkSimpleArrayInterfaceAdapter(ISimpleArrayInterface* impl, ApiGear::ObjectLink::RemoteRegistry& registry)
    : m_impl(impl)
    , m_node(nullptr)
    , m_registry(&registry)
{
    m_impl->_getPublisher()->subscribeToSimpleArrayInterfaceInterface(*this);
    m_registry->addObjectSource(this);
}

OLinkSimpleArrayInterfaceAdapter::~OLinkSimpleArrayInterfaceAdapter()
{
    m_registry->removeObjectSource(this);
    m_impl->_getPublisher()->unsubscribeFromSimpleArrayInterfaceInterface(*this);
}

nlohmann::json OLinkSimpleArrayInterfaceAdapter::captureState()
{
    return nlohmann::json::object({
        { "propBool", m_impl->propBool() },
        { "propInt", m_impl->propInt() },
        { "propFloat", m_impl->propFloat() },
        { "propString", m_impl->propString() }
    });
}

void OLinkSimpleArrayInterfaceAdapter::applyState(const nlohmann::json& state)
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


std::string OLinkSimpleArrayInterfaceAdapter::olinkObjectName() {
    return "tb.simple.SimpleArrayInterface";
}

nlohmann::json OLinkSimpleArrayInterfaceAdapter::olinkInvoke(std::string fcnName, nlohmann::json fcnArgs) {
    std::clog << fcnName << std::endl;
    std::string path = ApiGear::ObjectLink::Name::pathFromName(fcnName);
    if(path == "funcBool") {
        const std::list<bool>& paramBool = fcnArgs.at(0);
        std::list<bool> result = m_impl->funcBool(paramBool);
        return result;
    }
    if(path == "funcInt") {
        const std::list<int>& paramInt = fcnArgs.at(0);
        std::list<int> result = m_impl->funcInt(paramInt);
        return result;
    }
    if(path == "funcFloat") {
        const std::list<float>& paramFloat = fcnArgs.at(0);
        std::list<float> result = m_impl->funcFloat(paramFloat);
        return result;
    }
    if(path == "funcString") {
        const std::list<std::string>& paramString = fcnArgs.at(0);
        std::list<std::string> result = m_impl->funcString(paramString);
        return result;
    }
    return nlohmann::json();
}

void OLinkSimpleArrayInterfaceAdapter::olinkSetProperty(std::string name, nlohmann::json value) {
    std::clog << name << std::endl;
    std::string path = ApiGear::ObjectLink::Name::pathFromName(name);
    if(path == "propBool") {
        std::list<bool> propBool = value.get<std::list<bool>>();
        m_impl->setPropbool(propBool);
    }
    if(path == "propInt") {
        std::list<int> propInt = value.get<std::list<int>>();
        m_impl->setPropint(propInt);
    }
    if(path == "propFloat") {
        std::list<float> propFloat = value.get<std::list<float>>();
        m_impl->setPropfloat(propFloat);
    }
    if(path == "propString") {
        std::list<std::string> propString = value.get<std::list<std::string>>();
        m_impl->setPropstring(propString);
    } 
}

void OLinkSimpleArrayInterfaceAdapter::olinkLinked(std::string name, ApiGear::ObjectLink::IRemoteNode *node) {
    std::clog << name << std::endl;
    m_node = node;
}

void OLinkSimpleArrayInterfaceAdapter::olinkUnlinked(std::string name)
{
    std::clog << name << std::endl;
    m_node = nullptr;
}

nlohmann::json OLinkSimpleArrayInterfaceAdapter::olinkCollectProperties()
{
    return captureState();
}
void OLinkSimpleArrayInterfaceAdapter::OnSigBool(const std::list<bool>& paramBool)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { paramBool };
        m_node->notifySignal("tb.simple.SimpleArrayInterface/sigBool", args);
    }
}
void OLinkSimpleArrayInterfaceAdapter::OnSigInt(const std::list<int>& paramInt)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { paramInt };
        m_node->notifySignal("tb.simple.SimpleArrayInterface/sigInt", args);
    }
}
void OLinkSimpleArrayInterfaceAdapter::OnSigFloat(const std::list<float>& paramFloat)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { paramFloat };
        m_node->notifySignal("tb.simple.SimpleArrayInterface/sigFloat", args);
    }
}
void OLinkSimpleArrayInterfaceAdapter::OnSigString(const std::list<std::string>& paramString)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { paramString };
        m_node->notifySignal("tb.simple.SimpleArrayInterface/sigString", args);
    }
}
void OLinkSimpleArrayInterfaceAdapter::OnPropBoolChanged(const std::list<bool>& propBool)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("tb.simple.SimpleArrayInterface/propBool", propBool);
    }
}
void OLinkSimpleArrayInterfaceAdapter::OnPropIntChanged(const std::list<int>& propInt)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("tb.simple.SimpleArrayInterface/propInt", propInt);
    }
}
void OLinkSimpleArrayInterfaceAdapter::OnPropFloatChanged(const std::list<float>& propFloat)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("tb.simple.SimpleArrayInterface/propFloat", propFloat);
    }
}
void OLinkSimpleArrayInterfaceAdapter::OnPropStringChanged(const std::list<std::string>& propString)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("tb.simple.SimpleArrayInterface/propString", propString);
    }
}

