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


#include "tb_same2_sameenum2interface.trace.h"
#include "tb_same2.trace.h"

using namespace Test::TbSame2;
SameEnum2InterfaceTracerDecorator::SameEnum2InterfaceTracerDecorator(ISameEnum2Interface* impl, ApiGear::PocoImpl::Tracer* tracer)
    : AbstractSameEnum2InterfaceDecorator(impl)
    , m_tracer(std::make_unique<SameEnum2InterfaceTracer>(tracer))
{
}
SameEnum2InterfaceTracerDecorator::~SameEnum2InterfaceTracerDecorator() = default;
SameEnum2InterfaceTracerDecorator* SameEnum2InterfaceTracerDecorator::connect(ISameEnum2Interface* impl, ApiGear::PocoImpl::Tracer* tracer)
{
    return new SameEnum2InterfaceTracerDecorator(impl, tracer);
}
/**
   \brief 
*/
Enum1Enum SameEnum2InterfaceTracerDecorator::func1(const Enum1Enum& param1)
{
    m_tracer->trace_func1(param1);
    return AbstractSameEnum2InterfaceDecorator::func1(param1);
}
std::future<Enum1Enum> SameEnum2InterfaceTracerDecorator::func1Async(const Enum1Enum& param1)
{
    m_tracer->trace_func1(param1);
    return AbstractSameEnum2InterfaceDecorator::func1Async(param1);
}
/**
   \brief 
*/
Enum1Enum SameEnum2InterfaceTracerDecorator::func2(const Enum1Enum& param1, const Enum2Enum& param2)
{
    m_tracer->trace_func2(param1,param2);
    return AbstractSameEnum2InterfaceDecorator::func2(param1,param2);
}
std::future<Enum1Enum> SameEnum2InterfaceTracerDecorator::func2Async(const Enum1Enum& param1, const Enum2Enum& param2)
{
    m_tracer->trace_func2(param1,param2);
    return AbstractSameEnum2InterfaceDecorator::func2Async(param1,param2);
}
void SameEnum2InterfaceTracerDecorator::OnSig1(const Enum1Enum& param1)
{
    (void) param1;
    //m_tracer->trace_Sig1(param1);
}
void SameEnum2InterfaceTracerDecorator::OnSig2(const Enum1Enum& param1,const Enum2Enum& param2)
{
    (void) param1;
    (void) param2;
    //m_tracer->trace_Sig2(param1,param2);
}
void SameEnum2InterfaceTracerDecorator::OnProp1Changed(const Enum1Enum&)
{
    m_tracer->capture_state(this);
}
void SameEnum2InterfaceTracerDecorator::OnProp2Changed(const Enum2Enum&)
{
    m_tracer->capture_state(this);
}
