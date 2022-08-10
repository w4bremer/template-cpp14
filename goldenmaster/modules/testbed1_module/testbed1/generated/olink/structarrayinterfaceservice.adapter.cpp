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


#include "testbed1/generated/olink/structarrayinterfaceservice.adapter.h"
#include "testbed1/generated/core/testbed1.json.adapter.h"
#include <iostream>

using namespace Test::Testbed1;
using namespace Test::Testbed1::olink;

StructArrayInterfaceServiceAdapter::StructArrayInterfaceServiceAdapter(IStructArrayInterface& StructArrayInterface, ApiGear::ObjectLink::RemoteRegistry& registry)
    : m_StructArrayInterface(StructArrayInterface)
    , m_node(nullptr)
    , m_registry(registry)
{
    m_StructArrayInterface._getPublisher().subscribeToAllChanges(*this);
    m_registry.addObjectSource(this);
}

StructArrayInterfaceServiceAdapter::~StructArrayInterfaceServiceAdapter()
{
    m_registry.removeObjectSource(this);
    m_StructArrayInterface._getPublisher().unsubscribeFromAllChanges(*this);
}

std::string StructArrayInterfaceServiceAdapter::olinkObjectName() {
    return "testbed1.StructArrayInterface";
}

nlohmann::json StructArrayInterfaceServiceAdapter::olinkInvoke(std::string fcnName, nlohmann::json fcnArgs) {
    std::clog << fcnName << std::endl;
    std::string path = ApiGear::ObjectLink::Name::pathFromName(fcnName);
    if(path == "funcBool") {
        const std::list<StructBool>& paramBool = fcnArgs.at(0);
        StructBool result = m_StructArrayInterface.funcBool(paramBool);
        return result;
    }
    if(path == "funcInt") {
        const std::list<StructInt>& paramInt = fcnArgs.at(0);
        StructBool result = m_StructArrayInterface.funcInt(paramInt);
        return result;
    }
    if(path == "funcFloat") {
        const std::list<StructFloat>& paramFloat = fcnArgs.at(0);
        StructBool result = m_StructArrayInterface.funcFloat(paramFloat);
        return result;
    }
    if(path == "funcString") {
        const std::list<StructString>& paramString = fcnArgs.at(0);
        StructBool result = m_StructArrayInterface.funcString(paramString);
        return result;
    }
    return nlohmann::json();
}

void StructArrayInterfaceServiceAdapter::olinkSetProperty(std::string name, nlohmann::json value) {
    std::clog << name << std::endl;
    std::string path = ApiGear::ObjectLink::Name::pathFromName(name);
    if(path == "propBool") {
        std::list<StructBool> propBool = value.get<std::list<StructBool>>();
        m_StructArrayInterface.setPropBool(propBool);
    }
    if(path == "propInt") {
        std::list<StructInt> propInt = value.get<std::list<StructInt>>();
        m_StructArrayInterface.setPropInt(propInt);
    }
    if(path == "propFloat") {
        std::list<StructFloat> propFloat = value.get<std::list<StructFloat>>();
        m_StructArrayInterface.setPropFloat(propFloat);
    }
    if(path == "propString") {
        std::list<StructString> propString = value.get<std::list<StructString>>();
        m_StructArrayInterface.setPropString(propString);
    } 
}

void StructArrayInterfaceServiceAdapter::olinkLinked(std::string name, ApiGear::ObjectLink::IRemoteNode *node) {
    std::clog << name << std::endl;
    m_node = node;
}

void StructArrayInterfaceServiceAdapter::olinkUnlinked(std::string name)
{
    std::clog << name << std::endl;
    m_node = nullptr;
}

nlohmann::json StructArrayInterfaceServiceAdapter::olinkCollectProperties()
{
    return nlohmann::json::object({
        { "propBool", m_StructArrayInterface.propBool() },
        { "propInt", m_StructArrayInterface.propInt() },
        { "propFloat", m_StructArrayInterface.propFloat() },
        { "propString", m_StructArrayInterface.propString() }
    });
}
void StructArrayInterfaceServiceAdapter::onSigBool(const std::list<StructBool>& paramBool)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { paramBool };
        m_node->notifySignal("testbed1.StructArrayInterface/sigBool", args);
    }
}
void StructArrayInterfaceServiceAdapter::onSigInt(const std::list<StructInt>& paramInt)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { paramInt };
        m_node->notifySignal("testbed1.StructArrayInterface/sigInt", args);
    }
}
void StructArrayInterfaceServiceAdapter::onSigFloat(const std::list<StructFloat>& paramFloat)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { paramFloat };
        m_node->notifySignal("testbed1.StructArrayInterface/sigFloat", args);
    }
}
void StructArrayInterfaceServiceAdapter::onSigString(const std::list<StructString>& paramString)
{
    if(m_node != nullptr) {
        const nlohmann::json& args = { paramString };
        m_node->notifySignal("testbed1.StructArrayInterface/sigString", args);
    }
}
void StructArrayInterfaceServiceAdapter::onPropBoolChanged(const std::list<StructBool>& propBool)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("testbed1.StructArrayInterface/propBool", propBool);
    }
}
void StructArrayInterfaceServiceAdapter::onPropIntChanged(const std::list<StructInt>& propInt)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("testbed1.StructArrayInterface/propInt", propInt);
    }
}
void StructArrayInterfaceServiceAdapter::onPropFloatChanged(const std::list<StructFloat>& propFloat)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("testbed1.StructArrayInterface/propFloat", propFloat);
    }
}
void StructArrayInterfaceServiceAdapter::onPropStringChanged(const std::list<StructString>& propString)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("testbed1.StructArrayInterface/propString", propString);
    }
}

