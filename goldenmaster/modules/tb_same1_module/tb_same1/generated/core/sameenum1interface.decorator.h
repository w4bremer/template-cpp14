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

#pragma once
#include "tb_same1/generated/api/tb_same1.h"
#include "tb_same1/generated/api/common.h"

namespace Test {
namespace TbSame1 {

class TEST_TB_SAME1_EXPORT AbstractSameEnum1InterfaceDecorator : public ISameEnum1Interface, public ISameEnum1InterfaceSubscriber {
public:
    explicit AbstractSameEnum1InterfaceDecorator(ISameEnum1Interface* impl);
    ISameEnum1Interface* swapUnderlyingImplementation(ISameEnum1Interface* impl);
    ISameEnum1Interface* disconnectFromUnderlyingImplementation();
    virtual ~AbstractSameEnum1InterfaceDecorator();
public:
    // property prop1
    void setProp1(const Enum1Enum& prop1) override;
    const Enum1Enum& prop1() const override;
    
    // operations
    Enum1Enum func1(const Enum1Enum& param1) override;
    std::future<Enum1Enum> func1Async(const Enum1Enum& param1) override;

    ISameEnum1InterfacePublisher& _getPublisher() const override;
private:
    ISameEnum1Interface* m_impl {nullptr};
};
} // namespace TbSame1
} // namespace Test
