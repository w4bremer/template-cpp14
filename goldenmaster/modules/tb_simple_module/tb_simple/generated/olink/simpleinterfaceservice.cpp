

#include "tb_simple/generated/api/datastructs.api.h"
#include "tb_simple/generated/olink/simpleinterfaceservice.h"
#include "tb_simple/generated/core/tb_simple.json.adapter.h"

#include "olink/iremotenode.h"
#include "olink/remoteregistry.h"
#include "apigear/utilities/logger.h"

#include <iostream>


using namespace Test::TbSimple;
using namespace Test::TbSimple::olink;

namespace 
{
const std::string interfaceId = "tb.simple.SimpleInterface";
}

SimpleInterfaceService::SimpleInterfaceService(std::shared_ptr<ISimpleInterface> SimpleInterface, ApiGear::ObjectLink::RemoteRegistry& registry)
    : m_SimpleInterface(SimpleInterface)
    , m_registry(registry)
{
    m_SimpleInterface->_getPublisher().subscribeToAllChanges(*this);
}

SimpleInterfaceService::~SimpleInterfaceService()
{
    m_SimpleInterface->_getPublisher().unsubscribeFromAllChanges(*this);
}

std::string SimpleInterfaceService::olinkObjectName() {
    return interfaceId;
}

nlohmann::json SimpleInterfaceService::olinkInvoke(const std::string& methodId, const nlohmann::json& fcnArgs) {
    AG_LOG_DEBUG("SimpleInterfaceService invoke " + methodId);
    const auto& memberMethod = ApiGear::ObjectLink::Name::getMemberName(methodId);
    if(memberMethod == "funcVoid") {
        m_SimpleInterface->funcVoid();
        return nlohmann::json{};
    }
    if(memberMethod == "funcBool") {
        const bool& paramBool = fcnArgs.at(0);
        bool result = m_SimpleInterface->funcBool(paramBool);
        return result;
    }
    if(memberMethod == "funcInt") {
        const int& paramInt = fcnArgs.at(0);
        int result = m_SimpleInterface->funcInt(paramInt);
        return result;
    }
    if(memberMethod == "funcInt32") {
        const int32_t& paramInt32 = fcnArgs.at(0);
        int32_t result = m_SimpleInterface->funcInt32(paramInt32);
        return result;
    }
    if(memberMethod == "funcInt64") {
        const int64_t& paramInt64 = fcnArgs.at(0);
        int64_t result = m_SimpleInterface->funcInt64(paramInt64);
        return result;
    }
    if(memberMethod == "funcFloat") {
        const float& paramFloat = fcnArgs.at(0);
        float result = m_SimpleInterface->funcFloat(paramFloat);
        return result;
    }
    if(memberMethod == "funcFloat32") {
        const float& paramFloat32 = fcnArgs.at(0);
        float result = m_SimpleInterface->funcFloat32(paramFloat32);
        return result;
    }
    if(memberMethod == "funcFloat64") {
        const double& paramFloat = fcnArgs.at(0);
        double result = m_SimpleInterface->funcFloat64(paramFloat);
        return result;
    }
    if(memberMethod == "funcString") {
        const std::string& paramString = fcnArgs.at(0);
        std::string result = m_SimpleInterface->funcString(paramString);
        return result;
    }
    return nlohmann::json();
}

void SimpleInterfaceService::olinkSetProperty(const std::string& propertyId, const nlohmann::json& value) {
    AG_LOG_DEBUG("SimpleInterfaceService set property " + propertyId);
    const auto& memberProperty = ApiGear::ObjectLink::Name::getMemberName(propertyId);
    if(memberProperty == "propBool") {
        bool propBool = value.get<bool>();
        m_SimpleInterface->setPropBool(propBool);
    }
    if(memberProperty == "propInt") {
        int propInt = value.get<int>();
        m_SimpleInterface->setPropInt(propInt);
    }
    if(memberProperty == "propInt32") {
        int32_t propInt32 = value.get<int32_t>();
        m_SimpleInterface->setPropInt32(propInt32);
    }
    if(memberProperty == "propInt64") {
        int64_t propInt64 = value.get<int64_t>();
        m_SimpleInterface->setPropInt64(propInt64);
    }
    if(memberProperty == "propFloat") {
        float propFloat = value.get<float>();
        m_SimpleInterface->setPropFloat(propFloat);
    }
    if(memberProperty == "propFloat32") {
        float propFloat32 = value.get<float>();
        m_SimpleInterface->setPropFloat32(propFloat32);
    }
    if(memberProperty == "propFloat64") {
        double propFloat64 = value.get<double>();
        m_SimpleInterface->setPropFloat64(propFloat64);
    }
    if(memberProperty == "propString") {
        std::string propString = value.get<std::string>();
        m_SimpleInterface->setPropString(propString);
    } 
}

void SimpleInterfaceService::olinkLinked(const std::string& objectId, ApiGear::ObjectLink::IRemoteNode* /*node*/) {
    AG_LOG_DEBUG("SimpleInterfaceService linked " + objectId);
}

void SimpleInterfaceService::olinkUnlinked(const std::string& objectId){
    AG_LOG_DEBUG("SimpleInterfaceService unlinked " + objectId);
}

nlohmann::json SimpleInterfaceService::olinkCollectProperties()
{
    return nlohmann::json::object({
        { "propBool", m_SimpleInterface->getPropBool() },
        { "propInt", m_SimpleInterface->getPropInt() },
        { "propInt32", m_SimpleInterface->getPropInt32() },
        { "propInt64", m_SimpleInterface->getPropInt64() },
        { "propFloat", m_SimpleInterface->getPropFloat() },
        { "propFloat32", m_SimpleInterface->getPropFloat32() },
        { "propFloat64", m_SimpleInterface->getPropFloat64() },
        { "propString", m_SimpleInterface->getPropString() }
    });
}
void SimpleInterfaceService::onSigVoid()
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
void SimpleInterfaceService::onSigBool(bool paramBool)
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
void SimpleInterfaceService::onSigInt(int paramInt)
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
void SimpleInterfaceService::onSigInt32(int32_t paramInt32)
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
void SimpleInterfaceService::onSigInt64(int64_t paramInt64)
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
void SimpleInterfaceService::onSigFloat(float paramFloat)
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
void SimpleInterfaceService::onSigFloat32(float paramFloa32)
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
void SimpleInterfaceService::onSigFloat64(double paramFloat64)
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
void SimpleInterfaceService::onSigString(const std::string& paramString)
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
void SimpleInterfaceService::onPropBoolChanged(bool propBool)
{
    const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propBool");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifyPropertyChange(propertyId, propBool);
        }
    }
}
void SimpleInterfaceService::onPropIntChanged(int propInt)
{
    const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propInt");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifyPropertyChange(propertyId, propInt);
        }
    }
}
void SimpleInterfaceService::onPropInt32Changed(int32_t propInt32)
{
    const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propInt32");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifyPropertyChange(propertyId, propInt32);
        }
    }
}
void SimpleInterfaceService::onPropInt64Changed(int64_t propInt64)
{
    const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propInt64");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifyPropertyChange(propertyId, propInt64);
        }
    }
}
void SimpleInterfaceService::onPropFloatChanged(float propFloat)
{
    const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propFloat");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifyPropertyChange(propertyId, propFloat);
        }
    }
}
void SimpleInterfaceService::onPropFloat32Changed(float propFloat32)
{
    const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propFloat32");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifyPropertyChange(propertyId, propFloat32);
        }
    }
}
void SimpleInterfaceService::onPropFloat64Changed(double propFloat64)
{
    const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propFloat64");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifyPropertyChange(propertyId, propFloat64);
        }
    }
}
void SimpleInterfaceService::onPropStringChanged(const std::string& propString)
{
    const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propString");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifyPropertyChange(propertyId, propString);
        }
    }
}

