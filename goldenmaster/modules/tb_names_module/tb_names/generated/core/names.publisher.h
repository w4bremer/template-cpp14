#pragma once

#include "tb_names/generated/api/datastructs.api.h"
#include "tb_names/generated/api/names.api.h"
#include "tb_names/generated/api/common.h"

#include <atomic>
#include <vector>
#include <map>
#include <functional>
#include <shared_mutex>

namespace Test {
namespace TbNames {

/**
 * The implementation of a NamesPublisher.
 * Use this class to store clients of the Names and inform them about the change
 * on call of the appropriate publish function.
 *
 * @warning This class is thread safe, but the subscribed classes or functions are not protected.
 */
class TEST_TB_NAMES_EXPORT NamesPublisher : public INamesPublisher
{
public:
    /**
    * Implementation of INamesPublisher::subscribeToAllChanges
    */
    void subscribeToAllChanges(INamesSubscriber& subscriber) override;
    /**
    * Implementation of INamesPublisher::unsubscribeFromAllChanges
    */
    void unsubscribeFromAllChanges(INamesSubscriber& subscriber) override;

    /**
    * Implementation of INamesPublisher::subscribeToSwitchChanged
    */
    long subscribeToSwitchChanged(NamesSwitchPropertyCb callback) override;
    /**
    * Implementation of INamesPublisher::subscribeToSwitchChanged
    */
    void unsubscribeFromSwitchChanged(long handleId) override;

    /**
    * Implementation of INamesPublisher::publishSwitchChanged
    */
    void publishSwitchChanged(bool Switch) const override;
private:
    // Subscribers informed about any property change or signal emitted in Names
    std::vector<std::reference_wrapper<INamesSubscriber>> m_allChangesSubscribers;
    // Mutex for m_allChangesSubscribers
    mutable std::shared_timed_mutex m_allChangesSubscribersMutex;
    // Next free unique identifier to subscribe for the Switch change.
    std::atomic<long> m_switchChangedCallbackNextId {0};
    // Subscribed callbacks for the Switch change.
    std::map<long, NamesSwitchPropertyCb> m_switchCallbacks;
    // Mutex for m_switchCallbacks
    mutable std::shared_timed_mutex m_switchCallbacksMutex;
};

} // namespace TbNames
} // namespace Test
