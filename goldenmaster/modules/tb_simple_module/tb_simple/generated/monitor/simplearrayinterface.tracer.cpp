#include "apigear/tracer/tracer.h"
#include "tb_simple/generated/core/tb_simple.json.adapter.h"
#include "tb_simple/generated/monitor/simplearrayinterface.tracer.h"

using namespace Test::TbSimple;

SimpleArrayInterfaceTracer::SimpleArrayInterfaceTracer(ApiGear::PocoImpl::Tracer& tracer)
    : m_tracer(tracer)
{
}

void SimpleArrayInterfaceTracer::capture_state(ISimpleArrayInterface* obj)
{
    nlohmann::json fields_;
    fields_["propBool"] = obj->propBool();
    fields_["propInt"] = obj->propInt();
    fields_["propFloat"] = obj->propFloat();
    fields_["propString"] = obj->propString();
    m_tracer.state("tb.simple.SimpleArrayInterface#_state", fields_);
}

void SimpleArrayInterfaceTracer::trace_funcBool(const std::list<bool>& paramBool)
{
    nlohmann::json fields_;
    fields_["paramBool"] = paramBool;
    m_tracer.call("tb.simple.SimpleArrayInterface#funcBool", fields_);
}

void SimpleArrayInterfaceTracer::trace_funcInt(const std::list<int>& paramInt)
{
    nlohmann::json fields_;
    fields_["paramInt"] = paramInt;
    m_tracer.call("tb.simple.SimpleArrayInterface#funcInt", fields_);
}

void SimpleArrayInterfaceTracer::trace_funcFloat(const std::list<float>& paramFloat)
{
    nlohmann::json fields_;
    fields_["paramFloat"] = paramFloat;
    m_tracer.call("tb.simple.SimpleArrayInterface#funcFloat", fields_);
}

void SimpleArrayInterfaceTracer::trace_funcString(const std::list<std::string>& paramString)
{
    nlohmann::json fields_;
    fields_["paramString"] = paramString;
    m_tracer.call("tb.simple.SimpleArrayInterface#funcString", fields_);
}
void SimpleArrayInterfaceTracer::trace_sigBool(const std::list<bool>& paramBool)
{
    nlohmann::json fields_;
    fields_["paramBool"] = paramBool;
    m_tracer.signal("tb.simple.SimpleArrayInterface#sigBool", fields_);
}
void SimpleArrayInterfaceTracer::trace_sigInt(const std::list<int>& paramInt)
{
    nlohmann::json fields_;
    fields_["paramInt"] = paramInt;
    m_tracer.signal("tb.simple.SimpleArrayInterface#sigInt", fields_);
}
void SimpleArrayInterfaceTracer::trace_sigFloat(const std::list<float>& paramFloat)
{
    nlohmann::json fields_;
    fields_["paramFloat"] = paramFloat;
    m_tracer.signal("tb.simple.SimpleArrayInterface#sigFloat", fields_);
}
void SimpleArrayInterfaceTracer::trace_sigString(const std::list<std::string>& paramString)
{
    nlohmann::json fields_;
    fields_["paramString"] = paramString;
    m_tracer.signal("tb.simple.SimpleArrayInterface#sigString", fields_);
}