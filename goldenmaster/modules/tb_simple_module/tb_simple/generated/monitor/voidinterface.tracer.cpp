#include "apigear/tracer/tracer.h"
#include "tb_simple/generated/core/tb_simple.json.adapter.h"
#include "tb_simple/generated/monitor/voidinterface.tracer.h"

using namespace Test::TbSimple;

VoidInterfaceTracer::VoidInterfaceTracer(ApiGear::PocoImpl::Tracer& tracer)
    : m_tracer(tracer)
{
}

void VoidInterfaceTracer::capture_state(IVoidInterface* obj)
{
    nlohmann::json fields_;
    (void) obj;
    m_tracer.state("tb.simple.VoidInterface#_state", fields_);
}

void VoidInterfaceTracer::trace_funcVoid()
{
    nlohmann::json fields_;
    m_tracer.call("tb.simple.VoidInterface#funcVoid", fields_);
}
void VoidInterfaceTracer::trace_sigVoid()
{
    nlohmann::json fields_;
    m_tracer.signal("tb.simple.VoidInterface#sigVoid", fields_);
}