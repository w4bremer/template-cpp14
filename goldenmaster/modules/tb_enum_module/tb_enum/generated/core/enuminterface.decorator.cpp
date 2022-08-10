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


#include "tb_enum/generated/core/enuminterface.decorator.h"
#include "tb_enum/generated/core/enuminterface.publisher.h"

using namespace Test::TbEnum;
/**
   \brief 
*/
AbstractEnumInterfaceDecorator::AbstractEnumInterfaceDecorator(IEnumInterface* impl)
    : m_impl(impl)
{
    m_impl->_getPublisher().subscribeToAllChanges(*this);
}
IEnumInterface* AbstractEnumInterfaceDecorator::swapUnderlyingImplementation(IEnumInterface* impl)
{
    IEnumInterface* retVal = m_impl;
    if (m_impl != nullptr) {
        m_impl->_getPublisher().unsubscribeFromAllChanges(*this);
    }
    m_impl = impl;
    if (m_impl != nullptr) {
        m_impl->_getPublisher().subscribeToAllChanges(*this);
    }
    return retVal;
}
IEnumInterface* AbstractEnumInterfaceDecorator::disconnectFromUnderlyingImplementation()
{
    IEnumInterface* retVal = m_impl;
    if (m_impl != nullptr) {
        m_impl->_getPublisher().unsubscribeFromAllChanges(*this);
        m_impl = nullptr;
    }
    return retVal;
}
AbstractEnumInterfaceDecorator::~AbstractEnumInterfaceDecorator()
{
    if (m_impl != nullptr)
    {
        m_impl->_getPublisher().unsubscribeFromAllChanges(*this);
    }
}
void AbstractEnumInterfaceDecorator::setProp0(const Enum0Enum& prop0)
{
    m_impl->setProp0(prop0);
}

const Enum0Enum& AbstractEnumInterfaceDecorator::prop0() const
{
    return m_impl->prop0();
}
void AbstractEnumInterfaceDecorator::setProp1(const Enum1Enum& prop1)
{
    m_impl->setProp1(prop1);
}

const Enum1Enum& AbstractEnumInterfaceDecorator::prop1() const
{
    return m_impl->prop1();
}
void AbstractEnumInterfaceDecorator::setProp2(const Enum2Enum& prop2)
{
    m_impl->setProp2(prop2);
}

const Enum2Enum& AbstractEnumInterfaceDecorator::prop2() const
{
    return m_impl->prop2();
}
void AbstractEnumInterfaceDecorator::setProp3(const Enum3Enum& prop3)
{
    m_impl->setProp3(prop3);
}

const Enum3Enum& AbstractEnumInterfaceDecorator::prop3() const
{
    return m_impl->prop3();
}
/**
   \brief 
*/
Enum0Enum AbstractEnumInterfaceDecorator::func0(const Enum0Enum& param0)
{
    return m_impl->func0(param0);
}
std::future<Enum0Enum> AbstractEnumInterfaceDecorator::func0Async(const Enum0Enum& param0)
{
    return m_impl->func0Async(param0);
}
/**
   \brief 
*/
Enum1Enum AbstractEnumInterfaceDecorator::func1(const Enum1Enum& param1)
{
    return m_impl->func1(param1);
}
std::future<Enum1Enum> AbstractEnumInterfaceDecorator::func1Async(const Enum1Enum& param1)
{
    return m_impl->func1Async(param1);
}
/**
   \brief 
*/
Enum2Enum AbstractEnumInterfaceDecorator::func2(const Enum2Enum& param2)
{
    return m_impl->func2(param2);
}
std::future<Enum2Enum> AbstractEnumInterfaceDecorator::func2Async(const Enum2Enum& param2)
{
    return m_impl->func2Async(param2);
}
/**
   \brief 
*/
Enum3Enum AbstractEnumInterfaceDecorator::func3(const Enum3Enum& param3)
{
    return m_impl->func3(param3);
}
std::future<Enum3Enum> AbstractEnumInterfaceDecorator::func3Async(const Enum3Enum& param3)
{
    return m_impl->func3Async(param3);
}

IEnumInterfacePublisher& AbstractEnumInterfaceDecorator::_getPublisher() const
{
    return m_impl->_getPublisher();
}
