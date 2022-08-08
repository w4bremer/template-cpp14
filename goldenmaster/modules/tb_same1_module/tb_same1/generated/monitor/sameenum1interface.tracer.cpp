#include "apigear/tracer/tracer.h"
#include "tb_same1/generated/core/tb_same1.json.adapter.h"
#include "tb_same1/generated/monitor/sameenum1interface.tracer.h"

using namespace Test::TbSame1;

SameEnum1InterfaceTracer::SameEnum1InterfaceTracer(ApiGear::PocoImpl::Tracer* tracer)
    : m_tracer(tracer)
{
}

void SameEnum1InterfaceTracer::capture_state(ISameEnum1Interface* obj)
{
    nlohmann::json fields_;
    fields_["prop1"] = obj->prop1();
    m_tracer->state("tb.same1.SameEnum1Interface#_state", fields_);
}

void SameEnum1InterfaceTracer::trace_func1(const Enum1Enum& param1)
{
    nlohmann::json fields_;
    fields_["param1"] = param1;
    m_tracer->call("tb.same1.SameEnum1Interface#func1", fields_);
}
