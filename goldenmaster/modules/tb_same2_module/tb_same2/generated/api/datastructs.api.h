#pragma once

#include <cinttypes>
#include <string>
#include <list>

#include "tb_same2/generated/api/common.h"

namespace Test {
namespace TbSame2 {
struct Struct1;
struct Struct2;

/**
 * Enumeration Enum1
 */
enum class Enum1Enum {
    value1 = 1,
    value2 = 2
};
TEST_TB_SAME2_EXPORT Enum1Enum toEnum1Enum(std::uint8_t v, bool *ok);

/**
 * Enumeration Enum2
 */
enum class Enum2Enum {
    value1 = 1,
    value2 = 2
};
TEST_TB_SAME2_EXPORT Enum2Enum toEnum2Enum(std::uint8_t v, bool *ok);

/**
 * Struct Struct1
 */
struct TEST_TB_SAME2_EXPORT Struct1
{
    Struct1();
    Struct1(int field1,int field2,int field3);

    int field1{};
    int field2{};
    int field3{};

};
bool TEST_TB_SAME2_EXPORT operator==(const Struct1 &, const Struct1 &) noexcept;
bool TEST_TB_SAME2_EXPORT operator!=(const Struct1 &, const Struct1 &) noexcept;

/**
 * Struct Struct2
 */
struct TEST_TB_SAME2_EXPORT Struct2
{
    Struct2();
    Struct2(int field1,int field2,int field3);

    int field1{};
    int field2{};
    int field3{};

};
bool TEST_TB_SAME2_EXPORT operator==(const Struct2 &, const Struct2 &) noexcept;
bool TEST_TB_SAME2_EXPORT operator!=(const Struct2 &, const Struct2 &) noexcept;
} // namespace TbSame2
} // namespace Test
