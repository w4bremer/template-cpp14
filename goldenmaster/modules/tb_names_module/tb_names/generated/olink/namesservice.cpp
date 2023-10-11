

#include "tb_names/generated/api/datastructs.api.h"
#include "tb_names/generated/olink/namesservice.h"
#include "tb_names/generated/core/tb_names.json.adapter.h"

#include "olink/iremotenode.h"
#include "olink/remoteregistry.h"
#include "apigear/utilities/logger.h"

#include <iostream>


using namespace Test::TbNames;
using namespace Test::TbNames::olink;

namespace 
{
const std::string interfaceId = "tb.names.Names";
}

NamesService::NamesService(std::shared_ptr<INames> Names, ApiGear::ObjectLink::RemoteRegistry& registry)
    : m_Names(Names)
    , m_registry(registry)
{
    m_Names->_getPublisher().subscribeToAllChanges(*this);
}

NamesService::~NamesService()
{
    m_Names->_getPublisher().unsubscribeFromAllChanges(*this);
}

std::string NamesService::olinkObjectName() {
    return interfaceId;
}

nlohmann::json NamesService::olinkInvoke(const std::string& methodId, const nlohmann::json& fcnArgs) {
    AG_LOG_DEBUG("NamesService invoke " + methodId);
    const auto& memberMethod = ApiGear::ObjectLink::Name::getMemberName(methodId);
    // no operations to invoke
    (void) fcnArgs;
    (void) memberMethod;
    return nlohmann::json();
}

void NamesService::olinkSetProperty(const std::string& propertyId, const nlohmann::json& value) {
    AG_LOG_DEBUG("NamesService set property " + propertyId);
    const auto& memberProperty = ApiGear::ObjectLink::Name::getMemberName(propertyId);
    if(memberProperty == "Switch") {
        bool Switch = value.get<bool>();
        m_Names->setSwitch(Switch);
    } 
}

void NamesService::olinkLinked(const std::string& objectId, ApiGear::ObjectLink::IRemoteNode* /*node*/) {
    AG_LOG_DEBUG("NamesService linked " + objectId);
}

void NamesService::olinkUnlinked(const std::string& objectId){
    AG_LOG_DEBUG("NamesService unlinked " + objectId);
}

nlohmann::json NamesService::olinkCollectProperties()
{
    return nlohmann::json::object({
        { "Switch", m_Names->getSwitch() }
    });
}
void NamesService::onSwitchChanged(bool Switch)
{
    static const auto propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "Switch");
    static const auto objectId = olinkObjectName();
    for(auto node: m_registry.getNodes(objectId)) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifyPropertyChange(propertyId, Switch);
        }
    }
}

