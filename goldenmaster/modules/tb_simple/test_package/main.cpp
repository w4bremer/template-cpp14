
#include "tb_simple_simpleinterface.h"
#include "tb_simple_simplearrayinterface.h"

using namespace Test::TbSimple;

int main(){
    std::unique_ptr<ISimpleInterface> testSimpleInterface = std::make_unique<SimpleInterface>();
    std::unique_ptr<ISimpleArrayInterface> testSimpleArrayInterface = std::make_unique<SimpleArrayInterface>();

    return 0;
}
