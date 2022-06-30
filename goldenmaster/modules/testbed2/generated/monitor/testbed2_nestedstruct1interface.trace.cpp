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


#include "testbed2_nestedstruct1interface.trace.h"
#include "testbed2.trace.h"

using namespace Test::Testbed2;
NestedStruct1InterfaceTracerDecorator::NestedStruct1InterfaceTracerDecorator(INestedStruct1Interface* impl, ApiGear::PocoImpl::Tracer* tracer)
    : AbstractNestedStruct1InterfaceDecorator(impl)
    , m_tracer(std::make_unique<NestedStruct1InterfaceTracer>(tracer))
{
}
NestedStruct1InterfaceTracerDecorator::~NestedStruct1InterfaceTracerDecorator() = default;
NestedStruct1InterfaceTracerDecorator* NestedStruct1InterfaceTracerDecorator::connect(INestedStruct1Interface* impl, ApiGear::PocoImpl::Tracer* tracer)
{
    return new NestedStruct1InterfaceTracerDecorator(impl, tracer);
}
/**
   \brief 
*/
NestedStruct1 NestedStruct1InterfaceTracerDecorator::func1(const NestedStruct1& param1)
{
    m_tracer->trace_func1(param1);
    return AbstractNestedStruct1InterfaceDecorator::func1(param1);
}
std::future<NestedStruct1> NestedStruct1InterfaceTracerDecorator::func1Async(const NestedStruct1& param1)
{
    m_tracer->trace_func1(param1);
    return AbstractNestedStruct1InterfaceDecorator::func1Async(param1);
}
void NestedStruct1InterfaceTracerDecorator::OnSig1(const NestedStruct1& param1)
{
    (void) param1;
    //m_tracer->trace_Sig1(param1);
}
void NestedStruct1InterfaceTracerDecorator::OnProp1Changed(const NestedStruct1&)
{
    m_tracer->capture_state(this);
}
