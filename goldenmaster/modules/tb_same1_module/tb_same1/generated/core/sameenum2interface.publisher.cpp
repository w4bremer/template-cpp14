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
#include "tb_same1/generated/core/sameenum2interface.publisher.h"


namespace Test {
namespace TbSame1 {
class SameEnum2InterfacePublisherPimpl : public ISameEnum2InterfacePublisher
{
public:
    void subscribeToSameEnum2InterfaceInterface(ISameEnum2InterfaceSubscriber& subscriber) override;
    void unsubscribeFromSameEnum2InterfaceInterface(ISameEnum2InterfaceSubscriber& subscriber) override;

    long subscribeToProp1Changed(SameEnum2InterfaceProp1PropertyCb callback) override;
    void unsubscribeFromProp1Changed(long handleId) override;

    long subscribeToProp2Changed(SameEnum2InterfaceProp2PropertyCb callback) override;
    void unsubscribeFromProp2Changed(long handleId) override;

    long subscribeToSig1(SameEnum2InterfaceSig1SignalCb callback) override;
    void unsubscribeFromSig1(long handleId) override;

    long subscribeToSig2(SameEnum2InterfaceSig2SignalCb callback) override;
    void unsubscribeFromSig2(long handleId) override;

    void publishProp1Changed(const Enum1Enum& prop1) const override;
    void publishProp2Changed(const Enum2Enum& prop2) const override;
    void publishSig1(const Enum1Enum& param1) const override;
    void publishSig2(const Enum1Enum& param1,const Enum2Enum& param2) const override;
private:
    std::set<ISameEnum2InterfaceSubscriber*> ISameEnum2InterfaceInterfaceSubscribers;
    std::map<long, SameEnum2InterfaceProp1PropertyCb> Prop1Callbacks;
    std::map<long, SameEnum2InterfaceProp2PropertyCb> Prop2Callbacks;
    std::map<long, SameEnum2InterfaceSig1SignalCb> Sig1Callbacks;
    std::map<long, SameEnum2InterfaceSig2SignalCb> Sig2Callbacks;
};

} // namespace TbSame1
} // namespace Test

using namespace Test::TbSame1;

/**
 * Implementation SameEnum2InterfacePublisherPimpl
 */
void SameEnum2InterfacePublisherPimpl::subscribeToSameEnum2InterfaceInterface(ISameEnum2InterfaceSubscriber& subscriber)
{
    ISameEnum2InterfaceInterfaceSubscribers.insert(&subscriber);
}

void SameEnum2InterfacePublisherPimpl::unsubscribeFromSameEnum2InterfaceInterface(ISameEnum2InterfaceSubscriber& subscriber)
{
    ISameEnum2InterfaceInterfaceSubscribers.erase(&subscriber);
}

long SameEnum2InterfacePublisherPimpl::subscribeToProp1Changed(SameEnum2InterfaceProp1PropertyCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    long handleId = static_cast<long>(Prop1Callbacks.size());
    Prop1Callbacks[handleId] = callback;
    return handleId;
}

void SameEnum2InterfacePublisherPimpl::unsubscribeFromProp1Changed(long handleId)
{
    Prop1Callbacks.erase(handleId);
}

void SameEnum2InterfacePublisherPimpl::publishProp1Changed(const Enum1Enum& prop1) const
{
    for(const auto& Subscriber: ISameEnum2InterfaceInterfaceSubscribers)
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

long SameEnum2InterfacePublisherPimpl::subscribeToProp2Changed(SameEnum2InterfaceProp2PropertyCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    long handleId = static_cast<long>(Prop2Callbacks.size());
    Prop2Callbacks[handleId] = callback;
    return handleId;
}

void SameEnum2InterfacePublisherPimpl::unsubscribeFromProp2Changed(long handleId)
{
    Prop2Callbacks.erase(handleId);
}

void SameEnum2InterfacePublisherPimpl::publishProp2Changed(const Enum2Enum& prop2) const
{
    for(const auto& Subscriber: ISameEnum2InterfaceInterfaceSubscribers)
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

long SameEnum2InterfacePublisherPimpl::subscribeToSig1(SameEnum2InterfaceSig1SignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    long handleId = static_cast<long>(Sig1Callbacks.size());
    Sig1Callbacks[handleId] = callback;
    return handleId;
}

void SameEnum2InterfacePublisherPimpl::unsubscribeFromSig1(long handleId)
{
    Sig1Callbacks.erase(handleId);
}

void SameEnum2InterfacePublisherPimpl::publishSig1(const Enum1Enum& param1) const
{
    for(const auto& Subscriber: ISameEnum2InterfaceInterfaceSubscribers)
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

long SameEnum2InterfacePublisherPimpl::subscribeToSig2(SameEnum2InterfaceSig2SignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    long handleId = static_cast<long>(Sig2Callbacks.size());
    Sig2Callbacks[handleId] = callback;
    return handleId;
}

void SameEnum2InterfacePublisherPimpl::unsubscribeFromSig2(long handleId)
{
    Sig2Callbacks.erase(handleId);
}

void SameEnum2InterfacePublisherPimpl::publishSig2(const Enum1Enum& param1,const Enum2Enum& param2) const
{
    for(const auto& Subscriber: ISameEnum2InterfaceInterfaceSubscribers)
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
 * Implementation SameEnum2InterfacePublisher
 */
SameEnum2InterfacePublisher::SameEnum2InterfacePublisher()
    : m_impl(std::make_shared<SameEnum2InterfacePublisherPimpl>())
{
}
SameEnum2InterfacePublisher::~SameEnum2InterfacePublisher() = default;

void SameEnum2InterfacePublisher::subscribeToSameEnum2InterfaceInterface(ISameEnum2InterfaceSubscriber& subscriber)
{
    m_impl->subscribeToSameEnum2InterfaceInterface(subscriber);
}

void SameEnum2InterfacePublisher::unsubscribeFromSameEnum2InterfaceInterface(ISameEnum2InterfaceSubscriber& subscriber)
{
    m_impl->unsubscribeFromSameEnum2InterfaceInterface(subscriber);
}

long SameEnum2InterfacePublisher::subscribeToProp1Changed(SameEnum2InterfaceProp1PropertyCb callback)
{
    return m_impl->subscribeToProp1Changed(callback);
}

void SameEnum2InterfacePublisher::unsubscribeFromProp1Changed(long handleId)
{
    m_impl->unsubscribeFromProp1Changed(handleId);
}

void SameEnum2InterfacePublisher::publishProp1Changed(const Enum1Enum& prop1) const
{
    m_impl->publishProp1Changed(prop1);
}

long SameEnum2InterfacePublisher::subscribeToProp2Changed(SameEnum2InterfaceProp2PropertyCb callback)
{
    return m_impl->subscribeToProp2Changed(callback);
}

void SameEnum2InterfacePublisher::unsubscribeFromProp2Changed(long handleId)
{
    m_impl->unsubscribeFromProp2Changed(handleId);
}

void SameEnum2InterfacePublisher::publishProp2Changed(const Enum2Enum& prop2) const
{
    m_impl->publishProp2Changed(prop2);
}

long SameEnum2InterfacePublisher::subscribeToSig1(SameEnum2InterfaceSig1SignalCb callback)
{
    return m_impl->subscribeToSig1(callback);
}

void SameEnum2InterfacePublisher::unsubscribeFromSig1(long handleId)
{
    m_impl->unsubscribeFromSig1(handleId);
}

void SameEnum2InterfacePublisher::publishSig1(const Enum1Enum& param1) const
{
    m_impl->publishSig1(param1);
}

long SameEnum2InterfacePublisher::subscribeToSig2(SameEnum2InterfaceSig2SignalCb callback)
{
    return m_impl->subscribeToSig2(callback);
}

void SameEnum2InterfacePublisher::unsubscribeFromSig2(long handleId)
{
    m_impl->unsubscribeFromSig2(handleId);
}

void SameEnum2InterfacePublisher::publishSig2(const Enum1Enum& param1,const Enum2Enum& param2) const
{
    m_impl->publishSig2(param1,param2);
}
