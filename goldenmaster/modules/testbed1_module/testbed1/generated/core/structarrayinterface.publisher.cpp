

#include "testbed1/generated/core/structarrayinterface.publisher.h"
#include <algorithm>


using namespace Test::Testbed1;

void StructArrayInterfacePublisher::subscribeToAllChanges(IStructArrayInterfaceSubscriber& subscriber)
{
    auto found = std::find_if(m_allChangesSubscribers.begin(), m_allChangesSubscribers.end(),
                        [&subscriber](const auto element){return &(element.get()) == &subscriber;});
    if (found == m_allChangesSubscribers.end())
    {
        m_allChangesSubscribers.push_back(std::reference_wrapper<IStructArrayInterfaceSubscriber>(subscriber));
    }
}

void StructArrayInterfacePublisher::unsubscribeFromAllChanges(IStructArrayInterfaceSubscriber& subscriber)
{
    auto found = std::find_if(m_allChangesSubscribers.begin(), m_allChangesSubscribers.end(),
                        [&subscriber](const auto element){return &(element.get()) == &subscriber;});
    if (found != m_allChangesSubscribers.end())
    {
        m_allChangesSubscribers.erase(found);
    }
}

long StructArrayInterfacePublisher::subscribeToPropBoolChanged(StructArrayInterfacePropBoolPropertyCb callback)
{
    auto handleId = m_propBoolChangedCallbackNextId++;
    m_propBoolCallbacks[handleId] = callback;
    return handleId;
}

void StructArrayInterfacePublisher::unsubscribeFromPropBoolChanged(long handleId)
{
    m_propBoolCallbacks.erase(handleId);
}

void StructArrayInterfacePublisher::publishPropBoolChanged(const std::list<StructBool>& propBool) const
{
    for(const auto& subscriber: m_allChangesSubscribers)
    {
        subscriber.get().onPropBoolChanged(propBool);
    }
    for(const auto& callbackEntry: m_propBoolCallbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(propBool);
        }
    }
}

long StructArrayInterfacePublisher::subscribeToPropIntChanged(StructArrayInterfacePropIntPropertyCb callback)
{
    auto handleId = m_propIntChangedCallbackNextId++;
    m_propIntCallbacks[handleId] = callback;
    return handleId;
}

void StructArrayInterfacePublisher::unsubscribeFromPropIntChanged(long handleId)
{
    m_propIntCallbacks.erase(handleId);
}

void StructArrayInterfacePublisher::publishPropIntChanged(const std::list<StructInt>& propInt) const
{
    for(const auto& subscriber: m_allChangesSubscribers)
    {
        subscriber.get().onPropIntChanged(propInt);
    }
    for(const auto& callbackEntry: m_propIntCallbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(propInt);
        }
    }
}

long StructArrayInterfacePublisher::subscribeToPropFloatChanged(StructArrayInterfacePropFloatPropertyCb callback)
{
    auto handleId = m_propFloatChangedCallbackNextId++;
    m_propFloatCallbacks[handleId] = callback;
    return handleId;
}

void StructArrayInterfacePublisher::unsubscribeFromPropFloatChanged(long handleId)
{
    m_propFloatCallbacks.erase(handleId);
}

void StructArrayInterfacePublisher::publishPropFloatChanged(const std::list<StructFloat>& propFloat) const
{
    for(const auto& subscriber: m_allChangesSubscribers)
    {
        subscriber.get().onPropFloatChanged(propFloat);
    }
    for(const auto& callbackEntry: m_propFloatCallbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(propFloat);
        }
    }
}

long StructArrayInterfacePublisher::subscribeToPropStringChanged(StructArrayInterfacePropStringPropertyCb callback)
{
    auto handleId = m_propStringChangedCallbackNextId++;
    m_propStringCallbacks[handleId] = callback;
    return handleId;
}

void StructArrayInterfacePublisher::unsubscribeFromPropStringChanged(long handleId)
{
    m_propStringCallbacks.erase(handleId);
}

void StructArrayInterfacePublisher::publishPropStringChanged(const std::list<StructString>& propString) const
{
    for(const auto& subscriber: m_allChangesSubscribers)
    {
        subscriber.get().onPropStringChanged(propString);
    }
    for(const auto& callbackEntry: m_propStringCallbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(propString);
        }
    }
}

long StructArrayInterfacePublisher::subscribeToSigBool(StructArrayInterfaceSigBoolSignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    auto handleId = m_sigBoolSignalCallbackNextId++;
    m_sigBoolCallbacks[handleId] = callback;
    return handleId;
}

void StructArrayInterfacePublisher::unsubscribeFromSigBool(long handleId)
{
    m_sigBoolCallbacks.erase(handleId);
}

void StructArrayInterfacePublisher::publishSigBool(const std::list<StructBool>& paramBool) const
{
    for(const auto& subscriber: m_allChangesSubscribers)
    {
        subscriber.get().onSigBool(paramBool);
    }
    for(const auto& callbackEntry: m_sigBoolCallbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(paramBool);
        }
    }
}

long StructArrayInterfacePublisher::subscribeToSigInt(StructArrayInterfaceSigIntSignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    auto handleId = m_sigIntSignalCallbackNextId++;
    m_sigIntCallbacks[handleId] = callback;
    return handleId;
}

void StructArrayInterfacePublisher::unsubscribeFromSigInt(long handleId)
{
    m_sigIntCallbacks.erase(handleId);
}

void StructArrayInterfacePublisher::publishSigInt(const std::list<StructInt>& paramInt) const
{
    for(const auto& subscriber: m_allChangesSubscribers)
    {
        subscriber.get().onSigInt(paramInt);
    }
    for(const auto& callbackEntry: m_sigIntCallbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(paramInt);
        }
    }
}

long StructArrayInterfacePublisher::subscribeToSigFloat(StructArrayInterfaceSigFloatSignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    auto handleId = m_sigFloatSignalCallbackNextId++;
    m_sigFloatCallbacks[handleId] = callback;
    return handleId;
}

void StructArrayInterfacePublisher::unsubscribeFromSigFloat(long handleId)
{
    m_sigFloatCallbacks.erase(handleId);
}

void StructArrayInterfacePublisher::publishSigFloat(const std::list<StructFloat>& paramFloat) const
{
    for(const auto& subscriber: m_allChangesSubscribers)
    {
        subscriber.get().onSigFloat(paramFloat);
    }
    for(const auto& callbackEntry: m_sigFloatCallbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(paramFloat);
        }
    }
}

long StructArrayInterfacePublisher::subscribeToSigString(StructArrayInterfaceSigStringSignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    auto handleId = m_sigStringSignalCallbackNextId++;
    m_sigStringCallbacks[handleId] = callback;
    return handleId;
}

void StructArrayInterfacePublisher::unsubscribeFromSigString(long handleId)
{
    m_sigStringCallbacks.erase(handleId);
}

void StructArrayInterfacePublisher::publishSigString(const std::list<StructString>& paramString) const
{
    for(const auto& subscriber: m_allChangesSubscribers)
    {
        subscriber.get().onSigString(paramString);
    }
    for(const auto& callbackEntry: m_sigStringCallbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(paramString);
        }
    }
}

