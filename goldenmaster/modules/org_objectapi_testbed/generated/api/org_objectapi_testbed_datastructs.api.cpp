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
#include "org_objectapi_testbed_datastructs.api.h"

namespace Test {
namespace OrgObjectapiTestbed {

// ********************************************************************
// Enumeration Enum1
// ********************************************************************
Enum1Enum toEnum1Enum(std::uint8_t v, bool *ok)
{
    if (ok != nullptr) {
        *ok = true;
    }
    switch (v) {
        case 0: return Enum1Enum::Member1;
        case 1: return Enum1Enum::Member2;
        case 2: return Enum1Enum::Member3;
        case 3: return Enum1Enum::Member4;
        default:
            if (ok != nullptr) {
                *ok = false;
            }
            return Enum1Enum::Member1;
    }
}

// ********************************************************************
// Enumeration Enum2
// ********************************************************************
Enum2Enum toEnum2Enum(std::uint8_t v, bool *ok)
{
    if (ok != nullptr) {
        *ok = true;
    }
    switch (v) {
        case 0: return Enum2Enum::Member1;
        case 1: return Enum2Enum::Member2;
        case 2: return Enum2Enum::Member3;
        case 3: return Enum2Enum::Member4;
        default:
            if (ok != nullptr) {
                *ok = false;
            }
            return Enum2Enum::Member1;
    }
}
// ********************************************************************
// Struct Struct1
// ********************************************************************
Struct1::Struct1() = default;
Struct1::Struct1(
    bool field1,
    int field2,
    float field3,
    const std::string& field4):
    field1(field1),
    field2(field2),
    field3(field3),
    field4(field4)
{
}

bool operator==(const Struct1& lhs, const Struct1& rhs) noexcept
{
    return (
        lhs.field1 == rhs.field1 &&
        lhs.field2 == rhs.field2 &&
        lhs.field3 == rhs.field3 &&
        lhs.field4 == rhs.field4

    );
}

bool operator!=(const Struct1& lhs, const Struct1& rhs) noexcept
{
    return !(lhs == rhs);
}
} // namespace OrgObjectapiTestbed
} // namespace Test
