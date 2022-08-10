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


#include "testbed2/generated/core/nestedstruct3interface.decorator.h"
#include "testbed2/generated/core/nestedstruct3interface.publisher.h"

using namespace Test::Testbed2;
/**
   \brief 
*/
AbstractNestedStruct3InterfaceDecorator::AbstractNestedStruct3InterfaceDecorator(INestedStruct3Interface* impl)
    : m_impl(impl)
{
    m_impl->_getPublisher().subscribeToAllChanges(*this);
}
INestedStruct3Interface* AbstractNestedStruct3InterfaceDecorator::swapUnderlyingImplementation(INestedStruct3Interface* impl)
{
    INestedStruct3Interface* retVal = m_impl;
    if (m_impl != nullptr) {
        m_impl->_getPublisher().unsubscribeFromAllChanges(*this);
    }
    m_impl = impl;
    if (m_impl != nullptr) {
        m_impl->_getPublisher().subscribeToAllChanges(*this);
    }
    return retVal;
}
INestedStruct3Interface* AbstractNestedStruct3InterfaceDecorator::disconnectFromUnderlyingImplementation()
{
    INestedStruct3Interface* retVal = m_impl;
    if (m_impl != nullptr) {
        m_impl->_getPublisher().unsubscribeFromAllChanges(*this);
        m_impl = nullptr;
    }
    return retVal;
}
AbstractNestedStruct3InterfaceDecorator::~AbstractNestedStruct3InterfaceDecorator()
{
    if (m_impl != nullptr)
    {
        m_impl->_getPublisher().unsubscribeFromAllChanges(*this);
    }
}
void AbstractNestedStruct3InterfaceDecorator::setProp1(const NestedStruct1& prop1)
{
    m_impl->setProp1(prop1);
}

const NestedStruct1& AbstractNestedStruct3InterfaceDecorator::prop1() const
{
    return m_impl->prop1();
}
void AbstractNestedStruct3InterfaceDecorator::setProp2(const NestedStruct2& prop2)
{
    m_impl->setProp2(prop2);
}

const NestedStruct2& AbstractNestedStruct3InterfaceDecorator::prop2() const
{
    return m_impl->prop2();
}
void AbstractNestedStruct3InterfaceDecorator::setProp3(const NestedStruct3& prop3)
{
    m_impl->setProp3(prop3);
}

const NestedStruct3& AbstractNestedStruct3InterfaceDecorator::prop3() const
{
    return m_impl->prop3();
}
/**
   \brief 
*/
NestedStruct1 AbstractNestedStruct3InterfaceDecorator::func1(const NestedStruct1& param1)
{
    return m_impl->func1(param1);
}
std::future<NestedStruct1> AbstractNestedStruct3InterfaceDecorator::func1Async(const NestedStruct1& param1)
{
    return m_impl->func1Async(param1);
}
/**
   \brief 
*/
NestedStruct1 AbstractNestedStruct3InterfaceDecorator::func2(const NestedStruct1& param1, const NestedStruct2& param2)
{
    return m_impl->func2(param1,param2);
}
std::future<NestedStruct1> AbstractNestedStruct3InterfaceDecorator::func2Async(const NestedStruct1& param1, const NestedStruct2& param2)
{
    return m_impl->func2Async(param1,param2);
}
/**
   \brief 
*/
NestedStruct1 AbstractNestedStruct3InterfaceDecorator::func3(const NestedStruct1& param1, const NestedStruct2& param2, const NestedStruct3& param3)
{
    return m_impl->func3(param1,param2,param3);
}
std::future<NestedStruct1> AbstractNestedStruct3InterfaceDecorator::func3Async(const NestedStruct1& param1, const NestedStruct2& param2, const NestedStruct3& param3)
{
    return m_impl->func3Async(param1,param2,param3);
}

INestedStruct3InterfacePublisher& AbstractNestedStruct3InterfaceDecorator::_getPublisher() const
{
    return m_impl->_getPublisher();
}
