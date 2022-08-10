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


#include "tb_same2/generated/core/sameenum2interface.decorator.h"
#include "tb_same2/generated/core/sameenum2interface.publisher.h"

using namespace Test::TbSame2;
/**
   \brief 
*/
AbstractSameEnum2InterfaceDecorator::AbstractSameEnum2InterfaceDecorator(ISameEnum2Interface* impl)
    : m_impl(impl)
{
    m_impl->_getPublisher().subscribeToAllChanges(*this);
}
ISameEnum2Interface* AbstractSameEnum2InterfaceDecorator::swapUnderlyingImplementation(ISameEnum2Interface* impl)
{
    ISameEnum2Interface* retVal = m_impl;
    if (m_impl != nullptr) {
        m_impl->_getPublisher().unsubscribeFromAllChanges(*this);
    }
    m_impl = impl;
    if (m_impl != nullptr) {
        m_impl->_getPublisher().subscribeToAllChanges(*this);
    }
    return retVal;
}
ISameEnum2Interface* AbstractSameEnum2InterfaceDecorator::disconnectFromUnderlyingImplementation()
{
    ISameEnum2Interface* retVal = m_impl;
    if (m_impl != nullptr) {
        m_impl->_getPublisher().unsubscribeFromAllChanges(*this);
        m_impl = nullptr;
    }
    return retVal;
}
AbstractSameEnum2InterfaceDecorator::~AbstractSameEnum2InterfaceDecorator()
{
    if (m_impl != nullptr)
    {
        m_impl->_getPublisher().unsubscribeFromAllChanges(*this);
    }
}
void AbstractSameEnum2InterfaceDecorator::setProp1(const Enum1Enum& prop1)
{
    m_impl->setProp1(prop1);
}

const Enum1Enum& AbstractSameEnum2InterfaceDecorator::prop1() const
{
    return m_impl->prop1();
}
void AbstractSameEnum2InterfaceDecorator::setProp2(const Enum2Enum& prop2)
{
    m_impl->setProp2(prop2);
}

const Enum2Enum& AbstractSameEnum2InterfaceDecorator::prop2() const
{
    return m_impl->prop2();
}
/**
   \brief 
*/
Enum1Enum AbstractSameEnum2InterfaceDecorator::func1(const Enum1Enum& param1)
{
    return m_impl->func1(param1);
}
std::future<Enum1Enum> AbstractSameEnum2InterfaceDecorator::func1Async(const Enum1Enum& param1)
{
    return m_impl->func1Async(param1);
}
/**
   \brief 
*/
Enum1Enum AbstractSameEnum2InterfaceDecorator::func2(const Enum1Enum& param1, const Enum2Enum& param2)
{
    return m_impl->func2(param1,param2);
}
std::future<Enum1Enum> AbstractSameEnum2InterfaceDecorator::func2Async(const Enum1Enum& param1, const Enum2Enum& param2)
{
    return m_impl->func2Async(param1,param2);
}

ISameEnum2InterfacePublisher& AbstractSameEnum2InterfaceDecorator::_getPublisher() const
{
    return m_impl->_getPublisher();
}
