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
#include "testbed2/generated/api/testbed2.h"
#include "testbed2/generated/api/common.h"
#include "testbed2/generated/core/nestedstruct1interface.decorator.h"

namespace ApiGear { namespace PocoImpl { class Tracer; } }

namespace Test {
namespace Testbed2 {

class NestedStruct1InterfaceTracer;

class TEST_TESTBED2_EXPORT NestedStruct1InterfaceTracerDecorator : public AbstractNestedStruct1InterfaceDecorator
{
protected:
    explicit NestedStruct1InterfaceTracerDecorator(INestedStruct1Interface* impl, ApiGear::PocoImpl::Tracer* tracer);
public:
    static NestedStruct1InterfaceTracerDecorator* connect(INestedStruct1Interface* impl, ApiGear::PocoImpl::Tracer* tracer);
    virtual ~NestedStruct1InterfaceTracerDecorator();

    // operations
    NestedStruct1 func1(const NestedStruct1& param1) override;
    std::future<NestedStruct1> func1Async(const NestedStruct1& param1) override;
public: // INestedStruct1InterfaceSubscriber interface
    void OnSig1(const NestedStruct1& param1) override;
    void OnProp1Changed(const NestedStruct1& Value) override;
private:
    std::unique_ptr<NestedStruct1InterfaceTracer> m_tracer;
};
} // namespace Testbed2
} // namespace Test
