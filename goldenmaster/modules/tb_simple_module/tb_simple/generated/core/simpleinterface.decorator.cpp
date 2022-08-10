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


#include "tb_simple/generated/core/simpleinterface.decorator.h"
#include "tb_simple/generated/core/simpleinterface.publisher.h"

using namespace Test::TbSimple;
/**
   \brief 
*/
AbstractSimpleInterfaceDecorator::AbstractSimpleInterfaceDecorator(ISimpleInterface* impl)
    : m_impl(impl)
{
    m_impl->_getPublisher().subscribeToAllChanges(*this);
}
ISimpleInterface* AbstractSimpleInterfaceDecorator::swapUnderlyingImplementation(ISimpleInterface* impl)
{
    ISimpleInterface* retVal = m_impl;
    if (m_impl != nullptr) {
        m_impl->_getPublisher().unsubscribeFromAllChanges(*this);
    }
    m_impl = impl;
    if (m_impl != nullptr) {
        m_impl->_getPublisher().subscribeToAllChanges(*this);
    }
    return retVal;
}
ISimpleInterface* AbstractSimpleInterfaceDecorator::disconnectFromUnderlyingImplementation()
{
    ISimpleInterface* retVal = m_impl;
    if (m_impl != nullptr) {
        m_impl->_getPublisher().unsubscribeFromAllChanges(*this);
        m_impl = nullptr;
    }
    return retVal;
}
AbstractSimpleInterfaceDecorator::~AbstractSimpleInterfaceDecorator()
{
    if (m_impl != nullptr)
    {
        m_impl->_getPublisher().unsubscribeFromAllChanges(*this);
    }
}
void AbstractSimpleInterfaceDecorator::setPropBool(bool propBool)
{
    m_impl->setPropBool(propBool);
}

bool AbstractSimpleInterfaceDecorator::propBool() const
{
    return m_impl->propBool();
}
void AbstractSimpleInterfaceDecorator::setPropInt(int propInt)
{
    m_impl->setPropInt(propInt);
}

int AbstractSimpleInterfaceDecorator::propInt() const
{
    return m_impl->propInt();
}
void AbstractSimpleInterfaceDecorator::setPropFloat(float propFloat)
{
    m_impl->setPropFloat(propFloat);
}

float AbstractSimpleInterfaceDecorator::propFloat() const
{
    return m_impl->propFloat();
}
void AbstractSimpleInterfaceDecorator::setPropString(const std::string& propString)
{
    m_impl->setPropString(propString);
}

std::string AbstractSimpleInterfaceDecorator::propString() const
{
    return m_impl->propString();
}
/**
   \brief 
*/
bool AbstractSimpleInterfaceDecorator::funcBool(bool paramBool)
{
    return m_impl->funcBool(paramBool);
}
std::future<bool> AbstractSimpleInterfaceDecorator::funcBoolAsync(bool paramBool)
{
    return m_impl->funcBoolAsync(paramBool);
}
/**
   \brief 
*/
int AbstractSimpleInterfaceDecorator::funcInt(int paramInt)
{
    return m_impl->funcInt(paramInt);
}
std::future<int> AbstractSimpleInterfaceDecorator::funcIntAsync(int paramInt)
{
    return m_impl->funcIntAsync(paramInt);
}
/**
   \brief 
*/
float AbstractSimpleInterfaceDecorator::funcFloat(float paramFloat)
{
    return m_impl->funcFloat(paramFloat);
}
std::future<float> AbstractSimpleInterfaceDecorator::funcFloatAsync(float paramFloat)
{
    return m_impl->funcFloatAsync(paramFloat);
}
/**
   \brief 
*/
std::string AbstractSimpleInterfaceDecorator::funcString(const std::string& paramString)
{
    return m_impl->funcString(paramString);
}
std::future<std::string> AbstractSimpleInterfaceDecorator::funcStringAsync(const std::string& paramString)
{
    return m_impl->funcStringAsync(paramString);
}

ISimpleInterfacePublisher& AbstractSimpleInterfaceDecorator::_getPublisher() const
{
    return m_impl->_getPublisher();
}
