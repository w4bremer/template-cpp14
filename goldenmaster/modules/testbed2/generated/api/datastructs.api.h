#pragma once

#include <cinttypes>
#include <string>
#include <list>

#include "testbed2/generated/api/common.h"

namespace Test {
namespace Testbed2 {
struct Struct1;
struct Struct2;
struct Struct3;
struct Struct4;
struct NestedStruct1;
struct NestedStruct2;
struct NestedStruct3;

/**
 * Enumeration Enum1
 */
enum class Enum1Enum {
    value1 = 1,
    value2 = 2,
    value3 = 3,
    value4 = 4
};
TEST_TESTBED2_EXPORT Enum1Enum toEnum1Enum(std::uint8_t v, bool *ok);

/**
 * Enumeration Enum2
 */
enum class Enum2Enum {
    value1 = 1,
    value2 = 2,
    value3 = 3,
    value4 = 4
};
TEST_TESTBED2_EXPORT Enum2Enum toEnum2Enum(std::uint8_t v, bool *ok);

/**
 * Enumeration Enum3
 */
enum class Enum3Enum {
    value1 = 1,
    value2 = 2,
    value3 = 3,
    value4 = 4
};
TEST_TESTBED2_EXPORT Enum3Enum toEnum3Enum(std::uint8_t v, bool *ok);

/**
 * Struct Struct1
 */
struct TEST_TESTBED2_EXPORT Struct1
{
    Struct1();
    Struct1(int field1);

    int field1{};

};
bool TEST_TESTBED2_EXPORT operator==(const Struct1 &, const Struct1 &) noexcept;
bool TEST_TESTBED2_EXPORT operator!=(const Struct1 &, const Struct1 &) noexcept;

/**
 * Struct Struct2
 */
struct TEST_TESTBED2_EXPORT Struct2
{
    Struct2();
    Struct2(int field1, int field2);

    int field1{};
    int field2{};

};
bool TEST_TESTBED2_EXPORT operator==(const Struct2 &, const Struct2 &) noexcept;
bool TEST_TESTBED2_EXPORT operator!=(const Struct2 &, const Struct2 &) noexcept;

/**
 * Struct Struct3
 */
struct TEST_TESTBED2_EXPORT Struct3
{
    Struct3();
    Struct3(int field1, int field2, int field3);

    int field1{};
    int field2{};
    int field3{};

};
bool TEST_TESTBED2_EXPORT operator==(const Struct3 &, const Struct3 &) noexcept;
bool TEST_TESTBED2_EXPORT operator!=(const Struct3 &, const Struct3 &) noexcept;

/**
 * Struct Struct4
 */
struct TEST_TESTBED2_EXPORT Struct4
{
    Struct4();
    Struct4(int field1, int field2, int field3, int field4);

    int field1{};
    int field2{};
    int field3{};
    int field4{};

};
bool TEST_TESTBED2_EXPORT operator==(const Struct4 &, const Struct4 &) noexcept;
bool TEST_TESTBED2_EXPORT operator!=(const Struct4 &, const Struct4 &) noexcept;

/**
 * Struct NestedStruct1
 */
struct TEST_TESTBED2_EXPORT NestedStruct1
{
    NestedStruct1();
    NestedStruct1(const Struct1& field1);

    Struct1 field1{};

};
bool TEST_TESTBED2_EXPORT operator==(const NestedStruct1 &, const NestedStruct1 &) noexcept;
bool TEST_TESTBED2_EXPORT operator!=(const NestedStruct1 &, const NestedStruct1 &) noexcept;

/**
 * Struct NestedStruct2
 */
struct TEST_TESTBED2_EXPORT NestedStruct2
{
    NestedStruct2();
    NestedStruct2(const Struct1& field1, const Struct2& field2);

    Struct1 field1{};
    Struct2 field2{};

};
bool TEST_TESTBED2_EXPORT operator==(const NestedStruct2 &, const NestedStruct2 &) noexcept;
bool TEST_TESTBED2_EXPORT operator!=(const NestedStruct2 &, const NestedStruct2 &) noexcept;

/**
 * Struct NestedStruct3
 */
struct TEST_TESTBED2_EXPORT NestedStruct3
{
    NestedStruct3();
    NestedStruct3(const Struct1& field1, const Struct2& field2, const Struct3& field3);

    Struct1 field1{};
    Struct2 field2{};
    Struct3 field3{};

};
bool TEST_TESTBED2_EXPORT operator==(const NestedStruct3 &, const NestedStruct3 &) noexcept;
bool TEST_TESTBED2_EXPORT operator!=(const NestedStruct3 &, const NestedStruct3 &) noexcept;
} // namespace Testbed2
} // namespace Test
