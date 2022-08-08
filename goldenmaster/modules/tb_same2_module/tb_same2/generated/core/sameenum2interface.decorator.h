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
#include "tb_same2/generated/core/sameenum2interface.publisher.h"

namespace Test {
namespace TbSame2 {

class TEST_TB_SAME2_EXPORT AbstractSameEnum2InterfaceDecorator : public ISameEnum2InterfaceDecorator
{
public:
    explicit AbstractSameEnum2InterfaceDecorator(ISameEnum2Interface* impl);
    ISameEnum2Interface* swapUnderlyingImplementation(ISameEnum2Interface* impl) override;
    ISameEnum2Interface* disconnectFromUnderlyingImplementation() override;
    virtual ~AbstractSameEnum2InterfaceDecorator();
public:
    // property prop1
    void setProp1(const Enum1Enum& prop1) override;
    const Enum1Enum& prop1() const override;
    
    // property prop2
    void setProp2(const Enum2Enum& prop2) override;
    const Enum2Enum& prop2() const override;
    
    // operations
    Enum1Enum func1(const Enum1Enum& param1) override;
    std::future<Enum1Enum> func1Async(const Enum1Enum& param1) override;
    Enum1Enum func2(const Enum1Enum& param1, const Enum2Enum& param2) override;
    std::future<Enum1Enum> func2Async(const Enum1Enum& param1, const Enum2Enum& param2) override;

    ISameEnum2InterfacePublisher* _getPublisher() const override;
private:
    ISameEnum2Interface* m_impl {nullptr};
};
} // namespace TbSame2
} // namespace Test
