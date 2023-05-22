#include "tb_simple/generated/mqtt/nosignalsinterfaceservice.h"
#include "tb_simple/generated/core/tb_simple.json.adapter.h"
#include <iostream>

using namespace Test::TbSimple;
using namespace Test::TbSimple::MQTT;

NoSignalsInterfaceService::NoSignalsInterfaceService(std::shared_ptr<INoSignalsInterface> impl, std::shared_ptr<ApiGear::MQTT::Client> client)
    : m_impl(impl)
    , m_client(client)
{
    m_impl->_getPublisher().subscribeToAllChanges(*this);

    m_connectionStatusRegistrationID = m_client->subscribeToConnectionStatus(std::bind(&NoSignalsInterfaceService::onConnectionStatusChanged, this, std::placeholders::_1));
    // subscribe to all property change request methods
    m_client->subscribeTopic(ApiGear::MQTT::Topic("tb.simple","NoSignalsInterface",ApiGear::MQTT::Topic::TopicType::Operation,"_setpropBool"), this);
    m_client->subscribeTopic(ApiGear::MQTT::Topic("tb.simple","NoSignalsInterface",ApiGear::MQTT::Topic::TopicType::Operation,"_setpropInt"), this);
    m_client->subscribeTopic(ApiGear::MQTT::Topic("tb.simple","NoSignalsInterface",ApiGear::MQTT::Topic::TopicType::Operation,"funcVoid"), this);
    m_client->subscribeTopic(ApiGear::MQTT::Topic("tb.simple","NoSignalsInterface",ApiGear::MQTT::Topic::TopicType::Operation,"funcBool"), this);

}

NoSignalsInterfaceService::~NoSignalsInterfaceService()
{
    m_impl->_getPublisher().unsubscribeFromAllChanges(*this);

    m_client->unsubscribeToConnectionStatus(m_connectionStatusRegistrationID);
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("tb.simple","NoSignalsInterface",ApiGear::MQTT::Topic::TopicType::Operation,"_setpropBool"), this);
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("tb.simple","NoSignalsInterface",ApiGear::MQTT::Topic::TopicType::Operation,"_setpropInt"), this);
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("tb.simple","NoSignalsInterface",ApiGear::MQTT::Topic::TopicType::Operation,"funcVoid"), this);
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("tb.simple","NoSignalsInterface",ApiGear::MQTT::Topic::TopicType::Operation,"funcBool"), this);
}

void NoSignalsInterfaceService::onConnectionStatusChanged(bool connectionStatus)
{
    if(!connectionStatus)
    {
        return;
    }

    // send current values
    onPropBoolChanged(m_impl->getPropBool());
    onPropIntChanged(m_impl->getPropInt());
}

void NoSignalsInterfaceService::onInvoke(const ApiGear::MQTT::Topic& topic, const std::string& args, const ApiGear::MQTT::Topic& responseTopic, const std::string& correlationData)
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    const std::string& name = topic.getEntityName();
    if(name == "_setpropBool") {
        auto propBool = json_args.get<bool>();
        m_impl->setPropBool(propBool);
        return;
    }
    if(name == "_setpropInt") {
        auto propInt = json_args.get<int>();
        m_impl->setPropInt(propInt);
        return;
    }


    if(name == "funcVoid") {
        m_impl->funcVoid();
        return;
    }
    if(name == "funcBool") {
        const bool& paramBool = json_args.at(0).get<bool>();
        auto result = m_impl->funcBool(paramBool);
        m_client->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
        return;
    }
}
void NoSignalsInterfaceService::onPropBoolChanged(bool propBool)
{
    if(m_client != nullptr) {
        static const auto topic = ApiGear::MQTT::Topic("tb.simple","NoSignalsInterface",ApiGear::MQTT::Topic::TopicType::Property,"propBool");
        m_client->notifyPropertyChange(topic, nlohmann::json(propBool).dump());
    }
}
void NoSignalsInterfaceService::onPropIntChanged(int propInt)
{
    if(m_client != nullptr) {
        static const auto topic = ApiGear::MQTT::Topic("tb.simple","NoSignalsInterface",ApiGear::MQTT::Topic::TopicType::Property,"propInt");
        m_client->notifyPropertyChange(topic, nlohmann::json(propInt).dump());
    }
}
