

#include "tb_enum/generated/olink/enuminterfaceclient.h"
#include "tb_enum/generated/core/enuminterface.publisher.h"
#include "tb_enum/generated/core/tb_enum.json.adapter.h"

#include "olink/iclientnode.h"
#include "apigear/olink/olinkconnection.h"
#include "apigear/olink/logger/logger.h"

using namespace Test::TbEnum;
using namespace Test::TbEnum::olink;

namespace 
{
const std::string interfaceId = "tb.enum.EnumInterface";
}

EnumInterfaceClient::EnumInterfaceClient()
    : m_publisher(std::make_unique<EnumInterfacePublisher>())
    , m_logger(std::make_unique<ApiGear::Logger::Logger>())
{}

void EnumInterfaceClient::applyState(const nlohmann::json& fields) 
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

void EnumInterfaceClient::setProp0(Enum0Enum prop0)
{
    if(!m_node) {
        m_logger->emitLog(ApiGear::Logger::LogLevel::Warning, "Attempt to set property but " + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return;
    }
    const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "prop0");
    m_node->setRemoteProperty(propertyId, prop0);
}

void EnumInterfaceClient::setProp0Local(Enum0Enum prop0)
{
    if (m_data.m_prop0 != prop0) {
        m_data.m_prop0 = prop0;
        m_publisher->publishProp0Changed(prop0);
    }
}

Enum0Enum EnumInterfaceClient::getProp0() const
{
    return m_data.m_prop0;
}

void EnumInterfaceClient::setProp1(Enum1Enum prop1)
{
    if(!m_node) {
        m_logger->emitLog(ApiGear::Logger::LogLevel::Warning, "Attempt to set property but " + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return;
    }
    const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "prop1");
    m_node->setRemoteProperty(propertyId, prop1);
}

void EnumInterfaceClient::setProp1Local(Enum1Enum prop1)
{
    if (m_data.m_prop1 != prop1) {
        m_data.m_prop1 = prop1;
        m_publisher->publishProp1Changed(prop1);
    }
}

Enum1Enum EnumInterfaceClient::getProp1() const
{
    return m_data.m_prop1;
}

void EnumInterfaceClient::setProp2(Enum2Enum prop2)
{
    if(!m_node) {
        m_logger->emitLog(ApiGear::Logger::LogLevel::Warning, "Attempt to set property but " + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return;
    }
    const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "prop2");
    m_node->setRemoteProperty(propertyId, prop2);
}

void EnumInterfaceClient::setProp2Local(Enum2Enum prop2)
{
    if (m_data.m_prop2 != prop2) {
        m_data.m_prop2 = prop2;
        m_publisher->publishProp2Changed(prop2);
    }
}

Enum2Enum EnumInterfaceClient::getProp2() const
{
    return m_data.m_prop2;
}

void EnumInterfaceClient::setProp3(Enum3Enum prop3)
{
    if(!m_node) {
        m_logger->emitLog(ApiGear::Logger::LogLevel::Warning, "Attempt to set property but " + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return;
    }
    const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "prop3");
    m_node->setRemoteProperty(propertyId, prop3);
}

void EnumInterfaceClient::setProp3Local(Enum3Enum prop3)
{
    if (m_data.m_prop3 != prop3) {
        m_data.m_prop3 = prop3;
        m_publisher->publishProp3Changed(prop3);
    }
}

Enum3Enum EnumInterfaceClient::getProp3() const
{
    return m_data.m_prop3;
}

Enum0Enum EnumInterfaceClient::func0(Enum0Enum param0)
{
     if(!m_node) {
        m_logger->emitLog(ApiGear::Logger::LogLevel::Warning, "Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return Enum0Enum::value0;
    }
    Enum0Enum value(func0Async(param0).get());
    return value;
}

std::future<Enum0Enum> EnumInterfaceClient::func0Async(Enum0Enum param0)
{
    if(!m_node) {
        m_logger->emitLog(ApiGear::Logger::LogLevel::Warning, "Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return std::future<Enum0Enum>{};
    }
    return std::async(std::launch::async, [this,
                    param0]()
        {
            std::promise<Enum0Enum> resultPromise;
            const auto& operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "func0");
            m_node->invokeRemote(operationId,
                nlohmann::json::array({param0}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const Enum0Enum& value = arg.value.get<Enum0Enum>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

Enum1Enum EnumInterfaceClient::func1(Enum1Enum param1)
{
     if(!m_node) {
        m_logger->emitLog(ApiGear::Logger::LogLevel::Warning, "Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return Enum1Enum::value1;
    }
    Enum1Enum value(func1Async(param1).get());
    return value;
}

std::future<Enum1Enum> EnumInterfaceClient::func1Async(Enum1Enum param1)
{
    if(!m_node) {
        m_logger->emitLog(ApiGear::Logger::LogLevel::Warning, "Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return std::future<Enum1Enum>{};
    }
    return std::async(std::launch::async, [this,
                    param1]()
        {
            std::promise<Enum1Enum> resultPromise;
            const auto& operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "func1");
            m_node->invokeRemote(operationId,
                nlohmann::json::array({param1}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const Enum1Enum& value = arg.value.get<Enum1Enum>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

Enum2Enum EnumInterfaceClient::func2(Enum2Enum param2)
{
     if(!m_node) {
        m_logger->emitLog(ApiGear::Logger::LogLevel::Warning, "Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return Enum2Enum::value2;
    }
    Enum2Enum value(func2Async(param2).get());
    return value;
}

std::future<Enum2Enum> EnumInterfaceClient::func2Async(Enum2Enum param2)
{
    if(!m_node) {
        m_logger->emitLog(ApiGear::Logger::LogLevel::Warning, "Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return std::future<Enum2Enum>{};
    }
    return std::async(std::launch::async, [this,
                    param2]()
        {
            std::promise<Enum2Enum> resultPromise;
            const auto& operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "func2");
            m_node->invokeRemote(operationId,
                nlohmann::json::array({param2}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const Enum2Enum& value = arg.value.get<Enum2Enum>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

Enum3Enum EnumInterfaceClient::func3(Enum3Enum param3)
{
     if(!m_node) {
        m_logger->emitLog(ApiGear::Logger::LogLevel::Warning, "Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return Enum3Enum::value3;
    }
    Enum3Enum value(func3Async(param3).get());
    return value;
}

std::future<Enum3Enum> EnumInterfaceClient::func3Async(Enum3Enum param3)
{
    if(!m_node) {
        m_logger->emitLog(ApiGear::Logger::LogLevel::Warning, "Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return std::future<Enum3Enum>{};
    }
    return std::async(std::launch::async, [this,
                    param3]()
        {
            std::promise<Enum3Enum> resultPromise;
            const auto& operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "func3");
            m_node->invokeRemote(operationId,
                nlohmann::json::array({param3}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const Enum3Enum& value = arg.value.get<Enum3Enum>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

std::string EnumInterfaceClient::olinkObjectName()
{
    return interfaceId;
}

void EnumInterfaceClient::olinkOnSignal(const std::string& signalId, const nlohmann::json& args)
{
    const auto& signalName = ApiGear::ObjectLink::Name::getMemberName(signalId);
    if(signalName == "sig0") {
        m_publisher->publishSig0(args[0].get<Enum0Enum>());   
        return;
    }
    if(signalName == "sig1") {
        m_publisher->publishSig1(args[0].get<Enum1Enum>());   
        return;
    }
    if(signalName == "sig2") {
        m_publisher->publishSig2(args[0].get<Enum2Enum>());   
        return;
    }
    if(signalName == "sig3") {
        m_publisher->publishSig3(args[0].get<Enum3Enum>());   
        return;
    }
}

void EnumInterfaceClient::olinkOnPropertyChanged(const std::string& propertyId, const nlohmann::json& value)
{
    applyState({ {ApiGear::ObjectLink::Name::getMemberName(propertyId), value} });
}
void EnumInterfaceClient::olinkOnInit(const std::string& /*name*/, const nlohmann::json& props, ApiGear::ObjectLink::IClientNode *node)
{
    m_node = node;
    applyState(props);
}

void EnumInterfaceClient::olinkOnRelease()
{
    m_node = nullptr;
}

bool EnumInterfaceClient::isReady() const
{
    return m_node != nullptr;
}

IEnumInterfacePublisher& EnumInterfaceClient::_getPublisher() const
{
    return *m_publisher;
}
