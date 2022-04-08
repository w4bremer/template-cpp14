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

#include "org_objectapi_testbed_common.h"

namespace Test {
namespace OrgObjectapiTestbed {
struct Struct1;

/**
 * Enumeration Enum1
 */
enum class Enum1Enum {
    Member1 = 0,
    Member2 = 1,
    Member3 = 2,
    Member4 = 3
};
TEST_ORG_OBJECTAPI_TESTBED_EXPORT Enum1Enum toEnum1Enum(std::uint8_t v, bool *ok);

/**
 * Enumeration Enum2
 */
enum class Enum2Enum {
    Member1 = 0,
    Member2 = 1,
    Member3 = 2,
    Member4 = 3
};
TEST_ORG_OBJECTAPI_TESTBED_EXPORT Enum2Enum toEnum2Enum(std::uint8_t v, bool *ok);

/**
 * Struct Struct1
 */
struct TEST_ORG_OBJECTAPI_TESTBED_EXPORT Struct1
{
    Struct1();
    Struct1(bool field1,int field2,float field3,const std::string& field4);

    bool field1{};
    int field2{};
    float field3{};
    std::string field4{};

};
bool TEST_ORG_OBJECTAPI_TESTBED_EXPORT operator==(const Struct1 &, const Struct1 &) noexcept;
bool TEST_ORG_OBJECTAPI_TESTBED_EXPORT operator!=(const Struct1 &, const Struct1 &) noexcept;
} // namespace OrgObjectapiTestbed
} // namespace Test
