#include <iostream>
#include "org_objectapi_testbed_interface1.h"
#include "generated/olink/org_objectapi_testbed_interface1adapter.h"
#include "org_objectapi_testbed_interface2.h"
#include "generated/olink/org_objectapi_testbed_interface2adapter.h"
#include "apigear/olink/olinkhost.h"

using namespace Test;

int main(){
    ApiGear::ObjectLink::RemoteRegistry registry;
    ApiGear::PocoImpl::OLinkHost testserver(registry);
    std::unique_ptr<OrgObjectapiTestbed::IInterface1> testOrgObjectapiTestbedInterface1 = std::make_unique<OrgObjectapiTestbed::Interface1>();
    OrgObjectapiTestbed::OLinkInterface1Adapter testOrgObjectapiTestbedInterface1Adapter(testOrgObjectapiTestbedInterface1.get(), registry);
    std::unique_ptr<OrgObjectapiTestbed::IInterface2> testOrgObjectapiTestbedInterface2 = std::make_unique<OrgObjectapiTestbed::Interface2>();
    OrgObjectapiTestbed::OLinkInterface2Adapter testOrgObjectapiTestbedInterface2Adapter(testOrgObjectapiTestbedInterface2.get(), registry);

    testserver.listen(8000);

    bool keepRunning = true;
    std::string cmd;
    do {
        std::cout << "Enter command:" << std::endl;
        getline (std::cin, cmd);

        if(cmd == "quit"){
            testserver.close();
            keepRunning = false;
        }
    } while(keepRunning);

    return 0;
}
