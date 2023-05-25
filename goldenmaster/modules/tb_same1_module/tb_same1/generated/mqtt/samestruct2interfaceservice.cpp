#include "tb_same1/generated/mqtt/samestruct2interfaceservice.h"
#include "tb_same1/generated/core/tb_same1.json.adapter.h"
#include <iostream>

using namespace Test::TbSame1;
using namespace Test::TbSame1::MQTT;

SameStruct2InterfaceService::SameStruct2InterfaceService(std::shared_ptr<ISameStruct2Interface> impl, std::shared_ptr<ApiGear::MQTT::Service> service)
    : m_impl(impl)
    , m_service(service)
{
    m_impl->_getPublisher().subscribeToAllChanges(*this);

    m_connectionStatusRegistrationID = m_service->subscribeToConnectionStatus(std::bind(&SameStruct2InterfaceService::onConnectionStatusChanged, this, std::placeholders::_1));
    // subscribe to all property change request methods
    m_service->subscribeTopic(ApiGear::MQTT::Topic("tb.same1","SameStruct2Interface",ApiGear::MQTT::Topic::TopicType::Operation,"_setprop1"), std::bind(&SameStruct2InterfaceService::onInvoke, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_service->subscribeTopic(ApiGear::MQTT::Topic("tb.same1","SameStruct2Interface",ApiGear::MQTT::Topic::TopicType::Operation,"_setprop2"), std::bind(&SameStruct2InterfaceService::onInvoke, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_service->subscribeTopic(ApiGear::MQTT::Topic("tb.same1","SameStruct2Interface",ApiGear::MQTT::Topic::TopicType::Operation,"func1"), std::bind(&SameStruct2InterfaceService::onInvoke, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_service->subscribeTopic(ApiGear::MQTT::Topic("tb.same1","SameStruct2Interface",ApiGear::MQTT::Topic::TopicType::Operation,"func2"), std::bind(&SameStruct2InterfaceService::onInvoke, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));

}

SameStruct2InterfaceService::~SameStruct2InterfaceService()
{
    m_impl->_getPublisher().unsubscribeFromAllChanges(*this);

    m_service->unsubscribeToConnectionStatus(m_connectionStatusRegistrationID);
    m_service->unsubscribeTopic(ApiGear::MQTT::Topic("tb.same1","SameStruct2Interface",ApiGear::MQTT::Topic::TopicType::Operation,"_setprop1"), std::bind(&SameStruct2InterfaceService::onInvoke, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_service->unsubscribeTopic(ApiGear::MQTT::Topic("tb.same1","SameStruct2Interface",ApiGear::MQTT::Topic::TopicType::Operation,"_setprop2"), std::bind(&SameStruct2InterfaceService::onInvoke, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_service->unsubscribeTopic(ApiGear::MQTT::Topic("tb.same1","SameStruct2Interface",ApiGear::MQTT::Topic::TopicType::Operation,"func1"), std::bind(&SameStruct2InterfaceService::onInvoke, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_service->unsubscribeTopic(ApiGear::MQTT::Topic("tb.same1","SameStruct2Interface",ApiGear::MQTT::Topic::TopicType::Operation,"func2"), std::bind(&SameStruct2InterfaceService::onInvoke, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
}

void SameStruct2InterfaceService::onConnectionStatusChanged(bool connectionStatus)
{
    if(!connectionStatus)
    {
        return;
    }

    // send current values
    onProp1Changed(m_impl->getProp1());
    onProp2Changed(m_impl->getProp2());
}

void SameStruct2InterfaceService::onInvoke(const ApiGear::MQTT::Topic& topic, const std::string& args, const ApiGear::MQTT::Topic& responseTopic, const std::string& correlationData)
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    const std::string& name = topic.getEntityName();
    if(name == "_setprop1") {
        auto prop1 = json_args.get<Struct2>();
        m_impl->setProp1(prop1);
        return;
    }
    if(name == "_setprop2") {
        auto prop2 = json_args.get<Struct2>();
        m_impl->setProp2(prop2);
        return;
    }


    if(name == "func1") {
        const Struct1& param1 = json_args.at(0).get<Struct1>();
        auto result = m_impl->func1(param1);
        m_service->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
        return;
    }
    if(name == "func2") {
        const Struct1& param1 = json_args.at(0).get<Struct1>();
        const Struct2& param2 = json_args.at(1).get<Struct2>();
        auto result = m_impl->func2(param1, param2);
        m_service->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
        return;
    }
}
void SameStruct2InterfaceService::onSig1(const Struct1& param1)
{
    if(m_service != nullptr) {
        const nlohmann::json& args = { param1 };
        static const auto topic = ApiGear::MQTT::Topic("tb.same1","SameStruct2Interface",ApiGear::MQTT::Topic::TopicType::Signal,"sig1");
        m_service->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void SameStruct2InterfaceService::onSig2(const Struct1& param1, const Struct2& param2)
{
    if(m_service != nullptr) {
        const nlohmann::json& args = { param1, param2 };
        static const auto topic = ApiGear::MQTT::Topic("tb.same1","SameStruct2Interface",ApiGear::MQTT::Topic::TopicType::Signal,"sig2");
        m_service->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void SameStruct2InterfaceService::onProp1Changed(const Struct2& prop1)
{
    if(m_service != nullptr) {
        static const auto topic = ApiGear::MQTT::Topic("tb.same1","SameStruct2Interface",ApiGear::MQTT::Topic::TopicType::Property,"prop1");
        m_service->notifyPropertyChange(topic, nlohmann::json(prop1).dump());
    }
}
void SameStruct2InterfaceService::onProp2Changed(const Struct2& prop2)
{
    if(m_service != nullptr) {
        static const auto topic = ApiGear::MQTT::Topic("tb.same1","SameStruct2Interface",ApiGear::MQTT::Topic::TopicType::Property,"prop2");
        m_service->notifyPropertyChange(topic, nlohmann::json(prop2).dump());
    }
}
