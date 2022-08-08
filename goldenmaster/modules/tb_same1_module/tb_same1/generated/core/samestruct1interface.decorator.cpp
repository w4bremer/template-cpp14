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


#include "tb_same1/generated/core/samestruct1interface.decorator.h"

using namespace Test::TbSame1;
/**
   \brief 
*/
AbstractSameStruct1InterfaceDecorator::AbstractSameStruct1InterfaceDecorator(ISameStruct1Interface* impl)
    : m_impl(impl)
{
    m_impl->_getPublisher()->subscribeToSameStruct1InterfaceInterface(*this);
}
ISameStruct1Interface* AbstractSameStruct1InterfaceDecorator::swapUnderlyingImplementation(ISameStruct1Interface* impl)
{
    ISameStruct1Interface* retVal = m_impl;
    if (m_impl != nullptr) {
        m_impl->_getPublisher()->unsubscribeFromSameStruct1InterfaceInterface(*this);
    }
    m_impl = impl;
    if (m_impl != nullptr) {
        m_impl->_getPublisher()->subscribeToSameStruct1InterfaceInterface(*this);
    }
    return retVal;
}
ISameStruct1Interface* AbstractSameStruct1InterfaceDecorator::disconnectFromUnderlyingImplementation()
{
    ISameStruct1Interface* retVal = m_impl;
    if (m_impl != nullptr) {
        m_impl->_getPublisher()->unsubscribeFromSameStruct1InterfaceInterface(*this);
        m_impl = nullptr;
    }
    return retVal;
}
AbstractSameStruct1InterfaceDecorator::~AbstractSameStruct1InterfaceDecorator()
{
    if (m_impl != nullptr)
    {
        m_impl->_getPublisher()->unsubscribeFromSameStruct1InterfaceInterface(*this);
    }
}
void AbstractSameStruct1InterfaceDecorator::setProp1(const Struct1& prop1)
{
    m_impl->setProp1(prop1);
}

const Struct1& AbstractSameStruct1InterfaceDecorator::prop1() const
{
    return m_impl->prop1();
}
/**
   \brief 
*/
Struct1 AbstractSameStruct1InterfaceDecorator::func1(const Struct1& param1)
{
    return m_impl->func1(param1);
}
std::future<Struct1> AbstractSameStruct1InterfaceDecorator::func1Async(const Struct1& param1)
{
    return m_impl->func1Async(param1);
}

ISameStruct1InterfacePublisher* AbstractSameStruct1InterfaceDecorator::_getPublisher() const
{
    return m_impl->_getPublisher();
}
