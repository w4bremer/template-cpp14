

#include "tb_simple/generated/core/nopropertiesinterface.publisher.h"
#include <algorithm>


using namespace Test::TbSimple;

void NoPropertiesInterfacePublisher::subscribeToAllChanges(INoPropertiesInterfaceSubscriber& subscriber)
{
    std::unique_lock<std::shared_timed_mutex> lock(m_allChangesSubscribersMutex);
    auto found = std::find_if(m_allChangesSubscribers.begin(), m_allChangesSubscribers.end(),
                        [&subscriber](const auto element){return &(element.get()) == &subscriber;});
    if (found == m_allChangesSubscribers.end())
    {
        m_allChangesSubscribers.push_back(std::reference_wrapper<INoPropertiesInterfaceSubscriber>(subscriber));
    }
}

void NoPropertiesInterfacePublisher::unsubscribeFromAllChanges(INoPropertiesInterfaceSubscriber& subscriber)
{
    std::unique_lock<std::shared_timed_mutex> lock(m_allChangesSubscribersMutex);
    auto found = std::find_if(m_allChangesSubscribers.begin(), m_allChangesSubscribers.end(),
                        [&subscriber](const auto element){return &(element.get()) == &subscriber;});
    if (found != m_allChangesSubscribers.end())
    {
        m_allChangesSubscribers.erase(found);
    }
}

long NoPropertiesInterfacePublisher::subscribeToSigVoid(NoPropertiesInterfaceSigVoidSignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    auto handleId = m_sigVoidSignalCallbackNextId++;
    std::unique_lock<std::shared_timed_mutex> lock(m_sigVoidCallbacksMutex);
    m_sigVoidCallbacks[handleId] = callback;
    return handleId;
}

void NoPropertiesInterfacePublisher::unsubscribeFromSigVoid(long handleId)
{
    std::unique_lock<std::shared_timed_mutex> lock(m_sigVoidCallbacksMutex);
    m_sigVoidCallbacks.erase(handleId);
}

void NoPropertiesInterfacePublisher::publishSigVoid() const
{
    std::shared_lock<std::shared_timed_mutex> allChangesSubscribersLock(m_allChangesSubscribersMutex);
    const auto allChangesSubscribers = m_allChangesSubscribers;
    allChangesSubscribersLock.unlock();
    for(const auto& subscriber: allChangesSubscribers)
    {
        subscriber.get().onSigVoid();
    }
    std::shared_lock<std::shared_timed_mutex> sigVoidCallbacksLock(m_sigVoidCallbacksMutex);
    const auto sigVoidCallbacks = m_sigVoidCallbacks;
    sigVoidCallbacksLock.unlock();
    for(const auto& callbackEntry: sigVoidCallbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second();
        }
    }
}

long NoPropertiesInterfacePublisher::subscribeToSigBool(NoPropertiesInterfaceSigBoolSignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    auto handleId = m_sigBoolSignalCallbackNextId++;
    std::unique_lock<std::shared_timed_mutex> lock(m_sigBoolCallbacksMutex);
    m_sigBoolCallbacks[handleId] = callback;
    return handleId;
}

void NoPropertiesInterfacePublisher::unsubscribeFromSigBool(long handleId)
{
    std::unique_lock<std::shared_timed_mutex> lock(m_sigBoolCallbacksMutex);
    m_sigBoolCallbacks.erase(handleId);
}

void NoPropertiesInterfacePublisher::publishSigBool(bool paramBool) const
{
    std::shared_lock<std::shared_timed_mutex> allChangesSubscribersLock(m_allChangesSubscribersMutex);
    const auto allChangesSubscribers = m_allChangesSubscribers;
    allChangesSubscribersLock.unlock();
    for(const auto& subscriber: allChangesSubscribers)
    {
        subscriber.get().onSigBool(paramBool);
    }
    std::shared_lock<std::shared_timed_mutex> sigBoolCallbacksLock(m_sigBoolCallbacksMutex);
    const auto sigBoolCallbacks = m_sigBoolCallbacks;
    sigBoolCallbacksLock.unlock();
    for(const auto& callbackEntry: sigBoolCallbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(paramBool);
        }
    }
}

