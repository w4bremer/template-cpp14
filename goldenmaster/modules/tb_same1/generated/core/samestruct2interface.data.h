#pragma once

#include "tb_same1/generated/api/tb_same1.h"


namespace Test
{
namespace TbSame1
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