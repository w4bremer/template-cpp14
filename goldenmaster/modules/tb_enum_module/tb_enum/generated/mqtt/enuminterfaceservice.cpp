#include "tb_enum/generated/mqtt/enuminterfaceservice.h"
#include "tb_enum/generated/core/tb_enum.json.adapter.h"
#include <iostream>

using namespace Test::TbEnum;
using namespace Test::TbEnum::mqtt;

EnumInterfaceService::EnumInterfaceService(IEnumInterface& impl, std::shared_ptr<ApiGear::MQTTImpl::Client> client)
    : m_impl(impl)
    , m_client(client)
{
    m_impl._getPublisher().subscribeToAllChanges(*this);

    m_client->registerSink(*this);
    // subscribe to all property change request methods
    m_client->subscribeTopic(ApiGear::MQTTImpl::Topic("tb.enum","EnumInterface",ApiGear::MQTTImpl::Topic::TopicType::Operation,"_setprop0"), this);
    m_client->subscribeTopic(ApiGear::MQTTImpl::Topic("tb.enum","EnumInterface",ApiGear::MQTTImpl::Topic::TopicType::Operation,"_setprop1"), this);
    m_client->subscribeTopic(ApiGear::MQTTImpl::Topic("tb.enum","EnumInterface",ApiGear::MQTTImpl::Topic::TopicType::Operation,"_setprop2"), this);
    m_client->subscribeTopic(ApiGear::MQTTImpl::Topic("tb.enum","EnumInterface",ApiGear::MQTTImpl::Topic::TopicType::Operation,"_setprop3"), this);
    m_client->subscribeTopic(ApiGear::MQTTImpl::Topic("tb.enum","EnumInterface",ApiGear::MQTTImpl::Topic::TopicType::Operation,"func0"), this);
    m_client->subscribeTopic(ApiGear::MQTTImpl::Topic("tb.enum","EnumInterface",ApiGear::MQTTImpl::Topic::TopicType::Operation,"func1"), this);
    m_client->subscribeTopic(ApiGear::MQTTImpl::Topic("tb.enum","EnumInterface",ApiGear::MQTTImpl::Topic::TopicType::Operation,"func2"), this);
    m_client->subscribeTopic(ApiGear::MQTTImpl::Topic("tb.enum","EnumInterface",ApiGear::MQTTImpl::Topic::TopicType::Operation,"func3"), this);

}

EnumInterfaceService::~EnumInterfaceService()
{
    m_impl._getPublisher().unsubscribeFromAllChanges(*this);

    m_client->unregisterSink(*this);
    m_client->unsubscribeTopic(ApiGear::MQTTImpl::Topic("tb.enum","EnumInterface",ApiGear::MQTTImpl::Topic::TopicType::Operation,"_setprop0"), this);
    m_client->unsubscribeTopic(ApiGear::MQTTImpl::Topic("tb.enum","EnumInterface",ApiGear::MQTTImpl::Topic::TopicType::Operation,"_setprop1"), this);
    m_client->unsubscribeTopic(ApiGear::MQTTImpl::Topic("tb.enum","EnumInterface",ApiGear::MQTTImpl::Topic::TopicType::Operation,"_setprop2"), this);
    m_client->unsubscribeTopic(ApiGear::MQTTImpl::Topic("tb.enum","EnumInterface",ApiGear::MQTTImpl::Topic::TopicType::Operation,"_setprop3"), this);
    m_client->unsubscribeTopic(ApiGear::MQTTImpl::Topic("tb.enum","EnumInterface",ApiGear::MQTTImpl::Topic::TopicType::Operation,"func0"), this);
    m_client->unsubscribeTopic(ApiGear::MQTTImpl::Topic("tb.enum","EnumInterface",ApiGear::MQTTImpl::Topic::TopicType::Operation,"func1"), this);
    m_client->unsubscribeTopic(ApiGear::MQTTImpl::Topic("tb.enum","EnumInterface",ApiGear::MQTTImpl::Topic::TopicType::Operation,"func2"), this);
    m_client->unsubscribeTopic(ApiGear::MQTTImpl::Topic("tb.enum","EnumInterface",ApiGear::MQTTImpl::Topic::TopicType::Operation,"func3"), this);
}

void EnumInterfaceService::onConnected()
{
    // send current values
    onProp0Changed(m_impl.getProp0());
    onProp1Changed(m_impl.getProp1());
    onProp2Changed(m_impl.getProp2());
    onProp3Changed(m_impl.getProp3());
}

void EnumInterfaceService::onInvoke(const ApiGear::MQTTImpl::Topic& topic, const std::string& args, const ApiGear::MQTTImpl::Topic& responseTopic, const std::string& correlationData)
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    const std::string& name = topic.getEntityName();
    if(name == "_setprop0") {
        auto prop0 = json_args.get<Enum0Enum>();
        m_impl.setProp0(prop0);
        return;
    }
    if(name == "_setprop1") {
        auto prop1 = json_args.get<Enum1Enum>();
        m_impl.setProp1(prop1);
        return;
    }
    if(name == "_setprop2") {
        auto prop2 = json_args.get<Enum2Enum>();
        m_impl.setProp2(prop2);
        return;
    }
    if(name == "_setprop3") {
        auto prop3 = json_args.get<Enum3Enum>();
        m_impl.setProp3(prop3);
        return;
    }


    if(name == "func0") {
        const Enum0Enum& param0 = json_args.at(0).get<Enum0Enum>();
        auto result = m_impl.func0(param0);
        m_client->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
        return;
    }
    if(name == "func1") {
        const Enum1Enum& param1 = json_args.at(0).get<Enum1Enum>();
        auto result = m_impl.func1(param1);
        m_client->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
        return;
    }
    if(name == "func2") {
        const Enum2Enum& param2 = json_args.at(0).get<Enum2Enum>();
        auto result = m_impl.func2(param2);
        m_client->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
        return;
    }
    if(name == "func3") {
        const Enum3Enum& param3 = json_args.at(0).get<Enum3Enum>();
        auto result = m_impl.func3(param3);
        m_client->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
        return;
    }
}
void EnumInterfaceService::onSig0(Enum0Enum param0)
{
    if(m_client != nullptr) {
        const nlohmann::json& args = { param0 };
        static const auto topic = ApiGear::MQTTImpl::Topic("tb.enum","EnumInterface",ApiGear::MQTTImpl::Topic::TopicType::Signal,"sig0");
        m_client->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void EnumInterfaceService::onSig1(Enum1Enum param1)
{
    if(m_client != nullptr) {
        const nlohmann::json& args = { param1 };
        static const auto topic = ApiGear::MQTTImpl::Topic("tb.enum","EnumInterface",ApiGear::MQTTImpl::Topic::TopicType::Signal,"sig1");
        m_client->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void EnumInterfaceService::onSig2(Enum2Enum param2)
{
    if(m_client != nullptr) {
        const nlohmann::json& args = { param2 };
        static const auto topic = ApiGear::MQTTImpl::Topic("tb.enum","EnumInterface",ApiGear::MQTTImpl::Topic::TopicType::Signal,"sig2");
        m_client->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void EnumInterfaceService::onSig3(Enum3Enum param3)
{
    if(m_client != nullptr) {
        const nlohmann::json& args = { param3 };
        static const auto topic = ApiGear::MQTTImpl::Topic("tb.enum","EnumInterface",ApiGear::MQTTImpl::Topic::TopicType::Signal,"sig3");
        m_client->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void EnumInterfaceService::onProp0Changed(Enum0Enum prop0)
{
    if(m_client != nullptr) {
        static const auto topic = ApiGear::MQTTImpl::Topic("tb.enum","EnumInterface",ApiGear::MQTTImpl::Topic::TopicType::Property,"prop0");
        m_client->notifyPropertyChange(topic, nlohmann::json(prop0).dump());
    }
}
void EnumInterfaceService::onProp1Changed(Enum1Enum prop1)
{
    if(m_client != nullptr) {
        static const auto topic = ApiGear::MQTTImpl::Topic("tb.enum","EnumInterface",ApiGear::MQTTImpl::Topic::TopicType::Property,"prop1");
        m_client->notifyPropertyChange(topic, nlohmann::json(prop1).dump());
    }
}
void EnumInterfaceService::onProp2Changed(Enum2Enum prop2)
{
    if(m_client != nullptr) {
        static const auto topic = ApiGear::MQTTImpl::Topic("tb.enum","EnumInterface",ApiGear::MQTTImpl::Topic::TopicType::Property,"prop2");
        m_client->notifyPropertyChange(topic, nlohmann::json(prop2).dump());
    }
}
void EnumInterfaceService::onProp3Changed(Enum3Enum prop3)
{
    if(m_client != nullptr) {
        static const auto topic = ApiGear::MQTTImpl::Topic("tb.enum","EnumInterface",ApiGear::MQTTImpl::Topic::TopicType::Property,"prop3");
        m_client->notifyPropertyChange(topic, nlohmann::json(prop3).dump());
    }
}
