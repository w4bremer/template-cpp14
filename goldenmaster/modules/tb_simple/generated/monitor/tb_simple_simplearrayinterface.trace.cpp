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


#include "tb_simple_simplearrayinterface.trace.h"
#include "tb_simple.trace.h"

using namespace Test::TbSimple;
SimpleArrayInterfaceTracerDecorator::SimpleArrayInterfaceTracerDecorator(ISimpleArrayInterface* impl, ApiGear::PocoImpl::Tracer* tracer)
    : AbstractSimpleArrayInterfaceDecorator(impl)
    , m_tracer(std::make_unique<SimpleArrayInterfaceTracer>(tracer))
{
}
SimpleArrayInterfaceTracerDecorator::~SimpleArrayInterfaceTracerDecorator() = default;
SimpleArrayInterfaceTracerDecorator* SimpleArrayInterfaceTracerDecorator::connect(ISimpleArrayInterface* impl, ApiGear::PocoImpl::Tracer* tracer)
{
    return new SimpleArrayInterfaceTracerDecorator(impl, tracer);
}
/**
   \brief 
*/
std::list<bool> SimpleArrayInterfaceTracerDecorator::funcBool(const std::list<bool>& paramBool)
{
    m_tracer->trace_funcBool(paramBool);
    return AbstractSimpleArrayInterfaceDecorator::funcBool(paramBool);
}
std::future<std::list<bool>> SimpleArrayInterfaceTracerDecorator::funcBoolAsync(const std::list<bool>& paramBool)
{
    m_tracer->trace_funcBool(paramBool);
    return AbstractSimpleArrayInterfaceDecorator::funcBoolAsync(paramBool);
}
/**
   \brief 
*/
std::list<int> SimpleArrayInterfaceTracerDecorator::funcInt(const std::list<int>& paramInt)
{
    m_tracer->trace_funcInt(paramInt);
    return AbstractSimpleArrayInterfaceDecorator::funcInt(paramInt);
}
std::future<std::list<int>> SimpleArrayInterfaceTracerDecorator::funcIntAsync(const std::list<int>& paramInt)
{
    m_tracer->trace_funcInt(paramInt);
    return AbstractSimpleArrayInterfaceDecorator::funcIntAsync(paramInt);
}
/**
   \brief 
*/
std::list<float> SimpleArrayInterfaceTracerDecorator::funcFloat(const std::list<float>& paramFloat)
{
    m_tracer->trace_funcFloat(paramFloat);
    return AbstractSimpleArrayInterfaceDecorator::funcFloat(paramFloat);
}
std::future<std::list<float>> SimpleArrayInterfaceTracerDecorator::funcFloatAsync(const std::list<float>& paramFloat)
{
    m_tracer->trace_funcFloat(paramFloat);
    return AbstractSimpleArrayInterfaceDecorator::funcFloatAsync(paramFloat);
}
/**
   \brief 
*/
std::list<std::string> SimpleArrayInterfaceTracerDecorator::funcString(const std::list<std::string>& paramString)
{
    m_tracer->trace_funcString(paramString);
    return AbstractSimpleArrayInterfaceDecorator::funcString(paramString);
}
std::future<std::list<std::string>> SimpleArrayInterfaceTracerDecorator::funcStringAsync(const std::list<std::string>& paramString)
{
    m_tracer->trace_funcString(paramString);
    return AbstractSimpleArrayInterfaceDecorator::funcStringAsync(paramString);
}
void SimpleArrayInterfaceTracerDecorator::OnSigBool(const std::list<bool>& paramBool)
{
    (void) paramBool;
    //m_tracer->trace_SigBool(paramBool);
}
void SimpleArrayInterfaceTracerDecorator::OnSigInt(const std::list<int>& paramInt)
{
    (void) paramInt;
    //m_tracer->trace_SigInt(paramInt);
}
void SimpleArrayInterfaceTracerDecorator::OnSigFloat(const std::list<float>& paramFloat)
{
    (void) paramFloat;
    //m_tracer->trace_SigFloat(paramFloat);
}
void SimpleArrayInterfaceTracerDecorator::OnSigString(const std::list<std::string>& paramString)
{
    (void) paramString;
    //m_tracer->trace_SigString(paramString);
}
void SimpleArrayInterfaceTracerDecorator::OnPropBoolChanged(const std::list<bool>&)
{
    m_tracer->capture_state(this);
}
void SimpleArrayInterfaceTracerDecorator::OnPropIntChanged(const std::list<int>&)
{
    m_tracer->capture_state(this);
}
void SimpleArrayInterfaceTracerDecorator::OnPropFloatChanged(const std::list<float>&)
{
    m_tracer->capture_state(this);
}
void SimpleArrayInterfaceTracerDecorator::OnPropStringChanged(const std::list<std::string>&)
{
    m_tracer->capture_state(this);
}
