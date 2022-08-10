/**
NO TITLE
Copyright (C) 2020 ApiGear UG

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/


#include "testbed2/generated/monitor/nestedstruct3interface.trace.h"
#include "testbed2/generated/monitor/nestedstruct3interface.tracer.h"

using namespace Test::Testbed2;
NestedStruct3InterfaceTracerDecorator::NestedStruct3InterfaceTracerDecorator(INestedStruct3Interface* impl, ApiGear::PocoImpl::Tracer& tracer)
    : AbstractNestedStruct3InterfaceDecorator(impl)
    , m_tracer(std::make_unique<NestedStruct3InterfaceTracer>(tracer))
{
}
NestedStruct3InterfaceTracerDecorator::~NestedStruct3InterfaceTracerDecorator() = default;
NestedStruct3InterfaceTracerDecorator* NestedStruct3InterfaceTracerDecorator::connect(INestedStruct3Interface* impl, ApiGear::PocoImpl::Tracer& tracer)
{
    return new NestedStruct3InterfaceTracerDecorator(impl, tracer);
}
/**
   \brief 
*/
NestedStruct1 NestedStruct3InterfaceTracerDecorator::func1(const NestedStruct1& param1)
{
    m_tracer->trace_func1(param1);
    return AbstractNestedStruct3InterfaceDecorator::func1(param1);
}
std::future<NestedStruct1> NestedStruct3InterfaceTracerDecorator::func1Async(const NestedStruct1& param1)
{
    m_tracer->trace_func1(param1);
    return AbstractNestedStruct3InterfaceDecorator::func1Async(param1);
}
/**
   \brief 
*/
NestedStruct1 NestedStruct3InterfaceTracerDecorator::func2(const NestedStruct1& param1, const NestedStruct2& param2)
{
    m_tracer->trace_func2(param1,param2);
    return AbstractNestedStruct3InterfaceDecorator::func2(param1,param2);
}
std::future<NestedStruct1> NestedStruct3InterfaceTracerDecorator::func2Async(const NestedStruct1& param1, const NestedStruct2& param2)
{
    m_tracer->trace_func2(param1,param2);
    return AbstractNestedStruct3InterfaceDecorator::func2Async(param1,param2);
}
/**
   \brief 
*/
NestedStruct1 NestedStruct3InterfaceTracerDecorator::func3(const NestedStruct1& param1, const NestedStruct2& param2, const NestedStruct3& param3)
{
    m_tracer->trace_func3(param1,param2,param3);
    return AbstractNestedStruct3InterfaceDecorator::func3(param1,param2,param3);
}
std::future<NestedStruct1> NestedStruct3InterfaceTracerDecorator::func3Async(const NestedStruct1& param1, const NestedStruct2& param2, const NestedStruct3& param3)
{
    m_tracer->trace_func3(param1,param2,param3);
    return AbstractNestedStruct3InterfaceDecorator::func3Async(param1,param2,param3);
}
void NestedStruct3InterfaceTracerDecorator::onSig1(const NestedStruct1& param1)
{
    (void) param1;
    //m_tracer->trace_Sig1(param1);
}
void NestedStruct3InterfaceTracerDecorator::onSig2(const NestedStruct1& param1,const NestedStruct2& param2)
{
    (void) param1;
    (void) param2;
    //m_tracer->trace_Sig2(param1,param2);
}
void NestedStruct3InterfaceTracerDecorator::onSig3(const NestedStruct1& param1,const NestedStruct2& param2,const NestedStruct3& param3)
{
    (void) param1;
    (void) param2;
    (void) param3;
    //m_tracer->trace_Sig3(param1,param2,param3);
}
void NestedStruct3InterfaceTracerDecorator::onProp1Changed(const NestedStruct1&)
{
    m_tracer->capture_state(this);
}
void NestedStruct3InterfaceTracerDecorator::onProp2Changed(const NestedStruct2&)
{
    m_tracer->capture_state(this);
}
void NestedStruct3InterfaceTracerDecorator::onProp3Changed(const NestedStruct3&)
{
    m_tracer->capture_state(this);
}
