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
#include "tb_enum/generated/api/tb_enum.h"
#include "tb_enum/generated/api/common.h"

namespace Test {
namespace TbEnum {

class TEST_TB_ENUM_EXPORT EnumInterface : public IEnumInterface
{
public:
    explicit EnumInterface();
    ~EnumInterface();
public:
    // property prop0
    void setProp0(const Enum0Enum& prop0) override;
    const Enum0Enum& prop0() const override;
    
    // property prop1
    void setProp1(const Enum1Enum& prop1) override;
    const Enum1Enum& prop1() const override;
    
    // property prop2
    void setProp2(const Enum2Enum& prop2) override;
    const Enum2Enum& prop2() const override;
    
    // property prop3
    void setProp3(const Enum3Enum& prop3) override;
    const Enum3Enum& prop3() const override;
    
    // operations
    Enum0Enum func0(const Enum0Enum& param0) override;
    std::future<Enum0Enum> func0Async(const Enum0Enum& param0) override;
    Enum1Enum func1(const Enum1Enum& param1) override;
    std::future<Enum1Enum> func1Async(const Enum1Enum& param1) override;
    Enum2Enum func2(const Enum2Enum& param2) override;
    std::future<Enum2Enum> func2Async(const Enum2Enum& param2) override;
    Enum3Enum func3(const Enum3Enum& param3) override;
    std::future<Enum3Enum> func3Async(const Enum3Enum& param3) override;

    IEnumInterfacePublisher* _getPublisher() const override;
private:
    struct EnumInterfaceData;
    std::unique_ptr<EnumInterfaceData> d_ptr;
};
} // namespace TbEnum
} // namespace Test
