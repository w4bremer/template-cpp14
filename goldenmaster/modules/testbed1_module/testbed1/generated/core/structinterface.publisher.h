#pragma once

#include "testbed1/generated/api/datastructs.api.h"
#include "testbed1/generated/api/structinterface.api.h"
#include "testbed1/generated/api/common.h"

#include <atomic>
#include <vector>
#include <map>
#include <functional>
#include <shared_mutex>

namespace Test {
namespace Testbed1 {

/**
 * The implementation of a StructInterfacePublisher.
 * Use this class to store clients of the StructInterface and inform them about the change
 * on call of the appropriate publish function.
 *
 * @warning This class is thread safe, but the subscribed classes or functions are not protected.
 */
class TEST_TESTBED1_EXPORT StructInterfacePublisher : public IStructInterfacePublisher
{
public:
    /**
    * Implementation of IStructInterfacePublisher::subscribeToAllChanges
    */
    void subscribeToAllChanges(IStructInterfaceSubscriber& subscriber) override;
    /**
    * Implementation of IStructInterfacePublisher::unsubscribeFromAllChanges
    */
    void unsubscribeFromAllChanges(IStructInterfaceSubscriber& subscriber) override;

    /**
    * Implementation of IStructInterfacePublisher::subscribeToPropBoolChanged
    */
    long subscribeToPropBoolChanged(StructInterfacePropBoolPropertyCb callback) override;
    /**
    * Implementation of IStructInterfacePublisher::subscribeToPropBoolChanged
    */
    void unsubscribeFromPropBoolChanged(long handleId) override;

    /**
    * Implementation of IStructInterfacePublisher::subscribeToPropIntChanged
    */
    long subscribeToPropIntChanged(StructInterfacePropIntPropertyCb callback) override;
    /**
    * Implementation of IStructInterfacePublisher::subscribeToPropIntChanged
    */
    void unsubscribeFromPropIntChanged(long handleId) override;

    /**
    * Implementation of IStructInterfacePublisher::subscribeToPropFloatChanged
    */
    long subscribeToPropFloatChanged(StructInterfacePropFloatPropertyCb callback) override;
    /**
    * Implementation of IStructInterfacePublisher::subscribeToPropFloatChanged
    */
    void unsubscribeFromPropFloatChanged(long handleId) override;

    /**
    * Implementation of IStructInterfacePublisher::subscribeToPropStringChanged
    */
    long subscribeToPropStringChanged(StructInterfacePropStringPropertyCb callback) override;
    /**
    * Implementation of IStructInterfacePublisher::subscribeToPropStringChanged
    */
    void unsubscribeFromPropStringChanged(long handleId) override;

    /**
    * Implementation of IStructInterfacePublisher::subscribeToSigBool
    */
    long subscribeToSigBool(StructInterfaceSigBoolSignalCb callback) override;
    /**
    * Implementation of IStructInterfacePublisher::unsubscribeFromSigBool
    */
    void unsubscribeFromSigBool(long handleId) override;

    /**
    * Implementation of IStructInterfacePublisher::subscribeToSigInt
    */
    long subscribeToSigInt(StructInterfaceSigIntSignalCb callback) override;
    /**
    * Implementation of IStructInterfacePublisher::unsubscribeFromSigInt
    */
    void unsubscribeFromSigInt(long handleId) override;

    /**
    * Implementation of IStructInterfacePublisher::subscribeToSigFloat
    */
    long subscribeToSigFloat(StructInterfaceSigFloatSignalCb callback) override;
    /**
    * Implementation of IStructInterfacePublisher::unsubscribeFromSigFloat
    */
    void unsubscribeFromSigFloat(long handleId) override;

    /**
    * Implementation of IStructInterfacePublisher::subscribeToSigString
    */
    long subscribeToSigString(StructInterfaceSigStringSignalCb callback) override;
    /**
    * Implementation of IStructInterfacePublisher::unsubscribeFromSigString
    */
    void unsubscribeFromSigString(long handleId) override;

    /**
    * Implementation of IStructInterfacePublisher::publishPropBoolChanged
    */
    void publishPropBoolChanged(const StructBool& propBool) const override;
    /**
    * Implementation of IStructInterfacePublisher::publishPropIntChanged
    */
    void publishPropIntChanged(const StructInt& propInt) const override;
    /**
    * Implementation of IStructInterfacePublisher::publishPropFloatChanged
    */
    void publishPropFloatChanged(const StructFloat& propFloat) const override;
    /**
    * Implementation of IStructInterfacePublisher::publishPropStringChanged
    */
    void publishPropStringChanged(const StructString& propString) const override;
    /**
    * Implementation of IStructInterfacePublisher::publishSigBool
    */
    void publishSigBool(const StructBool& paramBool) const override;
    /**
    * Implementation of IStructInterfacePublisher::publishSigInt
    */
    void publishSigInt(const StructInt& paramInt) const override;
    /**
    * Implementation of IStructInterfacePublisher::publishSigFloat
    */
    void publishSigFloat(const StructFloat& paramFloat) const override;
    /**
    * Implementation of IStructInterfacePublisher::publishSigString
    */
    void publishSigString(const StructString& paramString) const override;
private:
    // Subscribers informed about any property change or signal emitted in StructInterface
    std::vector<std::reference_wrapper<IStructInterfaceSubscriber>> m_allChangesSubscribers;
    // Mutex for m_allChangesSubscribers
    mutable std::shared_timed_mutex m_allChangesSubscribersMutex;
    // Next free unique identifier to subscribe for the PropBool change.
    std::atomic<long> m_propBoolChangedCallbackNextId {0};
    // Subscribed callbacks for the PropBool change.
    std::map<long, StructInterfacePropBoolPropertyCb> m_propBoolCallbacks;
    // Mutex for m_propBoolCallbacks
    mutable std::shared_timed_mutex m_propBoolCallbacksMutex;
    // Next free unique identifier to subscribe for the PropInt change.
    std::atomic<long> m_propIntChangedCallbackNextId {0};
    // Subscribed callbacks for the PropInt change.
    std::map<long, StructInterfacePropIntPropertyCb> m_propIntCallbacks;
    // Mutex for m_propIntCallbacks
    mutable std::shared_timed_mutex m_propIntCallbacksMutex;
    // Next free unique identifier to subscribe for the PropFloat change.
    std::atomic<long> m_propFloatChangedCallbackNextId {0};
    // Subscribed callbacks for the PropFloat change.
    std::map<long, StructInterfacePropFloatPropertyCb> m_propFloatCallbacks;
    // Mutex for m_propFloatCallbacks
    mutable std::shared_timed_mutex m_propFloatCallbacksMutex;
    // Next free unique identifier to subscribe for the PropString change.
    std::atomic<long> m_propStringChangedCallbackNextId {0};
    // Subscribed callbacks for the PropString change.
    std::map<long, StructInterfacePropStringPropertyCb> m_propStringCallbacks;
    // Mutex for m_propStringCallbacks
    mutable std::shared_timed_mutex m_propStringCallbacksMutex;
    // Next free unique identifier to subscribe for the SigBool emission.
    std::atomic<long> m_sigBoolSignalCallbackNextId {0};
    // Subscribed callbacks for the SigBool emission.
    std::map<long, StructInterfaceSigBoolSignalCb > m_sigBoolCallbacks;
    // Mutex for m_sigBoolSignalCallbackNextId and m_sigBoolCallbacks
    mutable std::shared_timed_mutex m_sigBoolCallbacksMutex;
    // Next free unique identifier to subscribe for the SigInt emission.
    std::atomic<long> m_sigIntSignalCallbackNextId {0};
    // Subscribed callbacks for the SigInt emission.
    std::map<long, StructInterfaceSigIntSignalCb > m_sigIntCallbacks;
    // Mutex for m_sigIntSignalCallbackNextId and m_sigIntCallbacks
    mutable std::shared_timed_mutex m_sigIntCallbacksMutex;
    // Next free unique identifier to subscribe for the SigFloat emission.
    std::atomic<long> m_sigFloatSignalCallbackNextId {0};
    // Subscribed callbacks for the SigFloat emission.
    std::map<long, StructInterfaceSigFloatSignalCb > m_sigFloatCallbacks;
    // Mutex for m_sigFloatSignalCallbackNextId and m_sigFloatCallbacks
    mutable std::shared_timed_mutex m_sigFloatCallbacksMutex;
    // Next free unique identifier to subscribe for the SigString emission.
    std::atomic<long> m_sigStringSignalCallbackNextId {0};
    // Subscribed callbacks for the SigString emission.
    std::map<long, StructInterfaceSigStringSignalCb > m_sigStringCallbacks;
    // Mutex for m_sigStringSignalCallbackNextId and m_sigStringCallbacks
    mutable std::shared_timed_mutex m_sigStringCallbacksMutex;
};

} // namespace Testbed1
} // namespace Test
