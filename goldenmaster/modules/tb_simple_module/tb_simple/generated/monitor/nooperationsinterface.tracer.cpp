#include "apigear/tracer/tracer.h"
#include "tb_simple/generated/core/tb_simple.json.adapter.h"
#include "tb_simple/generated/monitor/nooperationsinterface.tracer.h"

using namespace Test::TbSimple;

NoOperationsInterfaceTracer::NoOperationsInterfaceTracer(ApiGear::PocoImpl::Tracer& tracer)
    : m_tracer(tracer)
{
}

void NoOperationsInterfaceTracer::capture_state(INoOperationsInterface* obj)
{
    nlohmann::json fields_;
    fields_["propBool"] = obj->getPropBool();
    fields_["propInt"] = obj->getPropInt();
    m_tracer.state("tb.simple.NoOperationsInterface#_state", fields_);
}
void NoOperationsInterfaceTracer::trace_sigVoid()
{
    nlohmann::json fields_;
    m_tracer.signal("tb.simple.NoOperationsInterface#sigVoid", fields_);
}
void NoOperationsInterfaceTracer::trace_sigBool(bool paramBool)
{
    nlohmann::json fields_;
    fields_["paramBool"] = paramBool;
    m_tracer.signal("tb.simple.NoOperationsInterface#sigBool", fields_);
}