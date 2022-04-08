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
#include "generated/api/org_objectapi_testbed_interface1.api.h"
#include "generated/api/org_objectapi_testbed_common.h"

namespace Test {
namespace OrgObjectapiTestbed {
/**
 * Implementation Interface1Publisher
 */
class TEST_ORG_OBJECTAPI_TESTBED_EXPORT Interface1Publisher: public IInterface1Publisher
{
public:
    explicit Interface1Publisher();
    virtual ~Interface1Publisher();

    // Interface1Publisher is not copyable
    Interface1Publisher(const Interface1Publisher& a) = delete;
    Interface1Publisher& operator=(const Interface1Publisher& a) = delete;
    // Interface1Publisher is not movable
    Interface1Publisher(Interface1Publisher&& a) = delete;
    Interface1Publisher& operator=(Interface1Publisher&& a) = delete;

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

    void publishSig1() const override;
    void publishSig2(int step) const override;
    void publishSig3() const override;
protected:
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
private:
    std::shared_ptr<IInterface1Publisher> m_impl;
};

} // namespace OrgObjectapiTestbed
} // namespace Test
