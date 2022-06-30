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

class TEST_TB_SAME1_EXPORT SameEnum1Interface : public ISameEnum1Interface
{
public:
    explicit SameEnum1Interface();
    ~SameEnum1Interface();
public:
    // property prop1
    void setProp1(const Enum1Enum& prop1) override;
    const Enum1Enum& prop1() const override;
    
    // operations
    Enum1Enum func1(const Enum1Enum& param1) override;
    std::future<Enum1Enum> func1Async(const Enum1Enum& param1) override;

    ISameEnum1InterfacePublisher* _getPublisher() const override;
private:
    struct SameEnum1InterfaceData;
    std::unique_ptr<SameEnum1InterfaceData> d_ptr;
};
} // namespace TbSame1
} // namespace Test
