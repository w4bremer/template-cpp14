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
#include "org_objectapi_testbed_interface1adapter.h"

//#include "../api/agent.h"
#include "generated/core/org_objectapi_testbed.json.adapter.h"

using namespace Test::OrgObjectapiTestbed;

OLinkInterface1Adapter::OLinkInterface1Adapter(IInterface1* impl, ApiGear::ObjectLink::RemoteRegistry& registry)
    : m_impl(impl)
    , m_node(nullptr)
    , m_registry(&registry)
{
    m_impl->_getPublisher()->subscribeToInterface1Interface(*this);
    m_registry->addObjectSource(this);
}

OLinkInterface1Adapter::~OLinkInterface1Adapter()
{
    m_registry->removeObjectSource(this);
    m_impl->_getPublisher()->unsubscribeFromInterface1Interface(*this);
}

nlohmann::json OLinkInterface1Adapter::captureState()
{
    return nlohmann::json::object({
        { "prop1", m_impl->prop1() },
        { "prop2", m_impl->prop2() },
        { "prop3", m_impl->prop3() },
        { "prop4", m_impl->prop4() },
        { "prop5", m_impl->prop5() },
        { "prop6", m_impl->prop6() },
        { "prop7", m_impl->prop7() },
        { "prop10", m_impl->prop10() },
        { "prop11", m_impl->prop11() },
        { "prop12", m_impl->prop12() },
        { "prop14", m_impl->prop14() }
    });
}

void OLinkInterface1Adapter::applyState(const nlohmann::json& state)
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
    if(state.contains("prop5")) {
        m_impl->setProp5(state["prop5"]);
    }
    if(state.contains("prop6")) {
        m_impl->setProp6(state["prop6"]);
    }
    if(state.contains("prop7")) {
        m_impl->setProp7(state["prop7"]);
    }
    if(state.contains("prop10")) {
        m_impl->setProp10(state["prop10"]);
    }
    if(state.contains("prop11")) {
        m_impl->setProp11(state["prop11"]);
    }
    if(state.contains("prop12")) {
        m_impl->setProp12(state["prop12"]);
    }
    if(state.contains("prop14")) {
        m_impl->setProp14(state["prop14"]);
    }
}


std::string OLinkInterface1Adapter::olinkObjectName() {
    return "org.objectapi.testbed.Interface1";
}

nlohmann::json OLinkInterface1Adapter::olinkInvoke(std::string fcnName, nlohmann::json fcnArgs) {
    std::clog << fcnName << std::endl;
    std::string path = ApiGear::ObjectLink::Name::pathFromName(fcnName);
    if(path == "op1") {
        m_impl->op1();
        return nlohmann::json{};
    }
    if(path == "op2") {
        const int& step = fcnArgs.at(0);
        m_impl->op2(step);
        return nlohmann::json{};
    }
    if(path == "op3") {
        int result = m_impl->op3();
        return result;
    }
    return nlohmann::json();
}

void OLinkInterface1Adapter::olinkSetProperty(std::string name, nlohmann::json value) {
    std::clog << name << std::endl;
    std::string path = ApiGear::ObjectLink::Name::pathFromName(name);
    if(path == "prop1") {
        bool prop1 = value.get<bool>();
        m_impl->setProp1(prop1);
    }
    if(path == "prop2") {
        int prop2 = value.get<int>();
        m_impl->setProp2(prop2);
    }
    if(path == "prop3") {
        float prop3 = value.get<float>();
        m_impl->setProp3(prop3);
    }
    if(path == "prop4") {
        std::string prop4 = value.get<std::string>();
        m_impl->setProp4(prop4);
    }
    if(path == "prop5") {
        std::list<int> prop5 = value.get<std::list<int>>();
        m_impl->setProp5(prop5);
    }
    if(path == "prop6") {
        Struct1 prop6 = value.get<Struct1>();
        m_impl->setProp6(prop6);
    }
    if(path == "prop7") {
        int prop7 = value.get<int>();
        m_impl->setProp7(prop7);
    }
    if(path == "prop10") {
        std::list<int> prop10 = value.get<std::list<int>>();
        m_impl->setProp10(prop10);
    }
    if(path == "prop11") {
        std::list<Struct1> prop11 = value.get<std::list<Struct1>>();
        m_impl->setProp11(prop11);
    }
    if(path == "prop12") {
        std::list<Enum1Enum> prop12 = value.get<std::list<Enum1Enum>>();
        m_impl->setProp12(prop12);
    }
    if(path == "prop14") {
        std::list<Struct1> prop14 = value.get<std::list<Struct1>>();
        m_impl->setProp14(prop14);
    } 
}

void OLinkInterface1Adapter::olinkLinked(std::string name, ApiGear::ObjectLink::IRemoteNode *node) {
    std::clog << name << std::endl;
    m_node = node;
}

void OLinkInterface1Adapter::olinkUnlinked(std::string name)
{
    std::clog << name << std::endl;
    m_node = nullptr;
}

nlohmann::json OLinkInterface1Adapter::olinkCollectProperties()
{
    return captureState();
}
void OLinkInterface1Adapter::OnSig1()
{
    if(m_node != nullptr) {
        const nlohmann::json& args = {  };
        m_node->notifySignal("org.objectapi.testbed.Interface1/sig1", args);
    }
}
void OLinkInterface1Adapter::OnSig2(int step)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { step };
        m_node->notifySignal("org.objectapi.testbed.Interface1/sig2", args);
    }
}
void OLinkInterface1Adapter::OnSig3()
{
    if(m_node != nullptr) {
        const nlohmann::json& args = {  };
        m_node->notifySignal("org.objectapi.testbed.Interface1/sig3", args);
    }
}
void OLinkInterface1Adapter::OnProp1Changed(bool prop1)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("org.objectapi.testbed.Interface1/prop1", prop1);
    }
}
void OLinkInterface1Adapter::OnProp2Changed(int prop2)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("org.objectapi.testbed.Interface1/prop2", prop2);
    }
}
void OLinkInterface1Adapter::OnProp3Changed(float prop3)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("org.objectapi.testbed.Interface1/prop3", prop3);
    }
}
void OLinkInterface1Adapter::OnProp4Changed(std::string prop4)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("org.objectapi.testbed.Interface1/prop4", prop4);
    }
}
void OLinkInterface1Adapter::OnProp5Changed(const std::list<int>& prop5)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("org.objectapi.testbed.Interface1/prop5", prop5);
    }
}
void OLinkInterface1Adapter::OnProp6Changed(const Struct1& prop6)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("org.objectapi.testbed.Interface1/prop6", prop6);
    }
}
void OLinkInterface1Adapter::OnProp7Changed(int prop7)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("org.objectapi.testbed.Interface1/prop7", prop7);
    }
}
void OLinkInterface1Adapter::OnProp10Changed(const std::list<int>& prop10)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("org.objectapi.testbed.Interface1/prop10", prop10);
    }
}
void OLinkInterface1Adapter::OnProp11Changed(const std::list<Struct1>& prop11)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("org.objectapi.testbed.Interface1/prop11", prop11);
    }
}
void OLinkInterface1Adapter::OnProp12Changed(const std::list<Enum1Enum>& prop12)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("org.objectapi.testbed.Interface1/prop12", prop12);
    }
}
void OLinkInterface1Adapter::OnProp14Changed(const std::list<Struct1>& prop14)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("org.objectapi.testbed.Interface1/prop14", prop14);
    }
}

