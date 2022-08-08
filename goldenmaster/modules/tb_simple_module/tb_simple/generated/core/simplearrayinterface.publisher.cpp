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
#include "tb_simple/generated/core/simplearrayinterface.publisher.h"


namespace Test {
namespace TbSimple {
class SimpleArrayInterfacePublisherPimpl : public ISimpleArrayInterfacePublisher
{
public:
    void subscribeToSimpleArrayInterfaceInterface(ISimpleArrayInterfaceSubscriber& subscriber) override;
    void unsubscribeFromSimpleArrayInterfaceInterface(ISimpleArrayInterfaceSubscriber& subscriber) override;

    long subscribeToPropBoolChanged(SimpleArrayInterfacePropBoolPropertyCb callback) override;
    void unsubscribeFromPropBoolChanged(long handleId) override;

    long subscribeToPropIntChanged(SimpleArrayInterfacePropIntPropertyCb callback) override;
    void unsubscribeFromPropIntChanged(long handleId) override;

    long subscribeToPropFloatChanged(SimpleArrayInterfacePropFloatPropertyCb callback) override;
    void unsubscribeFromPropFloatChanged(long handleId) override;

    long subscribeToPropStringChanged(SimpleArrayInterfacePropStringPropertyCb callback) override;
    void unsubscribeFromPropStringChanged(long handleId) override;

    long subscribeToSigBool(SimpleArrayInterfaceSigBoolSignalCb callback) override;
    void unsubscribeFromSigBool(long handleId) override;

    long subscribeToSigInt(SimpleArrayInterfaceSigIntSignalCb callback) override;
    void unsubscribeFromSigInt(long handleId) override;

    long subscribeToSigFloat(SimpleArrayInterfaceSigFloatSignalCb callback) override;
    void unsubscribeFromSigFloat(long handleId) override;

    long subscribeToSigString(SimpleArrayInterfaceSigStringSignalCb callback) override;
    void unsubscribeFromSigString(long handleId) override;

    void publishPropBoolChanged(const std::list<bool>& propBool) const override;
    void publishPropIntChanged(const std::list<int>& propInt) const override;
    void publishPropFloatChanged(const std::list<float>& propFloat) const override;
    void publishPropStringChanged(const std::list<std::string>& propString) const override;
    void publishSigBool(const std::list<bool>& paramBool) const override;
    void publishSigInt(const std::list<int>& paramInt) const override;
    void publishSigFloat(const std::list<float>& paramFloat) const override;
    void publishSigString(const std::list<std::string>& paramString) const override;
private:
    std::set<ISimpleArrayInterfaceSubscriber*> ISimpleArrayInterfaceInterfaceSubscribers;
    std::map<long, SimpleArrayInterfacePropBoolPropertyCb> PropBoolCallbacks;
    std::map<long, SimpleArrayInterfacePropIntPropertyCb> PropIntCallbacks;
    std::map<long, SimpleArrayInterfacePropFloatPropertyCb> PropFloatCallbacks;
    std::map<long, SimpleArrayInterfacePropStringPropertyCb> PropStringCallbacks;
    std::map<long, SimpleArrayInterfaceSigBoolSignalCb> SigBoolCallbacks;
    std::map<long, SimpleArrayInterfaceSigIntSignalCb> SigIntCallbacks;
    std::map<long, SimpleArrayInterfaceSigFloatSignalCb> SigFloatCallbacks;
    std::map<long, SimpleArrayInterfaceSigStringSignalCb> SigStringCallbacks;
};

} // namespace TbSimple
} // namespace Test

using namespace Test::TbSimple;

/**
 * Implementation SimpleArrayInterfacePublisherPimpl
 */
void SimpleArrayInterfacePublisherPimpl::subscribeToSimpleArrayInterfaceInterface(ISimpleArrayInterfaceSubscriber& subscriber)
{
    ISimpleArrayInterfaceInterfaceSubscribers.insert(&subscriber);
}

void SimpleArrayInterfacePublisherPimpl::unsubscribeFromSimpleArrayInterfaceInterface(ISimpleArrayInterfaceSubscriber& subscriber)
{
    ISimpleArrayInterfaceInterfaceSubscribers.erase(&subscriber);
}

long SimpleArrayInterfacePublisherPimpl::subscribeToPropBoolChanged(SimpleArrayInterfacePropBoolPropertyCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    long handleId = static_cast<long>(PropBoolCallbacks.size());
    PropBoolCallbacks[handleId] = callback;
    return handleId;
}

void SimpleArrayInterfacePublisherPimpl::unsubscribeFromPropBoolChanged(long handleId)
{
    PropBoolCallbacks.erase(handleId);
}

void SimpleArrayInterfacePublisherPimpl::publishPropBoolChanged(const std::list<bool>& propBool) const
{
    for(const auto& Subscriber: ISimpleArrayInterfaceInterfaceSubscribers)
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

long SimpleArrayInterfacePublisherPimpl::subscribeToPropIntChanged(SimpleArrayInterfacePropIntPropertyCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    long handleId = static_cast<long>(PropIntCallbacks.size());
    PropIntCallbacks[handleId] = callback;
    return handleId;
}

void SimpleArrayInterfacePublisherPimpl::unsubscribeFromPropIntChanged(long handleId)
{
    PropIntCallbacks.erase(handleId);
}

void SimpleArrayInterfacePublisherPimpl::publishPropIntChanged(const std::list<int>& propInt) const
{
    for(const auto& Subscriber: ISimpleArrayInterfaceInterfaceSubscribers)
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

long SimpleArrayInterfacePublisherPimpl::subscribeToPropFloatChanged(SimpleArrayInterfacePropFloatPropertyCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    long handleId = static_cast<long>(PropFloatCallbacks.size());
    PropFloatCallbacks[handleId] = callback;
    return handleId;
}

void SimpleArrayInterfacePublisherPimpl::unsubscribeFromPropFloatChanged(long handleId)
{
    PropFloatCallbacks.erase(handleId);
}

void SimpleArrayInterfacePublisherPimpl::publishPropFloatChanged(const std::list<float>& propFloat) const
{
    for(const auto& Subscriber: ISimpleArrayInterfaceInterfaceSubscribers)
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

long SimpleArrayInterfacePublisherPimpl::subscribeToPropStringChanged(SimpleArrayInterfacePropStringPropertyCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    long handleId = static_cast<long>(PropStringCallbacks.size());
    PropStringCallbacks[handleId] = callback;
    return handleId;
}

void SimpleArrayInterfacePublisherPimpl::unsubscribeFromPropStringChanged(long handleId)
{
    PropStringCallbacks.erase(handleId);
}

void SimpleArrayInterfacePublisherPimpl::publishPropStringChanged(const std::list<std::string>& propString) const
{
    for(const auto& Subscriber: ISimpleArrayInterfaceInterfaceSubscribers)
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

long SimpleArrayInterfacePublisherPimpl::subscribeToSigBool(SimpleArrayInterfaceSigBoolSignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    long handleId = static_cast<long>(SigBoolCallbacks.size());
    SigBoolCallbacks[handleId] = callback;
    return handleId;
}

void SimpleArrayInterfacePublisherPimpl::unsubscribeFromSigBool(long handleId)
{
    SigBoolCallbacks.erase(handleId);
}

void SimpleArrayInterfacePublisherPimpl::publishSigBool(const std::list<bool>& paramBool) const
{
    for(const auto& Subscriber: ISimpleArrayInterfaceInterfaceSubscribers)
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

long SimpleArrayInterfacePublisherPimpl::subscribeToSigInt(SimpleArrayInterfaceSigIntSignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    long handleId = static_cast<long>(SigIntCallbacks.size());
    SigIntCallbacks[handleId] = callback;
    return handleId;
}

void SimpleArrayInterfacePublisherPimpl::unsubscribeFromSigInt(long handleId)
{
    SigIntCallbacks.erase(handleId);
}

void SimpleArrayInterfacePublisherPimpl::publishSigInt(const std::list<int>& paramInt) const
{
    for(const auto& Subscriber: ISimpleArrayInterfaceInterfaceSubscribers)
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

long SimpleArrayInterfacePublisherPimpl::subscribeToSigFloat(SimpleArrayInterfaceSigFloatSignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    long handleId = static_cast<long>(SigFloatCallbacks.size());
    SigFloatCallbacks[handleId] = callback;
    return handleId;
}

void SimpleArrayInterfacePublisherPimpl::unsubscribeFromSigFloat(long handleId)
{
    SigFloatCallbacks.erase(handleId);
}

void SimpleArrayInterfacePublisherPimpl::publishSigFloat(const std::list<float>& paramFloat) const
{
    for(const auto& Subscriber: ISimpleArrayInterfaceInterfaceSubscribers)
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

long SimpleArrayInterfacePublisherPimpl::subscribeToSigString(SimpleArrayInterfaceSigStringSignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    long handleId = static_cast<long>(SigStringCallbacks.size());
    SigStringCallbacks[handleId] = callback;
    return handleId;
}

void SimpleArrayInterfacePublisherPimpl::unsubscribeFromSigString(long handleId)
{
    SigStringCallbacks.erase(handleId);
}

void SimpleArrayInterfacePublisherPimpl::publishSigString(const std::list<std::string>& paramString) const
{
    for(const auto& Subscriber: ISimpleArrayInterfaceInterfaceSubscribers)
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
 * Implementation SimpleArrayInterfacePublisher
 */
SimpleArrayInterfacePublisher::SimpleArrayInterfacePublisher()
    : m_impl(std::make_shared<SimpleArrayInterfacePublisherPimpl>())
{
}
SimpleArrayInterfacePublisher::~SimpleArrayInterfacePublisher() = default;

void SimpleArrayInterfacePublisher::subscribeToSimpleArrayInterfaceInterface(ISimpleArrayInterfaceSubscriber& subscriber)
{
    m_impl->subscribeToSimpleArrayInterfaceInterface(subscriber);
}

void SimpleArrayInterfacePublisher::unsubscribeFromSimpleArrayInterfaceInterface(ISimpleArrayInterfaceSubscriber& subscriber)
{
    m_impl->unsubscribeFromSimpleArrayInterfaceInterface(subscriber);
}

long SimpleArrayInterfacePublisher::subscribeToPropBoolChanged(SimpleArrayInterfacePropBoolPropertyCb callback)
{
    return m_impl->subscribeToPropBoolChanged(callback);
}

void SimpleArrayInterfacePublisher::unsubscribeFromPropBoolChanged(long handleId)
{
    m_impl->unsubscribeFromPropBoolChanged(handleId);
}

void SimpleArrayInterfacePublisher::publishPropBoolChanged(const std::list<bool>& propBool) const
{
    m_impl->publishPropBoolChanged(propBool);
}

long SimpleArrayInterfacePublisher::subscribeToPropIntChanged(SimpleArrayInterfacePropIntPropertyCb callback)
{
    return m_impl->subscribeToPropIntChanged(callback);
}

void SimpleArrayInterfacePublisher::unsubscribeFromPropIntChanged(long handleId)
{
    m_impl->unsubscribeFromPropIntChanged(handleId);
}

void SimpleArrayInterfacePublisher::publishPropIntChanged(const std::list<int>& propInt) const
{
    m_impl->publishPropIntChanged(propInt);
}

long SimpleArrayInterfacePublisher::subscribeToPropFloatChanged(SimpleArrayInterfacePropFloatPropertyCb callback)
{
    return m_impl->subscribeToPropFloatChanged(callback);
}

void SimpleArrayInterfacePublisher::unsubscribeFromPropFloatChanged(long handleId)
{
    m_impl->unsubscribeFromPropFloatChanged(handleId);
}

void SimpleArrayInterfacePublisher::publishPropFloatChanged(const std::list<float>& propFloat) const
{
    m_impl->publishPropFloatChanged(propFloat);
}

long SimpleArrayInterfacePublisher::subscribeToPropStringChanged(SimpleArrayInterfacePropStringPropertyCb callback)
{
    return m_impl->subscribeToPropStringChanged(callback);
}

void SimpleArrayInterfacePublisher::unsubscribeFromPropStringChanged(long handleId)
{
    m_impl->unsubscribeFromPropStringChanged(handleId);
}

void SimpleArrayInterfacePublisher::publishPropStringChanged(const std::list<std::string>& propString) const
{
    m_impl->publishPropStringChanged(propString);
}

long SimpleArrayInterfacePublisher::subscribeToSigBool(SimpleArrayInterfaceSigBoolSignalCb callback)
{
    return m_impl->subscribeToSigBool(callback);
}

void SimpleArrayInterfacePublisher::unsubscribeFromSigBool(long handleId)
{
    m_impl->unsubscribeFromSigBool(handleId);
}

void SimpleArrayInterfacePublisher::publishSigBool(const std::list<bool>& paramBool) const
{
    m_impl->publishSigBool(paramBool);
}

long SimpleArrayInterfacePublisher::subscribeToSigInt(SimpleArrayInterfaceSigIntSignalCb callback)
{
    return m_impl->subscribeToSigInt(callback);
}

void SimpleArrayInterfacePublisher::unsubscribeFromSigInt(long handleId)
{
    m_impl->unsubscribeFromSigInt(handleId);
}

void SimpleArrayInterfacePublisher::publishSigInt(const std::list<int>& paramInt) const
{
    m_impl->publishSigInt(paramInt);
}

long SimpleArrayInterfacePublisher::subscribeToSigFloat(SimpleArrayInterfaceSigFloatSignalCb callback)
{
    return m_impl->subscribeToSigFloat(callback);
}

void SimpleArrayInterfacePublisher::unsubscribeFromSigFloat(long handleId)
{
    m_impl->unsubscribeFromSigFloat(handleId);
}

void SimpleArrayInterfacePublisher::publishSigFloat(const std::list<float>& paramFloat) const
{
    m_impl->publishSigFloat(paramFloat);
}

long SimpleArrayInterfacePublisher::subscribeToSigString(SimpleArrayInterfaceSigStringSignalCb callback)
{
    return m_impl->subscribeToSigString(callback);
}

void SimpleArrayInterfacePublisher::unsubscribeFromSigString(long handleId)
{
    m_impl->unsubscribeFromSigString(handleId);
}

void SimpleArrayInterfacePublisher::publishSigString(const std::list<std::string>& paramString) const
{
    m_impl->publishSigString(paramString);
}
