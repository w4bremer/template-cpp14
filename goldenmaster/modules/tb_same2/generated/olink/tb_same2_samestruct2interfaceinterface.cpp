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



#include "tb_same2_samestruct2interfaceinterface.h"

#include "generated/core/tb_same2.json.adapter.h"

using namespace Test::TbSame2;

OLinkSameStruct2Interface::OLinkSameStruct2Interface(ApiGear::ObjectLink::ClientRegistry& registry, ApiGear::PocoImpl::OLinkClient& client)
    : m_isReady(false)
    , m_prop1(Struct2())
    , m_prop2(Struct2())
    , m_node(nullptr)
    , m_registry(&registry)
    , m_publisher(new SameStruct2InterfacePublisher())
{
    m_node = m_registry->addObjectSink(this);
    client.linkObjectSource("tb.same2.SameStruct2Interface");
}

OLinkSameStruct2Interface::~OLinkSameStruct2Interface()
{
    m_registry->removeObjectSink(this);
}

void OLinkSameStruct2Interface::applyState(const nlohmann::json& fields) 
{
    if(fields.contains("prop1")) {
        setProp1Local(fields["prop1"].get<Struct2>());
    }
    if(fields.contains("prop2")) {
        setProp2Local(fields["prop2"].get<Struct2>());
    }
}

void OLinkSameStruct2Interface::setProp1(const Struct2& prop1)
{
    if(m_node == nullptr) {
        return;
    }
    m_node->setRemoteProperty("tb.same2.SameStruct2Interface/prop1", prop1);
}

void OLinkSameStruct2Interface::setProp1Local(const Struct2& prop1)
{
    if (m_prop1 != prop1) {
        m_prop1 = prop1;
        m_publisher->publishProp1Changed(prop1);
    }
}

const Struct2& OLinkSameStruct2Interface::prop1() const
{
    return m_prop1;
}

void OLinkSameStruct2Interface::setProp2(const Struct2& prop2)
{
    if(m_node == nullptr) {
        return;
    }
    m_node->setRemoteProperty("tb.same2.SameStruct2Interface/prop2", prop2);
}

void OLinkSameStruct2Interface::setProp2Local(const Struct2& prop2)
{
    if (m_prop2 != prop2) {
        m_prop2 = prop2;
        m_publisher->publishProp2Changed(prop2);
    }
}

const Struct2& OLinkSameStruct2Interface::prop2() const
{
    return m_prop2;
}

Struct1 OLinkSameStruct2Interface::func1(const Struct1& param1)
{
    if(m_node == nullptr) {
        return Struct1();
    }
    Struct1 value(func1Async(param1).get());
    return value;
}

std::future<Struct1> OLinkSameStruct2Interface::func1Async(const Struct1& param1)
{
    if(m_node == nullptr) {
        throw std::runtime_error("Node is not initialized");
    }
    return std::async(std::launch::async, [this,
                    param1]()
        {
            std::promise<Struct1> resultPromise;
            m_node->invokeRemote("tb.same2.SameStruct2Interface/func1",
                nlohmann::json::array({param1}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const Struct1& value = arg.value.get<Struct1>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

Struct1 OLinkSameStruct2Interface::func2(const Struct1& param1, const Struct2& param2)
{
    if(m_node == nullptr) {
        return Struct1();
    }
    Struct1 value(func2Async(param1, param2).get());
    return value;
}

std::future<Struct1> OLinkSameStruct2Interface::func2Async(const Struct1& param1, const Struct2& param2)
{
    if(m_node == nullptr) {
        throw std::runtime_error("Node is not initialized");
    }
    return std::async(std::launch::async, [this,
                    param1,
                    param2]()
        {
            std::promise<Struct1> resultPromise;
            m_node->invokeRemote("tb.same2.SameStruct2Interface/func2",
                nlohmann::json::array({param1,param2}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const Struct1& value = arg.value.get<Struct1>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}


std::string OLinkSameStruct2Interface::olinkObjectName()
{
    return "tb.same2.SameStruct2Interface";
}

void OLinkSameStruct2Interface::olinkOnSignal(std::string name, nlohmann::json args)
{
    std::string path = ApiGear::ObjectLink::Name::pathFromName(name);
    if(path == "sig1") {
        m_publisher->publishSig1(args[0].get<Struct1>());   
        return;
    }
    if(path == "sig2") {
        m_publisher->publishSig2(args[0].get<Struct1>(),args[1].get<Struct2>());   
        return;
    }
}

void OLinkSameStruct2Interface::olinkOnPropertyChanged(std::string name, nlohmann::json value)
{
    std::string path = ApiGear::ObjectLink::Name::pathFromName(name);
    applyState({ {path, value} });
}
void OLinkSameStruct2Interface::olinkOnInit(std::string name, nlohmann::json props, ApiGear::ObjectLink::IClientNode *node)
{
    (void) name;
    m_isReady = true;
    m_node = node;
    applyState(props);
}

void OLinkSameStruct2Interface::olinkOnRelease()
{
    m_isReady = false;
    m_node = nullptr;
}

bool OLinkSameStruct2Interface::isReady() const
{
    return m_isReady;
}

ISameStruct2InterfacePublisher* OLinkSameStruct2Interface::_getPublisher() const
{
    return m_publisher;
}
