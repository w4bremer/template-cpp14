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

namespace Test {
namespace Testbed2 {

class TEST_TESTBED2_EXPORT AbstractNestedStruct1InterfaceDecorator : public INestedStruct1Interface, public INestedStruct1InterfaceSubscriber {
public:
    explicit AbstractNestedStruct1InterfaceDecorator(INestedStruct1Interface* impl);
    INestedStruct1Interface* swapUnderlyingImplementation(INestedStruct1Interface* impl);
    INestedStruct1Interface* disconnectFromUnderlyingImplementation();
    virtual ~AbstractNestedStruct1InterfaceDecorator();
public:
    // property prop1
    void setProp1(const NestedStruct1& prop1) override;
    const NestedStruct1& prop1() const override;
    
    // operations
    NestedStruct1 func1(const NestedStruct1& param1) override;
    std::future<NestedStruct1> func1Async(const NestedStruct1& param1) override;

    INestedStruct1InterfacePublisher& _getPublisher() const override;
private:
    INestedStruct1Interface* m_impl {nullptr};
};
} // namespace Testbed2
} // namespace Test
