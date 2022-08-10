#include "apigear/tracer/tracer.h"
#include "tb_same2/generated/core/tb_same2.json.adapter.h"
#include "tb_same2/generated/monitor/sameenum2interface.tracer.h"

using namespace Test::TbSame2;

SameEnum2InterfaceTracer::SameEnum2InterfaceTracer(ApiGear::PocoImpl::Tracer& tracer)
    : m_tracer(tracer)
{
}

void SameEnum2InterfaceTracer::capture_state(ISameEnum2Interface* obj)
{
    nlohmann::json fields_;
    fields_["prop1"] = obj->prop1();
    fields_["prop2"] = obj->prop2();
    m_tracer.state("tb.same2.SameEnum2Interface#_state", fields_);
}

void SameEnum2InterfaceTracer::trace_func1(const Enum1Enum& param1)
{
    nlohmann::json fields_;
    fields_["param1"] = param1;
    m_tracer.call("tb.same2.SameEnum2Interface#func1", fields_);
}

void SameEnum2InterfaceTracer::trace_func2(const Enum1Enum& param1, const Enum2Enum& param2)
{
    nlohmann::json fields_;
    fields_["param1"] = param1;
    fields_["param2"] = param2;
    m_tracer.call("tb.same2.SameEnum2Interface#func2", fields_);
}
void SameEnum2InterfaceTracer::trace_sig1(const Enum1Enum& param1)
{
    nlohmann::json fields_;
    fields_["param1"] = param1;
    m_tracer.signal("tb.same2.SameEnum2Interface#sig1", fields_);
}
void SameEnum2InterfaceTracer::trace_sig2(const Enum1Enum& param1,const Enum2Enum& param2)
{
    nlohmann::json fields_;
    fields_["param1"] = param1;
    fields_["param2"] = param2;
    m_tracer.signal("tb.same2.SameEnum2Interface#sig2", fields_);
}
