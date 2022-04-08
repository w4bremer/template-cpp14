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
#include "org_objectapi_testbed_interface1.publisher.h"


namespace Test {
namespace OrgObjectapiTestbed {
class Interface1PublisherPimpl : public IInterface1Publisher
{
public:
    void subscribeToInterface1Interface(IInterface1Subscriber& subscriber) override;
    void unsubscribeFromInterface1Interface(IInterface1Subscriber& subscriber) override;

    long subscribeToProp1Changed(Interface1Prop1PropertyCb callback) override;
    void unsubscribeFromProp1Changed(long handleId) override;

    long subscribeToProp2Changed(Interface1Prop2PropertyCb callback) override;
    void unsubscribeFromProp2Changed(long handleId) override;

    long subscribeToProp3Changed(Interface1Prop3PropertyCb callback) override;
    void unsubscribeFromProp3Changed(long handleId) override;

    long subscribeToProp4Changed(Interface1Prop4PropertyCb callback) override;
    void unsubscribeFromProp4Changed(long handleId) override;

    long subscribeToProp5Changed(Interface1Prop5PropertyCb callback) override;
    void unsubscribeFromProp5Changed(long handleId) override;

    long subscribeToProp6Changed(Interface1Prop6PropertyCb callback) override;
    void unsubscribeFromProp6Changed(long handleId) override;

    long subscribeToProp7Changed(Interface1Prop7PropertyCb callback) override;
    void unsubscribeFromProp7Changed(long handleId) override;

    long subscribeToProp10Changed(Interface1Prop10PropertyCb callback) override;
    void unsubscribeFromProp10Changed(long handleId) override;

    long subscribeToProp11Changed(Interface1Prop11PropertyCb callback) override;
    void unsubscribeFromProp11Changed(long handleId) override;

    long subscribeToProp12Changed(Interface1Prop12PropertyCb callback) override;
    void unsubscribeFromProp12Changed(long handleId) override;

    long subscribeToProp14Changed(Interface1Prop14PropertyCb callback) override;
    void unsubscribeFromProp14Changed(long handleId) override;

    long subscribeToSig1(Interface1Sig1SignalCb callback) override;
    void unsubscribeFromSig1(long handleId) override;

    long subscribeToSig2(Interface1Sig2SignalCb callback) override;
    void unsubscribeFromSig2(long handleId) override;

    long subscribeToSig3(Interface1Sig3SignalCb callback) override;
    void unsubscribeFromSig3(long handleId) override;

    void publishProp1Changed(bool prop1) const override;
    void publishProp2Changed(int prop2) const override;
    void publishProp3Changed(float prop3) const override;
    void publishProp4Changed(const std::string& prop4) const override;
    void publishProp5Changed(const std::list<int>& prop5) const override;
    void publishProp6Changed(const Struct1& prop6) const override;
    void publishProp7Changed(int prop7) const override;
    void publishProp10Changed(const std::list<int>& prop10) const override;
    void publishProp11Changed(const std::list<Struct1>& prop11) const override;
    void publishProp12Changed(const std::list<Enum1Enum>& prop12) const override;
    void publishProp14Changed(const std::list<Struct1>& prop14) const override;
    void publishSig1() const override;
    void publishSig2(int step) const override;
    void publishSig3() const override;
private:
    std::set<IInterface1Subscriber*> IInterface1InterfaceSubscribers;
    std::map<long, Interface1Prop1PropertyCb> Prop1Callbacks;
    std::map<long, Interface1Prop2PropertyCb> Prop2Callbacks;
    std::map<long, Interface1Prop3PropertyCb> Prop3Callbacks;
    std::map<long, Interface1Prop4PropertyCb> Prop4Callbacks;
    std::map<long, Interface1Prop5PropertyCb> Prop5Callbacks;
    std::map<long, Interface1Prop6PropertyCb> Prop6Callbacks;
    std::map<long, Interface1Prop7PropertyCb> Prop7Callbacks;
    std::map<long, Interface1Prop10PropertyCb> Prop10Callbacks;
    std::map<long, Interface1Prop11PropertyCb> Prop11Callbacks;
    std::map<long, Interface1Prop12PropertyCb> Prop12Callbacks;
    std::map<long, Interface1Prop14PropertyCb> Prop14Callbacks;
    std::map<long, Interface1Sig1SignalCb> Sig1Callbacks;
    std::map<long, Interface1Sig2SignalCb> Sig2Callbacks;
    std::map<long, Interface1Sig3SignalCb> Sig3Callbacks;
};

} // namespace OrgObjectapiTestbed
} // namespace Test

using namespace Test::OrgObjectapiTestbed;

/**
 * Implementation Interface1PublisherPimpl
 */
void Interface1PublisherPimpl::subscribeToInterface1Interface(IInterface1Subscriber& subscriber)
{
    IInterface1InterfaceSubscribers.insert(&subscriber);
}

void Interface1PublisherPimpl::unsubscribeFromInterface1Interface(IInterface1Subscriber& subscriber)
{
    IInterface1InterfaceSubscribers.erase(&subscriber);
}

long Interface1PublisherPimpl::subscribeToProp1Changed(Interface1Prop1PropertyCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    long handleId = static_cast<long>(Prop1Callbacks.size());
    Prop1Callbacks[handleId] = callback;
    return handleId;
}

void Interface1PublisherPimpl::unsubscribeFromProp1Changed(long handleId)
{
    Prop1Callbacks.erase(handleId);
}

void Interface1PublisherPimpl::publishProp1Changed(bool prop1) const
{
    for(const auto& Subscriber: IInterface1InterfaceSubscribers)
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

long Interface1PublisherPimpl::subscribeToProp2Changed(Interface1Prop2PropertyCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    long handleId = static_cast<long>(Prop2Callbacks.size());
    Prop2Callbacks[handleId] = callback;
    return handleId;
}

void Interface1PublisherPimpl::unsubscribeFromProp2Changed(long handleId)
{
    Prop2Callbacks.erase(handleId);
}

void Interface1PublisherPimpl::publishProp2Changed(int prop2) const
{
    for(const auto& Subscriber: IInterface1InterfaceSubscribers)
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

long Interface1PublisherPimpl::subscribeToProp3Changed(Interface1Prop3PropertyCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    long handleId = static_cast<long>(Prop3Callbacks.size());
    Prop3Callbacks[handleId] = callback;
    return handleId;
}

void Interface1PublisherPimpl::unsubscribeFromProp3Changed(long handleId)
{
    Prop3Callbacks.erase(handleId);
}

void Interface1PublisherPimpl::publishProp3Changed(float prop3) const
{
    for(const auto& Subscriber: IInterface1InterfaceSubscribers)
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

long Interface1PublisherPimpl::subscribeToProp4Changed(Interface1Prop4PropertyCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    long handleId = static_cast<long>(Prop4Callbacks.size());
    Prop4Callbacks[handleId] = callback;
    return handleId;
}

void Interface1PublisherPimpl::unsubscribeFromProp4Changed(long handleId)
{
    Prop4Callbacks.erase(handleId);
}

void Interface1PublisherPimpl::publishProp4Changed(const std::string& prop4) const
{
    for(const auto& Subscriber: IInterface1InterfaceSubscribers)
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

long Interface1PublisherPimpl::subscribeToProp5Changed(Interface1Prop5PropertyCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    long handleId = static_cast<long>(Prop5Callbacks.size());
    Prop5Callbacks[handleId] = callback;
    return handleId;
}

void Interface1PublisherPimpl::unsubscribeFromProp5Changed(long handleId)
{
    Prop5Callbacks.erase(handleId);
}

void Interface1PublisherPimpl::publishProp5Changed(const std::list<int>& prop5) const
{
    for(const auto& Subscriber: IInterface1InterfaceSubscribers)
    {
        Subscriber->OnProp5Changed(prop5);
    }
    for(const auto& callbackEntry: Prop5Callbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(prop5);
        }
    }
}

long Interface1PublisherPimpl::subscribeToProp6Changed(Interface1Prop6PropertyCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    long handleId = static_cast<long>(Prop6Callbacks.size());
    Prop6Callbacks[handleId] = callback;
    return handleId;
}

void Interface1PublisherPimpl::unsubscribeFromProp6Changed(long handleId)
{
    Prop6Callbacks.erase(handleId);
}

void Interface1PublisherPimpl::publishProp6Changed(const Struct1& prop6) const
{
    for(const auto& Subscriber: IInterface1InterfaceSubscribers)
    {
        Subscriber->OnProp6Changed(prop6);
    }
    for(const auto& callbackEntry: Prop6Callbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(prop6);
        }
    }
}

long Interface1PublisherPimpl::subscribeToProp7Changed(Interface1Prop7PropertyCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    long handleId = static_cast<long>(Prop7Callbacks.size());
    Prop7Callbacks[handleId] = callback;
    return handleId;
}

void Interface1PublisherPimpl::unsubscribeFromProp7Changed(long handleId)
{
    Prop7Callbacks.erase(handleId);
}

void Interface1PublisherPimpl::publishProp7Changed(int prop7) const
{
    for(const auto& Subscriber: IInterface1InterfaceSubscribers)
    {
        Subscriber->OnProp7Changed(prop7);
    }
    for(const auto& callbackEntry: Prop7Callbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(prop7);
        }
    }
}

long Interface1PublisherPimpl::subscribeToProp10Changed(Interface1Prop10PropertyCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    long handleId = static_cast<long>(Prop10Callbacks.size());
    Prop10Callbacks[handleId] = callback;
    return handleId;
}

void Interface1PublisherPimpl::unsubscribeFromProp10Changed(long handleId)
{
    Prop10Callbacks.erase(handleId);
}

void Interface1PublisherPimpl::publishProp10Changed(const std::list<int>& prop10) const
{
    for(const auto& Subscriber: IInterface1InterfaceSubscribers)
    {
        Subscriber->OnProp10Changed(prop10);
    }
    for(const auto& callbackEntry: Prop10Callbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(prop10);
        }
    }
}

long Interface1PublisherPimpl::subscribeToProp11Changed(Interface1Prop11PropertyCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    long handleId = static_cast<long>(Prop11Callbacks.size());
    Prop11Callbacks[handleId] = callback;
    return handleId;
}

void Interface1PublisherPimpl::unsubscribeFromProp11Changed(long handleId)
{
    Prop11Callbacks.erase(handleId);
}

void Interface1PublisherPimpl::publishProp11Changed(const std::list<Struct1>& prop11) const
{
    for(const auto& Subscriber: IInterface1InterfaceSubscribers)
    {
        Subscriber->OnProp11Changed(prop11);
    }
    for(const auto& callbackEntry: Prop11Callbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(prop11);
        }
    }
}

long Interface1PublisherPimpl::subscribeToProp12Changed(Interface1Prop12PropertyCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    long handleId = static_cast<long>(Prop12Callbacks.size());
    Prop12Callbacks[handleId] = callback;
    return handleId;
}

void Interface1PublisherPimpl::unsubscribeFromProp12Changed(long handleId)
{
    Prop12Callbacks.erase(handleId);
}

void Interface1PublisherPimpl::publishProp12Changed(const std::list<Enum1Enum>& prop12) const
{
    for(const auto& Subscriber: IInterface1InterfaceSubscribers)
    {
        Subscriber->OnProp12Changed(prop12);
    }
    for(const auto& callbackEntry: Prop12Callbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(prop12);
        }
    }
}

long Interface1PublisherPimpl::subscribeToProp14Changed(Interface1Prop14PropertyCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    long handleId = static_cast<long>(Prop14Callbacks.size());
    Prop14Callbacks[handleId] = callback;
    return handleId;
}

void Interface1PublisherPimpl::unsubscribeFromProp14Changed(long handleId)
{
    Prop14Callbacks.erase(handleId);
}

void Interface1PublisherPimpl::publishProp14Changed(const std::list<Struct1>& prop14) const
{
    for(const auto& Subscriber: IInterface1InterfaceSubscribers)
    {
        Subscriber->OnProp14Changed(prop14);
    }
    for(const auto& callbackEntry: Prop14Callbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(prop14);
        }
    }
}

long Interface1PublisherPimpl::subscribeToSig1(Interface1Sig1SignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    long handleId = static_cast<long>(Sig1Callbacks.size());
    Sig1Callbacks[handleId] = callback;
    return handleId;
}

void Interface1PublisherPimpl::unsubscribeFromSig1(long handleId)
{
    Sig1Callbacks.erase(handleId);
}

void Interface1PublisherPimpl::publishSig1() const
{
    for(const auto& Subscriber: IInterface1InterfaceSubscribers)
    {
        Subscriber->OnSig1();
    }
    for(const auto& callbackEntry: Sig1Callbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second();
        }
    }
}

long Interface1PublisherPimpl::subscribeToSig2(Interface1Sig2SignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    long handleId = static_cast<long>(Sig2Callbacks.size());
    Sig2Callbacks[handleId] = callback;
    return handleId;
}

void Interface1PublisherPimpl::unsubscribeFromSig2(long handleId)
{
    Sig2Callbacks.erase(handleId);
}

void Interface1PublisherPimpl::publishSig2(int step) const
{
    for(const auto& Subscriber: IInterface1InterfaceSubscribers)
    {
        Subscriber->OnSig2(step);
    }
    for(const auto& callbackEntry: Sig2Callbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(step);
        }
    }
}

long Interface1PublisherPimpl::subscribeToSig3(Interface1Sig3SignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    long handleId = static_cast<long>(Sig3Callbacks.size());
    Sig3Callbacks[handleId] = callback;
    return handleId;
}

void Interface1PublisherPimpl::unsubscribeFromSig3(long handleId)
{
    Sig3Callbacks.erase(handleId);
}

void Interface1PublisherPimpl::publishSig3() const
{
    for(const auto& Subscriber: IInterface1InterfaceSubscribers)
    {
        Subscriber->OnSig3();
    }
    for(const auto& callbackEntry: Sig3Callbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second();
        }
    }
}

/**
 * Implementation Interface1Publisher
 */
Interface1Publisher::Interface1Publisher()
    : m_impl(std::make_shared<Interface1PublisherPimpl>())
{
}
Interface1Publisher::~Interface1Publisher() = default;

void Interface1Publisher::subscribeToInterface1Interface(IInterface1Subscriber& subscriber)
{
    m_impl->subscribeToInterface1Interface(subscriber);
}

void Interface1Publisher::unsubscribeFromInterface1Interface(IInterface1Subscriber& subscriber)
{
    m_impl->unsubscribeFromInterface1Interface(subscriber);
}

long Interface1Publisher::subscribeToProp1Changed(Interface1Prop1PropertyCb callback)
{
    return m_impl->subscribeToProp1Changed(callback);
}

void Interface1Publisher::unsubscribeFromProp1Changed(long handleId)
{
    m_impl->unsubscribeFromProp1Changed(handleId);
}

void Interface1Publisher::publishProp1Changed(bool prop1) const
{
    m_impl->publishProp1Changed(prop1);
}

long Interface1Publisher::subscribeToProp2Changed(Interface1Prop2PropertyCb callback)
{
    return m_impl->subscribeToProp2Changed(callback);
}

void Interface1Publisher::unsubscribeFromProp2Changed(long handleId)
{
    m_impl->unsubscribeFromProp2Changed(handleId);
}

void Interface1Publisher::publishProp2Changed(int prop2) const
{
    m_impl->publishProp2Changed(prop2);
}

long Interface1Publisher::subscribeToProp3Changed(Interface1Prop3PropertyCb callback)
{
    return m_impl->subscribeToProp3Changed(callback);
}

void Interface1Publisher::unsubscribeFromProp3Changed(long handleId)
{
    m_impl->unsubscribeFromProp3Changed(handleId);
}

void Interface1Publisher::publishProp3Changed(float prop3) const
{
    m_impl->publishProp3Changed(prop3);
}

long Interface1Publisher::subscribeToProp4Changed(Interface1Prop4PropertyCb callback)
{
    return m_impl->subscribeToProp4Changed(callback);
}

void Interface1Publisher::unsubscribeFromProp4Changed(long handleId)
{
    m_impl->unsubscribeFromProp4Changed(handleId);
}

void Interface1Publisher::publishProp4Changed(const std::string& prop4) const
{
    m_impl->publishProp4Changed(prop4);
}

long Interface1Publisher::subscribeToProp5Changed(Interface1Prop5PropertyCb callback)
{
    return m_impl->subscribeToProp5Changed(callback);
}

void Interface1Publisher::unsubscribeFromProp5Changed(long handleId)
{
    m_impl->unsubscribeFromProp5Changed(handleId);
}

void Interface1Publisher::publishProp5Changed(const std::list<int>& prop5) const
{
    m_impl->publishProp5Changed(prop5);
}

long Interface1Publisher::subscribeToProp6Changed(Interface1Prop6PropertyCb callback)
{
    return m_impl->subscribeToProp6Changed(callback);
}

void Interface1Publisher::unsubscribeFromProp6Changed(long handleId)
{
    m_impl->unsubscribeFromProp6Changed(handleId);
}

void Interface1Publisher::publishProp6Changed(const Struct1& prop6) const
{
    m_impl->publishProp6Changed(prop6);
}

long Interface1Publisher::subscribeToProp7Changed(Interface1Prop7PropertyCb callback)
{
    return m_impl->subscribeToProp7Changed(callback);
}

void Interface1Publisher::unsubscribeFromProp7Changed(long handleId)
{
    m_impl->unsubscribeFromProp7Changed(handleId);
}

void Interface1Publisher::publishProp7Changed(int prop7) const
{
    m_impl->publishProp7Changed(prop7);
}

long Interface1Publisher::subscribeToProp10Changed(Interface1Prop10PropertyCb callback)
{
    return m_impl->subscribeToProp10Changed(callback);
}

void Interface1Publisher::unsubscribeFromProp10Changed(long handleId)
{
    m_impl->unsubscribeFromProp10Changed(handleId);
}

void Interface1Publisher::publishProp10Changed(const std::list<int>& prop10) const
{
    m_impl->publishProp10Changed(prop10);
}

long Interface1Publisher::subscribeToProp11Changed(Interface1Prop11PropertyCb callback)
{
    return m_impl->subscribeToProp11Changed(callback);
}

void Interface1Publisher::unsubscribeFromProp11Changed(long handleId)
{
    m_impl->unsubscribeFromProp11Changed(handleId);
}

void Interface1Publisher::publishProp11Changed(const std::list<Struct1>& prop11) const
{
    m_impl->publishProp11Changed(prop11);
}

long Interface1Publisher::subscribeToProp12Changed(Interface1Prop12PropertyCb callback)
{
    return m_impl->subscribeToProp12Changed(callback);
}

void Interface1Publisher::unsubscribeFromProp12Changed(long handleId)
{
    m_impl->unsubscribeFromProp12Changed(handleId);
}

void Interface1Publisher::publishProp12Changed(const std::list<Enum1Enum>& prop12) const
{
    m_impl->publishProp12Changed(prop12);
}

long Interface1Publisher::subscribeToProp14Changed(Interface1Prop14PropertyCb callback)
{
    return m_impl->subscribeToProp14Changed(callback);
}

void Interface1Publisher::unsubscribeFromProp14Changed(long handleId)
{
    m_impl->unsubscribeFromProp14Changed(handleId);
}

void Interface1Publisher::publishProp14Changed(const std::list<Struct1>& prop14) const
{
    m_impl->publishProp14Changed(prop14);
}

long Interface1Publisher::subscribeToSig1(Interface1Sig1SignalCb callback)
{
    return m_impl->subscribeToSig1(callback);
}

void Interface1Publisher::unsubscribeFromSig1(long handleId)
{
    m_impl->unsubscribeFromSig1(handleId);
}

void Interface1Publisher::publishSig1() const
{
    m_impl->publishSig1();
}

long Interface1Publisher::subscribeToSig2(Interface1Sig2SignalCb callback)
{
    return m_impl->subscribeToSig2(callback);
}

void Interface1Publisher::unsubscribeFromSig2(long handleId)
{
    m_impl->unsubscribeFromSig2(handleId);
}

void Interface1Publisher::publishSig2(int step) const
{
    m_impl->publishSig2(step);
}

long Interface1Publisher::subscribeToSig3(Interface1Sig3SignalCb callback)
{
    return m_impl->subscribeToSig3(callback);
}

void Interface1Publisher::unsubscribeFromSig3(long handleId)
{
    m_impl->unsubscribeFromSig3(handleId);
}

void Interface1Publisher::publishSig3() const
{
    m_impl->publishSig3();
}
