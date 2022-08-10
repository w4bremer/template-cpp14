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
#include "tb_same1/generated/core/samestruct1interface.data.h"
#include <memory>

namespace Test {
namespace TbSame1 {

/**
* The SameStruct1Interface implementation.
*/
class TEST_TB_SAME1_EXPORT SameStruct1Interface : public ISameStruct1Interface
{
public:
    explicit SameStruct1Interface();
    ~SameStruct1Interface();
public:
    void setProp1(const Struct1& prop1) override;
    const Struct1& prop1() const override;
    
    Struct1 func1(const Struct1& param1) override;
    std::future<Struct1> func1Async(const Struct1& param1) override;
        
    /**
    * Access to a publisher, use it to subscribe for SameStruct1Interface changes and signal emission.
    * @return The publisher for SameStruct1Interface.
    */
    ISameStruct1InterfacePublisher& _getPublisher() const override;
private:
    /** The publisher for the SameStruct1Interface. */
    std::unique_ptr<ISameStruct1InterfacePublisher> m_publisher;
    /** The helper structure to store all the properties for SameStruct1Interface. */
    SameStruct1InterfaceData m_data;
};
} // namespace TbSame1
} // namespace Test
