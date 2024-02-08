
#include "tb_names/implementation/names.h"

using namespace Test::TbNames;

int main(){
    std::unique_ptr<INamEs> testNamEs = std::make_unique<NamEs>();

    return 0;
}
