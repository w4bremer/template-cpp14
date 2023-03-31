

#include "tb_same2/generated/api/datastructs.api.h"
#include "tb_same2/generated/olink/samestruct1interfaceservice.h"
#include "tb_same2/generated/core/tb_same2.json.adapter.h"

#include "olink/iremotenode.h"
#include "olink/remoteregistry.h"
#include "apigear/olink/logger/logger.h"

#include <iostream>


using namespace Test::TbSame2;
using namespace Test::TbSame2::olink;

namespace 
{
const std::string interfaceId = "tb.same2.SameStruct1Interface";
}

SameStruct1InterfaceService::SameStruct1InterfaceService(std::shared_ptr<ISameStruct1Interface> SameStruct1Interface, ApiGear::ObjectLink::RemoteRegistry& registry)
    : m_SameStruct1Interface(SameStruct1Interface)
    , m_registry(registry)
    , m_logger(std::make_unique<ApiGear::Logger::Logger>())
{
    m_SameStruct1Interface->_getPublisher().subscribeToAllChanges(*this);
}

SameStruct1InterfaceService::~SameStruct1InterfaceService()
{
    m_SameStruct1Interface->_getPublisher().unsubscribeFromAllChanges(*this);
}

std::string SameStruct1InterfaceService::olinkObjectName() {
    return interfaceId;
}

nlohmann::json SameStruct1InterfaceService::olinkInvoke(const std::string& methodId, const nlohmann::json& fcnArgs) {
    m_logger->emitLog(ApiGear::Logger::LogLevel::Debug, methodId);
    const auto& memberMethod = ApiGear::ObjectLink::Name::getMemberName(methodId);
    if(memberMethod == "func1") {
        const Struct1& param1 = fcnArgs.at(0);
        Struct1 result = m_SameStruct1Interface->func1(param1);
        return result;
    }
    return nlohmann::json();
}

void SameStruct1InterfaceService::olinkSetProperty(const std::string& propertyId, const nlohmann::json& value) {
    m_logger->emitLog(ApiGear::Logger::LogLevel::Debug, propertyId);
    const auto& memberProperty = ApiGear::ObjectLink::Name::getMemberName(propertyId);
    if(memberProperty == "prop1") {
        Struct1 prop1 = value.get<Struct1>();
        m_SameStruct1Interface->setProp1(prop1);
    } 
}

void SameStruct1InterfaceService::olinkLinked(const std::string& objetId, ApiGear::ObjectLink::IRemoteNode* /*node*/) {
    m_logger->emitLog(ApiGear::Logger::LogLevel::Debug, objetId);
}

void SameStruct1InterfaceService::olinkUnlinked(const std::string& objetId){
    m_logger->emitLog(ApiGear::Logger::LogLevel::Debug, objetId);
}

nlohmann::json SameStruct1InterfaceService::olinkCollectProperties()
{
    return nlohmann::json::object({
        { "prop1", m_SameStruct1Interface->getProp1() }
    });
}
void SameStruct1InterfaceService::onSig1(const Struct1& param1)
{
    const nlohmann::json args = { param1 };
    const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sig1");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(signalId))) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifySignal(signalId, args);
        }
    }
}
void SameStruct1InterfaceService::onProp1Changed(const Struct1& prop1)
{
    const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "prop1");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifyPropertyChange(propertyId, prop1);
        }
    }
}

