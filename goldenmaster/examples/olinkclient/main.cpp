#include <iostream>
#include "generated/olink/org_objectapi_testbed_interface1interface.h"
#include "generated/monitor/org_objectapi_testbed_interface1.trace.h"
#include "generated/olink/org_objectapi_testbed_interface2interface.h"
#include "generated/monitor/org_objectapi_testbed_interface2.trace.h"
#include "apigear/olink/olinkclient.h"
#include "apigear/tracer/tracer.h"

using namespace Test;

int main(){
    ApiGear::PocoImpl::Tracer tracer;
    tracer.connect("http://localhost:5555", "testExampleOLinkApp");
    ApiGear::ObjectLink::ClientRegistry registry;
    ApiGear::PocoImpl::OLinkClient testClient(registry);
    std::unique_ptr<OrgObjectapiTestbed::IInterface1> testOrgObjectapiTestbedInterface1 = std::make_unique<OrgObjectapiTestbed::OLinkInterface1>(registry, testClient);
    std::unique_ptr<OrgObjectapiTestbed::IInterface1Decorator> testOrgObjectapiTestbedInterface1TracerDecorator(OrgObjectapiTestbed::Interface1TracerDecorator::connect(testOrgObjectapiTestbedInterface1.get(), &tracer));
    std::unique_ptr<OrgObjectapiTestbed::IInterface2> testOrgObjectapiTestbedInterface2 = std::make_unique<OrgObjectapiTestbed::OLinkInterface2>(registry, testClient);
    std::unique_ptr<OrgObjectapiTestbed::IInterface2Decorator> testOrgObjectapiTestbedInterface2TracerDecorator(OrgObjectapiTestbed::Interface2TracerDecorator::connect(testOrgObjectapiTestbedInterface2.get(), &tracer));
    
    testClient.connectToHost(Poco::URI("ws://localhost:8000"));

    bool keepRunning = true;
    std::string cmd;
    do {
        std::cout << "Enter command:" << std::endl;
        getline (std::cin, cmd);

        if(cmd == "quit"){
            keepRunning = false;
            testClient.disconnect();
        }
    } while(keepRunning);

    return 0;
}
