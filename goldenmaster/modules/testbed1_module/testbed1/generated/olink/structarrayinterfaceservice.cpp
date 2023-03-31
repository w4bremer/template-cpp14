

#include "testbed1/generated/api/datastructs.api.h"
#include "testbed1/generated/olink/structarrayinterfaceservice.h"
#include "testbed1/generated/core/testbed1.json.adapter.h"

#include "olink/iremotenode.h"
#include "olink/remoteregistry.h"
#include "apigear/utilities/logger.h"

#include <iostream>


using namespace Test::Testbed1;
using namespace Test::Testbed1::olink;

namespace 
{
const std::string interfaceId = "testbed1.StructArrayInterface";
}

StructArrayInterfaceService::StructArrayInterfaceService(std::shared_ptr<IStructArrayInterface> StructArrayInterface, ApiGear::ObjectLink::RemoteRegistry& registry)
    : m_StructArrayInterface(StructArrayInterface)
    , m_registry(registry)
    , m_logger(std::make_unique<ApiGear::Utilities::Logger>())
{
    m_StructArrayInterface->_getPublisher().subscribeToAllChanges(*this);
}

StructArrayInterfaceService::~StructArrayInterfaceService()
{
    m_StructArrayInterface->_getPublisher().unsubscribeFromAllChanges(*this);
}

std::string StructArrayInterfaceService::olinkObjectName() {
    return interfaceId;
}

nlohmann::json StructArrayInterfaceService::olinkInvoke(const std::string& methodId, const nlohmann::json& fcnArgs) {
    m_logger->emitLog(ApiGear::Utilities::LogLevel::Debug, methodId);
    const auto& memberMethod = ApiGear::ObjectLink::Name::getMemberName(methodId);
    if(memberMethod == "funcBool") {
        const std::list<StructBool>& paramBool = fcnArgs.at(0);
        StructBool result = m_StructArrayInterface->funcBool(paramBool);
        return result;
    }
    if(memberMethod == "funcInt") {
        const std::list<StructInt>& paramInt = fcnArgs.at(0);
        StructBool result = m_StructArrayInterface->funcInt(paramInt);
        return result;
    }
    if(memberMethod == "funcFloat") {
        const std::list<StructFloat>& paramFloat = fcnArgs.at(0);
        StructBool result = m_StructArrayInterface->funcFloat(paramFloat);
        return result;
    }
    if(memberMethod == "funcString") {
        const std::list<StructString>& paramString = fcnArgs.at(0);
        StructBool result = m_StructArrayInterface->funcString(paramString);
        return result;
    }
    return nlohmann::json();
}

void StructArrayInterfaceService::olinkSetProperty(const std::string& propertyId, const nlohmann::json& value) {
    m_logger->emitLog(ApiGear::Utilities::LogLevel::Debug, propertyId);
    const auto& memberProperty = ApiGear::ObjectLink::Name::getMemberName(propertyId);
    if(memberProperty == "propBool") {
        std::list<StructBool> propBool = value.get<std::list<StructBool>>();
        m_StructArrayInterface->setPropBool(propBool);
    }
    if(memberProperty == "propInt") {
        std::list<StructInt> propInt = value.get<std::list<StructInt>>();
        m_StructArrayInterface->setPropInt(propInt);
    }
    if(memberProperty == "propFloat") {
        std::list<StructFloat> propFloat = value.get<std::list<StructFloat>>();
        m_StructArrayInterface->setPropFloat(propFloat);
    }
    if(memberProperty == "propString") {
        std::list<StructString> propString = value.get<std::list<StructString>>();
        m_StructArrayInterface->setPropString(propString);
    } 
}

void StructArrayInterfaceService::olinkLinked(const std::string& objetId, ApiGear::ObjectLink::IRemoteNode* /*node*/) {
    m_logger->emitLog(ApiGear::Utilities::LogLevel::Debug, objetId);
}

void StructArrayInterfaceService::olinkUnlinked(const std::string& objetId){
    m_logger->emitLog(ApiGear::Utilities::LogLevel::Debug, objetId);
}

nlohmann::json StructArrayInterfaceService::olinkCollectProperties()
{
    return nlohmann::json::object({
        { "propBool", m_StructArrayInterface->getPropBool() },
        { "propInt", m_StructArrayInterface->getPropInt() },
        { "propFloat", m_StructArrayInterface->getPropFloat() },
        { "propString", m_StructArrayInterface->getPropString() }
    });
}
void StructArrayInterfaceService::onSigBool(const std::list<StructBool>& paramBool)
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
void StructArrayInterfaceService::onSigInt(const std::list<StructInt>& paramInt)
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
void StructArrayInterfaceService::onSigFloat(const std::list<StructFloat>& paramFloat)
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
void StructArrayInterfaceService::onSigString(const std::list<StructString>& paramString)
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
void StructArrayInterfaceService::onPropBoolChanged(const std::list<StructBool>& propBool)
{
    const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propBool");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifyPropertyChange(propertyId, propBool);
        }
    }
}
void StructArrayInterfaceService::onPropIntChanged(const std::list<StructInt>& propInt)
{
    const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propInt");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifyPropertyChange(propertyId, propInt);
        }
    }
}
void StructArrayInterfaceService::onPropFloatChanged(const std::list<StructFloat>& propFloat)
{
    const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propFloat");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifyPropertyChange(propertyId, propFloat);
        }
    }
}
void StructArrayInterfaceService::onPropStringChanged(const std::list<StructString>& propString)
{
    const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propString");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifyPropertyChange(propertyId, propString);
        }
    }
}

