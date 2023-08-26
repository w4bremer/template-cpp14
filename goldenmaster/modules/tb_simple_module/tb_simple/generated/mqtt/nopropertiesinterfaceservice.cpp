#include "tb_simple/generated/mqtt/nopropertiesinterfaceservice.h"
#include "tb_simple/generated/core/tb_simple.json.adapter.h"
#include <iostream>

using namespace Test::TbSimple;
using namespace Test::TbSimple::MQTT;

namespace {
    std::map<std::string, ApiGear::MQTT::CallbackFunction> createTopicMap(NoPropertiesInterfaceService* service)
    {
        return {
            {std::string("tb.simple/NoPropertiesInterface/rpc/funcVoid"), [service](const std::string& args, const std::string& responseTopic, const std::string& correlationData) { service->onInvokeFuncVoid(args, responseTopic, correlationData); } },
            {std::string("tb.simple/NoPropertiesInterface/rpc/funcBool"), [service](const std::string& args, const std::string& responseTopic, const std::string& correlationData) { service->onInvokeFuncBool(args, responseTopic, correlationData); } },
        };
    };
}

NoPropertiesInterfaceService::NoPropertiesInterfaceService(std::shared_ptr<INoPropertiesInterface> impl, std::shared_ptr<ApiGear::MQTT::Service> service)
    : m_impl(impl)
    , m_service(service)
    , m_topics(createTopicMap(this))
{
    m_impl->_getPublisher().subscribeToAllChanges(*this);

    m_connectionStatusRegistrationID = m_service->subscribeToConnectionStatus([this](bool connectionStatus){ onConnectionStatusChanged(connectionStatus); });

    for (const auto& topic: m_topics)
    {
        m_service->subscribeTopic(topic. first, topic.second);
    }
}

NoPropertiesInterfaceService::~NoPropertiesInterfaceService()
{
    m_impl->_getPublisher().unsubscribeFromAllChanges(*this);

    m_service->unsubscribeToConnectionStatus(m_connectionStatusRegistrationID);

    for (const auto& topic: m_topics)
    {
        m_service->unsubscribeTopic(topic. first);
    }
}

void NoPropertiesInterfaceService::onConnectionStatusChanged(bool connectionStatus)
{
    if(!connectionStatus)
    {
        return;
    }

    // send current values
}
void NoPropertiesInterfaceService::onInvokeFuncVoid(const std::string& args, const std::string& responseTopic, const std::string& correlationData) const
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    (void) responseTopic;
    (void) correlationData;
    m_impl->funcVoid();
}
void NoPropertiesInterfaceService::onInvokeFuncBool(const std::string& args, const std::string& responseTopic, const std::string& correlationData) const
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    const bool& paramBool = json_args.at(0).get<bool>();
    auto result = m_impl->funcBool(paramBool);
    m_service->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
}
void NoPropertiesInterfaceService::onSigVoid()
{
    if(m_service != nullptr) {
        const nlohmann::json& args = {  };
        static const auto topic = std::string("tb.simple/NoPropertiesInterface/sig/sigVoid");
        m_service->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void NoPropertiesInterfaceService::onSigBool(bool paramBool)
{
    if(m_service != nullptr) {
        const nlohmann::json& args = { paramBool };
        static const auto topic = std::string("tb.simple/NoPropertiesInterface/sig/sigBool");
        m_service->notifySignal(topic, nlohmann::json(args).dump());
    }
}
