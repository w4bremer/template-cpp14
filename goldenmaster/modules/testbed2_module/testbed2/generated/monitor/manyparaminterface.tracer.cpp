#include "apigear/tracer/tracer.h"
#include "testbed2/generated/core/testbed2.json.adapter.h"
#include "testbed2/generated/monitor/manyparaminterface.tracer.h"

using namespace Test::Testbed2;

ManyParamInterfaceTracer::ManyParamInterfaceTracer(ApiGear::PocoImpl::Tracer& tracer)
    : m_tracer(tracer)
{
}

void ManyParamInterfaceTracer::capture_state(IManyParamInterface* obj)
{
    nlohmann::json fields_;
    fields_["prop1"] = obj->getProp1();
    fields_["prop2"] = obj->getProp2();
    fields_["prop3"] = obj->getProp3();
    fields_["prop4"] = obj->getProp4();
    m_tracer.state("testbed2.ManyParamInterface#_state", fields_);
}

void ManyParamInterfaceTracer::trace_func1(int param1)
{
    nlohmann::json fields_;
    fields_["param1"] = param1;
    m_tracer.call("testbed2.ManyParamInterface#func1", fields_);
}

void ManyParamInterfaceTracer::trace_func2(int param1, int param2)
{
    nlohmann::json fields_;
    fields_["param1"] = param1;
    fields_["param2"] = param2;
    m_tracer.call("testbed2.ManyParamInterface#func2", fields_);
}

void ManyParamInterfaceTracer::trace_func3(int param1, int param2, int param3)
{
    nlohmann::json fields_;
    fields_["param1"] = param1;
    fields_["param2"] = param2;
    fields_["param3"] = param3;
    m_tracer.call("testbed2.ManyParamInterface#func3", fields_);
}

void ManyParamInterfaceTracer::trace_func4(int param1, int param2, int param3, int param4)
{
    nlohmann::json fields_;
    fields_["param1"] = param1;
    fields_["param2"] = param2;
    fields_["param3"] = param3;
    fields_["param4"] = param4;
    m_tracer.call("testbed2.ManyParamInterface#func4", fields_);
}
void ManyParamInterfaceTracer::trace_sig1(int param1)
{
    nlohmann::json fields_;
    fields_["param1"] = param1;
    m_tracer.signal("testbed2.ManyParamInterface#sig1", fields_);
}
void ManyParamInterfaceTracer::trace_sig2(int param1,int param2)
{
    nlohmann::json fields_;
    fields_["param1"] = param1;
    fields_["param2"] = param2;
    m_tracer.signal("testbed2.ManyParamInterface#sig2", fields_);
}
void ManyParamInterfaceTracer::trace_sig3(int param1,int param2,int param3)
{
    nlohmann::json fields_;
    fields_["param1"] = param1;
    fields_["param2"] = param2;
    fields_["param3"] = param3;
    m_tracer.signal("testbed2.ManyParamInterface#sig3", fields_);
}
void ManyParamInterfaceTracer::trace_sig4(int param1,int param2,int param3,int param4)
{
    nlohmann::json fields_;
    fields_["param1"] = param1;
    fields_["param2"] = param2;
    fields_["param3"] = param3;
    fields_["param4"] = param4;
    m_tracer.signal("testbed2.ManyParamInterface#sig4", fields_);
}