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


#include "testbed1/generated/core/structarrayinterface.decorator.h"
#include "testbed1/generated/core/structarrayinterface.publisher.h"

using namespace Test::Testbed1;
/**
   \brief 
*/
AbstractStructArrayInterfaceDecorator::AbstractStructArrayInterfaceDecorator(IStructArrayInterface* impl)
    : m_impl(impl)
{
    m_impl->_getPublisher().subscribeToAllChanges(*this);
}
IStructArrayInterface* AbstractStructArrayInterfaceDecorator::swapUnderlyingImplementation(IStructArrayInterface* impl)
{
    IStructArrayInterface* retVal = m_impl;
    if (m_impl != nullptr) {
        m_impl->_getPublisher().unsubscribeFromAllChanges(*this);
    }
    m_impl = impl;
    if (m_impl != nullptr) {
        m_impl->_getPublisher().subscribeToAllChanges(*this);
    }
    return retVal;
}
IStructArrayInterface* AbstractStructArrayInterfaceDecorator::disconnectFromUnderlyingImplementation()
{
    IStructArrayInterface* retVal = m_impl;
    if (m_impl != nullptr) {
        m_impl->_getPublisher().unsubscribeFromAllChanges(*this);
        m_impl = nullptr;
    }
    return retVal;
}
AbstractStructArrayInterfaceDecorator::~AbstractStructArrayInterfaceDecorator()
{
    if (m_impl != nullptr)
    {
        m_impl->_getPublisher().unsubscribeFromAllChanges(*this);
    }
}
void AbstractStructArrayInterfaceDecorator::setPropBool(const std::list<StructBool>& propBool)
{
    m_impl->setPropBool(propBool);
}

const std::list<StructBool>& AbstractStructArrayInterfaceDecorator::propBool() const
{
    return m_impl->propBool();
}
void AbstractStructArrayInterfaceDecorator::setPropInt(const std::list<StructInt>& propInt)
{
    m_impl->setPropInt(propInt);
}

const std::list<StructInt>& AbstractStructArrayInterfaceDecorator::propInt() const
{
    return m_impl->propInt();
}
void AbstractStructArrayInterfaceDecorator::setPropFloat(const std::list<StructFloat>& propFloat)
{
    m_impl->setPropFloat(propFloat);
}

const std::list<StructFloat>& AbstractStructArrayInterfaceDecorator::propFloat() const
{
    return m_impl->propFloat();
}
void AbstractStructArrayInterfaceDecorator::setPropString(const std::list<StructString>& propString)
{
    m_impl->setPropString(propString);
}

const std::list<StructString>& AbstractStructArrayInterfaceDecorator::propString() const
{
    return m_impl->propString();
}
/**
   \brief 
*/
StructBool AbstractStructArrayInterfaceDecorator::funcBool(const std::list<StructBool>& paramBool)
{
    return m_impl->funcBool(paramBool);
}
std::future<StructBool> AbstractStructArrayInterfaceDecorator::funcBoolAsync(const std::list<StructBool>& paramBool)
{
    return m_impl->funcBoolAsync(paramBool);
}
/**
   \brief 
*/
StructBool AbstractStructArrayInterfaceDecorator::funcInt(const std::list<StructInt>& paramInt)
{
    return m_impl->funcInt(paramInt);
}
std::future<StructBool> AbstractStructArrayInterfaceDecorator::funcIntAsync(const std::list<StructInt>& paramInt)
{
    return m_impl->funcIntAsync(paramInt);
}
/**
   \brief 
*/
StructBool AbstractStructArrayInterfaceDecorator::funcFloat(const std::list<StructFloat>& paramFloat)
{
    return m_impl->funcFloat(paramFloat);
}
std::future<StructBool> AbstractStructArrayInterfaceDecorator::funcFloatAsync(const std::list<StructFloat>& paramFloat)
{
    return m_impl->funcFloatAsync(paramFloat);
}
/**
   \brief 
*/
StructBool AbstractStructArrayInterfaceDecorator::funcString(const std::list<StructString>& paramString)
{
    return m_impl->funcString(paramString);
}
std::future<StructBool> AbstractStructArrayInterfaceDecorator::funcStringAsync(const std::list<StructString>& paramString)
{
    return m_impl->funcStringAsync(paramString);
}

IStructArrayInterfacePublisher& AbstractStructArrayInterfaceDecorator::_getPublisher() const
{
    return m_impl->_getPublisher();
}
