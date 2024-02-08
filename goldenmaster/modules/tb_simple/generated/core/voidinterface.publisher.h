#pragma once

#include "tb_simple/generated/api/datastructs.api.h"
#include "tb_simple/generated/api/voidinterface.api.h"
#include "tb_simple/generated/api/common.h"

#include <atomic>
#include <vector>
#include <map>
#include <functional>
#include <shared_mutex>

namespace Test {
namespace TbSimple {

/**
 * The implementation of a VoidInterfacePublisher.
 * Use this class to store clients of the VoidInterface and inform them about the change
 * on call of the appropriate publish function.
 *
 * @warning This class is thread safe, but the subscribed classes or functions are not protected.
 */
class TEST_TB_SIMPLE_EXPORT VoidInterfacePublisher : public IVoidInterfacePublisher
{
public:
    /**
    * Implementation of IVoidInterfacePublisher::subscribeToAllChanges
    */
    void subscribeToAllChanges(IVoidInterfaceSubscriber& subscriber) override;
    /**
    * Implementation of IVoidInterfacePublisher::unsubscribeFromAllChanges
    */
    void unsubscribeFromAllChanges(IVoidInterfaceSubscriber& subscriber) override;

    /**
    * Implementation of IVoidInterfacePublisher::subscribeToSigVoid
    */
    long subscribeToSigVoid(VoidInterfaceSigVoidSignalCb callback) override;
    /**
    * Implementation of IVoidInterfacePublisher::unsubscribeFromSigVoid
    */
    void unsubscribeFromSigVoid(long handleId) override;

    /**
    * Implementation of IVoidInterfacePublisher::publishSigVoid
    */
    void publishSigVoid() const override;
private:
    // Subscribers informed about any property change or signal emitted in VoidInterface
    std::vector<std::reference_wrapper<IVoidInterfaceSubscriber>> m_allChangesSubscribers;
    // Mutex for m_allChangesSubscribers
    mutable std::shared_timed_mutex m_allChangesSubscribersMutex;
    // Next free unique identifier to subscribe for the SigVoid emission.
    std::atomic<long> m_sigVoidSignalCallbackNextId {0};
    // Subscribed callbacks for the SigVoid emission.
    std::map<long, VoidInterfaceSigVoidSignalCb > m_sigVoidCallbacks;
    // Mutex for m_sigVoidSignalCallbackNextId and m_sigVoidCallbacks
    mutable std::shared_timed_mutex m_sigVoidCallbacksMutex;
};

} // namespace TbSimple
} // namespace Test
