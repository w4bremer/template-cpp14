#pragma once

#include "tb_simple/generated/api/tb_simple.h"


namespace Test
{
namespace TbSimple
{

/**
* A helper structure for implementations of NoOperationsInterface. Stores all the properties.
*/
struct NoOperationsInterfaceData
{
    bool m_propBool {false};
    int m_propInt {0};
};

}
}