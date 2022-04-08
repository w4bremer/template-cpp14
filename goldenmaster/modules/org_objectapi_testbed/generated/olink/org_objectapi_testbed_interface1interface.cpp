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



#include "org_objectapi_testbed_interface1interface.h"

#include "generated/core/org_objectapi_testbed.json.adapter.h"

using namespace Test::OrgObjectapiTestbed;

OLinkInterface1::OLinkInterface1(ApiGear::ObjectLink::ClientRegistry& registry, ApiGear::PocoImpl::OLinkClient& client)
    : m_isReady(false)
    , m_prop1(false)
    , m_prop2(0)
    , m_prop3(0.0f)
    , m_prop4(std::string())
    , m_prop5(std::list<int>())
    , m_prop6(Struct1())
    , m_prop7(0)
    , m_prop10(std::list<int>())
    , m_prop11(std::list<Struct1>())
    , m_prop12(std::list<Enum1Enum>())
    , m_prop14(std::list<Struct1>())
    , m_node(nullptr)
    , m_registry(&registry)
    , m_publisher(new Interface1Publisher())
{
    m_node = m_registry->addObjectSink(this);
    client.linkObjectSource("org.objectapi.testbed.Interface1");
}

OLinkInterface1::~OLinkInterface1()
{
    m_registry->removeObjectSink(this);
}

void OLinkInterface1::applyState(const nlohmann::json& fields) 
{
    if(fields.contains("prop1")) {
        setProp1Local(fields["prop1"].get<bool>());
    }
    if(fields.contains("prop2")) {
        setProp2Local(fields["prop2"].get<int>());
    }
    if(fields.contains("prop3")) {
        setProp3Local(fields["prop3"].get<float>());
    }
    if(fields.contains("prop4")) {
        setProp4Local(fields["prop4"].get<std::string>());
    }
    if(fields.contains("prop5")) {
        setProp5Local(fields["prop5"].get<std::list<int>>());
    }
    if(fields.contains("prop6")) {
        setProp6Local(fields["prop6"].get<Struct1>());
    }
    if(fields.contains("prop7")) {
        setProp7Local(fields["prop7"].get<int>());
    }
    if(fields.contains("prop10")) {
        setProp10Local(fields["prop10"].get<std::list<int>>());
    }
    if(fields.contains("prop11")) {
        setProp11Local(fields["prop11"].get<std::list<Struct1>>());
    }
    if(fields.contains("prop12")) {
        setProp12Local(fields["prop12"].get<std::list<Enum1Enum>>());
    }
    if(fields.contains("prop14")) {
        setProp14Local(fields["prop14"].get<std::list<Struct1>>());
    }
}

void OLinkInterface1::setProp1(bool prop1)
{
    if(m_node == nullptr) {
        return;
    }
    m_node->setRemoteProperty("org.objectapi.testbed.Interface1/prop1", prop1);
}

void OLinkInterface1::setProp1Local(bool prop1)
{
    if (m_prop1 != prop1) {
        m_prop1 = prop1;
        m_publisher->publishProp1Changed(prop1);
    }
}

bool OLinkInterface1::prop1() const
{
    return m_prop1;
}

void OLinkInterface1::setProp2(int prop2)
{
    if(m_node == nullptr) {
        return;
    }
    m_node->setRemoteProperty("org.objectapi.testbed.Interface1/prop2", prop2);
}

void OLinkInterface1::setProp2Local(int prop2)
{
    if (m_prop2 != prop2) {
        m_prop2 = prop2;
        m_publisher->publishProp2Changed(prop2);
    }
}

int OLinkInterface1::prop2() const
{
    return m_prop2;
}

void OLinkInterface1::setProp3(float prop3)
{
    if(m_node == nullptr) {
        return;
    }
    m_node->setRemoteProperty("org.objectapi.testbed.Interface1/prop3", prop3);
}

void OLinkInterface1::setProp3Local(float prop3)
{
    if (m_prop3 != prop3) {
        m_prop3 = prop3;
        m_publisher->publishProp3Changed(prop3);
    }
}

float OLinkInterface1::prop3() const
{
    return m_prop3;
}

void OLinkInterface1::setProp4(const std::string& prop4)
{
    if(m_node == nullptr) {
        return;
    }
    m_node->setRemoteProperty("org.objectapi.testbed.Interface1/prop4", prop4);
}

void OLinkInterface1::setProp4Local(const std::string& prop4)
{
    if (m_prop4 != prop4) {
        m_prop4 = prop4;
        m_publisher->publishProp4Changed(prop4);
    }
}

std::string OLinkInterface1::prop4() const
{
    return m_prop4;
}

void OLinkInterface1::setProp5(const std::list<int>& prop5)
{
    if(m_node == nullptr) {
        return;
    }
    m_node->setRemoteProperty("org.objectapi.testbed.Interface1/prop5", prop5);
}

void OLinkInterface1::setProp5Local(const std::list<int>& prop5)
{
    if (m_prop5 != prop5) {
        m_prop5 = prop5;
        m_publisher->publishProp5Changed(prop5);
    }
}

const std::list<int>& OLinkInterface1::prop5() const
{
    return m_prop5;
}

void OLinkInterface1::setProp6(const Struct1& prop6)
{
    if(m_node == nullptr) {
        return;
    }
    m_node->setRemoteProperty("org.objectapi.testbed.Interface1/prop6", prop6);
}

void OLinkInterface1::setProp6Local(const Struct1& prop6)
{
    if (m_prop6 != prop6) {
        m_prop6 = prop6;
        m_publisher->publishProp6Changed(prop6);
    }
}

const Struct1& OLinkInterface1::prop6() const
{
    return m_prop6;
}

void OLinkInterface1::setProp7(int prop7)
{
    if(m_node == nullptr) {
        return;
    }
    m_node->setRemoteProperty("org.objectapi.testbed.Interface1/prop7", prop7);
}

void OLinkInterface1::setProp7Local(int prop7)
{
    if (m_prop7 != prop7) {
        m_prop7 = prop7;
        m_publisher->publishProp7Changed(prop7);
    }
}

int OLinkInterface1::prop7() const
{
    return m_prop7;
}

void OLinkInterface1::setProp10(const std::list<int>& prop10)
{
    if(m_node == nullptr) {
        return;
    }
    m_node->setRemoteProperty("org.objectapi.testbed.Interface1/prop10", prop10);
}

void OLinkInterface1::setProp10Local(const std::list<int>& prop10)
{
    if (m_prop10 != prop10) {
        m_prop10 = prop10;
        m_publisher->publishProp10Changed(prop10);
    }
}

const std::list<int>& OLinkInterface1::prop10() const
{
    return m_prop10;
}

void OLinkInterface1::setProp11(const std::list<Struct1>& prop11)
{
    if(m_node == nullptr) {
        return;
    }
    m_node->setRemoteProperty("org.objectapi.testbed.Interface1/prop11", prop11);
}

void OLinkInterface1::setProp11Local(const std::list<Struct1>& prop11)
{
    if (m_prop11 != prop11) {
        m_prop11 = prop11;
        m_publisher->publishProp11Changed(prop11);
    }
}

const std::list<Struct1>& OLinkInterface1::prop11() const
{
    return m_prop11;
}

void OLinkInterface1::setProp12(const std::list<Enum1Enum>& prop12)
{
    if(m_node == nullptr) {
        return;
    }
    m_node->setRemoteProperty("org.objectapi.testbed.Interface1/prop12", prop12);
}

void OLinkInterface1::setProp12Local(const std::list<Enum1Enum>& prop12)
{
    if (m_prop12 != prop12) {
        m_prop12 = prop12;
        m_publisher->publishProp12Changed(prop12);
    }
}

const std::list<Enum1Enum>& OLinkInterface1::prop12() const
{
    return m_prop12;
}

void OLinkInterface1::setProp14(const std::list<Struct1>& prop14)
{
    if(m_node == nullptr) {
        return;
    }
    m_node->setRemoteProperty("org.objectapi.testbed.Interface1/prop14", prop14);
}

void OLinkInterface1::setProp14Local(const std::list<Struct1>& prop14)
{
    if (m_prop14 != prop14) {
        m_prop14 = prop14;
        m_publisher->publishProp14Changed(prop14);
    }
}

const std::list<Struct1>& OLinkInterface1::prop14() const
{
    return m_prop14;
}

void OLinkInterface1::op1()
{
    if(m_node == nullptr) {
        return ;
    }
    ApiGear::ObjectLink::InvokeReplyFunc func = [this](ApiGear::ObjectLink::InvokeReplyArg arg)
        {
            (void) this;
            (void) arg;
        };
    const nlohmann::json &args = nlohmann::json::array({
        
    });
    m_node->invokeRemote("org_objectapi_testbed.Interface1/op1", args, func);
}

std::future<void> OLinkInterface1::op1Async()
{
    if(m_node == nullptr) {
        throw std::runtime_error("Node is not initialized");
    }
    return std::async(std::launch::async, [this]()
        {
            std::promise<void> resultPromise;
            m_node->invokeRemote("org.objectapi.testbed.Interface1/op1",
                nlohmann::json::array({}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    (void) arg;
                    resultPromise.set_value();
                });
            return resultPromise.get_future().get();
        }
    );
}

void OLinkInterface1::op2(int step)
{
    if(m_node == nullptr) {
        return ;
    }
    ApiGear::ObjectLink::InvokeReplyFunc func = [this](ApiGear::ObjectLink::InvokeReplyArg arg)
        {
            (void) this;
            (void) arg;
        };
    const nlohmann::json &args = nlohmann::json::array({
        step
    });
    m_node->invokeRemote("org_objectapi_testbed.Interface1/op2", args, func);
}

std::future<void> OLinkInterface1::op2Async(int step)
{
    if(m_node == nullptr) {
        throw std::runtime_error("Node is not initialized");
    }
    return std::async(std::launch::async, [this,
                    step]()
        {
            std::promise<void> resultPromise;
            m_node->invokeRemote("org.objectapi.testbed.Interface1/op2",
                nlohmann::json::array({step}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    (void) arg;
                    resultPromise.set_value();
                });
            return resultPromise.get_future().get();
        }
    );
}

int OLinkInterface1::op3()
{
    if(m_node == nullptr) {
        return 0;
    }
    int value(op3Async().get());
    return value;
}

std::future<int> OLinkInterface1::op3Async()
{
    if(m_node == nullptr) {
        throw std::runtime_error("Node is not initialized");
    }
    return std::async(std::launch::async, [this]()
        {
            std::promise<int> resultPromise;
            m_node->invokeRemote("org.objectapi.testbed.Interface1/op3",
                nlohmann::json::array({}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const int& value = arg.value.get<int>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}


std::string OLinkInterface1::olinkObjectName()
{
    return "org.objectapi.testbed.Interface1";
}

void OLinkInterface1::olinkOnSignal(std::string name, nlohmann::json args)
{
    std::string path = ApiGear::ObjectLink::Name::pathFromName(name);
    if(path == "sig1") {
        m_publisher->publishSig1();   
        return;
    }
    if(path == "sig2") {
        m_publisher->publishSig2(args[0].get<int>());   
        return;
    }
    if(path == "sig3") {
        m_publisher->publishSig3();   
        return;
    }
}

void OLinkInterface1::olinkOnPropertyChanged(std::string name, nlohmann::json value)
{
    std::string path = ApiGear::ObjectLink::Name::pathFromName(name);
    applyState({ {path, value} });
}
void OLinkInterface1::olinkOnInit(std::string name, nlohmann::json props, ApiGear::ObjectLink::IClientNode *node)
{
    (void) name;
    m_isReady = true;
    m_node = node;
    applyState(props);
}

void OLinkInterface1::olinkOnRelease()
{
    m_isReady = false;
    m_node = nullptr;
}

bool OLinkInterface1::isReady() const
{
    return m_isReady;
}

IInterface1Publisher* OLinkInterface1::_getPublisher() const
{
    return m_publisher;
}
