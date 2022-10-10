

#include "testbed1/generated/api/datastructs.api.h"
#include "testbed1/generated/olink/structarrayinterfaceservice.adapter.h"
#include "testbed1/generated/core/testbed1.json.adapter.h"

#include "olink/iremotenode.h"
#include "olink/remoteregistry.h"

#include <iostream>


using namespace Test::Testbed1;
using namespace Test::Testbed1::olink;

namespace 
{
const std::string interfaceId = "testbed1.StructArrayInterface";
}

StructArrayInterfaceServiceAdapter::StructArrayInterfaceServiceAdapter(std::shared_ptr<IStructArrayInterface> StructArrayInterface, ApiGear::ObjectLink::RemoteRegistry& registry)
    : m_StructArrayInterface(StructArrayInterface)
    , m_registry(registry)
{
    m_StructArrayInterface->_getPublisher().subscribeToAllChanges(*this);
}

StructArrayInterfaceServiceAdapter::~StructArrayInterfaceServiceAdapter()
{
    m_StructArrayInterface->_getPublisher().unsubscribeFromAllChanges(*this);
}

std::string StructArrayInterfaceServiceAdapter::olinkObjectName() {
    return interfaceId;
}

nlohmann::json StructArrayInterfaceServiceAdapter::olinkInvoke(const std::string& methodId, const nlohmann::json& fcnArgs) {
    std::clog << methodId << std::endl;
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

void StructArrayInterfaceServiceAdapter::olinkSetProperty(const std::string& propertyId, const nlohmann::json& value) {
    std::clog << propertyId << std::endl;
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

void StructArrayInterfaceServiceAdapter::olinkLinked(const std::string& objetId, ApiGear::ObjectLink::IRemoteNode* /*node*/) {
    std::clog << objetId << std::endl;
}

void StructArrayInterfaceServiceAdapter::olinkUnlinked(const std::string& objetId){
    std::clog << objetId << std::endl;
}

nlohmann::json StructArrayInterfaceServiceAdapter::olinkCollectProperties()
{
    return nlohmann::json::object({
        { "propBool", m_StructArrayInterface->getPropBool() },
        { "propInt", m_StructArrayInterface->getPropInt() },
        { "propFloat", m_StructArrayInterface->getPropFloat() },
        { "propString", m_StructArrayInterface->getPropString() }
    });
}
void StructArrayInterfaceServiceAdapter::onSigBool(const std::list<StructBool>& paramBool)
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
void StructArrayInterfaceServiceAdapter::onSigInt(const std::list<StructInt>& paramInt)
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
void StructArrayInterfaceServiceAdapter::onSigFloat(const std::list<StructFloat>& paramFloat)
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
void StructArrayInterfaceServiceAdapter::onSigString(const std::list<StructString>& paramString)
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
void StructArrayInterfaceServiceAdapter::onPropBoolChanged(const std::list<StructBool>& propBool)
{
    const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propBool");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifyPropertyChange(propertyId, propBool);
        }
    }
}
void StructArrayInterfaceServiceAdapter::onPropIntChanged(const std::list<StructInt>& propInt)
{
    const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propInt");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifyPropertyChange(propertyId, propInt);
        }
    }
}
void StructArrayInterfaceServiceAdapter::onPropFloatChanged(const std::list<StructFloat>& propFloat)
{
    const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propFloat");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifyPropertyChange(propertyId, propFloat);
        }
    }
}
void StructArrayInterfaceServiceAdapter::onPropStringChanged(const std::list<StructString>& propString)
{
    const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propString");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifyPropertyChange(propertyId, propString);
        }
    }
}

