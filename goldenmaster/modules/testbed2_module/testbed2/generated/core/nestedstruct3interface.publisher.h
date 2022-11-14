#pragma once

#include "testbed2/generated/api/datastructs.api.h"
#include "testbed2/generated/api/nestedstruct3interface.api.h"
#include "testbed2/generated/api/common.h"

#include <atomic>
#include <vector>
#include <map>
#include <functional>
#include <shared_mutex>

namespace Test {
namespace Testbed2 {

/**
 * The implementation of a NestedStruct3InterfacePublisher.
 * Use this class to store clients of the NestedStruct3Interface and inform them about the change
 * on call of the appropriate publish function.
 *
 * @warning This class is thread safe, but the subscribed classes or functions are not protected.
 */
class TEST_TESTBED2_EXPORT NestedStruct3InterfacePublisher : public INestedStruct3InterfacePublisher
{
public:
    /**
    * Implementation of INestedStruct3InterfacePublisher::subscribeToAllChanges
    */
    void subscribeToAllChanges(INestedStruct3InterfaceSubscriber& subscriber) override;
    /**
    * Implementation of INestedStruct3InterfacePublisher::unsubscribeFromAllChanges
    */
    void unsubscribeFromAllChanges(INestedStruct3InterfaceSubscriber& subscriber) override;

    /**
    * Implementation of INestedStruct3InterfacePublisher::subscribeToProp1Changed
    */
    long subscribeToProp1Changed(NestedStruct3InterfaceProp1PropertyCb callback) override;
    /**
    * Implementation of INestedStruct3InterfacePublisher::subscribeToProp1Changed
    */
    void unsubscribeFromProp1Changed(long handleId) override;

    /**
    * Implementation of INestedStruct3InterfacePublisher::subscribeToProp2Changed
    */
    long subscribeToProp2Changed(NestedStruct3InterfaceProp2PropertyCb callback) override;
    /**
    * Implementation of INestedStruct3InterfacePublisher::subscribeToProp2Changed
    */
    void unsubscribeFromProp2Changed(long handleId) override;

    /**
    * Implementation of INestedStruct3InterfacePublisher::subscribeToProp3Changed
    */
    long subscribeToProp3Changed(NestedStruct3InterfaceProp3PropertyCb callback) override;
    /**
    * Implementation of INestedStruct3InterfacePublisher::subscribeToProp3Changed
    */
    void unsubscribeFromProp3Changed(long handleId) override;

    /**
    * Implementation of INestedStruct3InterfacePublisher::subscribeToSig1
    */
    long subscribeToSig1(NestedStruct3InterfaceSig1SignalCb callback) override;
    /**
    * Implementation of INestedStruct3InterfacePublisher::unsubscribeFromSig1
    */
    void unsubscribeFromSig1(long handleId) override;

    /**
    * Implementation of INestedStruct3InterfacePublisher::subscribeToSig2
    */
    long subscribeToSig2(NestedStruct3InterfaceSig2SignalCb callback) override;
    /**
    * Implementation of INestedStruct3InterfacePublisher::unsubscribeFromSig2
    */
    void unsubscribeFromSig2(long handleId) override;

    /**
    * Implementation of INestedStruct3InterfacePublisher::subscribeToSig3
    */
    long subscribeToSig3(NestedStruct3InterfaceSig3SignalCb callback) override;
    /**
    * Implementation of INestedStruct3InterfacePublisher::unsubscribeFromSig3
    */
    void unsubscribeFromSig3(long handleId) override;

    /**
    * Implementation of INestedStruct3InterfacePublisher::publishProp1Changed
    */
    void publishProp1Changed(const NestedStruct1& prop1) const override;
    /**
    * Implementation of INestedStruct3InterfacePublisher::publishProp2Changed
    */
    void publishProp2Changed(const NestedStruct2& prop2) const override;
    /**
    * Implementation of INestedStruct3InterfacePublisher::publishProp3Changed
    */
    void publishProp3Changed(const NestedStruct3& prop3) const override;
    /**
    * Implementation of INestedStruct3InterfacePublisher::publishSig1
    */
    void publishSig1(const NestedStruct1& param1) const override;
    /**
    * Implementation of INestedStruct3InterfacePublisher::publishSig2
    */
    void publishSig2(const NestedStruct1& param1, const NestedStruct2& param2) const override;
    /**
    * Implementation of INestedStruct3InterfacePublisher::publishSig3
    */
    void publishSig3(const NestedStruct1& param1, const NestedStruct2& param2, const NestedStruct3& param3) const override;
private:
    // Subscribers informed about any property change or signal emitted in NestedStruct3Interface
    std::vector<std::reference_wrapper<INestedStruct3InterfaceSubscriber>> m_allChangesSubscribers;
    // Mutex for m_allChangesSubscribers
    mutable std::shared_timed_mutex m_allChangesSubscribersMutex;
    // Next free unique identifier to subscribe for the Prop1 change.
    std::atomic<long> m_prop1ChangedCallbackNextId {0};
    // Subscribed callbacks for the Prop1 change.
    std::map<long, NestedStruct3InterfaceProp1PropertyCb> m_prop1Callbacks;
    // Mutex for m_prop1Callbacks
    mutable std::shared_timed_mutex m_prop1CallbacksMutex;
    // Next free unique identifier to subscribe for the Prop2 change.
    std::atomic<long> m_prop2ChangedCallbackNextId {0};
    // Subscribed callbacks for the Prop2 change.
    std::map<long, NestedStruct3InterfaceProp2PropertyCb> m_prop2Callbacks;
    // Mutex for m_prop2Callbacks
    mutable std::shared_timed_mutex m_prop2CallbacksMutex;
    // Next free unique identifier to subscribe for the Prop3 change.
    std::atomic<long> m_prop3ChangedCallbackNextId {0};
    // Subscribed callbacks for the Prop3 change.
    std::map<long, NestedStruct3InterfaceProp3PropertyCb> m_prop3Callbacks;
    // Mutex for m_prop3Callbacks
    mutable std::shared_timed_mutex m_prop3CallbacksMutex;
    // Next free unique identifier to subscribe for the Sig1 emission.
    std::atomic<long> m_sig1SignalCallbackNextId {0};
    // Subscribed callbacks for the Sig1 emission.
    std::map<long, NestedStruct3InterfaceSig1SignalCb > m_sig1Callbacks;
    // Mutex for m_sig1SignalCallbackNextId and m_sig1Callbacks
    mutable std::shared_timed_mutex m_sig1CallbacksMutex;
    // Next free unique identifier to subscribe for the Sig2 emission.
    std::atomic<long> m_sig2SignalCallbackNextId {0};
    // Subscribed callbacks for the Sig2 emission.
    std::map<long, NestedStruct3InterfaceSig2SignalCb > m_sig2Callbacks;
    // Mutex for m_sig2SignalCallbackNextId and m_sig2Callbacks
    mutable std::shared_timed_mutex m_sig2CallbacksMutex;
    // Next free unique identifier to subscribe for the Sig3 emission.
    std::atomic<long> m_sig3SignalCallbackNextId {0};
    // Subscribed callbacks for the Sig3 emission.
    std::map<long, NestedStruct3InterfaceSig3SignalCb > m_sig3Callbacks;
    // Mutex for m_sig3SignalCallbackNextId and m_sig3Callbacks
    mutable std::shared_timed_mutex m_sig3CallbacksMutex;
};

} // namespace Testbed2
} // namespace Test
