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
#include "generated/api/testbed1.h"
#include "generated/api/testbed1_common.h"
#include "generated/core/testbed1_structarrayinterface.decorator.h"

namespace ApiGear { namespace PocoImpl { class Tracer; } }

namespace Test {
namespace Testbed1 {

class StructArrayInterfaceTracer;

class TEST_TESTBED1_EXPORT StructArrayInterfaceTracerDecorator : public AbstractStructArrayInterfaceDecorator
{
protected:
    explicit StructArrayInterfaceTracerDecorator(IStructArrayInterface* impl, ApiGear::PocoImpl::Tracer* tracer);
public:
    static StructArrayInterfaceTracerDecorator* connect(IStructArrayInterface* impl, ApiGear::PocoImpl::Tracer* tracer);
    virtual ~StructArrayInterfaceTracerDecorator();

    // operations
    StructBool funcBool(const std::list<StructBool>& paramBool) override;
    std::future<StructBool> funcBoolAsync(const std::list<StructBool>& paramBool) override;
    StructBool funcInt(const std::list<StructInt>& paramInt) override;
    std::future<StructBool> funcIntAsync(const std::list<StructInt>& paramInt) override;
    StructBool funcFloat(const std::list<StructFloat>& paramFloat) override;
    std::future<StructBool> funcFloatAsync(const std::list<StructFloat>& paramFloat) override;
    StructBool funcString(const std::list<StructString>& paramString) override;
    std::future<StructBool> funcStringAsync(const std::list<StructString>& paramString) override;
public: // IStructArrayInterfaceSubscriber interface
    void OnSigBool(const std::list<StructBool>& paramBool) override;
    void OnSigInt(const std::list<StructInt>& paramInt) override;
    void OnSigFloat(const std::list<StructFloat>& paramFloat) override;
    void OnSigString(const std::list<StructString>& paramString) override;
    void OnPropBoolChanged(const std::list<StructBool>& Value) override;
    void OnPropIntChanged(const std::list<StructInt>& Value) override;
    void OnPropFloatChanged(const std::list<StructFloat>& Value) override;
    void OnPropStringChanged(const std::list<StructString>& Value) override;
private:
    std::unique_ptr<StructArrayInterfaceTracer> m_tracer;
};
} // namespace Testbed1
} // namespace Test
