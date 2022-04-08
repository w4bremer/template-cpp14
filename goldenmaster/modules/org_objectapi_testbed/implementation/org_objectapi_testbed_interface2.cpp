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


#include "org_objectapi_testbed_interface2.h"
#include "generated/core/org_objectapi_testbed_interface2.publisher.h"

using namespace Test::OrgObjectapiTestbed;

struct Interface2::Interface2Data
{
    Interface2Data()
    : _publisher(std::make_unique<Interface2Publisher>())
    , m_prop200(0)
    , m_prop201(0)
    , m_prop202(0)
    , m_prop203(0.0f)
    , m_prop204(0.0f)
    , m_prop205(std::string())
    {
    }
    std::unique_ptr<IInterface2Publisher> _publisher;
    int m_prop200;
    int m_prop201;
    int m_prop202;
    float m_prop203;
    float m_prop204;
    std::string m_prop205;

    ~Interface2Data() = default;
};
/**
   \brief 
*/
Interface2::Interface2()
    : d_ptr(std::make_unique<Interface2::Interface2Data>())
{
}
Interface2::~Interface2()
{
}
void Interface2::setProp200(int prop200)
{
    if (d_ptr->m_prop200 != prop200) {
        d_ptr->m_prop200 = prop200;
        d_ptr->_publisher->publishProp200Changed(prop200);
    }
}

int Interface2::prop200() const
{
    return d_ptr->m_prop200;
}
void Interface2::setProp201(int prop201)
{
    if (d_ptr->m_prop201 != prop201) {
        d_ptr->m_prop201 = prop201;
        d_ptr->_publisher->publishProp201Changed(prop201);
    }
}

int Interface2::prop201() const
{
    return d_ptr->m_prop201;
}
void Interface2::setProp202(int prop202)
{
    if (d_ptr->m_prop202 != prop202) {
        d_ptr->m_prop202 = prop202;
        d_ptr->_publisher->publishProp202Changed(prop202);
    }
}

int Interface2::prop202() const
{
    return d_ptr->m_prop202;
}
void Interface2::setProp203(float prop203)
{
    if (d_ptr->m_prop203 != prop203) {
        d_ptr->m_prop203 = prop203;
        d_ptr->_publisher->publishProp203Changed(prop203);
    }
}

float Interface2::prop203() const
{
    return d_ptr->m_prop203;
}
void Interface2::setProp204(float prop204)
{
    if (d_ptr->m_prop204 != prop204) {
        d_ptr->m_prop204 = prop204;
        d_ptr->_publisher->publishProp204Changed(prop204);
    }
}

float Interface2::prop204() const
{
    return d_ptr->m_prop204;
}
void Interface2::setProp205(const std::string& prop205)
{
    if (d_ptr->m_prop205 != prop205) {
        d_ptr->m_prop205 = prop205;
        d_ptr->_publisher->publishProp205Changed(prop205);
    }
}

std::string Interface2::prop205() const
{
    return d_ptr->m_prop205;
}

IInterface2Publisher* Interface2::_getPublisher() const
{
    return d_ptr->_publisher.get();
}
