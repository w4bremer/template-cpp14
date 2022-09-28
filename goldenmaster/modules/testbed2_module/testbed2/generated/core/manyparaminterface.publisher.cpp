

#include "testbed2/generated/core/manyparaminterface.publisher.h"
#include <algorithm>


using namespace Test::Testbed2;

void ManyParamInterfacePublisher::subscribeToAllChanges(IManyParamInterfaceSubscriber& subscriber)
{
    std::unique_lock<std::shared_timed_mutex> lock(m_allChangesSubscribersMutex);
    auto found = std::find_if(m_allChangesSubscribers.begin(), m_allChangesSubscribers.end(),
                        [&subscriber](const auto element){return &(element.get()) == &subscriber;});
    if (found == m_allChangesSubscribers.end())
    {
        m_allChangesSubscribers.push_back(std::reference_wrapper<IManyParamInterfaceSubscriber>(subscriber));
    }
}

void ManyParamInterfacePublisher::unsubscribeFromAllChanges(IManyParamInterfaceSubscriber& subscriber)
{
    std::unique_lock<std::shared_timed_mutex> lock(m_allChangesSubscribersMutex);
    auto found = std::find_if(m_allChangesSubscribers.begin(), m_allChangesSubscribers.end(),
                        [&subscriber](const auto element){return &(element.get()) == &subscriber;});
    if (found != m_allChangesSubscribers.end())
    {
        m_allChangesSubscribers.erase(found);
    }
}

long ManyParamInterfacePublisher::subscribeToProp1Changed(ManyParamInterfaceProp1PropertyCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    auto handleId = m_prop1ChangedCallbackNextId++;
    std::unique_lock<std::shared_timed_mutex> lock(m_prop1CallbacksMutex);
    m_prop1Callbacks[handleId] = callback;
    return handleId;
}

void ManyParamInterfacePublisher::unsubscribeFromProp1Changed(long handleId)
{
    std::unique_lock<std::shared_timed_mutex> lock(m_prop1CallbacksMutex);
    m_prop1Callbacks.erase(handleId);
}

void ManyParamInterfacePublisher::publishProp1Changed(int prop1) const
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

long ManyParamInterfacePublisher::subscribeToProp2Changed(ManyParamInterfaceProp2PropertyCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    auto handleId = m_prop2ChangedCallbackNextId++;
    std::unique_lock<std::shared_timed_mutex> lock(m_prop2CallbacksMutex);
    m_prop2Callbacks[handleId] = callback;
    return handleId;
}

void ManyParamInterfacePublisher::unsubscribeFromProp2Changed(long handleId)
{
    std::unique_lock<std::shared_timed_mutex> lock(m_prop2CallbacksMutex);
    m_prop2Callbacks.erase(handleId);
}

void ManyParamInterfacePublisher::publishProp2Changed(int prop2) const
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

long ManyParamInterfacePublisher::subscribeToProp3Changed(ManyParamInterfaceProp3PropertyCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    auto handleId = m_prop3ChangedCallbackNextId++;
    std::unique_lock<std::shared_timed_mutex> lock(m_prop3CallbacksMutex);
    m_prop3Callbacks[handleId] = callback;
    return handleId;
}

void ManyParamInterfacePublisher::unsubscribeFromProp3Changed(long handleId)
{
    std::unique_lock<std::shared_timed_mutex> lock(m_prop3CallbacksMutex);
    m_prop3Callbacks.erase(handleId);
}

void ManyParamInterfacePublisher::publishProp3Changed(int prop3) const
{
    std::shared_lock<std::shared_timed_mutex> allChangesSubscribersLock(m_allChangesSubscribersMutex);
    const auto allChangesSubscribers = m_allChangesSubscribers;
    allChangesSubscribersLock.unlock();
    for(const auto& subscriber: allChangesSubscribers)
    {
        subscriber.get().onProp3Changed(prop3);
    }
    std::shared_lock<std::shared_timed_mutex> prop3CallbacksLock(m_prop3CallbacksMutex);
    const auto prop3Callbacks = m_prop3Callbacks;
    prop3CallbacksLock.unlock();
    for(const auto& callbackEntry: prop3Callbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(prop3);
        }
    }
}

long ManyParamInterfacePublisher::subscribeToProp4Changed(ManyParamInterfaceProp4PropertyCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    auto handleId = m_prop4ChangedCallbackNextId++;
    std::unique_lock<std::shared_timed_mutex> lock(m_prop4CallbacksMutex);
    m_prop4Callbacks[handleId] = callback;
    return handleId;
}

void ManyParamInterfacePublisher::unsubscribeFromProp4Changed(long handleId)
{
    std::unique_lock<std::shared_timed_mutex> lock(m_prop4CallbacksMutex);
    m_prop4Callbacks.erase(handleId);
}

void ManyParamInterfacePublisher::publishProp4Changed(int prop4) const
{
    std::shared_lock<std::shared_timed_mutex> allChangesSubscribersLock(m_allChangesSubscribersMutex);
    const auto allChangesSubscribers = m_allChangesSubscribers;
    allChangesSubscribersLock.unlock();
    for(const auto& subscriber: allChangesSubscribers)
    {
        subscriber.get().onProp4Changed(prop4);
    }
    std::shared_lock<std::shared_timed_mutex> prop4CallbacksLock(m_prop4CallbacksMutex);
    const auto prop4Callbacks = m_prop4Callbacks;
    prop4CallbacksLock.unlock();
    for(const auto& callbackEntry: prop4Callbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(prop4);
        }
    }
}

long ManyParamInterfacePublisher::subscribeToSig1(ManyParamInterfaceSig1SignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    auto handleId = m_sig1SignalCallbackNextId++;
    std::unique_lock<std::shared_timed_mutex> lock(m_sig1CallbacksMutex);
    m_sig1Callbacks[handleId] = callback;
    return handleId;
}

void ManyParamInterfacePublisher::unsubscribeFromSig1(long handleId)
{
    std::unique_lock<std::shared_timed_mutex> lock(m_sig1CallbacksMutex);
    m_sig1Callbacks.erase(handleId);
}

void ManyParamInterfacePublisher::publishSig1(int param1) const
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

long ManyParamInterfacePublisher::subscribeToSig2(ManyParamInterfaceSig2SignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    auto handleId = m_sig2SignalCallbackNextId++;
    std::unique_lock<std::shared_timed_mutex> lock(m_sig2CallbacksMutex);
    m_sig2Callbacks[handleId] = callback;
    return handleId;
}

void ManyParamInterfacePublisher::unsubscribeFromSig2(long handleId)
{
    std::unique_lock<std::shared_timed_mutex> lock(m_sig2CallbacksMutex);
    m_sig2Callbacks.erase(handleId);
}

void ManyParamInterfacePublisher::publishSig2(int param1, int param2) const
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

long ManyParamInterfacePublisher::subscribeToSig3(ManyParamInterfaceSig3SignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    auto handleId = m_sig3SignalCallbackNextId++;
    std::unique_lock<std::shared_timed_mutex> lock(m_sig3CallbacksMutex);
    m_sig3Callbacks[handleId] = callback;
    return handleId;
}

void ManyParamInterfacePublisher::unsubscribeFromSig3(long handleId)
{
    std::unique_lock<std::shared_timed_mutex> lock(m_sig3CallbacksMutex);
    m_sig3Callbacks.erase(handleId);
}

void ManyParamInterfacePublisher::publishSig3(int param1, int param2, int param3) const
{
    std::shared_lock<std::shared_timed_mutex> allChangesSubscribersLock(m_allChangesSubscribersMutex);
    const auto allChangesSubscribers = m_allChangesSubscribers;
    allChangesSubscribersLock.unlock();
    for(const auto& subscriber: allChangesSubscribers)
    {
        subscriber.get().onSig3(param1, param2, param3);
    }
    std::shared_lock<std::shared_timed_mutex> sig3CallbacksLock(m_sig3CallbacksMutex);
    const auto sig3Callbacks = m_sig3Callbacks;
    sig3CallbacksLock.unlock();
    for(const auto& callbackEntry: sig3Callbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(param1, param2, param3);
        }
    }
}

long ManyParamInterfacePublisher::subscribeToSig4(ManyParamInterfaceSig4SignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    auto handleId = m_sig4SignalCallbackNextId++;
    std::unique_lock<std::shared_timed_mutex> lock(m_sig4CallbacksMutex);
    m_sig4Callbacks[handleId] = callback;
    return handleId;
}

void ManyParamInterfacePublisher::unsubscribeFromSig4(long handleId)
{
    std::unique_lock<std::shared_timed_mutex> lock(m_sig4CallbacksMutex);
    m_sig4Callbacks.erase(handleId);
}

void ManyParamInterfacePublisher::publishSig4(int param1, int param2, int param3, int param4) const
{
    std::shared_lock<std::shared_timed_mutex> allChangesSubscribersLock(m_allChangesSubscribersMutex);
    const auto allChangesSubscribers = m_allChangesSubscribers;
    allChangesSubscribersLock.unlock();
    for(const auto& subscriber: allChangesSubscribers)
    {
        subscriber.get().onSig4(param1, param2, param3, param4);
    }
    std::shared_lock<std::shared_timed_mutex> sig4CallbacksLock(m_sig4CallbacksMutex);
    const auto sig4Callbacks = m_sig4Callbacks;
    sig4CallbacksLock.unlock();
    for(const auto& callbackEntry: sig4Callbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(param1, param2, param3, param4);
        }
    }
}

