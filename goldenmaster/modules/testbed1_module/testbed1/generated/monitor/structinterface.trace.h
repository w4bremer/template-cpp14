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
#include "testbed1/generated/core/structinterface.decorator.h"

namespace ApiGear { namespace PocoImpl { class Tracer; } }

namespace Test {
namespace Testbed1 {

class StructInterfaceTracer;

class TEST_TESTBED1_EXPORT StructInterfaceTracerDecorator : public AbstractStructInterfaceDecorator
{
protected:
    explicit StructInterfaceTracerDecorator(IStructInterface* impl, ApiGear::PocoImpl::Tracer& tracer);
public:
    static StructInterfaceTracerDecorator* connect(IStructInterface* impl, ApiGear::PocoImpl::Tracer& tracer);
    virtual ~StructInterfaceTracerDecorator();

    // operations
    StructBool funcBool(const StructBool& paramBool) override;
    std::future<StructBool> funcBoolAsync(const StructBool& paramBool) override;
    StructBool funcInt(const StructInt& paramInt) override;
    std::future<StructBool> funcIntAsync(const StructInt& paramInt) override;
    StructFloat funcFloat(const StructFloat& paramFloat) override;
    std::future<StructFloat> funcFloatAsync(const StructFloat& paramFloat) override;
    StructString funcString(const StructString& paramString) override;
    std::future<StructString> funcStringAsync(const StructString& paramString) override;
public: // IStructInterfaceSubscriber interface
    void onSigBool(const StructBool& paramBool) override;
    void onSigInt(const StructInt& paramInt) override;
    void onSigFloat(const StructFloat& paramFloat) override;
    void onSigString(const StructString& paramString) override;
    void onPropBoolChanged(const StructBool& Value) override;
    void onPropIntChanged(const StructInt& Value) override;
    void onPropFloatChanged(const StructFloat& Value) override;
    void onPropStringChanged(const StructString& Value) override;
private:
    std::unique_ptr<StructInterfaceTracer> m_tracer;
};
} // namespace Testbed1
} // namespace Test
