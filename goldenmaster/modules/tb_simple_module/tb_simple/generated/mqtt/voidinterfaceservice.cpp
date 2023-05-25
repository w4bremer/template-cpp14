#include "tb_simple/generated/mqtt/voidinterfaceservice.h"
#include "tb_simple/generated/core/tb_simple.json.adapter.h"
#include <iostream>

using namespace Test::TbSimple;
using namespace Test::TbSimple::MQTT;

VoidInterfaceService::VoidInterfaceService(std::shared_ptr<IVoidInterface> impl, std::shared_ptr<ApiGear::MQTT::Service> service)
    : m_impl(impl)
    , m_service(service)
{
    m_impl->_getPublisher().subscribeToAllChanges(*this);

    m_connectionStatusRegistrationID = m_service->subscribeToConnectionStatus(std::bind(&VoidInterfaceService::onConnectionStatusChanged, this, std::placeholders::_1));
    // subscribe to all property change request methods
    m_service->subscribeTopic(ApiGear::MQTT::Topic("tb.simple","VoidInterface",ApiGear::MQTT::Topic::TopicType::Operation,"funcVoid"), this);

}

VoidInterfaceService::~VoidInterfaceService()
{
    m_impl->_getPublisher().unsubscribeFromAllChanges(*this);

    m_service->unsubscribeToConnectionStatus(m_connectionStatusRegistrationID);
    m_service->unsubscribeTopic(ApiGear::MQTT::Topic("tb.simple","VoidInterface",ApiGear::MQTT::Topic::TopicType::Operation,"funcVoid"), this);
}

void VoidInterfaceService::onConnectionStatusChanged(bool connectionStatus)
{
    if(!connectionStatus)
    {
        return;
    }

    // send current values
}

void VoidInterfaceService::onInvoke(const ApiGear::MQTT::Topic& topic, const std::string& args, const ApiGear::MQTT::Topic& responseTopic, const std::string& correlationData)
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    const std::string& name = topic.getEntityName();

    // no operations with return value
    (void) responseTopic;
    (void) correlationData;

    if(name == "funcVoid") {
        m_impl->funcVoid();
        return;
    }
}
void VoidInterfaceService::onSigVoid()
{
    if(m_service != nullptr) {
        const nlohmann::json& args = {  };
        static const auto topic = ApiGear::MQTT::Topic("tb.simple","VoidInterface",ApiGear::MQTT::Topic::TopicType::Signal,"sigVoid");
        m_service->notifySignal(topic, nlohmann::json(args).dump());
    }
}
