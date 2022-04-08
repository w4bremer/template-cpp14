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
#include "org_objectapi_testbed_interface2.publisher.h"


namespace Test {
namespace OrgObjectapiTestbed {
class Interface2PublisherPimpl : public IInterface2Publisher
{
public:
    void subscribeToInterface2Interface(IInterface2Subscriber& subscriber) override;
    void unsubscribeFromInterface2Interface(IInterface2Subscriber& subscriber) override;

    long subscribeToProp200Changed(Interface2Prop200PropertyCb callback) override;
    void unsubscribeFromProp200Changed(long handleId) override;

    long subscribeToProp201Changed(Interface2Prop201PropertyCb callback) override;
    void unsubscribeFromProp201Changed(long handleId) override;

    long subscribeToProp202Changed(Interface2Prop202PropertyCb callback) override;
    void unsubscribeFromProp202Changed(long handleId) override;

    long subscribeToProp203Changed(Interface2Prop203PropertyCb callback) override;
    void unsubscribeFromProp203Changed(long handleId) override;

    long subscribeToProp204Changed(Interface2Prop204PropertyCb callback) override;
    void unsubscribeFromProp204Changed(long handleId) override;

    long subscribeToProp205Changed(Interface2Prop205PropertyCb callback) override;
    void unsubscribeFromProp205Changed(long handleId) override;

    void publishProp200Changed(int prop200) const override;
    void publishProp201Changed(int prop201) const override;
    void publishProp202Changed(int prop202) const override;
    void publishProp203Changed(float prop203) const override;
    void publishProp204Changed(float prop204) const override;
    void publishProp205Changed(const std::string& prop205) const override;
private:
    std::set<IInterface2Subscriber*> IInterface2InterfaceSubscribers;
    std::map<long, Interface2Prop200PropertyCb> Prop200Callbacks;
    std::map<long, Interface2Prop201PropertyCb> Prop201Callbacks;
    std::map<long, Interface2Prop202PropertyCb> Prop202Callbacks;
    std::map<long, Interface2Prop203PropertyCb> Prop203Callbacks;
    std::map<long, Interface2Prop204PropertyCb> Prop204Callbacks;
    std::map<long, Interface2Prop205PropertyCb> Prop205Callbacks;
};

} // namespace OrgObjectapiTestbed
} // namespace Test

using namespace Test::OrgObjectapiTestbed;

/**
 * Implementation Interface2PublisherPimpl
 */
void Interface2PublisherPimpl::subscribeToInterface2Interface(IInterface2Subscriber& subscriber)
{
    IInterface2InterfaceSubscribers.insert(&subscriber);
}

void Interface2PublisherPimpl::unsubscribeFromInterface2Interface(IInterface2Subscriber& subscriber)
{
    IInterface2InterfaceSubscribers.erase(&subscriber);
}

long Interface2PublisherPimpl::subscribeToProp200Changed(Interface2Prop200PropertyCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    long handleId = static_cast<long>(Prop200Callbacks.size());
    Prop200Callbacks[handleId] = callback;
    return handleId;
}

void Interface2PublisherPimpl::unsubscribeFromProp200Changed(long handleId)
{
    Prop200Callbacks.erase(handleId);
}

void Interface2PublisherPimpl::publishProp200Changed(int prop200) const
{
    for(const auto& Subscriber: IInterface2InterfaceSubscribers)
    {
        Subscriber->OnProp200Changed(prop200);
    }
    for(const auto& callbackEntry: Prop200Callbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(prop200);
        }
    }
}

long Interface2PublisherPimpl::subscribeToProp201Changed(Interface2Prop201PropertyCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    long handleId = static_cast<long>(Prop201Callbacks.size());
    Prop201Callbacks[handleId] = callback;
    return handleId;
}

void Interface2PublisherPimpl::unsubscribeFromProp201Changed(long handleId)
{
    Prop201Callbacks.erase(handleId);
}

void Interface2PublisherPimpl::publishProp201Changed(int prop201) const
{
    for(const auto& Subscriber: IInterface2InterfaceSubscribers)
    {
        Subscriber->OnProp201Changed(prop201);
    }
    for(const auto& callbackEntry: Prop201Callbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(prop201);
        }
    }
}

long Interface2PublisherPimpl::subscribeToProp202Changed(Interface2Prop202PropertyCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    long handleId = static_cast<long>(Prop202Callbacks.size());
    Prop202Callbacks[handleId] = callback;
    return handleId;
}

void Interface2PublisherPimpl::unsubscribeFromProp202Changed(long handleId)
{
    Prop202Callbacks.erase(handleId);
}

void Interface2PublisherPimpl::publishProp202Changed(int prop202) const
{
    for(const auto& Subscriber: IInterface2InterfaceSubscribers)
    {
        Subscriber->OnProp202Changed(prop202);
    }
    for(const auto& callbackEntry: Prop202Callbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(prop202);
        }
    }
}

long Interface2PublisherPimpl::subscribeToProp203Changed(Interface2Prop203PropertyCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    long handleId = static_cast<long>(Prop203Callbacks.size());
    Prop203Callbacks[handleId] = callback;
    return handleId;
}

void Interface2PublisherPimpl::unsubscribeFromProp203Changed(long handleId)
{
    Prop203Callbacks.erase(handleId);
}

void Interface2PublisherPimpl::publishProp203Changed(float prop203) const
{
    for(const auto& Subscriber: IInterface2InterfaceSubscribers)
    {
        Subscriber->OnProp203Changed(prop203);
    }
    for(const auto& callbackEntry: Prop203Callbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(prop203);
        }
    }
}

long Interface2PublisherPimpl::subscribeToProp204Changed(Interface2Prop204PropertyCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    long handleId = static_cast<long>(Prop204Callbacks.size());
    Prop204Callbacks[handleId] = callback;
    return handleId;
}

void Interface2PublisherPimpl::unsubscribeFromProp204Changed(long handleId)
{
    Prop204Callbacks.erase(handleId);
}

void Interface2PublisherPimpl::publishProp204Changed(float prop204) const
{
    for(const auto& Subscriber: IInterface2InterfaceSubscribers)
    {
        Subscriber->OnProp204Changed(prop204);
    }
    for(const auto& callbackEntry: Prop204Callbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(prop204);
        }
    }
}

long Interface2PublisherPimpl::subscribeToProp205Changed(Interface2Prop205PropertyCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    long handleId = static_cast<long>(Prop205Callbacks.size());
    Prop205Callbacks[handleId] = callback;
    return handleId;
}

void Interface2PublisherPimpl::unsubscribeFromProp205Changed(long handleId)
{
    Prop205Callbacks.erase(handleId);
}

void Interface2PublisherPimpl::publishProp205Changed(const std::string& prop205) const
{
    for(const auto& Subscriber: IInterface2InterfaceSubscribers)
    {
        Subscriber->OnProp205Changed(prop205);
    }
    for(const auto& callbackEntry: Prop205Callbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(prop205);
        }
    }
}

/**
 * Implementation Interface2Publisher
 */
Interface2Publisher::Interface2Publisher()
    : m_impl(std::make_shared<Interface2PublisherPimpl>())
{
}
Interface2Publisher::~Interface2Publisher() = default;

void Interface2Publisher::subscribeToInterface2Interface(IInterface2Subscriber& subscriber)
{
    m_impl->subscribeToInterface2Interface(subscriber);
}

void Interface2Publisher::unsubscribeFromInterface2Interface(IInterface2Subscriber& subscriber)
{
    m_impl->unsubscribeFromInterface2Interface(subscriber);
}

long Interface2Publisher::subscribeToProp200Changed(Interface2Prop200PropertyCb callback)
{
    return m_impl->subscribeToProp200Changed(callback);
}

void Interface2Publisher::unsubscribeFromProp200Changed(long handleId)
{
    m_impl->unsubscribeFromProp200Changed(handleId);
}

void Interface2Publisher::publishProp200Changed(int prop200) const
{
    m_impl->publishProp200Changed(prop200);
}

long Interface2Publisher::subscribeToProp201Changed(Interface2Prop201PropertyCb callback)
{
    return m_impl->subscribeToProp201Changed(callback);
}

void Interface2Publisher::unsubscribeFromProp201Changed(long handleId)
{
    m_impl->unsubscribeFromProp201Changed(handleId);
}

void Interface2Publisher::publishProp201Changed(int prop201) const
{
    m_impl->publishProp201Changed(prop201);
}

long Interface2Publisher::subscribeToProp202Changed(Interface2Prop202PropertyCb callback)
{
    return m_impl->subscribeToProp202Changed(callback);
}

void Interface2Publisher::unsubscribeFromProp202Changed(long handleId)
{
    m_impl->unsubscribeFromProp202Changed(handleId);
}

void Interface2Publisher::publishProp202Changed(int prop202) const
{
    m_impl->publishProp202Changed(prop202);
}

long Interface2Publisher::subscribeToProp203Changed(Interface2Prop203PropertyCb callback)
{
    return m_impl->subscribeToProp203Changed(callback);
}

void Interface2Publisher::unsubscribeFromProp203Changed(long handleId)
{
    m_impl->unsubscribeFromProp203Changed(handleId);
}

void Interface2Publisher::publishProp203Changed(float prop203) const
{
    m_impl->publishProp203Changed(prop203);
}

long Interface2Publisher::subscribeToProp204Changed(Interface2Prop204PropertyCb callback)
{
    return m_impl->subscribeToProp204Changed(callback);
}

void Interface2Publisher::unsubscribeFromProp204Changed(long handleId)
{
    m_impl->unsubscribeFromProp204Changed(handleId);
}

void Interface2Publisher::publishProp204Changed(float prop204) const
{
    m_impl->publishProp204Changed(prop204);
}

long Interface2Publisher::subscribeToProp205Changed(Interface2Prop205PropertyCb callback)
{
    return m_impl->subscribeToProp205Changed(callback);
}

void Interface2Publisher::unsubscribeFromProp205Changed(long handleId)
{
    m_impl->unsubscribeFromProp205Changed(handleId);
}

void Interface2Publisher::publishProp205Changed(const std::string& prop205) const
{
    m_impl->publishProp205Changed(prop205);
}
