

#include "testbed2/generated/api/datastructs.api.h"
#include "testbed2/generated/olink/nestedstruct1interfaceservice.adapter.h"
#include "testbed2/generated/core/testbed2.json.adapter.h"

#include "olink/iremotenode.h"
#include "olink/remoteregistry.h"

#include <iostream>


using namespace Test::Testbed2;
using namespace Test::Testbed2::olink;

namespace 
{
const std::string interfaceId = "testbed2.NestedStruct1Interface";
}

NestedStruct1InterfaceServiceAdapter::NestedStruct1InterfaceServiceAdapter(std::shared_ptr<INestedStruct1Interface> NestedStruct1Interface, ApiGear::ObjectLink::RemoteRegistry& registry)
    : m_NestedStruct1Interface(NestedStruct1Interface)
    , m_registry(registry)
{
    m_NestedStruct1Interface->_getPublisher().subscribeToAllChanges(*this);
}

NestedStruct1InterfaceServiceAdapter::~NestedStruct1InterfaceServiceAdapter()
{
    m_NestedStruct1Interface->_getPublisher().unsubscribeFromAllChanges(*this);
}

std::string NestedStruct1InterfaceServiceAdapter::olinkObjectName() {
    return interfaceId;
}

nlohmann::json NestedStruct1InterfaceServiceAdapter::olinkInvoke(const std::string& methodId, const nlohmann::json& fcnArgs) {
    std::clog << methodId << std::endl;
    const auto& memberMethod = ApiGear::ObjectLink::Name::getMemberName(methodId);
    if(memberMethod == "func1") {
        const NestedStruct1& param1 = fcnArgs.at(0);
        NestedStruct1 result = m_NestedStruct1Interface->func1(param1);
        return result;
    }
    return nlohmann::json();
}

void NestedStruct1InterfaceServiceAdapter::olinkSetProperty(const std::string& propertyId, const nlohmann::json& value) {
    std::clog << propertyId << std::endl;
    const auto& memberProperty = ApiGear::ObjectLink::Name::getMemberName(propertyId);
    if(memberProperty == "prop1") {
        NestedStruct1 prop1 = value.get<NestedStruct1>();
        m_NestedStruct1Interface->setProp1(prop1);
    } 
}

void NestedStruct1InterfaceServiceAdapter::olinkLinked(const std::string& objetId, ApiGear::ObjectLink::IRemoteNode* /*node*/) {
    std::clog << objetId << std::endl;
}

void NestedStruct1InterfaceServiceAdapter::olinkUnlinked(const std::string& objetId){
    std::clog << objetId << std::endl;
}

nlohmann::json NestedStruct1InterfaceServiceAdapter::olinkCollectProperties()
{
    return nlohmann::json::object({
        { "prop1", m_NestedStruct1Interface->getProp1() }
    });
}
void NestedStruct1InterfaceServiceAdapter::onSig1(const NestedStruct1& param1)
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
void NestedStruct1InterfaceServiceAdapter::onProp1Changed(const NestedStruct1& prop1)
{
    const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "prop1");
    for(auto node: m_registry.getNodes(ApiGear::ObjectLink::Name::getObjectId(propertyId))) {
        auto lockedNode = node.lock();
        if(lockedNode) {
            lockedNode->notifyPropertyChange(propertyId, prop1);
        }
    }
}

