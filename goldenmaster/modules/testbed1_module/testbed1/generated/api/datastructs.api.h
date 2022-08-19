#pragma once

#include <cinttypes>
#include <string>
#include <list>

#include "testbed1/generated/api/common.h"

namespace Test {
namespace Testbed1 {
struct StructBool;
struct StructInt;
struct StructFloat;
struct StructString;

/**
 * Struct StructBool
 */
struct TEST_TESTBED1_EXPORT StructBool
{
    StructBool();
    StructBool(bool fieldBool);

    bool fieldBool{};

};
bool TEST_TESTBED1_EXPORT operator==(const StructBool &, const StructBool &) noexcept;
bool TEST_TESTBED1_EXPORT operator!=(const StructBool &, const StructBool &) noexcept;

/**
 * Struct StructInt
 */
struct TEST_TESTBED1_EXPORT StructInt
{
    StructInt();
    StructInt(int fieldInt);

    int fieldInt{};

};
bool TEST_TESTBED1_EXPORT operator==(const StructInt &, const StructInt &) noexcept;
bool TEST_TESTBED1_EXPORT operator!=(const StructInt &, const StructInt &) noexcept;

/**
 * Struct StructFloat
 */
struct TEST_TESTBED1_EXPORT StructFloat
{
    StructFloat();
    StructFloat(float fieldFloat);

    float fieldFloat{};

};
bool TEST_TESTBED1_EXPORT operator==(const StructFloat &, const StructFloat &) noexcept;
bool TEST_TESTBED1_EXPORT operator!=(const StructFloat &, const StructFloat &) noexcept;

/**
 * Struct StructString
 */
struct TEST_TESTBED1_EXPORT StructString
{
    StructString();
    StructString(const std::string& fieldString);

    std::string fieldString{};

};
bool TEST_TESTBED1_EXPORT operator==(const StructString &, const StructString &) noexcept;
bool TEST_TESTBED1_EXPORT operator!=(const StructString &, const StructString &) noexcept;
} // namespace Testbed1
} // namespace Test
