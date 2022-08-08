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
#include "testbed1/generated/core/structarrayinterface.publisher.h"


namespace Test {
namespace Testbed1 {
class StructArrayInterfacePublisherPimpl : public IStructArrayInterfacePublisher
{
public:
    void subscribeToStructArrayInterfaceInterface(IStructArrayInterfaceSubscriber& subscriber) override;
    void unsubscribeFromStructArrayInterfaceInterface(IStructArrayInterfaceSubscriber& subscriber) override;

    long subscribeToPropBoolChanged(StructArrayInterfacePropBoolPropertyCb callback) override;
    void unsubscribeFromPropBoolChanged(long handleId) override;

    long subscribeToPropIntChanged(StructArrayInterfacePropIntPropertyCb callback) override;
    void unsubscribeFromPropIntChanged(long handleId) override;

    long subscribeToPropFloatChanged(StructArrayInterfacePropFloatPropertyCb callback) override;
    void unsubscribeFromPropFloatChanged(long handleId) override;

    long subscribeToPropStringChanged(StructArrayInterfacePropStringPropertyCb callback) override;
    void unsubscribeFromPropStringChanged(long handleId) override;

    long subscribeToSigBool(StructArrayInterfaceSigBoolSignalCb callback) override;
    void unsubscribeFromSigBool(long handleId) override;

    long subscribeToSigInt(StructArrayInterfaceSigIntSignalCb callback) override;
    void unsubscribeFromSigInt(long handleId) override;

    long subscribeToSigFloat(StructArrayInterfaceSigFloatSignalCb callback) override;
    void unsubscribeFromSigFloat(long handleId) override;

    long subscribeToSigString(StructArrayInterfaceSigStringSignalCb callback) override;
    void unsubscribeFromSigString(long handleId) override;

    void publishPropBoolChanged(const std::list<StructBool>& propBool) const override;
    void publishPropIntChanged(const std::list<StructInt>& propInt) const override;
    void publishPropFloatChanged(const std::list<StructFloat>& propFloat) const override;
    void publishPropStringChanged(const std::list<StructString>& propString) const override;
    void publishSigBool(const std::list<StructBool>& paramBool) const override;
    void publishSigInt(const std::list<StructInt>& paramInt) const override;
    void publishSigFloat(const std::list<StructFloat>& paramFloat) const override;
    void publishSigString(const std::list<StructString>& paramString) const override;
private:
    std::set<IStructArrayInterfaceSubscriber*> IStructArrayInterfaceInterfaceSubscribers;
    std::map<long, StructArrayInterfacePropBoolPropertyCb> PropBoolCallbacks;
    std::map<long, StructArrayInterfacePropIntPropertyCb> PropIntCallbacks;
    std::map<long, StructArrayInterfacePropFloatPropertyCb> PropFloatCallbacks;
    std::map<long, StructArrayInterfacePropStringPropertyCb> PropStringCallbacks;
    std::map<long, StructArrayInterfaceSigBoolSignalCb> SigBoolCallbacks;
    std::map<long, StructArrayInterfaceSigIntSignalCb> SigIntCallbacks;
    std::map<long, StructArrayInterfaceSigFloatSignalCb> SigFloatCallbacks;
    std::map<long, StructArrayInterfaceSigStringSignalCb> SigStringCallbacks;
};

} // namespace Testbed1
} // namespace Test

using namespace Test::Testbed1;

/**
 * Implementation StructArrayInterfacePublisherPimpl
 */
void StructArrayInterfacePublisherPimpl::subscribeToStructArrayInterfaceInterface(IStructArrayInterfaceSubscriber& subscriber)
{
    IStructArrayInterfaceInterfaceSubscribers.insert(&subscriber);
}

void StructArrayInterfacePublisherPimpl::unsubscribeFromStructArrayInterfaceInterface(IStructArrayInterfaceSubscriber& subscriber)
{
    IStructArrayInterfaceInterfaceSubscribers.erase(&subscriber);
}

long StructArrayInterfacePublisherPimpl::subscribeToPropBoolChanged(StructArrayInterfacePropBoolPropertyCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    long handleId = static_cast<long>(PropBoolCallbacks.size());
    PropBoolCallbacks[handleId] = callback;
    return handleId;
}

void StructArrayInterfacePublisherPimpl::unsubscribeFromPropBoolChanged(long handleId)
{
    PropBoolCallbacks.erase(handleId);
}

void StructArrayInterfacePublisherPimpl::publishPropBoolChanged(const std::list<StructBool>& propBool) const
{
    for(const auto& Subscriber: IStructArrayInterfaceInterfaceSubscribers)
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

long StructArrayInterfacePublisherPimpl::subscribeToPropIntChanged(StructArrayInterfacePropIntPropertyCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    long handleId = static_cast<long>(PropIntCallbacks.size());
    PropIntCallbacks[handleId] = callback;
    return handleId;
}

void StructArrayInterfacePublisherPimpl::unsubscribeFromPropIntChanged(long handleId)
{
    PropIntCallbacks.erase(handleId);
}

void StructArrayInterfacePublisherPimpl::publishPropIntChanged(const std::list<StructInt>& propInt) const
{
    for(const auto& Subscriber: IStructArrayInterfaceInterfaceSubscribers)
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

long StructArrayInterfacePublisherPimpl::subscribeToPropFloatChanged(StructArrayInterfacePropFloatPropertyCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    long handleId = static_cast<long>(PropFloatCallbacks.size());
    PropFloatCallbacks[handleId] = callback;
    return handleId;
}

void StructArrayInterfacePublisherPimpl::unsubscribeFromPropFloatChanged(long handleId)
{
    PropFloatCallbacks.erase(handleId);
}

void StructArrayInterfacePublisherPimpl::publishPropFloatChanged(const std::list<StructFloat>& propFloat) const
{
    for(const auto& Subscriber: IStructArrayInterfaceInterfaceSubscribers)
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

long StructArrayInterfacePublisherPimpl::subscribeToPropStringChanged(StructArrayInterfacePropStringPropertyCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    long handleId = static_cast<long>(PropStringCallbacks.size());
    PropStringCallbacks[handleId] = callback;
    return handleId;
}

void StructArrayInterfacePublisherPimpl::unsubscribeFromPropStringChanged(long handleId)
{
    PropStringCallbacks.erase(handleId);
}

void StructArrayInterfacePublisherPimpl::publishPropStringChanged(const std::list<StructString>& propString) const
{
    for(const auto& Subscriber: IStructArrayInterfaceInterfaceSubscribers)
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

long StructArrayInterfacePublisherPimpl::subscribeToSigBool(StructArrayInterfaceSigBoolSignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    long handleId = static_cast<long>(SigBoolCallbacks.size());
    SigBoolCallbacks[handleId] = callback;
    return handleId;
}

void StructArrayInterfacePublisherPimpl::unsubscribeFromSigBool(long handleId)
{
    SigBoolCallbacks.erase(handleId);
}

void StructArrayInterfacePublisherPimpl::publishSigBool(const std::list<StructBool>& paramBool) const
{
    for(const auto& Subscriber: IStructArrayInterfaceInterfaceSubscribers)
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

long StructArrayInterfacePublisherPimpl::subscribeToSigInt(StructArrayInterfaceSigIntSignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    long handleId = static_cast<long>(SigIntCallbacks.size());
    SigIntCallbacks[handleId] = callback;
    return handleId;
}

void StructArrayInterfacePublisherPimpl::unsubscribeFromSigInt(long handleId)
{
    SigIntCallbacks.erase(handleId);
}

void StructArrayInterfacePublisherPimpl::publishSigInt(const std::list<StructInt>& paramInt) const
{
    for(const auto& Subscriber: IStructArrayInterfaceInterfaceSubscribers)
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

long StructArrayInterfacePublisherPimpl::subscribeToSigFloat(StructArrayInterfaceSigFloatSignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    long handleId = static_cast<long>(SigFloatCallbacks.size());
    SigFloatCallbacks[handleId] = callback;
    return handleId;
}

void StructArrayInterfacePublisherPimpl::unsubscribeFromSigFloat(long handleId)
{
    SigFloatCallbacks.erase(handleId);
}

void StructArrayInterfacePublisherPimpl::publishSigFloat(const std::list<StructFloat>& paramFloat) const
{
    for(const auto& Subscriber: IStructArrayInterfaceInterfaceSubscribers)
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

long StructArrayInterfacePublisherPimpl::subscribeToSigString(StructArrayInterfaceSigStringSignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    long handleId = static_cast<long>(SigStringCallbacks.size());
    SigStringCallbacks[handleId] = callback;
    return handleId;
}

void StructArrayInterfacePublisherPimpl::unsubscribeFromSigString(long handleId)
{
    SigStringCallbacks.erase(handleId);
}

void StructArrayInterfacePublisherPimpl::publishSigString(const std::list<StructString>& paramString) const
{
    for(const auto& Subscriber: IStructArrayInterfaceInterfaceSubscribers)
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
 * Implementation StructArrayInterfacePublisher
 */
StructArrayInterfacePublisher::StructArrayInterfacePublisher()
    : m_impl(std::make_shared<StructArrayInterfacePublisherPimpl>())
{
}
StructArrayInterfacePublisher::~StructArrayInterfacePublisher() = default;

void StructArrayInterfacePublisher::subscribeToStructArrayInterfaceInterface(IStructArrayInterfaceSubscriber& subscriber)
{
    m_impl->subscribeToStructArrayInterfaceInterface(subscriber);
}

void StructArrayInterfacePublisher::unsubscribeFromStructArrayInterfaceInterface(IStructArrayInterfaceSubscriber& subscriber)
{
    m_impl->unsubscribeFromStructArrayInterfaceInterface(subscriber);
}

long StructArrayInterfacePublisher::subscribeToPropBoolChanged(StructArrayInterfacePropBoolPropertyCb callback)
{
    return m_impl->subscribeToPropBoolChanged(callback);
}

void StructArrayInterfacePublisher::unsubscribeFromPropBoolChanged(long handleId)
{
    m_impl->unsubscribeFromPropBoolChanged(handleId);
}

void StructArrayInterfacePublisher::publishPropBoolChanged(const std::list<StructBool>& propBool) const
{
    m_impl->publishPropBoolChanged(propBool);
}

long StructArrayInterfacePublisher::subscribeToPropIntChanged(StructArrayInterfacePropIntPropertyCb callback)
{
    return m_impl->subscribeToPropIntChanged(callback);
}

void StructArrayInterfacePublisher::unsubscribeFromPropIntChanged(long handleId)
{
    m_impl->unsubscribeFromPropIntChanged(handleId);
}

void StructArrayInterfacePublisher::publishPropIntChanged(const std::list<StructInt>& propInt) const
{
    m_impl->publishPropIntChanged(propInt);
}

long StructArrayInterfacePublisher::subscribeToPropFloatChanged(StructArrayInterfacePropFloatPropertyCb callback)
{
    return m_impl->subscribeToPropFloatChanged(callback);
}

void StructArrayInterfacePublisher::unsubscribeFromPropFloatChanged(long handleId)
{
    m_impl->unsubscribeFromPropFloatChanged(handleId);
}

void StructArrayInterfacePublisher::publishPropFloatChanged(const std::list<StructFloat>& propFloat) const
{
    m_impl->publishPropFloatChanged(propFloat);
}

long StructArrayInterfacePublisher::subscribeToPropStringChanged(StructArrayInterfacePropStringPropertyCb callback)
{
    return m_impl->subscribeToPropStringChanged(callback);
}

void StructArrayInterfacePublisher::unsubscribeFromPropStringChanged(long handleId)
{
    m_impl->unsubscribeFromPropStringChanged(handleId);
}

void StructArrayInterfacePublisher::publishPropStringChanged(const std::list<StructString>& propString) const
{
    m_impl->publishPropStringChanged(propString);
}

long StructArrayInterfacePublisher::subscribeToSigBool(StructArrayInterfaceSigBoolSignalCb callback)
{
    return m_impl->subscribeToSigBool(callback);
}

void StructArrayInterfacePublisher::unsubscribeFromSigBool(long handleId)
{
    m_impl->unsubscribeFromSigBool(handleId);
}

void StructArrayInterfacePublisher::publishSigBool(const std::list<StructBool>& paramBool) const
{
    m_impl->publishSigBool(paramBool);
}

long StructArrayInterfacePublisher::subscribeToSigInt(StructArrayInterfaceSigIntSignalCb callback)
{
    return m_impl->subscribeToSigInt(callback);
}

void StructArrayInterfacePublisher::unsubscribeFromSigInt(long handleId)
{
    m_impl->unsubscribeFromSigInt(handleId);
}

void StructArrayInterfacePublisher::publishSigInt(const std::list<StructInt>& paramInt) const
{
    m_impl->publishSigInt(paramInt);
}

long StructArrayInterfacePublisher::subscribeToSigFloat(StructArrayInterfaceSigFloatSignalCb callback)
{
    return m_impl->subscribeToSigFloat(callback);
}

void StructArrayInterfacePublisher::unsubscribeFromSigFloat(long handleId)
{
    m_impl->unsubscribeFromSigFloat(handleId);
}

void StructArrayInterfacePublisher::publishSigFloat(const std::list<StructFloat>& paramFloat) const
{
    m_impl->publishSigFloat(paramFloat);
}

long StructArrayInterfacePublisher::subscribeToSigString(StructArrayInterfaceSigStringSignalCb callback)
{
    return m_impl->subscribeToSigString(callback);
}

void StructArrayInterfacePublisher::unsubscribeFromSigString(long handleId)
{
    m_impl->unsubscribeFromSigString(handleId);
}

void StructArrayInterfacePublisher::publishSigString(const std::list<StructString>& paramString) const
{
    m_impl->publishSigString(paramString);
}
