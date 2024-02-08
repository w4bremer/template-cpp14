

#include "tb_simple/generated/core/voidinterface.publisher.h"
#include <algorithm>


using namespace Test::TbSimple;

void VoidInterfacePublisher::subscribeToAllChanges(IVoidInterfaceSubscriber& subscriber)
{
    std::unique_lock<std::shared_timed_mutex> lock(m_allChangesSubscribersMutex);
    auto found = std::find_if(m_allChangesSubscribers.begin(), m_allChangesSubscribers.end(),
                        [&subscriber](const auto element){return &(element.get()) == &subscriber;});
    if (found == m_allChangesSubscribers.end())
    {
        m_allChangesSubscribers.push_back(std::reference_wrapper<IVoidInterfaceSubscriber>(subscriber));
    }
}

void VoidInterfacePublisher::unsubscribeFromAllChanges(IVoidInterfaceSubscriber& subscriber)
{
    std::unique_lock<std::shared_timed_mutex> lock(m_allChangesSubscribersMutex);
    auto found = std::find_if(m_allChangesSubscribers.begin(), m_allChangesSubscribers.end(),
                        [&subscriber](const auto element){return &(element.get()) == &subscriber;});
    if (found != m_allChangesSubscribers.end())
    {
        m_allChangesSubscribers.erase(found);
    }
}

long VoidInterfacePublisher::subscribeToSigVoid(VoidInterfaceSigVoidSignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    auto handleId = m_sigVoidSignalCallbackNextId++;
    std::unique_lock<std::shared_timed_mutex> lock(m_sigVoidCallbacksMutex);
    m_sigVoidCallbacks[handleId] = callback;
    return handleId;
}

void VoidInterfacePublisher::unsubscribeFromSigVoid(long handleId)
{
    std::unique_lock<std::shared_timed_mutex> lock(m_sigVoidCallbacksMutex);
    m_sigVoidCallbacks.erase(handleId);
}

void VoidInterfacePublisher::publishSigVoid() const
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

