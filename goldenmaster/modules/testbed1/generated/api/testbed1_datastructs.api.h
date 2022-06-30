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

#include "testbed1_common.h"

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
