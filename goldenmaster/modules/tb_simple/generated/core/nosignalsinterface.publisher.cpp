

#include "tb_simple/generated/core/nosignalsinterface.publisher.h"
#include <algorithm>


using namespace Test::TbSimple;

void NoSignalsInterfacePublisher::subscribeToAllChanges(INoSignalsInterfaceSubscriber& subscriber)
{
    std::unique_lock<std::shared_timed_mutex> lock(m_allChangesSubscribersMutex);
    auto found = std::find_if(m_allChangesSubscribers.begin(), m_allChangesSubscribers.end(),
                        [&subscriber](const auto element){return &(element.get()) == &subscriber;});
    if (found == m_allChangesSubscribers.end())
    {
        m_allChangesSubscribers.push_back(std::reference_wrapper<INoSignalsInterfaceSubscriber>(subscriber));
    }
}

void NoSignalsInterfacePublisher::unsubscribeFromAllChanges(INoSignalsInterfaceSubscriber& subscriber)
{
    std::unique_lock<std::shared_timed_mutex> lock(m_allChangesSubscribersMutex);
    auto found = std::find_if(m_allChangesSubscribers.begin(), m_allChangesSubscribers.end(),
                        [&subscriber](const auto element){return &(element.get()) == &subscriber;});
    if (found != m_allChangesSubscribers.end())
    {
        m_allChangesSubscribers.erase(found);
    }
}

long NoSignalsInterfacePublisher::subscribeToPropBoolChanged(NoSignalsInterfacePropBoolPropertyCb callback)
{
    auto handleId = m_propBoolChangedCallbackNextId++;
    std::unique_lock<std::shared_timed_mutex> lock(m_propBoolCallbacksMutex);
    m_propBoolCallbacks[handleId] = callback;
    return handleId;
}

void NoSignalsInterfacePublisher::unsubscribeFromPropBoolChanged(long handleId)
{
    std::unique_lock<std::shared_timed_mutex> lock(m_propBoolCallbacksMutex);
    m_propBoolCallbacks.erase(handleId);
}

void NoSignalsInterfacePublisher::publishPropBoolChanged(bool propBool) const
{
    std::shared_lock<std::shared_timed_mutex> allChangesSubscribersLock(m_allChangesSubscribersMutex);
    const auto allChangesSubscribers = m_allChangesSubscribers;
    allChangesSubscribersLock.unlock();
    for(const auto& subscriber: allChangesSubscribers)
    {
        subscriber.get().onPropBoolChanged(propBool);
    }
    std::shared_lock<std::shared_timed_mutex> propBoolCallbacksLock(m_propBoolCallbacksMutex);
    const auto propBoolCallbacks = m_propBoolCallbacks;
    propBoolCallbacksLock.unlock();
    for(const auto& callbackEntry: propBoolCallbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(propBool);
        }
    }
}

long NoSignalsInterfacePublisher::subscribeToPropIntChanged(NoSignalsInterfacePropIntPropertyCb callback)
{
    auto handleId = m_propIntChangedCallbackNextId++;
    std::unique_lock<std::shared_timed_mutex> lock(m_propIntCallbacksMutex);
    m_propIntCallbacks[handleId] = callback;
    return handleId;
}

void NoSignalsInterfacePublisher::unsubscribeFromPropIntChanged(long handleId)
{
    std::unique_lock<std::shared_timed_mutex> lock(m_propIntCallbacksMutex);
    m_propIntCallbacks.erase(handleId);
}

void NoSignalsInterfacePublisher::publishPropIntChanged(int propInt) const
{
    std::shared_lock<std::shared_timed_mutex> allChangesSubscribersLock(m_allChangesSubscribersMutex);
    const auto allChangesSubscribers = m_allChangesSubscribers;
    allChangesSubscribersLock.unlock();
    for(const auto& subscriber: allChangesSubscribers)
    {
        subscriber.get().onPropIntChanged(propInt);
    }
    std::shared_lock<std::shared_timed_mutex> propIntCallbacksLock(m_propIntCallbacksMutex);
    const auto propIntCallbacks = m_propIntCallbacks;
    propIntCallbacksLock.unlock();
    for(const auto& callbackEntry: propIntCallbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(propInt);
        }
    }
}

