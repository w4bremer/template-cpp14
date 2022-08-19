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
    StructBool m_propBool;
    StructInt m_propInt;
    StructFloat m_propFloat;
    StructString m_propString;
};

}
}