

#include "testbed1/generated/api/datastructs.api.h"
#include "testbed1/generated/olink/structinterfaceservice.h"
#include "testbed1/generated/core/testbed1.json.adapter.h"

#include "olink/iremotenode.h"
#include "olink/remoteregistry.h"
#include "apigear/olink/logger/logger.h"

#include <iostream>


using namespace Test::Testbed1;
using namespace Test::Testbed1::olink;

namespace 
{
const std::string interfaceId = "testbed1.StructInterface";
}

StructInterfaceService::StructInterfaceService(std::shared_ptr<IStructInterface> StructInterface, ApiGear::ObjectLink::RemoteRegistry& registry)
    : m_StructInterface(StructInterface)
    , m_registry(registry)
    , m_logger(std::make_unique<ApiGear::Logger::Logger>())
{
    m_StructInterface->_getPublisher().subscribeToAllChanges(*this);
}

StructInterfaceService::~StructInterfaceService()
{
    m_StructInterface->_getPublisher().unsubscribeFromAllChanges(*this);
}

std::string StructInterfaceService::olinkObjectName() {
    return interfaceId;
}

nlohmann::json StructInterfaceService::olinkInvoke(const std::string& methodId, const nlohmann::json& fcnArgs) {
    m_logger->emitLog(ApiGear::Logger::LogLevel::Debug, methodId);
    const auto& memberMethod = ApiGear::ObjectLink::Name::getMemberName(methodId);
    if(memberMethod == "funcBool") {
        const StructBool& paramBool = fcnArgs.at(0);
        StructBool result = m_StructInterface->funcBool(paramBool);
        return result;
    }
    if(memberMethod == "funcInt") {
        const StructInt& paramInt = fcnArgs.at(0);
        StructBool result = m_StructInterface->funcInt(paramInt);
        return result;
    }
    if(memberMethod == "funcFloat") {
        const StructFloat& paramFloat = fcnArgs.at(0);
        StructFloat result = m_StructInterface->funcFloat(paramFloat);
        return result;
    }
    if(memberMethod == "funcString") {
        const StructString& paramString = fcnArgs.at(0);
        StructString result = m_StructInterface->funcString(paramString);
        return result;
    }
    return nlohmann::json();
}

void StructInterfaceService::olinkSetProperty(const std::string& propertyId, const nlohmann::json& value) {
    m_logger->emitLog(ApiGear::Logger::LogLevel::Debug, propertyId);
    const auto& memberProperty = ApiGear::ObjectLink::Name::getMemberName(propertyId);
    if(memberProperty == "propBool") {
        StructBool propBool = value.get<StructBool>();
        m_StructInterface->setPropBool(propBool);
    }
    if(memberProperty == "propInt") {
        StructInt propInt = value.get<StructInt>();
        m_StructInterface->setPropInt(propInt);
    }
    if(memberProperty == "propFloat") {
        StructFloat propFloat = value.get<StructFloat>();
        m_StructInterface->setPropFloat(propFloat);
    }
    if(memberProperty == "propString") {
        StructString propString = value.get<StructString>();
        m_StructInterface->setPropString(propString);
    } 
}

void StructInterfaceService::olinkLinked(const std::string& objetId, ApiGear::ObjectLink::IRemoteNode* /*node*/) {
    m_logger->emitLog(ApiGear::Logger::LogLevel::Debug, objetId);
}

void StructInterfaceService::olinkUnlinked(const std::string& objetId){
    m_logger->emitLog(ApiGear::Logger::LogLevel::Debug, objetId);
}

nlohmann::json StructInterfaceService::olinkCollectProperties()
{
    return nlohmann::json::object({
        { "propBool", m_StructInterface->getPropBool() },
        { "propInt", m_StructInterface->getPropInt() },
        { "propFloat", m_StructInterface->getPropFloat() },
        { "propString", m_StructInterface->getPropString() }
    });
}
void StructInterfaceService::onSigBool(const StructBool& paramBool)
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
void StructInterfaceService::onSigInt(const StructInt& paramInt)
{
    const nlohmann::json args = { paramInt };
    const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sigInt");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(signalId))) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifySignal(signalId, args);
        }
    }
}
void StructInterfaceService::onSigFloat(const StructFloat& paramFloat)
{
    const nlohmann::json args = { paramFloat };
    const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sigFloat");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(signalId))) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifySignal(signalId, args);
        }
    }
}
void StructInterfaceService::onSigString(const StructString& paramString)
{
    const nlohmann::json args = { paramString };
    const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sigString");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(signalId))) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifySignal(signalId, args);
        }
    }
}
void StructInterfaceService::onPropBoolChanged(const StructBool& propBool)
{
    const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propBool");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifyPropertyChange(propertyId, propBool);
        }
    }
}
void StructInterfaceService::onPropIntChanged(const StructInt& propInt)
{
    const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propInt");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifyPropertyChange(propertyId, propInt);
        }
    }
}
void StructInterfaceService::onPropFloatChanged(const StructFloat& propFloat)
{
    const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propFloat");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifyPropertyChange(propertyId, propFloat);
        }
    }
}
void StructInterfaceService::onPropStringChanged(const StructString& propString)
{
    const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propString");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifyPropertyChange(propertyId, propString);
        }
    }
}

