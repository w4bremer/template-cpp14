#include "apigear/tracer/tracer.h"
#include "org_objectapi_testbed.trace.h"
#include "generated/core/org_objectapi_testbed.json.adapter.h"

using namespace Test::OrgObjectapiTestbed;

Interface1Tracer::Interface1Tracer(ApiGear::PocoImpl::Tracer* tracer)
    : m_tracer(tracer)
{
}

void Interface1Tracer::capture_state(IInterface1* obj)
{
    nlohmann::json fields_;
    fields_["prop1"] = obj->prop1();
    fields_["prop2"] = obj->prop2();
    fields_["prop3"] = obj->prop3();
    fields_["prop4"] = obj->prop4();
    fields_["prop5"] = obj->prop5();
    fields_["prop6"] = obj->prop6();
    fields_["prop7"] = obj->prop7();
    fields_["prop10"] = obj->prop10();
    fields_["prop11"] = obj->prop11();
    fields_["prop12"] = obj->prop12();
    fields_["prop14"] = obj->prop14();
    m_tracer->state("org.objectapi.testbed.Interface1#_state", fields_);
}

void Interface1Tracer::trace_op1()
{
    nlohmann::json fields_;
    m_tracer->call("org.objectapi.testbed.Interface1#op1", fields_);
}

void Interface1Tracer::trace_op2(int step)
{
    nlohmann::json fields_;
    fields_["step"] = step;
    m_tracer->call("org.objectapi.testbed.Interface1#op2", fields_);
}

void Interface1Tracer::trace_op3()
{
    nlohmann::json fields_;
    m_tracer->call("org.objectapi.testbed.Interface1#op3", fields_);
}

Interface2Tracer::Interface2Tracer(ApiGear::PocoImpl::Tracer* tracer)
    : m_tracer(tracer)
{
}

void Interface2Tracer::capture_state(IInterface2* obj)
{
    nlohmann::json fields_;
    fields_["prop200"] = obj->prop200();
    fields_["prop201"] = obj->prop201();
    fields_["prop202"] = obj->prop202();
    fields_["prop203"] = obj->prop203();
    fields_["prop204"] = obj->prop204();
    fields_["prop205"] = obj->prop205();
    m_tracer->state("org.objectapi.testbed.Interface2#_state", fields_);
}
