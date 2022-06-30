#include "apigear/tracer/tracer.h"
#include "tb_same1.trace.h"
#include "generated/core/tb_same1.json.adapter.h"

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

SameStruct2InterfaceTracer::SameStruct2InterfaceTracer(ApiGear::PocoImpl::Tracer* tracer)
    : m_tracer(tracer)
{
}

void SameStruct2InterfaceTracer::capture_state(ISameStruct2Interface* obj)
{
    nlohmann::json fields_;
    fields_["prop1"] = obj->prop1();
    fields_["prop2"] = obj->prop2();
    m_tracer->state("tb.same1.SameStruct2Interface#_state", fields_);
}

void SameStruct2InterfaceTracer::trace_func1(const Struct1& param1)
{
    nlohmann::json fields_;
    fields_["param1"] = param1;
    m_tracer->call("tb.same1.SameStruct2Interface#func1", fields_);
}

void SameStruct2InterfaceTracer::trace_func2(const Struct1& param1, const Struct2& param2)
{
    nlohmann::json fields_;
    fields_["param1"] = param1;
    fields_["param2"] = param2;
    m_tracer->call("tb.same1.SameStruct2Interface#func2", fields_);
}

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

SameEnum2InterfaceTracer::SameEnum2InterfaceTracer(ApiGear::PocoImpl::Tracer* tracer)
    : m_tracer(tracer)
{
}

void SameEnum2InterfaceTracer::capture_state(ISameEnum2Interface* obj)
{
    nlohmann::json fields_;
    fields_["prop1"] = obj->prop1();
    fields_["prop2"] = obj->prop2();
    m_tracer->state("tb.same1.SameEnum2Interface#_state", fields_);
}

void SameEnum2InterfaceTracer::trace_func1(const Enum1Enum& param1)
{
    nlohmann::json fields_;
    fields_["param1"] = param1;
    m_tracer->call("tb.same1.SameEnum2Interface#func1", fields_);
}

void SameEnum2InterfaceTracer::trace_func2(const Enum1Enum& param1, const Enum2Enum& param2)
{
    nlohmann::json fields_;
    fields_["param1"] = param1;
    fields_["param2"] = param2;
    m_tracer->call("tb.same1.SameEnum2Interface#func2", fields_);
}
