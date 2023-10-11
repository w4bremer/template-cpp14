

#include "tb_names/generated/olink/namesclient.h"
#include "tb_names/generated/core/names.publisher.h"
#include "tb_names/generated/core/tb_names.json.adapter.h"

#include "olink/iclientnode.h"
#include "apigear/utilities/logger.h"

using namespace Test::TbNames;
using namespace Test::TbNames::olink;

namespace 
{
const std::string interfaceId = "tb.names.Names";
}

NamesClient::NamesClient()
    : m_publisher(std::make_unique<NamesPublisher>())
{}

void NamesClient::applyState(const nlohmann::json& fields) 
{
    if(fields.contains("Switch")) {
        setSwitchLocal(fields["Switch"].get<bool>());
    }
}

void NamesClient::applyProperty(const std::string& propertyName, const nlohmann::json& value)
{
    if ( propertyName == "Switch") {
        setSwitchLocal(value.get<bool>());
    }
}

void NamesClient::setSwitch(bool Switch)
{
    if(!m_node) {
        AG_LOG_WARNING("Attempt to set property but " + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return;
    }
    static const auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "Switch");
    m_node->setRemoteProperty(propertyId, Switch);
}

void NamesClient::setSwitchLocal(bool Switch)
{
    if (m_data.m_Switch != Switch) {
        m_data.m_Switch = Switch;
        m_publisher->publishSwitchChanged(Switch);
    }
}

bool NamesClient::getSwitch() const
{
    return m_data.m_Switch;
}

std::string NamesClient::olinkObjectName()
{
    return interfaceId;
}

void NamesClient::olinkOnSignal(const std::string& signalId, const nlohmann::json& args)
{
    const auto& signalName = ApiGear::ObjectLink::Name::getMemberName(signalId);
    (void) args;
    (void) signalName;
}

void NamesClient::olinkOnPropertyChanged(const std::string& propertyId, const nlohmann::json& value)
{
    applyProperty(ApiGear::ObjectLink::Name::getMemberName(propertyId), value);
}
void NamesClient::olinkOnInit(const std::string& /*name*/, const nlohmann::json& props, ApiGear::ObjectLink::IClientNode *node)
{
    m_node = node;
    applyState(props);
}

void NamesClient::olinkOnRelease()
{
    m_node = nullptr;
}

bool NamesClient::isReady() const
{
    return m_node != nullptr;
}

INamesPublisher& NamesClient::_getPublisher() const
{
    return *m_publisher;
}
