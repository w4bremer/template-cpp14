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
#include "testbed2/generated/core/nestedstruct2interface.publisher.h"


namespace Test {
namespace Testbed2 {
class NestedStruct2InterfacePublisherPimpl : public INestedStruct2InterfacePublisher
{
public:
    void subscribeToNestedStruct2InterfaceInterface(INestedStruct2InterfaceSubscriber& subscriber) override;
    void unsubscribeFromNestedStruct2InterfaceInterface(INestedStruct2InterfaceSubscriber& subscriber) override;

    long subscribeToProp1Changed(NestedStruct2InterfaceProp1PropertyCb callback) override;
    void unsubscribeFromProp1Changed(long handleId) override;

    long subscribeToProp2Changed(NestedStruct2InterfaceProp2PropertyCb callback) override;
    void unsubscribeFromProp2Changed(long handleId) override;

    long subscribeToSig1(NestedStruct2InterfaceSig1SignalCb callback) override;
    void unsubscribeFromSig1(long handleId) override;

    long subscribeToSig2(NestedStruct2InterfaceSig2SignalCb callback) override;
    void unsubscribeFromSig2(long handleId) override;

    void publishProp1Changed(const NestedStruct1& prop1) const override;
    void publishProp2Changed(const NestedStruct2& prop2) const override;
    void publishSig1(const NestedStruct1& param1) const override;
    void publishSig2(const NestedStruct1& param1,const NestedStruct2& param2) const override;
private:
    std::set<INestedStruct2InterfaceSubscriber*> INestedStruct2InterfaceInterfaceSubscribers;
    std::map<long, NestedStruct2InterfaceProp1PropertyCb> Prop1Callbacks;
    std::map<long, NestedStruct2InterfaceProp2PropertyCb> Prop2Callbacks;
    std::map<long, NestedStruct2InterfaceSig1SignalCb> Sig1Callbacks;
    std::map<long, NestedStruct2InterfaceSig2SignalCb> Sig2Callbacks;
};

} // namespace Testbed2
} // namespace Test

using namespace Test::Testbed2;

/**
 * Implementation NestedStruct2InterfacePublisherPimpl
 */
void NestedStruct2InterfacePublisherPimpl::subscribeToNestedStruct2InterfaceInterface(INestedStruct2InterfaceSubscriber& subscriber)
{
    INestedStruct2InterfaceInterfaceSubscribers.insert(&subscriber);
}

void NestedStruct2InterfacePublisherPimpl::unsubscribeFromNestedStruct2InterfaceInterface(INestedStruct2InterfaceSubscriber& subscriber)
{
    INestedStruct2InterfaceInterfaceSubscribers.erase(&subscriber);
}

long NestedStruct2InterfacePublisherPimpl::subscribeToProp1Changed(NestedStruct2InterfaceProp1PropertyCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    long handleId = static_cast<long>(Prop1Callbacks.size());
    Prop1Callbacks[handleId] = callback;
    return handleId;
}

void NestedStruct2InterfacePublisherPimpl::unsubscribeFromProp1Changed(long handleId)
{
    Prop1Callbacks.erase(handleId);
}

void NestedStruct2InterfacePublisherPimpl::publishProp1Changed(const NestedStruct1& prop1) const
{
    for(const auto& Subscriber: INestedStruct2InterfaceInterfaceSubscribers)
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

long NestedStruct2InterfacePublisherPimpl::subscribeToProp2Changed(NestedStruct2InterfaceProp2PropertyCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    long handleId = static_cast<long>(Prop2Callbacks.size());
    Prop2Callbacks[handleId] = callback;
    return handleId;
}

void NestedStruct2InterfacePublisherPimpl::unsubscribeFromProp2Changed(long handleId)
{
    Prop2Callbacks.erase(handleId);
}

void NestedStruct2InterfacePublisherPimpl::publishProp2Changed(const NestedStruct2& prop2) const
{
    for(const auto& Subscriber: INestedStruct2InterfaceInterfaceSubscribers)
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

long NestedStruct2InterfacePublisherPimpl::subscribeToSig1(NestedStruct2InterfaceSig1SignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    long handleId = static_cast<long>(Sig1Callbacks.size());
    Sig1Callbacks[handleId] = callback;
    return handleId;
}

void NestedStruct2InterfacePublisherPimpl::unsubscribeFromSig1(long handleId)
{
    Sig1Callbacks.erase(handleId);
}

void NestedStruct2InterfacePublisherPimpl::publishSig1(const NestedStruct1& param1) const
{
    for(const auto& Subscriber: INestedStruct2InterfaceInterfaceSubscribers)
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

long NestedStruct2InterfacePublisherPimpl::subscribeToSig2(NestedStruct2InterfaceSig2SignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    long handleId = static_cast<long>(Sig2Callbacks.size());
    Sig2Callbacks[handleId] = callback;
    return handleId;
}

void NestedStruct2InterfacePublisherPimpl::unsubscribeFromSig2(long handleId)
{
    Sig2Callbacks.erase(handleId);
}

void NestedStruct2InterfacePublisherPimpl::publishSig2(const NestedStruct1& param1,const NestedStruct2& param2) const
{
    for(const auto& Subscriber: INestedStruct2InterfaceInterfaceSubscribers)
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

/**
 * Implementation NestedStruct2InterfacePublisher
 */
NestedStruct2InterfacePublisher::NestedStruct2InterfacePublisher()
    : m_impl(std::make_shared<NestedStruct2InterfacePublisherPimpl>())
{
}
NestedStruct2InterfacePublisher::~NestedStruct2InterfacePublisher() = default;

void NestedStruct2InterfacePublisher::subscribeToNestedStruct2InterfaceInterface(INestedStruct2InterfaceSubscriber& subscriber)
{
    m_impl->subscribeToNestedStruct2InterfaceInterface(subscriber);
}

void NestedStruct2InterfacePublisher::unsubscribeFromNestedStruct2InterfaceInterface(INestedStruct2InterfaceSubscriber& subscriber)
{
    m_impl->unsubscribeFromNestedStruct2InterfaceInterface(subscriber);
}

long NestedStruct2InterfacePublisher::subscribeToProp1Changed(NestedStruct2InterfaceProp1PropertyCb callback)
{
    return m_impl->subscribeToProp1Changed(callback);
}

void NestedStruct2InterfacePublisher::unsubscribeFromProp1Changed(long handleId)
{
    m_impl->unsubscribeFromProp1Changed(handleId);
}

void NestedStruct2InterfacePublisher::publishProp1Changed(const NestedStruct1& prop1) const
{
    m_impl->publishProp1Changed(prop1);
}

long NestedStruct2InterfacePublisher::subscribeToProp2Changed(NestedStruct2InterfaceProp2PropertyCb callback)
{
    return m_impl->subscribeToProp2Changed(callback);
}

void NestedStruct2InterfacePublisher::unsubscribeFromProp2Changed(long handleId)
{
    m_impl->unsubscribeFromProp2Changed(handleId);
}

void NestedStruct2InterfacePublisher::publishProp2Changed(const NestedStruct2& prop2) const
{
    m_impl->publishProp2Changed(prop2);
}

long NestedStruct2InterfacePublisher::subscribeToSig1(NestedStruct2InterfaceSig1SignalCb callback)
{
    return m_impl->subscribeToSig1(callback);
}

void NestedStruct2InterfacePublisher::unsubscribeFromSig1(long handleId)
{
    m_impl->unsubscribeFromSig1(handleId);
}

void NestedStruct2InterfacePublisher::publishSig1(const NestedStruct1& param1) const
{
    m_impl->publishSig1(param1);
}

long NestedStruct2InterfacePublisher::subscribeToSig2(NestedStruct2InterfaceSig2SignalCb callback)
{
    return m_impl->subscribeToSig2(callback);
}

void NestedStruct2InterfacePublisher::unsubscribeFromSig2(long handleId)
{
    m_impl->unsubscribeFromSig2(handleId);
}

void NestedStruct2InterfacePublisher::publishSig2(const NestedStruct1& param1,const NestedStruct2& param2) const
{
    m_impl->publishSig2(param1,param2);
}
