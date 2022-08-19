#include "apigear/tracer/tracer.h"
#include "tb_same1/generated/core/tb_same1.json.adapter.h"
#include "tb_same1/generated/monitor/sameenum2interface.tracer.h"

using namespace Test::TbSame1;

SameEnum2InterfaceTracer::SameEnum2InterfaceTracer(ApiGear::PocoImpl::Tracer& tracer)
    : m_tracer(tracer)
{
}

void SameEnum2InterfaceTracer::capture_state(ISameEnum2Interface* obj)
{
    nlohmann::json fields_;
    fields_["prop1"] = obj->getProp1();
    fields_["prop2"] = obj->getProp2();
    m_tracer.state("tb.same1.SameEnum2Interface#_state", fields_);
}

void SameEnum2InterfaceTracer::trace_func1(const Enum1Enum& param1)
{
    nlohmann::json fields_;
    fields_["param1"] = param1;
    m_tracer.call("tb.same1.SameEnum2Interface#func1", fields_);
}

void SameEnum2InterfaceTracer::trace_func2(const Enum1Enum& param1, const Enum2Enum& param2)
{
    nlohmann::json fields_;
    fields_["param1"] = param1;
    fields_["param2"] = param2;
    m_tracer.call("tb.same1.SameEnum2Interface#func2", fields_);
}
void SameEnum2InterfaceTracer::trace_sig1(const Enum1Enum& param1)
{
    nlohmann::json fields_;
    fields_["param1"] = param1;
    m_tracer.signal("tb.same1.SameEnum2Interface#sig1", fields_);
}
void SameEnum2InterfaceTracer::trace_sig2(const Enum1Enum& param1,const Enum2Enum& param2)
{
    nlohmann::json fields_;
    fields_["param1"] = param1;
    fields_["param2"] = param2;
    m_tracer.signal("tb.same1.SameEnum2Interface#sig2", fields_);
}