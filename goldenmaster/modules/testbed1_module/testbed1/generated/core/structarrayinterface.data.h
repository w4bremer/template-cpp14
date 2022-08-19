#pragma once

#include "testbed1/generated/api/testbed1.h"


namespace Test
{
namespace Testbed1
{

/**
* A helper structure for implementations of StructArrayInterface. Stores all the properties.
*/
struct StructArrayInterfaceData
{
    std::list<StructBool> m_propBool;
    std::list<StructInt> m_propInt;
    std::list<StructFloat> m_propFloat;
    std::list<StructString> m_propString;
};

}
}