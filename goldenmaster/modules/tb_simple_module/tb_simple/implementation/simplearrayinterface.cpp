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


#include "tb_simple/implementation/simplearrayinterface.h"
#include "tb_simple/generated/core/simplearrayinterface.publisher.h"
#include "tb_simple/generated/core/simplearrayinterface.data.h"

using namespace Test::TbSimple;

SimpleArrayInterface::SimpleArrayInterface()
    : m_publisher(std::make_unique<SimpleArrayInterfacePublisher>()) 
{
}
SimpleArrayInterface::~SimpleArrayInterface()
{
}

void SimpleArrayInterface::setPropBool(const std::list<bool>& propBool)
{
    if (m_data.m_propBool != propBool) {
        m_data.m_propBool = propBool;
        m_publisher->publishPropBoolChanged(propBool);
    }
}

const std::list<bool>& SimpleArrayInterface::propBool() const
{
    return m_data.m_propBool;
}

void SimpleArrayInterface::setPropInt(const std::list<int>& propInt)
{
    if (m_data.m_propInt != propInt) {
        m_data.m_propInt = propInt;
        m_publisher->publishPropIntChanged(propInt);
    }
}

const std::list<int>& SimpleArrayInterface::propInt() const
{
    return m_data.m_propInt;
}

void SimpleArrayInterface::setPropFloat(const std::list<float>& propFloat)
{
    if (m_data.m_propFloat != propFloat) {
        m_data.m_propFloat = propFloat;
        m_publisher->publishPropFloatChanged(propFloat);
    }
}

const std::list<float>& SimpleArrayInterface::propFloat() const
{
    return m_data.m_propFloat;
}

void SimpleArrayInterface::setPropString(const std::list<std::string>& propString)
{
    if (m_data.m_propString != propString) {
        m_data.m_propString = propString;
        m_publisher->publishPropStringChanged(propString);
    }
}

const std::list<std::string>& SimpleArrayInterface::propString() const
{
    return m_data.m_propString;
}

std::list<bool> SimpleArrayInterface::funcBool(const std::list<bool>& paramBool)
{
    (void) paramBool; //suppress the 'Unreferenced Formal Parameter' warning.
    // do business logic here
    return {};
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

std::list<int> SimpleArrayInterface::funcInt(const std::list<int>& paramInt)
{
    (void) paramInt; //suppress the 'Unreferenced Formal Parameter' warning.
    // do business logic here
    return {};
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

std::list<float> SimpleArrayInterface::funcFloat(const std::list<float>& paramFloat)
{
    (void) paramFloat; //suppress the 'Unreferenced Formal Parameter' warning.
    // do business logic here
    return {};
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

std::list<std::string> SimpleArrayInterface::funcString(const std::list<std::string>& paramString)
{
    (void) paramString; //suppress the 'Unreferenced Formal Parameter' warning.
    // do business logic here
    return {};
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

ISimpleArrayInterfacePublisher& SimpleArrayInterface::_getPublisher() const
{
    return *m_publisher;
}
