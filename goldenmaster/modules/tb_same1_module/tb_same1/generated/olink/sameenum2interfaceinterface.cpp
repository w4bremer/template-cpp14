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



#include "tb_same1/generated/olink/sameenum2interfaceinterface.h"

#include "tb_same1/generated/core/tb_same1.json.adapter.h"

using namespace Test::TbSame1;

OLinkSameEnum2Interface::OLinkSameEnum2Interface(ApiGear::ObjectLink::ClientRegistry& registry, ApiGear::PocoImpl::OLinkClient& client)
    : m_isReady(false)
    , m_prop1(Enum1Enum::value1)
    , m_prop2(Enum2Enum::value1)
    , m_node(nullptr)
    , m_registry(&registry)
    , m_publisher(new SameEnum2InterfacePublisher())
{
    m_node = m_registry->addObjectSink(this);
    client.linkObjectSource("tb.same1.SameEnum2Interface");
}

OLinkSameEnum2Interface::~OLinkSameEnum2Interface()
{
    m_registry->removeObjectSink(this);
}

void OLinkSameEnum2Interface::applyState(const nlohmann::json& fields) 
{
    if(fields.contains("prop1")) {
        setProp1Local(fields["prop1"].get<Enum1Enum>());
    }
    if(fields.contains("prop2")) {
        setProp2Local(fields["prop2"].get<Enum2Enum>());
    }
}

void OLinkSameEnum2Interface::setProp1(const Enum1Enum& prop1)
{
    if(m_node == nullptr) {
        return;
    }
    m_node->setRemoteProperty("tb.same1.SameEnum2Interface/prop1", prop1);
}

void OLinkSameEnum2Interface::setProp1Local(const Enum1Enum& prop1)
{
    if (m_prop1 != prop1) {
        m_prop1 = prop1;
        m_publisher->publishProp1Changed(prop1);
    }
}

const Enum1Enum& OLinkSameEnum2Interface::prop1() const
{
    return m_prop1;
}

void OLinkSameEnum2Interface::setProp2(const Enum2Enum& prop2)
{
    if(m_node == nullptr) {
        return;
    }
    m_node->setRemoteProperty("tb.same1.SameEnum2Interface/prop2", prop2);
}

void OLinkSameEnum2Interface::setProp2Local(const Enum2Enum& prop2)
{
    if (m_prop2 != prop2) {
        m_prop2 = prop2;
        m_publisher->publishProp2Changed(prop2);
    }
}

const Enum2Enum& OLinkSameEnum2Interface::prop2() const
{
    return m_prop2;
}

Enum1Enum OLinkSameEnum2Interface::func1(const Enum1Enum& param1)
{
    if(m_node == nullptr) {
        return Enum1Enum::value1;
    }
    Enum1Enum value(func1Async(param1).get());
    return value;
}

std::future<Enum1Enum> OLinkSameEnum2Interface::func1Async(const Enum1Enum& param1)
{
    if(m_node == nullptr) {
        throw std::runtime_error("Node is not initialized");
    }
    return std::async(std::launch::async, [this,
                    param1]()
        {
            std::promise<Enum1Enum> resultPromise;
            m_node->invokeRemote("tb.same1.SameEnum2Interface/func1",
                nlohmann::json::array({param1}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const Enum1Enum& value = arg.value.get<Enum1Enum>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

Enum1Enum OLinkSameEnum2Interface::func2(const Enum1Enum& param1, const Enum2Enum& param2)
{
    if(m_node == nullptr) {
        return Enum1Enum::value1;
    }
    Enum1Enum value(func2Async(param1, param2).get());
    return value;
}

std::future<Enum1Enum> OLinkSameEnum2Interface::func2Async(const Enum1Enum& param1, const Enum2Enum& param2)
{
    if(m_node == nullptr) {
        throw std::runtime_error("Node is not initialized");
    }
    return std::async(std::launch::async, [this,
                    param1,
                    param2]()
        {
            std::promise<Enum1Enum> resultPromise;
            m_node->invokeRemote("tb.same1.SameEnum2Interface/func2",
                nlohmann::json::array({param1,param2}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const Enum1Enum& value = arg.value.get<Enum1Enum>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}


std::string OLinkSameEnum2Interface::olinkObjectName()
{
    return "tb.same1.SameEnum2Interface";
}

void OLinkSameEnum2Interface::olinkOnSignal(std::string name, nlohmann::json args)
{
    std::string path = ApiGear::ObjectLink::Name::pathFromName(name);
    if(path == "sig1") {
        m_publisher->publishSig1(args[0].get<Enum1Enum>());   
        return;
    }
    if(path == "sig2") {
        m_publisher->publishSig2(args[0].get<Enum1Enum>(),args[1].get<Enum2Enum>());   
        return;
    }
}

void OLinkSameEnum2Interface::olinkOnPropertyChanged(std::string name, nlohmann::json value)
{
    std::string path = ApiGear::ObjectLink::Name::pathFromName(name);
    applyState({ {path, value} });
}
void OLinkSameEnum2Interface::olinkOnInit(std::string name, nlohmann::json props, ApiGear::ObjectLink::IClientNode *node)
{
    (void) name;
    m_isReady = true;
    m_node = node;
    applyState(props);
}

void OLinkSameEnum2Interface::olinkOnRelease()
{
    m_isReady = false;
    m_node = nullptr;
}

bool OLinkSameEnum2Interface::isReady() const
{
    return m_isReady;
}

ISameEnum2InterfacePublisher* OLinkSameEnum2Interface::_getPublisher() const
{
    return m_publisher;
}
