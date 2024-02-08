#pragma once

#include "tb_same2/generated/api/datastructs.api.h"
#include "tb_same2/generated/api/samestruct2interface.api.h"
#include "tb_same2/generated/api/common.h"

#include <atomic>
#include <vector>
#include <map>
#include <functional>
#include <shared_mutex>

namespace Test {
namespace TbSame2 {

/**
 * The implementation of a SameStruct2InterfacePublisher.
 * Use this class to store clients of the SameStruct2Interface and inform them about the change
 * on call of the appropriate publish function.
 *
 * @warning This class is thread safe, but the subscribed classes or functions are not protected.
 */
class TEST_TB_SAME2_EXPORT SameStruct2InterfacePublisher : public ISameStruct2InterfacePublisher
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
    // Subscribers informed about any property change or signal emitted in SameStruct2Interface
    std::vector<std::reference_wrapper<ISameStruct2InterfaceSubscriber>> m_allChangesSubscribers;
    // Mutex for m_allChangesSubscribers
    mutable std::shared_timed_mutex m_allChangesSubscribersMutex;
    // Next free unique identifier to subscribe for the Prop1 change.
    std::atomic<long> m_prop1ChangedCallbackNextId {0};
    // Subscribed callbacks for the Prop1 change.
    std::map<long, SameStruct2InterfaceProp1PropertyCb> m_prop1Callbacks;
    // Mutex for m_prop1Callbacks
    mutable std::shared_timed_mutex m_prop1CallbacksMutex;
    // Next free unique identifier to subscribe for the Prop2 change.
    std::atomic<long> m_prop2ChangedCallbackNextId {0};
    // Subscribed callbacks for the Prop2 change.
    std::map<long, SameStruct2InterfaceProp2PropertyCb> m_prop2Callbacks;
    // Mutex for m_prop2Callbacks
    mutable std::shared_timed_mutex m_prop2CallbacksMutex;
    // Next free unique identifier to subscribe for the Sig1 emission.
    std::atomic<long> m_sig1SignalCallbackNextId {0};
    // Subscribed callbacks for the Sig1 emission.
    std::map<long, SameStruct2InterfaceSig1SignalCb > m_sig1Callbacks;
    // Mutex for m_sig1SignalCallbackNextId and m_sig1Callbacks
    mutable std::shared_timed_mutex m_sig1CallbacksMutex;
    // Next free unique identifier to subscribe for the Sig2 emission.
    std::atomic<long> m_sig2SignalCallbackNextId {0};
    // Subscribed callbacks for the Sig2 emission.
    std::map<long, SameStruct2InterfaceSig2SignalCb > m_sig2Callbacks;
    // Mutex for m_sig2SignalCallbackNextId and m_sig2Callbacks
    mutable std::shared_timed_mutex m_sig2CallbacksMutex;
};

} // namespace TbSame2
} // namespace Test
