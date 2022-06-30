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


#include "tb_same1_sameenum2interface.h"
#include "generated/core/tb_same1_sameenum2interface.publisher.h"

using namespace Test::TbSame1;

struct SameEnum2Interface::SameEnum2InterfaceData
{
    SameEnum2InterfaceData()
    : _publisher(std::make_unique<SameEnum2InterfacePublisher>())
    , m_prop1(Enum1Enum::value1)
    , m_prop2(Enum2Enum::value1)
    {
    }
    std::unique_ptr<ISameEnum2InterfacePublisher> _publisher;
    Enum1Enum m_prop1;
    Enum2Enum m_prop2;

    ~SameEnum2InterfaceData() = default;
};
/**
   \brief 
*/
SameEnum2Interface::SameEnum2Interface()
    : d_ptr(std::make_unique<SameEnum2Interface::SameEnum2InterfaceData>())
{
}
SameEnum2Interface::~SameEnum2Interface()
{
}
void SameEnum2Interface::setProp1(const Enum1Enum& prop1)
{
    if (d_ptr->m_prop1 != prop1) {
        d_ptr->m_prop1 = prop1;
        d_ptr->_publisher->publishProp1Changed(prop1);
    }
}

const Enum1Enum& SameEnum2Interface::prop1() const
{
    return d_ptr->m_prop1;
}
void SameEnum2Interface::setProp2(const Enum2Enum& prop2)
{
    if (d_ptr->m_prop2 != prop2) {
        d_ptr->m_prop2 = prop2;
        d_ptr->_publisher->publishProp2Changed(prop2);
    }
}

const Enum2Enum& SameEnum2Interface::prop2() const
{
    return d_ptr->m_prop2;
}
/**
   \brief 
*/
Enum1Enum SameEnum2Interface::func1(const Enum1Enum& param1)
{
    (void) param1;
    // do business logic here
    return Enum1Enum::value1;
}

std::future<Enum1Enum> SameEnum2Interface::func1Async(const Enum1Enum& param1)
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
Enum1Enum SameEnum2Interface::func2(const Enum1Enum& param1, const Enum2Enum& param2)
{
    (void) param1;
    (void) param2;
    // do business logic here
    return Enum1Enum::value1;
}

std::future<Enum1Enum> SameEnum2Interface::func2Async(const Enum1Enum& param1, const Enum2Enum& param2)
{
    return std::async(std::launch::async, [this,
                    param1,
                    param2]()
        {
            return func2(param1,param2);
        }
    );
}

ISameEnum2InterfacePublisher* SameEnum2Interface::_getPublisher() const
{
    return d_ptr->_publisher.get();
}
