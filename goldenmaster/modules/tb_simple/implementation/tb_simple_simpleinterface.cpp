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


#include "tb_simple_simpleinterface.h"
#include "generated/core/tb_simple_simpleinterface.publisher.h"

using namespace Test::TbSimple;

struct SimpleInterface::SimpleInterfaceData
{
    SimpleInterfaceData()
    : _publisher(std::make_unique<SimpleInterfacePublisher>())
    , m_propBool(false)
    , m_propInt(0)
    , m_propFloat(0.0f)
    , m_propString(std::string())
    {
    }
    std::unique_ptr<ISimpleInterfacePublisher> _publisher;
    bool m_propBool;
    int m_propInt;
    float m_propFloat;
    std::string m_propString;

    ~SimpleInterfaceData() = default;
};
/**
   \brief 
*/
SimpleInterface::SimpleInterface()
    : d_ptr(std::make_unique<SimpleInterface::SimpleInterfaceData>())
{
}
SimpleInterface::~SimpleInterface()
{
}
void SimpleInterface::setPropbool(bool propBool)
{
    if (d_ptr->m_propBool != propBool) {
        d_ptr->m_propBool = propBool;
        d_ptr->_publisher->publishPropBoolChanged(propBool);
    }
}

bool SimpleInterface::propBool() const
{
    return d_ptr->m_propBool;
}
void SimpleInterface::setPropint(int propInt)
{
    if (d_ptr->m_propInt != propInt) {
        d_ptr->m_propInt = propInt;
        d_ptr->_publisher->publishPropIntChanged(propInt);
    }
}

int SimpleInterface::propInt() const
{
    return d_ptr->m_propInt;
}
void SimpleInterface::setPropfloat(float propFloat)
{
    if (d_ptr->m_propFloat != propFloat) {
        d_ptr->m_propFloat = propFloat;
        d_ptr->_publisher->publishPropFloatChanged(propFloat);
    }
}

float SimpleInterface::propFloat() const
{
    return d_ptr->m_propFloat;
}
void SimpleInterface::setPropstring(const std::string& propString)
{
    if (d_ptr->m_propString != propString) {
        d_ptr->m_propString = propString;
        d_ptr->_publisher->publishPropStringChanged(propString);
    }
}

std::string SimpleInterface::propString() const
{
    return d_ptr->m_propString;
}
/**
   \brief 
*/
bool SimpleInterface::funcBool(bool paramBool)
{
    (void) paramBool;
    // do business logic here
    return false;
}

std::future<bool> SimpleInterface::funcBoolAsync(bool paramBool)
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
int SimpleInterface::funcInt(int paramInt)
{
    (void) paramInt;
    // do business logic here
    return 0;
}

std::future<int> SimpleInterface::funcIntAsync(int paramInt)
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
float SimpleInterface::funcFloat(float paramFloat)
{
    (void) paramFloat;
    // do business logic here
    return 0.0f;
}

std::future<float> SimpleInterface::funcFloatAsync(float paramFloat)
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
std::string SimpleInterface::funcString(const std::string& paramString)
{
    (void) paramString;
    // do business logic here
    return std::string();
}

std::future<std::string> SimpleInterface::funcStringAsync(const std::string& paramString)
{
    return std::async(std::launch::async, [this,
                    paramString]()
        {
            return funcString(paramString);
        }
    );
}

ISimpleInterfacePublisher* SimpleInterface::_getPublisher() const
{
    return d_ptr->_publisher.get();
}
