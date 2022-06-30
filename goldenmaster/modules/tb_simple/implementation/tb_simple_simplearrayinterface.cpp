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


#include "tb_simple_simplearrayinterface.h"
#include "generated/core/tb_simple_simplearrayinterface.publisher.h"

using namespace Test::TbSimple;

struct SimpleArrayInterface::SimpleArrayInterfaceData
{
    SimpleArrayInterfaceData()
    : _publisher(std::make_unique<SimpleArrayInterfacePublisher>())
    , m_propBool(std::list<bool>())
    , m_propInt(std::list<int>())
    , m_propFloat(std::list<float>())
    , m_propString(std::list<std::string>())
    {
    }
    std::unique_ptr<ISimpleArrayInterfacePublisher> _publisher;
    std::list<bool> m_propBool;
    std::list<int> m_propInt;
    std::list<float> m_propFloat;
    std::list<std::string> m_propString;

    ~SimpleArrayInterfaceData() = default;
};
/**
   \brief 
*/
SimpleArrayInterface::SimpleArrayInterface()
    : d_ptr(std::make_unique<SimpleArrayInterface::SimpleArrayInterfaceData>())
{
}
SimpleArrayInterface::~SimpleArrayInterface()
{
}
void SimpleArrayInterface::setPropbool(const std::list<bool>& propBool)
{
    if (d_ptr->m_propBool != propBool) {
        d_ptr->m_propBool = propBool;
        d_ptr->_publisher->publishPropBoolChanged(propBool);
    }
}

const std::list<bool>& SimpleArrayInterface::propBool() const
{
    return d_ptr->m_propBool;
}
void SimpleArrayInterface::setPropint(const std::list<int>& propInt)
{
    if (d_ptr->m_propInt != propInt) {
        d_ptr->m_propInt = propInt;
        d_ptr->_publisher->publishPropIntChanged(propInt);
    }
}

const std::list<int>& SimpleArrayInterface::propInt() const
{
    return d_ptr->m_propInt;
}
void SimpleArrayInterface::setPropfloat(const std::list<float>& propFloat)
{
    if (d_ptr->m_propFloat != propFloat) {
        d_ptr->m_propFloat = propFloat;
        d_ptr->_publisher->publishPropFloatChanged(propFloat);
    }
}

const std::list<float>& SimpleArrayInterface::propFloat() const
{
    return d_ptr->m_propFloat;
}
void SimpleArrayInterface::setPropstring(const std::list<std::string>& propString)
{
    if (d_ptr->m_propString != propString) {
        d_ptr->m_propString = propString;
        d_ptr->_publisher->publishPropStringChanged(propString);
    }
}

const std::list<std::string>& SimpleArrayInterface::propString() const
{
    return d_ptr->m_propString;
}
/**
   \brief 
*/
std::list<bool> SimpleArrayInterface::funcBool(const std::list<bool>& paramBool)
{
    (void) paramBool;
    // do business logic here
    return std::list<bool>();
}

std::future<std::list<bool>> SimpleArrayInterface::funcBoolAsync(const std::list<bool>& paramBool)
{
    return std::async(std::launch::async, [this,
                    paramBool]()
        {
            return funcBool(paramBool);
        }
    );
}
/**
   \brief 
*/
std::list<int> SimpleArrayInterface::funcInt(const std::list<int>& paramInt)
{
    (void) paramInt;
    // do business logic here
    return std::list<int>();
}

std::future<std::list<int>> SimpleArrayInterface::funcIntAsync(const std::list<int>& paramInt)
{
    return std::async(std::launch::async, [this,
                    paramInt]()
        {
            return funcInt(paramInt);
        }
    );
}
/**
   \brief 
*/
std::list<float> SimpleArrayInterface::funcFloat(const std::list<float>& paramFloat)
{
    (void) paramFloat;
    // do business logic here
    return std::list<float>();
}

std::future<std::list<float>> SimpleArrayInterface::funcFloatAsync(const std::list<float>& paramFloat)
{
    return std::async(std::launch::async, [this,
                    paramFloat]()
        {
            return funcFloat(paramFloat);
        }
    );
}
/**
   \brief 
*/
std::list<std::string> SimpleArrayInterface::funcString(const std::list<std::string>& paramString)
{
    (void) paramString;
    // do business logic here
    return std::list<std::string>();
}

std::future<std::list<std::string>> SimpleArrayInterface::funcStringAsync(const std::list<std::string>& paramString)
{
    return std::async(std::launch::async, [this,
                    paramString]()
        {
            return funcString(paramString);
        }
    );
}

ISimpleArrayInterfacePublisher* SimpleArrayInterface::_getPublisher() const
{
    return d_ptr->_publisher.get();
}
