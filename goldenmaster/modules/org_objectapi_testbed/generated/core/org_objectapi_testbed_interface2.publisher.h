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
#pragma once

#include <memory>
#include "generated/api/org_objectapi_testbed_datastructs.api.h"
#include "generated/api/org_objectapi_testbed_interface2.api.h"
#include "generated/api/org_objectapi_testbed_common.h"

namespace Test {
namespace OrgObjectapiTestbed {
/**
 * Implementation Interface2Publisher
 */
class TEST_ORG_OBJECTAPI_TESTBED_EXPORT Interface2Publisher: public IInterface2Publisher
{
public:
    explicit Interface2Publisher();
    virtual ~Interface2Publisher();

    // Interface2Publisher is not copyable
    Interface2Publisher(const Interface2Publisher& a) = delete;
    Interface2Publisher& operator=(const Interface2Publisher& a) = delete;
    // Interface2Publisher is not movable
    Interface2Publisher(Interface2Publisher&& a) = delete;
    Interface2Publisher& operator=(Interface2Publisher&& a) = delete;

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

protected:
    void publishProp200Changed(int prop200) const override;
    void publishProp201Changed(int prop201) const override;
    void publishProp202Changed(int prop202) const override;
    void publishProp203Changed(float prop203) const override;
    void publishProp204Changed(float prop204) const override;
    void publishProp205Changed(const std::string& prop205) const override;
private:
    std::shared_ptr<IInterface2Publisher> m_impl;
};

} // namespace OrgObjectapiTestbed
} // namespace Test
