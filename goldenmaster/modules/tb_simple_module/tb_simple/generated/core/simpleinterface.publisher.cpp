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
#include "tb_simple/generated/core/simpleinterface.publisher.h"


namespace Test {
namespace TbSimple {
class SimpleInterfacePublisherPimpl : public ISimpleInterfacePublisher
{
public:
    void subscribeToSimpleInterfaceInterface(ISimpleInterfaceSubscriber& subscriber) override;
    void unsubscribeFromSimpleInterfaceInterface(ISimpleInterfaceSubscriber& subscriber) override;

    long subscribeToPropBoolChanged(SimpleInterfacePropBoolPropertyCb callback) override;
    void unsubscribeFromPropBoolChanged(long handleId) override;

    long subscribeToPropIntChanged(SimpleInterfacePropIntPropertyCb callback) override;
    void unsubscribeFromPropIntChanged(long handleId) override;

    long subscribeToPropFloatChanged(SimpleInterfacePropFloatPropertyCb callback) override;
    void unsubscribeFromPropFloatChanged(long handleId) override;

    long subscribeToPropStringChanged(SimpleInterfacePropStringPropertyCb callback) override;
    void unsubscribeFromPropStringChanged(long handleId) override;

    long subscribeToSigBool(SimpleInterfaceSigBoolSignalCb callback) override;
    void unsubscribeFromSigBool(long handleId) override;

    long subscribeToSigInt(SimpleInterfaceSigIntSignalCb callback) override;
    void unsubscribeFromSigInt(long handleId) override;

    long subscribeToSigFloat(SimpleInterfaceSigFloatSignalCb callback) override;
    void unsubscribeFromSigFloat(long handleId) override;

    long subscribeToSigString(SimpleInterfaceSigStringSignalCb callback) override;
    void unsubscribeFromSigString(long handleId) override;

    void publishPropBoolChanged(bool propBool) const override;
    void publishPropIntChanged(int propInt) const override;
    void publishPropFloatChanged(float propFloat) const override;
    void publishPropStringChanged(const std::string& propString) const override;
    void publishSigBool(bool paramBool) const override;
    void publishSigInt(int paramInt) const override;
    void publishSigFloat(float paramFloat) const override;
    void publishSigString(const std::string& paramString) const override;
private:
    std::set<ISimpleInterfaceSubscriber*> ISimpleInterfaceInterfaceSubscribers;
    std::map<long, SimpleInterfacePropBoolPropertyCb> PropBoolCallbacks;
    std::map<long, SimpleInterfacePropIntPropertyCb> PropIntCallbacks;
    std::map<long, SimpleInterfacePropFloatPropertyCb> PropFloatCallbacks;
    std::map<long, SimpleInterfacePropStringPropertyCb> PropStringCallbacks;
    std::map<long, SimpleInterfaceSigBoolSignalCb> SigBoolCallbacks;
    std::map<long, SimpleInterfaceSigIntSignalCb> SigIntCallbacks;
    std::map<long, SimpleInterfaceSigFloatSignalCb> SigFloatCallbacks;
    std::map<long, SimpleInterfaceSigStringSignalCb> SigStringCallbacks;
};

} // namespace TbSimple
} // namespace Test

using namespace Test::TbSimple;

/**
 * Implementation SimpleInterfacePublisherPimpl
 */
void SimpleInterfacePublisherPimpl::subscribeToSimpleInterfaceInterface(ISimpleInterfaceSubscriber& subscriber)
{
    ISimpleInterfaceInterfaceSubscribers.insert(&subscriber);
}

void SimpleInterfacePublisherPimpl::unsubscribeFromSimpleInterfaceInterface(ISimpleInterfaceSubscriber& subscriber)
{
    ISimpleInterfaceInterfaceSubscribers.erase(&subscriber);
}

long SimpleInterfacePublisherPimpl::subscribeToPropBoolChanged(SimpleInterfacePropBoolPropertyCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    long handleId = static_cast<long>(PropBoolCallbacks.size());
    PropBoolCallbacks[handleId] = callback;
    return handleId;
}

void SimpleInterfacePublisherPimpl::unsubscribeFromPropBoolChanged(long handleId)
{
    PropBoolCallbacks.erase(handleId);
}

void SimpleInterfacePublisherPimpl::publishPropBoolChanged(bool propBool) const
{
    for(const auto& Subscriber: ISimpleInterfaceInterfaceSubscribers)
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

long SimpleInterfacePublisherPimpl::subscribeToPropIntChanged(SimpleInterfacePropIntPropertyCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    long handleId = static_cast<long>(PropIntCallbacks.size());
    PropIntCallbacks[handleId] = callback;
    return handleId;
}

void SimpleInterfacePublisherPimpl::unsubscribeFromPropIntChanged(long handleId)
{
    PropIntCallbacks.erase(handleId);
}

void SimpleInterfacePublisherPimpl::publishPropIntChanged(int propInt) const
{
    for(const auto& Subscriber: ISimpleInterfaceInterfaceSubscribers)
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

long SimpleInterfacePublisherPimpl::subscribeToPropFloatChanged(SimpleInterfacePropFloatPropertyCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    long handleId = static_cast<long>(PropFloatCallbacks.size());
    PropFloatCallbacks[handleId] = callback;
    return handleId;
}

void SimpleInterfacePublisherPimpl::unsubscribeFromPropFloatChanged(long handleId)
{
    PropFloatCallbacks.erase(handleId);
}

void SimpleInterfacePublisherPimpl::publishPropFloatChanged(float propFloat) const
{
    for(const auto& Subscriber: ISimpleInterfaceInterfaceSubscribers)
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

long SimpleInterfacePublisherPimpl::subscribeToPropStringChanged(SimpleInterfacePropStringPropertyCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    long handleId = static_cast<long>(PropStringCallbacks.size());
    PropStringCallbacks[handleId] = callback;
    return handleId;
}

void SimpleInterfacePublisherPimpl::unsubscribeFromPropStringChanged(long handleId)
{
    PropStringCallbacks.erase(handleId);
}

void SimpleInterfacePublisherPimpl::publishPropStringChanged(const std::string& propString) const
{
    for(const auto& Subscriber: ISimpleInterfaceInterfaceSubscribers)
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

long SimpleInterfacePublisherPimpl::subscribeToSigBool(SimpleInterfaceSigBoolSignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    long handleId = static_cast<long>(SigBoolCallbacks.size());
    SigBoolCallbacks[handleId] = callback;
    return handleId;
}

void SimpleInterfacePublisherPimpl::unsubscribeFromSigBool(long handleId)
{
    SigBoolCallbacks.erase(handleId);
}

void SimpleInterfacePublisherPimpl::publishSigBool(bool paramBool) const
{
    for(const auto& Subscriber: ISimpleInterfaceInterfaceSubscribers)
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

long SimpleInterfacePublisherPimpl::subscribeToSigInt(SimpleInterfaceSigIntSignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    long handleId = static_cast<long>(SigIntCallbacks.size());
    SigIntCallbacks[handleId] = callback;
    return handleId;
}

void SimpleInterfacePublisherPimpl::unsubscribeFromSigInt(long handleId)
{
    SigIntCallbacks.erase(handleId);
}

void SimpleInterfacePublisherPimpl::publishSigInt(int paramInt) const
{
    for(const auto& Subscriber: ISimpleInterfaceInterfaceSubscribers)
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

long SimpleInterfacePublisherPimpl::subscribeToSigFloat(SimpleInterfaceSigFloatSignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    long handleId = static_cast<long>(SigFloatCallbacks.size());
    SigFloatCallbacks[handleId] = callback;
    return handleId;
}

void SimpleInterfacePublisherPimpl::unsubscribeFromSigFloat(long handleId)
{
    SigFloatCallbacks.erase(handleId);
}

void SimpleInterfacePublisherPimpl::publishSigFloat(float paramFloat) const
{
    for(const auto& Subscriber: ISimpleInterfaceInterfaceSubscribers)
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

long SimpleInterfacePublisherPimpl::subscribeToSigString(SimpleInterfaceSigStringSignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    long handleId = static_cast<long>(SigStringCallbacks.size());
    SigStringCallbacks[handleId] = callback;
    return handleId;
}

void SimpleInterfacePublisherPimpl::unsubscribeFromSigString(long handleId)
{
    SigStringCallbacks.erase(handleId);
}

void SimpleInterfacePublisherPimpl::publishSigString(const std::string& paramString) const
{
    for(const auto& Subscriber: ISimpleInterfaceInterfaceSubscribers)
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
 * Implementation SimpleInterfacePublisher
 */
SimpleInterfacePublisher::SimpleInterfacePublisher()
    : m_impl(std::make_shared<SimpleInterfacePublisherPimpl>())
{
}
SimpleInterfacePublisher::~SimpleInterfacePublisher() = default;

void SimpleInterfacePublisher::subscribeToSimpleInterfaceInterface(ISimpleInterfaceSubscriber& subscriber)
{
    m_impl->subscribeToSimpleInterfaceInterface(subscriber);
}

void SimpleInterfacePublisher::unsubscribeFromSimpleInterfaceInterface(ISimpleInterfaceSubscriber& subscriber)
{
    m_impl->unsubscribeFromSimpleInterfaceInterface(subscriber);
}

long SimpleInterfacePublisher::subscribeToPropBoolChanged(SimpleInterfacePropBoolPropertyCb callback)
{
    return m_impl->subscribeToPropBoolChanged(callback);
}

void SimpleInterfacePublisher::unsubscribeFromPropBoolChanged(long handleId)
{
    m_impl->unsubscribeFromPropBoolChanged(handleId);
}

void SimpleInterfacePublisher::publishPropBoolChanged(bool propBool) const
{
    m_impl->publishPropBoolChanged(propBool);
}

long SimpleInterfacePublisher::subscribeToPropIntChanged(SimpleInterfacePropIntPropertyCb callback)
{
    return m_impl->subscribeToPropIntChanged(callback);
}

void SimpleInterfacePublisher::unsubscribeFromPropIntChanged(long handleId)
{
    m_impl->unsubscribeFromPropIntChanged(handleId);
}

void SimpleInterfacePublisher::publishPropIntChanged(int propInt) const
{
    m_impl->publishPropIntChanged(propInt);
}

long SimpleInterfacePublisher::subscribeToPropFloatChanged(SimpleInterfacePropFloatPropertyCb callback)
{
    return m_impl->subscribeToPropFloatChanged(callback);
}

void SimpleInterfacePublisher::unsubscribeFromPropFloatChanged(long handleId)
{
    m_impl->unsubscribeFromPropFloatChanged(handleId);
}

void SimpleInterfacePublisher::publishPropFloatChanged(float propFloat) const
{
    m_impl->publishPropFloatChanged(propFloat);
}

long SimpleInterfacePublisher::subscribeToPropStringChanged(SimpleInterfacePropStringPropertyCb callback)
{
    return m_impl->subscribeToPropStringChanged(callback);
}

void SimpleInterfacePublisher::unsubscribeFromPropStringChanged(long handleId)
{
    m_impl->unsubscribeFromPropStringChanged(handleId);
}

void SimpleInterfacePublisher::publishPropStringChanged(const std::string& propString) const
{
    m_impl->publishPropStringChanged(propString);
}

long SimpleInterfacePublisher::subscribeToSigBool(SimpleInterfaceSigBoolSignalCb callback)
{
    return m_impl->subscribeToSigBool(callback);
}

void SimpleInterfacePublisher::unsubscribeFromSigBool(long handleId)
{
    m_impl->unsubscribeFromSigBool(handleId);
}

void SimpleInterfacePublisher::publishSigBool(bool paramBool) const
{
    m_impl->publishSigBool(paramBool);
}

long SimpleInterfacePublisher::subscribeToSigInt(SimpleInterfaceSigIntSignalCb callback)
{
    return m_impl->subscribeToSigInt(callback);
}

void SimpleInterfacePublisher::unsubscribeFromSigInt(long handleId)
{
    m_impl->unsubscribeFromSigInt(handleId);
}

void SimpleInterfacePublisher::publishSigInt(int paramInt) const
{
    m_impl->publishSigInt(paramInt);
}

long SimpleInterfacePublisher::subscribeToSigFloat(SimpleInterfaceSigFloatSignalCb callback)
{
    return m_impl->subscribeToSigFloat(callback);
}

void SimpleInterfacePublisher::unsubscribeFromSigFloat(long handleId)
{
    m_impl->unsubscribeFromSigFloat(handleId);
}

void SimpleInterfacePublisher::publishSigFloat(float paramFloat) const
{
    m_impl->publishSigFloat(paramFloat);
}

long SimpleInterfacePublisher::subscribeToSigString(SimpleInterfaceSigStringSignalCb callback)
{
    return m_impl->subscribeToSigString(callback);
}

void SimpleInterfacePublisher::unsubscribeFromSigString(long handleId)
{
    m_impl->unsubscribeFromSigString(handleId);
}

void SimpleInterfacePublisher::publishSigString(const std::string& paramString) const
{
    m_impl->publishSigString(paramString);
}
