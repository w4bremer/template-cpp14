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
#include "tb_same2/generated/core/sameenum2interface.decorator.h"

namespace ApiGear { namespace PocoImpl { class Tracer; } }

namespace Test {
namespace TbSame2 {

class SameEnum2InterfaceTracer;

class TEST_TB_SAME2_EXPORT SameEnum2InterfaceTracerDecorator : public AbstractSameEnum2InterfaceDecorator
{
protected:
    explicit SameEnum2InterfaceTracerDecorator(ISameEnum2Interface* impl, ApiGear::PocoImpl::Tracer* tracer);
public:
    static SameEnum2InterfaceTracerDecorator* connect(ISameEnum2Interface* impl, ApiGear::PocoImpl::Tracer* tracer);
    virtual ~SameEnum2InterfaceTracerDecorator();

    // operations
    Enum1Enum func1(const Enum1Enum& param1) override;
    std::future<Enum1Enum> func1Async(const Enum1Enum& param1) override;
    Enum1Enum func2(const Enum1Enum& param1, const Enum2Enum& param2) override;
    std::future<Enum1Enum> func2Async(const Enum1Enum& param1, const Enum2Enum& param2) override;
public: // ISameEnum2InterfaceSubscriber interface
    void OnSig1(const Enum1Enum& param1) override;
    void OnSig2(const Enum1Enum& param1,const Enum2Enum& param2) override;
    void OnProp1Changed(const Enum1Enum& Value) override;
    void OnProp2Changed(const Enum2Enum& Value) override;
private:
    std::unique_ptr<SameEnum2InterfaceTracer> m_tracer;
};
} // namespace TbSame2
} // namespace Test
