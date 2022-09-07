#include "tb_simple/generated/mqtt/nopropertiesinterfaceservice.h"
#include "tb_simple/generated/core/tb_simple.json.adapter.h"
#include <iostream>

using namespace Test::TbSimple;
using namespace Test::TbSimple::mqtt;

NoPropertiesInterfaceService::NoPropertiesInterfaceService(INoPropertiesInterface& impl, std::shared_ptr<ApiGear::MQTTImpl::Client> client)
    : m_impl(impl)
    , m_client(client)
{
    m_impl._getPublisher().subscribeToAllChanges(*this);

    m_client->registerSink(*this);
    // subscribe to all property change request methods
    m_client->subscribeTopic(ApiGear::MQTTImpl::Topic("tb.simple","NoPropertiesInterface",ApiGear::MQTTImpl::Topic::TopicType::Operation,"funcVoid"), this);
    m_client->subscribeTopic(ApiGear::MQTTImpl::Topic("tb.simple","NoPropertiesInterface",ApiGear::MQTTImpl::Topic::TopicType::Operation,"funcBool"), this);

}

NoPropertiesInterfaceService::~NoPropertiesInterfaceService()
{
    m_impl._getPublisher().unsubscribeFromAllChanges(*this);

    m_client->unregisterSink(*this);
    m_client->unsubscribeTopic(ApiGear::MQTTImpl::Topic("tb.simple","NoPropertiesInterface",ApiGear::MQTTImpl::Topic::TopicType::Operation,"funcVoid"), this);
    m_client->unsubscribeTopic(ApiGear::MQTTImpl::Topic("tb.simple","NoPropertiesInterface",ApiGear::MQTTImpl::Topic::TopicType::Operation,"funcBool"), this);
}

void NoPropertiesInterfaceService::onConnected()
{
    // send current values
}

void NoPropertiesInterfaceService::onInvoke(const ApiGear::MQTTImpl::Topic& topic, const std::string& args, const ApiGear::MQTTImpl::Topic& responseTopic, const std::string& correlationData)
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    const std::string& name = topic.getEntityName();


    if(name == "funcVoid") {
        m_impl.funcVoid();
        return;
    }
    if(name == "funcBool") {
        const bool& paramBool = json_args.at(0).get<bool>();
        auto result = m_impl.funcBool(paramBool);
        m_client->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
        return;
    }
}
void NoPropertiesInterfaceService::onSigVoid()
{
    if(m_client != nullptr) {
        const nlohmann::json& args = {  };
        static const auto topic = ApiGear::MQTTImpl::Topic("tb.simple","NoPropertiesInterface",ApiGear::MQTTImpl::Topic::TopicType::Signal,"sigVoid");
        m_client->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void NoPropertiesInterfaceService::onSigBool(bool paramBool)
{
    if(m_client != nullptr) {
        const nlohmann::json& args = { paramBool };
        static const auto topic = ApiGear::MQTTImpl::Topic("tb.simple","NoPropertiesInterface",ApiGear::MQTTImpl::Topic::TopicType::Signal,"sigBool");
        m_client->notifySignal(topic, nlohmann::json(args).dump());
    }
}
