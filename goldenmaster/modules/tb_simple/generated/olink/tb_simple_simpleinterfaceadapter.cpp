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
#include "tb_simple_simpleinterfaceadapter.h"

//#include "../api/agent.h"
#include "generated/core/tb_simple.json.adapter.h"

using namespace Test::TbSimple;

OLinkSimpleInterfaceAdapter::OLinkSimpleInterfaceAdapter(ISimpleInterface* impl, ApiGear::ObjectLink::RemoteRegistry& registry)
    : m_impl(impl)
    , m_node(nullptr)
    , m_registry(&registry)
{
    m_impl->_getPublisher()->subscribeToSimpleInterfaceInterface(*this);
    m_registry->addObjectSource(this);
}

OLinkSimpleInterfaceAdapter::~OLinkSimpleInterfaceAdapter()
{
    m_registry->removeObjectSource(this);
    m_impl->_getPublisher()->unsubscribeFromSimpleInterfaceInterface(*this);
}

nlohmann::json OLinkSimpleInterfaceAdapter::captureState()
{
    return nlohmann::json::object({
        { "propBool", m_impl->propBool() },
        { "propInt", m_impl->propInt() },
        { "propFloat", m_impl->propFloat() },
        { "propString", m_impl->propString() }
    });
}

void OLinkSimpleInterfaceAdapter::applyState(const nlohmann::json& state)
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


std::string OLinkSimpleInterfaceAdapter::olinkObjectName() {
    return "tb.simple.SimpleInterface";
}

nlohmann::json OLinkSimpleInterfaceAdapter::olinkInvoke(std::string fcnName, nlohmann::json fcnArgs) {
    std::clog << fcnName << std::endl;
    std::string path = ApiGear::ObjectLink::Name::pathFromName(fcnName);
    if(path == "funcBool") {
        const bool& paramBool = fcnArgs.at(0);
        bool result = m_impl->funcBool(paramBool);
        return result;
    }
    if(path == "funcInt") {
        const int& paramInt = fcnArgs.at(0);
        int result = m_impl->funcInt(paramInt);
        return result;
    }
    if(path == "funcFloat") {
        const float& paramFloat = fcnArgs.at(0);
        float result = m_impl->funcFloat(paramFloat);
        return result;
    }
    if(path == "funcString") {
        const std::string& paramString = fcnArgs.at(0);
        std::string result = m_impl->funcString(paramString);
        return result;
    }
    return nlohmann::json();
}

void OLinkSimpleInterfaceAdapter::olinkSetProperty(std::string name, nlohmann::json value) {
    std::clog << name << std::endl;
    std::string path = ApiGear::ObjectLink::Name::pathFromName(name);
    if(path == "propBool") {
        bool propBool = value.get<bool>();
        m_impl->setPropbool(propBool);
    }
    if(path == "propInt") {
        int propInt = value.get<int>();
        m_impl->setPropint(propInt);
    }
    if(path == "propFloat") {
        float propFloat = value.get<float>();
        m_impl->setPropfloat(propFloat);
    }
    if(path == "propString") {
        std::string propString = value.get<std::string>();
        m_impl->setPropstring(propString);
    } 
}

void OLinkSimpleInterfaceAdapter::olinkLinked(std::string name, ApiGear::ObjectLink::IRemoteNode *node) {
    std::clog << name << std::endl;
    m_node = node;
}

void OLinkSimpleInterfaceAdapter::olinkUnlinked(std::string name)
{
    std::clog << name << std::endl;
    m_node = nullptr;
}

nlohmann::json OLinkSimpleInterfaceAdapter::olinkCollectProperties()
{
    return captureState();
}
void OLinkSimpleInterfaceAdapter::OnSigBool(bool paramBool)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { paramBool };
        m_node->notifySignal("tb.simple.SimpleInterface/sigBool", args);
    }
}
void OLinkSimpleInterfaceAdapter::OnSigInt(int paramInt)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { paramInt };
        m_node->notifySignal("tb.simple.SimpleInterface/sigInt", args);
    }
}
void OLinkSimpleInterfaceAdapter::OnSigFloat(float paramFloat)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { paramFloat };
        m_node->notifySignal("tb.simple.SimpleInterface/sigFloat", args);
    }
}
void OLinkSimpleInterfaceAdapter::OnSigString(const std::string& paramString)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { paramString };
        m_node->notifySignal("tb.simple.SimpleInterface/sigString", args);
    }
}
void OLinkSimpleInterfaceAdapter::OnPropBoolChanged(bool propBool)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("tb.simple.SimpleInterface/propBool", propBool);
    }
}
void OLinkSimpleInterfaceAdapter::OnPropIntChanged(int propInt)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("tb.simple.SimpleInterface/propInt", propInt);
    }
}
void OLinkSimpleInterfaceAdapter::OnPropFloatChanged(float propFloat)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("tb.simple.SimpleInterface/propFloat", propFloat);
    }
}
void OLinkSimpleInterfaceAdapter::OnPropStringChanged(std::string propString)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("tb.simple.SimpleInterface/propString", propString);
    }
}

