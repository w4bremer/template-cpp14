
#include "testbed1/implementation/structinterface.h"
#include "testbed1/implementation/structarrayinterface.h"

using namespace Test::Testbed1;

int main(){
    std::unique_ptr<IStructInterface> testStructInterface = std::make_unique<StructInterface>();
    std::unique_ptr<IStructArrayInterface> testStructArrayInterface = std::make_unique<StructArrayInterface>();

    return 0;
}
