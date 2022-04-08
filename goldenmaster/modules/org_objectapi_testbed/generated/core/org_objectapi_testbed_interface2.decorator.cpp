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


#include "org_objectapi_testbed_interface2.decorator.h"

using namespace Test::OrgObjectapiTestbed;
/**
   \brief 
*/
AbstractInterface2Decorator::AbstractInterface2Decorator(IInterface2* impl)
    : m_impl(impl)
{
    m_impl->_getPublisher()->subscribeToInterface2Interface(*this);
}
IInterface2* AbstractInterface2Decorator::swapUnderlyingImplementation(IInterface2* impl)
{
    IInterface2* retVal = m_impl;
    if (m_impl != nullptr) {
        m_impl->_getPublisher()->unsubscribeFromInterface2Interface(*this);
    }
    m_impl = impl;
    if (m_impl != nullptr) {
        m_impl->_getPublisher()->subscribeToInterface2Interface(*this);
    }
    return retVal;
}
IInterface2* AbstractInterface2Decorator::disconnectFromUnderlyingImplementation()
{
    IInterface2* retVal = m_impl;
    if (m_impl != nullptr) {
        m_impl->_getPublisher()->unsubscribeFromInterface2Interface(*this);
        m_impl = nullptr;
    }
    return retVal;
}
AbstractInterface2Decorator::~AbstractInterface2Decorator()
{
    if (m_impl != nullptr)
    {
        m_impl->_getPublisher()->unsubscribeFromInterface2Interface(*this);
    }
}
void AbstractInterface2Decorator::setProp200(int prop200)
{
    m_impl->setProp200(prop200);
}

int AbstractInterface2Decorator::prop200() const
{
    return m_impl->prop200();
}
void AbstractInterface2Decorator::setProp201(int prop201)
{
    m_impl->setProp201(prop201);
}

int AbstractInterface2Decorator::prop201() const
{
    return m_impl->prop201();
}
void AbstractInterface2Decorator::setProp202(int prop202)
{
    m_impl->setProp202(prop202);
}

int AbstractInterface2Decorator::prop202() const
{
    return m_impl->prop202();
}
void AbstractInterface2Decorator::setProp203(float prop203)
{
    m_impl->setProp203(prop203);
}

float AbstractInterface2Decorator::prop203() const
{
    return m_impl->prop203();
}
void AbstractInterface2Decorator::setProp204(float prop204)
{
    m_impl->setProp204(prop204);
}

float AbstractInterface2Decorator::prop204() const
{
    return m_impl->prop204();
}
void AbstractInterface2Decorator::setProp205(const std::string& prop205)
{
    m_impl->setProp205(prop205);
}

std::string AbstractInterface2Decorator::prop205() const
{
    return m_impl->prop205();
}

IInterface2Publisher* AbstractInterface2Decorator::_getPublisher() const
{
    return m_impl->_getPublisher();
}
