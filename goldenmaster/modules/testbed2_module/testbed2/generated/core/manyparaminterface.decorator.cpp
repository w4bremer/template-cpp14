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


#include "testbed2/generated/core/manyparaminterface.decorator.h"
#include "testbed2/generated/core/manyparaminterface.publisher.h"

using namespace Test::Testbed2;
/**
   \brief 
*/
AbstractManyParamInterfaceDecorator::AbstractManyParamInterfaceDecorator(IManyParamInterface* impl)
    : m_impl(impl)
{
    m_impl->_getPublisher().subscribeToAllChanges(*this);
}
IManyParamInterface* AbstractManyParamInterfaceDecorator::swapUnderlyingImplementation(IManyParamInterface* impl)
{
    IManyParamInterface* retVal = m_impl;
    if (m_impl != nullptr) {
        m_impl->_getPublisher().unsubscribeFromAllChanges(*this);
    }
    m_impl = impl;
    if (m_impl != nullptr) {
        m_impl->_getPublisher().subscribeToAllChanges(*this);
    }
    return retVal;
}
IManyParamInterface* AbstractManyParamInterfaceDecorator::disconnectFromUnderlyingImplementation()
{
    IManyParamInterface* retVal = m_impl;
    if (m_impl != nullptr) {
        m_impl->_getPublisher().unsubscribeFromAllChanges(*this);
        m_impl = nullptr;
    }
    return retVal;
}
AbstractManyParamInterfaceDecorator::~AbstractManyParamInterfaceDecorator()
{
    if (m_impl != nullptr)
    {
        m_impl->_getPublisher().unsubscribeFromAllChanges(*this);
    }
}
void AbstractManyParamInterfaceDecorator::setProp1(int prop1)
{
    m_impl->setProp1(prop1);
}

int AbstractManyParamInterfaceDecorator::prop1() const
{
    return m_impl->prop1();
}
void AbstractManyParamInterfaceDecorator::setProp2(int prop2)
{
    m_impl->setProp2(prop2);
}

int AbstractManyParamInterfaceDecorator::prop2() const
{
    return m_impl->prop2();
}
void AbstractManyParamInterfaceDecorator::setProp3(int prop3)
{
    m_impl->setProp3(prop3);
}

int AbstractManyParamInterfaceDecorator::prop3() const
{
    return m_impl->prop3();
}
void AbstractManyParamInterfaceDecorator::setProp4(int prop4)
{
    m_impl->setProp4(prop4);
}

int AbstractManyParamInterfaceDecorator::prop4() const
{
    return m_impl->prop4();
}
/**
   \brief 
*/
int AbstractManyParamInterfaceDecorator::func1(int param1)
{
    return m_impl->func1(param1);
}
std::future<int> AbstractManyParamInterfaceDecorator::func1Async(int param1)
{
    return m_impl->func1Async(param1);
}
/**
   \brief 
*/
int AbstractManyParamInterfaceDecorator::func2(int param1, int param2)
{
    return m_impl->func2(param1,param2);
}
std::future<int> AbstractManyParamInterfaceDecorator::func2Async(int param1, int param2)
{
    return m_impl->func2Async(param1,param2);
}
/**
   \brief 
*/
int AbstractManyParamInterfaceDecorator::func3(int param1, int param2, int param3)
{
    return m_impl->func3(param1,param2,param3);
}
std::future<int> AbstractManyParamInterfaceDecorator::func3Async(int param1, int param2, int param3)
{
    return m_impl->func3Async(param1,param2,param3);
}
/**
   \brief 
*/
int AbstractManyParamInterfaceDecorator::func4(int param1, int param2, int param3, int param4)
{
    return m_impl->func4(param1,param2,param3,param4);
}
std::future<int> AbstractManyParamInterfaceDecorator::func4Async(int param1, int param2, int param3, int param4)
{
    return m_impl->func4Async(param1,param2,param3,param4);
}

IManyParamInterfacePublisher& AbstractManyParamInterfaceDecorator::_getPublisher() const
{
    return m_impl->_getPublisher();
}
