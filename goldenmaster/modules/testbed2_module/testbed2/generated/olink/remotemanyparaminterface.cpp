

#include "testbed2/generated/olink/remotemanyparaminterface.h"
#include "testbed2/generated/core/manyparaminterface.publisher.h"
#include "testbed2/generated/core/testbed2.json.adapter.h"

#include "olink/iclientnode.h"
#include "apigear/olink/olinkconnection.h"

using namespace Test::Testbed2;
using namespace Test::Testbed2::olink;

namespace 
{
const std::string interfaceId = "testbed2.ManyParamInterface";
}

RemoteManyParamInterface::RemoteManyParamInterface(std::weak_ptr<ApiGear::PocoImpl::IOlinkConnector> olinkConnector)
    : m_olinkConnector(olinkConnector),
      m_publisher(std::make_unique<ManyParamInterfacePublisher>())
{
    if(auto connector = m_olinkConnector.lock())
    {
        connector->connectAndLinkObject(*this);
    }
}

RemoteManyParamInterface::~RemoteManyParamInterface()
{    
    if(auto connector = m_olinkConnector.lock())
    {
        connector->disconnectAndUnlink(olinkObjectName());
    }
}

void RemoteManyParamInterface::applyState(const nlohmann::json& fields) 
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

void RemoteManyParamInterface::setProp1(int prop1)
{
    if(!m_node) {
        emitLog(ApiGear::Logger::LogLevel::Warning, "Attempt to set property but " + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return;
    }
    const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "prop1");
    m_node->setRemoteProperty(propertyId, prop1);
}

void RemoteManyParamInterface::setProp1Local(int prop1)
{
    if (m_data.m_prop1 != prop1) {
        m_data.m_prop1 = prop1;
        m_publisher->publishProp1Changed(prop1);
    }
}

int RemoteManyParamInterface::getProp1() const
{
    return m_data.m_prop1;
}

void RemoteManyParamInterface::setProp2(int prop2)
{
    if(!m_node) {
        emitLog(ApiGear::Logger::LogLevel::Warning, "Attempt to set property but " + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return;
    }
    const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "prop2");
    m_node->setRemoteProperty(propertyId, prop2);
}

void RemoteManyParamInterface::setProp2Local(int prop2)
{
    if (m_data.m_prop2 != prop2) {
        m_data.m_prop2 = prop2;
        m_publisher->publishProp2Changed(prop2);
    }
}

int RemoteManyParamInterface::getProp2() const
{
    return m_data.m_prop2;
}

void RemoteManyParamInterface::setProp3(int prop3)
{
    if(!m_node) {
        emitLog(ApiGear::Logger::LogLevel::Warning, "Attempt to set property but " + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return;
    }
    const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "prop3");
    m_node->setRemoteProperty(propertyId, prop3);
}

void RemoteManyParamInterface::setProp3Local(int prop3)
{
    if (m_data.m_prop3 != prop3) {
        m_data.m_prop3 = prop3;
        m_publisher->publishProp3Changed(prop3);
    }
}

int RemoteManyParamInterface::getProp3() const
{
    return m_data.m_prop3;
}

void RemoteManyParamInterface::setProp4(int prop4)
{
    if(!m_node) {
        emitLog(ApiGear::Logger::LogLevel::Warning, "Attempt to set property but " + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return;
    }
    const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "prop4");
    m_node->setRemoteProperty(propertyId, prop4);
}

void RemoteManyParamInterface::setProp4Local(int prop4)
{
    if (m_data.m_prop4 != prop4) {
        m_data.m_prop4 = prop4;
        m_publisher->publishProp4Changed(prop4);
    }
}

int RemoteManyParamInterface::getProp4() const
{
    return m_data.m_prop4;
}

int RemoteManyParamInterface::func1(int param1)
{
     if(!m_node) {
        emitLog(ApiGear::Logger::LogLevel::Warning, "Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return 0;
    }
    int value(func1Async(param1).get());
    return value;
}

std::future<int> RemoteManyParamInterface::func1Async(int param1)
{
    if(!m_node) {
        emitLog(ApiGear::Logger::LogLevel::Warning, "Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return std::future<int>{};
    }
    return std::async(std::launch::async, [this,
                    param1]()
        {
            std::promise<int> resultPromise;
            const auto& operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "func1");
            m_node->invokeRemote(operationId,
                nlohmann::json::array({param1}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const int& value = arg.value.get<int>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

int RemoteManyParamInterface::func2(int param1, int param2)
{
     if(!m_node) {
        emitLog(ApiGear::Logger::LogLevel::Warning, "Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return 0;
    }
    int value(func2Async(param1, param2).get());
    return value;
}

std::future<int> RemoteManyParamInterface::func2Async(int param1, int param2)
{
    if(!m_node) {
        emitLog(ApiGear::Logger::LogLevel::Warning, "Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return std::future<int>{};
    }
    return std::async(std::launch::async, [this,
                    param1,
                    param2]()
        {
            std::promise<int> resultPromise;
            const auto& operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "func2");
            m_node->invokeRemote(operationId,
                nlohmann::json::array({param1,param2}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const int& value = arg.value.get<int>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

int RemoteManyParamInterface::func3(int param1, int param2, int param3)
{
     if(!m_node) {
        emitLog(ApiGear::Logger::LogLevel::Warning, "Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return 0;
    }
    int value(func3Async(param1, param2, param3).get());
    return value;
}

std::future<int> RemoteManyParamInterface::func3Async(int param1, int param2, int param3)
{
    if(!m_node) {
        emitLog(ApiGear::Logger::LogLevel::Warning, "Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return std::future<int>{};
    }
    return std::async(std::launch::async, [this,
                    param1,
                    param2,
                    param3]()
        {
            std::promise<int> resultPromise;
            const auto& operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "func3");
            m_node->invokeRemote(operationId,
                nlohmann::json::array({param1,param2,param3}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const int& value = arg.value.get<int>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

int RemoteManyParamInterface::func4(int param1, int param2, int param3, int param4)
{
     if(!m_node) {
        emitLog(ApiGear::Logger::LogLevel::Warning, "Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return 0;
    }
    int value(func4Async(param1, param2, param3, param4).get());
    return value;
}

std::future<int> RemoteManyParamInterface::func4Async(int param1, int param2, int param3, int param4)
{
    if(!m_node) {
        emitLog(ApiGear::Logger::LogLevel::Warning, "Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return std::future<int>{};
    }
    return std::async(std::launch::async, [this,
                    param1,
                    param2,
                    param3,
                    param4]()
        {
            std::promise<int> resultPromise;
            const auto& operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "func4");
            m_node->invokeRemote(operationId,
                nlohmann::json::array({param1,param2,param3,param4}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const int& value = arg.value.get<int>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

std::string RemoteManyParamInterface::olinkObjectName()
{
    return interfaceId;
}

void RemoteManyParamInterface::olinkOnSignal(const std::string& signalId, const nlohmann::json& args)
{
    const auto& signalName = ApiGear::ObjectLink::Name::getMemberName(signalId);
    if(signalName == "sig1") {
        m_publisher->publishSig1(args[0].get<int>());   
        return;
    }
    if(signalName == "sig2") {
        m_publisher->publishSig2(args[0].get<int>(),args[1].get<int>());   
        return;
    }
    if(signalName == "sig3") {
        m_publisher->publishSig3(args[0].get<int>(),args[1].get<int>(),args[2].get<int>());   
        return;
    }
    if(signalName == "sig4") {
        m_publisher->publishSig4(args[0].get<int>(),args[1].get<int>(),args[2].get<int>(),args[3].get<int>());   
        return;
    }
}

void RemoteManyParamInterface::olinkOnPropertyChanged(const std::string& propertyId, const nlohmann::json& value)
{
    applyState({ {ApiGear::ObjectLink::Name::getMemberName(propertyId), value} });
}
void RemoteManyParamInterface::olinkOnInit(const std::string& /*name*/, const nlohmann::json& props, ApiGear::ObjectLink::IClientNode *node)
{
    m_node = node;
    applyState(props);
}

void RemoteManyParamInterface::olinkOnRelease()
{
    m_node = nullptr;
}

bool RemoteManyParamInterface::isReady() const
{
    return m_node != nullptr;
}

IManyParamInterfacePublisher& RemoteManyParamInterface::_getPublisher() const
{
    return *m_publisher;
}
