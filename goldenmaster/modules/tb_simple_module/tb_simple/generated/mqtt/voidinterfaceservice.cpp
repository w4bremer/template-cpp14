#include "tb_simple/generated/mqtt/voidinterfaceservice.h"
#include "tb_simple/generated/core/tb_simple.json.adapter.h"
#include <iostream>

using namespace Test::TbSimple;
using namespace Test::TbSimple::MQTT;

namespace {
    std::map<std::string, ApiGear::MQTT::CallbackFunction> createTopicMap(VoidInterfaceService* service)
    {
        return {
            {std::string("tb.simple/VoidInterface/rpc/funcVoid"), [service](const std::string& args, const std::string& responseTopic, const std::string& correlationData) { service->onInvokeFuncVoid(args, responseTopic, correlationData); } },
        };
    };
}

VoidInterfaceService::VoidInterfaceService(std::shared_ptr<IVoidInterface> impl, std::shared_ptr<ApiGear::MQTT::Service> service)
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

VoidInterfaceService::~VoidInterfaceService()
{
    m_impl->_getPublisher().unsubscribeFromAllChanges(*this);

    m_service->unsubscribeToConnectionStatus(m_connectionStatusRegistrationID);

    for (const auto& topic: m_topics)
    {
        m_service->unsubscribeTopic(topic. first);
    }
}

void VoidInterfaceService::onConnectionStatusChanged(bool connectionStatus)
{
    if(!connectionStatus)
    {
        return;
    }

    // send current values
}
void VoidInterfaceService::onInvokeFuncVoid(const std::string& args, const std::string& responseTopic, const std::string& correlationData) const
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    (void) responseTopic;
    (void) correlationData;
    m_impl->funcVoid();
}
void VoidInterfaceService::onSigVoid()
{
    if(m_service != nullptr) {
        const nlohmann::json& args = {  };
        static const auto topic = std::string("tb.simple/VoidInterface/sig/sigVoid");
        m_service->notifySignal(topic, nlohmann::json(args).dump());
    }
}
