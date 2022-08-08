
#include "testbed2/implementation/manyparaminterface.h"
#include "testbed2/implementation/nestedstruct1interface.h"
#include "testbed2/implementation/nestedstruct2interface.h"
#include "testbed2/implementation/nestedstruct3interface.h"

using namespace Test::Testbed2;

int main(){
    std::unique_ptr<IManyParamInterface> testManyParamInterface = std::make_unique<ManyParamInterface>();
    std::unique_ptr<INestedStruct1Interface> testNestedStruct1Interface = std::make_unique<NestedStruct1Interface>();
    std::unique_ptr<INestedStruct2Interface> testNestedStruct2Interface = std::make_unique<NestedStruct2Interface>();
    std::unique_ptr<INestedStruct3Interface> testNestedStruct3Interface = std::make_unique<NestedStruct3Interface>();

    return 0;
}
