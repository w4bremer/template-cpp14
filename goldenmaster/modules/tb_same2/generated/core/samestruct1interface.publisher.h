#pragma once

#include "tb_same2/generated/api/datastructs.api.h"
#include "tb_same2/generated/api/samestruct1interface.api.h"
#include "tb_same2/generated/api/common.h"

#include <atomic>
#include <vector>
#include <map>
#include <functional>
#include <shared_mutex>

namespace Test {
namespace TbSame2 {

/**
 * The implementation of a SameStruct1InterfacePublisher.
 * Use this class to store clients of the SameStruct1Interface and inform them about the change
 * on call of the appropriate publish function.
 *
 * @warning This class is thread safe, but the subscribed classes or functions are not protected.
 */
class TEST_TB_SAME2_EXPORT SameStruct1InterfacePublisher : public ISameStruct1InterfacePublisher
{
public:
    /**
    * Implementation of ISameStruct1InterfacePublisher::subscribeToAllChanges
    */
    void subscribeToAllChanges(ISameStruct1InterfaceSubscriber& subscriber) override;
    /**
    * Implementation of ISameStruct1InterfacePublisher::unsubscribeFromAllChanges
    */
    void unsubscribeFromAllChanges(ISameStruct1InterfaceSubscriber& subscriber) override;

    /**
    * Implementation of ISameStruct1InterfacePublisher::subscribeToProp1Changed
    */
    long subscribeToProp1Changed(SameStruct1InterfaceProp1PropertyCb callback) override;
    /**
    * Implementation of ISameStruct1InterfacePublisher::subscribeToProp1Changed
    */
    void unsubscribeFromProp1Changed(long handleId) override;

    /**
    * Implementation of ISameStruct1InterfacePublisher::subscribeToSig1
    */
    long subscribeToSig1(SameStruct1InterfaceSig1SignalCb callback) override;
    /**
    * Implementation of ISameStruct1InterfacePublisher::unsubscribeFromSig1
    */
    void unsubscribeFromSig1(long handleId) override;

    /**
    * Implementation of ISameStruct1InterfacePublisher::publishProp1Changed
    */
    void publishProp1Changed(const Struct1& prop1) const override;
    /**
    * Implementation of ISameStruct1InterfacePublisher::publishSig1
    */
    void publishSig1(const Struct1& param1) const override;
private:
    // Subscribers informed about any property change or signal emitted in SameStruct1Interface
    std::vector<std::reference_wrapper<ISameStruct1InterfaceSubscriber>> m_allChangesSubscribers;
    // Mutex for m_allChangesSubscribers
    mutable std::shared_timed_mutex m_allChangesSubscribersMutex;
    // Next free unique identifier to subscribe for the Prop1 change.
    std::atomic<long> m_prop1ChangedCallbackNextId {0};
    // Subscribed callbacks for the Prop1 change.
    std::map<long, SameStruct1InterfaceProp1PropertyCb> m_prop1Callbacks;
    // Mutex for m_prop1Callbacks
    mutable std::shared_timed_mutex m_prop1CallbacksMutex;
    // Next free unique identifier to subscribe for the Sig1 emission.
    std::atomic<long> m_sig1SignalCallbackNextId {0};
    // Subscribed callbacks for the Sig1 emission.
    std::map<long, SameStruct1InterfaceSig1SignalCb > m_sig1Callbacks;
    // Mutex for m_sig1SignalCallbackNextId and m_sig1Callbacks
    mutable std::shared_timed_mutex m_sig1CallbacksMutex;
};

} // namespace TbSame2
} // namespace Test
