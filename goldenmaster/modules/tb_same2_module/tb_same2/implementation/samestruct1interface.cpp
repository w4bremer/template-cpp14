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


#include "tb_same2/implementation/samestruct1interface.h"
#include "tb_same2/generated/core/samestruct1interface.publisher.h"

using namespace Test::TbSame2;

struct SameStruct1Interface::SameStruct1InterfaceData
{
    SameStruct1InterfaceData()
    : _publisher(std::make_unique<SameStruct1InterfacePublisher>())
    , m_prop1(Struct1())
    {
    }
    std::unique_ptr<ISameStruct1InterfacePublisher> _publisher;
    Struct1 m_prop1;

    ~SameStruct1InterfaceData() = default;
};
/**
   \brief 
*/
SameStruct1Interface::SameStruct1Interface()
    : d_ptr(std::make_unique<SameStruct1Interface::SameStruct1InterfaceData>())
{
}
SameStruct1Interface::~SameStruct1Interface()
{
}
void SameStruct1Interface::setProp1(const Struct1& prop1)
{
    if (d_ptr->m_prop1 != prop1) {
        d_ptr->m_prop1 = prop1;
        d_ptr->_publisher->publishProp1Changed(prop1);
    }
}

const Struct1& SameStruct1Interface::prop1() const
{
    return d_ptr->m_prop1;
}
/**
   \brief 
*/
Struct1 SameStruct1Interface::func1(const Struct1& param1)
{
    (void) param1;
    // do business logic here
    return Struct1();
}

std::future<Struct1> SameStruct1Interface::func1Async(const Struct1& param1)
{
    return std::async(std::launch::async, [this,
                    param1]()
        {
            return func1(param1);
        }
    );
}

ISameStruct1InterfacePublisher* SameStruct1Interface::_getPublisher() const
{
    return d_ptr->_publisher.get();
}
