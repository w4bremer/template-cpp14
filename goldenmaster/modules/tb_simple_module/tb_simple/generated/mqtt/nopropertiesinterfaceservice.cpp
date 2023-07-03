#include "tb_simple/generated/mqtt/nopropertiesinterfaceservice.h"
#include "tb_simple/generated/core/tb_simple.json.adapter.h"
#include <iostream>

using namespace Test::TbSimple;
using namespace Test::TbSimple::MQTT;

NoPropertiesInterfaceService::NoPropertiesInterfaceService(std::shared_ptr<INoPropertiesInterface> impl, std::shared_ptr<ApiGear::MQTT::Service> service)
    : m_impl(impl)
    , m_service(service)
{
    m_impl->_getPublisher().subscribeToAllChanges(*this);

    m_connectionStatusRegistrationID = m_service->subscribeToConnectionStatus(std::bind(&NoPropertiesInterfaceService::onConnectionStatusChanged, this, std::placeholders::_1));
    // subscribe to all property change request methods
    m_service->subscribeTopic(ApiGear::MQTT::Topic("tb.simple","NoPropertiesInterface",ApiGear::MQTT::Topic::TopicType::Operation,"funcVoid"), std::bind(&NoPropertiesInterfaceService::onInvoke, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_service->subscribeTopic(ApiGear::MQTT::Topic("tb.simple","NoPropertiesInterface",ApiGear::MQTT::Topic::TopicType::Operation,"funcBool"), std::bind(&NoPropertiesInterfaceService::onInvoke, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));

}

NoPropertiesInterfaceService::~NoPropertiesInterfaceService()
{
    m_impl->_getPublisher().unsubscribeFromAllChanges(*this);

    m_service->unsubscribeToConnectionStatus(m_connectionStatusRegistrationID);
    m_service->unsubscribeTopic(ApiGear::MQTT::Topic("tb.simple","NoPropertiesInterface",ApiGear::MQTT::Topic::TopicType::Operation,"funcVoid"), std::bind(&NoPropertiesInterfaceService::onInvoke, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_service->unsubscribeTopic(ApiGear::MQTT::Topic("tb.simple","NoPropertiesInterface",ApiGear::MQTT::Topic::TopicType::Operation,"funcBool"), std::bind(&NoPropertiesInterfaceService::onInvoke, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
}

void NoPropertiesInterfaceService::onConnectionStatusChanged(bool connectionStatus)
{
    if(!connectionStatus)
    {
        return;
    }

    // send current values
}

void NoPropertiesInterfaceService::onInvoke(const ApiGear::MQTT::Topic& topic, const std::string& args, const ApiGear::MQTT::Topic& responseTopic, const std::string& correlationData)
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    const std::string& name = topic.getEntityName();


    if(name == "funcVoid") {
        m_impl->funcVoid();
        return;
    }
    if(name == "funcBool") {
        const bool& paramBool = json_args.at(0).get<bool>();
        auto result = m_impl->funcBool(paramBool);
        m_service->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
        return;
    }
}
void NoPropertiesInterfaceService::onSigVoid()
{
    if(m_service != nullptr) {
        const nlohmann::json& args = {  };
        static const auto topic = ApiGear::MQTT::Topic("tb.simple","NoPropertiesInterface",ApiGear::MQTT::Topic::TopicType::Signal,"sigVoid");
        m_service->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void NoPropertiesInterfaceService::onSigBool(bool paramBool)
{
    if(m_service != nullptr) {
        const nlohmann::json& args = { paramBool };
        static const auto topic = ApiGear::MQTT::Topic("tb.simple","NoPropertiesInterface",ApiGear::MQTT::Topic::TopicType::Signal,"sigBool");
        m_service->notifySignal(topic, nlohmann::json(args).dump());
    }
}
