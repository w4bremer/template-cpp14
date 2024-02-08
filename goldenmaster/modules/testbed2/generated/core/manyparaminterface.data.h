#pragma once

#include "testbed2/generated/api/testbed2.h"


namespace Test
{
namespace Testbed2
{

/**
* A helper structure for implementations of ManyParamInterface. Stores all the properties.
*/
struct ManyParamInterfaceData
{
    int m_prop1 {0};
    int m_prop2 {0};
    int m_prop3 {0};
    int m_prop4 {0};
};

}
}