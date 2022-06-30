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
#include "generated/api/tb_same1.h"
#include "generated/api/tb_same1_common.h"
#include "generated/core/tb_same1_samestruct1interface.decorator.h"

namespace ApiGear { namespace PocoImpl { class Tracer; } }

namespace Test {
namespace TbSame1 {

class SameStruct1InterfaceTracer;

class TEST_TB_SAME1_EXPORT SameStruct1InterfaceTracerDecorator : public AbstractSameStruct1InterfaceDecorator
{
protected:
    explicit SameStruct1InterfaceTracerDecorator(ISameStruct1Interface* impl, ApiGear::PocoImpl::Tracer* tracer);
public:
    static SameStruct1InterfaceTracerDecorator* connect(ISameStruct1Interface* impl, ApiGear::PocoImpl::Tracer* tracer);
    virtual ~SameStruct1InterfaceTracerDecorator();

    // operations
    Struct1 func1(const Struct1& param1) override;
    std::future<Struct1> func1Async(const Struct1& param1) override;
public: // ISameStruct1InterfaceSubscriber interface
    void OnSig1(const Struct1& param1) override;
    void OnProp1Changed(const Struct1& Value) override;
private:
    std::unique_ptr<SameStruct1InterfaceTracer> m_tracer;
};
} // namespace TbSame1
} // namespace Test
