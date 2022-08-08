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



#include "testbed2/generated/olink/manyparaminterfaceinterface.h"

#include "testbed2/generated/core/testbed2.json.adapter.h"

using namespace Test::Testbed2;

OLinkManyParamInterface::OLinkManyParamInterface(ApiGear::ObjectLink::ClientRegistry& registry, ApiGear::PocoImpl::OLinkClient& client)
    : m_isReady(false)
    , m_prop1(0)
    , m_prop2(0)
    , m_prop3(0)
    , m_prop4(0)
    , m_node(nullptr)
    , m_registry(&registry)
    , m_publisher(new ManyParamInterfacePublisher())
{
    m_node = m_registry->addObjectSink(this);
    client.linkObjectSource("testbed2.ManyParamInterface");
}

OLinkManyParamInterface::~OLinkManyParamInterface()
{
    m_registry->removeObjectSink(this);
}

void OLinkManyParamInterface::applyState(const nlohmann::json& fields) 
{
    if(fields.contains("prop1")) {
        setProp1Local(fields["prop1"].get<int>());
    }
    if(fields.contains("prop2")) {
        setProp2Local(fields["prop2"].get<int>());
    }
    if(fields.contains("prop3")) {
        setProp3Local(fields["prop3"].get<int>());
    }
    if(fields.contains("prop4")) {
        setProp4Local(fields["prop4"].get<int>());
    }
}

void OLinkManyParamInterface::setProp1(int prop1)
{
    if(m_node == nullptr) {
        return;
    }
    m_node->setRemoteProperty("testbed2.ManyParamInterface/prop1", prop1);
}

void OLinkManyParamInterface::setProp1Local(int prop1)
{
    if (m_prop1 != prop1) {
        m_prop1 = prop1;
        m_publisher->publishProp1Changed(prop1);
    }
}

int OLinkManyParamInterface::prop1() const
{
    return m_prop1;
}

void OLinkManyParamInterface::setProp2(int prop2)
{
    if(m_node == nullptr) {
        return;
    }
    m_node->setRemoteProperty("testbed2.ManyParamInterface/prop2", prop2);
}

void OLinkManyParamInterface::setProp2Local(int prop2)
{
    if (m_prop2 != prop2) {
        m_prop2 = prop2;
        m_publisher->publishProp2Changed(prop2);
    }
}

int OLinkManyParamInterface::prop2() const
{
    return m_prop2;
}

void OLinkManyParamInterface::setProp3(int prop3)
{
    if(m_node == nullptr) {
        return;
    }
    m_node->setRemoteProperty("testbed2.ManyParamInterface/prop3", prop3);
}

void OLinkManyParamInterface::setProp3Local(int prop3)
{
    if (m_prop3 != prop3) {
        m_prop3 = prop3;
        m_publisher->publishProp3Changed(prop3);
    }
}

int OLinkManyParamInterface::prop3() const
{
    return m_prop3;
}

void OLinkManyParamInterface::setProp4(int prop4)
{
    if(m_node == nullptr) {
        return;
    }
    m_node->setRemoteProperty("testbed2.ManyParamInterface/prop4", prop4);
}

void OLinkManyParamInterface::setProp4Local(int prop4)
{
    if (m_prop4 != prop4) {
        m_prop4 = prop4;
        m_publisher->publishProp4Changed(prop4);
    }
}

int OLinkManyParamInterface::prop4() const
{
    return m_prop4;
}

int OLinkManyParamInterface::func1(int param1)
{
    if(m_node == nullptr) {
        return 0;
    }
    int value(func1Async(param1).get());
    return value;
}

std::future<int> OLinkManyParamInterface::func1Async(int param1)
{
    if(m_node == nullptr) {
        throw std::runtime_error("Node is not initialized");
    }
    return std::async(std::launch::async, [this,
                    param1]()
        {
            std::promise<int> resultPromise;
            m_node->invokeRemote("testbed2.ManyParamInterface/func1",
                nlohmann::json::array({param1}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const int& value = arg.value.get<int>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

int OLinkManyParamInterface::func2(int param1, int param2)
{
    if(m_node == nullptr) {
        return 0;
    }
    int value(func2Async(param1, param2).get());
    return value;
}

std::future<int> OLinkManyParamInterface::func2Async(int param1, int param2)
{
    if(m_node == nullptr) {
        throw std::runtime_error("Node is not initialized");
    }
    return std::async(std::launch::async, [this,
                    param1,
                    param2]()
        {
            std::promise<int> resultPromise;
            m_node->invokeRemote("testbed2.ManyParamInterface/func2",
                nlohmann::json::array({param1,param2}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const int& value = arg.value.get<int>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

int OLinkManyParamInterface::func3(int param1, int param2, int param3)
{
    if(m_node == nullptr) {
        return 0;
    }
    int value(func3Async(param1, param2, param3).get());
    return value;
}

std::future<int> OLinkManyParamInterface::func3Async(int param1, int param2, int param3)
{
    if(m_node == nullptr) {
        throw std::runtime_error("Node is not initialized");
    }
    return std::async(std::launch::async, [this,
                    param1,
                    param2,
                    param3]()
        {
            std::promise<int> resultPromise;
            m_node->invokeRemote("testbed2.ManyParamInterface/func3",
                nlohmann::json::array({param1,param2,param3}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const int& value = arg.value.get<int>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

int OLinkManyParamInterface::func4(int param1, int param2, int param3, int param4)
{
    if(m_node == nullptr) {
        return 0;
    }
    int value(func4Async(param1, param2, param3, param4).get());
    return value;
}

std::future<int> OLinkManyParamInterface::func4Async(int param1, int param2, int param3, int param4)
{
    if(m_node == nullptr) {
        throw std::runtime_error("Node is not initialized");
    }
    return std::async(std::launch::async, [this,
                    param1,
                    param2,
                    param3,
                    param4]()
        {
            std::promise<int> resultPromise;
            m_node->invokeRemote("testbed2.ManyParamInterface/func4",
                nlohmann::json::array({param1,param2,param3,param4}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const int& value = arg.value.get<int>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}


std::string OLinkManyParamInterface::olinkObjectName()
{
    return "testbed2.ManyParamInterface";
}

void OLinkManyParamInterface::olinkOnSignal(std::string name, nlohmann::json args)
{
    std::string path = ApiGear::ObjectLink::Name::pathFromName(name);
    if(path == "sig1") {
        m_publisher->publishSig1(args[0].get<int>());   
        return;
    }
    if(path == "sig2") {
        m_publisher->publishSig2(args[0].get<int>(),args[1].get<int>());   
        return;
    }
    if(path == "sig3") {
        m_publisher->publishSig3(args[0].get<int>(),args[1].get<int>(),args[2].get<int>());   
        return;
    }
    if(path == "sig4") {
        m_publisher->publishSig4(args[0].get<int>(),args[1].get<int>(),args[2].get<int>(),args[3].get<int>());   
        return;
    }
}

void OLinkManyParamInterface::olinkOnPropertyChanged(std::string name, nlohmann::json value)
{
    std::string path = ApiGear::ObjectLink::Name::pathFromName(name);
    applyState({ {path, value} });
}
void OLinkManyParamInterface::olinkOnInit(std::string name, nlohmann::json props, ApiGear::ObjectLink::IClientNode *node)
{
    (void) name;
    m_isReady = true;
    m_node = node;
    applyState(props);
}

void OLinkManyParamInterface::olinkOnRelease()
{
    m_isReady = false;
    m_node = nullptr;
}

bool OLinkManyParamInterface::isReady() const
{
    return m_isReady;
}

IManyParamInterfacePublisher* OLinkManyParamInterface::_getPublisher() const
{
    return m_publisher;
}
