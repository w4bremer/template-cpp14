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


#include "org_objectapi_testbed_interface1.h"
#include "generated/core/org_objectapi_testbed_interface1.publisher.h"

using namespace Test::OrgObjectapiTestbed;

struct Interface1::Interface1Data
{
    Interface1Data()
    : _publisher(std::make_unique<Interface1Publisher>())
    , m_prop1(false)
    , m_prop2(0)
    , m_prop3(0.0f)
    , m_prop4(std::string())
    , m_prop5(std::list<int>())
    , m_prop6(Struct1())
    , m_prop7(0)
    , m_prop10(std::list<int>())
    , m_prop11(std::list<Struct1>())
    , m_prop12(std::list<Enum1Enum>())
    , m_prop14(std::list<Struct1>())
    {
    }
    std::unique_ptr<IInterface1Publisher> _publisher;
    bool m_prop1;
    int m_prop2;
    float m_prop3;
    std::string m_prop4;
    std::list<int> m_prop5;
    Struct1 m_prop6;
    int m_prop7;
    std::list<int> m_prop10;
    std::list<Struct1> m_prop11;
    std::list<Enum1Enum> m_prop12;
    std::list<Struct1> m_prop14;

    ~Interface1Data() = default;
};
/**
   \brief 
*/
Interface1::Interface1()
    : d_ptr(std::make_unique<Interface1::Interface1Data>())
{
}
Interface1::~Interface1()
{
}
void Interface1::setProp1(bool prop1)
{
    if (d_ptr->m_prop1 != prop1) {
        d_ptr->m_prop1 = prop1;
        d_ptr->_publisher->publishProp1Changed(prop1);
    }
}

bool Interface1::prop1() const
{
    return d_ptr->m_prop1;
}
void Interface1::setProp2(int prop2)
{
    if (d_ptr->m_prop2 != prop2) {
        d_ptr->m_prop2 = prop2;
        d_ptr->_publisher->publishProp2Changed(prop2);
    }
}

int Interface1::prop2() const
{
    return d_ptr->m_prop2;
}
void Interface1::setProp3(float prop3)
{
    if (d_ptr->m_prop3 != prop3) {
        d_ptr->m_prop3 = prop3;
        d_ptr->_publisher->publishProp3Changed(prop3);
    }
}

float Interface1::prop3() const
{
    return d_ptr->m_prop3;
}
void Interface1::setProp4(const std::string& prop4)
{
    if (d_ptr->m_prop4 != prop4) {
        d_ptr->m_prop4 = prop4;
        d_ptr->_publisher->publishProp4Changed(prop4);
    }
}

std::string Interface1::prop4() const
{
    return d_ptr->m_prop4;
}
void Interface1::setProp5(const std::list<int>& prop5)
{
    if (d_ptr->m_prop5 != prop5) {
        d_ptr->m_prop5 = prop5;
        d_ptr->_publisher->publishProp5Changed(prop5);
    }
}

const std::list<int>& Interface1::prop5() const
{
    return d_ptr->m_prop5;
}
void Interface1::setProp6(const Struct1& prop6)
{
    if (d_ptr->m_prop6 != prop6) {
        d_ptr->m_prop6 = prop6;
        d_ptr->_publisher->publishProp6Changed(prop6);
    }
}

const Struct1& Interface1::prop6() const
{
    return d_ptr->m_prop6;
}
void Interface1::setProp7(int prop7)
{
    if (d_ptr->m_prop7 != prop7) {
        d_ptr->m_prop7 = prop7;
        d_ptr->_publisher->publishProp7Changed(prop7);
    }
}

int Interface1::prop7() const
{
    return d_ptr->m_prop7;
}
void Interface1::setProp10(const std::list<int>& prop10)
{
    if (d_ptr->m_prop10 != prop10) {
        d_ptr->m_prop10 = prop10;
        d_ptr->_publisher->publishProp10Changed(prop10);
    }
}

const std::list<int>& Interface1::prop10() const
{
    return d_ptr->m_prop10;
}
void Interface1::setProp11(const std::list<Struct1>& prop11)
{
    if (d_ptr->m_prop11 != prop11) {
        d_ptr->m_prop11 = prop11;
        d_ptr->_publisher->publishProp11Changed(prop11);
    }
}

const std::list<Struct1>& Interface1::prop11() const
{
    return d_ptr->m_prop11;
}
void Interface1::setProp12(const std::list<Enum1Enum>& prop12)
{
    if (d_ptr->m_prop12 != prop12) {
        d_ptr->m_prop12 = prop12;
        d_ptr->_publisher->publishProp12Changed(prop12);
    }
}

const std::list<Enum1Enum>& Interface1::prop12() const
{
    return d_ptr->m_prop12;
}
void Interface1::setProp14(const std::list<Struct1>& prop14)
{
    if (d_ptr->m_prop14 != prop14) {
        d_ptr->m_prop14 = prop14;
        d_ptr->_publisher->publishProp14Changed(prop14);
    }
}

const std::list<Struct1>& Interface1::prop14() const
{
    return d_ptr->m_prop14;
}
/**
   \brief 
*/
void Interface1::op1()
{
    // do business logic here
    return ;
}

std::future<void> Interface1::op1Async()
{
    return std::async(std::launch::async, [this]()
        {
            return op1();
        }
    );
}
/**
   \brief 
*/
void Interface1::op2(int step)
{
    (void) step;
    // do business logic here
    return ;
}

std::future<void> Interface1::op2Async(int step)
{
    return std::async(std::launch::async, [this,
                    step]()
        {
            return op2(step);
        }
    );
}
/**
   \brief 
*/
int Interface1::op3()
{
    // do business logic here
    return 0;
}

std::future<int> Interface1::op3Async()
{
    return std::async(std::launch::async, [this]()
        {
            return op3();
        }
    );
}

IInterface1Publisher* Interface1::_getPublisher() const
{
    return d_ptr->_publisher.get();
}
