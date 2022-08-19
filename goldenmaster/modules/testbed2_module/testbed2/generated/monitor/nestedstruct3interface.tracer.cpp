#include "apigear/tracer/tracer.h"
#include "testbed2/generated/core/testbed2.json.adapter.h"
#include "testbed2/generated/monitor/nestedstruct3interface.tracer.h"

using namespace Test::Testbed2;

NestedStruct3InterfaceTracer::NestedStruct3InterfaceTracer(ApiGear::PocoImpl::Tracer& tracer)
    : m_tracer(tracer)
{
}

void NestedStruct3InterfaceTracer::capture_state(INestedStruct3Interface* obj)
{
    nlohmann::json fields_;
    fields_["prop1"] = obj->getProp1();
    fields_["prop2"] = obj->getProp2();
    fields_["prop3"] = obj->getProp3();
    m_tracer.state("testbed2.NestedStruct3Interface#_state", fields_);
}

void NestedStruct3InterfaceTracer::trace_func1(const NestedStruct1& param1)
{
    nlohmann::json fields_;
    fields_["param1"] = param1;
    m_tracer.call("testbed2.NestedStruct3Interface#func1", fields_);
}

void NestedStruct3InterfaceTracer::trace_func2(const NestedStruct1& param1, const NestedStruct2& param2)
{
    nlohmann::json fields_;
    fields_["param1"] = param1;
    fields_["param2"] = param2;
    m_tracer.call("testbed2.NestedStruct3Interface#func2", fields_);
}

void NestedStruct3InterfaceTracer::trace_func3(const NestedStruct1& param1, const NestedStruct2& param2, const NestedStruct3& param3)
{
    nlohmann::json fields_;
    fields_["param1"] = param1;
    fields_["param2"] = param2;
    fields_["param3"] = param3;
    m_tracer.call("testbed2.NestedStruct3Interface#func3", fields_);
}
void NestedStruct3InterfaceTracer::trace_sig1(const NestedStruct1& param1)
{
    nlohmann::json fields_;
    fields_["param1"] = param1;
    m_tracer.signal("testbed2.NestedStruct3Interface#sig1", fields_);
}
void NestedStruct3InterfaceTracer::trace_sig2(const NestedStruct1& param1,const NestedStruct2& param2)
{
    nlohmann::json fields_;
    fields_["param1"] = param1;
    fields_["param2"] = param2;
    m_tracer.signal("testbed2.NestedStruct3Interface#sig2", fields_);
}
void NestedStruct3InterfaceTracer::trace_sig3(const NestedStruct1& param1,const NestedStruct2& param2,const NestedStruct3& param3)
{
    nlohmann::json fields_;
    fields_["param1"] = param1;
    fields_["param2"] = param2;
    fields_["param3"] = param3;
    m_tracer.signal("testbed2.NestedStruct3Interface#sig3", fields_);
}