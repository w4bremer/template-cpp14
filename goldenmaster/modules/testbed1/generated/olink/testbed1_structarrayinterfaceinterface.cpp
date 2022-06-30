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



#include "testbed1_structarrayinterfaceinterface.h"

#include "generated/core/testbed1.json.adapter.h"

using namespace Test::Testbed1;

OLinkStructArrayInterface::OLinkStructArrayInterface(ApiGear::ObjectLink::ClientRegistry& registry, ApiGear::PocoImpl::OLinkClient& client)
    : m_isReady(false)
    , m_propBool(std::list<StructBool>())
    , m_propInt(std::list<StructInt>())
    , m_propFloat(std::list<StructFloat>())
    , m_propString(std::list<StructString>())
    , m_node(nullptr)
    , m_registry(&registry)
    , m_publisher(new StructArrayInterfacePublisher())
{
    m_node = m_registry->addObjectSink(this);
    client.linkObjectSource("testbed1.StructArrayInterface");
}

OLinkStructArrayInterface::~OLinkStructArrayInterface()
{
    m_registry->removeObjectSink(this);
}

void OLinkStructArrayInterface::applyState(const nlohmann::json& fields) 
{
    if(fields.contains("propBool")) {
        setPropboolLocal(fields["propBool"].get<std::list<StructBool>>());
    }
    if(fields.contains("propInt")) {
        setPropintLocal(fields["propInt"].get<std::list<StructInt>>());
    }
    if(fields.contains("propFloat")) {
        setPropfloatLocal(fields["propFloat"].get<std::list<StructFloat>>());
    }
    if(fields.contains("propString")) {
        setPropstringLocal(fields["propString"].get<std::list<StructString>>());
    }
}

void OLinkStructArrayInterface::setPropbool(const std::list<StructBool>& propBool)
{
    if(m_node == nullptr) {
        return;
    }
    m_node->setRemoteProperty("testbed1.StructArrayInterface/propBool", propBool);
}

void OLinkStructArrayInterface::setPropboolLocal(const std::list<StructBool>& propBool)
{
    if (m_propBool != propBool) {
        m_propBool = propBool;
        m_publisher->publishPropBoolChanged(propBool);
    }
}

const std::list<StructBool>& OLinkStructArrayInterface::propBool() const
{
    return m_propBool;
}

void OLinkStructArrayInterface::setPropint(const std::list<StructInt>& propInt)
{
    if(m_node == nullptr) {
        return;
    }
    m_node->setRemoteProperty("testbed1.StructArrayInterface/propInt", propInt);
}

void OLinkStructArrayInterface::setPropintLocal(const std::list<StructInt>& propInt)
{
    if (m_propInt != propInt) {
        m_propInt = propInt;
        m_publisher->publishPropIntChanged(propInt);
    }
}

const std::list<StructInt>& OLinkStructArrayInterface::propInt() const
{
    return m_propInt;
}

void OLinkStructArrayInterface::setPropfloat(const std::list<StructFloat>& propFloat)
{
    if(m_node == nullptr) {
        return;
    }
    m_node->setRemoteProperty("testbed1.StructArrayInterface/propFloat", propFloat);
}

void OLinkStructArrayInterface::setPropfloatLocal(const std::list<StructFloat>& propFloat)
{
    if (m_propFloat != propFloat) {
        m_propFloat = propFloat;
        m_publisher->publishPropFloatChanged(propFloat);
    }
}

const std::list<StructFloat>& OLinkStructArrayInterface::propFloat() const
{
    return m_propFloat;
}

void OLinkStructArrayInterface::setPropstring(const std::list<StructString>& propString)
{
    if(m_node == nullptr) {
        return;
    }
    m_node->setRemoteProperty("testbed1.StructArrayInterface/propString", propString);
}

void OLinkStructArrayInterface::setPropstringLocal(const std::list<StructString>& propString)
{
    if (m_propString != propString) {
        m_propString = propString;
        m_publisher->publishPropStringChanged(propString);
    }
}

const std::list<StructString>& OLinkStructArrayInterface::propString() const
{
    return m_propString;
}

StructBool OLinkStructArrayInterface::funcBool(const std::list<StructBool>& paramBool)
{
    if(m_node == nullptr) {
        return StructBool();
    }
    StructBool value(funcBoolAsync(paramBool).get());
    return value;
}

std::future<StructBool> OLinkStructArrayInterface::funcBoolAsync(const std::list<StructBool>& paramBool)
{
    if(m_node == nullptr) {
        throw std::runtime_error("Node is not initialized");
    }
    return std::async(std::launch::async, [this,
                    paramBool]()
        {
            std::promise<StructBool> resultPromise;
            m_node->invokeRemote("testbed1.StructArrayInterface/funcBool",
                nlohmann::json::array({paramBool}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const StructBool& value = arg.value.get<StructBool>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

StructBool OLinkStructArrayInterface::funcInt(const std::list<StructInt>& paramInt)
{
    if(m_node == nullptr) {
        return StructBool();
    }
    StructBool value(funcIntAsync(paramInt).get());
    return value;
}

std::future<StructBool> OLinkStructArrayInterface::funcIntAsync(const std::list<StructInt>& paramInt)
{
    if(m_node == nullptr) {
        throw std::runtime_error("Node is not initialized");
    }
    return std::async(std::launch::async, [this,
                    paramInt]()
        {
            std::promise<StructBool> resultPromise;
            m_node->invokeRemote("testbed1.StructArrayInterface/funcInt",
                nlohmann::json::array({paramInt}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const StructBool& value = arg.value.get<StructBool>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

StructBool OLinkStructArrayInterface::funcFloat(const std::list<StructFloat>& paramFloat)
{
    if(m_node == nullptr) {
        return StructBool();
    }
    StructBool value(funcFloatAsync(paramFloat).get());
    return value;
}

std::future<StructBool> OLinkStructArrayInterface::funcFloatAsync(const std::list<StructFloat>& paramFloat)
{
    if(m_node == nullptr) {
        throw std::runtime_error("Node is not initialized");
    }
    return std::async(std::launch::async, [this,
                    paramFloat]()
        {
            std::promise<StructBool> resultPromise;
            m_node->invokeRemote("testbed1.StructArrayInterface/funcFloat",
                nlohmann::json::array({paramFloat}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const StructBool& value = arg.value.get<StructBool>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

StructBool OLinkStructArrayInterface::funcString(const std::list<StructString>& paramString)
{
    if(m_node == nullptr) {
        return StructBool();
    }
    StructBool value(funcStringAsync(paramString).get());
    return value;
}

std::future<StructBool> OLinkStructArrayInterface::funcStringAsync(const std::list<StructString>& paramString)
{
    if(m_node == nullptr) {
        throw std::runtime_error("Node is not initialized");
    }
    return std::async(std::launch::async, [this,
                    paramString]()
        {
            std::promise<StructBool> resultPromise;
            m_node->invokeRemote("testbed1.StructArrayInterface/funcString",
                nlohmann::json::array({paramString}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const StructBool& value = arg.value.get<StructBool>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}


std::string OLinkStructArrayInterface::olinkObjectName()
{
    return "testbed1.StructArrayInterface";
}

void OLinkStructArrayInterface::olinkOnSignal(std::string name, nlohmann::json args)
{
    std::string path = ApiGear::ObjectLink::Name::pathFromName(name);
    if(path == "sigBool") {
        m_publisher->publishSigBool(args[0].get<std::list<StructBool>>());   
        return;
    }
    if(path == "sigInt") {
        m_publisher->publishSigInt(args[0].get<std::list<StructInt>>());   
        return;
    }
    if(path == "sigFloat") {
        m_publisher->publishSigFloat(args[0].get<std::list<StructFloat>>());   
        return;
    }
    if(path == "sigString") {
        m_publisher->publishSigString(args[0].get<std::list<StructString>>());   
        return;
    }
}

void OLinkStructArrayInterface::olinkOnPropertyChanged(std::string name, nlohmann::json value)
{
    std::string path = ApiGear::ObjectLink::Name::pathFromName(name);
    applyState({ {path, value} });
}
void OLinkStructArrayInterface::olinkOnInit(std::string name, nlohmann::json props, ApiGear::ObjectLink::IClientNode *node)
{
    (void) name;
    m_isReady = true;
    m_node = node;
    applyState(props);
}

void OLinkStructArrayInterface::olinkOnRelease()
{
    m_isReady = false;
    m_node = nullptr;
}

bool OLinkStructArrayInterface::isReady() const
{
    return m_isReady;
}

IStructArrayInterfacePublisher* OLinkStructArrayInterface::_getPublisher() const
{
    return m_publisher;
}
