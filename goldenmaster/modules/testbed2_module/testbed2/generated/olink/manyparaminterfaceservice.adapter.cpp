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


#include "testbed2/generated/olink/manyparaminterfaceservice.adapter.h"
#include "testbed2/generated/core/testbed2.json.adapter.h"
#include <iostream>

using namespace Test::Testbed2;
using namespace Test::Testbed2::olink;

ManyParamInterfaceServiceAdapter::ManyParamInterfaceServiceAdapter(IManyParamInterface& ManyParamInterface, ApiGear::ObjectLink::RemoteRegistry& registry)
    : m_ManyParamInterface(ManyParamInterface)
    , m_node(nullptr)
    , m_registry(registry)
{
    m_ManyParamInterface._getPublisher().subscribeToAllChanges(*this);
    m_registry.addObjectSource(this);
}

ManyParamInterfaceServiceAdapter::~ManyParamInterfaceServiceAdapter()
{
    m_registry.removeObjectSource(this);
    m_ManyParamInterface._getPublisher().unsubscribeFromAllChanges(*this);
}

std::string ManyParamInterfaceServiceAdapter::olinkObjectName() {
    return "testbed2.ManyParamInterface";
}

nlohmann::json ManyParamInterfaceServiceAdapter::olinkInvoke(std::string fcnName, nlohmann::json fcnArgs) {
    std::clog << fcnName << std::endl;
    std::string path = ApiGear::ObjectLink::Name::pathFromName(fcnName);
    if(path == "func1") {
        const int& param1 = fcnArgs.at(0);
        int result = m_ManyParamInterface.func1(param1);
        return result;
    }
    if(path == "func2") {
        const int& param1 = fcnArgs.at(0);
        const int& param2 = fcnArgs.at(1);
        int result = m_ManyParamInterface.func2(param1, param2);
        return result;
    }
    if(path == "func3") {
        const int& param1 = fcnArgs.at(0);
        const int& param2 = fcnArgs.at(1);
        const int& param3 = fcnArgs.at(2);
        int result = m_ManyParamInterface.func3(param1, param2, param3);
        return result;
    }
    if(path == "func4") {
        const int& param1 = fcnArgs.at(0);
        const int& param2 = fcnArgs.at(1);
        const int& param3 = fcnArgs.at(2);
        const int& param4 = fcnArgs.at(3);
        int result = m_ManyParamInterface.func4(param1, param2, param3, param4);
        return result;
    }
    return nlohmann::json();
}

void ManyParamInterfaceServiceAdapter::olinkSetProperty(std::string name, nlohmann::json value) {
    std::clog << name << std::endl;
    std::string path = ApiGear::ObjectLink::Name::pathFromName(name);
    if(path == "prop1") {
        int prop1 = value.get<int>();
        m_ManyParamInterface.setProp1(prop1);
    }
    if(path == "prop2") {
        int prop2 = value.get<int>();
        m_ManyParamInterface.setProp2(prop2);
    }
    if(path == "prop3") {
        int prop3 = value.get<int>();
        m_ManyParamInterface.setProp3(prop3);
    }
    if(path == "prop4") {
        int prop4 = value.get<int>();
        m_ManyParamInterface.setProp4(prop4);
    } 
}

void ManyParamInterfaceServiceAdapter::olinkLinked(std::string name, ApiGear::ObjectLink::IRemoteNode *node) {
    std::clog << name << std::endl;
    m_node = node;
}

void ManyParamInterfaceServiceAdapter::olinkUnlinked(std::string name)
{
    std::clog << name << std::endl;
    m_node = nullptr;
}

nlohmann::json ManyParamInterfaceServiceAdapter::olinkCollectProperties()
{
    return nlohmann::json::object({
        { "prop1", m_ManyParamInterface.prop1() },
        { "prop2", m_ManyParamInterface.prop2() },
        { "prop3", m_ManyParamInterface.prop3() },
        { "prop4", m_ManyParamInterface.prop4() }
    });
}
void ManyParamInterfaceServiceAdapter::onSig1(int param1)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { param1 };
        m_node->notifySignal("testbed2.ManyParamInterface/sig1", args);
    }
}
void ManyParamInterfaceServiceAdapter::onSig2(int param1,int param2)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { param1, param2 };
        m_node->notifySignal("testbed2.ManyParamInterface/sig2", args);
    }
}
void ManyParamInterfaceServiceAdapter::onSig3(int param1,int param2,int param3)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { param1, param2, param3 };
        m_node->notifySignal("testbed2.ManyParamInterface/sig3", args);
    }
}
void ManyParamInterfaceServiceAdapter::onSig4(int param1,int param2,int param3,int param4)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { param1, param2, param3, param4 };
        m_node->notifySignal("testbed2.ManyParamInterface/sig4", args);
    }
}
void ManyParamInterfaceServiceAdapter::onProp1Changed(int prop1)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("testbed2.ManyParamInterface/prop1", prop1);
    }
}
void ManyParamInterfaceServiceAdapter::onProp2Changed(int prop2)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("testbed2.ManyParamInterface/prop2", prop2);
    }
}
void ManyParamInterfaceServiceAdapter::onProp3Changed(int prop3)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("testbed2.ManyParamInterface/prop3", prop3);
    }
}
void ManyParamInterfaceServiceAdapter::onProp4Changed(int prop4)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("testbed2.ManyParamInterface/prop4", prop4);
    }
}

