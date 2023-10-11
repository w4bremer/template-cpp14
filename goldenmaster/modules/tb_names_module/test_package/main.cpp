
#include "tb_names/implementation/names.h"

using namespace Test::TbNames;

int main(){
    std::unique_ptr<INames> testNames = std::make_unique<Names>();

    return 0;
}
