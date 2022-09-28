

#include "testbed2/generated/core/nestedstruct2interface.publisher.h"
#include <algorithm>


using namespace Test::Testbed2;

void NestedStruct2InterfacePublisher::subscribeToAllChanges(INestedStruct2InterfaceSubscriber& subscriber)
{
    std::unique_lock<std::shared_timed_mutex> lock(m_allChangesSubscribersMutex);
    auto found = std::find_if(m_allChangesSubscribers.begin(), m_allChangesSubscribers.end(),
                        [&subscriber](const auto element){return &(element.get()) == &subscriber;});
    if (found == m_allChangesSubscribers.end())
    {
        m_allChangesSubscribers.push_back(std::reference_wrapper<INestedStruct2InterfaceSubscriber>(subscriber));
    }
}

void NestedStruct2InterfacePublisher::unsubscribeFromAllChanges(INestedStruct2InterfaceSubscriber& subscriber)
{
    std::unique_lock<std::shared_timed_mutex> lock(m_allChangesSubscribersMutex);
    auto found = std::find_if(m_allChangesSubscribers.begin(), m_allChangesSubscribers.end(),
                        [&subscriber](const auto element){return &(element.get()) == &subscriber;});
    if (found != m_allChangesSubscribers.end())
    {
        m_allChangesSubscribers.erase(found);
    }
}

long NestedStruct2InterfacePublisher::subscribeToProp1Changed(NestedStruct2InterfaceProp1PropertyCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    auto handleId = m_prop1ChangedCallbackNextId++;
    std::unique_lock<std::shared_timed_mutex> lock(m_prop1CallbacksMutex);
    m_prop1Callbacks[handleId] = callback;
    return handleId;
}

void NestedStruct2InterfacePublisher::unsubscribeFromProp1Changed(long handleId)
{
    std::unique_lock<std::shared_timed_mutex> lock(m_prop1CallbacksMutex);
    m_prop1Callbacks.erase(handleId);
}

void NestedStruct2InterfacePublisher::publishProp1Changed(const NestedStruct1& prop1) const
{
    std::shared_lock<std::shared_timed_mutex> allChangesSubscribersLock(m_allChangesSubscribersMutex);
    const auto allChangesSubscribers = m_allChangesSubscribers;
    allChangesSubscribersLock.unlock();
    for(const auto& subscriber: allChangesSubscribers)
    {
        subscriber.get().onProp1Changed(prop1);
    }
    std::shared_lock<std::shared_timed_mutex> prop1CallbacksLock(m_prop1CallbacksMutex);
    const auto prop1Callbacks = m_prop1Callbacks;
    prop1CallbacksLock.unlock();
    for(const auto& callbackEntry: prop1Callbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(prop1);
        }
    }
}

long NestedStruct2InterfacePublisher::subscribeToProp2Changed(NestedStruct2InterfaceProp2PropertyCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    auto handleId = m_prop2ChangedCallbackNextId++;
    std::unique_lock<std::shared_timed_mutex> lock(m_prop2CallbacksMutex);
    m_prop2Callbacks[handleId] = callback;
    return handleId;
}

void NestedStruct2InterfacePublisher::unsubscribeFromProp2Changed(long handleId)
{
    std::unique_lock<std::shared_timed_mutex> lock(m_prop2CallbacksMutex);
    m_prop2Callbacks.erase(handleId);
}

void NestedStruct2InterfacePublisher::publishProp2Changed(const NestedStruct2& prop2) const
{
    std::shared_lock<std::shared_timed_mutex> allChangesSubscribersLock(m_allChangesSubscribersMutex);
    const auto allChangesSubscribers = m_allChangesSubscribers;
    allChangesSubscribersLock.unlock();
    for(const auto& subscriber: allChangesSubscribers)
    {
        subscriber.get().onProp2Changed(prop2);
    }
    std::shared_lock<std::shared_timed_mutex> prop2CallbacksLock(m_prop2CallbacksMutex);
    const auto prop2Callbacks = m_prop2Callbacks;
    prop2CallbacksLock.unlock();
    for(const auto& callbackEntry: prop2Callbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(prop2);
        }
    }
}

long NestedStruct2InterfacePublisher::subscribeToSig1(NestedStruct2InterfaceSig1SignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    auto handleId = m_sig1SignalCallbackNextId++;
    std::unique_lock<std::shared_timed_mutex> lock(m_sig1CallbacksMutex);
    m_sig1Callbacks[handleId] = callback;
    return handleId;
}

void NestedStruct2InterfacePublisher::unsubscribeFromSig1(long handleId)
{
    std::unique_lock<std::shared_timed_mutex> lock(m_sig1CallbacksMutex);
    m_sig1Callbacks.erase(handleId);
}

void NestedStruct2InterfacePublisher::publishSig1(const NestedStruct1& param1) const
{
    std::shared_lock<std::shared_timed_mutex> allChangesSubscribersLock(m_allChangesSubscribersMutex);
    const auto allChangesSubscribers = m_allChangesSubscribers;
    allChangesSubscribersLock.unlock();
    for(const auto& subscriber: allChangesSubscribers)
    {
        subscriber.get().onSig1(param1);
    }
    std::shared_lock<std::shared_timed_mutex> sig1CallbacksLock(m_sig1CallbacksMutex);
    const auto sig1Callbacks = m_sig1Callbacks;
    sig1CallbacksLock.unlock();
    for(const auto& callbackEntry: sig1Callbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(param1);
        }
    }
}

long NestedStruct2InterfacePublisher::subscribeToSig2(NestedStruct2InterfaceSig2SignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    auto handleId = m_sig2SignalCallbackNextId++;
    std::unique_lock<std::shared_timed_mutex> lock(m_sig2CallbacksMutex);
    m_sig2Callbacks[handleId] = callback;
    return handleId;
}

void NestedStruct2InterfacePublisher::unsubscribeFromSig2(long handleId)
{
    std::unique_lock<std::shared_timed_mutex> lock(m_sig2CallbacksMutex);
    m_sig2Callbacks.erase(handleId);
}

void NestedStruct2InterfacePublisher::publishSig2(const NestedStruct1& param1, const NestedStruct2& param2) const
{
    std::shared_lock<std::shared_timed_mutex> allChangesSubscribersLock(m_allChangesSubscribersMutex);
    const auto allChangesSubscribers = m_allChangesSubscribers;
    allChangesSubscribersLock.unlock();
    for(const auto& subscriber: allChangesSubscribers)
    {
        subscriber.get().onSig2(param1, param2);
    }
    std::shared_lock<std::shared_timed_mutex> sig2CallbacksLock(m_sig2CallbacksMutex);
    const auto sig2Callbacks = m_sig2Callbacks;
    sig2CallbacksLock.unlock();
    for(const auto& callbackEntry: sig2Callbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(param1, param2);
        }
    }
}

