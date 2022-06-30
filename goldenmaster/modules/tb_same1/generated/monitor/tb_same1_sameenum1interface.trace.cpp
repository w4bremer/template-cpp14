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


#include "tb_same1_sameenum1interface.trace.h"
#include "tb_same1.trace.h"

using namespace Test::TbSame1;
SameEnum1InterfaceTracerDecorator::SameEnum1InterfaceTracerDecorator(ISameEnum1Interface* impl, ApiGear::PocoImpl::Tracer* tracer)
    : AbstractSameEnum1InterfaceDecorator(impl)
    , m_tracer(std::make_unique<SameEnum1InterfaceTracer>(tracer))
{
}
SameEnum1InterfaceTracerDecorator::~SameEnum1InterfaceTracerDecorator() = default;
SameEnum1InterfaceTracerDecorator* SameEnum1InterfaceTracerDecorator::connect(ISameEnum1Interface* impl, ApiGear::PocoImpl::Tracer* tracer)
{
    return new SameEnum1InterfaceTracerDecorator(impl, tracer);
}
/**
   \brief 
*/
Enum1Enum SameEnum1InterfaceTracerDecorator::func1(const Enum1Enum& param1)
{
    m_tracer->trace_func1(param1);
    return AbstractSameEnum1InterfaceDecorator::func1(param1);
}
std::future<Enum1Enum> SameEnum1InterfaceTracerDecorator::func1Async(const Enum1Enum& param1)
{
    m_tracer->trace_func1(param1);
    return AbstractSameEnum1InterfaceDecorator::func1Async(param1);
}
void SameEnum1InterfaceTracerDecorator::OnSig1(const Enum1Enum& param1)
{
    (void) param1;
    //m_tracer->trace_Sig1(param1);
}
void SameEnum1InterfaceTracerDecorator::OnProp1Changed(const Enum1Enum&)
{
    m_tracer->capture_state(this);
}
