

#include "tb_simple/generated/api/datastructs.api.h"
#include "tb_simple/generated/olink/nooperationsinterfaceservice.h"
#include "tb_simple/generated/core/tb_simple.json.adapter.h"

#include "olink/iremotenode.h"
#include "olink/remoteregistry.h"
#include "apigear/utilities/logger.h"

#include <iostream>


using namespace Test::TbSimple;
using namespace Test::TbSimple::olink;

namespace 
{
const std::string interfaceId = "tb.simple.NoOperationsInterface";
}

NoOperationsInterfaceService::NoOperationsInterfaceService(std::shared_ptr<INoOperationsInterface> NoOperationsInterface, ApiGear::ObjectLink::RemoteRegistry& registry)
    : m_NoOperationsInterface(NoOperationsInterface)
    , m_registry(registry)
{
    m_NoOperationsInterface->_getPublisher().subscribeToAllChanges(*this);
}

NoOperationsInterfaceService::~NoOperationsInterfaceService()
{
    m_NoOperationsInterface->_getPublisher().unsubscribeFromAllChanges(*this);
}

std::string NoOperationsInterfaceService::olinkObjectName() {
    return interfaceId;
}

nlohmann::json NoOperationsInterfaceService::olinkInvoke(const std::string& methodId, const nlohmann::json& fcnArgs) {
    AG_LOG_DEBUG(methodId);
    const auto& memberMethod = ApiGear::ObjectLink::Name::getMemberName(methodId);
    // no operations to invoke
    (void) fcnArgs;
    (void) memberMethod;
    return nlohmann::json();
}

void NoOperationsInterfaceService::olinkSetProperty(const std::string& propertyId, const nlohmann::json& value) {
    AG_LOG_DEBUG(propertyId);
    const auto& memberProperty = ApiGear::ObjectLink::Name::getMemberName(propertyId);
    if(memberProperty == "propBool") {
        bool propBool = value.get<bool>();
        m_NoOperationsInterface->setPropBool(propBool);
    }
    if(memberProperty == "propInt") {
        int propInt = value.get<int>();
        m_NoOperationsInterface->setPropInt(propInt);
    } 
}

void NoOperationsInterfaceService::olinkLinked(const std::string& objectId, ApiGear::ObjectLink::IRemoteNode* /*node*/) {
    AG_LOG_DEBUG(objectId);
}

void NoOperationsInterfaceService::olinkUnlinked(const std::string& objectId){
    AG_LOG_DEBUG(objectId);
}

nlohmann::json NoOperationsInterfaceService::olinkCollectProperties()
{
    return nlohmann::json::object({
        { "propBool", m_NoOperationsInterface->getPropBool() },
        { "propInt", m_NoOperationsInterface->getPropInt() }
    });
}
void NoOperationsInterfaceService::onSigVoid()
{
    const nlohmann::json args = {  };
    const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sigVoid");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(signalId))) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifySignal(signalId, args);
        }
    }
}
void NoOperationsInterfaceService::onSigBool(bool paramBool)
{
    const nlohmann::json args = { paramBool };
    const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sigBool");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(signalId))) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifySignal(signalId, args);
        }
    }
}
void NoOperationsInterfaceService::onPropBoolChanged(bool propBool)
{
    const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propBool");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifyPropertyChange(propertyId, propBool);
        }
    }
}
void NoOperationsInterfaceService::onPropIntChanged(int propInt)
{
    const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propInt");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifyPropertyChange(propertyId, propInt);
        }
    }
}

