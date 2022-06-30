
#include "tb_same2_samestruct1interface.h"
#include "tb_same2_samestruct2interface.h"
#include "tb_same2_sameenum1interface.h"
#include "tb_same2_sameenum2interface.h"

using namespace Test::TbSame2;

int main(){
    std::unique_ptr<ISameStruct1Interface> testSameStruct1Interface = std::make_unique<SameStruct1Interface>();
    std::unique_ptr<ISameStruct2Interface> testSameStruct2Interface = std::make_unique<SameStruct2Interface>();
    std::unique_ptr<ISameEnum1Interface> testSameEnum1Interface = std::make_unique<SameEnum1Interface>();
    std::unique_ptr<ISameEnum2Interface> testSameEnum2Interface = std::make_unique<SameEnum2Interface>();

    return 0;
}
