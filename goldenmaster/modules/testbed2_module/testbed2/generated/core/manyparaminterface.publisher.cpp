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
#include "testbed2/generated/core/manyparaminterface.publisher.h"


namespace Test {
namespace Testbed2 {
class ManyParamInterfacePublisherPimpl : public IManyParamInterfacePublisher
{
public:
    void subscribeToManyParamInterfaceInterface(IManyParamInterfaceSubscriber& subscriber) override;
    void unsubscribeFromManyParamInterfaceInterface(IManyParamInterfaceSubscriber& subscriber) override;

    long subscribeToProp1Changed(ManyParamInterfaceProp1PropertyCb callback) override;
    void unsubscribeFromProp1Changed(long handleId) override;

    long subscribeToProp2Changed(ManyParamInterfaceProp2PropertyCb callback) override;
    void unsubscribeFromProp2Changed(long handleId) override;

    long subscribeToProp3Changed(ManyParamInterfaceProp3PropertyCb callback) override;
    void unsubscribeFromProp3Changed(long handleId) override;

    long subscribeToProp4Changed(ManyParamInterfaceProp4PropertyCb callback) override;
    void unsubscribeFromProp4Changed(long handleId) override;

    long subscribeToSig1(ManyParamInterfaceSig1SignalCb callback) override;
    void unsubscribeFromSig1(long handleId) override;

    long subscribeToSig2(ManyParamInterfaceSig2SignalCb callback) override;
    void unsubscribeFromSig2(long handleId) override;

    long subscribeToSig3(ManyParamInterfaceSig3SignalCb callback) override;
    void unsubscribeFromSig3(long handleId) override;

    long subscribeToSig4(ManyParamInterfaceSig4SignalCb callback) override;
    void unsubscribeFromSig4(long handleId) override;

    void publishProp1Changed(int prop1) const override;
    void publishProp2Changed(int prop2) const override;
    void publishProp3Changed(int prop3) const override;
    void publishProp4Changed(int prop4) const override;
    void publishSig1(int param1) const override;
    void publishSig2(int param1,int param2) const override;
    void publishSig3(int param1,int param2,int param3) const override;
    void publishSig4(int param1,int param2,int param3,int param4) const override;
private:
    std::set<IManyParamInterfaceSubscriber*> IManyParamInterfaceInterfaceSubscribers;
    std::map<long, ManyParamInterfaceProp1PropertyCb> Prop1Callbacks;
    std::map<long, ManyParamInterfaceProp2PropertyCb> Prop2Callbacks;
    std::map<long, ManyParamInterfaceProp3PropertyCb> Prop3Callbacks;
    std::map<long, ManyParamInterfaceProp4PropertyCb> Prop4Callbacks;
    std::map<long, ManyParamInterfaceSig1SignalCb> Sig1Callbacks;
    std::map<long, ManyParamInterfaceSig2SignalCb> Sig2Callbacks;
    std::map<long, ManyParamInterfaceSig3SignalCb> Sig3Callbacks;
    std::map<long, ManyParamInterfaceSig4SignalCb> Sig4Callbacks;
};

} // namespace Testbed2
} // namespace Test

using namespace Test::Testbed2;

/**
 * Implementation ManyParamInterfacePublisherPimpl
 */
void ManyParamInterfacePublisherPimpl::subscribeToManyParamInterfaceInterface(IManyParamInterfaceSubscriber& subscriber)
{
    IManyParamInterfaceInterfaceSubscribers.insert(&subscriber);
}

void ManyParamInterfacePublisherPimpl::unsubscribeFromManyParamInterfaceInterface(IManyParamInterfaceSubscriber& subscriber)
{
    IManyParamInterfaceInterfaceSubscribers.erase(&subscriber);
}

long ManyParamInterfacePublisherPimpl::subscribeToProp1Changed(ManyParamInterfaceProp1PropertyCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    long handleId = static_cast<long>(Prop1Callbacks.size());
    Prop1Callbacks[handleId] = callback;
    return handleId;
}

void ManyParamInterfacePublisherPimpl::unsubscribeFromProp1Changed(long handleId)
{
    Prop1Callbacks.erase(handleId);
}

void ManyParamInterfacePublisherPimpl::publishProp1Changed(int prop1) const
{
    for(const auto& Subscriber: IManyParamInterfaceInterfaceSubscribers)
    {
        Subscriber->OnProp1Changed(prop1);
    }
    for(const auto& callbackEntry: Prop1Callbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(prop1);
        }
    }
}

long ManyParamInterfacePublisherPimpl::subscribeToProp2Changed(ManyParamInterfaceProp2PropertyCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    long handleId = static_cast<long>(Prop2Callbacks.size());
    Prop2Callbacks[handleId] = callback;
    return handleId;
}

void ManyParamInterfacePublisherPimpl::unsubscribeFromProp2Changed(long handleId)
{
    Prop2Callbacks.erase(handleId);
}

void ManyParamInterfacePublisherPimpl::publishProp2Changed(int prop2) const
{
    for(const auto& Subscriber: IManyParamInterfaceInterfaceSubscribers)
    {
        Subscriber->OnProp2Changed(prop2);
    }
    for(const auto& callbackEntry: Prop2Callbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(prop2);
        }
    }
}

long ManyParamInterfacePublisherPimpl::subscribeToProp3Changed(ManyParamInterfaceProp3PropertyCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    long handleId = static_cast<long>(Prop3Callbacks.size());
    Prop3Callbacks[handleId] = callback;
    return handleId;
}

void ManyParamInterfacePublisherPimpl::unsubscribeFromProp3Changed(long handleId)
{
    Prop3Callbacks.erase(handleId);
}

void ManyParamInterfacePublisherPimpl::publishProp3Changed(int prop3) const
{
    for(const auto& Subscriber: IManyParamInterfaceInterfaceSubscribers)
    {
        Subscriber->OnProp3Changed(prop3);
    }
    for(const auto& callbackEntry: Prop3Callbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(prop3);
        }
    }
}

long ManyParamInterfacePublisherPimpl::subscribeToProp4Changed(ManyParamInterfaceProp4PropertyCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    long handleId = static_cast<long>(Prop4Callbacks.size());
    Prop4Callbacks[handleId] = callback;
    return handleId;
}

void ManyParamInterfacePublisherPimpl::unsubscribeFromProp4Changed(long handleId)
{
    Prop4Callbacks.erase(handleId);
}

void ManyParamInterfacePublisherPimpl::publishProp4Changed(int prop4) const
{
    for(const auto& Subscriber: IManyParamInterfaceInterfaceSubscribers)
    {
        Subscriber->OnProp4Changed(prop4);
    }
    for(const auto& callbackEntry: Prop4Callbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(prop4);
        }
    }
}

long ManyParamInterfacePublisherPimpl::subscribeToSig1(ManyParamInterfaceSig1SignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    long handleId = static_cast<long>(Sig1Callbacks.size());
    Sig1Callbacks[handleId] = callback;
    return handleId;
}

void ManyParamInterfacePublisherPimpl::unsubscribeFromSig1(long handleId)
{
    Sig1Callbacks.erase(handleId);
}

void ManyParamInterfacePublisherPimpl::publishSig1(int param1) const
{
    for(const auto& Subscriber: IManyParamInterfaceInterfaceSubscribers)
    {
        Subscriber->OnSig1(param1);
    }
    for(const auto& callbackEntry: Sig1Callbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(param1);
        }
    }
}

long ManyParamInterfacePublisherPimpl::subscribeToSig2(ManyParamInterfaceSig2SignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    long handleId = static_cast<long>(Sig2Callbacks.size());
    Sig2Callbacks[handleId] = callback;
    return handleId;
}

void ManyParamInterfacePublisherPimpl::unsubscribeFromSig2(long handleId)
{
    Sig2Callbacks.erase(handleId);
}

void ManyParamInterfacePublisherPimpl::publishSig2(int param1,int param2) const
{
    for(const auto& Subscriber: IManyParamInterfaceInterfaceSubscribers)
    {
        Subscriber->OnSig2(param1,param2);
    }
    for(const auto& callbackEntry: Sig2Callbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(param1,param2);
        }
    }
}

long ManyParamInterfacePublisherPimpl::subscribeToSig3(ManyParamInterfaceSig3SignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    long handleId = static_cast<long>(Sig3Callbacks.size());
    Sig3Callbacks[handleId] = callback;
    return handleId;
}

void ManyParamInterfacePublisherPimpl::unsubscribeFromSig3(long handleId)
{
    Sig3Callbacks.erase(handleId);
}

void ManyParamInterfacePublisherPimpl::publishSig3(int param1,int param2,int param3) const
{
    for(const auto& Subscriber: IManyParamInterfaceInterfaceSubscribers)
    {
        Subscriber->OnSig3(param1,param2,param3);
    }
    for(const auto& callbackEntry: Sig3Callbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(param1,param2,param3);
        }
    }
}

long ManyParamInterfacePublisherPimpl::subscribeToSig4(ManyParamInterfaceSig4SignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    long handleId = static_cast<long>(Sig4Callbacks.size());
    Sig4Callbacks[handleId] = callback;
    return handleId;
}

void ManyParamInterfacePublisherPimpl::unsubscribeFromSig4(long handleId)
{
    Sig4Callbacks.erase(handleId);
}

void ManyParamInterfacePublisherPimpl::publishSig4(int param1,int param2,int param3,int param4) const
{
    for(const auto& Subscriber: IManyParamInterfaceInterfaceSubscribers)
    {
        Subscriber->OnSig4(param1,param2,param3,param4);
    }
    for(const auto& callbackEntry: Sig4Callbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(param1,param2,param3,param4);
        }
    }
}

/**
 * Implementation ManyParamInterfacePublisher
 */
ManyParamInterfacePublisher::ManyParamInterfacePublisher()
    : m_impl(std::make_shared<ManyParamInterfacePublisherPimpl>())
{
}
ManyParamInterfacePublisher::~ManyParamInterfacePublisher() = default;

void ManyParamInterfacePublisher::subscribeToManyParamInterfaceInterface(IManyParamInterfaceSubscriber& subscriber)
{
    m_impl->subscribeToManyParamInterfaceInterface(subscriber);
}

void ManyParamInterfacePublisher::unsubscribeFromManyParamInterfaceInterface(IManyParamInterfaceSubscriber& subscriber)
{
    m_impl->unsubscribeFromManyParamInterfaceInterface(subscriber);
}

long ManyParamInterfacePublisher::subscribeToProp1Changed(ManyParamInterfaceProp1PropertyCb callback)
{
    return m_impl->subscribeToProp1Changed(callback);
}

void ManyParamInterfacePublisher::unsubscribeFromProp1Changed(long handleId)
{
    m_impl->unsubscribeFromProp1Changed(handleId);
}

void ManyParamInterfacePublisher::publishProp1Changed(int prop1) const
{
    m_impl->publishProp1Changed(prop1);
}

long ManyParamInterfacePublisher::subscribeToProp2Changed(ManyParamInterfaceProp2PropertyCb callback)
{
    return m_impl->subscribeToProp2Changed(callback);
}

void ManyParamInterfacePublisher::unsubscribeFromProp2Changed(long handleId)
{
    m_impl->unsubscribeFromProp2Changed(handleId);
}

void ManyParamInterfacePublisher::publishProp2Changed(int prop2) const
{
    m_impl->publishProp2Changed(prop2);
}

long ManyParamInterfacePublisher::subscribeToProp3Changed(ManyParamInterfaceProp3PropertyCb callback)
{
    return m_impl->subscribeToProp3Changed(callback);
}

void ManyParamInterfacePublisher::unsubscribeFromProp3Changed(long handleId)
{
    m_impl->unsubscribeFromProp3Changed(handleId);
}

void ManyParamInterfacePublisher::publishProp3Changed(int prop3) const
{
    m_impl->publishProp3Changed(prop3);
}

long ManyParamInterfacePublisher::subscribeToProp4Changed(ManyParamInterfaceProp4PropertyCb callback)
{
    return m_impl->subscribeToProp4Changed(callback);
}

void ManyParamInterfacePublisher::unsubscribeFromProp4Changed(long handleId)
{
    m_impl->unsubscribeFromProp4Changed(handleId);
}

void ManyParamInterfacePublisher::publishProp4Changed(int prop4) const
{
    m_impl->publishProp4Changed(prop4);
}

long ManyParamInterfacePublisher::subscribeToSig1(ManyParamInterfaceSig1SignalCb callback)
{
    return m_impl->subscribeToSig1(callback);
}

void ManyParamInterfacePublisher::unsubscribeFromSig1(long handleId)
{
    m_impl->unsubscribeFromSig1(handleId);
}

void ManyParamInterfacePublisher::publishSig1(int param1) const
{
    m_impl->publishSig1(param1);
}

long ManyParamInterfacePublisher::subscribeToSig2(ManyParamInterfaceSig2SignalCb callback)
{
    return m_impl->subscribeToSig2(callback);
}

void ManyParamInterfacePublisher::unsubscribeFromSig2(long handleId)
{
    m_impl->unsubscribeFromSig2(handleId);
}

void ManyParamInterfacePublisher::publishSig2(int param1,int param2) const
{
    m_impl->publishSig2(param1,param2);
}

long ManyParamInterfacePublisher::subscribeToSig3(ManyParamInterfaceSig3SignalCb callback)
{
    return m_impl->subscribeToSig3(callback);
}

void ManyParamInterfacePublisher::unsubscribeFromSig3(long handleId)
{
    m_impl->unsubscribeFromSig3(handleId);
}

void ManyParamInterfacePublisher::publishSig3(int param1,int param2,int param3) const
{
    m_impl->publishSig3(param1,param2,param3);
}

long ManyParamInterfacePublisher::subscribeToSig4(ManyParamInterfaceSig4SignalCb callback)
{
    return m_impl->subscribeToSig4(callback);
}

void ManyParamInterfacePublisher::unsubscribeFromSig4(long handleId)
{
    m_impl->unsubscribeFromSig4(handleId);
}

void ManyParamInterfacePublisher::publishSig4(int param1,int param2,int param3,int param4) const
{
    m_impl->publishSig4(param1,param2,param3,param4);
}
