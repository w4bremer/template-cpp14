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
#include "tb_simple/generated/core/simpleinterface.decorator.h"

namespace ApiGear { namespace PocoImpl { class Tracer; } }

namespace Test {
namespace TbSimple {

class SimpleInterfaceTracer;

class TEST_TB_SIMPLE_EXPORT SimpleInterfaceTracerDecorator : public AbstractSimpleInterfaceDecorator
{
protected:
    explicit SimpleInterfaceTracerDecorator(ISimpleInterface* impl, ApiGear::PocoImpl::Tracer* tracer);
public:
    static SimpleInterfaceTracerDecorator* connect(ISimpleInterface* impl, ApiGear::PocoImpl::Tracer* tracer);
    virtual ~SimpleInterfaceTracerDecorator();

    // operations
    bool funcBool(bool paramBool) override;
    std::future<bool> funcBoolAsync(bool paramBool) override;
    int funcInt(int paramInt) override;
    std::future<int> funcIntAsync(int paramInt) override;
    float funcFloat(float paramFloat) override;
    std::future<float> funcFloatAsync(float paramFloat) override;
    std::string funcString(const std::string& paramString) override;
    std::future<std::string> funcStringAsync(const std::string& paramString) override;
public: // ISimpleInterfaceSubscriber interface
    void OnSigBool(bool paramBool) override;
    void OnSigInt(int paramInt) override;
    void OnSigFloat(float paramFloat) override;
    void OnSigString(const std::string& paramString) override;
    void OnPropBoolChanged(bool Value) override;
    void OnPropIntChanged(int Value) override;
    void OnPropFloatChanged(float Value) override;
    void OnPropStringChanged(std::string Value) override;
private:
    std::unique_ptr<SimpleInterfaceTracer> m_tracer;
};
} // namespace TbSimple
} // namespace Test
