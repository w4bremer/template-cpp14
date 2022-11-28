#pragma once

#include "tb_same2/generated/api/tb_same2.h"


namespace Test
{
namespace TbSame2
{

/**
* A helper structure for implementations of SameEnum2Interface. Stores all the properties.
*/
struct SameEnum2InterfaceData
{
    Enum1Enum m_prop1 {Enum1Enum::value1};
    Enum2Enum m_prop2 {Enum2Enum::value1};
};

}
}