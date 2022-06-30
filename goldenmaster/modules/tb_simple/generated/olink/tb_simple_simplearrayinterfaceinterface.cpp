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



#include "tb_simple_simplearrayinterfaceinterface.h"

#include "generated/core/tb_simple.json.adapter.h"

using namespace Test::TbSimple;

OLinkSimpleArrayInterface::OLinkSimpleArrayInterface(ApiGear::ObjectLink::ClientRegistry& registry, ApiGear::PocoImpl::OLinkClient& client)
    : m_isReady(false)
    , m_propBool(std::list<bool>())
    , m_propInt(std::list<int>())
    , m_propFloat(std::list<float>())
    , m_propString(std::list<std::string>())
    , m_node(nullptr)
    , m_registry(&registry)
    , m_publisher(new SimpleArrayInterfacePublisher())
{
    m_node = m_registry->addObjectSink(this);
    client.linkObjectSource("tb.simple.SimpleArrayInterface");
}

OLinkSimpleArrayInterface::~OLinkSimpleArrayInterface()
{
    m_registry->removeObjectSink(this);
}

void OLinkSimpleArrayInterface::applyState(const nlohmann::json& fields) 
{
    if(fields.contains("propBool")) {
        setPropboolLocal(fields["propBool"].get<std::list<bool>>());
    }
    if(fields.contains("propInt")) {
        setPropintLocal(fields["propInt"].get<std::list<int>>());
    }
    if(fields.contains("propFloat")) {
        setPropfloatLocal(fields["propFloat"].get<std::list<float>>());
    }
    if(fields.contains("propString")) {
        setPropstringLocal(fields["propString"].get<std::list<std::string>>());
    }
}

void OLinkSimpleArrayInterface::setPropbool(const std::list<bool>& propBool)
{
    if(m_node == nullptr) {
        return;
    }
    m_node->setRemoteProperty("tb.simple.SimpleArrayInterface/propBool", propBool);
}

void OLinkSimpleArrayInterface::setPropboolLocal(const std::list<bool>& propBool)
{
    if (m_propBool != propBool) {
        m_propBool = propBool;
        m_publisher->publishPropBoolChanged(propBool);
    }
}

const std::list<bool>& OLinkSimpleArrayInterface::propBool() const
{
    return m_propBool;
}

void OLinkSimpleArrayInterface::setPropint(const std::list<int>& propInt)
{
    if(m_node == nullptr) {
        return;
    }
    m_node->setRemoteProperty("tb.simple.SimpleArrayInterface/propInt", propInt);
}

void OLinkSimpleArrayInterface::setPropintLocal(const std::list<int>& propInt)
{
    if (m_propInt != propInt) {
        m_propInt = propInt;
        m_publisher->publishPropIntChanged(propInt);
    }
}

const std::list<int>& OLinkSimpleArrayInterface::propInt() const
{
    return m_propInt;
}

void OLinkSimpleArrayInterface::setPropfloat(const std::list<float>& propFloat)
{
    if(m_node == nullptr) {
        return;
    }
    m_node->setRemoteProperty("tb.simple.SimpleArrayInterface/propFloat", propFloat);
}

void OLinkSimpleArrayInterface::setPropfloatLocal(const std::list<float>& propFloat)
{
    if (m_propFloat != propFloat) {
        m_propFloat = propFloat;
        m_publisher->publishPropFloatChanged(propFloat);
    }
}

const std::list<float>& OLinkSimpleArrayInterface::propFloat() const
{
    return m_propFloat;
}

void OLinkSimpleArrayInterface::setPropstring(const std::list<std::string>& propString)
{
    if(m_node == nullptr) {
        return;
    }
    m_node->setRemoteProperty("tb.simple.SimpleArrayInterface/propString", propString);
}

void OLinkSimpleArrayInterface::setPropstringLocal(const std::list<std::string>& propString)
{
    if (m_propString != propString) {
        m_propString = propString;
        m_publisher->publishPropStringChanged(propString);
    }
}

const std::list<std::string>& OLinkSimpleArrayInterface::propString() const
{
    return m_propString;
}

std::list<bool> OLinkSimpleArrayInterface::funcBool(const std::list<bool>& paramBool)
{
    if(m_node == nullptr) {
        return std::list<bool>();
    }
    std::list<bool> value(funcBoolAsync(paramBool).get());
    return value;
}

std::future<std::list<bool>> OLinkSimpleArrayInterface::funcBoolAsync(const std::list<bool>& paramBool)
{
    if(m_node == nullptr) {
        throw std::runtime_error("Node is not initialized");
    }
    return std::async(std::launch::async, [this,
                    paramBool]()
        {
            std::promise<std::list<bool>> resultPromise;
            m_node->invokeRemote("tb.simple.SimpleArrayInterface/funcBool",
                nlohmann::json::array({paramBool}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const std::list<bool>& value = arg.value.get<std::list<bool>>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

std::list<int> OLinkSimpleArrayInterface::funcInt(const std::list<int>& paramInt)
{
    if(m_node == nullptr) {
        return std::list<int>();
    }
    std::list<int> value(funcIntAsync(paramInt).get());
    return value;
}

std::future<std::list<int>> OLinkSimpleArrayInterface::funcIntAsync(const std::list<int>& paramInt)
{
    if(m_node == nullptr) {
        throw std::runtime_error("Node is not initialized");
    }
    return std::async(std::launch::async, [this,
                    paramInt]()
        {
            std::promise<std::list<int>> resultPromise;
            m_node->invokeRemote("tb.simple.SimpleArrayInterface/funcInt",
                nlohmann::json::array({paramInt}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const std::list<int>& value = arg.value.get<std::list<int>>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

std::list<float> OLinkSimpleArrayInterface::funcFloat(const std::list<float>& paramFloat)
{
    if(m_node == nullptr) {
        return std::list<float>();
    }
    std::list<float> value(funcFloatAsync(paramFloat).get());
    return value;
}

std::future<std::list<float>> OLinkSimpleArrayInterface::funcFloatAsync(const std::list<float>& paramFloat)
{
    if(m_node == nullptr) {
        throw std::runtime_error("Node is not initialized");
    }
    return std::async(std::launch::async, [this,
                    paramFloat]()
        {
            std::promise<std::list<float>> resultPromise;
            m_node->invokeRemote("tb.simple.SimpleArrayInterface/funcFloat",
                nlohmann::json::array({paramFloat}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const std::list<float>& value = arg.value.get<std::list<float>>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

std::list<std::string> OLinkSimpleArrayInterface::funcString(const std::list<std::string>& paramString)
{
    if(m_node == nullptr) {
        return std::list<std::string>();
    }
    std::list<std::string> value(funcStringAsync(paramString).get());
    return value;
}

std::future<std::list<std::string>> OLinkSimpleArrayInterface::funcStringAsync(const std::list<std::string>& paramString)
{
    if(m_node == nullptr) {
        throw std::runtime_error("Node is not initialized");
    }
    return std::async(std::launch::async, [this,
                    paramString]()
        {
            std::promise<std::list<std::string>> resultPromise;
            m_node->invokeRemote("tb.simple.SimpleArrayInterface/funcString",
                nlohmann::json::array({paramString}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const std::list<std::string>& value = arg.value.get<std::list<std::string>>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}


std::string OLinkSimpleArrayInterface::olinkObjectName()
{
    return "tb.simple.SimpleArrayInterface";
}

void OLinkSimpleArrayInterface::olinkOnSignal(std::string name, nlohmann::json args)
{
    std::string path = ApiGear::ObjectLink::Name::pathFromName(name);
    if(path == "sigBool") {
        m_publisher->publishSigBool(args[0].get<std::list<bool>>());   
        return;
    }
    if(path == "sigInt") {
        m_publisher->publishSigInt(args[0].get<std::list<int>>());   
        return;
    }
    if(path == "sigFloat") {
        m_publisher->publishSigFloat(args[0].get<std::list<float>>());   
        return;
    }
    if(path == "sigString") {
        m_publisher->publishSigString(args[0].get<std::list<std::string>>());   
        return;
    }
}

void OLinkSimpleArrayInterface::olinkOnPropertyChanged(std::string name, nlohmann::json value)
{
    std::string path = ApiGear::ObjectLink::Name::pathFromName(name);
    applyState({ {path, value} });
}
void OLinkSimpleArrayInterface::olinkOnInit(std::string name, nlohmann::json props, ApiGear::ObjectLink::IClientNode *node)
{
    (void) name;
    m_isReady = true;
    m_node = node;
    applyState(props);
}

void OLinkSimpleArrayInterface::olinkOnRelease()
{
    m_isReady = false;
    m_node = nullptr;
}

bool OLinkSimpleArrayInterface::isReady() const
{
    return m_isReady;
}

ISimpleArrayInterfacePublisher* OLinkSimpleArrayInterface::_getPublisher() const
{
    return m_publisher;
}
