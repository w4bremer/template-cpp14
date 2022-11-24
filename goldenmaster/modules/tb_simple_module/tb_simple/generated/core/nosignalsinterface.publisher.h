#pragma once

#include "tb_simple/generated/api/datastructs.api.h"
#include "tb_simple/generated/api/nosignalsinterface.api.h"
#include "tb_simple/generated/api/common.h"

#include <atomic>
#include <vector>
#include <map>
#include <functional>
#include <shared_mutex>

namespace Test {
namespace TbSimple {

/**
 * The implementation of a NoSignalsInterfacePublisher.
 * Use this class to store clients of the NoSignalsInterface and inform them about the change
 * on call of the appropriate publish function.
 *
 * @warning This class is thread safe, but the subscribed classes or functions are not protected.
 */
class TEST_TB_SIMPLE_EXPORT NoSignalsInterfacePublisher : public INoSignalsInterfacePublisher
{
public:
    /**
    * Implementation of INoSignalsInterfacePublisher::subscribeToAllChanges
    */
    void subscribeToAllChanges(INoSignalsInterfaceSubscriber& subscriber) override;
    /**
    * Implementation of INoSignalsInterfacePublisher::unsubscribeFromAllChanges
    */
    void unsubscribeFromAllChanges(INoSignalsInterfaceSubscriber& subscriber) override;

    /**
    * Implementation of INoSignalsInterfacePublisher::subscribeToPropBoolChanged
    */
    long subscribeToPropBoolChanged(NoSignalsInterfacePropBoolPropertyCb callback) override;
    /**
    * Implementation of INoSignalsInterfacePublisher::subscribeToPropBoolChanged
    */
    void unsubscribeFromPropBoolChanged(long handleId) override;

    /**
    * Implementation of INoSignalsInterfacePublisher::subscribeToPropIntChanged
    */
    long subscribeToPropIntChanged(NoSignalsInterfacePropIntPropertyCb callback) override;
    /**
    * Implementation of INoSignalsInterfacePublisher::subscribeToPropIntChanged
    */
    void unsubscribeFromPropIntChanged(long handleId) override;

    /**
    * Implementation of INoSignalsInterfacePublisher::publishPropBoolChanged
    */
    void publishPropBoolChanged(bool propBool) const override;
    /**
    * Implementation of INoSignalsInterfacePublisher::publishPropIntChanged
    */
    void publishPropIntChanged(int propInt) const override;
private:
    // Subscribers informed about any property change or signal emitted in NoSignalsInterface
    std::vector<std::reference_wrapper<INoSignalsInterfaceSubscriber>> m_allChangesSubscribers;
    // Mutex for m_allChangesSubscribers
    mutable std::shared_timed_mutex m_allChangesSubscribersMutex;
    // Next free unique identifier to subscribe for the PropBool change.
    std::atomic<long> m_propBoolChangedCallbackNextId {0};
    // Subscribed callbacks for the PropBool change.
    std::map<long, NoSignalsInterfacePropBoolPropertyCb> m_propBoolCallbacks;
    // Mutex for m_propBoolCallbacks
    mutable std::shared_timed_mutex m_propBoolCallbacksMutex;
    // Next free unique identifier to subscribe for the PropInt change.
    std::atomic<long> m_propIntChangedCallbackNextId {0};
    // Subscribed callbacks for the PropInt change.
    std::map<long, NoSignalsInterfacePropIntPropertyCb> m_propIntCallbacks;
    // Mutex for m_propIntCallbacks
    mutable std::shared_timed_mutex m_propIntCallbacksMutex;
};

} // namespace TbSimple
} // namespace Test
