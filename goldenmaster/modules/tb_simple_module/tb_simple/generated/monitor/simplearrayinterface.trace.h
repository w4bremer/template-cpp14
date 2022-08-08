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
#include "tb_simple/generated/api/tb_simple.h"
#include "tb_simple/generated/api/common.h"
#include "tb_simple/generated/core/simplearrayinterface.decorator.h"

namespace ApiGear { namespace PocoImpl { class Tracer; } }

namespace Test {
namespace TbSimple {

class SimpleArrayInterfaceTracer;

class TEST_TB_SIMPLE_EXPORT SimpleArrayInterfaceTracerDecorator : public AbstractSimpleArrayInterfaceDecorator
{
protected:
    explicit SimpleArrayInterfaceTracerDecorator(ISimpleArrayInterface* impl, ApiGear::PocoImpl::Tracer* tracer);
public:
    static SimpleArrayInterfaceTracerDecorator* connect(ISimpleArrayInterface* impl, ApiGear::PocoImpl::Tracer* tracer);
    virtual ~SimpleArrayInterfaceTracerDecorator();

    // operations
    std::list<bool> funcBool(const std::list<bool>& paramBool) override;
    std::future<std::list<bool>> funcBoolAsync(const std::list<bool>& paramBool) override;
    std::list<int> funcInt(const std::list<int>& paramInt) override;
    std::future<std::list<int>> funcIntAsync(const std::list<int>& paramInt) override;
    std::list<float> funcFloat(const std::list<float>& paramFloat) override;
    std::future<std::list<float>> funcFloatAsync(const std::list<float>& paramFloat) override;
    std::list<std::string> funcString(const std::list<std::string>& paramString) override;
    std::future<std::list<std::string>> funcStringAsync(const std::list<std::string>& paramString) override;
public: // ISimpleArrayInterfaceSubscriber interface
    void OnSigBool(const std::list<bool>& paramBool) override;
    void OnSigInt(const std::list<int>& paramInt) override;
    void OnSigFloat(const std::list<float>& paramFloat) override;
    void OnSigString(const std::list<std::string>& paramString) override;
    void OnPropBoolChanged(const std::list<bool>& Value) override;
    void OnPropIntChanged(const std::list<int>& Value) override;
    void OnPropFloatChanged(const std::list<float>& Value) override;
    void OnPropStringChanged(const std::list<std::string>& Value) override;
private:
    std::unique_ptr<SimpleArrayInterfaceTracer> m_tracer;
};
} // namespace TbSimple
} // namespace Test
