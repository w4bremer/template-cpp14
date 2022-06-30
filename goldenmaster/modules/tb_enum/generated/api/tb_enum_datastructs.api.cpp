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
#include "tb_enum_datastructs.api.h"

namespace Test {
namespace TbEnum {

// ********************************************************************
// Enumeration Enum0
// ********************************************************************
Enum0Enum toEnum0Enum(std::uint8_t v, bool *ok)
{
    if (ok != nullptr) {
        *ok = true;
    }
    switch (v) {
        case 0: return Enum0Enum::value0;
        case 1: return Enum0Enum::value1;
        case 2: return Enum0Enum::value2;
        default:
            if (ok != nullptr) {
                *ok = false;
            }
            return Enum0Enum::value0;
    }
}

// ********************************************************************
// Enumeration Enum1
// ********************************************************************
Enum1Enum toEnum1Enum(std::uint8_t v, bool *ok)
{
    if (ok != nullptr) {
        *ok = true;
    }
    switch (v) {
        case 1: return Enum1Enum::value1;
        case 2: return Enum1Enum::value2;
        case 3: return Enum1Enum::value3;
        default:
            if (ok != nullptr) {
                *ok = false;
            }
            return Enum1Enum::value1;
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
        case 2: return Enum2Enum::value2;
        case 1: return Enum2Enum::value1;
        case 0: return Enum2Enum::value0;
        default:
            if (ok != nullptr) {
                *ok = false;
            }
            return Enum2Enum::value2;
    }
}

// ********************************************************************
// Enumeration Enum3
// ********************************************************************
Enum3Enum toEnum3Enum(std::uint8_t v, bool *ok)
{
    if (ok != nullptr) {
        *ok = true;
    }
    switch (v) {
        case 3: return Enum3Enum::value3;
        case 2: return Enum3Enum::value2;
        case 1: return Enum3Enum::value1;
        default:
            if (ok != nullptr) {
                *ok = false;
            }
            return Enum3Enum::value3;
    }
}
} // namespace TbEnum
} // namespace Test
