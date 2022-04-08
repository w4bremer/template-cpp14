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


#include "org_objectapi_testbed_interface1.decorator.h"

using namespace Test::OrgObjectapiTestbed;
/**
   \brief 
*/
AbstractInterface1Decorator::AbstractInterface1Decorator(IInterface1* impl)
    : m_impl(impl)
{
    m_impl->_getPublisher()->subscribeToInterface1Interface(*this);
}
IInterface1* AbstractInterface1Decorator::swapUnderlyingImplementation(IInterface1* impl)
{
    IInterface1* retVal = m_impl;
    if (m_impl != nullptr) {
        m_impl->_getPublisher()->unsubscribeFromInterface1Interface(*this);
    }
    m_impl = impl;
    if (m_impl != nullptr) {
        m_impl->_getPublisher()->subscribeToInterface1Interface(*this);
    }
    return retVal;
}
IInterface1* AbstractInterface1Decorator::disconnectFromUnderlyingImplementation()
{
    IInterface1* retVal = m_impl;
    if (m_impl != nullptr) {
        m_impl->_getPublisher()->unsubscribeFromInterface1Interface(*this);
        m_impl = nullptr;
    }
    return retVal;
}
AbstractInterface1Decorator::~AbstractInterface1Decorator()
{
    if (m_impl != nullptr)
    {
        m_impl->_getPublisher()->unsubscribeFromInterface1Interface(*this);
    }
}
void AbstractInterface1Decorator::setProp1(bool prop1)
{
    m_impl->setProp1(prop1);
}

bool AbstractInterface1Decorator::prop1() const
{
    return m_impl->prop1();
}
void AbstractInterface1Decorator::setProp2(int prop2)
{
    m_impl->setProp2(prop2);
}

int AbstractInterface1Decorator::prop2() const
{
    return m_impl->prop2();
}
void AbstractInterface1Decorator::setProp3(float prop3)
{
    m_impl->setProp3(prop3);
}

float AbstractInterface1Decorator::prop3() const
{
    return m_impl->prop3();
}
void AbstractInterface1Decorator::setProp4(const std::string& prop4)
{
    m_impl->setProp4(prop4);
}

std::string AbstractInterface1Decorator::prop4() const
{
    return m_impl->prop4();
}
void AbstractInterface1Decorator::setProp5(const std::list<int>& prop5)
{
    m_impl->setProp5(prop5);
}

const std::list<int>& AbstractInterface1Decorator::prop5() const
{
    return m_impl->prop5();
}
void AbstractInterface1Decorator::setProp6(const Struct1& prop6)
{
    m_impl->setProp6(prop6);
}

const Struct1& AbstractInterface1Decorator::prop6() const
{
    return m_impl->prop6();
}
void AbstractInterface1Decorator::setProp7(int prop7)
{
    m_impl->setProp7(prop7);
}

int AbstractInterface1Decorator::prop7() const
{
    return m_impl->prop7();
}
void AbstractInterface1Decorator::setProp10(const std::list<int>& prop10)
{
    m_impl->setProp10(prop10);
}

const std::list<int>& AbstractInterface1Decorator::prop10() const
{
    return m_impl->prop10();
}
void AbstractInterface1Decorator::setProp11(const std::list<Struct1>& prop11)
{
    m_impl->setProp11(prop11);
}

const std::list<Struct1>& AbstractInterface1Decorator::prop11() const
{
    return m_impl->prop11();
}
void AbstractInterface1Decorator::setProp12(const std::list<Enum1Enum>& prop12)
{
    m_impl->setProp12(prop12);
}

const std::list<Enum1Enum>& AbstractInterface1Decorator::prop12() const
{
    return m_impl->prop12();
}
void AbstractInterface1Decorator::setProp14(const std::list<Struct1>& prop14)
{
    m_impl->setProp14(prop14);
}

const std::list<Struct1>& AbstractInterface1Decorator::prop14() const
{
    return m_impl->prop14();
}
/**
   \brief 
*/
void AbstractInterface1Decorator::op1()
{
    return m_impl->op1();
}
std::future<void> AbstractInterface1Decorator::op1Async()
{
    return m_impl->op1Async();
}
/**
   \brief 
*/
void AbstractInterface1Decorator::op2(int step)
{
    return m_impl->op2(step);
}
std::future<void> AbstractInterface1Decorator::op2Async(int step)
{
    return m_impl->op2Async(step);
}
/**
   \brief 
*/
int AbstractInterface1Decorator::op3()
{
    return m_impl->op3();
}
std::future<int> AbstractInterface1Decorator::op3Async()
{
    return m_impl->op3Async();
}

IInterface1Publisher* AbstractInterface1Decorator::_getPublisher() const
{
    return m_impl->_getPublisher();
}
