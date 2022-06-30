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
#include "generated/api/tb_simple.h"
#include "generated/api/tb_simple_common.h"
#include "generated/core/tb_simple_simplearrayinterface.publisher.h"

namespace Test {
namespace TbSimple {

class TEST_TB_SIMPLE_EXPORT AbstractSimpleArrayInterfaceDecorator : public ISimpleArrayInterfaceDecorator
{
public:
    explicit AbstractSimpleArrayInterfaceDecorator(ISimpleArrayInterface* impl);
    ISimpleArrayInterface* swapUnderlyingImplementation(ISimpleArrayInterface* impl) override;
    ISimpleArrayInterface* disconnectFromUnderlyingImplementation() override;
    virtual ~AbstractSimpleArrayInterfaceDecorator();
public:
    // property propBool
    void setPropbool(const std::list<bool>& propBool) override;
    const std::list<bool>& propBool() const override;
    
    // property propInt
    void setPropint(const std::list<int>& propInt) override;
    const std::list<int>& propInt() const override;
    
    // property propFloat
    void setPropfloat(const std::list<float>& propFloat) override;
    const std::list<float>& propFloat() const override;
    
    // property propString
    void setPropstring(const std::list<std::string>& propString) override;
    const std::list<std::string>& propString() const override;
    
    // operations
    std::list<bool> funcBool(const std::list<bool>& paramBool) override;
    std::future<std::list<bool>> funcBoolAsync(const std::list<bool>& paramBool) override;
    std::list<int> funcInt(const std::list<int>& paramInt) override;
    std::future<std::list<int>> funcIntAsync(const std::list<int>& paramInt) override;
    std::list<float> funcFloat(const std::list<float>& paramFloat) override;
    std::future<std::list<float>> funcFloatAsync(const std::list<float>& paramFloat) override;
    std::list<std::string> funcString(const std::list<std::string>& paramString) override;
    std::future<std::list<std::string>> funcStringAsync(const std::list<std::string>& paramString) override;

    ISimpleArrayInterfacePublisher* _getPublisher() const override;
private:
    ISimpleArrayInterface* m_impl {nullptr};
};
} // namespace TbSimple
} // namespace Test
