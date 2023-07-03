#include "tb_same2/generated/mqtt/samestruct1interfaceservice.h"
#include "tb_same2/generated/core/tb_same2.json.adapter.h"
#include <iostream>

using namespace Test::TbSame2;
using namespace Test::TbSame2::MQTT;

SameStruct1InterfaceService::SameStruct1InterfaceService(std::shared_ptr<ISameStruct1Interface> impl, std::shared_ptr<ApiGear::MQTT::Service> service)
    : m_impl(impl)
    , m_service(service)
{
    m_impl->_getPublisher().subscribeToAllChanges(*this);

    m_connectionStatusRegistrationID = m_service->subscribeToConnectionStatus(std::bind(&SameStruct1InterfaceService::onConnectionStatusChanged, this, std::placeholders::_1));
    // subscribe to all property change request methods
    m_service->subscribeTopic(ApiGear::MQTT::Topic("tb.same2","SameStruct1Interface",ApiGear::MQTT::Topic::TopicType::Operation,"_setprop1"), std::bind(&SameStruct1InterfaceService::onInvoke, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_service->subscribeTopic(ApiGear::MQTT::Topic("tb.same2","SameStruct1Interface",ApiGear::MQTT::Topic::TopicType::Operation,"func1"), std::bind(&SameStruct1InterfaceService::onInvoke, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));

}

SameStruct1InterfaceService::~SameStruct1InterfaceService()
{
    m_impl->_getPublisher().unsubscribeFromAllChanges(*this);

    m_service->unsubscribeToConnectionStatus(m_connectionStatusRegistrationID);
    m_service->unsubscribeTopic(ApiGear::MQTT::Topic("tb.same2","SameStruct1Interface",ApiGear::MQTT::Topic::TopicType::Operation,"_setprop1"), std::bind(&SameStruct1InterfaceService::onInvoke, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_service->unsubscribeTopic(ApiGear::MQTT::Topic("tb.same2","SameStruct1Interface",ApiGear::MQTT::Topic::TopicType::Operation,"func1"), std::bind(&SameStruct1InterfaceService::onInvoke, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
}

void SameStruct1InterfaceService::onConnectionStatusChanged(bool connectionStatus)
{
    if(!connectionStatus)
    {
        return;
    }

    // send current values
    onProp1Changed(m_impl->getProp1());
}

void SameStruct1InterfaceService::onInvoke(const ApiGear::MQTT::Topic& topic, const std::string& args, const ApiGear::MQTT::Topic& responseTopic, const std::string& correlationData)
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    const std::string& name = topic.getEntityName();
    if(name == "_setprop1") {
        auto prop1 = json_args.get<Struct1>();
        m_impl->setProp1(prop1);
        return;
    }


    if(name == "func1") {
        const Struct1& param1 = json_args.at(0).get<Struct1>();
        auto result = m_impl->func1(param1);
        m_service->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
        return;
    }
}
void SameStruct1InterfaceService::onSig1(const Struct1& param1)
{
    if(m_service != nullptr) {
        const nlohmann::json& args = { param1 };
        static const auto topic = ApiGear::MQTT::Topic("tb.same2","SameStruct1Interface",ApiGear::MQTT::Topic::TopicType::Signal,"sig1");
        m_service->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void SameStruct1InterfaceService::onProp1Changed(const Struct1& prop1)
{
    if(m_service != nullptr) {
        static const auto topic = ApiGear::MQTT::Topic("tb.same2","SameStruct1Interface",ApiGear::MQTT::Topic::TopicType::Property,"prop1");
        m_service->notifyPropertyChange(topic, nlohmann::json(prop1).dump());
    }
}