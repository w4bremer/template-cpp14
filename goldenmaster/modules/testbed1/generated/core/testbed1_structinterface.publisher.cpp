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
#include <set>
#include <map>
#include "testbed1_structinterface.publisher.h"


namespace Test {
namespace Testbed1 {
class StructInterfacePublisherPimpl : public IStructInterfacePublisher
{
public:
    void subscribeToStructInterfaceInterface(IStructInterfaceSubscriber& subscriber) override;
    void unsubscribeFromStructInterfaceInterface(IStructInterfaceSubscriber& subscriber) override;

    long subscribeToPropBoolChanged(StructInterfacePropBoolPropertyCb callback) override;
    void unsubscribeFromPropBoolChanged(long handleId) override;

    long subscribeToPropIntChanged(StructInterfacePropIntPropertyCb callback) override;
    void unsubscribeFromPropIntChanged(long handleId) override;

    long subscribeToPropFloatChanged(StructInterfacePropFloatPropertyCb callback) override;
    void unsubscribeFromPropFloatChanged(long handleId) override;

    long subscribeToPropStringChanged(StructInterfacePropStringPropertyCb callback) override;
    void unsubscribeFromPropStringChanged(long handleId) override;

    long subscribeToSigBool(StructInterfaceSigBoolSignalCb callback) override;
    void unsubscribeFromSigBool(long handleId) override;

    long subscribeToSigInt(StructInterfaceSigIntSignalCb callback) override;
    void unsubscribeFromSigInt(long handleId) override;

    long subscribeToSigFloat(StructInterfaceSigFloatSignalCb callback) override;
    void unsubscribeFromSigFloat(long handleId) override;

    long subscribeToSigString(StructInterfaceSigStringSignalCb callback) override;
    void unsubscribeFromSigString(long handleId) override;

    void publishPropBoolChanged(const StructBool& propBool) const override;
    void publishPropIntChanged(const StructInt& propInt) const override;
    void publishPropFloatChanged(const StructFloat& propFloat) const override;
    void publishPropStringChanged(const StructString& propString) const override;
    void publishSigBool(const StructBool& paramBool) const override;
    void publishSigInt(const StructInt& paramInt) const override;
    void publishSigFloat(const StructFloat& paramFloat) const override;
    void publishSigString(const StructString& paramString) const override;
private:
    std::set<IStructInterfaceSubscriber*> IStructInterfaceInterfaceSubscribers;
    std::map<long, StructInterfacePropBoolPropertyCb> PropBoolCallbacks;
    std::map<long, StructInterfacePropIntPropertyCb> PropIntCallbacks;
    std::map<long, StructInterfacePropFloatPropertyCb> PropFloatCallbacks;
    std::map<long, StructInterfacePropStringPropertyCb> PropStringCallbacks;
    std::map<long, StructInterfaceSigBoolSignalCb> SigBoolCallbacks;
    std::map<long, StructInterfaceSigIntSignalCb> SigIntCallbacks;
    std::map<long, StructInterfaceSigFloatSignalCb> SigFloatCallbacks;
    std::map<long, StructInterfaceSigStringSignalCb> SigStringCallbacks;
};

} // namespace Testbed1
} // namespace Test

using namespace Test::Testbed1;

/**
 * Implementation StructInterfacePublisherPimpl
 */
void StructInterfacePublisherPimpl::subscribeToStructInterfaceInterface(IStructInterfaceSubscriber& subscriber)
{
    IStructInterfaceInterfaceSubscribers.insert(&subscriber);
}

void StructInterfacePublisherPimpl::unsubscribeFromStructInterfaceInterface(IStructInterfaceSubscriber& subscriber)
{
    IStructInterfaceInterfaceSubscribers.erase(&subscriber);
}

long StructInterfacePublisherPimpl::subscribeToPropBoolChanged(StructInterfacePropBoolPropertyCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    long handleId = static_cast<long>(PropBoolCallbacks.size());
    PropBoolCallbacks[handleId] = callback;
    return handleId;
}

void StructInterfacePublisherPimpl::unsubscribeFromPropBoolChanged(long handleId)
{
    PropBoolCallbacks.erase(handleId);
}

void StructInterfacePublisherPimpl::publishPropBoolChanged(const StructBool& propBool) const
{
    for(const auto& Subscriber: IStructInterfaceInterfaceSubscribers)
    {
        Subscriber->OnPropBoolChanged(propBool);
    }
    for(const auto& callbackEntry: PropBoolCallbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(propBool);
        }
    }
}

long StructInterfacePublisherPimpl::subscribeToPropIntChanged(StructInterfacePropIntPropertyCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    long handleId = static_cast<long>(PropIntCallbacks.size());
    PropIntCallbacks[handleId] = callback;
    return handleId;
}

void StructInterfacePublisherPimpl::unsubscribeFromPropIntChanged(long handleId)
{
    PropIntCallbacks.erase(handleId);
}

void StructInterfacePublisherPimpl::publishPropIntChanged(const StructInt& propInt) const
{
    for(const auto& Subscriber: IStructInterfaceInterfaceSubscribers)
    {
        Subscriber->OnPropIntChanged(propInt);
    }
    for(const auto& callbackEntry: PropIntCallbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(propInt);
        }
    }
}

long StructInterfacePublisherPimpl::subscribeToPropFloatChanged(StructInterfacePropFloatPropertyCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    long handleId = static_cast<long>(PropFloatCallbacks.size());
    PropFloatCallbacks[handleId] = callback;
    return handleId;
}

void StructInterfacePublisherPimpl::unsubscribeFromPropFloatChanged(long handleId)
{
    PropFloatCallbacks.erase(handleId);
}

void StructInterfacePublisherPimpl::publishPropFloatChanged(const StructFloat& propFloat) const
{
    for(const auto& Subscriber: IStructInterfaceInterfaceSubscribers)
    {
        Subscriber->OnPropFloatChanged(propFloat);
    }
    for(const auto& callbackEntry: PropFloatCallbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(propFloat);
        }
    }
}

long StructInterfacePublisherPimpl::subscribeToPropStringChanged(StructInterfacePropStringPropertyCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    long handleId = static_cast<long>(PropStringCallbacks.size());
    PropStringCallbacks[handleId] = callback;
    return handleId;
}

void StructInterfacePublisherPimpl::unsubscribeFromPropStringChanged(long handleId)
{
    PropStringCallbacks.erase(handleId);
}

void StructInterfacePublisherPimpl::publishPropStringChanged(const StructString& propString) const
{
    for(const auto& Subscriber: IStructInterfaceInterfaceSubscribers)
    {
        Subscriber->OnPropStringChanged(propString);
    }
    for(const auto& callbackEntry: PropStringCallbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(propString);
        }
    }
}

long StructInterfacePublisherPimpl::subscribeToSigBool(StructInterfaceSigBoolSignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    long handleId = static_cast<long>(SigBoolCallbacks.size());
    SigBoolCallbacks[handleId] = callback;
    return handleId;
}

void StructInterfacePublisherPimpl::unsubscribeFromSigBool(long handleId)
{
    SigBoolCallbacks.erase(handleId);
}

void StructInterfacePublisherPimpl::publishSigBool(const StructBool& paramBool) const
{
    for(const auto& Subscriber: IStructInterfaceInterfaceSubscribers)
    {
        Subscriber->OnSigBool(paramBool);
    }
    for(const auto& callbackEntry: SigBoolCallbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(paramBool);
        }
    }
}

long StructInterfacePublisherPimpl::subscribeToSigInt(StructInterfaceSigIntSignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    long handleId = static_cast<long>(SigIntCallbacks.size());
    SigIntCallbacks[handleId] = callback;
    return handleId;
}

void StructInterfacePublisherPimpl::unsubscribeFromSigInt(long handleId)
{
    SigIntCallbacks.erase(handleId);
}

void StructInterfacePublisherPimpl::publishSigInt(const StructInt& paramInt) const
{
    for(const auto& Subscriber: IStructInterfaceInterfaceSubscribers)
    {
        Subscriber->OnSigInt(paramInt);
    }
    for(const auto& callbackEntry: SigIntCallbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(paramInt);
        }
    }
}

long StructInterfacePublisherPimpl::subscribeToSigFloat(StructInterfaceSigFloatSignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    long handleId = static_cast<long>(SigFloatCallbacks.size());
    SigFloatCallbacks[handleId] = callback;
    return handleId;
}

void StructInterfacePublisherPimpl::unsubscribeFromSigFloat(long handleId)
{
    SigFloatCallbacks.erase(handleId);
}

void StructInterfacePublisherPimpl::publishSigFloat(const StructFloat& paramFloat) const
{
    for(const auto& Subscriber: IStructInterfaceInterfaceSubscribers)
    {
        Subscriber->OnSigFloat(paramFloat);
    }
    for(const auto& callbackEntry: SigFloatCallbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(paramFloat);
        }
    }
}

long StructInterfacePublisherPimpl::subscribeToSigString(StructInterfaceSigStringSignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    long handleId = static_cast<long>(SigStringCallbacks.size());
    SigStringCallbacks[handleId] = callback;
    return handleId;
}

void StructInterfacePublisherPimpl::unsubscribeFromSigString(long handleId)
{
    SigStringCallbacks.erase(handleId);
}

void StructInterfacePublisherPimpl::publishSigString(const StructString& paramString) const
{
    for(const auto& Subscriber: IStructInterfaceInterfaceSubscribers)
    {
        Subscriber->OnSigString(paramString);
    }
    for(const auto& callbackEntry: SigStringCallbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(paramString);
        }
    }
}

/**
 * Implementation StructInterfacePublisher
 */
StructInterfacePublisher::StructInterfacePublisher()
    : m_impl(std::make_shared<StructInterfacePublisherPimpl>())
{
}
StructInterfacePublisher::~StructInterfacePublisher() = default;

void StructInterfacePublisher::subscribeToStructInterfaceInterface(IStructInterfaceSubscriber& subscriber)
{
    m_impl->subscribeToStructInterfaceInterface(subscriber);
}

void StructInterfacePublisher::unsubscribeFromStructInterfaceInterface(IStructInterfaceSubscriber& subscriber)
{
    m_impl->unsubscribeFromStructInterfaceInterface(subscriber);
}

long StructInterfacePublisher::subscribeToPropBoolChanged(StructInterfacePropBoolPropertyCb callback)
{
    return m_impl->subscribeToPropBoolChanged(callback);
}

void StructInterfacePublisher::unsubscribeFromPropBoolChanged(long handleId)
{
    m_impl->unsubscribeFromPropBoolChanged(handleId);
}

void StructInterfacePublisher::publishPropBoolChanged(const StructBool& propBool) const
{
    m_impl->publishPropBoolChanged(propBool);
}

long StructInterfacePublisher::subscribeToPropIntChanged(StructInterfacePropIntPropertyCb callback)
{
    return m_impl->subscribeToPropIntChanged(callback);
}

void StructInterfacePublisher::unsubscribeFromPropIntChanged(long handleId)
{
    m_impl->unsubscribeFromPropIntChanged(handleId);
}

void StructInterfacePublisher::publishPropIntChanged(const StructInt& propInt) const
{
    m_impl->publishPropIntChanged(propInt);
}

long StructInterfacePublisher::subscribeToPropFloatChanged(StructInterfacePropFloatPropertyCb callback)
{
    return m_impl->subscribeToPropFloatChanged(callback);
}

void StructInterfacePublisher::unsubscribeFromPropFloatChanged(long handleId)
{
    m_impl->unsubscribeFromPropFloatChanged(handleId);
}

void StructInterfacePublisher::publishPropFloatChanged(const StructFloat& propFloat) const
{
    m_impl->publishPropFloatChanged(propFloat);
}

long StructInterfacePublisher::subscribeToPropStringChanged(StructInterfacePropStringPropertyCb callback)
{
    return m_impl->subscribeToPropStringChanged(callback);
}

void StructInterfacePublisher::unsubscribeFromPropStringChanged(long handleId)
{
    m_impl->unsubscribeFromPropStringChanged(handleId);
}

void StructInterfacePublisher::publishPropStringChanged(const StructString& propString) const
{
    m_impl->publishPropStringChanged(propString);
}

long StructInterfacePublisher::subscribeToSigBool(StructInterfaceSigBoolSignalCb callback)
{
    return m_impl->subscribeToSigBool(callback);
}

void StructInterfacePublisher::unsubscribeFromSigBool(long handleId)
{
    m_impl->unsubscribeFromSigBool(handleId);
}

void StructInterfacePublisher::publishSigBool(const StructBool& paramBool) const
{
    m_impl->publishSigBool(paramBool);
}

long StructInterfacePublisher::subscribeToSigInt(StructInterfaceSigIntSignalCb callback)
{
    return m_impl->subscribeToSigInt(callback);
}

void StructInterfacePublisher::unsubscribeFromSigInt(long handleId)
{
    m_impl->unsubscribeFromSigInt(handleId);
}

void StructInterfacePublisher::publishSigInt(const StructInt& paramInt) const
{
    m_impl->publishSigInt(paramInt);
}

long StructInterfacePublisher::subscribeToSigFloat(StructInterfaceSigFloatSignalCb callback)
{
    return m_impl->subscribeToSigFloat(callback);
}

void StructInterfacePublisher::unsubscribeFromSigFloat(long handleId)
{
    m_impl->unsubscribeFromSigFloat(handleId);
}

void StructInterfacePublisher::publishSigFloat(const StructFloat& paramFloat) const
{
    m_impl->publishSigFloat(paramFloat);
}

long StructInterfacePublisher::subscribeToSigString(StructInterfaceSigStringSignalCb callback)
{
    return m_impl->subscribeToSigString(callback);
}

void StructInterfacePublisher::unsubscribeFromSigString(long handleId)
{
    m_impl->unsubscribeFromSigString(handleId);
}

void StructInterfacePublisher::publishSigString(const StructString& paramString) const
{
    m_impl->publishSigString(paramString);
}
