#pragma once

#include "tb_simple/generated/api/tb_simple.h"


namespace Test
{
namespace TbSimple
{

/**
* A helper structure for implementations of SimpleArrayInterface. Stores all the properties.
*/
struct SimpleArrayInterfaceData
{
    std::list<bool> m_propBool {std::list<bool>()};
    std::list<int> m_propInt {std::list<int>()};
    std::list<float> m_propFloat {std::list<float>()};
    std::list<std::string> m_propString {std::list<std::string>()};
};

}
}