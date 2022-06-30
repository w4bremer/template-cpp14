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
#include "generated/api/tb_same1.h"
#include "generated/api/tb_same1_common.h"

namespace Test {
namespace TbSame1 {

class TEST_TB_SAME1_EXPORT SameEnum2Interface : public ISameEnum2Interface
{
public:
    explicit SameEnum2Interface();
    ~SameEnum2Interface();
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
    struct SameEnum2InterfaceData;
    std::unique_ptr<SameEnum2InterfaceData> d_ptr;
};
} // namespace TbSame1
} // namespace Test
