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
#include "generated/api/testbed2.h"
#include "generated/api/testbed2_common.h"
#include "generated/core/testbed2_nestedstruct3interface.decorator.h"

namespace ApiGear { namespace PocoImpl { class Tracer; } }

namespace Test {
namespace Testbed2 {

class NestedStruct3InterfaceTracer;

class TEST_TESTBED2_EXPORT NestedStruct3InterfaceTracerDecorator : public AbstractNestedStruct3InterfaceDecorator
{
protected:
    explicit NestedStruct3InterfaceTracerDecorator(INestedStruct3Interface* impl, ApiGear::PocoImpl::Tracer* tracer);
public:
    static NestedStruct3InterfaceTracerDecorator* connect(INestedStruct3Interface* impl, ApiGear::PocoImpl::Tracer* tracer);
    virtual ~NestedStruct3InterfaceTracerDecorator();

    // operations
    NestedStruct1 func1(const NestedStruct1& param1) override;
    std::future<NestedStruct1> func1Async(const NestedStruct1& param1) override;
    NestedStruct1 func2(const NestedStruct1& param1, const NestedStruct2& param2) override;
    std::future<NestedStruct1> func2Async(const NestedStruct1& param1, const NestedStruct2& param2) override;
    NestedStruct1 func3(const NestedStruct1& param1, const NestedStruct2& param2, const NestedStruct3& param3) override;
    std::future<NestedStruct1> func3Async(const NestedStruct1& param1, const NestedStruct2& param2, const NestedStruct3& param3) override;
public: // INestedStruct3InterfaceSubscriber interface
    void OnSig1(const NestedStruct1& param1) override;
    void OnSig2(const NestedStruct1& param1,const NestedStruct2& param2) override;
    void OnSig3(const NestedStruct1& param1,const NestedStruct2& param2,const NestedStruct3& param3) override;
    void OnProp1Changed(const NestedStruct1& Value) override;
    void OnProp2Changed(const NestedStruct2& Value) override;
    void OnProp3Changed(const NestedStruct3& Value) override;
private:
    std::unique_ptr<NestedStruct3InterfaceTracer> m_tracer;
};
} // namespace Testbed2
} // namespace Test
