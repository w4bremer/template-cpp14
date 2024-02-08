

#include "tb_simple/generated/core/nooperationsinterface.publisher.h"
#include <algorithm>


using namespace Test::TbSimple;

void NoOperationsInterfacePublisher::subscribeToAllChanges(INoOperationsInterfaceSubscriber& subscriber)
{
    std::unique_lock<std::shared_timed_mutex> lock(m_allChangesSubscribersMutex);
    auto found = std::find_if(m_allChangesSubscribers.begin(), m_allChangesSubscribers.end(),
                        [&subscriber](const auto element){return &(element.get()) == &subscriber;});
    if (found == m_allChangesSubscribers.end())
    {
        m_allChangesSubscribers.push_back(std::reference_wrapper<INoOperationsInterfaceSubscriber>(subscriber));
    }
}

void NoOperationsInterfacePublisher::unsubscribeFromAllChanges(INoOperationsInterfaceSubscriber& subscriber)
{
    std::unique_lock<std::shared_timed_mutex> lock(m_allChangesSubscribersMutex);
    auto found = std::find_if(m_allChangesSubscribers.begin(), m_allChangesSubscribers.end(),
                        [&subscriber](const auto element){return &(element.get()) == &subscriber;});
    if (found != m_allChangesSubscribers.end())
    {
        m_allChangesSubscribers.erase(found);
    }
}

long NoOperationsInterfacePublisher::subscribeToPropBoolChanged(NoOperationsInterfacePropBoolPropertyCb callback)
{
    auto handleId = m_propBoolChangedCallbackNextId++;
    std::unique_lock<std::shared_timed_mutex> lock(m_propBoolCallbacksMutex);
    m_propBoolCallbacks[handleId] = callback;
    return handleId;
}

void NoOperationsInterfacePublisher::unsubscribeFromPropBoolChanged(long handleId)
{
    std::unique_lock<std::shared_timed_mutex> lock(m_propBoolCallbacksMutex);
    m_propBoolCallbacks.erase(handleId);
}

void NoOperationsInterfacePublisher::publishPropBoolChanged(bool propBool) const
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

long NoOperationsInterfacePublisher::subscribeToPropIntChanged(NoOperationsInterfacePropIntPropertyCb callback)
{
    auto handleId = m_propIntChangedCallbackNextId++;
    std::unique_lock<std::shared_timed_mutex> lock(m_propIntCallbacksMutex);
    m_propIntCallbacks[handleId] = callback;
    return handleId;
}

void NoOperationsInterfacePublisher::unsubscribeFromPropIntChanged(long handleId)
{
    std::unique_lock<std::shared_timed_mutex> lock(m_propIntCallbacksMutex);
    m_propIntCallbacks.erase(handleId);
}

void NoOperationsInterfacePublisher::publishPropIntChanged(int propInt) const
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

long NoOperationsInterfacePublisher::subscribeToSigVoid(NoOperationsInterfaceSigVoidSignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    auto handleId = m_sigVoidSignalCallbackNextId++;
    std::unique_lock<std::shared_timed_mutex> lock(m_sigVoidCallbacksMutex);
    m_sigVoidCallbacks[handleId] = callback;
    return handleId;
}

void NoOperationsInterfacePublisher::unsubscribeFromSigVoid(long handleId)
{
    std::unique_lock<std::shared_timed_mutex> lock(m_sigVoidCallbacksMutex);
    m_sigVoidCallbacks.erase(handleId);
}

void NoOperationsInterfacePublisher::publishSigVoid() const
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

long NoOperationsInterfacePublisher::subscribeToSigBool(NoOperationsInterfaceSigBoolSignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    auto handleId = m_sigBoolSignalCallbackNextId++;
    std::unique_lock<std::shared_timed_mutex> lock(m_sigBoolCallbacksMutex);
    m_sigBoolCallbacks[handleId] = callback;
    return handleId;
}

void NoOperationsInterfacePublisher::unsubscribeFromSigBool(long handleId)
{
    std::unique_lock<std::shared_timed_mutex> lock(m_sigBoolCallbacksMutex);
    m_sigBoolCallbacks.erase(handleId);
}

void NoOperationsInterfacePublisher::publishSigBool(bool paramBool) const
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

