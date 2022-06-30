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



#include "testbed1_structinterfaceinterface.h"

#include "generated/core/testbed1.json.adapter.h"

using namespace Test::Testbed1;

OLinkStructInterface::OLinkStructInterface(ApiGear::ObjectLink::ClientRegistry& registry, ApiGear::PocoImpl::OLinkClient& client)
    : m_isReady(false)
    , m_propBool(StructBool())
    , m_propInt(StructInt())
    , m_propFloat(StructFloat())
    , m_propString(StructString())
    , m_node(nullptr)
    , m_registry(&registry)
    , m_publisher(new StructInterfacePublisher())
{
    m_node = m_registry->addObjectSink(this);
    client.linkObjectSource("testbed1.StructInterface");
}

OLinkStructInterface::~OLinkStructInterface()
{
    m_registry->removeObjectSink(this);
}

void OLinkStructInterface::applyState(const nlohmann::json& fields) 
{
    if(fields.contains("propBool")) {
        setPropboolLocal(fields["propBool"].get<StructBool>());
    }
    if(fields.contains("propInt")) {
        setPropintLocal(fields["propInt"].get<StructInt>());
    }
    if(fields.contains("propFloat")) {
        setPropfloatLocal(fields["propFloat"].get<StructFloat>());
    }
    if(fields.contains("propString")) {
        setPropstringLocal(fields["propString"].get<StructString>());
    }
}

void OLinkStructInterface::setPropbool(const StructBool& propBool)
{
    if(m_node == nullptr) {
        return;
    }
    m_node->setRemoteProperty("testbed1.StructInterface/propBool", propBool);
}

void OLinkStructInterface::setPropboolLocal(const StructBool& propBool)
{
    if (m_propBool != propBool) {
        m_propBool = propBool;
        m_publisher->publishPropBoolChanged(propBool);
    }
}

const StructBool& OLinkStructInterface::propBool() const
{
    return m_propBool;
}

void OLinkStructInterface::setPropint(const StructInt& propInt)
{
    if(m_node == nullptr) {
        return;
    }
    m_node->setRemoteProperty("testbed1.StructInterface/propInt", propInt);
}

void OLinkStructInterface::setPropintLocal(const StructInt& propInt)
{
    if (m_propInt != propInt) {
        m_propInt = propInt;
        m_publisher->publishPropIntChanged(propInt);
    }
}

const StructInt& OLinkStructInterface::propInt() const
{
    return m_propInt;
}

void OLinkStructInterface::setPropfloat(const StructFloat& propFloat)
{
    if(m_node == nullptr) {
        return;
    }
    m_node->setRemoteProperty("testbed1.StructInterface/propFloat", propFloat);
}

void OLinkStructInterface::setPropfloatLocal(const StructFloat& propFloat)
{
    if (m_propFloat != propFloat) {
        m_propFloat = propFloat;
        m_publisher->publishPropFloatChanged(propFloat);
    }
}

const StructFloat& OLinkStructInterface::propFloat() const
{
    return m_propFloat;
}

void OLinkStructInterface::setPropstring(const StructString& propString)
{
    if(m_node == nullptr) {
        return;
    }
    m_node->setRemoteProperty("testbed1.StructInterface/propString", propString);
}

void OLinkStructInterface::setPropstringLocal(const StructString& propString)
{
    if (m_propString != propString) {
        m_propString = propString;
        m_publisher->publishPropStringChanged(propString);
    }
}

const StructString& OLinkStructInterface::propString() const
{
    return m_propString;
}

StructBool OLinkStructInterface::funcBool(const StructBool& paramBool)
{
    if(m_node == nullptr) {
        return StructBool();
    }
    StructBool value(funcBoolAsync(paramBool).get());
    return value;
}

std::future<StructBool> OLinkStructInterface::funcBoolAsync(const StructBool& paramBool)
{
    if(m_node == nullptr) {
        throw std::runtime_error("Node is not initialized");
    }
    return std::async(std::launch::async, [this,
                    paramBool]()
        {
            std::promise<StructBool> resultPromise;
            m_node->invokeRemote("testbed1.StructInterface/funcBool",
                nlohmann::json::array({paramBool}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const StructBool& value = arg.value.get<StructBool>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

StructBool OLinkStructInterface::funcInt(const StructInt& paramInt)
{
    if(m_node == nullptr) {
        return StructBool();
    }
    StructBool value(funcIntAsync(paramInt).get());
    return value;
}

std::future<StructBool> OLinkStructInterface::funcIntAsync(const StructInt& paramInt)
{
    if(m_node == nullptr) {
        throw std::runtime_error("Node is not initialized");
    }
    return std::async(std::launch::async, [this,
                    paramInt]()
        {
            std::promise<StructBool> resultPromise;
            m_node->invokeRemote("testbed1.StructInterface/funcInt",
                nlohmann::json::array({paramInt}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const StructBool& value = arg.value.get<StructBool>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

StructFloat OLinkStructInterface::funcFloat(const StructFloat& paramFloat)
{
    if(m_node == nullptr) {
        return StructFloat();
    }
    StructFloat value(funcFloatAsync(paramFloat).get());
    return value;
}

std::future<StructFloat> OLinkStructInterface::funcFloatAsync(const StructFloat& paramFloat)
{
    if(m_node == nullptr) {
        throw std::runtime_error("Node is not initialized");
    }
    return std::async(std::launch::async, [this,
                    paramFloat]()
        {
            std::promise<StructFloat> resultPromise;
            m_node->invokeRemote("testbed1.StructInterface/funcFloat",
                nlohmann::json::array({paramFloat}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const StructFloat& value = arg.value.get<StructFloat>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

StructString OLinkStructInterface::funcString(const StructString& paramString)
{
    if(m_node == nullptr) {
        return StructString();
    }
    StructString value(funcStringAsync(paramString).get());
    return value;
}

std::future<StructString> OLinkStructInterface::funcStringAsync(const StructString& paramString)
{
    if(m_node == nullptr) {
        throw std::runtime_error("Node is not initialized");
    }
    return std::async(std::launch::async, [this,
                    paramString]()
        {
            std::promise<StructString> resultPromise;
            m_node->invokeRemote("testbed1.StructInterface/funcString",
                nlohmann::json::array({paramString}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const StructString& value = arg.value.get<StructString>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}


std::string OLinkStructInterface::olinkObjectName()
{
    return "testbed1.StructInterface";
}

void OLinkStructInterface::olinkOnSignal(std::string name, nlohmann::json args)
{
    std::string path = ApiGear::ObjectLink::Name::pathFromName(name);
    if(path == "sigBool") {
        m_publisher->publishSigBool(args[0].get<StructBool>());   
        return;
    }
    if(path == "sigInt") {
        m_publisher->publishSigInt(args[0].get<StructInt>());   
        return;
    }
    if(path == "sigFloat") {
        m_publisher->publishSigFloat(args[0].get<StructFloat>());   
        return;
    }
    if(path == "sigString") {
        m_publisher->publishSigString(args[0].get<StructString>());   
        return;
    }
}

void OLinkStructInterface::olinkOnPropertyChanged(std::string name, nlohmann::json value)
{
    std::string path = ApiGear::ObjectLink::Name::pathFromName(name);
    applyState({ {path, value} });
}
void OLinkStructInterface::olinkOnInit(std::string name, nlohmann::json props, ApiGear::ObjectLink::IClientNode *node)
{
    (void) name;
    m_isReady = true;
    m_node = node;
    applyState(props);
}

void OLinkStructInterface::olinkOnRelease()
{
    m_isReady = false;
    m_node = nullptr;
}

bool OLinkStructInterface::isReady() const
{
    return m_isReady;
}

IStructInterfacePublisher* OLinkStructInterface::_getPublisher() const
{
    return m_publisher;
}
