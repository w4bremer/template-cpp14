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


#include "testbed1/generated/monitor/structarrayinterface.trace.h"
#include "testbed1/generated/monitor/structarrayinterface.tracer.h"

using namespace Test::Testbed1;
StructArrayInterfaceTracerDecorator::StructArrayInterfaceTracerDecorator(IStructArrayInterface* impl, ApiGear::PocoImpl::Tracer* tracer)
    : AbstractStructArrayInterfaceDecorator(impl)
    , m_tracer(std::make_unique<StructArrayInterfaceTracer>(tracer))
{
}
StructArrayInterfaceTracerDecorator::~StructArrayInterfaceTracerDecorator() = default;
StructArrayInterfaceTracerDecorator* StructArrayInterfaceTracerDecorator::connect(IStructArrayInterface* impl, ApiGear::PocoImpl::Tracer* tracer)
{
    return new StructArrayInterfaceTracerDecorator(impl, tracer);
}
/**
   \brief 
*/
StructBool StructArrayInterfaceTracerDecorator::funcBool(const std::list<StructBool>& paramBool)
{
    m_tracer->trace_funcBool(paramBool);
    return AbstractStructArrayInterfaceDecorator::funcBool(paramBool);
}
std::future<StructBool> StructArrayInterfaceTracerDecorator::funcBoolAsync(const std::list<StructBool>& paramBool)
{
    m_tracer->trace_funcBool(paramBool);
    return AbstractStructArrayInterfaceDecorator::funcBoolAsync(paramBool);
}
/**
   \brief 
*/
StructBool StructArrayInterfaceTracerDecorator::funcInt(const std::list<StructInt>& paramInt)
{
    m_tracer->trace_funcInt(paramInt);
    return AbstractStructArrayInterfaceDecorator::funcInt(paramInt);
}
std::future<StructBool> StructArrayInterfaceTracerDecorator::funcIntAsync(const std::list<StructInt>& paramInt)
{
    m_tracer->trace_funcInt(paramInt);
    return AbstractStructArrayInterfaceDecorator::funcIntAsync(paramInt);
}
/**
   \brief 
*/
StructBool StructArrayInterfaceTracerDecorator::funcFloat(const std::list<StructFloat>& paramFloat)
{
    m_tracer->trace_funcFloat(paramFloat);
    return AbstractStructArrayInterfaceDecorator::funcFloat(paramFloat);
}
std::future<StructBool> StructArrayInterfaceTracerDecorator::funcFloatAsync(const std::list<StructFloat>& paramFloat)
{
    m_tracer->trace_funcFloat(paramFloat);
    return AbstractStructArrayInterfaceDecorator::funcFloatAsync(paramFloat);
}
/**
   \brief 
*/
StructBool StructArrayInterfaceTracerDecorator::funcString(const std::list<StructString>& paramString)
{
    m_tracer->trace_funcString(paramString);
    return AbstractStructArrayInterfaceDecorator::funcString(paramString);
}
std::future<StructBool> StructArrayInterfaceTracerDecorator::funcStringAsync(const std::list<StructString>& paramString)
{
    m_tracer->trace_funcString(paramString);
    return AbstractStructArrayInterfaceDecorator::funcStringAsync(paramString);
}
void StructArrayInterfaceTracerDecorator::OnSigBool(const std::list<StructBool>& paramBool)
{
    (void) paramBool;
    //m_tracer->trace_SigBool(paramBool);
}
void StructArrayInterfaceTracerDecorator::OnSigInt(const std::list<StructInt>& paramInt)
{
    (void) paramInt;
    //m_tracer->trace_SigInt(paramInt);
}
void StructArrayInterfaceTracerDecorator::OnSigFloat(const std::list<StructFloat>& paramFloat)
{
    (void) paramFloat;
    //m_tracer->trace_SigFloat(paramFloat);
}
void StructArrayInterfaceTracerDecorator::OnSigString(const std::list<StructString>& paramString)
{
    (void) paramString;
    //m_tracer->trace_SigString(paramString);
}
void StructArrayInterfaceTracerDecorator::OnPropBoolChanged(const std::list<StructBool>&)
{
    m_tracer->capture_state(this);
}
void StructArrayInterfaceTracerDecorator::OnPropIntChanged(const std::list<StructInt>&)
{
    m_tracer->capture_state(this);
}
void StructArrayInterfaceTracerDecorator::OnPropFloatChanged(const std::list<StructFloat>&)
{
    m_tracer->capture_state(this);
}
void StructArrayInterfaceTracerDecorator::OnPropStringChanged(const std::list<StructString>&)
{
    m_tracer->capture_state(this);
}
