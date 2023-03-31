

#include "tb_simple/generated/api/datastructs.api.h"
#include "tb_simple/generated/olink/nopropertiesinterfaceservice.h"
#include "tb_simple/generated/core/tb_simple.json.adapter.h"

#include "olink/iremotenode.h"
#include "olink/remoteregistry.h"
#include "apigear/olink/logger/logger.h"

#include <iostream>


using namespace Test::TbSimple;
using namespace Test::TbSimple::olink;

namespace 
{
const std::string interfaceId = "tb.simple.NoPropertiesInterface";
}

NoPropertiesInterfaceService::NoPropertiesInterfaceService(std::shared_ptr<INoPropertiesInterface> NoPropertiesInterface, ApiGear::ObjectLink::RemoteRegistry& registry)
    : m_NoPropertiesInterface(NoPropertiesInterface)
    , m_registry(registry)
    , m_logger(std::make_unique<ApiGear::Logger::Logger>())
{
    m_NoPropertiesInterface->_getPublisher().subscribeToAllChanges(*this);
}

NoPropertiesInterfaceService::~NoPropertiesInterfaceService()
{
    m_NoPropertiesInterface->_getPublisher().unsubscribeFromAllChanges(*this);
}

std::string NoPropertiesInterfaceService::olinkObjectName() {
    return interfaceId;
}

nlohmann::json NoPropertiesInterfaceService::olinkInvoke(const std::string& methodId, const nlohmann::json& fcnArgs) {
    m_logger->emitLog(ApiGear::Logger::LogLevel::Debug, methodId);
    const auto& memberMethod = ApiGear::ObjectLink::Name::getMemberName(methodId);
    if(memberMethod == "funcVoid") {
        m_NoPropertiesInterface->funcVoid();
        return nlohmann::json{};
    }
    if(memberMethod == "funcBool") {
        const bool& paramBool = fcnArgs.at(0);
        bool result = m_NoPropertiesInterface->funcBool(paramBool);
        return result;
    }
    return nlohmann::json();
}

void NoPropertiesInterfaceService::olinkSetProperty(const std::string& propertyId, const nlohmann::json& value) {
    m_logger->emitLog(ApiGear::Logger::LogLevel::Debug, propertyId);
    const auto& memberProperty = ApiGear::ObjectLink::Name::getMemberName(propertyId);
    // no properties to set
    (void) value;
    (void) memberProperty; 
}

void NoPropertiesInterfaceService::olinkLinked(const std::string& objetId, ApiGear::ObjectLink::IRemoteNode* /*node*/) {
    m_logger->emitLog(ApiGear::Logger::LogLevel::Debug, objetId);
}

void NoPropertiesInterfaceService::olinkUnlinked(const std::string& objetId){
    m_logger->emitLog(ApiGear::Logger::LogLevel::Debug, objetId);
}

nlohmann::json NoPropertiesInterfaceService::olinkCollectProperties()
{
    return nlohmann::json::object({
    });
}
void NoPropertiesInterfaceService::onSigVoid()
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
void NoPropertiesInterfaceService::onSigBool(bool paramBool)
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

