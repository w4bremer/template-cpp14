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


#include "testbed2/generated/core/nestedstruct1interface.decorator.h"
#include "testbed2/generated/core/nestedstruct1interface.publisher.h"

using namespace Test::Testbed2;
/**
   \brief 
*/
AbstractNestedStruct1InterfaceDecorator::AbstractNestedStruct1InterfaceDecorator(INestedStruct1Interface* impl)
    : m_impl(impl)
{
    m_impl->_getPublisher().subscribeToAllChanges(*this);
}
INestedStruct1Interface* AbstractNestedStruct1InterfaceDecorator::swapUnderlyingImplementation(INestedStruct1Interface* impl)
{
    INestedStruct1Interface* retVal = m_impl;
    if (m_impl != nullptr) {
        m_impl->_getPublisher().unsubscribeFromAllChanges(*this);
    }
    m_impl = impl;
    if (m_impl != nullptr) {
        m_impl->_getPublisher().subscribeToAllChanges(*this);
    }
    return retVal;
}
INestedStruct1Interface* AbstractNestedStruct1InterfaceDecorator::disconnectFromUnderlyingImplementation()
{
    INestedStruct1Interface* retVal = m_impl;
    if (m_impl != nullptr) {
        m_impl->_getPublisher().unsubscribeFromAllChanges(*this);
        m_impl = nullptr;
    }
    return retVal;
}
AbstractNestedStruct1InterfaceDecorator::~AbstractNestedStruct1InterfaceDecorator()
{
    if (m_impl != nullptr)
    {
        m_impl->_getPublisher().unsubscribeFromAllChanges(*this);
    }
}
void AbstractNestedStruct1InterfaceDecorator::setProp1(const NestedStruct1& prop1)
{
    m_impl->setProp1(prop1);
}

const NestedStruct1& AbstractNestedStruct1InterfaceDecorator::prop1() const
{
    return m_impl->prop1();
}
/**
   \brief 
*/
NestedStruct1 AbstractNestedStruct1InterfaceDecorator::func1(const NestedStruct1& param1)
{
    return m_impl->func1(param1);
}
std::future<NestedStruct1> AbstractNestedStruct1InterfaceDecorator::func1Async(const NestedStruct1& param1)
{
    return m_impl->func1Async(param1);
}

INestedStruct1InterfacePublisher& AbstractNestedStruct1InterfaceDecorator::_getPublisher() const
{
    return m_impl->_getPublisher();
}
