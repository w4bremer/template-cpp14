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

class TEST_TESTBED1_EXPORT AbstractStructArrayInterfaceDecorator : public IStructArrayInterface, public IStructArrayInterfaceSubscriber {
public:
    explicit AbstractStructArrayInterfaceDecorator(IStructArrayInterface* impl);
    IStructArrayInterface* swapUnderlyingImplementation(IStructArrayInterface* impl);
    IStructArrayInterface* disconnectFromUnderlyingImplementation();
    virtual ~AbstractStructArrayInterfaceDecorator();
public:
    // property propBool
    void setPropBool(const std::list<StructBool>& propBool) override;
    const std::list<StructBool>& propBool() const override;
    
    // property propInt
    void setPropInt(const std::list<StructInt>& propInt) override;
    const std::list<StructInt>& propInt() const override;
    
    // property propFloat
    void setPropFloat(const std::list<StructFloat>& propFloat) override;
    const std::list<StructFloat>& propFloat() const override;
    
    // property propString
    void setPropString(const std::list<StructString>& propString) override;
    const std::list<StructString>& propString() const override;
    
    // operations
    StructBool funcBool(const std::list<StructBool>& paramBool) override;
    std::future<StructBool> funcBoolAsync(const std::list<StructBool>& paramBool) override;
    StructBool funcInt(const std::list<StructInt>& paramInt) override;
    std::future<StructBool> funcIntAsync(const std::list<StructInt>& paramInt) override;
    StructBool funcFloat(const std::list<StructFloat>& paramFloat) override;
    std::future<StructBool> funcFloatAsync(const std::list<StructFloat>& paramFloat) override;
    StructBool funcString(const std::list<StructString>& paramString) override;
    std::future<StructBool> funcStringAsync(const std::list<StructString>& paramString) override;

    IStructArrayInterfacePublisher& _getPublisher() const override;
private:
    IStructArrayInterface* m_impl {nullptr};
};
} // namespace Testbed1
} // namespace Test
