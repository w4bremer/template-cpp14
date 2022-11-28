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
    bool m_propBool {false};
    int m_propInt {0};
    float m_propFloat {0.0};
    std::string m_propString {std::string()};
};

}
}