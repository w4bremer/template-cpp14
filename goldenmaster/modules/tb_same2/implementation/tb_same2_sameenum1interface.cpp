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


#include "tb_same2_sameenum1interface.h"
#include "generated/core/tb_same2_sameenum1interface.publisher.h"

using namespace Test::TbSame2;

struct SameEnum1Interface::SameEnum1InterfaceData
{
    SameEnum1InterfaceData()
    : _publisher(std::make_unique<SameEnum1InterfacePublisher>())
    , m_prop1(Enum1Enum::value1)
    {
    }
    std::unique_ptr<ISameEnum1InterfacePublisher> _publisher;
    Enum1Enum m_prop1;

    ~SameEnum1InterfaceData() = default;
};
/**
   \brief 
*/
SameEnum1Interface::SameEnum1Interface()
    : d_ptr(std::make_unique<SameEnum1Interface::SameEnum1InterfaceData>())
{
}
SameEnum1Interface::~SameEnum1Interface()
{
}
void SameEnum1Interface::setProp1(const Enum1Enum& prop1)
{
    if (d_ptr->m_prop1 != prop1) {
        d_ptr->m_prop1 = prop1;
        d_ptr->_publisher->publishProp1Changed(prop1);
    }
}

const Enum1Enum& SameEnum1Interface::prop1() const
{
    return d_ptr->m_prop1;
}
/**
   \brief 
*/
Enum1Enum SameEnum1Interface::func1(const Enum1Enum& param1)
{
    (void) param1;
    // do business logic here
    return Enum1Enum::value1;
}

std::future<Enum1Enum> SameEnum1Interface::func1Async(const Enum1Enum& param1)
{
    return std::async(std::launch::async, [this,
                    param1]()
        {
            return func1(param1);
        }
    );
}

ISameEnum1InterfacePublisher* SameEnum1Interface::_getPublisher() const
{
    return d_ptr->_publisher.get();
}
