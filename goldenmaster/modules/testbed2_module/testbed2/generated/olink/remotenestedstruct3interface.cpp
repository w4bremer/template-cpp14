

#include "testbed2/generated/olink/remotenestedstruct3interface.h"
#include "testbed2/generated/core/nestedstruct3interface.publisher.h"
#include "testbed2/generated/core/testbed2.json.adapter.h"

#include "olink/iclientnode.h"
#include "apigear/olink/olinkconnection.h"

using namespace Test::Testbed2;
using namespace Test::Testbed2::olink;

namespace 
{
const std::string interfaceId = "testbed2.NestedStruct3Interface";
}

RemoteNestedStruct3Interface::RemoteNestedStruct3Interface(std::weak_ptr<ApiGear::PocoImpl::IOlinkConnector> olinkConnector)
    : m_olinkConnector(olinkConnector),
      m_publisher(std::make_unique<NestedStruct3InterfacePublisher>())
{
    if(auto connector = m_olinkConnector.lock())
    {
        connector->connectAndLinkObject(*this);
    }
}

RemoteNestedStruct3Interface::~RemoteNestedStruct3Interface()
{    
    if(auto connector = m_olinkConnector.lock())
    {
        connector->disconnectAndUnlink(olinkObjectName());
    }
}

void RemoteNestedStruct3Interface::applyState(const nlohmann::json& fields) 
{
    if(fields.contains("prop1")) {
        setProp1Local(fields["prop1"].get<NestedStruct1>());
    }
    if(fields.contains("prop2")) {
        setProp2Local(fields["prop2"].get<NestedStruct2>());
    }
    if(fields.contains("prop3")) {
        setProp3Local(fields["prop3"].get<NestedStruct3>());
    }
}

void RemoteNestedStruct3Interface::setProp1(const NestedStruct1& prop1)
{
    if(!m_node) {
        emitLog(ApiGear::Logger::LogLevel::Warning, "Attempt to set property but " + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return;
    }
    const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "prop1");
    m_node->setRemoteProperty(propertyId, prop1);
}

void RemoteNestedStruct3Interface::setProp1Local(const NestedStruct1& prop1)
{
    if (m_data.m_prop1 != prop1) {
        m_data.m_prop1 = prop1;
        m_publisher->publishProp1Changed(prop1);
    }
}

const NestedStruct1& RemoteNestedStruct3Interface::getProp1() const
{
    return m_data.m_prop1;
}

void RemoteNestedStruct3Interface::setProp2(const NestedStruct2& prop2)
{
    if(!m_node) {
        emitLog(ApiGear::Logger::LogLevel::Warning, "Attempt to set property but " + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return;
    }
    const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "prop2");
    m_node->setRemoteProperty(propertyId, prop2);
}

void RemoteNestedStruct3Interface::setProp2Local(const NestedStruct2& prop2)
{
    if (m_data.m_prop2 != prop2) {
        m_data.m_prop2 = prop2;
        m_publisher->publishProp2Changed(prop2);
    }
}

const NestedStruct2& RemoteNestedStruct3Interface::getProp2() const
{
    return m_data.m_prop2;
}

void RemoteNestedStruct3Interface::setProp3(const NestedStruct3& prop3)
{
    if(!m_node) {
        emitLog(ApiGear::Logger::LogLevel::Warning, "Attempt to set property but " + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return;
    }
    const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "prop3");
    m_node->setRemoteProperty(propertyId, prop3);
}

void RemoteNestedStruct3Interface::setProp3Local(const NestedStruct3& prop3)
{
    if (m_data.m_prop3 != prop3) {
        m_data.m_prop3 = prop3;
        m_publisher->publishProp3Changed(prop3);
    }
}

const NestedStruct3& RemoteNestedStruct3Interface::getProp3() const
{
    return m_data.m_prop3;
}

NestedStruct1 RemoteNestedStruct3Interface::func1(const NestedStruct1& param1)
{
     if(!m_node) {
        emitLog(ApiGear::Logger::LogLevel::Warning, "Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return NestedStruct1();
    }
    NestedStruct1 value(func1Async(param1).get());
    return value;
}

std::future<NestedStruct1> RemoteNestedStruct3Interface::func1Async(const NestedStruct1& param1)
{
    if(!m_node) {
        emitLog(ApiGear::Logger::LogLevel::Warning, "Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return std::future<NestedStruct1>{};
    }
    return std::async(std::launch::async, [this,
                    param1]()
        {
            std::promise<NestedStruct1> resultPromise;
            const auto& operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "func1");
            m_node->invokeRemote(operationId,
                nlohmann::json::array({param1}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const NestedStruct1& value = arg.value.get<NestedStruct1>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

NestedStruct1 RemoteNestedStruct3Interface::func2(const NestedStruct1& param1, const NestedStruct2& param2)
{
     if(!m_node) {
        emitLog(ApiGear::Logger::LogLevel::Warning, "Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return NestedStruct1();
    }
    NestedStruct1 value(func2Async(param1, param2).get());
    return value;
}

std::future<NestedStruct1> RemoteNestedStruct3Interface::func2Async(const NestedStruct1& param1, const NestedStruct2& param2)
{
    if(!m_node) {
        emitLog(ApiGear::Logger::LogLevel::Warning, "Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return std::future<NestedStruct1>{};
    }
    return std::async(std::launch::async, [this,
                    param1,
                    param2]()
        {
            std::promise<NestedStruct1> resultPromise;
            const auto& operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "func2");
            m_node->invokeRemote(operationId,
                nlohmann::json::array({param1,param2}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const NestedStruct1& value = arg.value.get<NestedStruct1>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

NestedStruct1 RemoteNestedStruct3Interface::func3(const NestedStruct1& param1, const NestedStruct2& param2, const NestedStruct3& param3)
{
     if(!m_node) {
        emitLog(ApiGear::Logger::LogLevel::Warning, "Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return NestedStruct1();
    }
    NestedStruct1 value(func3Async(param1, param2, param3).get());
    return value;
}

std::future<NestedStruct1> RemoteNestedStruct3Interface::func3Async(const NestedStruct1& param1, const NestedStruct2& param2, const NestedStruct3& param3)
{
    if(!m_node) {
        emitLog(ApiGear::Logger::LogLevel::Warning, "Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return std::future<NestedStruct1>{};
    }
    return std::async(std::launch::async, [this,
                    param1,
                    param2,
                    param3]()
        {
            std::promise<NestedStruct1> resultPromise;
            const auto& operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "func3");
            m_node->invokeRemote(operationId,
                nlohmann::json::array({param1,param2,param3}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const NestedStruct1& value = arg.value.get<NestedStruct1>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

std::string RemoteNestedStruct3Interface::olinkObjectName()
{
    return interfaceId;
}

void RemoteNestedStruct3Interface::olinkOnSignal(const std::string& signalId, const nlohmann::json& args)
{
    const auto& signalName = ApiGear::ObjectLink::Name::getMemberName(signalId);
    if(signalName == "sig1") {
        m_publisher->publishSig1(args[0].get<NestedStruct1>());   
        return;
    }
    if(signalName == "sig2") {
        m_publisher->publishSig2(args[0].get<NestedStruct1>(),args[1].get<NestedStruct2>());   
        return;
    }
    if(signalName == "sig3") {
        m_publisher->publishSig3(args[0].get<NestedStruct1>(),args[1].get<NestedStruct2>(),args[2].get<NestedStruct3>());   
        return;
    }
}

void RemoteNestedStruct3Interface::olinkOnPropertyChanged(const std::string& propertyId, const nlohmann::json& value)
{
    applyState({ {ApiGear::ObjectLink::Name::getMemberName(propertyId), value} });
}
void RemoteNestedStruct3Interface::olinkOnInit(const std::string& /*name*/, const nlohmann::json& props, ApiGear::ObjectLink::IClientNode *node)
{
    m_node = node;
    applyState(props);
}

void RemoteNestedStruct3Interface::olinkOnRelease()
{
    m_node = nullptr;
}

bool RemoteNestedStruct3Interface::isReady() const
{
    return m_node != nullptr;
}

INestedStruct3InterfacePublisher& RemoteNestedStruct3Interface::_getPublisher() const
{
    return *m_publisher;
}
