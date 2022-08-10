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


#include "tb_simple/generated/core/simplearrayinterface.decorator.h"
#include "tb_simple/generated/core/simplearrayinterface.publisher.h"

using namespace Test::TbSimple;
/**
   \brief 
*/
AbstractSimpleArrayInterfaceDecorator::AbstractSimpleArrayInterfaceDecorator(ISimpleArrayInterface* impl)
    : m_impl(impl)
{
    m_impl->_getPublisher().subscribeToAllChanges(*this);
}
ISimpleArrayInterface* AbstractSimpleArrayInterfaceDecorator::swapUnderlyingImplementation(ISimpleArrayInterface* impl)
{
    ISimpleArrayInterface* retVal = m_impl;
    if (m_impl != nullptr) {
        m_impl->_getPublisher().unsubscribeFromAllChanges(*this);
    }
    m_impl = impl;
    if (m_impl != nullptr) {
        m_impl->_getPublisher().subscribeToAllChanges(*this);
    }
    return retVal;
}
ISimpleArrayInterface* AbstractSimpleArrayInterfaceDecorator::disconnectFromUnderlyingImplementation()
{
    ISimpleArrayInterface* retVal = m_impl;
    if (m_impl != nullptr) {
        m_impl->_getPublisher().unsubscribeFromAllChanges(*this);
        m_impl = nullptr;
    }
    return retVal;
}
AbstractSimpleArrayInterfaceDecorator::~AbstractSimpleArrayInterfaceDecorator()
{
    if (m_impl != nullptr)
    {
        m_impl->_getPublisher().unsubscribeFromAllChanges(*this);
    }
}
void AbstractSimpleArrayInterfaceDecorator::setPropBool(const std::list<bool>& propBool)
{
    m_impl->setPropBool(propBool);
}

const std::list<bool>& AbstractSimpleArrayInterfaceDecorator::propBool() const
{
    return m_impl->propBool();
}
void AbstractSimpleArrayInterfaceDecorator::setPropInt(const std::list<int>& propInt)
{
    m_impl->setPropInt(propInt);
}

const std::list<int>& AbstractSimpleArrayInterfaceDecorator::propInt() const
{
    return m_impl->propInt();
}
void AbstractSimpleArrayInterfaceDecorator::setPropFloat(const std::list<float>& propFloat)
{
    m_impl->setPropFloat(propFloat);
}

const std::list<float>& AbstractSimpleArrayInterfaceDecorator::propFloat() const
{
    return m_impl->propFloat();
}
void AbstractSimpleArrayInterfaceDecorator::setPropString(const std::list<std::string>& propString)
{
    m_impl->setPropString(propString);
}

const std::list<std::string>& AbstractSimpleArrayInterfaceDecorator::propString() const
{
    return m_impl->propString();
}
/**
   \brief 
*/
std::list<bool> AbstractSimpleArrayInterfaceDecorator::funcBool(const std::list<bool>& paramBool)
{
    return m_impl->funcBool(paramBool);
}
std::future<std::list<bool>> AbstractSimpleArrayInterfaceDecorator::funcBoolAsync(const std::list<bool>& paramBool)
{
    return m_impl->funcBoolAsync(paramBool);
}
/**
   \brief 
*/
std::list<int> AbstractSimpleArrayInterfaceDecorator::funcInt(const std::list<int>& paramInt)
{
    return m_impl->funcInt(paramInt);
}
std::future<std::list<int>> AbstractSimpleArrayInterfaceDecorator::funcIntAsync(const std::list<int>& paramInt)
{
    return m_impl->funcIntAsync(paramInt);
}
/**
   \brief 
*/
std::list<float> AbstractSimpleArrayInterfaceDecorator::funcFloat(const std::list<float>& paramFloat)
{
    return m_impl->funcFloat(paramFloat);
}
std::future<std::list<float>> AbstractSimpleArrayInterfaceDecorator::funcFloatAsync(const std::list<float>& paramFloat)
{
    return m_impl->funcFloatAsync(paramFloat);
}
/**
   \brief 
*/
std::list<std::string> AbstractSimpleArrayInterfaceDecorator::funcString(const std::list<std::string>& paramString)
{
    return m_impl->funcString(paramString);
}
std::future<std::list<std::string>> AbstractSimpleArrayInterfaceDecorator::funcStringAsync(const std::list<std::string>& paramString)
{
    return m_impl->funcStringAsync(paramString);
}

ISimpleArrayInterfacePublisher& AbstractSimpleArrayInterfaceDecorator::_getPublisher() const
{
    return m_impl->_getPublisher();
}
