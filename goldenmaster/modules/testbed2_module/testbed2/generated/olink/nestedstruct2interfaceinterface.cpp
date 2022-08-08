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



#include "testbed2/generated/olink/nestedstruct2interfaceinterface.h"

#include "testbed2/generated/core/testbed2.json.adapter.h"

using namespace Test::Testbed2;

OLinkNestedStruct2Interface::OLinkNestedStruct2Interface(ApiGear::ObjectLink::ClientRegistry& registry, ApiGear::PocoImpl::OLinkClient& client)
    : m_isReady(false)
    , m_prop1(NestedStruct1())
    , m_prop2(NestedStruct2())
    , m_node(nullptr)
    , m_registry(&registry)
    , m_publisher(new NestedStruct2InterfacePublisher())
{
    m_node = m_registry->addObjectSink(this);
    client.linkObjectSource("testbed2.NestedStruct2Interface");
}

OLinkNestedStruct2Interface::~OLinkNestedStruct2Interface()
{
    m_registry->removeObjectSink(this);
}

void OLinkNestedStruct2Interface::applyState(const nlohmann::json& fields) 
{
    if(fields.contains("prop1")) {
        setProp1Local(fields["prop1"].get<NestedStruct1>());
    }
    if(fields.contains("prop2")) {
        setProp2Local(fields["prop2"].get<NestedStruct2>());
    }
}

void OLinkNestedStruct2Interface::setProp1(const NestedStruct1& prop1)
{
    if(m_node == nullptr) {
        return;
    }
    m_node->setRemoteProperty("testbed2.NestedStruct2Interface/prop1", prop1);
}

void OLinkNestedStruct2Interface::setProp1Local(const NestedStruct1& prop1)
{
    if (m_prop1 != prop1) {
        m_prop1 = prop1;
        m_publisher->publishProp1Changed(prop1);
    }
}

const NestedStruct1& OLinkNestedStruct2Interface::prop1() const
{
    return m_prop1;
}

void OLinkNestedStruct2Interface::setProp2(const NestedStruct2& prop2)
{
    if(m_node == nullptr) {
        return;
    }
    m_node->setRemoteProperty("testbed2.NestedStruct2Interface/prop2", prop2);
}

void OLinkNestedStruct2Interface::setProp2Local(const NestedStruct2& prop2)
{
    if (m_prop2 != prop2) {
        m_prop2 = prop2;
        m_publisher->publishProp2Changed(prop2);
    }
}

const NestedStruct2& OLinkNestedStruct2Interface::prop2() const
{
    return m_prop2;
}

NestedStruct1 OLinkNestedStruct2Interface::func1(const NestedStruct1& param1)
{
    if(m_node == nullptr) {
        return NestedStruct1();
    }
    NestedStruct1 value(func1Async(param1).get());
    return value;
}

std::future<NestedStruct1> OLinkNestedStruct2Interface::func1Async(const NestedStruct1& param1)
{
    if(m_node == nullptr) {
        throw std::runtime_error("Node is not initialized");
    }
    return std::async(std::launch::async, [this,
                    param1]()
        {
            std::promise<NestedStruct1> resultPromise;
            m_node->invokeRemote("testbed2.NestedStruct2Interface/func1",
                nlohmann::json::array({param1}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const NestedStruct1& value = arg.value.get<NestedStruct1>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

NestedStruct1 OLinkNestedStruct2Interface::func2(const NestedStruct1& param1, const NestedStruct2& param2)
{
    if(m_node == nullptr) {
        return NestedStruct1();
    }
    NestedStruct1 value(func2Async(param1, param2).get());
    return value;
}

std::future<NestedStruct1> OLinkNestedStruct2Interface::func2Async(const NestedStruct1& param1, const NestedStruct2& param2)
{
    if(m_node == nullptr) {
        throw std::runtime_error("Node is not initialized");
    }
    return std::async(std::launch::async, [this,
                    param1,
                    param2]()
        {
            std::promise<NestedStruct1> resultPromise;
            m_node->invokeRemote("testbed2.NestedStruct2Interface/func2",
                nlohmann::json::array({param1,param2}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const NestedStruct1& value = arg.value.get<NestedStruct1>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}


std::string OLinkNestedStruct2Interface::olinkObjectName()
{
    return "testbed2.NestedStruct2Interface";
}

void OLinkNestedStruct2Interface::olinkOnSignal(std::string name, nlohmann::json args)
{
    std::string path = ApiGear::ObjectLink::Name::pathFromName(name);
    if(path == "sig1") {
        m_publisher->publishSig1(args[0].get<NestedStruct1>());   
        return;
    }
    if(path == "sig2") {
        m_publisher->publishSig2(args[0].get<NestedStruct1>(),args[1].get<NestedStruct2>());   
        return;
    }
}

void OLinkNestedStruct2Interface::olinkOnPropertyChanged(std::string name, nlohmann::json value)
{
    std::string path = ApiGear::ObjectLink::Name::pathFromName(name);
    applyState({ {path, value} });
}
void OLinkNestedStruct2Interface::olinkOnInit(std::string name, nlohmann::json props, ApiGear::ObjectLink::IClientNode *node)
{
    (void) name;
    m_isReady = true;
    m_node = node;
    applyState(props);
}

void OLinkNestedStruct2Interface::olinkOnRelease()
{
    m_isReady = false;
    m_node = nullptr;
}

bool OLinkNestedStruct2Interface::isReady() const
{
    return m_isReady;
}

INestedStruct2InterfacePublisher* OLinkNestedStruct2Interface::_getPublisher() const
{
    return m_publisher;
}
