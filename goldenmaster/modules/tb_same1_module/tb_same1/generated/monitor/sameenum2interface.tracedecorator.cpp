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


#include "tb_same1/generated/monitor/sameenum2interface.tracedecorator.h"
#include "tb_same1/generated/monitor/sameenum2interface.tracer.h"

using namespace Test::TbSame1;
SameEnum2InterfaceTraceDecorator::SameEnum2InterfaceTraceDecorator(ISameEnum2Interface& impl, ApiGear::PocoImpl::Tracer& tracer)
    : m_tracer(std::make_unique<SameEnum2InterfaceTracer>(tracer))
    , m_impl(impl)
{
        m_impl._getPublisher().subscribeToAllChanges(*this);
}
SameEnum2InterfaceTraceDecorator::~SameEnum2InterfaceTraceDecorator()
{
    m_impl._getPublisher().unsubscribeFromAllChanges(*this);
}

std::unique_ptr<SameEnum2InterfaceTraceDecorator> SameEnum2InterfaceTraceDecorator::connect(ISameEnum2Interface& impl, ApiGear::PocoImpl::Tracer& tracer)
{
    return std::unique_ptr<SameEnum2InterfaceTraceDecorator>(new SameEnum2InterfaceTraceDecorator(impl, tracer));
}
Enum1Enum SameEnum2InterfaceTraceDecorator::func1(const Enum1Enum& param1)
{
    m_tracer->trace_func1(param1);
    return m_impl.func1(param1);
}
std::future<Enum1Enum> SameEnum2InterfaceTraceDecorator::func1Async(const Enum1Enum& param1)
{
    m_tracer->trace_func1(param1);
    return m_impl.func1Async(param1);
}
Enum1Enum SameEnum2InterfaceTraceDecorator::func2(const Enum1Enum& param1, const Enum2Enum& param2)
{
    m_tracer->trace_func2(param1,param2);
    return m_impl.func2(param1,param2);
}
std::future<Enum1Enum> SameEnum2InterfaceTraceDecorator::func2Async(const Enum1Enum& param1, const Enum2Enum& param2)
{
    m_tracer->trace_func2(param1,param2);
    return m_impl.func2Async(param1,param2);
}
void SameEnum2InterfaceTraceDecorator::setProp1(const Enum1Enum& prop1)
{
    m_impl.setProp1(prop1);
}

const Enum1Enum& SameEnum2InterfaceTraceDecorator::prop1() const
{
    return m_impl.prop1();
}
void SameEnum2InterfaceTraceDecorator::setProp2(const Enum2Enum& prop2)
{
    m_impl.setProp2(prop2);
}

const Enum2Enum& SameEnum2InterfaceTraceDecorator::prop2() const
{
    return m_impl.prop2();
}
void SameEnum2InterfaceTraceDecorator::onSig1(const Enum1Enum& param1)
{
    m_tracer->trace_sig1(param1);
}

void SameEnum2InterfaceTraceDecorator::onSig2(const Enum1Enum& param1,const Enum2Enum& param2)
{
    m_tracer->trace_sig2(param1,param2);
}

void SameEnum2InterfaceTraceDecorator::onProp1Changed(const Enum1Enum& /*prop1*/)
{
    m_tracer->capture_state(this);
}

void SameEnum2InterfaceTraceDecorator::onProp2Changed(const Enum2Enum& /*prop2*/)
{
    m_tracer->capture_state(this);
}



ISameEnum2InterfacePublisher& SameEnum2InterfaceTraceDecorator::_getPublisher() const
{
    return m_impl._getPublisher();
}