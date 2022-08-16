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
#include "testbed1/generated/core/structarrayinterface.data.h"

using namespace Test::Testbed1;

StructArrayInterface::StructArrayInterface()
    : m_publisher(std::make_unique<StructArrayInterfacePublisher>())
{
}
StructArrayInterface::~StructArrayInterface()
{
}

void StructArrayInterface::setPropBool(const std::list<StructBool>& propBool)
{
    if (m_data.m_propBool != propBool) {
        m_data.m_propBool = propBool;
        m_publisher->publishPropBoolChanged(propBool);
    }
}

const std::list<StructBool>& StructArrayInterface::propBool() const
{
    return m_data.m_propBool;
}

void StructArrayInterface::setPropInt(const std::list<StructInt>& propInt)
{
    if (m_data.m_propInt != propInt) {
        m_data.m_propInt = propInt;
        m_publisher->publishPropIntChanged(propInt);
    }
}

const std::list<StructInt>& StructArrayInterface::propInt() const
{
    return m_data.m_propInt;
}

void StructArrayInterface::setPropFloat(const std::list<StructFloat>& propFloat)
{
    if (m_data.m_propFloat != propFloat) {
        m_data.m_propFloat = propFloat;
        m_publisher->publishPropFloatChanged(propFloat);
    }
}

const std::list<StructFloat>& StructArrayInterface::propFloat() const
{
    return m_data.m_propFloat;
}

void StructArrayInterface::setPropString(const std::list<StructString>& propString)
{
    if (m_data.m_propString != propString) {
        m_data.m_propString = propString;
        m_publisher->publishPropStringChanged(propString);
    }
}

const std::list<StructString>& StructArrayInterface::propString() const
{
    return m_data.m_propString;
}

StructBool StructArrayInterface::funcBool(const std::list<StructBool>& paramBool)
{
    (void) paramBool; // suppress the 'Unreferenced Formal Parameter' warning.
    // do business logic here
    return {};
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

StructBool StructArrayInterface::funcInt(const std::list<StructInt>& paramInt)
{
    (void) paramInt; // suppress the 'Unreferenced Formal Parameter' warning.
    // do business logic here
    return {};
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

StructBool StructArrayInterface::funcFloat(const std::list<StructFloat>& paramFloat)
{
    (void) paramFloat; // suppress the 'Unreferenced Formal Parameter' warning.
    // do business logic here
    return {};
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

StructBool StructArrayInterface::funcString(const std::list<StructString>& paramString)
{
    (void) paramString; // suppress the 'Unreferenced Formal Parameter' warning.
    // do business logic here
    return {};
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

IStructArrayInterfacePublisher& StructArrayInterface::_getPublisher() const
{
    return *m_publisher;
}
