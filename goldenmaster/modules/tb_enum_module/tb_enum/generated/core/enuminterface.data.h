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
    Enum0Enum m_prop0 {Enum0Enum::value0};
    Enum1Enum m_prop1 {Enum1Enum::value1};
    Enum2Enum m_prop2 {Enum2Enum::value2};
    Enum3Enum m_prop3 {Enum3Enum::value3};
};

}
}