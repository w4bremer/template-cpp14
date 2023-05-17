#include "tb_same2/generated/mqtt/sameenum2interfaceservice.h"
#include "tb_same2/generated/core/tb_same2.json.adapter.h"
#include <iostream>

using namespace Test::TbSame2;
using namespace Test::TbSame2::MQTT;

SameEnum2InterfaceService::SameEnum2InterfaceService(std::shared_ptr<ISameEnum2Interface> impl, std::shared_ptr<ApiGear::MQTT::Client> client)
    : m_impl(impl)
    , m_client(client)
{
    m_impl->_getPublisher().subscribeToAllChanges(*this);

    m_client->registerSink(*this);
    // subscribe to all property change request methods
    m_client->subscribeTopic(ApiGear::MQTT::Topic("tb.same2","SameEnum2Interface",ApiGear::MQTT::Topic::TopicType::Operation,"_setprop1"), this);
    m_client->subscribeTopic(ApiGear::MQTT::Topic("tb.same2","SameEnum2Interface",ApiGear::MQTT::Topic::TopicType::Operation,"_setprop2"), this);
    m_client->subscribeTopic(ApiGear::MQTT::Topic("tb.same2","SameEnum2Interface",ApiGear::MQTT::Topic::TopicType::Operation,"func1"), this);
    m_client->subscribeTopic(ApiGear::MQTT::Topic("tb.same2","SameEnum2Interface",ApiGear::MQTT::Topic::TopicType::Operation,"func2"), this);

}

SameEnum2InterfaceService::~SameEnum2InterfaceService()
{
    m_impl->_getPublisher().unsubscribeFromAllChanges(*this);

    m_client->unregisterSink(*this);
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("tb.same2","SameEnum2Interface",ApiGear::MQTT::Topic::TopicType::Operation,"_setprop1"), this);
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("tb.same2","SameEnum2Interface",ApiGear::MQTT::Topic::TopicType::Operation,"_setprop2"), this);
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("tb.same2","SameEnum2Interface",ApiGear::MQTT::Topic::TopicType::Operation,"func1"), this);
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("tb.same2","SameEnum2Interface",ApiGear::MQTT::Topic::TopicType::Operation,"func2"), this);
}

void SameEnum2InterfaceService::onConnected()
{
    // send current values
    onProp1Changed(m_impl->getProp1());
    onProp2Changed(m_impl->getProp2());
}

void SameEnum2InterfaceService::onInvoke(const ApiGear::MQTT::Topic& topic, const std::string& args, const ApiGear::MQTT::Topic& responseTopic, const std::string& correlationData)
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    const std::string& name = topic.getEntityName();
    if(name == "_setprop1") {
        auto prop1 = json_args.get<Enum1Enum>();
        m_impl->setProp1(prop1);
        return;
    }
    if(name == "_setprop2") {
        auto prop2 = json_args.get<Enum2Enum>();
        m_impl->setProp2(prop2);
        return;
    }


    if(name == "func1") {
        const Enum1Enum& param1 = json_args.at(0).get<Enum1Enum>();
        auto result = m_impl->func1(param1);
        m_client->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
        return;
    }
    if(name == "func2") {
        const Enum1Enum& param1 = json_args.at(0).get<Enum1Enum>();
        const Enum2Enum& param2 = json_args.at(1).get<Enum2Enum>();
        auto result = m_impl->func2(param1, param2);
        m_client->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
        return;
    }
}
void SameEnum2InterfaceService::onSig1(Enum1Enum param1)
{
    if(m_client != nullptr) {
        const nlohmann::json& args = { param1 };
        static const auto topic = ApiGear::MQTT::Topic("tb.same2","SameEnum2Interface",ApiGear::MQTT::Topic::TopicType::Signal,"sig1");
        m_client->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void SameEnum2InterfaceService::onSig2(Enum1Enum param1, Enum2Enum param2)
{
    if(m_client != nullptr) {
        const nlohmann::json& args = { param1, param2 };
        static const auto topic = ApiGear::MQTT::Topic("tb.same2","SameEnum2Interface",ApiGear::MQTT::Topic::TopicType::Signal,"sig2");
        m_client->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void SameEnum2InterfaceService::onProp1Changed(Enum1Enum prop1)
{
    if(m_client != nullptr) {
        static const auto topic = ApiGear::MQTT::Topic("tb.same2","SameEnum2Interface",ApiGear::MQTT::Topic::TopicType::Property,"prop1");
        m_client->notifyPropertyChange(topic, nlohmann::json(prop1).dump());
    }
}
void SameEnum2InterfaceService::onProp2Changed(Enum2Enum prop2)
{
    if(m_client != nullptr) {
        static const auto topic = ApiGear::MQTT::Topic("tb.same2","SameEnum2Interface",ApiGear::MQTT::Topic::TopicType::Property,"prop2");
        m_client->notifyPropertyChange(topic, nlohmann::json(prop2).dump());
    }
}
