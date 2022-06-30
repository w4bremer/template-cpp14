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



#include "tb_enum_enuminterfaceinterface.h"

#include "generated/core/tb_enum.json.adapter.h"

using namespace Test::TbEnum;

OLinkEnumInterface::OLinkEnumInterface(ApiGear::ObjectLink::ClientRegistry& registry, ApiGear::PocoImpl::OLinkClient& client)
    : m_isReady(false)
    , m_prop0(Enum0Enum::value0)
    , m_prop1(Enum1Enum::value1)
    , m_prop2(Enum2Enum::value2)
    , m_prop3(Enum3Enum::value3)
    , m_node(nullptr)
    , m_registry(&registry)
    , m_publisher(new EnumInterfacePublisher())
{
    m_node = m_registry->addObjectSink(this);
    client.linkObjectSource("tb.enum.EnumInterface");
}

OLinkEnumInterface::~OLinkEnumInterface()
{
    m_registry->removeObjectSink(this);
}

void OLinkEnumInterface::applyState(const nlohmann::json& fields) 
{
    if(fields.contains("prop0")) {
        setProp0Local(fields["prop0"].get<Enum0Enum>());
    }
    if(fields.contains("prop1")) {
        setProp1Local(fields["prop1"].get<Enum1Enum>());
    }
    if(fields.contains("prop2")) {
        setProp2Local(fields["prop2"].get<Enum2Enum>());
    }
    if(fields.contains("prop3")) {
        setProp3Local(fields["prop3"].get<Enum3Enum>());
    }
}

void OLinkEnumInterface::setProp0(const Enum0Enum& prop0)
{
    if(m_node == nullptr) {
        return;
    }
    m_node->setRemoteProperty("tb.enum.EnumInterface/prop0", prop0);
}

void OLinkEnumInterface::setProp0Local(const Enum0Enum& prop0)
{
    if (m_prop0 != prop0) {
        m_prop0 = prop0;
        m_publisher->publishProp0Changed(prop0);
    }
}

const Enum0Enum& OLinkEnumInterface::prop0() const
{
    return m_prop0;
}

void OLinkEnumInterface::setProp1(const Enum1Enum& prop1)
{
    if(m_node == nullptr) {
        return;
    }
    m_node->setRemoteProperty("tb.enum.EnumInterface/prop1", prop1);
}

void OLinkEnumInterface::setProp1Local(const Enum1Enum& prop1)
{
    if (m_prop1 != prop1) {
        m_prop1 = prop1;
        m_publisher->publishProp1Changed(prop1);
    }
}

const Enum1Enum& OLinkEnumInterface::prop1() const
{
    return m_prop1;
}

void OLinkEnumInterface::setProp2(const Enum2Enum& prop2)
{
    if(m_node == nullptr) {
        return;
    }
    m_node->setRemoteProperty("tb.enum.EnumInterface/prop2", prop2);
}

void OLinkEnumInterface::setProp2Local(const Enum2Enum& prop2)
{
    if (m_prop2 != prop2) {
        m_prop2 = prop2;
        m_publisher->publishProp2Changed(prop2);
    }
}

const Enum2Enum& OLinkEnumInterface::prop2() const
{
    return m_prop2;
}

void OLinkEnumInterface::setProp3(const Enum3Enum& prop3)
{
    if(m_node == nullptr) {
        return;
    }
    m_node->setRemoteProperty("tb.enum.EnumInterface/prop3", prop3);
}

void OLinkEnumInterface::setProp3Local(const Enum3Enum& prop3)
{
    if (m_prop3 != prop3) {
        m_prop3 = prop3;
        m_publisher->publishProp3Changed(prop3);
    }
}

const Enum3Enum& OLinkEnumInterface::prop3() const
{
    return m_prop3;
}

Enum0Enum OLinkEnumInterface::func0(const Enum0Enum& param0)
{
    if(m_node == nullptr) {
        return Enum0Enum::value0;
    }
    Enum0Enum value(func0Async(param0).get());
    return value;
}

std::future<Enum0Enum> OLinkEnumInterface::func0Async(const Enum0Enum& param0)
{
    if(m_node == nullptr) {
        throw std::runtime_error("Node is not initialized");
    }
    return std::async(std::launch::async, [this,
                    param0]()
        {
            std::promise<Enum0Enum> resultPromise;
            m_node->invokeRemote("tb.enum.EnumInterface/func0",
                nlohmann::json::array({param0}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const Enum0Enum& value = arg.value.get<Enum0Enum>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

Enum1Enum OLinkEnumInterface::func1(const Enum1Enum& param1)
{
    if(m_node == nullptr) {
        return Enum1Enum::value1;
    }
    Enum1Enum value(func1Async(param1).get());
    return value;
}

std::future<Enum1Enum> OLinkEnumInterface::func1Async(const Enum1Enum& param1)
{
    if(m_node == nullptr) {
        throw std::runtime_error("Node is not initialized");
    }
    return std::async(std::launch::async, [this,
                    param1]()
        {
            std::promise<Enum1Enum> resultPromise;
            m_node->invokeRemote("tb.enum.EnumInterface/func1",
                nlohmann::json::array({param1}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const Enum1Enum& value = arg.value.get<Enum1Enum>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

Enum2Enum OLinkEnumInterface::func2(const Enum2Enum& param2)
{
    if(m_node == nullptr) {
        return Enum2Enum::value2;
    }
    Enum2Enum value(func2Async(param2).get());
    return value;
}

std::future<Enum2Enum> OLinkEnumInterface::func2Async(const Enum2Enum& param2)
{
    if(m_node == nullptr) {
        throw std::runtime_error("Node is not initialized");
    }
    return std::async(std::launch::async, [this,
                    param2]()
        {
            std::promise<Enum2Enum> resultPromise;
            m_node->invokeRemote("tb.enum.EnumInterface/func2",
                nlohmann::json::array({param2}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const Enum2Enum& value = arg.value.get<Enum2Enum>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

Enum3Enum OLinkEnumInterface::func3(const Enum3Enum& param3)
{
    if(m_node == nullptr) {
        return Enum3Enum::value3;
    }
    Enum3Enum value(func3Async(param3).get());
    return value;
}

std::future<Enum3Enum> OLinkEnumInterface::func3Async(const Enum3Enum& param3)
{
    if(m_node == nullptr) {
        throw std::runtime_error("Node is not initialized");
    }
    return std::async(std::launch::async, [this,
                    param3]()
        {
            std::promise<Enum3Enum> resultPromise;
            m_node->invokeRemote("tb.enum.EnumInterface/func3",
                nlohmann::json::array({param3}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const Enum3Enum& value = arg.value.get<Enum3Enum>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}


std::string OLinkEnumInterface::olinkObjectName()
{
    return "tb.enum.EnumInterface";
}

void OLinkEnumInterface::olinkOnSignal(std::string name, nlohmann::json args)
{
    std::string path = ApiGear::ObjectLink::Name::pathFromName(name);
    if(path == "sig0") {
        m_publisher->publishSig0(args[0].get<Enum0Enum>());   
        return;
    }
    if(path == "sig1") {
        m_publisher->publishSig1(args[0].get<Enum1Enum>());   
        return;
    }
    if(path == "sig2") {
        m_publisher->publishSig2(args[0].get<Enum2Enum>());   
        return;
    }
    if(path == "sig3") {
        m_publisher->publishSig3(args[0].get<Enum3Enum>());   
        return;
    }
}

void OLinkEnumInterface::olinkOnPropertyChanged(std::string name, nlohmann::json value)
{
    std::string path = ApiGear::ObjectLink::Name::pathFromName(name);
    applyState({ {path, value} });
}
void OLinkEnumInterface::olinkOnInit(std::string name, nlohmann::json props, ApiGear::ObjectLink::IClientNode *node)
{
    (void) name;
    m_isReady = true;
    m_node = node;
    applyState(props);
}

void OLinkEnumInterface::olinkOnRelease()
{
    m_isReady = false;
    m_node = nullptr;
}

bool OLinkEnumInterface::isReady() const
{
    return m_isReady;
}

IEnumInterfacePublisher* OLinkEnumInterface::_getPublisher() const
{
    return m_publisher;
}
