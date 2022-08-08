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


#include "tb_same1/generated/monitor/samestruct1interface.trace.h"
#include "tb_same1/generated/monitor/samestruct1interface.tracer.h"

using namespace Test::TbSame1;
SameStruct1InterfaceTracerDecorator::SameStruct1InterfaceTracerDecorator(ISameStruct1Interface* impl, ApiGear::PocoImpl::Tracer* tracer)
    : AbstractSameStruct1InterfaceDecorator(impl)
    , m_tracer(std::make_unique<SameStruct1InterfaceTracer>(tracer))
{
}
SameStruct1InterfaceTracerDecorator::~SameStruct1InterfaceTracerDecorator() = default;
SameStruct1InterfaceTracerDecorator* SameStruct1InterfaceTracerDecorator::connect(ISameStruct1Interface* impl, ApiGear::PocoImpl::Tracer* tracer)
{
    return new SameStruct1InterfaceTracerDecorator(impl, tracer);
}
/**
   \brief 
*/
Struct1 SameStruct1InterfaceTracerDecorator::func1(const Struct1& param1)
{
    m_tracer->trace_func1(param1);
    return AbstractSameStruct1InterfaceDecorator::func1(param1);
}
std::future<Struct1> SameStruct1InterfaceTracerDecorator::func1Async(const Struct1& param1)
{
    m_tracer->trace_func1(param1);
    return AbstractSameStruct1InterfaceDecorator::func1Async(param1);
}
void SameStruct1InterfaceTracerDecorator::OnSig1(const Struct1& param1)
{
    (void) param1;
    //m_tracer->trace_Sig1(param1);
}
void SameStruct1InterfaceTracerDecorator::OnProp1Changed(const Struct1&)
{
    m_tracer->capture_state(this);
}
