

#include "tb_names/generated/core/names.publisher.h"
#include <algorithm>


using namespace Test::TbNames;

void NamesPublisher::subscribeToAllChanges(INamesSubscriber& subscriber)
{
    std::unique_lock<std::shared_timed_mutex> lock(m_allChangesSubscribersMutex);
    auto found = std::find_if(m_allChangesSubscribers.begin(), m_allChangesSubscribers.end(),
                        [&subscriber](const auto element){return &(element.get()) == &subscriber;});
    if (found == m_allChangesSubscribers.end())
    {
        m_allChangesSubscribers.push_back(std::reference_wrapper<INamesSubscriber>(subscriber));
    }
}

void NamesPublisher::unsubscribeFromAllChanges(INamesSubscriber& subscriber)
{
    std::unique_lock<std::shared_timed_mutex> lock(m_allChangesSubscribersMutex);
    auto found = std::find_if(m_allChangesSubscribers.begin(), m_allChangesSubscribers.end(),
                        [&subscriber](const auto element){return &(element.get()) == &subscriber;});
    if (found != m_allChangesSubscribers.end())
    {
        m_allChangesSubscribers.erase(found);
    }
}

long NamesPublisher::subscribeToSwitchChanged(NamesSwitchPropertyCb callback)
{
    auto handleId = m_switchChangedCallbackNextId++;
    std::unique_lock<std::shared_timed_mutex> lock(m_switchCallbacksMutex);
    m_switchCallbacks[handleId] = callback;
    return handleId;
}

void NamesPublisher::unsubscribeFromSwitchChanged(long handleId)
{
    std::unique_lock<std::shared_timed_mutex> lock(m_switchCallbacksMutex);
    m_switchCallbacks.erase(handleId);
}

void NamesPublisher::publishSwitchChanged(bool Switch) const
{
    std::shared_lock<std::shared_timed_mutex> allChangesSubscribersLock(m_allChangesSubscribersMutex);
    const auto allChangesSubscribers = m_allChangesSubscribers;
    allChangesSubscribersLock.unlock();
    for(const auto& subscriber: allChangesSubscribers)
    {
        subscriber.get().onSwitchChanged(Switch);
    }
    std::shared_lock<std::shared_timed_mutex> switchCallbacksLock(m_switchCallbacksMutex);
    const auto switchCallbacks = m_switchCallbacks;
    switchCallbacksLock.unlock();
    for(const auto& callbackEntry: switchCallbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(Switch);
        }
    }
}

