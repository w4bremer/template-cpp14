
#include "tb_enum/implementation/enuminterface.h"

using namespace Test::TbEnum;

int main(){
    std::unique_ptr<IEnumInterface> testEnumInterface = std::make_unique<EnumInterface>();

    return 0;
}
