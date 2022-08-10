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

#include "tb_enum/generated/api/tb_enum.h"


namespace Test
{
namespace TbEnum
{

/**
* A helper structure for implementations of EnumInterface. Stores all the properties.
*/
struct EnumInterfaceData
{
    Enum0Enum m_prop0;
    Enum1Enum m_prop1;
    Enum2Enum m_prop2;
    Enum3Enum m_prop3;
};

}
}