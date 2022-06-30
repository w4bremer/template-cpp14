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



#include "tb_same2_samestruct1interfaceinterface.h"

#include "generated/core/tb_same2.json.adapter.h"

using namespace Test::TbSame2;

OLinkSameStruct1Interface::OLinkSameStruct1Interface(ApiGear::ObjectLink::ClientRegistry& registry, ApiGear::PocoImpl::OLinkClient& client)
    : m_isReady(false)
    , m_prop1(Struct1())
    , m_node(nullptr)
    , m_registry(&registry)
    , m_publisher(new SameStruct1InterfacePublisher())
{
    m_node = m_registry->addObjectSink(this);
    client.linkObjectSource("tb.same2.SameStruct1Interface");
}

OLinkSameStruct1Interface::~OLinkSameStruct1Interface()
{
    m_registry->removeObjectSink(this);
}

void OLinkSameStruct1Interface::applyState(const nlohmann::json& fields) 
{
    if(fields.contains("prop1")) {
        setProp1Local(fields["prop1"].get<Struct1>());
    }
}

void OLinkSameStruct1Interface::setProp1(const Struct1& prop1)
{
    if(m_node == nullptr) {
        return;
    }
    m_node->setRemoteProperty("tb.same2.SameStruct1Interface/prop1", prop1);
}

void OLinkSameStruct1Interface::setProp1Local(const Struct1& prop1)
{
    if (m_prop1 != prop1) {
        m_prop1 = prop1;
        m_publisher->publishProp1Changed(prop1);
    }
}

const Struct1& OLinkSameStruct1Interface::prop1() const
{
    return m_prop1;
}

Struct1 OLinkSameStruct1Interface::func1(const Struct1& param1)
{
    if(m_node == nullptr) {
        return Struct1();
    }
    Struct1 value(func1Async(param1).get());
    return value;
}

std::future<Struct1> OLinkSameStruct1Interface::func1Async(const Struct1& param1)
{
    if(m_node == nullptr) {
        throw std::runtime_error("Node is not initialized");
    }
    return std::async(std::launch::async, [this,
                    param1]()
        {
            std::promise<Struct1> resultPromise;
            m_node->invokeRemote("tb.same2.SameStruct1Interface/func1",
                nlohmann::json::array({param1}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const Struct1& value = arg.value.get<Struct1>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}


std::string OLinkSameStruct1Interface::olinkObjectName()
{
    return "tb.same2.SameStruct1Interface";
}

void OLinkSameStruct1Interface::olinkOnSignal(std::string name, nlohmann::json args)
{
    std::string path = ApiGear::ObjectLink::Name::pathFromName(name);
    if(path == "sig1") {
        m_publisher->publishSig1(args[0].get<Struct1>());   
        return;
    }
}

void OLinkSameStruct1Interface::olinkOnPropertyChanged(std::string name, nlohmann::json value)
{
    std::string path = ApiGear::ObjectLink::Name::pathFromName(name);
    applyState({ {path, value} });
}
void OLinkSameStruct1Interface::olinkOnInit(std::string name, nlohmann::json props, ApiGear::ObjectLink::IClientNode *node)
{
    (void) name;
    m_isReady = true;
    m_node = node;
    applyState(props);
}

void OLinkSameStruct1Interface::olinkOnRelease()
{
    m_isReady = false;
    m_node = nullptr;
}

bool OLinkSameStruct1Interface::isReady() const
{
    return m_isReady;
}

ISameStruct1InterfacePublisher* OLinkSameStruct1Interface::_getPublisher() const
{
    return m_publisher;
}
