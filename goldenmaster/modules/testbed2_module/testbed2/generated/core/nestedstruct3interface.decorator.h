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
#include "testbed2/generated/api/testbed2.h"
#include "testbed2/generated/api/common.h"
#include "testbed2/generated/core/nestedstruct3interface.publisher.h"

namespace Test {
namespace Testbed2 {

class TEST_TESTBED2_EXPORT AbstractNestedStruct3InterfaceDecorator : public INestedStruct3InterfaceDecorator
{
public:
    explicit AbstractNestedStruct3InterfaceDecorator(INestedStruct3Interface* impl);
    INestedStruct3Interface* swapUnderlyingImplementation(INestedStruct3Interface* impl) override;
    INestedStruct3Interface* disconnectFromUnderlyingImplementation() override;
    virtual ~AbstractNestedStruct3InterfaceDecorator();
public:
    // property prop1
    void setProp1(const NestedStruct1& prop1) override;
    const NestedStruct1& prop1() const override;
    
    // property prop2
    void setProp2(const NestedStruct2& prop2) override;
    const NestedStruct2& prop2() const override;
    
    // property prop3
    void setProp3(const NestedStruct3& prop3) override;
    const NestedStruct3& prop3() const override;
    
    // operations
    NestedStruct1 func1(const NestedStruct1& param1) override;
    std::future<NestedStruct1> func1Async(const NestedStruct1& param1) override;
    NestedStruct1 func2(const NestedStruct1& param1, const NestedStruct2& param2) override;
    std::future<NestedStruct1> func2Async(const NestedStruct1& param1, const NestedStruct2& param2) override;
    NestedStruct1 func3(const NestedStruct1& param1, const NestedStruct2& param2, const NestedStruct3& param3) override;
    std::future<NestedStruct1> func3Async(const NestedStruct1& param1, const NestedStruct2& param2, const NestedStruct3& param3) override;

    INestedStruct3InterfacePublisher* _getPublisher() const override;
private:
    INestedStruct3Interface* m_impl {nullptr};
};
} // namespace Testbed2
} // namespace Test
