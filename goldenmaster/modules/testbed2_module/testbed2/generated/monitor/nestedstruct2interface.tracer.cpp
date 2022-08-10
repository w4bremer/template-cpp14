#include "apigear/tracer/tracer.h"
#include "testbed2/generated/core/testbed2.json.adapter.h"
#include "testbed2/generated/monitor/nestedstruct2interface.tracer.h"

using namespace Test::Testbed2;

NestedStruct2InterfaceTracer::NestedStruct2InterfaceTracer(ApiGear::PocoImpl::Tracer& tracer)
    : m_tracer(tracer)
{
}

void NestedStruct2InterfaceTracer::capture_state(INestedStruct2Interface* obj)
{
    nlohmann::json fields_;
    fields_["prop1"] = obj->prop1();
    fields_["prop2"] = obj->prop2();
    m_tracer.state("testbed2.NestedStruct2Interface#_state", fields_);
}

void NestedStruct2InterfaceTracer::trace_func1(const NestedStruct1& param1)
{
    nlohmann::json fields_;
    fields_["param1"] = param1;
    m_tracer.call("testbed2.NestedStruct2Interface#func1", fields_);
}

void NestedStruct2InterfaceTracer::trace_func2(const NestedStruct1& param1, const NestedStruct2& param2)
{
    nlohmann::json fields_;
    fields_["param1"] = param1;
    fields_["param2"] = param2;
    m_tracer.call("testbed2.NestedStruct2Interface#func2", fields_);
}
void NestedStruct2InterfaceTracer::trace_sig1(const NestedStruct1& param1)
{
    nlohmann::json fields_;
    fields_["param1"] = param1;
    m_tracer.signal("testbed2.NestedStruct2Interface#sig1", fields_);
}
void NestedStruct2InterfaceTracer::trace_sig2(const NestedStruct1& param1,const NestedStruct2& param2)
{
    nlohmann::json fields_;
    fields_["param1"] = param1;
    fields_["param2"] = param2;
    m_tracer.signal("testbed2.NestedStruct2Interface#sig2", fields_);
}
