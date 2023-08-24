#include "tb_simple/generated/mqtt/voidinterfaceservice.h"
#include "tb_simple/generated/core/tb_simple.json.adapter.h"
#include "apigear/mqtt/mqtttopic.h"
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
    m_service->subscribeTopic(std::string("tb.simple/VoidInterface/rpc/funcVoid"), std::bind(&VoidInterfaceService::onInvoke, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));

}

VoidInterfaceService::~VoidInterfaceService()
{
    m_impl->_getPublisher().unsubscribeFromAllChanges(*this);

    m_service->unsubscribeToConnectionStatus(m_connectionStatusRegistrationID);
    m_service->unsubscribeTopic(std::string("tb.simple/VoidInterface/rpc/funcVoid"), std::bind(&VoidInterfaceService::onInvoke, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
}

void VoidInterfaceService::onConnectionStatusChanged(bool connectionStatus)
{
    if(!connectionStatus)
    {
        return;
    }

    // send current values
}

void VoidInterfaceService::onSetProperty(const std::string& topic, const std::string& args)
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    const std::string& name = ApiGear::MQTT::Topic(topic).getEntityName();
    (void) name;
}

void VoidInterfaceService::onInvoke(const std::string& topic, const std::string& args, const std::string& responseTopic, const std::string& correlationData)
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    const std::string& name = ApiGear::MQTT::Topic(topic).getEntityName();

    // no operations with return value
    (void) responseTopic;
    (void) correlationData;
    (void) name;

    if(name == "funcVoid") {
        m_impl->funcVoid();
        return;
    }
}
void VoidInterfaceService::onSigVoid()
{
    if(m_service != nullptr) {
        const nlohmann::json& args = {  };
        static const auto topic = std::string("tb.simple/VoidInterface/sig/sigVoid");
        m_service->notifySignal(topic, nlohmann::json(args).dump());
    }
}
