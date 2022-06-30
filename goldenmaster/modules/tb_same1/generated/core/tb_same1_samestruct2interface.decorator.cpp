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


#include "tb_same1_samestruct2interface.decorator.h"

using namespace Test::TbSame1;
/**
   \brief 
*/
AbstractSameStruct2InterfaceDecorator::AbstractSameStruct2InterfaceDecorator(ISameStruct2Interface* impl)
    : m_impl(impl)
{
    m_impl->_getPublisher()->subscribeToSameStruct2InterfaceInterface(*this);
}
ISameStruct2Interface* AbstractSameStruct2InterfaceDecorator::swapUnderlyingImplementation(ISameStruct2Interface* impl)
{
    ISameStruct2Interface* retVal = m_impl;
    if (m_impl != nullptr) {
        m_impl->_getPublisher()->unsubscribeFromSameStruct2InterfaceInterface(*this);
    }
    m_impl = impl;
    if (m_impl != nullptr) {
        m_impl->_getPublisher()->subscribeToSameStruct2InterfaceInterface(*this);
    }
    return retVal;
}
ISameStruct2Interface* AbstractSameStruct2InterfaceDecorator::disconnectFromUnderlyingImplementation()
{
    ISameStruct2Interface* retVal = m_impl;
    if (m_impl != nullptr) {
        m_impl->_getPublisher()->unsubscribeFromSameStruct2InterfaceInterface(*this);
        m_impl = nullptr;
    }
    return retVal;
}
AbstractSameStruct2InterfaceDecorator::~AbstractSameStruct2InterfaceDecorator()
{
    if (m_impl != nullptr)
    {
        m_impl->_getPublisher()->unsubscribeFromSameStruct2InterfaceInterface(*this);
    }
}
void AbstractSameStruct2InterfaceDecorator::setProp1(const Struct2& prop1)
{
    m_impl->setProp1(prop1);
}

const Struct2& AbstractSameStruct2InterfaceDecorator::prop1() const
{
    return m_impl->prop1();
}
void AbstractSameStruct2InterfaceDecorator::setProp2(const Struct2& prop2)
{
    m_impl->setProp2(prop2);
}

const Struct2& AbstractSameStruct2InterfaceDecorator::prop2() const
{
    return m_impl->prop2();
}
/**
   \brief 
*/
Struct1 AbstractSameStruct2InterfaceDecorator::func1(const Struct1& param1)
{
    return m_impl->func1(param1);
}
std::future<Struct1> AbstractSameStruct2InterfaceDecorator::func1Async(const Struct1& param1)
{
    return m_impl->func1Async(param1);
}
/**
   \brief 
*/
Struct1 AbstractSameStruct2InterfaceDecorator::func2(const Struct1& param1, const Struct2& param2)
{
    return m_impl->func2(param1,param2);
}
std::future<Struct1> AbstractSameStruct2InterfaceDecorator::func2Async(const Struct1& param1, const Struct2& param2)
{
    return m_impl->func2Async(param1,param2);
}

ISameStruct2InterfacePublisher* AbstractSameStruct2InterfaceDecorator::_getPublisher() const
{
    return m_impl->_getPublisher();
}
