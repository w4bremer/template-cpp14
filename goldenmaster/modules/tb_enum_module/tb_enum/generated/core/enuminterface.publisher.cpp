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
#include "tb_enum/generated/core/enuminterface.publisher.h"


namespace Test {
namespace TbEnum {
class EnumInterfacePublisherPimpl : public IEnumInterfacePublisher
{
public:
    void subscribeToEnumInterfaceInterface(IEnumInterfaceSubscriber& subscriber) override;
    void unsubscribeFromEnumInterfaceInterface(IEnumInterfaceSubscriber& subscriber) override;

    long subscribeToProp0Changed(EnumInterfaceProp0PropertyCb callback) override;
    void unsubscribeFromProp0Changed(long handleId) override;

    long subscribeToProp1Changed(EnumInterfaceProp1PropertyCb callback) override;
    void unsubscribeFromProp1Changed(long handleId) override;

    long subscribeToProp2Changed(EnumInterfaceProp2PropertyCb callback) override;
    void unsubscribeFromProp2Changed(long handleId) override;

    long subscribeToProp3Changed(EnumInterfaceProp3PropertyCb callback) override;
    void unsubscribeFromProp3Changed(long handleId) override;

    long subscribeToSig0(EnumInterfaceSig0SignalCb callback) override;
    void unsubscribeFromSig0(long handleId) override;

    long subscribeToSig1(EnumInterfaceSig1SignalCb callback) override;
    void unsubscribeFromSig1(long handleId) override;

    long subscribeToSig2(EnumInterfaceSig2SignalCb callback) override;
    void unsubscribeFromSig2(long handleId) override;

    long subscribeToSig3(EnumInterfaceSig3SignalCb callback) override;
    void unsubscribeFromSig3(long handleId) override;

    void publishProp0Changed(const Enum0Enum& prop0) const override;
    void publishProp1Changed(const Enum1Enum& prop1) const override;
    void publishProp2Changed(const Enum2Enum& prop2) const override;
    void publishProp3Changed(const Enum3Enum& prop3) const override;
    void publishSig0(const Enum0Enum& param0) const override;
    void publishSig1(const Enum1Enum& param1) const override;
    void publishSig2(const Enum2Enum& param2) const override;
    void publishSig3(const Enum3Enum& param3) const override;
private:
    std::set<IEnumInterfaceSubscriber*> IEnumInterfaceInterfaceSubscribers;
    std::map<long, EnumInterfaceProp0PropertyCb> Prop0Callbacks;
    std::map<long, EnumInterfaceProp1PropertyCb> Prop1Callbacks;
    std::map<long, EnumInterfaceProp2PropertyCb> Prop2Callbacks;
    std::map<long, EnumInterfaceProp3PropertyCb> Prop3Callbacks;
    std::map<long, EnumInterfaceSig0SignalCb> Sig0Callbacks;
    std::map<long, EnumInterfaceSig1SignalCb> Sig1Callbacks;
    std::map<long, EnumInterfaceSig2SignalCb> Sig2Callbacks;
    std::map<long, EnumInterfaceSig3SignalCb> Sig3Callbacks;
};

} // namespace TbEnum
} // namespace Test

using namespace Test::TbEnum;

/**
 * Implementation EnumInterfacePublisherPimpl
 */
void EnumInterfacePublisherPimpl::subscribeToEnumInterfaceInterface(IEnumInterfaceSubscriber& subscriber)
{
    IEnumInterfaceInterfaceSubscribers.insert(&subscriber);
}

void EnumInterfacePublisherPimpl::unsubscribeFromEnumInterfaceInterface(IEnumInterfaceSubscriber& subscriber)
{
    IEnumInterfaceInterfaceSubscribers.erase(&subscriber);
}

long EnumInterfacePublisherPimpl::subscribeToProp0Changed(EnumInterfaceProp0PropertyCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    long handleId = static_cast<long>(Prop0Callbacks.size());
    Prop0Callbacks[handleId] = callback;
    return handleId;
}

void EnumInterfacePublisherPimpl::unsubscribeFromProp0Changed(long handleId)
{
    Prop0Callbacks.erase(handleId);
}

void EnumInterfacePublisherPimpl::publishProp0Changed(const Enum0Enum& prop0) const
{
    for(const auto& Subscriber: IEnumInterfaceInterfaceSubscribers)
    {
        Subscriber->OnProp0Changed(prop0);
    }
    for(const auto& callbackEntry: Prop0Callbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(prop0);
        }
    }
}

long EnumInterfacePublisherPimpl::subscribeToProp1Changed(EnumInterfaceProp1PropertyCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    long handleId = static_cast<long>(Prop1Callbacks.size());
    Prop1Callbacks[handleId] = callback;
    return handleId;
}

void EnumInterfacePublisherPimpl::unsubscribeFromProp1Changed(long handleId)
{
    Prop1Callbacks.erase(handleId);
}

void EnumInterfacePublisherPimpl::publishProp1Changed(const Enum1Enum& prop1) const
{
    for(const auto& Subscriber: IEnumInterfaceInterfaceSubscribers)
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

long EnumInterfacePublisherPimpl::subscribeToProp2Changed(EnumInterfaceProp2PropertyCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    long handleId = static_cast<long>(Prop2Callbacks.size());
    Prop2Callbacks[handleId] = callback;
    return handleId;
}

void EnumInterfacePublisherPimpl::unsubscribeFromProp2Changed(long handleId)
{
    Prop2Callbacks.erase(handleId);
}

void EnumInterfacePublisherPimpl::publishProp2Changed(const Enum2Enum& prop2) const
{
    for(const auto& Subscriber: IEnumInterfaceInterfaceSubscribers)
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

long EnumInterfacePublisherPimpl::subscribeToProp3Changed(EnumInterfaceProp3PropertyCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    long handleId = static_cast<long>(Prop3Callbacks.size());
    Prop3Callbacks[handleId] = callback;
    return handleId;
}

void EnumInterfacePublisherPimpl::unsubscribeFromProp3Changed(long handleId)
{
    Prop3Callbacks.erase(handleId);
}

void EnumInterfacePublisherPimpl::publishProp3Changed(const Enum3Enum& prop3) const
{
    for(const auto& Subscriber: IEnumInterfaceInterfaceSubscribers)
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

long EnumInterfacePublisherPimpl::subscribeToSig0(EnumInterfaceSig0SignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    long handleId = static_cast<long>(Sig0Callbacks.size());
    Sig0Callbacks[handleId] = callback;
    return handleId;
}

void EnumInterfacePublisherPimpl::unsubscribeFromSig0(long handleId)
{
    Sig0Callbacks.erase(handleId);
}

void EnumInterfacePublisherPimpl::publishSig0(const Enum0Enum& param0) const
{
    for(const auto& Subscriber: IEnumInterfaceInterfaceSubscribers)
    {
        Subscriber->OnSig0(param0);
    }
    for(const auto& callbackEntry: Sig0Callbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(param0);
        }
    }
}

long EnumInterfacePublisherPimpl::subscribeToSig1(EnumInterfaceSig1SignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    long handleId = static_cast<long>(Sig1Callbacks.size());
    Sig1Callbacks[handleId] = callback;
    return handleId;
}

void EnumInterfacePublisherPimpl::unsubscribeFromSig1(long handleId)
{
    Sig1Callbacks.erase(handleId);
}

void EnumInterfacePublisherPimpl::publishSig1(const Enum1Enum& param1) const
{
    for(const auto& Subscriber: IEnumInterfaceInterfaceSubscribers)
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

long EnumInterfacePublisherPimpl::subscribeToSig2(EnumInterfaceSig2SignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    long handleId = static_cast<long>(Sig2Callbacks.size());
    Sig2Callbacks[handleId] = callback;
    return handleId;
}

void EnumInterfacePublisherPimpl::unsubscribeFromSig2(long handleId)
{
    Sig2Callbacks.erase(handleId);
}

void EnumInterfacePublisherPimpl::publishSig2(const Enum2Enum& param2) const
{
    for(const auto& Subscriber: IEnumInterfaceInterfaceSubscribers)
    {
        Subscriber->OnSig2(param2);
    }
    for(const auto& callbackEntry: Sig2Callbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(param2);
        }
    }
}

long EnumInterfacePublisherPimpl::subscribeToSig3(EnumInterfaceSig3SignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    long handleId = static_cast<long>(Sig3Callbacks.size());
    Sig3Callbacks[handleId] = callback;
    return handleId;
}

void EnumInterfacePublisherPimpl::unsubscribeFromSig3(long handleId)
{
    Sig3Callbacks.erase(handleId);
}

void EnumInterfacePublisherPimpl::publishSig3(const Enum3Enum& param3) const
{
    for(const auto& Subscriber: IEnumInterfaceInterfaceSubscribers)
    {
        Subscriber->OnSig3(param3);
    }
    for(const auto& callbackEntry: Sig3Callbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(param3);
        }
    }
}

/**
 * Implementation EnumInterfacePublisher
 */
EnumInterfacePublisher::EnumInterfacePublisher()
    : m_impl(std::make_shared<EnumInterfacePublisherPimpl>())
{
}
EnumInterfacePublisher::~EnumInterfacePublisher() = default;

void EnumInterfacePublisher::subscribeToEnumInterfaceInterface(IEnumInterfaceSubscriber& subscriber)
{
    m_impl->subscribeToEnumInterfaceInterface(subscriber);
}

void EnumInterfacePublisher::unsubscribeFromEnumInterfaceInterface(IEnumInterfaceSubscriber& subscriber)
{
    m_impl->unsubscribeFromEnumInterfaceInterface(subscriber);
}

long EnumInterfacePublisher::subscribeToProp0Changed(EnumInterfaceProp0PropertyCb callback)
{
    return m_impl->subscribeToProp0Changed(callback);
}

void EnumInterfacePublisher::unsubscribeFromProp0Changed(long handleId)
{
    m_impl->unsubscribeFromProp0Changed(handleId);
}

void EnumInterfacePublisher::publishProp0Changed(const Enum0Enum& prop0) const
{
    m_impl->publishProp0Changed(prop0);
}

long EnumInterfacePublisher::subscribeToProp1Changed(EnumInterfaceProp1PropertyCb callback)
{
    return m_impl->subscribeToProp1Changed(callback);
}

void EnumInterfacePublisher::unsubscribeFromProp1Changed(long handleId)
{
    m_impl->unsubscribeFromProp1Changed(handleId);
}

void EnumInterfacePublisher::publishProp1Changed(const Enum1Enum& prop1) const
{
    m_impl->publishProp1Changed(prop1);
}

long EnumInterfacePublisher::subscribeToProp2Changed(EnumInterfaceProp2PropertyCb callback)
{
    return m_impl->subscribeToProp2Changed(callback);
}

void EnumInterfacePublisher::unsubscribeFromProp2Changed(long handleId)
{
    m_impl->unsubscribeFromProp2Changed(handleId);
}

void EnumInterfacePublisher::publishProp2Changed(const Enum2Enum& prop2) const
{
    m_impl->publishProp2Changed(prop2);
}

long EnumInterfacePublisher::subscribeToProp3Changed(EnumInterfaceProp3PropertyCb callback)
{
    return m_impl->subscribeToProp3Changed(callback);
}

void EnumInterfacePublisher::unsubscribeFromProp3Changed(long handleId)
{
    m_impl->unsubscribeFromProp3Changed(handleId);
}

void EnumInterfacePublisher::publishProp3Changed(const Enum3Enum& prop3) const
{
    m_impl->publishProp3Changed(prop3);
}

long EnumInterfacePublisher::subscribeToSig0(EnumInterfaceSig0SignalCb callback)
{
    return m_impl->subscribeToSig0(callback);
}

void EnumInterfacePublisher::unsubscribeFromSig0(long handleId)
{
    m_impl->unsubscribeFromSig0(handleId);
}

void EnumInterfacePublisher::publishSig0(const Enum0Enum& param0) const
{
    m_impl->publishSig0(param0);
}

long EnumInterfacePublisher::subscribeToSig1(EnumInterfaceSig1SignalCb callback)
{
    return m_impl->subscribeToSig1(callback);
}

void EnumInterfacePublisher::unsubscribeFromSig1(long handleId)
{
    m_impl->unsubscribeFromSig1(handleId);
}

void EnumInterfacePublisher::publishSig1(const Enum1Enum& param1) const
{
    m_impl->publishSig1(param1);
}

long EnumInterfacePublisher::subscribeToSig2(EnumInterfaceSig2SignalCb callback)
{
    return m_impl->subscribeToSig2(callback);
}

void EnumInterfacePublisher::unsubscribeFromSig2(long handleId)
{
    m_impl->unsubscribeFromSig2(handleId);
}

void EnumInterfacePublisher::publishSig2(const Enum2Enum& param2) const
{
    m_impl->publishSig2(param2);
}

long EnumInterfacePublisher::subscribeToSig3(EnumInterfaceSig3SignalCb callback)
{
    return m_impl->subscribeToSig3(callback);
}

void EnumInterfacePublisher::unsubscribeFromSig3(long handleId)
{
    m_impl->unsubscribeFromSig3(handleId);
}

void EnumInterfacePublisher::publishSig3(const Enum3Enum& param3) const
{
    m_impl->publishSig3(param3);
}
