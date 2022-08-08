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


#include "testbed2/implementation/nestedstruct1interface.h"
#include "testbed2/generated/core/nestedstruct1interface.publisher.h"

using namespace Test::Testbed2;

struct NestedStruct1Interface::NestedStruct1InterfaceData
{
    NestedStruct1InterfaceData()
    : _publisher(std::make_unique<NestedStruct1InterfacePublisher>())
    , m_prop1(NestedStruct1())
    {
    }
    std::unique_ptr<INestedStruct1InterfacePublisher> _publisher;
    NestedStruct1 m_prop1;

    ~NestedStruct1InterfaceData() = default;
};
/**
   \brief 
*/
NestedStruct1Interface::NestedStruct1Interface()
    : d_ptr(std::make_unique<NestedStruct1Interface::NestedStruct1InterfaceData>())
{
}
NestedStruct1Interface::~NestedStruct1Interface()
{
}
void NestedStruct1Interface::setProp1(const NestedStruct1& prop1)
{
    if (d_ptr->m_prop1 != prop1) {
        d_ptr->m_prop1 = prop1;
        d_ptr->_publisher->publishProp1Changed(prop1);
    }
}

const NestedStruct1& NestedStruct1Interface::prop1() const
{
    return d_ptr->m_prop1;
}
/**
   \brief 
*/
NestedStruct1 NestedStruct1Interface::func1(const NestedStruct1& param1)
{
    (void) param1;
    // do business logic here
    return NestedStruct1();
}

std::future<NestedStruct1> NestedStruct1Interface::func1Async(const NestedStruct1& param1)
{
    return std::async(std::launch::async, [this,
                    param1]()
        {
            return func1(param1);
        }
    );
}

INestedStruct1InterfacePublisher* NestedStruct1Interface::_getPublisher() const
{
    return d_ptr->_publisher.get();
}
