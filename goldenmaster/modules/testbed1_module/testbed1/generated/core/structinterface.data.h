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

#include "testbed1/generated/api/testbed1.h"


namespace Test
{
namespace Testbed1
{

/**
* A helper structure for implementations of StructInterface. Stores all the properties.
*/
struct StructInterfaceData
{
    StructBool m_propBool;
    StructInt m_propInt;
    StructFloat m_propFloat;
    StructString m_propString;
};

}
}