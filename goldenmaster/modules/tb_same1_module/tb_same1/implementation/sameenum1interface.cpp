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


#include "tb_same1/implementation/sameenum1interface.h"
#include "tb_same1/generated/core/sameenum1interface.publisher.h"
#include "tb_same1/generated/core/sameenum1interface.data.h"

using namespace Test::TbSame1;

SameEnum1Interface::SameEnum1Interface()
    : m_publisher(std::make_unique<SameEnum1InterfacePublisher>())
{
}
SameEnum1Interface::~SameEnum1Interface()
{
}

void SameEnum1Interface::setProp1(const Enum1Enum& prop1)
{
    if (m_data.m_prop1 != prop1) {
        m_data.m_prop1 = prop1;
        m_publisher->publishProp1Changed(prop1);
    }
}

const Enum1Enum& SameEnum1Interface::prop1() const
{
    return m_data.m_prop1;
}

Enum1Enum SameEnum1Interface::func1(const Enum1Enum& param1)
{
    (void) param1; // suppress the 'Unreferenced Formal Parameter' warning.
    // do business logic here
    return {};
}

std::future<Enum1Enum> SameEnum1Interface::func1Async(const Enum1Enum& param1)
{
    return std::async(std::launch::async, [this,
                    param1]()
        {
            return func1(param1);
        }
    );
}

ISameEnum1InterfacePublisher& SameEnum1Interface::_getPublisher() const
{
    return *m_publisher;
}
