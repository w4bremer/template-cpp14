#pragma once

#include "tb_simple/generated/api/datastructs.api.h"
#include "tb_simple/generated/api/nooperationsinterface.api.h"
#include "tb_simple/generated/api/common.h"

#include <atomic>
#include <vector>
#include <map>
#include <functional>
#include <shared_mutex>

namespace Test {
namespace TbSimple {

/**
 * The implementation of a NoOperationsInterfacePublisher.
 * Use this class to store clients of the NoOperationsInterface and inform them about the change
 * on call of the appropriate publish function.
 *
 * @warning This class is thread safe, but the subscribed classes or functions are not protected.
 */
class TEST_TB_SIMPLE_EXPORT NoOperationsInterfacePublisher : public INoOperationsInterfacePublisher
{
public:
    /**
    * Implementation of INoOperationsInterfacePublisher::subscribeToAllChanges
    */
    void subscribeToAllChanges(INoOperationsInterfaceSubscriber& subscriber) override;
    /**
    * Implementation of INoOperationsInterfacePublisher::unsubscribeFromAllChanges
    */
    void unsubscribeFromAllChanges(INoOperationsInterfaceSubscriber& subscriber) override;

    /**
    * Implementation of INoOperationsInterfacePublisher::subscribeToPropBoolChanged
    */
    long subscribeToPropBoolChanged(NoOperationsInterfacePropBoolPropertyCb callback) override;
    /**
    * Implementation of INoOperationsInterfacePublisher::subscribeToPropBoolChanged
    */
    void unsubscribeFromPropBoolChanged(long handleId) override;

    /**
    * Implementation of INoOperationsInterfacePublisher::subscribeToPropIntChanged
    */
    long subscribeToPropIntChanged(NoOperationsInterfacePropIntPropertyCb callback) override;
    /**
    * Implementation of INoOperationsInterfacePublisher::subscribeToPropIntChanged
    */
    void unsubscribeFromPropIntChanged(long handleId) override;

    /**
    * Implementation of INoOperationsInterfacePublisher::subscribeToSigVoid
    */
    long subscribeToSigVoid(NoOperationsInterfaceSigVoidSignalCb callback) override;
    /**
    * Implementation of INoOperationsInterfacePublisher::unsubscribeFromSigVoid
    */
    void unsubscribeFromSigVoid(long handleId) override;

    /**
    * Implementation of INoOperationsInterfacePublisher::subscribeToSigBool
    */
    long subscribeToSigBool(NoOperationsInterfaceSigBoolSignalCb callback) override;
    /**
    * Implementation of INoOperationsInterfacePublisher::unsubscribeFromSigBool
    */
    void unsubscribeFromSigBool(long handleId) override;

    /**
    * Implementation of INoOperationsInterfacePublisher::publishPropBoolChanged
    */
    void publishPropBoolChanged(bool propBool) const override;
    /**
    * Implementation of INoOperationsInterfacePublisher::publishPropIntChanged
    */
    void publishPropIntChanged(int propInt) const override;
    /**
    * Implementation of INoOperationsInterfacePublisher::publishSigVoid
    */
    void publishSigVoid() const override;
    /**
    * Implementation of INoOperationsInterfacePublisher::publishSigBool
    */
    void publishSigBool(bool paramBool) const override;
private:
    // Subscribers informed about any property change or signal emitted in NoOperationsInterface
    std::vector<std::reference_wrapper<INoOperationsInterfaceSubscriber>> m_allChangesSubscribers;
    // Mutex for m_allChangesSubscribers
    mutable std::shared_timed_mutex m_allChangesSubscribersMutex;
    // Next free unique identifier to subscribe for the PropBool change.
    std::atomic<long> m_propBoolChangedCallbackNextId {0};
    // Subscribed callbacks for the PropBool change.
    std::map<long, NoOperationsInterfacePropBoolPropertyCb> m_propBoolCallbacks;
    // Mutex for m_propBoolCallbacks
    mutable std::shared_timed_mutex m_propBoolCallbacksMutex;
    // Next free unique identifier to subscribe for the PropInt change.
    std::atomic<long> m_propIntChangedCallbackNextId {0};
    // Subscribed callbacks for the PropInt change.
    std::map<long, NoOperationsInterfacePropIntPropertyCb> m_propIntCallbacks;
    // Mutex for m_propIntCallbacks
    mutable std::shared_timed_mutex m_propIntCallbacksMutex;
    // Next free unique identifier to subscribe for the SigVoid emission.
    std::atomic<long> m_sigVoidSignalCallbackNextId {0};
    // Subscribed callbacks for the SigVoid emission.
    std::map<long, NoOperationsInterfaceSigVoidSignalCb > m_sigVoidCallbacks;
    // Mutex for m_sigVoidSignalCallbackNextId and m_sigVoidCallbacks
    mutable std::shared_timed_mutex m_sigVoidCallbacksMutex;
    // Next free unique identifier to subscribe for the SigBool emission.
    std::atomic<long> m_sigBoolSignalCallbackNextId {0};
    // Subscribed callbacks for the SigBool emission.
    std::map<long, NoOperationsInterfaceSigBoolSignalCb > m_sigBoolCallbacks;
    // Mutex for m_sigBoolSignalCallbackNextId and m_sigBoolCallbacks
    mutable std::shared_timed_mutex m_sigBoolCallbacksMutex;
};

} // namespace TbSimple
} // namespace Test
