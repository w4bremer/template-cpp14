#pragma once

#include "tb_simple/generated/api/tb_simple.h"


namespace Test
{
namespace TbSimple
{

/**
* A helper structure for implementations of SimpleInterface. Stores all the properties.
*/
struct SimpleInterfaceData
{
    bool m_propBool;
    int m_propInt;
    float m_propFloat;
    std::string m_propString;
};

}
}