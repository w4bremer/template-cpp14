#include "apigear/tracer/tracer.h"
#include "tb_same1/generated/core/tb_same1.json.adapter.h"
#include "tb_same1/generated/monitor/samestruct2interface.tracer.h"

using namespace Test::TbSame1;

SameStruct2InterfaceTracer::SameStruct2InterfaceTracer(ApiGear::PocoImpl::Tracer& tracer)
    : m_tracer(tracer)
{
}

void SameStruct2InterfaceTracer::capture_state(ISameStruct2Interface* obj)
{
    nlohmann::json fields_;
    fields_["prop1"] = obj->getProp1();
    fields_["prop2"] = obj->getProp2();
    m_tracer.state("tb.same1.SameStruct2Interface#_state", fields_);
}

void SameStruct2InterfaceTracer::trace_func1(const Struct1& param1)
{
    nlohmann::json fields_;
    fields_["param1"] = param1;
    m_tracer.call("tb.same1.SameStruct2Interface#func1", fields_);
}

void SameStruct2InterfaceTracer::trace_func2(const Struct1& param1, const Struct2& param2)
{
    nlohmann::json fields_;
    fields_["param1"] = param1;
    fields_["param2"] = param2;
    m_tracer.call("tb.same1.SameStruct2Interface#func2", fields_);
}
void SameStruct2InterfaceTracer::trace_sig1(const Struct1& param1)
{
    nlohmann::json fields_;
    fields_["param1"] = param1;
    m_tracer.signal("tb.same1.SameStruct2Interface#sig1", fields_);
}
void SameStruct2InterfaceTracer::trace_sig2(const Struct1& param1,const Struct2& param2)
{
    nlohmann::json fields_;
    fields_["param1"] = param1;
    fields_["param2"] = param2;
    m_tracer.signal("tb.same1.SameStruct2Interface#sig2", fields_);
}