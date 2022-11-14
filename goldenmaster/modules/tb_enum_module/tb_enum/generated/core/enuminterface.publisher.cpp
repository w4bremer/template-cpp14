

#include "tb_enum/generated/core/enuminterface.publisher.h"
#include <algorithm>


using namespace Test::TbEnum;

void EnumInterfacePublisher::subscribeToAllChanges(IEnumInterfaceSubscriber& subscriber)
{
    std::unique_lock<std::shared_timed_mutex> lock(m_allChangesSubscribersMutex);
    auto found = std::find_if(m_allChangesSubscribers.begin(), m_allChangesSubscribers.end(),
                        [&subscriber](const auto element){return &(element.get()) == &subscriber;});
    if (found == m_allChangesSubscribers.end())
    {
        m_allChangesSubscribers.push_back(std::reference_wrapper<IEnumInterfaceSubscriber>(subscriber));
    }
}

void EnumInterfacePublisher::unsubscribeFromAllChanges(IEnumInterfaceSubscriber& subscriber)
{
    std::unique_lock<std::shared_timed_mutex> lock(m_allChangesSubscribersMutex);
    auto found = std::find_if(m_allChangesSubscribers.begin(), m_allChangesSubscribers.end(),
                        [&subscriber](const auto element){return &(element.get()) == &subscriber;});
    if (found != m_allChangesSubscribers.end())
    {
        m_allChangesSubscribers.erase(found);
    }
}

long EnumInterfacePublisher::subscribeToProp0Changed(EnumInterfaceProp0PropertyCb callback)
{
    auto handleId = m_prop0ChangedCallbackNextId++;
    std::unique_lock<std::shared_timed_mutex> lock(m_prop0CallbacksMutex);
    m_prop0Callbacks[handleId] = callback;
    return handleId;
}

void EnumInterfacePublisher::unsubscribeFromProp0Changed(long handleId)
{
    std::unique_lock<std::shared_timed_mutex> lock(m_prop0CallbacksMutex);
    m_prop0Callbacks.erase(handleId);
}

void EnumInterfacePublisher::publishProp0Changed(Enum0Enum prop0) const
{
    std::shared_lock<std::shared_timed_mutex> allChangesSubscribersLock(m_allChangesSubscribersMutex);
    const auto allChangesSubscribers = m_allChangesSubscribers;
    allChangesSubscribersLock.unlock();
    for(const auto& subscriber: allChangesSubscribers)
    {
        subscriber.get().onProp0Changed(prop0);
    }
    std::shared_lock<std::shared_timed_mutex> prop0CallbacksLock(m_prop0CallbacksMutex);
    const auto prop0Callbacks = m_prop0Callbacks;
    prop0CallbacksLock.unlock();
    for(const auto& callbackEntry: prop0Callbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(prop0);
        }
    }
}

long EnumInterfacePublisher::subscribeToProp1Changed(EnumInterfaceProp1PropertyCb callback)
{
    auto handleId = m_prop1ChangedCallbackNextId++;
    std::unique_lock<std::shared_timed_mutex> lock(m_prop1CallbacksMutex);
    m_prop1Callbacks[handleId] = callback;
    return handleId;
}

void EnumInterfacePublisher::unsubscribeFromProp1Changed(long handleId)
{
    std::unique_lock<std::shared_timed_mutex> lock(m_prop1CallbacksMutex);
    m_prop1Callbacks.erase(handleId);
}

void EnumInterfacePublisher::publishProp1Changed(Enum1Enum prop1) const
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

long EnumInterfacePublisher::subscribeToProp2Changed(EnumInterfaceProp2PropertyCb callback)
{
    auto handleId = m_prop2ChangedCallbackNextId++;
    std::unique_lock<std::shared_timed_mutex> lock(m_prop2CallbacksMutex);
    m_prop2Callbacks[handleId] = callback;
    return handleId;
}

void EnumInterfacePublisher::unsubscribeFromProp2Changed(long handleId)
{
    std::unique_lock<std::shared_timed_mutex> lock(m_prop2CallbacksMutex);
    m_prop2Callbacks.erase(handleId);
}

void EnumInterfacePublisher::publishProp2Changed(Enum2Enum prop2) const
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

long EnumInterfacePublisher::subscribeToProp3Changed(EnumInterfaceProp3PropertyCb callback)
{
    auto handleId = m_prop3ChangedCallbackNextId++;
    std::unique_lock<std::shared_timed_mutex> lock(m_prop3CallbacksMutex);
    m_prop3Callbacks[handleId] = callback;
    return handleId;
}

void EnumInterfacePublisher::unsubscribeFromProp3Changed(long handleId)
{
    std::unique_lock<std::shared_timed_mutex> lock(m_prop3CallbacksMutex);
    m_prop3Callbacks.erase(handleId);
}

void EnumInterfacePublisher::publishProp3Changed(Enum3Enum prop3) const
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

long EnumInterfacePublisher::subscribeToSig0(EnumInterfaceSig0SignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    auto handleId = m_sig0SignalCallbackNextId++;
    std::unique_lock<std::shared_timed_mutex> lock(m_sig0CallbacksMutex);
    m_sig0Callbacks[handleId] = callback;
    return handleId;
}

void EnumInterfacePublisher::unsubscribeFromSig0(long handleId)
{
    std::unique_lock<std::shared_timed_mutex> lock(m_sig0CallbacksMutex);
    m_sig0Callbacks.erase(handleId);
}

void EnumInterfacePublisher::publishSig0(Enum0Enum param0) const
{
    std::shared_lock<std::shared_timed_mutex> allChangesSubscribersLock(m_allChangesSubscribersMutex);
    const auto allChangesSubscribers = m_allChangesSubscribers;
    allChangesSubscribersLock.unlock();
    for(const auto& subscriber: allChangesSubscribers)
    {
        subscriber.get().onSig0(param0);
    }
    std::shared_lock<std::shared_timed_mutex> sig0CallbacksLock(m_sig0CallbacksMutex);
    const auto sig0Callbacks = m_sig0Callbacks;
    sig0CallbacksLock.unlock();
    for(const auto& callbackEntry: sig0Callbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(param0);
        }
    }
}

long EnumInterfacePublisher::subscribeToSig1(EnumInterfaceSig1SignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    auto handleId = m_sig1SignalCallbackNextId++;
    std::unique_lock<std::shared_timed_mutex> lock(m_sig1CallbacksMutex);
    m_sig1Callbacks[handleId] = callback;
    return handleId;
}

void EnumInterfacePublisher::unsubscribeFromSig1(long handleId)
{
    std::unique_lock<std::shared_timed_mutex> lock(m_sig1CallbacksMutex);
    m_sig1Callbacks.erase(handleId);
}

void EnumInterfacePublisher::publishSig1(Enum1Enum param1) const
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

long EnumInterfacePublisher::subscribeToSig2(EnumInterfaceSig2SignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    auto handleId = m_sig2SignalCallbackNextId++;
    std::unique_lock<std::shared_timed_mutex> lock(m_sig2CallbacksMutex);
    m_sig2Callbacks[handleId] = callback;
    return handleId;
}

void EnumInterfacePublisher::unsubscribeFromSig2(long handleId)
{
    std::unique_lock<std::shared_timed_mutex> lock(m_sig2CallbacksMutex);
    m_sig2Callbacks.erase(handleId);
}

void EnumInterfacePublisher::publishSig2(Enum2Enum param2) const
{
    std::shared_lock<std::shared_timed_mutex> allChangesSubscribersLock(m_allChangesSubscribersMutex);
    const auto allChangesSubscribers = m_allChangesSubscribers;
    allChangesSubscribersLock.unlock();
    for(const auto& subscriber: allChangesSubscribers)
    {
        subscriber.get().onSig2(param2);
    }
    std::shared_lock<std::shared_timed_mutex> sig2CallbacksLock(m_sig2CallbacksMutex);
    const auto sig2Callbacks = m_sig2Callbacks;
    sig2CallbacksLock.unlock();
    for(const auto& callbackEntry: sig2Callbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(param2);
        }
    }
}

long EnumInterfacePublisher::subscribeToSig3(EnumInterfaceSig3SignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    auto handleId = m_sig3SignalCallbackNextId++;
    std::unique_lock<std::shared_timed_mutex> lock(m_sig3CallbacksMutex);
    m_sig3Callbacks[handleId] = callback;
    return handleId;
}

void EnumInterfacePublisher::unsubscribeFromSig3(long handleId)
{
    std::unique_lock<std::shared_timed_mutex> lock(m_sig3CallbacksMutex);
    m_sig3Callbacks.erase(handleId);
}

void EnumInterfacePublisher::publishSig3(Enum3Enum param3) const
{
    std::shared_lock<std::shared_timed_mutex> allChangesSubscribersLock(m_allChangesSubscribersMutex);
    const auto allChangesSubscribers = m_allChangesSubscribers;
    allChangesSubscribersLock.unlock();
    for(const auto& subscriber: allChangesSubscribers)
    {
        subscriber.get().onSig3(param3);
    }
    std::shared_lock<std::shared_timed_mutex> sig3CallbacksLock(m_sig3CallbacksMutex);
    const auto sig3Callbacks = m_sig3Callbacks;
    sig3CallbacksLock.unlock();
    for(const auto& callbackEntry: sig3Callbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(param3);
        }
    }
}

