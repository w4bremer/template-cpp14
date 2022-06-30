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


#include "testbed2_nestedstruct2interface.trace.h"
#include "testbed2.trace.h"

using namespace Test::Testbed2;
NestedStruct2InterfaceTracerDecorator::NestedStruct2InterfaceTracerDecorator(INestedStruct2Interface* impl, ApiGear::PocoImpl::Tracer* tracer)
    : AbstractNestedStruct2InterfaceDecorator(impl)
    , m_tracer(std::make_unique<NestedStruct2InterfaceTracer>(tracer))
{
}
NestedStruct2InterfaceTracerDecorator::~NestedStruct2InterfaceTracerDecorator() = default;
NestedStruct2InterfaceTracerDecorator* NestedStruct2InterfaceTracerDecorator::connect(INestedStruct2Interface* impl, ApiGear::PocoImpl::Tracer* tracer)
{
    return new NestedStruct2InterfaceTracerDecorator(impl, tracer);
}
/**
   \brief 
*/
NestedStruct1 NestedStruct2InterfaceTracerDecorator::func1(const NestedStruct1& param1)
{
    m_tracer->trace_func1(param1);
    return AbstractNestedStruct2InterfaceDecorator::func1(param1);
}
std::future<NestedStruct1> NestedStruct2InterfaceTracerDecorator::func1Async(const NestedStruct1& param1)
{
    m_tracer->trace_func1(param1);
    return AbstractNestedStruct2InterfaceDecorator::func1Async(param1);
}
/**
   \brief 
*/
NestedStruct1 NestedStruct2InterfaceTracerDecorator::func2(const NestedStruct1& param1, const NestedStruct2& param2)
{
    m_tracer->trace_func2(param1,param2);
    return AbstractNestedStruct2InterfaceDecorator::func2(param1,param2);
}
std::future<NestedStruct1> NestedStruct2InterfaceTracerDecorator::func2Async(const NestedStruct1& param1, const NestedStruct2& param2)
{
    m_tracer->trace_func2(param1,param2);
    return AbstractNestedStruct2InterfaceDecorator::func2Async(param1,param2);
}
void NestedStruct2InterfaceTracerDecorator::OnSig1(const NestedStruct1& param1)
{
    (void) param1;
    //m_tracer->trace_Sig1(param1);
}
void NestedStruct2InterfaceTracerDecorator::OnSig2(const NestedStruct1& param1,const NestedStruct2& param2)
{
    (void) param1;
    (void) param2;
    //m_tracer->trace_Sig2(param1,param2);
}
void NestedStruct2InterfaceTracerDecorator::OnProp1Changed(const NestedStruct1&)
{
    m_tracer->capture_state(this);
}
void NestedStruct2InterfaceTracerDecorator::OnProp2Changed(const NestedStruct2&)
{
    m_tracer->capture_state(this);
}
