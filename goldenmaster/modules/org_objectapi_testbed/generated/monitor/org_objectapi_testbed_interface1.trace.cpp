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


#include "org_objectapi_testbed_interface1.trace.h"
#include "org_objectapi_testbed.trace.h"

using namespace Test::OrgObjectapiTestbed;
Interface1TracerDecorator::Interface1TracerDecorator(IInterface1* impl, ApiGear::PocoImpl::Tracer* tracer)
    : AbstractInterface1Decorator(impl)
    , m_tracer(std::make_unique<Interface1Tracer>(tracer))
{
}
Interface1TracerDecorator::~Interface1TracerDecorator() = default;
Interface1TracerDecorator* Interface1TracerDecorator::connect(IInterface1* impl, ApiGear::PocoImpl::Tracer* tracer)
{
    return new Interface1TracerDecorator(impl, tracer);
}
/**
   \brief 
*/
void Interface1TracerDecorator::op1()
{
    m_tracer->trace_op1();
    return AbstractInterface1Decorator::op1();
}
std::future<void> Interface1TracerDecorator::op1Async()
{
    m_tracer->trace_op1();
    return AbstractInterface1Decorator::op1Async();
}
/**
   \brief 
*/
void Interface1TracerDecorator::op2(int step)
{
    m_tracer->trace_op2(step);
    return AbstractInterface1Decorator::op2(step);
}
std::future<void> Interface1TracerDecorator::op2Async(int step)
{
    m_tracer->trace_op2(step);
    return AbstractInterface1Decorator::op2Async(step);
}
/**
   \brief 
*/
int Interface1TracerDecorator::op3()
{
    m_tracer->trace_op3();
    return AbstractInterface1Decorator::op3();
}
std::future<int> Interface1TracerDecorator::op3Async()
{
    m_tracer->trace_op3();
    return AbstractInterface1Decorator::op3Async();
}
void Interface1TracerDecorator::OnSig1()
{
    //m_tracer->trace_Sig1();
}
void Interface1TracerDecorator::OnSig2(int step)
{
    (void) step;
    //m_tracer->trace_Sig2(step);
}
void Interface1TracerDecorator::OnSig3()
{
    //m_tracer->trace_Sig3();
}
void Interface1TracerDecorator::OnProp1Changed(bool)
{
    m_tracer->capture_state(this);
}
void Interface1TracerDecorator::OnProp2Changed(int)
{
    m_tracer->capture_state(this);
}
void Interface1TracerDecorator::OnProp3Changed(float)
{
    m_tracer->capture_state(this);
}
void Interface1TracerDecorator::OnProp4Changed(std::string)
{
    m_tracer->capture_state(this);
}
void Interface1TracerDecorator::OnProp5Changed(const std::list<int>&)
{
    m_tracer->capture_state(this);
}
void Interface1TracerDecorator::OnProp6Changed(const Struct1&)
{
    m_tracer->capture_state(this);
}
void Interface1TracerDecorator::OnProp7Changed(int)
{
    m_tracer->capture_state(this);
}
void Interface1TracerDecorator::OnProp10Changed(const std::list<int>&)
{
    m_tracer->capture_state(this);
}
void Interface1TracerDecorator::OnProp11Changed(const std::list<Struct1>&)
{
    m_tracer->capture_state(this);
}
void Interface1TracerDecorator::OnProp12Changed(const std::list<Enum1Enum>&)
{
    m_tracer->capture_state(this);
}
void Interface1TracerDecorator::OnProp14Changed(const std::list<Struct1>&)
{
    m_tracer->capture_state(this);
}
