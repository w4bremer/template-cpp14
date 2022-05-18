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

#include <future>
#include "generated/api/org_objectapi_testbed.h"
#include "generated/api/org_objectapi_testbed_common.h"
#include "generated/core/org_objectapi_testbed_interface1.publisher.h"
#include "olink/clientnode.h"
#include "apigear/olink/olinkclient.h"

namespace Test {
namespace OrgObjectapiTestbed {
class TEST_ORG_OBJECTAPI_TESTBED_EXPORT OLinkInterface1 : public IInterface1, public ApiGear::ObjectLink::IObjectSink
{
public:
    explicit OLinkInterface1(ApiGear::ObjectLink::ClientRegistry& registry, ApiGear::PocoImpl::OLinkClient& client);
    virtual ~OLinkInterface1() override;

    void applyState(const nlohmann::json& fields);
    bool prop1() const override;
    void setProp1(bool prop1) override;
    void setProp1Local(bool prop1);
    int prop2() const override;
    void setProp2(int prop2) override;
    void setProp2Local(int prop2);
    float prop3() const override;
    void setProp3(float prop3) override;
    void setProp3Local(float prop3);
    std::string prop4() const override;
    void setProp4(const std::string& prop4) override;
    void setProp4Local(const std::string& prop4);
    const std::list<int>& prop5() const override;
    void setProp5(const std::list<int>& prop5) override;
    void setProp5Local(const std::list<int>& prop5);
    const Struct1& prop6() const override;
    void setProp6(const Struct1& prop6) override;
    void setProp6Local(const Struct1& prop6);
    int prop7() const override;
    void setProp7(int prop7) override;
    void setProp7Local(int prop7);
    const std::list<int>& prop10() const override;
    void setProp10(const std::list<int>& prop10) override;
    void setProp10Local(const std::list<int>& prop10);
    const std::list<Struct1>& prop11() const override;
    void setProp11(const std::list<Struct1>& prop11) override;
    void setProp11Local(const std::list<Struct1>& prop11);
    const std::list<Enum1Enum>& prop12() const override;
    void setProp12(const std::list<Enum1Enum>& prop12) override;
    void setProp12Local(const std::list<Enum1Enum>& prop12);
    const std::list<Struct1>& prop14() const override;
    void setProp14(const std::list<Struct1>& prop14) override;
    void setProp14Local(const std::list<Struct1>& prop14);
    void op1() override;
    std::future<void> op1Async() override;
    void op2(int step) override;
    std::future<void> op2Async(int step) override;
    int op3() override;
    std::future<int> op3Async() override;
    bool isReady() const;
    IInterface1Publisher* _getPublisher() const override;
public:
    std::string olinkObjectName() override;
    void olinkOnSignal(std::string name, nlohmann::json args) override;
    void olinkOnPropertyChanged(std::string name, nlohmann::json value) override;
    void olinkOnInit(std::string name, nlohmann::json props, ApiGear::ObjectLink::IClientNode *node) override;
    void olinkOnRelease() override;
private:
    bool m_isReady;
    bool m_prop1;
    int m_prop2;
    float m_prop3;
    std::string m_prop4;
    std::list<int> m_prop5;
    Struct1 m_prop6;
    int m_prop7;
    std::list<int> m_prop10;
    std::list<Struct1> m_prop11;
    std::list<Enum1Enum> m_prop12;
    std::list<Struct1> m_prop14;
    ApiGear::ObjectLink::IClientNode *m_node;
    ApiGear::ObjectLink::ClientRegistry* m_registry;
    IInterface1Publisher* m_publisher;
};
} // namespace OrgObjectapiTestbed
} // namespace Test
