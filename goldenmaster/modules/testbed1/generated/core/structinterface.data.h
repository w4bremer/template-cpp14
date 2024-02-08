#pragma once

#include "testbed1/generated/api/testbed1.h"


namespace Test
{
namespace Testbed1
{

/**
* A helper structure for implementations of StructInterface. Stores all the properties.
*/
struct StructInterfaceData
{
    StructBool m_propBool {StructBool()};
    StructInt m_propInt {StructInt()};
    StructFloat m_propFloat {StructFloat()};
    StructString m_propString {StructString()};
};

}
}