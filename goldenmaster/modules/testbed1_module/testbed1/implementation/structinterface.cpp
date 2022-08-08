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


#include "testbed1/implementation/structinterface.h"
#include "testbed1/generated/core/structinterface.publisher.h"

using namespace Test::Testbed1;

struct StructInterface::StructInterfaceData
{
    StructInterfaceData()
    : _publisher(std::make_unique<StructInterfacePublisher>())
    , m_propBool(StructBool())
    , m_propInt(StructInt())
    , m_propFloat(StructFloat())
    , m_propString(StructString())
    {
    }
    std::unique_ptr<IStructInterfacePublisher> _publisher;
    StructBool m_propBool;
    StructInt m_propInt;
    StructFloat m_propFloat;
    StructString m_propString;

    ~StructInterfaceData() = default;
};
/**
   \brief 
*/
StructInterface::StructInterface()
    : d_ptr(std::make_unique<StructInterface::StructInterfaceData>())
{
}
StructInterface::~StructInterface()
{
}
void StructInterface::setPropbool(const StructBool& propBool)
{
    if (d_ptr->m_propBool != propBool) {
        d_ptr->m_propBool = propBool;
        d_ptr->_publisher->publishPropBoolChanged(propBool);
    }
}

const StructBool& StructInterface::propBool() const
{
    return d_ptr->m_propBool;
}
void StructInterface::setPropint(const StructInt& propInt)
{
    if (d_ptr->m_propInt != propInt) {
        d_ptr->m_propInt = propInt;
        d_ptr->_publisher->publishPropIntChanged(propInt);
    }
}

const StructInt& StructInterface::propInt() const
{
    return d_ptr->m_propInt;
}
void StructInterface::setPropfloat(const StructFloat& propFloat)
{
    if (d_ptr->m_propFloat != propFloat) {
        d_ptr->m_propFloat = propFloat;
        d_ptr->_publisher->publishPropFloatChanged(propFloat);
    }
}

const StructFloat& StructInterface::propFloat() const
{
    return d_ptr->m_propFloat;
}
void StructInterface::setPropstring(const StructString& propString)
{
    if (d_ptr->m_propString != propString) {
        d_ptr->m_propString = propString;
        d_ptr->_publisher->publishPropStringChanged(propString);
    }
}

const StructString& StructInterface::propString() const
{
    return d_ptr->m_propString;
}
/**
   \brief 
*/
StructBool StructInterface::funcBool(const StructBool& paramBool)
{
    (void) paramBool;
    // do business logic here
    return StructBool();
}

std::future<StructBool> StructInterface::funcBoolAsync(const StructBool& paramBool)
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
StructBool StructInterface::funcInt(const StructInt& paramInt)
{
    (void) paramInt;
    // do business logic here
    return StructBool();
}

std::future<StructBool> StructInterface::funcIntAsync(const StructInt& paramInt)
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
StructFloat StructInterface::funcFloat(const StructFloat& paramFloat)
{
    (void) paramFloat;
    // do business logic here
    return StructFloat();
}

std::future<StructFloat> StructInterface::funcFloatAsync(const StructFloat& paramFloat)
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
StructString StructInterface::funcString(const StructString& paramString)
{
    (void) paramString;
    // do business logic here
    return StructString();
}

std::future<StructString> StructInterface::funcStringAsync(const StructString& paramString)
{
    return std::async(std::launch::async, [this,
                    paramString]()
        {
            return funcString(paramString);
        }
    );
}

IStructInterfacePublisher* StructInterface::_getPublisher() const
{
    return d_ptr->_publisher.get();
}
