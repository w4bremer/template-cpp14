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
#include "generated/api/org_objectapi_testbed.h"
#include "generated/api/org_objectapi_testbed_common.h"
#include "generated/core/org_objectapi_testbed_interface1.publisher.h"

namespace Test {
namespace OrgObjectapiTestbed {

class TEST_ORG_OBJECTAPI_TESTBED_EXPORT AbstractInterface1Decorator : public IInterface1Decorator
{
public:
    explicit AbstractInterface1Decorator(IInterface1* impl);
    IInterface1* swapUnderlyingImplementation(IInterface1* impl) override;
    IInterface1* disconnectFromUnderlyingImplementation() override;
    virtual ~AbstractInterface1Decorator();
public:
    // property prop1
    void setProp1(bool prop1) override;
    bool prop1() const override;
    
    // property prop2
    void setProp2(int prop2) override;
    int prop2() const override;
    
    // property prop3
    void setProp3(float prop3) override;
    float prop3() const override;
    
    // property prop4
    void setProp4(const std::string& prop4) override;
    std::string prop4() const override;
    
    // property prop5
    void setProp5(const std::list<int>& prop5) override;
    const std::list<int>& prop5() const override;
    
    // property prop6
    void setProp6(const Struct1& prop6) override;
    const Struct1& prop6() const override;
    
    // property prop7
    void setProp7(int prop7) override;
    int prop7() const override;
    
    // property prop10
    void setProp10(const std::list<int>& prop10) override;
    const std::list<int>& prop10() const override;
    
    // property prop11
    void setProp11(const std::list<Struct1>& prop11) override;
    const std::list<Struct1>& prop11() const override;
    
    // property prop12
    void setProp12(const std::list<Enum1Enum>& prop12) override;
    const std::list<Enum1Enum>& prop12() const override;
    
    // property prop14
    void setProp14(const std::list<Struct1>& prop14) override;
    const std::list<Struct1>& prop14() const override;
    
    // operations
    void op1() override;
    std::future<void> op1Async() override;
    void op2(int step) override;
    std::future<void> op2Async(int step) override;
    int op3() override;
    std::future<int> op3Async() override;

    IInterface1Publisher* _getPublisher() const override;
private:
    IInterface1* m_impl {nullptr};
};
} // namespace OrgObjectapiTestbed
} // namespace Test
