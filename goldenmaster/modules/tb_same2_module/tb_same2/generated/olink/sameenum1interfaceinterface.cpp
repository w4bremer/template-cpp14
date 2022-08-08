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



#include "tb_same2/generated/olink/sameenum1interfaceinterface.h"

#include "tb_same2/generated/core/tb_same2.json.adapter.h"

using namespace Test::TbSame2;

OLinkSameEnum1Interface::OLinkSameEnum1Interface(ApiGear::ObjectLink::ClientRegistry& registry, ApiGear::PocoImpl::OLinkClient& client)
    : m_isReady(false)
    , m_prop1(Enum1Enum::value1)
    , m_node(nullptr)
    , m_registry(&registry)
    , m_publisher(new SameEnum1InterfacePublisher())
{
    m_node = m_registry->addObjectSink(this);
    client.linkObjectSource("tb.same2.SameEnum1Interface");
}

OLinkSameEnum1Interface::~OLinkSameEnum1Interface()
{
    m_registry->removeObjectSink(this);
}

void OLinkSameEnum1Interface::applyState(const nlohmann::json& fields) 
{
    if(fields.contains("prop1")) {
        setProp1Local(fields["prop1"].get<Enum1Enum>());
    }
}

void OLinkSameEnum1Interface::setProp1(const Enum1Enum& prop1)
{
    if(m_node == nullptr) {
        return;
    }
    m_node->setRemoteProperty("tb.same2.SameEnum1Interface/prop1", prop1);
}

void OLinkSameEnum1Interface::setProp1Local(const Enum1Enum& prop1)
{
    if (m_prop1 != prop1) {
        m_prop1 = prop1;
        m_publisher->publishProp1Changed(prop1);
    }
}

const Enum1Enum& OLinkSameEnum1Interface::prop1() const
{
    return m_prop1;
}

Enum1Enum OLinkSameEnum1Interface::func1(const Enum1Enum& param1)
{
    if(m_node == nullptr) {
        return Enum1Enum::value1;
    }
    Enum1Enum value(func1Async(param1).get());
    return value;
}

std::future<Enum1Enum> OLinkSameEnum1Interface::func1Async(const Enum1Enum& param1)
{
    if(m_node == nullptr) {
        throw std::runtime_error("Node is not initialized");
    }
    return std::async(std::launch::async, [this,
                    param1]()
        {
            std::promise<Enum1Enum> resultPromise;
            m_node->invokeRemote("tb.same2.SameEnum1Interface/func1",
                nlohmann::json::array({param1}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const Enum1Enum& value = arg.value.get<Enum1Enum>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}


std::string OLinkSameEnum1Interface::olinkObjectName()
{
    return "tb.same2.SameEnum1Interface";
}

void OLinkSameEnum1Interface::olinkOnSignal(std::string name, nlohmann::json args)
{
    std::string path = ApiGear::ObjectLink::Name::pathFromName(name);
    if(path == "sig1") {
        m_publisher->publishSig1(args[0].get<Enum1Enum>());   
        return;
    }
}

void OLinkSameEnum1Interface::olinkOnPropertyChanged(std::string name, nlohmann::json value)
{
    std::string path = ApiGear::ObjectLink::Name::pathFromName(name);
    applyState({ {path, value} });
}
void OLinkSameEnum1Interface::olinkOnInit(std::string name, nlohmann::json props, ApiGear::ObjectLink::IClientNode *node)
{
    (void) name;
    m_isReady = true;
    m_node = node;
    applyState(props);
}

void OLinkSameEnum1Interface::olinkOnRelease()
{
    m_isReady = false;
    m_node = nullptr;
}

bool OLinkSameEnum1Interface::isReady() const
{
    return m_isReady;
}

ISameEnum1InterfacePublisher* OLinkSameEnum1Interface::_getPublisher() const
{
    return m_publisher;
}
