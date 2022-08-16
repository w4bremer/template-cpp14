/**
NO TITLE
Copyright (C) 2020 ApiGear UG

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/


#include "tb_enum/generated/core/enuminterface.publisher.h"
#include <algorithm>


using namespace Test::TbEnum;

void EnumInterfacePublisher::subscribeToAllChanges(IEnumInterfaceSubscriber& subscriber)
{
    auto found = std::find_if(m_allChangesSubscribers.begin(), m_allChangesSubscribers.end(),
                        [&subscriber](const auto element){return &(element.get()) == &subscriber;});
    if (found == m_allChangesSubscribers.end())
    {
        m_allChangesSubscribers.push_back(std::reference_wrapper<IEnumInterfaceSubscriber>(subscriber));
    }
}

void EnumInterfacePublisher::unsubscribeFromAllChanges(IEnumInterfaceSubscriber& subscriber)
{
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
    m_prop0Callbacks[handleId] = callback;
    return handleId;
}

void EnumInterfacePublisher::unsubscribeFromProp0Changed(long handleId)
{
    m_prop0Callbacks.erase(handleId);
}

void EnumInterfacePublisher::publishProp0Changed(const Enum0Enum& prop0) const
{
    for(const auto& subscriber: m_allChangesSubscribers)
    {
        subscriber.get().onProp0Changed(prop0);
    }
    for(const auto& callbackEntry: m_prop0Callbacks)
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
    m_prop1Callbacks[handleId] = callback;
    return handleId;
}

void EnumInterfacePublisher::unsubscribeFromProp1Changed(long handleId)
{
    m_prop1Callbacks.erase(handleId);
}

void EnumInterfacePublisher::publishProp1Changed(const Enum1Enum& prop1) const
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

long EnumInterfacePublisher::subscribeToProp2Changed(EnumInterfaceProp2PropertyCb callback)
{
    auto handleId = m_prop2ChangedCallbackNextId++;
    m_prop2Callbacks[handleId] = callback;
    return handleId;
}

void EnumInterfacePublisher::unsubscribeFromProp2Changed(long handleId)
{
    m_prop2Callbacks.erase(handleId);
}

void EnumInterfacePublisher::publishProp2Changed(const Enum2Enum& prop2) const
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

long EnumInterfacePublisher::subscribeToProp3Changed(EnumInterfaceProp3PropertyCb callback)
{
    auto handleId = m_prop3ChangedCallbackNextId++;
    m_prop3Callbacks[handleId] = callback;
    return handleId;
}

void EnumInterfacePublisher::unsubscribeFromProp3Changed(long handleId)
{
    m_prop3Callbacks.erase(handleId);
}

void EnumInterfacePublisher::publishProp3Changed(const Enum3Enum& prop3) const
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

long EnumInterfacePublisher::subscribeToSig0(EnumInterfaceSig0SignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    auto handleId = m_sig0SignalCallbackNextId++;
    m_sig0Callbacks[handleId] = callback;
    return handleId;
}

void EnumInterfacePublisher::unsubscribeFromSig0(long handleId)
{
    m_sig0Callbacks.erase(handleId);
}

void EnumInterfacePublisher::publishSig0(const Enum0Enum& param0) const
{
    for(const auto& subscriber: m_allChangesSubscribers)
    {
        subscriber.get().onSig0(param0);
    }
    for(const auto& callbackEntry: m_sig0Callbacks)
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
    m_sig1Callbacks[handleId] = callback;
    return handleId;
}

void EnumInterfacePublisher::unsubscribeFromSig1(long handleId)
{
    m_sig1Callbacks.erase(handleId);
}

void EnumInterfacePublisher::publishSig1(const Enum1Enum& param1) const
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

long EnumInterfacePublisher::subscribeToSig2(EnumInterfaceSig2SignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    auto handleId = m_sig2SignalCallbackNextId++;
    m_sig2Callbacks[handleId] = callback;
    return handleId;
}

void EnumInterfacePublisher::unsubscribeFromSig2(long handleId)
{
    m_sig2Callbacks.erase(handleId);
}

void EnumInterfacePublisher::publishSig2(const Enum2Enum& param2) const
{
    for(const auto& subscriber: m_allChangesSubscribers)
    {
        subscriber.get().onSig2(param2);
    }
    for(const auto& callbackEntry: m_sig2Callbacks)
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
    m_sig3Callbacks[handleId] = callback;
    return handleId;
}

void EnumInterfacePublisher::unsubscribeFromSig3(long handleId)
{
    m_sig3Callbacks.erase(handleId);
}

void EnumInterfacePublisher::publishSig3(const Enum3Enum& param3) const
{
    for(const auto& subscriber: m_allChangesSubscribers)
    {
        subscriber.get().onSig3(param3);
    }
    for(const auto& callbackEntry: m_sig3Callbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(param3);
        }
    }
}

