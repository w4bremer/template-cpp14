

#include "tb_simple/generated/api/datastructs.api.h"
#include "tb_simple/generated/olink/simplearrayinterfaceservice.h"
#include "tb_simple/generated/core/tb_simple.json.adapter.h"

#include "olink/iremotenode.h"
#include "olink/remoteregistry.h"
#include "apigear/utilities/logger.h"

#include <iostream>


using namespace Test::TbSimple;
using namespace Test::TbSimple::olink;

namespace 
{
const std::string interfaceId = "tb.simple.SimpleArrayInterface";
}

SimpleArrayInterfaceService::SimpleArrayInterfaceService(std::shared_ptr<ISimpleArrayInterface> SimpleArrayInterface, ApiGear::ObjectLink::RemoteRegistry& registry)
    : m_SimpleArrayInterface(SimpleArrayInterface)
    , m_registry(registry)
{
    m_SimpleArrayInterface->_getPublisher().subscribeToAllChanges(*this);
}

SimpleArrayInterfaceService::~SimpleArrayInterfaceService()
{
    m_SimpleArrayInterface->_getPublisher().unsubscribeFromAllChanges(*this);
}

std::string SimpleArrayInterfaceService::olinkObjectName() {
    return interfaceId;
}

nlohmann::json SimpleArrayInterfaceService::olinkInvoke(const std::string& methodId, const nlohmann::json& fcnArgs) {
    ApiGear::Utilities::logDebug(methodId);
    const auto& memberMethod = ApiGear::ObjectLink::Name::getMemberName(methodId);
    if(memberMethod == "funcBool") {
        const std::list<bool>& paramBool = fcnArgs.at(0);
        std::list<bool> result = m_SimpleArrayInterface->funcBool(paramBool);
        return result;
    }
    if(memberMethod == "funcInt") {
        const std::list<int>& paramInt = fcnArgs.at(0);
        std::list<int> result = m_SimpleArrayInterface->funcInt(paramInt);
        return result;
    }
    if(memberMethod == "funcInt32") {
        const std::list<int32_t>& paramInt32 = fcnArgs.at(0);
        std::list<int32_t> result = m_SimpleArrayInterface->funcInt32(paramInt32);
        return result;
    }
    if(memberMethod == "funcInt64") {
        const std::list<int64_t>& paramInt64 = fcnArgs.at(0);
        std::list<int64_t> result = m_SimpleArrayInterface->funcInt64(paramInt64);
        return result;
    }
    if(memberMethod == "funcFloat") {
        const std::list<float>& paramFloat = fcnArgs.at(0);
        std::list<float> result = m_SimpleArrayInterface->funcFloat(paramFloat);
        return result;
    }
    if(memberMethod == "funcFloat32") {
        const std::list<float>& paramFloat32 = fcnArgs.at(0);
        std::list<float> result = m_SimpleArrayInterface->funcFloat32(paramFloat32);
        return result;
    }
    if(memberMethod == "funcFloat64") {
        const std::list<double>& paramFloat = fcnArgs.at(0);
        std::list<double> result = m_SimpleArrayInterface->funcFloat64(paramFloat);
        return result;
    }
    if(memberMethod == "funcString") {
        const std::list<std::string>& paramString = fcnArgs.at(0);
        std::list<std::string> result = m_SimpleArrayInterface->funcString(paramString);
        return result;
    }
    return nlohmann::json();
}

void SimpleArrayInterfaceService::olinkSetProperty(const std::string& propertyId, const nlohmann::json& value) {
    ApiGear::Utilities::logDebug(propertyId);
    const auto& memberProperty = ApiGear::ObjectLink::Name::getMemberName(propertyId);
    if(memberProperty == "propBool") {
        std::list<bool> propBool = value.get<std::list<bool>>();
        m_SimpleArrayInterface->setPropBool(propBool);
    }
    if(memberProperty == "propInt") {
        std::list<int> propInt = value.get<std::list<int>>();
        m_SimpleArrayInterface->setPropInt(propInt);
    }
    if(memberProperty == "propInt32") {
        std::list<int32_t> propInt32 = value.get<std::list<int32_t>>();
        m_SimpleArrayInterface->setPropInt32(propInt32);
    }
    if(memberProperty == "propInt64") {
        std::list<int64_t> propInt64 = value.get<std::list<int64_t>>();
        m_SimpleArrayInterface->setPropInt64(propInt64);
    }
    if(memberProperty == "propFloat") {
        std::list<float> propFloat = value.get<std::list<float>>();
        m_SimpleArrayInterface->setPropFloat(propFloat);
    }
    if(memberProperty == "propFloat32") {
        std::list<float> propFloat32 = value.get<std::list<float>>();
        m_SimpleArrayInterface->setPropFloat32(propFloat32);
    }
    if(memberProperty == "propFloat64") {
        std::list<double> propFloat64 = value.get<std::list<double>>();
        m_SimpleArrayInterface->setPropFloat64(propFloat64);
    }
    if(memberProperty == "propString") {
        std::list<std::string> propString = value.get<std::list<std::string>>();
        m_SimpleArrayInterface->setPropString(propString);
    } 
}

void SimpleArrayInterfaceService::olinkLinked(const std::string& objectId, ApiGear::ObjectLink::IRemoteNode* /*node*/) {
    ApiGear::Utilities::logDebug(objectId);
}

void SimpleArrayInterfaceService::olinkUnlinked(const std::string& objectId){
    ApiGear::Utilities::logDebug(objectId);
}

nlohmann::json SimpleArrayInterfaceService::olinkCollectProperties()
{
    return nlohmann::json::object({
        { "propBool", m_SimpleArrayInterface->getPropBool() },
        { "propInt", m_SimpleArrayInterface->getPropInt() },
        { "propInt32", m_SimpleArrayInterface->getPropInt32() },
        { "propInt64", m_SimpleArrayInterface->getPropInt64() },
        { "propFloat", m_SimpleArrayInterface->getPropFloat() },
        { "propFloat32", m_SimpleArrayInterface->getPropFloat32() },
        { "propFloat64", m_SimpleArrayInterface->getPropFloat64() },
        { "propString", m_SimpleArrayInterface->getPropString() }
    });
}
void SimpleArrayInterfaceService::onSigBool(const std::list<bool>& paramBool)
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
void SimpleArrayInterfaceService::onSigInt(const std::list<int>& paramInt)
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
void SimpleArrayInterfaceService::onSigInt32(const std::list<int32_t>& paramInt32)
{
    const nlohmann::json args = { paramInt32 };
    const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sigInt32");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(signalId))) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifySignal(signalId, args);
        }
    }
}
void SimpleArrayInterfaceService::onSigInt64(const std::list<int64_t>& paramInt64)
{
    const nlohmann::json args = { paramInt64 };
    const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sigInt64");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(signalId))) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifySignal(signalId, args);
        }
    }
}
void SimpleArrayInterfaceService::onSigFloat(const std::list<float>& paramFloat)
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
void SimpleArrayInterfaceService::onSigFloat32(const std::list<float>& paramFloa32)
{
    const nlohmann::json args = { paramFloa32 };
    const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sigFloat32");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(signalId))) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifySignal(signalId, args);
        }
    }
}
void SimpleArrayInterfaceService::onSigFloat64(const std::list<double>& paramFloat64)
{
    const nlohmann::json args = { paramFloat64 };
    const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sigFloat64");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(signalId))) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifySignal(signalId, args);
        }
    }
}
void SimpleArrayInterfaceService::onSigString(const std::list<std::string>& paramString)
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
void SimpleArrayInterfaceService::onPropBoolChanged(const std::list<bool>& propBool)
{
    const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propBool");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifyPropertyChange(propertyId, propBool);
        }
    }
}
void SimpleArrayInterfaceService::onPropIntChanged(const std::list<int>& propInt)
{
    const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propInt");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifyPropertyChange(propertyId, propInt);
        }
    }
}
void SimpleArrayInterfaceService::onPropInt32Changed(const std::list<int32_t>& propInt32)
{
    const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propInt32");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifyPropertyChange(propertyId, propInt32);
        }
    }
}
void SimpleArrayInterfaceService::onPropInt64Changed(const std::list<int64_t>& propInt64)
{
    const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propInt64");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifyPropertyChange(propertyId, propInt64);
        }
    }
}
void SimpleArrayInterfaceService::onPropFloatChanged(const std::list<float>& propFloat)
{
    const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propFloat");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifyPropertyChange(propertyId, propFloat);
        }
    }
}
void SimpleArrayInterfaceService::onPropFloat32Changed(const std::list<float>& propFloat32)
{
    const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propFloat32");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifyPropertyChange(propertyId, propFloat32);
        }
    }
}
void SimpleArrayInterfaceService::onPropFloat64Changed(const std::list<double>& propFloat64)
{
    const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propFloat64");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifyPropertyChange(propertyId, propFloat64);
        }
    }
}
void SimpleArrayInterfaceService::onPropStringChanged(const std::list<std::string>& propString)
{
    const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propString");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifyPropertyChange(propertyId, propString);
        }
    }
}

