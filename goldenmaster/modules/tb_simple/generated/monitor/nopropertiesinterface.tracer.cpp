#include "apigear/tracer/tracer.h"
#include "tb_simple/generated/core/tb_simple.json.adapter.h"
#include "tb_simple/generated/monitor/nopropertiesinterface.tracer.h"

using namespace Test::TbSimple;

NoPropertiesInterfaceTracer::NoPropertiesInterfaceTracer(ApiGear::PocoImpl::Tracer& tracer)
    : m_tracer(tracer)
{
}

void NoPropertiesInterfaceTracer::capture_state(INoPropertiesInterface* obj)
{
    nlohmann::json fields_;
    (void) obj;
    m_tracer.state("tb.simple.NoPropertiesInterface#_state", fields_);
}

void NoPropertiesInterfaceTracer::trace_funcVoid()
{
    nlohmann::json fields_;
    m_tracer.call("tb.simple.NoPropertiesInterface#funcVoid", fields_);
}

void NoPropertiesInterfaceTracer::trace_funcBool(bool paramBool)
{
    nlohmann::json fields_;
    fields_["paramBool"] = paramBool;
    m_tracer.call("tb.simple.NoPropertiesInterface#funcBool", fields_);
}
void NoPropertiesInterfaceTracer::trace_sigVoid()
{
    nlohmann::json fields_;
    m_tracer.signal("tb.simple.NoPropertiesInterface#sigVoid", fields_);
}
void NoPropertiesInterfaceTracer::trace_sigBool(bool paramBool)
{
    nlohmann::json fields_;
    fields_["paramBool"] = paramBool;
    m_tracer.signal("tb.simple.NoPropertiesInterface#sigBool", fields_);
}