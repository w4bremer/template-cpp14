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


#include "testbed2/generated/monitor/nestedstruct1interface.tracedecorator.h"
#include "testbed2/generated/monitor/nestedstruct1interface.tracer.h"

using namespace Test::Testbed2;
NestedStruct1InterfaceTraceDecorator::NestedStruct1InterfaceTraceDecorator(INestedStruct1Interface& impl, ApiGear::PocoImpl::Tracer& tracer)
    : m_tracer(std::make_unique<NestedStruct1InterfaceTracer>(tracer))
    , m_impl(impl)
{
        m_impl._getPublisher().subscribeToAllChanges(*this);
}
NestedStruct1InterfaceTraceDecorator::~NestedStruct1InterfaceTraceDecorator()
{
    m_impl._getPublisher().unsubscribeFromAllChanges(*this);
}

std::unique_ptr<NestedStruct1InterfaceTraceDecorator> NestedStruct1InterfaceTraceDecorator::connect(INestedStruct1Interface& impl, ApiGear::PocoImpl::Tracer& tracer)
{
    return std::unique_ptr<NestedStruct1InterfaceTraceDecorator>(new NestedStruct1InterfaceTraceDecorator(impl, tracer));
}
NestedStruct1 NestedStruct1InterfaceTraceDecorator::func1(const NestedStruct1& param1)
{
    m_tracer->trace_func1(param1);
    return m_impl.func1(param1);
}
std::future<NestedStruct1> NestedStruct1InterfaceTraceDecorator::func1Async(const NestedStruct1& param1)
{
    m_tracer->trace_func1(param1);
    return m_impl.func1Async(param1);
}
void NestedStruct1InterfaceTraceDecorator::setProp1(const NestedStruct1& prop1)
{
    m_impl.setProp1(prop1);
}

const NestedStruct1& NestedStruct1InterfaceTraceDecorator::prop1() const
{
    return m_impl.prop1();
}
void NestedStruct1InterfaceTraceDecorator::onSig1(const NestedStruct1& param1)
{
    m_tracer->trace_sig1(param1);
}

void NestedStruct1InterfaceTraceDecorator::onProp1Changed(const NestedStruct1& /*prop1*/)
{
    m_tracer->capture_state(this);
}



INestedStruct1InterfacePublisher& NestedStruct1InterfaceTraceDecorator::_getPublisher() const
{
    return m_impl._getPublisher();
}