#pragma once

#include "tb_simple/generated/api/tb_simple.h"


namespace Test
{
namespace TbSimple
{

/**
* A helper structure for implementations of NoSignalsInterface. Stores all the properties.
*/
struct NoSignalsInterfaceData
{
    bool m_propBool {false};
    int m_propInt {0};
};

}
}