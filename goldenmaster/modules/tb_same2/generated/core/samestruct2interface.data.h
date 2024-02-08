#pragma once

#include "tb_same2/generated/api/tb_same2.h"


namespace Test
{
namespace TbSame2
{

/**
* A helper structure for implementations of SameStruct2Interface. Stores all the properties.
*/
struct SameStruct2InterfaceData
{
    Struct2 m_prop1 {Struct2()};
    Struct2 m_prop2 {Struct2()};
};

}
}