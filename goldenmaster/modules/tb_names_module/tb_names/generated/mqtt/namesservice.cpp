#include "tb_names/generated/mqtt/namesservice.h"
#include "tb_names/generated/core/tb_names.json.adapter.h"
#include <iostream>

using namespace Test::TbNames;
using namespace Test::TbNames::MQTT;

NamesService::NamesService(std::shared_ptr<INames> impl, std::shared_ptr<ApiGear::MQTT::Service> service)
    : m_impl(impl)
    , m_service(service)
    , m_topics(createTopicMap())
{
    m_impl->_getPublisher().subscribeToAllChanges(*this);

    m_connectionStatusRegistrationID = m_service->subscribeToConnectionStatus([this](bool connectionStatus){ onConnectionStatusChanged(connectionStatus); });
}

NamesService::~NamesService()
{
    m_impl->_getPublisher().unsubscribeFromAllChanges(*this);

    m_service->unsubscribeToConnectionStatus(m_connectionStatusRegistrationID);

    for (const auto& topic: m_topics)
    {
        m_service->unsubscribeTopic(topic. first);
    }
}

std::map<std::string, ApiGear::MQTT::CallbackFunction> NamesService::createTopicMap()
{
    return {
        {std::string("tb.names/Names/set/Switch"), [this](const std::string& args, const std::string&, const std::string&){ this->onSetSwitch(args); } },
    };
}

void NamesService::onConnectionStatusChanged(bool connectionStatus)
{
    if(!connectionStatus)
    {
        return;
    }

    for (const auto& topic: m_topics)
    {
        m_service->subscribeTopic(topic. first, topic.second);
    }

    // send current values
    onSwitchChanged(m_impl->getSwitch());
}
void NamesService::onSetSwitch(const std::string& args) const
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    if (json_args.empty())
    {
        return;
    }

    auto Switch = json_args.get<bool>();
    m_impl->setSwitch(Switch);
}
void NamesService::onSwitchChanged(bool Switch)
{
    if(m_service != nullptr) {
        static const auto topic = std::string("tb.names/Names/prop/Switch");
        m_service->notifyPropertyChange(topic, nlohmann::json(Switch).dump());
    }
}
