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


#include "testbed1_structinterface.trace.h"
#include "testbed1.trace.h"

using namespace Test::Testbed1;
StructInterfaceTracerDecorator::StructInterfaceTracerDecorator(IStructInterface* impl, ApiGear::PocoImpl::Tracer* tracer)
    : AbstractStructInterfaceDecorator(impl)
    , m_tracer(std::make_unique<StructInterfaceTracer>(tracer))
{
}
StructInterfaceTracerDecorator::~StructInterfaceTracerDecorator() = default;
StructInterfaceTracerDecorator* StructInterfaceTracerDecorator::connect(IStructInterface* impl, ApiGear::PocoImpl::Tracer* tracer)
{
    return new StructInterfaceTracerDecorator(impl, tracer);
}
/**
   \brief 
*/
StructBool StructInterfaceTracerDecorator::funcBool(const StructBool& paramBool)
{
    m_tracer->trace_funcBool(paramBool);
    return AbstractStructInterfaceDecorator::funcBool(paramBool);
}
std::future<StructBool> StructInterfaceTracerDecorator::funcBoolAsync(const StructBool& paramBool)
{
    m_tracer->trace_funcBool(paramBool);
    return AbstractStructInterfaceDecorator::funcBoolAsync(paramBool);
}
/**
   \brief 
*/
StructBool StructInterfaceTracerDecorator::funcInt(const StructInt& paramInt)
{
    m_tracer->trace_funcInt(paramInt);
    return AbstractStructInterfaceDecorator::funcInt(paramInt);
}
std::future<StructBool> StructInterfaceTracerDecorator::funcIntAsync(const StructInt& paramInt)
{
    m_tracer->trace_funcInt(paramInt);
    return AbstractStructInterfaceDecorator::funcIntAsync(paramInt);
}
/**
   \brief 
*/
StructFloat StructInterfaceTracerDecorator::funcFloat(const StructFloat& paramFloat)
{
    m_tracer->trace_funcFloat(paramFloat);
    return AbstractStructInterfaceDecorator::funcFloat(paramFloat);
}
std::future<StructFloat> StructInterfaceTracerDecorator::funcFloatAsync(const StructFloat& paramFloat)
{
    m_tracer->trace_funcFloat(paramFloat);
    return AbstractStructInterfaceDecorator::funcFloatAsync(paramFloat);
}
/**
   \brief 
*/
StructString StructInterfaceTracerDecorator::funcString(const StructString& paramString)
{
    m_tracer->trace_funcString(paramString);
    return AbstractStructInterfaceDecorator::funcString(paramString);
}
std::future<StructString> StructInterfaceTracerDecorator::funcStringAsync(const StructString& paramString)
{
    m_tracer->trace_funcString(paramString);
    return AbstractStructInterfaceDecorator::funcStringAsync(paramString);
}
void StructInterfaceTracerDecorator::OnSigBool(const StructBool& paramBool)
{
    (void) paramBool;
    //m_tracer->trace_SigBool(paramBool);
}
void StructInterfaceTracerDecorator::OnSigInt(const StructInt& paramInt)
{
    (void) paramInt;
    //m_tracer->trace_SigInt(paramInt);
}
void StructInterfaceTracerDecorator::OnSigFloat(const StructFloat& paramFloat)
{
    (void) paramFloat;
    //m_tracer->trace_SigFloat(paramFloat);
}
void StructInterfaceTracerDecorator::OnSigString(const StructString& paramString)
{
    (void) paramString;
    //m_tracer->trace_SigString(paramString);
}
void StructInterfaceTracerDecorator::OnPropBoolChanged(const StructBool&)
{
    m_tracer->capture_state(this);
}
void StructInterfaceTracerDecorator::OnPropIntChanged(const StructInt&)
{
    m_tracer->capture_state(this);
}
void StructInterfaceTracerDecorator::OnPropFloatChanged(const StructFloat&)
{
    m_tracer->capture_state(this);
}
void StructInterfaceTracerDecorator::OnPropStringChanged(const StructString&)
{
    m_tracer->capture_state(this);
}
