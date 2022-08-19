

#include "tb_simple/generated/core/simplearrayinterface.publisher.h"
#include <algorithm>


using namespace Test::TbSimple;

void SimpleArrayInterfacePublisher::subscribeToAllChanges(ISimpleArrayInterfaceSubscriber& subscriber)
{
    auto found = std::find_if(m_allChangesSubscribers.begin(), m_allChangesSubscribers.end(),
                        [&subscriber](const auto element){return &(element.get()) == &subscriber;});
    if (found == m_allChangesSubscribers.end())
    {
        m_allChangesSubscribers.push_back(std::reference_wrapper<ISimpleArrayInterfaceSubscriber>(subscriber));
    }
}

void SimpleArrayInterfacePublisher::unsubscribeFromAllChanges(ISimpleArrayInterfaceSubscriber& subscriber)
{
    auto found = std::find_if(m_allChangesSubscribers.begin(), m_allChangesSubscribers.end(),
                        [&subscriber](const auto element){return &(element.get()) == &subscriber;});
    if (found != m_allChangesSubscribers.end())
    {
        m_allChangesSubscribers.erase(found);
    }
}

long SimpleArrayInterfacePublisher::subscribeToPropBoolChanged(SimpleArrayInterfacePropBoolPropertyCb callback)
{
    auto handleId = m_propBoolChangedCallbackNextId++;
    m_propBoolCallbacks[handleId] = callback;
    return handleId;
}

void SimpleArrayInterfacePublisher::unsubscribeFromPropBoolChanged(long handleId)
{
    m_propBoolCallbacks.erase(handleId);
}

void SimpleArrayInterfacePublisher::publishPropBoolChanged(const std::list<bool>& propBool) const
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

long SimpleArrayInterfacePublisher::subscribeToPropIntChanged(SimpleArrayInterfacePropIntPropertyCb callback)
{
    auto handleId = m_propIntChangedCallbackNextId++;
    m_propIntCallbacks[handleId] = callback;
    return handleId;
}

void SimpleArrayInterfacePublisher::unsubscribeFromPropIntChanged(long handleId)
{
    m_propIntCallbacks.erase(handleId);
}

void SimpleArrayInterfacePublisher::publishPropIntChanged(const std::list<int>& propInt) const
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

long SimpleArrayInterfacePublisher::subscribeToPropFloatChanged(SimpleArrayInterfacePropFloatPropertyCb callback)
{
    auto handleId = m_propFloatChangedCallbackNextId++;
    m_propFloatCallbacks[handleId] = callback;
    return handleId;
}

void SimpleArrayInterfacePublisher::unsubscribeFromPropFloatChanged(long handleId)
{
    m_propFloatCallbacks.erase(handleId);
}

void SimpleArrayInterfacePublisher::publishPropFloatChanged(const std::list<float>& propFloat) const
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

long SimpleArrayInterfacePublisher::subscribeToPropStringChanged(SimpleArrayInterfacePropStringPropertyCb callback)
{
    auto handleId = m_propStringChangedCallbackNextId++;
    m_propStringCallbacks[handleId] = callback;
    return handleId;
}

void SimpleArrayInterfacePublisher::unsubscribeFromPropStringChanged(long handleId)
{
    m_propStringCallbacks.erase(handleId);
}

void SimpleArrayInterfacePublisher::publishPropStringChanged(const std::list<std::string>& propString) const
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

long SimpleArrayInterfacePublisher::subscribeToSigBool(SimpleArrayInterfaceSigBoolSignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    auto handleId = m_sigBoolSignalCallbackNextId++;
    m_sigBoolCallbacks[handleId] = callback;
    return handleId;
}

void SimpleArrayInterfacePublisher::unsubscribeFromSigBool(long handleId)
{
    m_sigBoolCallbacks.erase(handleId);
}

void SimpleArrayInterfacePublisher::publishSigBool(const std::list<bool>& paramBool) const
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

long SimpleArrayInterfacePublisher::subscribeToSigInt(SimpleArrayInterfaceSigIntSignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    auto handleId = m_sigIntSignalCallbackNextId++;
    m_sigIntCallbacks[handleId] = callback;
    return handleId;
}

void SimpleArrayInterfacePublisher::unsubscribeFromSigInt(long handleId)
{
    m_sigIntCallbacks.erase(handleId);
}

void SimpleArrayInterfacePublisher::publishSigInt(const std::list<int>& paramInt) const
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

long SimpleArrayInterfacePublisher::subscribeToSigFloat(SimpleArrayInterfaceSigFloatSignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    auto handleId = m_sigFloatSignalCallbackNextId++;
    m_sigFloatCallbacks[handleId] = callback;
    return handleId;
}

void SimpleArrayInterfacePublisher::unsubscribeFromSigFloat(long handleId)
{
    m_sigFloatCallbacks.erase(handleId);
}

void SimpleArrayInterfacePublisher::publishSigFloat(const std::list<float>& paramFloat) const
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

long SimpleArrayInterfacePublisher::subscribeToSigString(SimpleArrayInterfaceSigStringSignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    auto handleId = m_sigStringSignalCallbackNextId++;
    m_sigStringCallbacks[handleId] = callback;
    return handleId;
}

void SimpleArrayInterfacePublisher::unsubscribeFromSigString(long handleId)
{
    m_sigStringCallbacks.erase(handleId);
}

void SimpleArrayInterfacePublisher::publishSigString(const std::list<std::string>& paramString) const
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

