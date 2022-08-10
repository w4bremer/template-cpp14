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

namespace Test {
namespace Testbed1 {

class TEST_TESTBED1_EXPORT AbstractStructInterfaceDecorator : public IStructInterface, public IStructInterfaceSubscriber {
public:
    explicit AbstractStructInterfaceDecorator(IStructInterface* impl);
    IStructInterface* swapUnderlyingImplementation(IStructInterface* impl);
    IStructInterface* disconnectFromUnderlyingImplementation();
    virtual ~AbstractStructInterfaceDecorator();
public:
    // property propBool
    void setPropBool(const StructBool& propBool) override;
    const StructBool& propBool() const override;
    
    // property propInt
    void setPropInt(const StructInt& propInt) override;
    const StructInt& propInt() const override;
    
    // property propFloat
    void setPropFloat(const StructFloat& propFloat) override;
    const StructFloat& propFloat() const override;
    
    // property propString
    void setPropString(const StructString& propString) override;
    const StructString& propString() const override;
    
    // operations
    StructBool funcBool(const StructBool& paramBool) override;
    std::future<StructBool> funcBoolAsync(const StructBool& paramBool) override;
    StructBool funcInt(const StructInt& paramInt) override;
    std::future<StructBool> funcIntAsync(const StructInt& paramInt) override;
    StructFloat funcFloat(const StructFloat& paramFloat) override;
    std::future<StructFloat> funcFloatAsync(const StructFloat& paramFloat) override;
    StructString funcString(const StructString& paramString) override;
    std::future<StructString> funcStringAsync(const StructString& paramString) override;

    IStructInterfacePublisher& _getPublisher() const override;
private:
    IStructInterface* m_impl {nullptr};
};
} // namespace Testbed1
} // namespace Test
