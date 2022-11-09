#pragma once

#include "tb_same1/generated/api/datastructs.api.h"
#include "tb_same1/generated/api/samestruct2interface.api.h"
#include "tb_same1/generated/api/common.h"

#include <vector>
#include <map>
#include <functional>

namespace Test {
namespace TbSame1 {

/**
 * The implementation of a SameStruct2InterfacePublisher.
 * Use this class to store clients of the SameStruct2Interface and inform them about the change
 * on call of the appropriate publish function.
 */
class TEST_TB_SAME1_EXPORT SameStruct2InterfacePublisher : public ISameStruct2InterfacePublisher
{
public:
    /**
    * Implementation of ISameStruct2InterfacePublisher::subscribeToAllChanges
    */
    void subscribeToAllChanges(ISameStruct2InterfaceSubscriber& subscriber) override;
    /**
    * Implementation of ISameStruct2InterfacePublisher::unsubscribeFromAllChanges
    */
    void unsubscribeFromAllChanges(ISameStruct2InterfaceSubscriber& subscriber) override;

    /**
    * Implementation of ISameStruct2InterfacePublisher::subscribeToProp1Changed
    */
    long subscribeToProp1Changed(SameStruct2InterfaceProp1PropertyCb callback) override;
    /**
    * Implementation of ISameStruct2InterfacePublisher::subscribeToProp1Changed
    */
    void unsubscribeFromProp1Changed(long handleId) override;

    /**
    * Implementation of ISameStruct2InterfacePublisher::subscribeToProp2Changed
    */
    long subscribeToProp2Changed(SameStruct2InterfaceProp2PropertyCb callback) override;
    /**
    * Implementation of ISameStruct2InterfacePublisher::subscribeToProp2Changed
    */
    void unsubscribeFromProp2Changed(long handleId) override;

    /**
    * Implementation of ISameStruct2InterfacePublisher::subscribeToSig1
    */
    long subscribeToSig1(SameStruct2InterfaceSig1SignalCb callback) override;
    /**
    * Implementation of ISameStruct2InterfacePublisher::unsubscribeFromSig1
    */
    void unsubscribeFromSig1(long handleId) override;

    /**
    * Implementation of ISameStruct2InterfacePublisher::subscribeToSig2
    */
    long subscribeToSig2(SameStruct2InterfaceSig2SignalCb callback) override;
    /**
    * Implementation of ISameStruct2InterfacePublisher::unsubscribeFromSig2
    */
    void unsubscribeFromSig2(long handleId) override;

    /**
    * Implementation of ISameStruct2InterfacePublisher::publishProp1Changed
    */
    void publishProp1Changed(const Struct2& prop1) const override;
    /**
    * Implementation of ISameStruct2InterfacePublisher::publishProp2Changed
    */
    void publishProp2Changed(const Struct2& prop2) const override;
    /**
    * Implementation of ISameStruct2InterfacePublisher::publishSig1
    */
    void publishSig1(const Struct1& param1) const override;
    /**
    * Implementation of ISameStruct2InterfacePublisher::publishSig2
    */
    void publishSig2(const Struct1& param1, const Struct2& param2) const override;
private:
    // Subscribers informed about any property change or singal emited in SameStruct2Interface
    std::vector<std::reference_wrapper<ISameStruct2InterfaceSubscriber>> m_allChangesSubscribers;
    // Next free unique identifier to subscribe for the Prop1 change.
    long m_prop1ChangedCallbackNextId = 0;
    // Subscribed callbacks for the Prop1 change.
    std::map<long, SameStruct2InterfaceProp1PropertyCb> m_prop1Callbacks;
    // Next free unique identifier to subscribe for the Prop2 change.
    long m_prop2ChangedCallbackNextId = 0;
    // Subscribed callbacks for the Prop2 change.
    std::map<long, SameStruct2InterfaceProp2PropertyCb> m_prop2Callbacks;
    // Next free unique identifier to subscribe for the Sig1 emission.
    long m_sig1SignalCallbackNextId = 0;
    // Subscribed callbacks for the Sig1 emission.
    std::map<long, SameStruct2InterfaceSig1SignalCb > m_sig1Callbacks;
    // Next free unique identifier to subscribe for the Sig2 emission.
    long m_sig2SignalCallbackNextId = 0;
    // Subscribed callbacks for the Sig2 emission.
    std::map<long, SameStruct2InterfaceSig2SignalCb > m_sig2Callbacks;
};

} // namespace TbSame1
} // namespace Test
