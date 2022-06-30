#include "apigear/tracer/tracer.h"
#include "testbed2.trace.h"
#include "generated/core/testbed2.json.adapter.h"

using namespace Test::Testbed2;

ManyParamInterfaceTracer::ManyParamInterfaceTracer(ApiGear::PocoImpl::Tracer* tracer)
    : m_tracer(tracer)
{
}

void ManyParamInterfaceTracer::capture_state(IManyParamInterface* obj)
{
    nlohmann::json fields_;
    fields_["prop1"] = obj->prop1();
    fields_["prop2"] = obj->prop2();
    fields_["prop3"] = obj->prop3();
    fields_["prop4"] = obj->prop4();
    m_tracer->state("testbed2.ManyParamInterface#_state", fields_);
}

void ManyParamInterfaceTracer::trace_func1(int param1)
{
    nlohmann::json fields_;
    fields_["param1"] = param1;
    m_tracer->call("testbed2.ManyParamInterface#func1", fields_);
}

void ManyParamInterfaceTracer::trace_func2(int param1, int param2)
{
    nlohmann::json fields_;
    fields_["param1"] = param1;
    fields_["param2"] = param2;
    m_tracer->call("testbed2.ManyParamInterface#func2", fields_);
}

void ManyParamInterfaceTracer::trace_func3(int param1, int param2, int param3)
{
    nlohmann::json fields_;
    fields_["param1"] = param1;
    fields_["param2"] = param2;
    fields_["param3"] = param3;
    m_tracer->call("testbed2.ManyParamInterface#func3", fields_);
}

void ManyParamInterfaceTracer::trace_func4(int param1, int param2, int param3, int param4)
{
    nlohmann::json fields_;
    fields_["param1"] = param1;
    fields_["param2"] = param2;
    fields_["param3"] = param3;
    fields_["param4"] = param4;
    m_tracer->call("testbed2.ManyParamInterface#func4", fields_);
}

NestedStruct1InterfaceTracer::NestedStruct1InterfaceTracer(ApiGear::PocoImpl::Tracer* tracer)
    : m_tracer(tracer)
{
}

void NestedStruct1InterfaceTracer::capture_state(INestedStruct1Interface* obj)
{
    nlohmann::json fields_;
    fields_["prop1"] = obj->prop1();
    m_tracer->state("testbed2.NestedStruct1Interface#_state", fields_);
}

void NestedStruct1InterfaceTracer::trace_func1(const NestedStruct1& param1)
{
    nlohmann::json fields_;
    fields_["param1"] = param1;
    m_tracer->call("testbed2.NestedStruct1Interface#func1", fields_);
}

NestedStruct2InterfaceTracer::NestedStruct2InterfaceTracer(ApiGear::PocoImpl::Tracer* tracer)
    : m_tracer(tracer)
{
}

void NestedStruct2InterfaceTracer::capture_state(INestedStruct2Interface* obj)
{
    nlohmann::json fields_;
    fields_["prop1"] = obj->prop1();
    fields_["prop2"] = obj->prop2();
    m_tracer->state("testbed2.NestedStruct2Interface#_state", fields_);
}

void NestedStruct2InterfaceTracer::trace_func1(const NestedStruct1& param1)
{
    nlohmann::json fields_;
    fields_["param1"] = param1;
    m_tracer->call("testbed2.NestedStruct2Interface#func1", fields_);
}

void NestedStruct2InterfaceTracer::trace_func2(const NestedStruct1& param1, const NestedStruct2& param2)
{
    nlohmann::json fields_;
    fields_["param1"] = param1;
    fields_["param2"] = param2;
    m_tracer->call("testbed2.NestedStruct2Interface#func2", fields_);
}

NestedStruct3InterfaceTracer::NestedStruct3InterfaceTracer(ApiGear::PocoImpl::Tracer* tracer)
    : m_tracer(tracer)
{
}

void NestedStruct3InterfaceTracer::capture_state(INestedStruct3Interface* obj)
{
    nlohmann::json fields_;
    fields_["prop1"] = obj->prop1();
    fields_["prop2"] = obj->prop2();
    fields_["prop3"] = obj->prop3();
    m_tracer->state("testbed2.NestedStruct3Interface#_state", fields_);
}

void NestedStruct3InterfaceTracer::trace_func1(const NestedStruct1& param1)
{
    nlohmann::json fields_;
    fields_["param1"] = param1;
    m_tracer->call("testbed2.NestedStruct3Interface#func1", fields_);
}

void NestedStruct3InterfaceTracer::trace_func2(const NestedStruct1& param1, const NestedStruct2& param2)
{
    nlohmann::json fields_;
    fields_["param1"] = param1;
    fields_["param2"] = param2;
    m_tracer->call("testbed2.NestedStruct3Interface#func2", fields_);
}

void NestedStruct3InterfaceTracer::trace_func3(const NestedStruct1& param1, const NestedStruct2& param2, const NestedStruct3& param3)
{
    nlohmann::json fields_;
    fields_["param1"] = param1;
    fields_["param2"] = param2;
    fields_["param3"] = param3;
    m_tracer->call("testbed2.NestedStruct3Interface#func3", fields_);
}
