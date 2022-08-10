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
#include "testbed1/generated/api/testbed1.h"
#include "testbed1/generated/api/common.h"
#include "testbed1/generated/core/structinterface.data.h"
#include <memory>

namespace Test {
namespace Testbed1 {

/**
* The StructInterface implementation.
*/
class TEST_TESTBED1_EXPORT StructInterface : public IStructInterface
{
public:
    explicit StructInterface();
    ~StructInterface();
public:
    void setPropBool(const StructBool& propBool) override;
    const StructBool& propBool() const override;
    
    void setPropInt(const StructInt& propInt) override;
    const StructInt& propInt() const override;
    
    void setPropFloat(const StructFloat& propFloat) override;
    const StructFloat& propFloat() const override;
    
    void setPropString(const StructString& propString) override;
    const StructString& propString() const override;
    
    StructBool funcBool(const StructBool& paramBool) override;
    std::future<StructBool> funcBoolAsync(const StructBool& paramBool) override;
        
    StructBool funcInt(const StructInt& paramInt) override;
    std::future<StructBool> funcIntAsync(const StructInt& paramInt) override;
        
    StructFloat funcFloat(const StructFloat& paramFloat) override;
    std::future<StructFloat> funcFloatAsync(const StructFloat& paramFloat) override;
        
    StructString funcString(const StructString& paramString) override;
    std::future<StructString> funcStringAsync(const StructString& paramString) override;
        
    /**
    * Access to a publisher, use it to subscribe for StructInterface changes and signal emission.
    * @return The publisher for StructInterface.
    */
    IStructInterfacePublisher& _getPublisher() const override;
private:
    /** The publisher for the StructInterface. */
    std::unique_ptr<IStructInterfacePublisher> m_publisher;
    /** The helper structure to store all the properties for StructInterface. */
    StructInterfaceData m_data;
};
} // namespace Testbed1
} // namespace Test
