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
    int32_t m_propInt32 {0};
    int64_t m_propInt64 {0LL};
    float m_propFloat {0.0f};
    float m_propFloat32 {0.0f};
    double m_propFloat64 {0.0};
    std::string m_propString {std::string()};
};

}
}