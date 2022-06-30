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
#include "testbed2_manyparaminterfaceadapter.h"

//#include "../api/agent.h"
#include "generated/core/testbed2.json.adapter.h"

using namespace Test::Testbed2;

OLinkManyParamInterfaceAdapter::OLinkManyParamInterfaceAdapter(IManyParamInterface* impl, ApiGear::ObjectLink::RemoteRegistry& registry)
    : m_impl(impl)
    , m_node(nullptr)
    , m_registry(&registry)
{
    m_impl->_getPublisher()->subscribeToManyParamInterfaceInterface(*this);
    m_registry->addObjectSource(this);
}

OLinkManyParamInterfaceAdapter::~OLinkManyParamInterfaceAdapter()
{
    m_registry->removeObjectSource(this);
    m_impl->_getPublisher()->unsubscribeFromManyParamInterfaceInterface(*this);
}

nlohmann::json OLinkManyParamInterfaceAdapter::captureState()
{
    return nlohmann::json::object({
        { "prop1", m_impl->prop1() },
        { "prop2", m_impl->prop2() },
        { "prop3", m_impl->prop3() },
        { "prop4", m_impl->prop4() }
    });
}

void OLinkManyParamInterfaceAdapter::applyState(const nlohmann::json& state)
{
    if(state.contains("prop1")) {
        m_impl->setProp1(state["prop1"]);
    }
    if(state.contains("prop2")) {
        m_impl->setProp2(state["prop2"]);
    }
    if(state.contains("prop3")) {
        m_impl->setProp3(state["prop3"]);
    }
    if(state.contains("prop4")) {
        m_impl->setProp4(state["prop4"]);
    }
}


std::string OLinkManyParamInterfaceAdapter::olinkObjectName() {
    return "testbed2.ManyParamInterface";
}

nlohmann::json OLinkManyParamInterfaceAdapter::olinkInvoke(std::string fcnName, nlohmann::json fcnArgs) {
    std::clog << fcnName << std::endl;
    std::string path = ApiGear::ObjectLink::Name::pathFromName(fcnName);
    if(path == "func1") {
        const int& param1 = fcnArgs.at(0);
        int result = m_impl->func1(param1);
        return result;
    }
    if(path == "func2") {
        const int& param1 = fcnArgs.at(0);
        const int& param2 = fcnArgs.at(1);
        int result = m_impl->func2(param1, param2);
        return result;
    }
    if(path == "func3") {
        const int& param1 = fcnArgs.at(0);
        const int& param2 = fcnArgs.at(1);
        const int& param3 = fcnArgs.at(2);
        int result = m_impl->func3(param1, param2, param3);
        return result;
    }
    if(path == "func4") {
        const int& param1 = fcnArgs.at(0);
        const int& param2 = fcnArgs.at(1);
        const int& param3 = fcnArgs.at(2);
        const int& param4 = fcnArgs.at(3);
        int result = m_impl->func4(param1, param2, param3, param4);
        return result;
    }
    return nlohmann::json();
}

void OLinkManyParamInterfaceAdapter::olinkSetProperty(std::string name, nlohmann::json value) {
    std::clog << name << std::endl;
    std::string path = ApiGear::ObjectLink::Name::pathFromName(name);
    if(path == "prop1") {
        int prop1 = value.get<int>();
        m_impl->setProp1(prop1);
    }
    if(path == "prop2") {
        int prop2 = value.get<int>();
        m_impl->setProp2(prop2);
    }
    if(path == "prop3") {
        int prop3 = value.get<int>();
        m_impl->setProp3(prop3);
    }
    if(path == "prop4") {
        int prop4 = value.get<int>();
        m_impl->setProp4(prop4);
    } 
}

void OLinkManyParamInterfaceAdapter::olinkLinked(std::string name, ApiGear::ObjectLink::IRemoteNode *node) {
    std::clog << name << std::endl;
    m_node = node;
}

void OLinkManyParamInterfaceAdapter::olinkUnlinked(std::string name)
{
    std::clog << name << std::endl;
    m_node = nullptr;
}

nlohmann::json OLinkManyParamInterfaceAdapter::olinkCollectProperties()
{
    return captureState();
}
void OLinkManyParamInterfaceAdapter::OnSig1(int param1)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { param1 };
        m_node->notifySignal("testbed2.ManyParamInterface/sig1", args);
    }
}
void OLinkManyParamInterfaceAdapter::OnSig2(int param1,int param2)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { param1, param2 };
        m_node->notifySignal("testbed2.ManyParamInterface/sig2", args);
    }
}
void OLinkManyParamInterfaceAdapter::OnSig3(int param1,int param2,int param3)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { param1, param2, param3 };
        m_node->notifySignal("testbed2.ManyParamInterface/sig3", args);
    }
}
void OLinkManyParamInterfaceAdapter::OnSig4(int param1,int param2,int param3,int param4)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { param1, param2, param3, param4 };
        m_node->notifySignal("testbed2.ManyParamInterface/sig4", args);
    }
}
void OLinkManyParamInterfaceAdapter::OnProp1Changed(int prop1)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("testbed2.ManyParamInterface/prop1", prop1);
    }
}
void OLinkManyParamInterfaceAdapter::OnProp2Changed(int prop2)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("testbed2.ManyParamInterface/prop2", prop2);
    }
}
void OLinkManyParamInterfaceAdapter::OnProp3Changed(int prop3)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("testbed2.ManyParamInterface/prop3", prop3);
    }
}
void OLinkManyParamInterfaceAdapter::OnProp4Changed(int prop4)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("testbed2.ManyParamInterface/prop4", prop4);
    }
}

