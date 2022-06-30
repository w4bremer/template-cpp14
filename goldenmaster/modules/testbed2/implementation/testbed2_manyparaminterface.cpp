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


#include "testbed2_manyparaminterface.h"
#include "generated/core/testbed2_manyparaminterface.publisher.h"

using namespace Test::Testbed2;

struct ManyParamInterface::ManyParamInterfaceData
{
    ManyParamInterfaceData()
    : _publisher(std::make_unique<ManyParamInterfacePublisher>())
    , m_prop1(0)
    , m_prop2(0)
    , m_prop3(0)
    , m_prop4(0)
    {
    }
    std::unique_ptr<IManyParamInterfacePublisher> _publisher;
    int m_prop1;
    int m_prop2;
    int m_prop3;
    int m_prop4;

    ~ManyParamInterfaceData() = default;
};
/**
   \brief 
*/
ManyParamInterface::ManyParamInterface()
    : d_ptr(std::make_unique<ManyParamInterface::ManyParamInterfaceData>())
{
}
ManyParamInterface::~ManyParamInterface()
{
}
void ManyParamInterface::setProp1(int prop1)
{
    if (d_ptr->m_prop1 != prop1) {
        d_ptr->m_prop1 = prop1;
        d_ptr->_publisher->publishProp1Changed(prop1);
    }
}

int ManyParamInterface::prop1() const
{
    return d_ptr->m_prop1;
}
void ManyParamInterface::setProp2(int prop2)
{
    if (d_ptr->m_prop2 != prop2) {
        d_ptr->m_prop2 = prop2;
        d_ptr->_publisher->publishProp2Changed(prop2);
    }
}

int ManyParamInterface::prop2() const
{
    return d_ptr->m_prop2;
}
void ManyParamInterface::setProp3(int prop3)
{
    if (d_ptr->m_prop3 != prop3) {
        d_ptr->m_prop3 = prop3;
        d_ptr->_publisher->publishProp3Changed(prop3);
    }
}

int ManyParamInterface::prop3() const
{
    return d_ptr->m_prop3;
}
void ManyParamInterface::setProp4(int prop4)
{
    if (d_ptr->m_prop4 != prop4) {
        d_ptr->m_prop4 = prop4;
        d_ptr->_publisher->publishProp4Changed(prop4);
    }
}

int ManyParamInterface::prop4() const
{
    return d_ptr->m_prop4;
}
/**
   \brief 
*/
int ManyParamInterface::func1(int param1)
{
    (void) param1;
    // do business logic here
    return 0;
}

std::future<int> ManyParamInterface::func1Async(int param1)
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
int ManyParamInterface::func2(int param1, int param2)
{
    (void) param1;
    (void) param2;
    // do business logic here
    return 0;
}

std::future<int> ManyParamInterface::func2Async(int param1, int param2)
{
    return std::async(std::launch::async, [this,
                    param1,
                    param2]()
        {
            return func2(param1,param2);
        }
    );
}
/**
   \brief 
*/
int ManyParamInterface::func3(int param1, int param2, int param3)
{
    (void) param1;
    (void) param2;
    (void) param3;
    // do business logic here
    return 0;
}

std::future<int> ManyParamInterface::func3Async(int param1, int param2, int param3)
{
    return std::async(std::launch::async, [this,
                    param1,
                    param2,
                    param3]()
        {
            return func3(param1,param2,param3);
        }
    );
}
/**
   \brief 
*/
int ManyParamInterface::func4(int param1, int param2, int param3, int param4)
{
    (void) param1;
    (void) param2;
    (void) param3;
    (void) param4;
    // do business logic here
    return 0;
}

std::future<int> ManyParamInterface::func4Async(int param1, int param2, int param3, int param4)
{
    return std::async(std::launch::async, [this,
                    param1,
                    param2,
                    param3,
                    param4]()
        {
            return func4(param1,param2,param3,param4);
        }
    );
}

IManyParamInterfacePublisher* ManyParamInterface::_getPublisher() const
{
    return d_ptr->_publisher.get();
}
