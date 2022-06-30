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
#include "tb_same2_samestruct1interface.publisher.h"


namespace Test {
namespace TbSame2 {
class SameStruct1InterfacePublisherPimpl : public ISameStruct1InterfacePublisher
{
public:
    void subscribeToSameStruct1InterfaceInterface(ISameStruct1InterfaceSubscriber& subscriber) override;
    void unsubscribeFromSameStruct1InterfaceInterface(ISameStruct1InterfaceSubscriber& subscriber) override;

    long subscribeToProp1Changed(SameStruct1InterfaceProp1PropertyCb callback) override;
    void unsubscribeFromProp1Changed(long handleId) override;

    long subscribeToSig1(SameStruct1InterfaceSig1SignalCb callback) override;
    void unsubscribeFromSig1(long handleId) override;

    void publishProp1Changed(const Struct1& prop1) const override;
    void publishSig1(const Struct1& param1) const override;
private:
    std::set<ISameStruct1InterfaceSubscriber*> ISameStruct1InterfaceInterfaceSubscribers;
    std::map<long, SameStruct1InterfaceProp1PropertyCb> Prop1Callbacks;
    std::map<long, SameStruct1InterfaceSig1SignalCb> Sig1Callbacks;
};

} // namespace TbSame2
} // namespace Test

using namespace Test::TbSame2;

/**
 * Implementation SameStruct1InterfacePublisherPimpl
 */
void SameStruct1InterfacePublisherPimpl::subscribeToSameStruct1InterfaceInterface(ISameStruct1InterfaceSubscriber& subscriber)
{
    ISameStruct1InterfaceInterfaceSubscribers.insert(&subscriber);
}

void SameStruct1InterfacePublisherPimpl::unsubscribeFromSameStruct1InterfaceInterface(ISameStruct1InterfaceSubscriber& subscriber)
{
    ISameStruct1InterfaceInterfaceSubscribers.erase(&subscriber);
}

long SameStruct1InterfacePublisherPimpl::subscribeToProp1Changed(SameStruct1InterfaceProp1PropertyCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    long handleId = static_cast<long>(Prop1Callbacks.size());
    Prop1Callbacks[handleId] = callback;
    return handleId;
}

void SameStruct1InterfacePublisherPimpl::unsubscribeFromProp1Changed(long handleId)
{
    Prop1Callbacks.erase(handleId);
}

void SameStruct1InterfacePublisherPimpl::publishProp1Changed(const Struct1& prop1) const
{
    for(const auto& Subscriber: ISameStruct1InterfaceInterfaceSubscribers)
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

long SameStruct1InterfacePublisherPimpl::subscribeToSig1(SameStruct1InterfaceSig1SignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    long handleId = static_cast<long>(Sig1Callbacks.size());
    Sig1Callbacks[handleId] = callback;
    return handleId;
}

void SameStruct1InterfacePublisherPimpl::unsubscribeFromSig1(long handleId)
{
    Sig1Callbacks.erase(handleId);
}

void SameStruct1InterfacePublisherPimpl::publishSig1(const Struct1& param1) const
{
    for(const auto& Subscriber: ISameStruct1InterfaceInterfaceSubscribers)
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

/**
 * Implementation SameStruct1InterfacePublisher
 */
SameStruct1InterfacePublisher::SameStruct1InterfacePublisher()
    : m_impl(std::make_shared<SameStruct1InterfacePublisherPimpl>())
{
}
SameStruct1InterfacePublisher::~SameStruct1InterfacePublisher() = default;

void SameStruct1InterfacePublisher::subscribeToSameStruct1InterfaceInterface(ISameStruct1InterfaceSubscriber& subscriber)
{
    m_impl->subscribeToSameStruct1InterfaceInterface(subscriber);
}

void SameStruct1InterfacePublisher::unsubscribeFromSameStruct1InterfaceInterface(ISameStruct1InterfaceSubscriber& subscriber)
{
    m_impl->unsubscribeFromSameStruct1InterfaceInterface(subscriber);
}

long SameStruct1InterfacePublisher::subscribeToProp1Changed(SameStruct1InterfaceProp1PropertyCb callback)
{
    return m_impl->subscribeToProp1Changed(callback);
}

void SameStruct1InterfacePublisher::unsubscribeFromProp1Changed(long handleId)
{
    m_impl->unsubscribeFromProp1Changed(handleId);
}

void SameStruct1InterfacePublisher::publishProp1Changed(const Struct1& prop1) const
{
    m_impl->publishProp1Changed(prop1);
}

long SameStruct1InterfacePublisher::subscribeToSig1(SameStruct1InterfaceSig1SignalCb callback)
{
    return m_impl->subscribeToSig1(callback);
}

void SameStruct1InterfacePublisher::unsubscribeFromSig1(long handleId)
{
    m_impl->unsubscribeFromSig1(handleId);
}

void SameStruct1InterfacePublisher::publishSig1(const Struct1& param1) const
{
    m_impl->publishSig1(param1);
}
