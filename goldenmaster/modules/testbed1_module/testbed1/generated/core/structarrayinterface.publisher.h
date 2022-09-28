#pragma once

#include "testbed1/generated/api/datastructs.api.h"
#include "testbed1/generated/api/structarrayinterface.api.h"
#include "testbed1/generated/api/common.h"

#include <atomic>
#include <vector>
#include <map>
#include <functional>
#include <shared_mutex>

namespace Test {
namespace Testbed1 {

/**
 * The implementation of a StructArrayInterfacePublisher.
 * Use this class to store clients of the StructArrayInterface and inform them about the change
 * on call of the appropriate publish function.
 */
class TEST_TESTBED1_EXPORT StructArrayInterfacePublisher : public IStructArrayInterfacePublisher
{
public:
    /**
    * Implementation of IStructArrayInterfacePublisher::subscribeToAllChanges
    */
    void subscribeToAllChanges(IStructArrayInterfaceSubscriber& subscriber) override;
    /**
    * Implementation of IStructArrayInterfacePublisher::unsubscribeFromAllChanges
    */
    void unsubscribeFromAllChanges(IStructArrayInterfaceSubscriber& subscriber) override;

    /**
    * Implementation of IStructArrayInterfacePublisher::subscribeToPropBoolChanged
    */
    long subscribeToPropBoolChanged(StructArrayInterfacePropBoolPropertyCb callback) override;
    /**
    * Implementation of IStructArrayInterfacePublisher::subscribeToPropBoolChanged
    */
    void unsubscribeFromPropBoolChanged(long handleId) override;

    /**
    * Implementation of IStructArrayInterfacePublisher::subscribeToPropIntChanged
    */
    long subscribeToPropIntChanged(StructArrayInterfacePropIntPropertyCb callback) override;
    /**
    * Implementation of IStructArrayInterfacePublisher::subscribeToPropIntChanged
    */
    void unsubscribeFromPropIntChanged(long handleId) override;

    /**
    * Implementation of IStructArrayInterfacePublisher::subscribeToPropFloatChanged
    */
    long subscribeToPropFloatChanged(StructArrayInterfacePropFloatPropertyCb callback) override;
    /**
    * Implementation of IStructArrayInterfacePublisher::subscribeToPropFloatChanged
    */
    void unsubscribeFromPropFloatChanged(long handleId) override;

    /**
    * Implementation of IStructArrayInterfacePublisher::subscribeToPropStringChanged
    */
    long subscribeToPropStringChanged(StructArrayInterfacePropStringPropertyCb callback) override;
    /**
    * Implementation of IStructArrayInterfacePublisher::subscribeToPropStringChanged
    */
    void unsubscribeFromPropStringChanged(long handleId) override;

    /**
    * Implementation of IStructArrayInterfacePublisher::subscribeToSigBool
    */
    long subscribeToSigBool(StructArrayInterfaceSigBoolSignalCb callback) override;
    /**
    * Implementation of IStructArrayInterfacePublisher::unsubscribeFromSigBool
    */
    void unsubscribeFromSigBool(long handleId) override;

    /**
    * Implementation of IStructArrayInterfacePublisher::subscribeToSigInt
    */
    long subscribeToSigInt(StructArrayInterfaceSigIntSignalCb callback) override;
    /**
    * Implementation of IStructArrayInterfacePublisher::unsubscribeFromSigInt
    */
    void unsubscribeFromSigInt(long handleId) override;

    /**
    * Implementation of IStructArrayInterfacePublisher::subscribeToSigFloat
    */
    long subscribeToSigFloat(StructArrayInterfaceSigFloatSignalCb callback) override;
    /**
    * Implementation of IStructArrayInterfacePublisher::unsubscribeFromSigFloat
    */
    void unsubscribeFromSigFloat(long handleId) override;

    /**
    * Implementation of IStructArrayInterfacePublisher::subscribeToSigString
    */
    long subscribeToSigString(StructArrayInterfaceSigStringSignalCb callback) override;
    /**
    * Implementation of IStructArrayInterfacePublisher::unsubscribeFromSigString
    */
    void unsubscribeFromSigString(long handleId) override;

    /**
    * Implementation of IStructArrayInterfacePublisher::publishPropBoolChanged
    */
    void publishPropBoolChanged(const std::list<StructBool>& propBool) const override;
    /**
    * Implementation of IStructArrayInterfacePublisher::publishPropIntChanged
    */
    void publishPropIntChanged(const std::list<StructInt>& propInt) const override;
    /**
    * Implementation of IStructArrayInterfacePublisher::publishPropFloatChanged
    */
    void publishPropFloatChanged(const std::list<StructFloat>& propFloat) const override;
    /**
    * Implementation of IStructArrayInterfacePublisher::publishPropStringChanged
    */
    void publishPropStringChanged(const std::list<StructString>& propString) const override;
    /**
    * Implementation of IStructArrayInterfacePublisher::publishSigBool
    */
    void publishSigBool(const std::list<StructBool>& paramBool) const override;
    /**
    * Implementation of IStructArrayInterfacePublisher::publishSigInt
    */
    void publishSigInt(const std::list<StructInt>& paramInt) const override;
    /**
    * Implementation of IStructArrayInterfacePublisher::publishSigFloat
    */
    void publishSigFloat(const std::list<StructFloat>& paramFloat) const override;
    /**
    * Implementation of IStructArrayInterfacePublisher::publishSigString
    */
    void publishSigString(const std::list<StructString>& paramString) const override;
private:
    // Subscribers informed about any property change or singal emited in StructArrayInterface
    std::vector<std::reference_wrapper<IStructArrayInterfaceSubscriber>> m_allChangesSubscribers;
    // Mutex for m_allChangesSubscribers
    mutable std::shared_timed_mutex m_allChangesSubscribersMutex;
    // Next free unique identifier to subscribe for the PropBool change.
    std::atomic<long> m_propBoolChangedCallbackNextId {0};
    // Subscribed callbacks for the PropBool change.
    std::map<long, StructArrayInterfacePropBoolPropertyCb> m_propBoolCallbacks;
    // Mutex for m_propBoolCallbacks
    mutable std::shared_timed_mutex m_propBoolCallbacksMutex;
    // Next free unique identifier to subscribe for the PropInt change.
    std::atomic<long> m_propIntChangedCallbackNextId {0};
    // Subscribed callbacks for the PropInt change.
    std::map<long, StructArrayInterfacePropIntPropertyCb> m_propIntCallbacks;
    // Mutex for m_propIntCallbacks
    mutable std::shared_timed_mutex m_propIntCallbacksMutex;
    // Next free unique identifier to subscribe for the PropFloat change.
    std::atomic<long> m_propFloatChangedCallbackNextId {0};
    // Subscribed callbacks for the PropFloat change.
    std::map<long, StructArrayInterfacePropFloatPropertyCb> m_propFloatCallbacks;
    // Mutex for m_propFloatCallbacks
    mutable std::shared_timed_mutex m_propFloatCallbacksMutex;
    // Next free unique identifier to subscribe for the PropString change.
    std::atomic<long> m_propStringChangedCallbackNextId {0};
    // Subscribed callbacks for the PropString change.
    std::map<long, StructArrayInterfacePropStringPropertyCb> m_propStringCallbacks;
    // Mutex for m_propStringCallbacks
    mutable std::shared_timed_mutex m_propStringCallbacksMutex;
    // Next free unique identifier to subscribe for the SigBool emission.
    std::atomic<long> m_sigBoolSignalCallbackNextId {0};
    // Subscribed callbacks for the SigBool emission.
    std::map<long, StructArrayInterfaceSigBoolSignalCb > m_sigBoolCallbacks;
    // Mutex for m_sigBoolSignalCallbackNextId and m_sigBoolCallbacks
    mutable std::shared_timed_mutex m_sigBoolCallbacksMutex;
    // Next free unique identifier to subscribe for the SigInt emission.
    std::atomic<long> m_sigIntSignalCallbackNextId {0};
    // Subscribed callbacks for the SigInt emission.
    std::map<long, StructArrayInterfaceSigIntSignalCb > m_sigIntCallbacks;
    // Mutex for m_sigIntSignalCallbackNextId and m_sigIntCallbacks
    mutable std::shared_timed_mutex m_sigIntCallbacksMutex;
    // Next free unique identifier to subscribe for the SigFloat emission.
    std::atomic<long> m_sigFloatSignalCallbackNextId {0};
    // Subscribed callbacks for the SigFloat emission.
    std::map<long, StructArrayInterfaceSigFloatSignalCb > m_sigFloatCallbacks;
    // Mutex for m_sigFloatSignalCallbackNextId and m_sigFloatCallbacks
    mutable std::shared_timed_mutex m_sigFloatCallbacksMutex;
    // Next free unique identifier to subscribe for the SigString emission.
    std::atomic<long> m_sigStringSignalCallbackNextId {0};
    // Subscribed callbacks for the SigString emission.
    std::map<long, StructArrayInterfaceSigStringSignalCb > m_sigStringCallbacks;
    // Mutex for m_sigStringSignalCallbackNextId and m_sigStringCallbacks
    mutable std::shared_timed_mutex m_sigStringCallbacksMutex;
};

} // namespace Testbed1
} // namespace Test
