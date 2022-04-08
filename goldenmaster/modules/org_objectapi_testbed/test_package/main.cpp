
#include "org_objectapi_testbed_interface1.h"
#include "org_objectapi_testbed_interface2.h"

using namespace Test::OrgObjectapiTestbed;

int main(){
    std::unique_ptr<IInterface1> testInterface1 = std::make_unique<Interface1>();
    std::unique_ptr<IInterface2> testInterface2 = std::make_unique<Interface2>();

    return 0;
}
