

#include "tb_simple/generated/api/datastructs.api.h"
#include "tb_simple/generated/olink/nosignalsinterfaceservice.h"
#include "tb_simple/generated/core/tb_simple.json.adapter.h"

#include "olink/iremotenode.h"
#include "olink/remoteregistry.h"
#include "apigear/olink/logger/logger.h"

#include <iostream>


using namespace Test::TbSimple;
using namespace Test::TbSimple::olink;

namespace 
{
const std::string interfaceId = "tb.simple.NoSignalsInterface";
}

NoSignalsInterfaceService::NoSignalsInterfaceService(std::shared_ptr<INoSignalsInterface> NoSignalsInterface, ApiGear::ObjectLink::RemoteRegistry& registry)
    : m_NoSignalsInterface(NoSignalsInterface)
    , m_registry(registry)
    , m_logger(std::make_unique<ApiGear::Logger::Logger>())
{
    m_NoSignalsInterface->_getPublisher().subscribeToAllChanges(*this);
}

NoSignalsInterfaceService::~NoSignalsInterfaceService()
{
    m_NoSignalsInterface->_getPublisher().unsubscribeFromAllChanges(*this);
}

std::string NoSignalsInterfaceService::olinkObjectName() {
    return interfaceId;
}

nlohmann::json NoSignalsInterfaceService::olinkInvoke(const std::string& methodId, const nlohmann::json& fcnArgs) {
    m_logger->emitLog(ApiGear::Logger::LogLevel::Debug, methodId);
    const auto& memberMethod = ApiGear::ObjectLink::Name::getMemberName(methodId);
    if(memberMethod == "funcVoid") {
        m_NoSignalsInterface->funcVoid();
        return nlohmann::json{};
    }
    if(memberMethod == "funcBool") {
        const bool& paramBool = fcnArgs.at(0);
        bool result = m_NoSignalsInterface->funcBool(paramBool);
        return result;
    }
    return nlohmann::json();
}

void NoSignalsInterfaceService::olinkSetProperty(const std::string& propertyId, const nlohmann::json& value) {
    m_logger->emitLog(ApiGear::Logger::LogLevel::Debug, propertyId);
    const auto& memberProperty = ApiGear::ObjectLink::Name::getMemberName(propertyId);
    if(memberProperty == "propBool") {
        bool propBool = value.get<bool>();
        m_NoSignalsInterface->setPropBool(propBool);
    }
    if(memberProperty == "propInt") {
        int propInt = value.get<int>();
        m_NoSignalsInterface->setPropInt(propInt);
    } 
}

void NoSignalsInterfaceService::olinkLinked(const std::string& objetId, ApiGear::ObjectLink::IRemoteNode* /*node*/) {
    m_logger->emitLog(ApiGear::Logger::LogLevel::Debug, objetId);
}

void NoSignalsInterfaceService::olinkUnlinked(const std::string& objetId){
    m_logger->emitLog(ApiGear::Logger::LogLevel::Debug, objetId);
}

nlohmann::json NoSignalsInterfaceService::olinkCollectProperties()
{
    return nlohmann::json::object({
        { "propBool", m_NoSignalsInterface->getPropBool() },
        { "propInt", m_NoSignalsInterface->getPropInt() }
    });
}
void NoSignalsInterfaceService::onPropBoolChanged(bool propBool)
{
    const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propBool");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifyPropertyChange(propertyId, propBool);
        }
    }
}
void NoSignalsInterfaceService::onPropIntChanged(int propInt)
{
    const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propInt");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifyPropertyChange(propertyId, propInt);
        }
    }
}

