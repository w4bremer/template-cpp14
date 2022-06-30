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
#include "tb_same1_sameenum1interface.publisher.h"


namespace Test {
namespace TbSame1 {
class SameEnum1InterfacePublisherPimpl : public ISameEnum1InterfacePublisher
{
public:
    void subscribeToSameEnum1InterfaceInterface(ISameEnum1InterfaceSubscriber& subscriber) override;
    void unsubscribeFromSameEnum1InterfaceInterface(ISameEnum1InterfaceSubscriber& subscriber) override;

    long subscribeToProp1Changed(SameEnum1InterfaceProp1PropertyCb callback) override;
    void unsubscribeFromProp1Changed(long handleId) override;

    long subscribeToSig1(SameEnum1InterfaceSig1SignalCb callback) override;
    void unsubscribeFromSig1(long handleId) override;

    void publishProp1Changed(const Enum1Enum& prop1) const override;
    void publishSig1(const Enum1Enum& param1) const override;
private:
    std::set<ISameEnum1InterfaceSubscriber*> ISameEnum1InterfaceInterfaceSubscribers;
    std::map<long, SameEnum1InterfaceProp1PropertyCb> Prop1Callbacks;
    std::map<long, SameEnum1InterfaceSig1SignalCb> Sig1Callbacks;
};

} // namespace TbSame1
} // namespace Test

using namespace Test::TbSame1;

/**
 * Implementation SameEnum1InterfacePublisherPimpl
 */
void SameEnum1InterfacePublisherPimpl::subscribeToSameEnum1InterfaceInterface(ISameEnum1InterfaceSubscriber& subscriber)
{
    ISameEnum1InterfaceInterfaceSubscribers.insert(&subscriber);
}

void SameEnum1InterfacePublisherPimpl::unsubscribeFromSameEnum1InterfaceInterface(ISameEnum1InterfaceSubscriber& subscriber)
{
    ISameEnum1InterfaceInterfaceSubscribers.erase(&subscriber);
}

long SameEnum1InterfacePublisherPimpl::subscribeToProp1Changed(SameEnum1InterfaceProp1PropertyCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    long handleId = static_cast<long>(Prop1Callbacks.size());
    Prop1Callbacks[handleId] = callback;
    return handleId;
}

void SameEnum1InterfacePublisherPimpl::unsubscribeFromProp1Changed(long handleId)
{
    Prop1Callbacks.erase(handleId);
}

void SameEnum1InterfacePublisherPimpl::publishProp1Changed(const Enum1Enum& prop1) const
{
    for(const auto& Subscriber: ISameEnum1InterfaceInterfaceSubscribers)
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

long SameEnum1InterfacePublisherPimpl::subscribeToSig1(SameEnum1InterfaceSig1SignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    long handleId = static_cast<long>(Sig1Callbacks.size());
    Sig1Callbacks[handleId] = callback;
    return handleId;
}

void SameEnum1InterfacePublisherPimpl::unsubscribeFromSig1(long handleId)
{
    Sig1Callbacks.erase(handleId);
}

void SameEnum1InterfacePublisherPimpl::publishSig1(const Enum1Enum& param1) const
{
    for(const auto& Subscriber: ISameEnum1InterfaceInterfaceSubscribers)
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
 * Implementation SameEnum1InterfacePublisher
 */
SameEnum1InterfacePublisher::SameEnum1InterfacePublisher()
    : m_impl(std::make_shared<SameEnum1InterfacePublisherPimpl>())
{
}
SameEnum1InterfacePublisher::~SameEnum1InterfacePublisher() = default;

void SameEnum1InterfacePublisher::subscribeToSameEnum1InterfaceInterface(ISameEnum1InterfaceSubscriber& subscriber)
{
    m_impl->subscribeToSameEnum1InterfaceInterface(subscriber);
}

void SameEnum1InterfacePublisher::unsubscribeFromSameEnum1InterfaceInterface(ISameEnum1InterfaceSubscriber& subscriber)
{
    m_impl->unsubscribeFromSameEnum1InterfaceInterface(subscriber);
}

long SameEnum1InterfacePublisher::subscribeToProp1Changed(SameEnum1InterfaceProp1PropertyCb callback)
{
    return m_impl->subscribeToProp1Changed(callback);
}

void SameEnum1InterfacePublisher::unsubscribeFromProp1Changed(long handleId)
{
    m_impl->unsubscribeFromProp1Changed(handleId);
}

void SameEnum1InterfacePublisher::publishProp1Changed(const Enum1Enum& prop1) const
{
    m_impl->publishProp1Changed(prop1);
}

long SameEnum1InterfacePublisher::subscribeToSig1(SameEnum1InterfaceSig1SignalCb callback)
{
    return m_impl->subscribeToSig1(callback);
}

void SameEnum1InterfacePublisher::unsubscribeFromSig1(long handleId)
{
    m_impl->unsubscribeFromSig1(handleId);
}

void SameEnum1InterfacePublisher::publishSig1(const Enum1Enum& param1) const
{
    m_impl->publishSig1(param1);
}
