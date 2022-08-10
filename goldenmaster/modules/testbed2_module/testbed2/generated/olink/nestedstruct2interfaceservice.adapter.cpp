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


#include "testbed2/generated/olink/nestedstruct2interfaceservice.adapter.h"
#include "testbed2/generated/core/testbed2.json.adapter.h"
#include <iostream>

using namespace Test::Testbed2;
using namespace Test::Testbed2::olink;

NestedStruct2InterfaceServiceAdapter::NestedStruct2InterfaceServiceAdapter(INestedStruct2Interface& NestedStruct2Interface, ApiGear::ObjectLink::RemoteRegistry& registry)
    : m_NestedStruct2Interface(NestedStruct2Interface)
    , m_node(nullptr)
    , m_registry(registry)
{
    m_NestedStruct2Interface._getPublisher().subscribeToAllChanges(*this);
    m_registry.addObjectSource(this);
}

NestedStruct2InterfaceServiceAdapter::~NestedStruct2InterfaceServiceAdapter()
{
    m_registry.removeObjectSource(this);
    m_NestedStruct2Interface._getPublisher().unsubscribeFromAllChanges(*this);
}

std::string NestedStruct2InterfaceServiceAdapter::olinkObjectName() {
    return "testbed2.NestedStruct2Interface";
}

nlohmann::json NestedStruct2InterfaceServiceAdapter::olinkInvoke(std::string fcnName, nlohmann::json fcnArgs) {
    std::clog << fcnName << std::endl;
    std::string path = ApiGear::ObjectLink::Name::pathFromName(fcnName);
    if(path == "func1") {
        const NestedStruct1& param1 = fcnArgs.at(0);
        NestedStruct1 result = m_NestedStruct2Interface.func1(param1);
        return result;
    }
    if(path == "func2") {
        const NestedStruct1& param1 = fcnArgs.at(0);
        const NestedStruct2& param2 = fcnArgs.at(1);
        NestedStruct1 result = m_NestedStruct2Interface.func2(param1, param2);
        return result;
    }
    return nlohmann::json();
}

void NestedStruct2InterfaceServiceAdapter::olinkSetProperty(std::string name, nlohmann::json value) {
    std::clog << name << std::endl;
    std::string path = ApiGear::ObjectLink::Name::pathFromName(name);
    if(path == "prop1") {
        NestedStruct1 prop1 = value.get<NestedStruct1>();
        m_NestedStruct2Interface.setProp1(prop1);
    }
    if(path == "prop2") {
        NestedStruct2 prop2 = value.get<NestedStruct2>();
        m_NestedStruct2Interface.setProp2(prop2);
    } 
}

void NestedStruct2InterfaceServiceAdapter::olinkLinked(std::string name, ApiGear::ObjectLink::IRemoteNode *node) {
    std::clog << name << std::endl;
    m_node = node;
}

void NestedStruct2InterfaceServiceAdapter::olinkUnlinked(std::string name)
{
    std::clog << name << std::endl;
    m_node = nullptr;
}

nlohmann::json NestedStruct2InterfaceServiceAdapter::olinkCollectProperties()
{
    return nlohmann::json::object({
        { "prop1", m_NestedStruct2Interface.prop1() },
        { "prop2", m_NestedStruct2Interface.prop2() }
    });
}
void NestedStruct2InterfaceServiceAdapter::onSig1(const NestedStruct1& param1)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { param1 };
        m_node->notifySignal("testbed2.NestedStruct2Interface/sig1", args);
    }
}
void NestedStruct2InterfaceServiceAdapter::onSig2(const NestedStruct1& param1,const NestedStruct2& param2)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { param1, param2 };
        m_node->notifySignal("testbed2.NestedStruct2Interface/sig2", args);
    }
}
void NestedStruct2InterfaceServiceAdapter::onProp1Changed(const NestedStruct1& prop1)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("testbed2.NestedStruct2Interface/prop1", prop1);
    }
}
void NestedStruct2InterfaceServiceAdapter::onProp2Changed(const NestedStruct2& prop2)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("testbed2.NestedStruct2Interface/prop2", prop2);
    }
}

