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


#include "tb_enum_enuminterface.h"
#include "generated/core/tb_enum_enuminterface.publisher.h"

using namespace Test::TbEnum;

struct EnumInterface::EnumInterfaceData
{
    EnumInterfaceData()
    : _publisher(std::make_unique<EnumInterfacePublisher>())
    , m_prop0(Enum0Enum::value0)
    , m_prop1(Enum1Enum::value1)
    , m_prop2(Enum2Enum::value2)
    , m_prop3(Enum3Enum::value3)
    {
    }
    std::unique_ptr<IEnumInterfacePublisher> _publisher;
    Enum0Enum m_prop0;
    Enum1Enum m_prop1;
    Enum2Enum m_prop2;
    Enum3Enum m_prop3;

    ~EnumInterfaceData() = default;
};
/**
   \brief 
*/
EnumInterface::EnumInterface()
    : d_ptr(std::make_unique<EnumInterface::EnumInterfaceData>())
{
}
EnumInterface::~EnumInterface()
{
}
void EnumInterface::setProp0(const Enum0Enum& prop0)
{
    if (d_ptr->m_prop0 != prop0) {
        d_ptr->m_prop0 = prop0;
        d_ptr->_publisher->publishProp0Changed(prop0);
    }
}

const Enum0Enum& EnumInterface::prop0() const
{
    return d_ptr->m_prop0;
}
void EnumInterface::setProp1(const Enum1Enum& prop1)
{
    if (d_ptr->m_prop1 != prop1) {
        d_ptr->m_prop1 = prop1;
        d_ptr->_publisher->publishProp1Changed(prop1);
    }
}

const Enum1Enum& EnumInterface::prop1() const
{
    return d_ptr->m_prop1;
}
void EnumInterface::setProp2(const Enum2Enum& prop2)
{
    if (d_ptr->m_prop2 != prop2) {
        d_ptr->m_prop2 = prop2;
        d_ptr->_publisher->publishProp2Changed(prop2);
    }
}

const Enum2Enum& EnumInterface::prop2() const
{
    return d_ptr->m_prop2;
}
void EnumInterface::setProp3(const Enum3Enum& prop3)
{
    if (d_ptr->m_prop3 != prop3) {
        d_ptr->m_prop3 = prop3;
        d_ptr->_publisher->publishProp3Changed(prop3);
    }
}

const Enum3Enum& EnumInterface::prop3() const
{
    return d_ptr->m_prop3;
}
/**
   \brief 
*/
Enum0Enum EnumInterface::func0(const Enum0Enum& param0)
{
    (void) param0;
    // do business logic here
    return Enum0Enum::value0;
}

std::future<Enum0Enum> EnumInterface::func0Async(const Enum0Enum& param0)
{
    return std::async(std::launch::async, [this,
                    param0]()
        {
            return func0(param0);
        }
    );
}
/**
   \brief 
*/
Enum1Enum EnumInterface::func1(const Enum1Enum& param1)
{
    (void) param1;
    // do business logic here
    return Enum1Enum::value1;
}

std::future<Enum1Enum> EnumInterface::func1Async(const Enum1Enum& param1)
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
Enum2Enum EnumInterface::func2(const Enum2Enum& param2)
{
    (void) param2;
    // do business logic here
    return Enum2Enum::value2;
}

std::future<Enum2Enum> EnumInterface::func2Async(const Enum2Enum& param2)
{
    return std::async(std::launch::async, [this,
                    param2]()
        {
            return func2(param2);
        }
    );
}
/**
   \brief 
*/
Enum3Enum EnumInterface::func3(const Enum3Enum& param3)
{
    (void) param3;
    // do business logic here
    return Enum3Enum::value3;
}

std::future<Enum3Enum> EnumInterface::func3Async(const Enum3Enum& param3)
{
    return std::async(std::launch::async, [this,
                    param3]()
        {
            return func3(param3);
        }
    );
}

IEnumInterfacePublisher* EnumInterface::_getPublisher() const
{
    return d_ptr->_publisher.get();
}
