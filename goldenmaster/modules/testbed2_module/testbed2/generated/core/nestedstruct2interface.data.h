#pragma once

#include "testbed2/generated/api/testbed2.h"


namespace Test
{
namespace Testbed2
{

/**
* A helper structure for implementations of NestedStruct2Interface. Stores all the properties.
*/
struct NestedStruct2InterfaceData
{
    NestedStruct1 m_prop1;
    NestedStruct2 m_prop2;
};

}
}