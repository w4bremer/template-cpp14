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


#include "tb_simple_simpleinterface.trace.h"
#include "tb_simple.trace.h"

using namespace Test::TbSimple;
SimpleInterfaceTracerDecorator::SimpleInterfaceTracerDecorator(ISimpleInterface* impl, ApiGear::PocoImpl::Tracer* tracer)
    : AbstractSimpleInterfaceDecorator(impl)
    , m_tracer(std::make_unique<SimpleInterfaceTracer>(tracer))
{
}
SimpleInterfaceTracerDecorator::~SimpleInterfaceTracerDecorator() = default;
SimpleInterfaceTracerDecorator* SimpleInterfaceTracerDecorator::connect(ISimpleInterface* impl, ApiGear::PocoImpl::Tracer* tracer)
{
    return new SimpleInterfaceTracerDecorator(impl, tracer);
}
/**
   \brief 
*/
bool SimpleInterfaceTracerDecorator::funcBool(bool paramBool)
{
    m_tracer->trace_funcBool(paramBool);
    return AbstractSimpleInterfaceDecorator::funcBool(paramBool);
}
std::future<bool> SimpleInterfaceTracerDecorator::funcBoolAsync(bool paramBool)
{
    m_tracer->trace_funcBool(paramBool);
    return AbstractSimpleInterfaceDecorator::funcBoolAsync(paramBool);
}
/**
   \brief 
*/
int SimpleInterfaceTracerDecorator::funcInt(int paramInt)
{
    m_tracer->trace_funcInt(paramInt);
    return AbstractSimpleInterfaceDecorator::funcInt(paramInt);
}
std::future<int> SimpleInterfaceTracerDecorator::funcIntAsync(int paramInt)
{
    m_tracer->trace_funcInt(paramInt);
    return AbstractSimpleInterfaceDecorator::funcIntAsync(paramInt);
}
/**
   \brief 
*/
float SimpleInterfaceTracerDecorator::funcFloat(float paramFloat)
{
    m_tracer->trace_funcFloat(paramFloat);
    return AbstractSimpleInterfaceDecorator::funcFloat(paramFloat);
}
std::future<float> SimpleInterfaceTracerDecorator::funcFloatAsync(float paramFloat)
{
    m_tracer->trace_funcFloat(paramFloat);
    return AbstractSimpleInterfaceDecorator::funcFloatAsync(paramFloat);
}
/**
   \brief 
*/
std::string SimpleInterfaceTracerDecorator::funcString(const std::string& paramString)
{
    m_tracer->trace_funcString(paramString);
    return AbstractSimpleInterfaceDecorator::funcString(paramString);
}
std::future<std::string> SimpleInterfaceTracerDecorator::funcStringAsync(const std::string& paramString)
{
    m_tracer->trace_funcString(paramString);
    return AbstractSimpleInterfaceDecorator::funcStringAsync(paramString);
}
void SimpleInterfaceTracerDecorator::OnSigBool(bool paramBool)
{
    (void) paramBool;
    //m_tracer->trace_SigBool(paramBool);
}
void SimpleInterfaceTracerDecorator::OnSigInt(int paramInt)
{
    (void) paramInt;
    //m_tracer->trace_SigInt(paramInt);
}
void SimpleInterfaceTracerDecorator::OnSigFloat(float paramFloat)
{
    (void) paramFloat;
    //m_tracer->trace_SigFloat(paramFloat);
}
void SimpleInterfaceTracerDecorator::OnSigString(const std::string& paramString)
{
    (void) paramString;
    //m_tracer->trace_SigString(paramString);
}
void SimpleInterfaceTracerDecorator::OnPropBoolChanged(bool)
{
    m_tracer->capture_state(this);
}
void SimpleInterfaceTracerDecorator::OnPropIntChanged(int)
{
    m_tracer->capture_state(this);
}
void SimpleInterfaceTracerDecorator::OnPropFloatChanged(float)
{
    m_tracer->capture_state(this);
}
void SimpleInterfaceTracerDecorator::OnPropStringChanged(std::string)
{
    m_tracer->capture_state(this);
}
