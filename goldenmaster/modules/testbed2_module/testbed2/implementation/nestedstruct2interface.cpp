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


#include "testbed2/implementation/nestedstruct2interface.h"
#include "testbed2/generated/core/nestedstruct2interface.publisher.h"

using namespace Test::Testbed2;

struct NestedStruct2Interface::NestedStruct2InterfaceData
{
    NestedStruct2InterfaceData()
    : _publisher(std::make_unique<NestedStruct2InterfacePublisher>())
    , m_prop1(NestedStruct1())
    , m_prop2(NestedStruct2())
    {
    }
    std::unique_ptr<INestedStruct2InterfacePublisher> _publisher;
    NestedStruct1 m_prop1;
    NestedStruct2 m_prop2;

    ~NestedStruct2InterfaceData() = default;
};
/**
   \brief 
*/
NestedStruct2Interface::NestedStruct2Interface()
    : d_ptr(std::make_unique<NestedStruct2Interface::NestedStruct2InterfaceData>())
{
}
NestedStruct2Interface::~NestedStruct2Interface()
{
}
void NestedStruct2Interface::setProp1(const NestedStruct1& prop1)
{
    if (d_ptr->m_prop1 != prop1) {
        d_ptr->m_prop1 = prop1;
        d_ptr->_publisher->publishProp1Changed(prop1);
    }
}

const NestedStruct1& NestedStruct2Interface::prop1() const
{
    return d_ptr->m_prop1;
}
void NestedStruct2Interface::setProp2(const NestedStruct2& prop2)
{
    if (d_ptr->m_prop2 != prop2) {
        d_ptr->m_prop2 = prop2;
        d_ptr->_publisher->publishProp2Changed(prop2);
    }
}

const NestedStruct2& NestedStruct2Interface::prop2() const
{
    return d_ptr->m_prop2;
}
/**
   \brief 
*/
NestedStruct1 NestedStruct2Interface::func1(const NestedStruct1& param1)
{
    (void) param1;
    // do business logic here
    return NestedStruct1();
}

std::future<NestedStruct1> NestedStruct2Interface::func1Async(const NestedStruct1& param1)
{
    return std::async(std::launch::async, [this,
                    param1]()
        {
            return func1(param1);
        }
    );
}
/**
   \brief 
*/
NestedStruct1 NestedStruct2Interface::func2(const NestedStruct1& param1, const NestedStruct2& param2)
{
    (void) param1;
    (void) param2;
    // do business logic here
    return NestedStruct1();
}

std::future<NestedStruct1> NestedStruct2Interface::func2Async(const NestedStruct1& param1, const NestedStruct2& param2)
{
    return std::async(std::launch::async, [this,
                    param1,
                    param2]()
        {
            return func2(param1,param2);
        }
    );
}

INestedStruct2InterfacePublisher* NestedStruct2Interface::_getPublisher() const
{
    return d_ptr->_publisher.get();
}
