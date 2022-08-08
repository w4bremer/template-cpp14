#include "apigear/tracer/tracer.h"
#include "tb_same1/generated/core/tb_same1.json.adapter.h"
#include "tb_same1/generated/monitor/samestruct1interface.tracer.h"

using namespace Test::TbSame1;

SameStruct1InterfaceTracer::SameStruct1InterfaceTracer(ApiGear::PocoImpl::Tracer* tracer)
    : m_tracer(tracer)
{
}

void SameStruct1InterfaceTracer::capture_state(ISameStruct1Interface* obj)
{
    nlohmann::json fields_;
    fields_["prop1"] = obj->prop1();
    m_tracer->state("tb.same1.SameStruct1Interface#_state", fields_);
}

void SameStruct1InterfaceTracer::trace_func1(const Struct1& param1)
{
    nlohmann::json fields_;
    fields_["param1"] = param1;
    m_tracer->call("tb.same1.SameStruct1Interface#func1", fields_);
}
