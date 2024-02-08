#pragma once

#include <cinttypes>
#include <string>
#include <list>

#include "tb_enum/generated/api/common.h"

namespace Test {
namespace TbEnum {

/**
 * Enumeration Enum0
 */
enum class Enum0Enum {
    value0 = 0,
    value1 = 1,
    value2 = 2
};
TEST_TB_ENUM_EXPORT Enum0Enum toEnum0Enum(std::uint8_t v, bool *ok);

/**
 * Enumeration Enum1
 */
enum class Enum1Enum {
    value1 = 1,
    value2 = 2,
    value3 = 3
};
TEST_TB_ENUM_EXPORT Enum1Enum toEnum1Enum(std::uint8_t v, bool *ok);

/**
 * Enumeration Enum2
 */
enum class Enum2Enum {
    value2 = 2,
    value1 = 1,
    value0 = 0
};
TEST_TB_ENUM_EXPORT Enum2Enum toEnum2Enum(std::uint8_t v, bool *ok);

/**
 * Enumeration Enum3
 */
enum class Enum3Enum {
    value3 = 3,
    value2 = 2,
    value1 = 1
};
TEST_TB_ENUM_EXPORT Enum3Enum toEnum3Enum(std::uint8_t v, bool *ok);
} // namespace TbEnum
} // namespace Test
