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


#include "testbed1_structinterface.decorator.h"

using namespace Test::Testbed1;
/**
   \brief 
*/
AbstractStructInterfaceDecorator::AbstractStructInterfaceDecorator(IStructInterface* impl)
    : m_impl(impl)
{
    m_impl->_getPublisher()->subscribeToStructInterfaceInterface(*this);
}
IStructInterface* AbstractStructInterfaceDecorator::swapUnderlyingImplementation(IStructInterface* impl)
{
    IStructInterface* retVal = m_impl;
    if (m_impl != nullptr) {
        m_impl->_getPublisher()->unsubscribeFromStructInterfaceInterface(*this);
    }
    m_impl = impl;
    if (m_impl != nullptr) {
        m_impl->_getPublisher()->subscribeToStructInterfaceInterface(*this);
    }
    return retVal;
}
IStructInterface* AbstractStructInterfaceDecorator::disconnectFromUnderlyingImplementation()
{
    IStructInterface* retVal = m_impl;
    if (m_impl != nullptr) {
        m_impl->_getPublisher()->unsubscribeFromStructInterfaceInterface(*this);
        m_impl = nullptr;
    }
    return retVal;
}
AbstractStructInterfaceDecorator::~AbstractStructInterfaceDecorator()
{
    if (m_impl != nullptr)
    {
        m_impl->_getPublisher()->unsubscribeFromStructInterfaceInterface(*this);
    }
}
void AbstractStructInterfaceDecorator::setPropbool(const StructBool& propBool)
{
    m_impl->setPropbool(propBool);
}

const StructBool& AbstractStructInterfaceDecorator::propBool() const
{
    return m_impl->propBool();
}
void AbstractStructInterfaceDecorator::setPropint(const StructInt& propInt)
{
    m_impl->setPropint(propInt);
}

const StructInt& AbstractStructInterfaceDecorator::propInt() const
{
    return m_impl->propInt();
}
void AbstractStructInterfaceDecorator::setPropfloat(const StructFloat& propFloat)
{
    m_impl->setPropfloat(propFloat);
}

const StructFloat& AbstractStructInterfaceDecorator::propFloat() const
{
    return m_impl->propFloat();
}
void AbstractStructInterfaceDecorator::setPropstring(const StructString& propString)
{
    m_impl->setPropstring(propString);
}

const StructString& AbstractStructInterfaceDecorator::propString() const
{
    return m_impl->propString();
}
/**
   \brief 
*/
StructBool AbstractStructInterfaceDecorator::funcBool(const StructBool& paramBool)
{
    return m_impl->funcBool(paramBool);
}
std::future<StructBool> AbstractStructInterfaceDecorator::funcBoolAsync(const StructBool& paramBool)
{
    return m_impl->funcBoolAsync(paramBool);
}
/**
   \brief 
*/
StructBool AbstractStructInterfaceDecorator::funcInt(const StructInt& paramInt)
{
    return m_impl->funcInt(paramInt);
}
std::future<StructBool> AbstractStructInterfaceDecorator::funcIntAsync(const StructInt& paramInt)
{
    return m_impl->funcIntAsync(paramInt);
}
/**
   \brief 
*/
StructFloat AbstractStructInterfaceDecorator::funcFloat(const StructFloat& paramFloat)
{
    return m_impl->funcFloat(paramFloat);
}
std::future<StructFloat> AbstractStructInterfaceDecorator::funcFloatAsync(const StructFloat& paramFloat)
{
    return m_impl->funcFloatAsync(paramFloat);
}
/**
   \brief 
*/
StructString AbstractStructInterfaceDecorator::funcString(const StructString& paramString)
{
    return m_impl->funcString(paramString);
}
std::future<StructString> AbstractStructInterfaceDecorator::funcStringAsync(const StructString& paramString)
{
    return m_impl->funcStringAsync(paramString);
}

IStructInterfacePublisher* AbstractStructInterfaceDecorator::_getPublisher() const
{
    return m_impl->_getPublisher();
}
