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
#include "testbed1_datastructs.api.h"

namespace Test {
namespace Testbed1 {
// ********************************************************************
// Struct StructBool
// ********************************************************************
StructBool::StructBool() = default;
StructBool::StructBool(
    bool fieldBool):
    fieldBool(fieldBool)
{
}

bool operator==(const StructBool& lhs, const StructBool& rhs) noexcept
{
    return (
        lhs.fieldBool == rhs.fieldBool

    );
}

bool operator!=(const StructBool& lhs, const StructBool& rhs) noexcept
{
    return !(lhs == rhs);
}
// ********************************************************************
// Struct StructInt
// ********************************************************************
StructInt::StructInt() = default;
StructInt::StructInt(
    int fieldInt):
    fieldInt(fieldInt)
{
}

bool operator==(const StructInt& lhs, const StructInt& rhs) noexcept
{
    return (
        lhs.fieldInt == rhs.fieldInt

    );
}

bool operator!=(const StructInt& lhs, const StructInt& rhs) noexcept
{
    return !(lhs == rhs);
}
// ********************************************************************
// Struct StructFloat
// ********************************************************************
StructFloat::StructFloat() = default;
StructFloat::StructFloat(
    float fieldFloat):
    fieldFloat(fieldFloat)
{
}

bool operator==(const StructFloat& lhs, const StructFloat& rhs) noexcept
{
    return (
        lhs.fieldFloat == rhs.fieldFloat

    );
}

bool operator!=(const StructFloat& lhs, const StructFloat& rhs) noexcept
{
    return !(lhs == rhs);
}
// ********************************************************************
// Struct StructString
// ********************************************************************
StructString::StructString() = default;
StructString::StructString(
    const std::string& fieldString):
    fieldString(fieldString)
{
}

bool operator==(const StructString& lhs, const StructString& rhs) noexcept
{
    return (
        lhs.fieldString == rhs.fieldString

    );
}

bool operator!=(const StructString& lhs, const StructString& rhs) noexcept
{
    return !(lhs == rhs);
}
} // namespace Testbed1
} // namespace Test
