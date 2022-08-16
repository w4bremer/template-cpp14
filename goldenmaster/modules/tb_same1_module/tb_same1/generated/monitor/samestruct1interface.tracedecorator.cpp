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


#include "tb_same1/generated/monitor/samestruct1interface.tracedecorator.h"
#include "tb_same1/generated/monitor/samestruct1interface.tracer.h"

using namespace Test::TbSame1;
SameStruct1InterfaceTraceDecorator::SameStruct1InterfaceTraceDecorator(ISameStruct1Interface& impl, ApiGear::PocoImpl::Tracer& tracer)
    : m_tracer(std::make_unique<SameStruct1InterfaceTracer>(tracer))
    , m_impl(impl)
{
        m_impl._getPublisher().subscribeToAllChanges(*this);
}
SameStruct1InterfaceTraceDecorator::~SameStruct1InterfaceTraceDecorator()
{
    m_impl._getPublisher().unsubscribeFromAllChanges(*this);
}

std::unique_ptr<SameStruct1InterfaceTraceDecorator> SameStruct1InterfaceTraceDecorator::connect(ISameStruct1Interface& impl, ApiGear::PocoImpl::Tracer& tracer)
{
    return std::unique_ptr<SameStruct1InterfaceTraceDecorator>(new SameStruct1InterfaceTraceDecorator(impl, tracer));
}
Struct1 SameStruct1InterfaceTraceDecorator::func1(const Struct1& param1)
{
    m_tracer->trace_func1(param1);
    return m_impl.func1(param1);
}
std::future<Struct1> SameStruct1InterfaceTraceDecorator::func1Async(const Struct1& param1)
{
    m_tracer->trace_func1(param1);
    return m_impl.func1Async(param1);
}
void SameStruct1InterfaceTraceDecorator::setProp1(const Struct1& prop1)
{
    m_impl.setProp1(prop1);
}

const Struct1& SameStruct1InterfaceTraceDecorator::prop1() const
{
    return m_impl.prop1();
}
void SameStruct1InterfaceTraceDecorator::onSig1(const Struct1& param1)
{
    m_tracer->trace_sig1(param1);
}

void SameStruct1InterfaceTraceDecorator::onProp1Changed(const Struct1& /*prop1*/)
{
    m_tracer->capture_state(this);
}



ISameStruct1InterfacePublisher& SameStruct1InterfaceTraceDecorator::_getPublisher() const
{
    return m_impl._getPublisher();
}