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


#include "testbed2/generated/core/nestedstruct2interface.decorator.h"

using namespace Test::Testbed2;
/**
   \brief 
*/
AbstractNestedStruct2InterfaceDecorator::AbstractNestedStruct2InterfaceDecorator(INestedStruct2Interface* impl)
    : m_impl(impl)
{
    m_impl->_getPublisher()->subscribeToNestedStruct2InterfaceInterface(*this);
}
INestedStruct2Interface* AbstractNestedStruct2InterfaceDecorator::swapUnderlyingImplementation(INestedStruct2Interface* impl)
{
    INestedStruct2Interface* retVal = m_impl;
    if (m_impl != nullptr) {
        m_impl->_getPublisher()->unsubscribeFromNestedStruct2InterfaceInterface(*this);
    }
    m_impl = impl;
    if (m_impl != nullptr) {
        m_impl->_getPublisher()->subscribeToNestedStruct2InterfaceInterface(*this);
    }
    return retVal;
}
INestedStruct2Interface* AbstractNestedStruct2InterfaceDecorator::disconnectFromUnderlyingImplementation()
{
    INestedStruct2Interface* retVal = m_impl;
    if (m_impl != nullptr) {
        m_impl->_getPublisher()->unsubscribeFromNestedStruct2InterfaceInterface(*this);
        m_impl = nullptr;
    }
    return retVal;
}
AbstractNestedStruct2InterfaceDecorator::~AbstractNestedStruct2InterfaceDecorator()
{
    if (m_impl != nullptr)
    {
        m_impl->_getPublisher()->unsubscribeFromNestedStruct2InterfaceInterface(*this);
    }
}
void AbstractNestedStruct2InterfaceDecorator::setProp1(const NestedStruct1& prop1)
{
    m_impl->setProp1(prop1);
}

const NestedStruct1& AbstractNestedStruct2InterfaceDecorator::prop1() const
{
    return m_impl->prop1();
}
void AbstractNestedStruct2InterfaceDecorator::setProp2(const NestedStruct2& prop2)
{
    m_impl->setProp2(prop2);
}

const NestedStruct2& AbstractNestedStruct2InterfaceDecorator::prop2() const
{
    return m_impl->prop2();
}
/**
   \brief 
*/
NestedStruct1 AbstractNestedStruct2InterfaceDecorator::func1(const NestedStruct1& param1)
{
    return m_impl->func1(param1);
}
std::future<NestedStruct1> AbstractNestedStruct2InterfaceDecorator::func1Async(const NestedStruct1& param1)
{
    return m_impl->func1Async(param1);
}
/**
   \brief 
*/
NestedStruct1 AbstractNestedStruct2InterfaceDecorator::func2(const NestedStruct1& param1, const NestedStruct2& param2)
{
    return m_impl->func2(param1,param2);
}
std::future<NestedStruct1> AbstractNestedStruct2InterfaceDecorator::func2Async(const NestedStruct1& param1, const NestedStruct2& param2)
{
    return m_impl->func2Async(param1,param2);
}

INestedStruct2InterfacePublisher* AbstractNestedStruct2InterfaceDecorator::_getPublisher() const
{
    return m_impl->_getPublisher();
}
