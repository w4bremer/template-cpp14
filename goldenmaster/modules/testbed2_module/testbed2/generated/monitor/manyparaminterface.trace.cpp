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


#include "testbed2/generated/monitor/manyparaminterface.trace.h"
#include "testbed2/generated/monitor/manyparaminterface.tracer.h"

using namespace Test::Testbed2;
ManyParamInterfaceTracerDecorator::ManyParamInterfaceTracerDecorator(IManyParamInterface* impl, ApiGear::PocoImpl::Tracer& tracer)
    : AbstractManyParamInterfaceDecorator(impl)
    , m_tracer(std::make_unique<ManyParamInterfaceTracer>(tracer))
{
}
ManyParamInterfaceTracerDecorator::~ManyParamInterfaceTracerDecorator() = default;
ManyParamInterfaceTracerDecorator* ManyParamInterfaceTracerDecorator::connect(IManyParamInterface* impl, ApiGear::PocoImpl::Tracer& tracer)
{
    return new ManyParamInterfaceTracerDecorator(impl, tracer);
}
/**
   \brief 
*/
int ManyParamInterfaceTracerDecorator::func1(int param1)
{
    m_tracer->trace_func1(param1);
    return AbstractManyParamInterfaceDecorator::func1(param1);
}
std::future<int> ManyParamInterfaceTracerDecorator::func1Async(int param1)
{
    m_tracer->trace_func1(param1);
    return AbstractManyParamInterfaceDecorator::func1Async(param1);
}
/**
   \brief 
*/
int ManyParamInterfaceTracerDecorator::func2(int param1, int param2)
{
    m_tracer->trace_func2(param1,param2);
    return AbstractManyParamInterfaceDecorator::func2(param1,param2);
}
std::future<int> ManyParamInterfaceTracerDecorator::func2Async(int param1, int param2)
{
    m_tracer->trace_func2(param1,param2);
    return AbstractManyParamInterfaceDecorator::func2Async(param1,param2);
}
/**
   \brief 
*/
int ManyParamInterfaceTracerDecorator::func3(int param1, int param2, int param3)
{
    m_tracer->trace_func3(param1,param2,param3);
    return AbstractManyParamInterfaceDecorator::func3(param1,param2,param3);
}
std::future<int> ManyParamInterfaceTracerDecorator::func3Async(int param1, int param2, int param3)
{
    m_tracer->trace_func3(param1,param2,param3);
    return AbstractManyParamInterfaceDecorator::func3Async(param1,param2,param3);
}
/**
   \brief 
*/
int ManyParamInterfaceTracerDecorator::func4(int param1, int param2, int param3, int param4)
{
    m_tracer->trace_func4(param1,param2,param3,param4);
    return AbstractManyParamInterfaceDecorator::func4(param1,param2,param3,param4);
}
std::future<int> ManyParamInterfaceTracerDecorator::func4Async(int param1, int param2, int param3, int param4)
{
    m_tracer->trace_func4(param1,param2,param3,param4);
    return AbstractManyParamInterfaceDecorator::func4Async(param1,param2,param3,param4);
}
void ManyParamInterfaceTracerDecorator::onSig1(int param1)
{
    (void) param1;
    //m_tracer->trace_Sig1(param1);
}
void ManyParamInterfaceTracerDecorator::onSig2(int param1,int param2)
{
    (void) param1;
    (void) param2;
    //m_tracer->trace_Sig2(param1,param2);
}
void ManyParamInterfaceTracerDecorator::onSig3(int param1,int param2,int param3)
{
    (void) param1;
    (void) param2;
    (void) param3;
    //m_tracer->trace_Sig3(param1,param2,param3);
}
void ManyParamInterfaceTracerDecorator::onSig4(int param1,int param2,int param3,int param4)
{
    (void) param1;
    (void) param2;
    (void) param3;
    (void) param4;
    //m_tracer->trace_Sig4(param1,param2,param3,param4);
}
void ManyParamInterfaceTracerDecorator::onProp1Changed(int)
{
    m_tracer->capture_state(this);
}
void ManyParamInterfaceTracerDecorator::onProp2Changed(int)
{
    m_tracer->capture_state(this);
}
void ManyParamInterfaceTracerDecorator::onProp3Changed(int)
{
    m_tracer->capture_state(this);
}
void ManyParamInterfaceTracerDecorator::onProp4Changed(int)
{
    m_tracer->capture_state(this);
}
