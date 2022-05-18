
#include "org_objectapi_testbed_interface1.h"
#include "generated/monitor/org_objectapi_testbed_interface1.trace.h"
#include "org_objectapi_testbed_interface2.h"
#include "generated/monitor/org_objectapi_testbed_interface2.trace.h"
#include "apigear/tracer/tracer.h"

using namespace Test;

int main(){
    ApiGear::PocoImpl::Tracer tracer;
    tracer.connect("http://localhost:5555", "testExampleApp");
    std::unique_ptr<OrgObjectapiTestbed::IInterface1> testOrgObjectapiTestbedInterface1 = std::make_unique<OrgObjectapiTestbed::Interface1>();
    std::unique_ptr<OrgObjectapiTestbed::IInterface1Decorator> testOrgObjectapiTestbedInterface1TracerDecorator(OrgObjectapiTestbed::Interface1TracerDecorator::connect(testOrgObjectapiTestbedInterface1.get(), &tracer));
    std::unique_ptr<OrgObjectapiTestbed::IInterface2> testOrgObjectapiTestbedInterface2 = std::make_unique<OrgObjectapiTestbed::Interface2>();
    std::unique_ptr<OrgObjectapiTestbed::IInterface2Decorator> testOrgObjectapiTestbedInterface2TracerDecorator(OrgObjectapiTestbed::Interface2TracerDecorator::connect(testOrgObjectapiTestbedInterface2.get(), &tracer));

    return 0;
}
