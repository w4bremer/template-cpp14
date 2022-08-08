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


#include "testbed1/implementation/structarrayinterface.h"
#include "testbed1/generated/core/structarrayinterface.publisher.h"

using namespace Test::Testbed1;

struct StructArrayInterface::StructArrayInterfaceData
{
    StructArrayInterfaceData()
    : _publisher(std::make_unique<StructArrayInterfacePublisher>())
    , m_propBool(std::list<StructBool>())
    , m_propInt(std::list<StructInt>())
    , m_propFloat(std::list<StructFloat>())
    , m_propString(std::list<StructString>())
    {
    }
    std::unique_ptr<IStructArrayInterfacePublisher> _publisher;
    std::list<StructBool> m_propBool;
    std::list<StructInt> m_propInt;
    std::list<StructFloat> m_propFloat;
    std::list<StructString> m_propString;

    ~StructArrayInterfaceData() = default;
};
/**
   \brief 
*/
StructArrayInterface::StructArrayInterface()
    : d_ptr(std::make_unique<StructArrayInterface::StructArrayInterfaceData>())
{
}
StructArrayInterface::~StructArrayInterface()
{
}
void StructArrayInterface::setPropbool(const std::list<StructBool>& propBool)
{
    if (d_ptr->m_propBool != propBool) {
        d_ptr->m_propBool = propBool;
        d_ptr->_publisher->publishPropBoolChanged(propBool);
    }
}

const std::list<StructBool>& StructArrayInterface::propBool() const
{
    return d_ptr->m_propBool;
}
void StructArrayInterface::setPropint(const std::list<StructInt>& propInt)
{
    if (d_ptr->m_propInt != propInt) {
        d_ptr->m_propInt = propInt;
        d_ptr->_publisher->publishPropIntChanged(propInt);
    }
}

const std::list<StructInt>& StructArrayInterface::propInt() const
{
    return d_ptr->m_propInt;
}
void StructArrayInterface::setPropfloat(const std::list<StructFloat>& propFloat)
{
    if (d_ptr->m_propFloat != propFloat) {
        d_ptr->m_propFloat = propFloat;
        d_ptr->_publisher->publishPropFloatChanged(propFloat);
    }
}

const std::list<StructFloat>& StructArrayInterface::propFloat() const
{
    return d_ptr->m_propFloat;
}
void StructArrayInterface::setPropstring(const std::list<StructString>& propString)
{
    if (d_ptr->m_propString != propString) {
        d_ptr->m_propString = propString;
        d_ptr->_publisher->publishPropStringChanged(propString);
    }
}

const std::list<StructString>& StructArrayInterface::propString() const
{
    return d_ptr->m_propString;
}
/**
   \brief 
*/
StructBool StructArrayInterface::funcBool(const std::list<StructBool>& paramBool)
{
    (void) paramBool;
    // do business logic here
    return StructBool();
}

std::future<StructBool> StructArrayInterface::funcBoolAsync(const std::list<StructBool>& paramBool)
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
StructBool StructArrayInterface::funcInt(const std::list<StructInt>& paramInt)
{
    (void) paramInt;
    // do business logic here
    return StructBool();
}

std::future<StructBool> StructArrayInterface::funcIntAsync(const std::list<StructInt>& paramInt)
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
StructBool StructArrayInterface::funcFloat(const std::list<StructFloat>& paramFloat)
{
    (void) paramFloat;
    // do business logic here
    return StructBool();
}

std::future<StructBool> StructArrayInterface::funcFloatAsync(const std::list<StructFloat>& paramFloat)
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
StructBool StructArrayInterface::funcString(const std::list<StructString>& paramString)
{
    (void) paramString;
    // do business logic here
    return StructBool();
}

std::future<StructBool> StructArrayInterface::funcStringAsync(const std::list<StructString>& paramString)
{
    return std::async(std::launch::async, [this,
                    paramString]()
        {
            return funcString(paramString);
        }
    );
}

IStructArrayInterfacePublisher* StructArrayInterface::_getPublisher() const
{
    return d_ptr->_publisher.get();
}
