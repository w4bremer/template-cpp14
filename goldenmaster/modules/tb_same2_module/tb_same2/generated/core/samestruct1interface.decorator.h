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
#include "tb_same2/generated/api/tb_same2.h"
#include "tb_same2/generated/api/common.h"

namespace Test {
namespace TbSame2 {

class TEST_TB_SAME2_EXPORT AbstractSameStruct1InterfaceDecorator : public ISameStruct1Interface, public ISameStruct1InterfaceSubscriber {
public:
    explicit AbstractSameStruct1InterfaceDecorator(ISameStruct1Interface* impl);
    ISameStruct1Interface* swapUnderlyingImplementation(ISameStruct1Interface* impl);
    ISameStruct1Interface* disconnectFromUnderlyingImplementation();
    virtual ~AbstractSameStruct1InterfaceDecorator();
public:
    // property prop1
    void setProp1(const Struct1& prop1) override;
    const Struct1& prop1() const override;
    
    // operations
    Struct1 func1(const Struct1& param1) override;
    std::future<Struct1> func1Async(const Struct1& param1) override;

    ISameStruct1InterfacePublisher& _getPublisher() const override;
private:
    ISameStruct1Interface* m_impl {nullptr};
};
} // namespace TbSame2
} // namespace Test
