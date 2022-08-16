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


#include "testbed1/generated/monitor/structarrayinterface.tracedecorator.h"
#include "testbed1/generated/monitor/structarrayinterface.tracer.h"

using namespace Test::Testbed1;
StructArrayInterfaceTraceDecorator::StructArrayInterfaceTraceDecorator(IStructArrayInterface& impl, ApiGear::PocoImpl::Tracer& tracer)
    : m_tracer(std::make_unique<StructArrayInterfaceTracer>(tracer))
    , m_impl(impl)
{
        m_impl._getPublisher().subscribeToAllChanges(*this);
}
StructArrayInterfaceTraceDecorator::~StructArrayInterfaceTraceDecorator()
{
    m_impl._getPublisher().unsubscribeFromAllChanges(*this);
}

std::unique_ptr<StructArrayInterfaceTraceDecorator> StructArrayInterfaceTraceDecorator::connect(IStructArrayInterface& impl, ApiGear::PocoImpl::Tracer& tracer)
{
    return std::unique_ptr<StructArrayInterfaceTraceDecorator>(new StructArrayInterfaceTraceDecorator(impl, tracer));
}
StructBool StructArrayInterfaceTraceDecorator::funcBool(const std::list<StructBool>& paramBool)
{
    m_tracer->trace_funcBool(paramBool);
    return m_impl.funcBool(paramBool);
}
std::future<StructBool> StructArrayInterfaceTraceDecorator::funcBoolAsync(const std::list<StructBool>& paramBool)
{
    m_tracer->trace_funcBool(paramBool);
    return m_impl.funcBoolAsync(paramBool);
}
StructBool StructArrayInterfaceTraceDecorator::funcInt(const std::list<StructInt>& paramInt)
{
    m_tracer->trace_funcInt(paramInt);
    return m_impl.funcInt(paramInt);
}
std::future<StructBool> StructArrayInterfaceTraceDecorator::funcIntAsync(const std::list<StructInt>& paramInt)
{
    m_tracer->trace_funcInt(paramInt);
    return m_impl.funcIntAsync(paramInt);
}
StructBool StructArrayInterfaceTraceDecorator::funcFloat(const std::list<StructFloat>& paramFloat)
{
    m_tracer->trace_funcFloat(paramFloat);
    return m_impl.funcFloat(paramFloat);
}
std::future<StructBool> StructArrayInterfaceTraceDecorator::funcFloatAsync(const std::list<StructFloat>& paramFloat)
{
    m_tracer->trace_funcFloat(paramFloat);
    return m_impl.funcFloatAsync(paramFloat);
}
StructBool StructArrayInterfaceTraceDecorator::funcString(const std::list<StructString>& paramString)
{
    m_tracer->trace_funcString(paramString);
    return m_impl.funcString(paramString);
}
std::future<StructBool> StructArrayInterfaceTraceDecorator::funcStringAsync(const std::list<StructString>& paramString)
{
    m_tracer->trace_funcString(paramString);
    return m_impl.funcStringAsync(paramString);
}
void StructArrayInterfaceTraceDecorator::setPropBool(const std::list<StructBool>& propBool)
{
    m_impl.setPropBool(propBool);
}

const std::list<StructBool>& StructArrayInterfaceTraceDecorator::propBool() const
{
    return m_impl.propBool();
}
void StructArrayInterfaceTraceDecorator::setPropInt(const std::list<StructInt>& propInt)
{
    m_impl.setPropInt(propInt);
}

const std::list<StructInt>& StructArrayInterfaceTraceDecorator::propInt() const
{
    return m_impl.propInt();
}
void StructArrayInterfaceTraceDecorator::setPropFloat(const std::list<StructFloat>& propFloat)
{
    m_impl.setPropFloat(propFloat);
}

const std::list<StructFloat>& StructArrayInterfaceTraceDecorator::propFloat() const
{
    return m_impl.propFloat();
}
void StructArrayInterfaceTraceDecorator::setPropString(const std::list<StructString>& propString)
{
    m_impl.setPropString(propString);
}

const std::list<StructString>& StructArrayInterfaceTraceDecorator::propString() const
{
    return m_impl.propString();
}
void StructArrayInterfaceTraceDecorator::onSigBool(const std::list<StructBool>& paramBool)
{
    m_tracer->trace_sigBool(paramBool);
}

void StructArrayInterfaceTraceDecorator::onSigInt(const std::list<StructInt>& paramInt)
{
    m_tracer->trace_sigInt(paramInt);
}

void StructArrayInterfaceTraceDecorator::onSigFloat(const std::list<StructFloat>& paramFloat)
{
    m_tracer->trace_sigFloat(paramFloat);
}

void StructArrayInterfaceTraceDecorator::onSigString(const std::list<StructString>& paramString)
{
    m_tracer->trace_sigString(paramString);
}

void StructArrayInterfaceTraceDecorator::onPropBoolChanged(const std::list<StructBool>& /*propBool*/)
{
    m_tracer->capture_state(this);
}

void StructArrayInterfaceTraceDecorator::onPropIntChanged(const std::list<StructInt>& /*propInt*/)
{
    m_tracer->capture_state(this);
}

void StructArrayInterfaceTraceDecorator::onPropFloatChanged(const std::list<StructFloat>& /*propFloat*/)
{
    m_tracer->capture_state(this);
}

void StructArrayInterfaceTraceDecorator::onPropStringChanged(const std::list<StructString>& /*propString*/)
{
    m_tracer->capture_state(this);
}



IStructArrayInterfacePublisher& StructArrayInterfaceTraceDecorator::_getPublisher() const
{
    return m_impl._getPublisher();
}