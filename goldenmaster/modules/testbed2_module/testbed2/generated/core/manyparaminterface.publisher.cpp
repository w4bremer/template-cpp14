

#include "testbed2/generated/core/manyparaminterface.publisher.h"
#include <algorithm>


using namespace Test::Testbed2;

void ManyParamInterfacePublisher::subscribeToAllChanges(IManyParamInterfaceSubscriber& subscriber)
{
    auto found = std::find_if(m_allChangesSubscribers.begin(), m_allChangesSubscribers.end(),
                        [&subscriber](const auto element){return &(element.get()) == &subscriber;});
    if (found == m_allChangesSubscribers.end())
    {
        m_allChangesSubscribers.push_back(std::reference_wrapper<IManyParamInterfaceSubscriber>(subscriber));
    }
}

void ManyParamInterfacePublisher::unsubscribeFromAllChanges(IManyParamInterfaceSubscriber& subscriber)
{
    auto found = std::find_if(m_allChangesSubscribers.begin(), m_allChangesSubscribers.end(),
                        [&subscriber](const auto element){return &(element.get()) == &subscriber;});
    if (found != m_allChangesSubscribers.end())
    {
        m_allChangesSubscribers.erase(found);
    }
}

long ManyParamInterfacePublisher::subscribeToProp1Changed(ManyParamInterfaceProp1PropertyCb callback)
{
    auto handleId = m_prop1ChangedCallbackNextId++;
    m_prop1Callbacks[handleId] = callback;
    return handleId;
}

void ManyParamInterfacePublisher::unsubscribeFromProp1Changed(long handleId)
{
    m_prop1Callbacks.erase(handleId);
}

void ManyParamInterfacePublisher::publishProp1Changed(int prop1) const
{
    for(const auto& subscriber: m_allChangesSubscribers)
    {
        subscriber.get().onProp1Changed(prop1);
    }
    for(const auto& callbackEntry: m_prop1Callbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(prop1);
        }
    }
}

long ManyParamInterfacePublisher::subscribeToProp2Changed(ManyParamInterfaceProp2PropertyCb callback)
{
    auto handleId = m_prop2ChangedCallbackNextId++;
    m_prop2Callbacks[handleId] = callback;
    return handleId;
}

void ManyParamInterfacePublisher::unsubscribeFromProp2Changed(long handleId)
{
    m_prop2Callbacks.erase(handleId);
}

void ManyParamInterfacePublisher::publishProp2Changed(int prop2) const
{
    for(const auto& subscriber: m_allChangesSubscribers)
    {
        subscriber.get().onProp2Changed(prop2);
    }
    for(const auto& callbackEntry: m_prop2Callbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(prop2);
        }
    }
}

long ManyParamInterfacePublisher::subscribeToProp3Changed(ManyParamInterfaceProp3PropertyCb callback)
{
    auto handleId = m_prop3ChangedCallbackNextId++;
    m_prop3Callbacks[handleId] = callback;
    return handleId;
}

void ManyParamInterfacePublisher::unsubscribeFromProp3Changed(long handleId)
{
    m_prop3Callbacks.erase(handleId);
}

void ManyParamInterfacePublisher::publishProp3Changed(int prop3) const
{
    for(const auto& subscriber: m_allChangesSubscribers)
    {
        subscriber.get().onProp3Changed(prop3);
    }
    for(const auto& callbackEntry: m_prop3Callbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(prop3);
        }
    }
}

long ManyParamInterfacePublisher::subscribeToProp4Changed(ManyParamInterfaceProp4PropertyCb callback)
{
    auto handleId = m_prop4ChangedCallbackNextId++;
    m_prop4Callbacks[handleId] = callback;
    return handleId;
}

void ManyParamInterfacePublisher::unsubscribeFromProp4Changed(long handleId)
{
    m_prop4Callbacks.erase(handleId);
}

void ManyParamInterfacePublisher::publishProp4Changed(int prop4) const
{
    for(const auto& subscriber: m_allChangesSubscribers)
    {
        subscriber.get().onProp4Changed(prop4);
    }
    for(const auto& callbackEntry: m_prop4Callbacks)
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
    m_sig1Callbacks[handleId] = callback;
    return handleId;
}

void ManyParamInterfacePublisher::unsubscribeFromSig1(long handleId)
{
    m_sig1Callbacks.erase(handleId);
}

void ManyParamInterfacePublisher::publishSig1(int param1) const
{
    for(const auto& subscriber: m_allChangesSubscribers)
    {
        subscriber.get().onSig1(param1);
    }
    for(const auto& callbackEntry: m_sig1Callbacks)
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
    m_sig2Callbacks[handleId] = callback;
    return handleId;
}

void ManyParamInterfacePublisher::unsubscribeFromSig2(long handleId)
{
    m_sig2Callbacks.erase(handleId);
}

void ManyParamInterfacePublisher::publishSig2(int param1, int param2) const
{
    for(const auto& subscriber: m_allChangesSubscribers)
    {
        subscriber.get().onSig2(param1, param2);
    }
    for(const auto& callbackEntry: m_sig2Callbacks)
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
    m_sig3Callbacks[handleId] = callback;
    return handleId;
}

void ManyParamInterfacePublisher::unsubscribeFromSig3(long handleId)
{
    m_sig3Callbacks.erase(handleId);
}

void ManyParamInterfacePublisher::publishSig3(int param1, int param2, int param3) const
{
    for(const auto& subscriber: m_allChangesSubscribers)
    {
        subscriber.get().onSig3(param1, param2, param3);
    }
    for(const auto& callbackEntry: m_sig3Callbacks)
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
    m_sig4Callbacks[handleId] = callback;
    return handleId;
}

void ManyParamInterfacePublisher::unsubscribeFromSig4(long handleId)
{
    m_sig4Callbacks.erase(handleId);
}

void ManyParamInterfacePublisher::publishSig4(int param1, int param2, int param3, int param4) const
{
    for(const auto& subscriber: m_allChangesSubscribers)
    {
        subscriber.get().onSig4(param1, param2, param3, param4);
    }
    for(const auto& callbackEntry: m_sig4Callbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(param1, param2, param3, param4);
        }
    }
}

