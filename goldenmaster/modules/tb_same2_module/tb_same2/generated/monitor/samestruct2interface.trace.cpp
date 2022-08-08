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


#include "tb_same2/generated/monitor/samestruct2interface.trace.h"
#include "tb_same2/generated/monitor/samestruct2interface.tracer.h"

using namespace Test::TbSame2;
SameStruct2InterfaceTracerDecorator::SameStruct2InterfaceTracerDecorator(ISameStruct2Interface* impl, ApiGear::PocoImpl::Tracer* tracer)
    : AbstractSameStruct2InterfaceDecorator(impl)
    , m_tracer(std::make_unique<SameStruct2InterfaceTracer>(tracer))
{
}
SameStruct2InterfaceTracerDecorator::~SameStruct2InterfaceTracerDecorator() = default;
SameStruct2InterfaceTracerDecorator* SameStruct2InterfaceTracerDecorator::connect(ISameStruct2Interface* impl, ApiGear::PocoImpl::Tracer* tracer)
{
    return new SameStruct2InterfaceTracerDecorator(impl, tracer);
}
/**
   \brief 
*/
Struct1 SameStruct2InterfaceTracerDecorator::func1(const Struct1& param1)
{
    m_tracer->trace_func1(param1);
    return AbstractSameStruct2InterfaceDecorator::func1(param1);
}
std::future<Struct1> SameStruct2InterfaceTracerDecorator::func1Async(const Struct1& param1)
{
    m_tracer->trace_func1(param1);
    return AbstractSameStruct2InterfaceDecorator::func1Async(param1);
}
/**
   \brief 
*/
Struct1 SameStruct2InterfaceTracerDecorator::func2(const Struct1& param1, const Struct2& param2)
{
    m_tracer->trace_func2(param1,param2);
    return AbstractSameStruct2InterfaceDecorator::func2(param1,param2);
}
std::future<Struct1> SameStruct2InterfaceTracerDecorator::func2Async(const Struct1& param1, const Struct2& param2)
{
    m_tracer->trace_func2(param1,param2);
    return AbstractSameStruct2InterfaceDecorator::func2Async(param1,param2);
}
void SameStruct2InterfaceTracerDecorator::OnSig1(const Struct1& param1)
{
    (void) param1;
    //m_tracer->trace_Sig1(param1);
}
void SameStruct2InterfaceTracerDecorator::OnSig2(const Struct1& param1,const Struct2& param2)
{
    (void) param1;
    (void) param2;
    //m_tracer->trace_Sig2(param1,param2);
}
void SameStruct2InterfaceTracerDecorator::OnProp1Changed(const Struct2&)
{
    m_tracer->capture_state(this);
}
void SameStruct2InterfaceTracerDecorator::OnProp2Changed(const Struct2&)
{
    m_tracer->capture_state(this);
}
