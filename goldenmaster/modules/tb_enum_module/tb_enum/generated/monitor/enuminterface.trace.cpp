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


#include "tb_enum/generated/monitor/enuminterface.trace.h"
#include "tb_enum/generated/monitor/enuminterface.tracer.h"

using namespace Test::TbEnum;
EnumInterfaceTracerDecorator::EnumInterfaceTracerDecorator(IEnumInterface* impl, ApiGear::PocoImpl::Tracer* tracer)
    : AbstractEnumInterfaceDecorator(impl)
    , m_tracer(std::make_unique<EnumInterfaceTracer>(tracer))
{
}
EnumInterfaceTracerDecorator::~EnumInterfaceTracerDecorator() = default;
EnumInterfaceTracerDecorator* EnumInterfaceTracerDecorator::connect(IEnumInterface* impl, ApiGear::PocoImpl::Tracer* tracer)
{
    return new EnumInterfaceTracerDecorator(impl, tracer);
}
/**
   \brief 
*/
Enum0Enum EnumInterfaceTracerDecorator::func0(const Enum0Enum& param0)
{
    m_tracer->trace_func0(param0);
    return AbstractEnumInterfaceDecorator::func0(param0);
}
std::future<Enum0Enum> EnumInterfaceTracerDecorator::func0Async(const Enum0Enum& param0)
{
    m_tracer->trace_func0(param0);
    return AbstractEnumInterfaceDecorator::func0Async(param0);
}
/**
   \brief 
*/
Enum1Enum EnumInterfaceTracerDecorator::func1(const Enum1Enum& param1)
{
    m_tracer->trace_func1(param1);
    return AbstractEnumInterfaceDecorator::func1(param1);
}
std::future<Enum1Enum> EnumInterfaceTracerDecorator::func1Async(const Enum1Enum& param1)
{
    m_tracer->trace_func1(param1);
    return AbstractEnumInterfaceDecorator::func1Async(param1);
}
/**
   \brief 
*/
Enum2Enum EnumInterfaceTracerDecorator::func2(const Enum2Enum& param2)
{
    m_tracer->trace_func2(param2);
    return AbstractEnumInterfaceDecorator::func2(param2);
}
std::future<Enum2Enum> EnumInterfaceTracerDecorator::func2Async(const Enum2Enum& param2)
{
    m_tracer->trace_func2(param2);
    return AbstractEnumInterfaceDecorator::func2Async(param2);
}
/**
   \brief 
*/
Enum3Enum EnumInterfaceTracerDecorator::func3(const Enum3Enum& param3)
{
    m_tracer->trace_func3(param3);
    return AbstractEnumInterfaceDecorator::func3(param3);
}
std::future<Enum3Enum> EnumInterfaceTracerDecorator::func3Async(const Enum3Enum& param3)
{
    m_tracer->trace_func3(param3);
    return AbstractEnumInterfaceDecorator::func3Async(param3);
}
void EnumInterfaceTracerDecorator::OnSig0(const Enum0Enum& param0)
{
    (void) param0;
    //m_tracer->trace_Sig0(param0);
}
void EnumInterfaceTracerDecorator::OnSig1(const Enum1Enum& param1)
{
    (void) param1;
    //m_tracer->trace_Sig1(param1);
}
void EnumInterfaceTracerDecorator::OnSig2(const Enum2Enum& param2)
{
    (void) param2;
    //m_tracer->trace_Sig2(param2);
}
void EnumInterfaceTracerDecorator::OnSig3(const Enum3Enum& param3)
{
    (void) param3;
    //m_tracer->trace_Sig3(param3);
}
void EnumInterfaceTracerDecorator::OnProp0Changed(const Enum0Enum&)
{
    m_tracer->capture_state(this);
}
void EnumInterfaceTracerDecorator::OnProp1Changed(const Enum1Enum&)
{
    m_tracer->capture_state(this);
}
void EnumInterfaceTracerDecorator::OnProp2Changed(const Enum2Enum&)
{
    m_tracer->capture_state(this);
}
void EnumInterfaceTracerDecorator::OnProp3Changed(const Enum3Enum&)
{
    m_tracer->capture_state(this);
}
