#include "tb_same1/generated/mqtt/samestruct2interfaceservice.h"
#include "tb_same1/generated/core/tb_same1.json.adapter.h"
#include <iostream>

using namespace Test::TbSame1;
using namespace Test::TbSame1::mqtt;

SameStruct2InterfaceService::SameStruct2InterfaceService(ISameStruct2Interface& impl, std::shared_ptr<ApiGear::MQTTImpl::Client> client)
    : m_impl(impl)
    , m_client(client)
{
    m_impl._getPublisher().subscribeToAllChanges(*this);

    m_client->registerSink(*this);
    // subscribe to all property change request methods
    m_client->subscribeTopic(ApiGear::MQTTImpl::Topic("tb.same1","SameStruct2Interface",ApiGear::MQTTImpl::Topic::TopicType::Operation,"_setprop1"), this);
    m_client->subscribeTopic(ApiGear::MQTTImpl::Topic("tb.same1","SameStruct2Interface",ApiGear::MQTTImpl::Topic::TopicType::Operation,"_setprop2"), this);
    m_client->subscribeTopic(ApiGear::MQTTImpl::Topic("tb.same1","SameStruct2Interface",ApiGear::MQTTImpl::Topic::TopicType::Operation,"func1"), this);
    m_client->subscribeTopic(ApiGear::MQTTImpl::Topic("tb.same1","SameStruct2Interface",ApiGear::MQTTImpl::Topic::TopicType::Operation,"func2"), this);

}

SameStruct2InterfaceService::~SameStruct2InterfaceService()
{
    m_impl._getPublisher().unsubscribeFromAllChanges(*this);

    m_client->unregisterSink(*this);
    m_client->unsubscribeTopic(ApiGear::MQTTImpl::Topic("tb.same1","SameStruct2Interface",ApiGear::MQTTImpl::Topic::TopicType::Operation,"_setprop1"), this);
    m_client->unsubscribeTopic(ApiGear::MQTTImpl::Topic("tb.same1","SameStruct2Interface",ApiGear::MQTTImpl::Topic::TopicType::Operation,"_setprop2"), this);
    m_client->unsubscribeTopic(ApiGear::MQTTImpl::Topic("tb.same1","SameStruct2Interface",ApiGear::MQTTImpl::Topic::TopicType::Operation,"func1"), this);
    m_client->unsubscribeTopic(ApiGear::MQTTImpl::Topic("tb.same1","SameStruct2Interface",ApiGear::MQTTImpl::Topic::TopicType::Operation,"func2"), this);
}

void SameStruct2InterfaceService::onConnected()
{
    // send current values
    onProp1Changed(m_impl.getProp1());
    onProp2Changed(m_impl.getProp2());
}

void SameStruct2InterfaceService::onInvoke(const ApiGear::MQTTImpl::Topic& topic, const std::string& args, const ApiGear::MQTTImpl::Topic& responseTopic, const std::string& correlationData)
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    const std::string& name = topic.getEntityName();
    if(name == "_setprop1") {
        auto prop1 = json_args.get<Struct2>();
        m_impl.setProp1(prop1);
        return;
    }
    if(name == "_setprop2") {
        auto prop2 = json_args.get<Struct2>();
        m_impl.setProp2(prop2);
        return;
    }


    if(name == "func1") {
        const Struct1& param1 = json_args.at(0).get<Struct1>();
        auto result = m_impl.func1(param1);
        m_client->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
        return;
    }
    if(name == "func2") {
        const Struct1& param1 = json_args.at(0).get<Struct1>();
        const Struct2& param2 = json_args.at(1).get<Struct2>();
        auto result = m_impl.func2(param1, param2);
        m_client->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
        return;
    }
}
void SameStruct2InterfaceService::onSig1(const Struct1& param1)
{
    if(m_client != nullptr) {
        const nlohmann::json& args = { param1 };
        static const auto topic = ApiGear::MQTTImpl::Topic("tb.same1","SameStruct2Interface",ApiGear::MQTTImpl::Topic::TopicType::Signal,"sig1");
        m_client->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void SameStruct2InterfaceService::onSig2(const Struct1& param1, const Struct2& param2)
{
    if(m_client != nullptr) {
        const nlohmann::json& args = { param1, param2 };
        static const auto topic = ApiGear::MQTTImpl::Topic("tb.same1","SameStruct2Interface",ApiGear::MQTTImpl::Topic::TopicType::Signal,"sig2");
        m_client->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void SameStruct2InterfaceService::onProp1Changed(const Struct2& prop1)
{
    if(m_client != nullptr) {
        static const auto topic = ApiGear::MQTTImpl::Topic("tb.same1","SameStruct2Interface",ApiGear::MQTTImpl::Topic::TopicType::Property,"prop1");
        m_client->notifyPropertyChange(topic, nlohmann::json(prop1).dump());
    }
}
void SameStruct2InterfaceService::onProp2Changed(const Struct2& prop2)
{
    if(m_client != nullptr) {
        static const auto topic = ApiGear::MQTTImpl::Topic("tb.same1","SameStruct2Interface",ApiGear::MQTTImpl::Topic::TopicType::Property,"prop2");
        m_client->notifyPropertyChange(topic, nlohmann::json(prop2).dump());
    }
}
