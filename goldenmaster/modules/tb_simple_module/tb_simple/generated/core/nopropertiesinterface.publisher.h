#pragma once

#include "tb_simple/generated/api/datastructs.api.h"
#include "tb_simple/generated/api/nopropertiesinterface.api.h"
#include "tb_simple/generated/api/common.h"

#include <atomic>
#include <vector>
#include <map>
#include <functional>
#include <shared_mutex>

namespace Test {
namespace TbSimple {

/**
 * The implementation of a NoPropertiesInterfacePublisher.
 * Use this class to store clients of the NoPropertiesInterface and inform them about the change
 * on call of the appropriate publish function.
 *
 * @warning This class is thread safe, but the subscribed classes or functions are not protected.
 */
class TEST_TB_SIMPLE_EXPORT NoPropertiesInterfacePublisher : public INoPropertiesInterfacePublisher
{
public:
    /**
    * Implementation of INoPropertiesInterfacePublisher::subscribeToAllChanges
    */
    void subscribeToAllChanges(INoPropertiesInterfaceSubscriber& subscriber) override;
    /**
    * Implementation of INoPropertiesInterfacePublisher::unsubscribeFromAllChanges
    */
    void unsubscribeFromAllChanges(INoPropertiesInterfaceSubscriber& subscriber) override;

    /**
    * Implementation of INoPropertiesInterfacePublisher::subscribeToSigVoid
    */
    long subscribeToSigVoid(NoPropertiesInterfaceSigVoidSignalCb callback) override;
    /**
    * Implementation of INoPropertiesInterfacePublisher::unsubscribeFromSigVoid
    */
    void unsubscribeFromSigVoid(long handleId) override;

    /**
    * Implementation of INoPropertiesInterfacePublisher::subscribeToSigBool
    */
    long subscribeToSigBool(NoPropertiesInterfaceSigBoolSignalCb callback) override;
    /**
    * Implementation of INoPropertiesInterfacePublisher::unsubscribeFromSigBool
    */
    void unsubscribeFromSigBool(long handleId) override;

    /**
    * Implementation of INoPropertiesInterfacePublisher::publishSigVoid
    */
    void publishSigVoid() const override;
    /**
    * Implementation of INoPropertiesInterfacePublisher::publishSigBool
    */
    void publishSigBool(bool paramBool) const override;
private:
    // Subscribers informed about any property change or signal emitted in NoPropertiesInterface
    std::vector<std::reference_wrapper<INoPropertiesInterfaceSubscriber>> m_allChangesSubscribers;
    // Mutex for m_allChangesSubscribers
    mutable std::shared_timed_mutex m_allChangesSubscribersMutex;
    // Next free unique identifier to subscribe for the SigVoid emission.
    std::atomic<long> m_sigVoidSignalCallbackNextId {0};
    // Subscribed callbacks for the SigVoid emission.
    std::map<long, NoPropertiesInterfaceSigVoidSignalCb > m_sigVoidCallbacks;
    // Mutex for m_sigVoidSignalCallbackNextId and m_sigVoidCallbacks
    mutable std::shared_timed_mutex m_sigVoidCallbacksMutex;
    // Next free unique identifier to subscribe for the SigBool emission.
    std::atomic<long> m_sigBoolSignalCallbackNextId {0};
    // Subscribed callbacks for the SigBool emission.
    std::map<long, NoPropertiesInterfaceSigBoolSignalCb > m_sigBoolCallbacks;
    // Mutex for m_sigBoolSignalCallbackNextId and m_sigBoolCallbacks
    mutable std::shared_timed_mutex m_sigBoolCallbacksMutex;
};

} // namespace TbSimple
} // namespace Test
