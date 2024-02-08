#include "apigear/tracer/tracer.h"
#include "tb_simple/generated/core/tb_simple.json.adapter.h"
#include "tb_simple/generated/monitor/nosignalsinterface.tracer.h"

using namespace Test::TbSimple;

NoSignalsInterfaceTracer::NoSignalsInterfaceTracer(ApiGear::PocoImpl::Tracer& tracer)
    : m_tracer(tracer)
{
}

void NoSignalsInterfaceTracer::capture_state(INoSignalsInterface* obj)
{
    nlohmann::json fields_;
    fields_["propBool"] = obj->getPropBool();
    fields_["propInt"] = obj->getPropInt();
    m_tracer.state("tb.simple.NoSignalsInterface#_state", fields_);
}

void NoSignalsInterfaceTracer::trace_funcVoid()
{
    nlohmann::json fields_;
    m_tracer.call("tb.simple.NoSignalsInterface#funcVoid", fields_);
}

void NoSignalsInterfaceTracer::trace_funcBool(bool paramBool)
{
    nlohmann::json fields_;
    fields_["paramBool"] = paramBool;
    m_tracer.call("tb.simple.NoSignalsInterface#funcBool", fields_);
}