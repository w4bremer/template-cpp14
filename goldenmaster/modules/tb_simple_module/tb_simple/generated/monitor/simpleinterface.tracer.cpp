#include "apigear/tracer/tracer.h"
#include "tb_simple/generated/core/tb_simple.json.adapter.h"
#include "tb_simple/generated/monitor/simpleinterface.tracer.h"

using namespace Test::TbSimple;

SimpleInterfaceTracer::SimpleInterfaceTracer(ApiGear::PocoImpl::Tracer& tracer)
    : m_tracer(tracer)
{
}

void SimpleInterfaceTracer::capture_state(ISimpleInterface* obj)
{
    nlohmann::json fields_;
    fields_["propBool"] = obj->getPropBool();
    fields_["propInt"] = obj->getPropInt();
    fields_["propFloat"] = obj->getPropFloat();
    fields_["propString"] = obj->getPropString();
    m_tracer.state("tb.simple.SimpleInterface#_state", fields_);
}

void SimpleInterfaceTracer::trace_funcVoid()
{
    nlohmann::json fields_;
    m_tracer.call("tb.simple.SimpleInterface#funcVoid", fields_);
}

void SimpleInterfaceTracer::trace_funcBool(bool paramBool)
{
    nlohmann::json fields_;
    fields_["paramBool"] = paramBool;
    m_tracer.call("tb.simple.SimpleInterface#funcBool", fields_);
}

void SimpleInterfaceTracer::trace_funcInt(int paramInt)
{
    nlohmann::json fields_;
    fields_["paramInt"] = paramInt;
    m_tracer.call("tb.simple.SimpleInterface#funcInt", fields_);
}

void SimpleInterfaceTracer::trace_funcFloat(float paramFloat)
{
    nlohmann::json fields_;
    fields_["paramFloat"] = paramFloat;
    m_tracer.call("tb.simple.SimpleInterface#funcFloat", fields_);
}

void SimpleInterfaceTracer::trace_funcString(const std::string& paramString)
{
    nlohmann::json fields_;
    fields_["paramString"] = paramString;
    m_tracer.call("tb.simple.SimpleInterface#funcString", fields_);
}
void SimpleInterfaceTracer::trace_sigBool(bool paramBool)
{
    nlohmann::json fields_;
    fields_["paramBool"] = paramBool;
    m_tracer.signal("tb.simple.SimpleInterface#sigBool", fields_);
}
void SimpleInterfaceTracer::trace_sigInt(int paramInt)
{
    nlohmann::json fields_;
    fields_["paramInt"] = paramInt;
    m_tracer.signal("tb.simple.SimpleInterface#sigInt", fields_);
}
void SimpleInterfaceTracer::trace_sigFloat(float paramFloat)
{
    nlohmann::json fields_;
    fields_["paramFloat"] = paramFloat;
    m_tracer.signal("tb.simple.SimpleInterface#sigFloat", fields_);
}
void SimpleInterfaceTracer::trace_sigString(const std::string& paramString)
{
    nlohmann::json fields_;
    fields_["paramString"] = paramString;
    m_tracer.signal("tb.simple.SimpleInterface#sigString", fields_);
}