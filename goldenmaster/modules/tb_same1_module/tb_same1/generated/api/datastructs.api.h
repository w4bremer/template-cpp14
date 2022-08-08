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

#include <cinttypes>
#include <string>
#include <list>

#include "tb_same1/generated/api/common.h"

namespace Test {
namespace TbSame1 {
struct Struct1;
struct Struct2;

/**
 * Enumeration Enum1
 */
enum class Enum1Enum {
    value1 = 1,
    value2 = 2
};
TEST_TB_SAME1_EXPORT Enum1Enum toEnum1Enum(std::uint8_t v, bool *ok);

/**
 * Enumeration Enum2
 */
enum class Enum2Enum {
    value1 = 1,
    value2 = 2
};
TEST_TB_SAME1_EXPORT Enum2Enum toEnum2Enum(std::uint8_t v, bool *ok);

/**
 * Struct Struct1
 */
struct TEST_TB_SAME1_EXPORT Struct1
{
    Struct1();
    Struct1(int field1,int field2,int field3);

    int field1{};
    int field2{};
    int field3{};

};
bool TEST_TB_SAME1_EXPORT operator==(const Struct1 &, const Struct1 &) noexcept;
bool TEST_TB_SAME1_EXPORT operator!=(const Struct1 &, const Struct1 &) noexcept;

/**
 * Struct Struct2
 */
struct TEST_TB_SAME1_EXPORT Struct2
{
    Struct2();
    Struct2(int field1,int field2,int field3);

    int field1{};
    int field2{};
    int field3{};

};
bool TEST_TB_SAME1_EXPORT operator==(const Struct2 &, const Struct2 &) noexcept;
bool TEST_TB_SAME1_EXPORT operator!=(const Struct2 &, const Struct2 &) noexcept;
} // namespace TbSame1
} // namespace Test
