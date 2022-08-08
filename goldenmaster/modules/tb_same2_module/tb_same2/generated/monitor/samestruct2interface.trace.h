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
#include "tb_same2/generated/api/tb_same2.h"
#include "tb_same2/generated/api/common.h"
#include "tb_same2/generated/core/samestruct2interface.decorator.h"

namespace ApiGear { namespace PocoImpl { class Tracer; } }

namespace Test {
namespace TbSame2 {

class SameStruct2InterfaceTracer;

class TEST_TB_SAME2_EXPORT SameStruct2InterfaceTracerDecorator : public AbstractSameStruct2InterfaceDecorator
{
protected:
    explicit SameStruct2InterfaceTracerDecorator(ISameStruct2Interface* impl, ApiGear::PocoImpl::Tracer* tracer);
public:
    static SameStruct2InterfaceTracerDecorator* connect(ISameStruct2Interface* impl, ApiGear::PocoImpl::Tracer* tracer);
    virtual ~SameStruct2InterfaceTracerDecorator();

    // operations
    Struct1 func1(const Struct1& param1) override;
    std::future<Struct1> func1Async(const Struct1& param1) override;
    Struct1 func2(const Struct1& param1, const Struct2& param2) override;
    std::future<Struct1> func2Async(const Struct1& param1, const Struct2& param2) override;
public: // ISameStruct2InterfaceSubscriber interface
    void OnSig1(const Struct1& param1) override;
    void OnSig2(const Struct1& param1,const Struct2& param2) override;
    void OnProp1Changed(const Struct2& Value) override;
    void OnProp2Changed(const Struct2& Value) override;
private:
    std::unique_ptr<SameStruct2InterfaceTracer> m_tracer;
};
} // namespace TbSame2
} // namespace Test
