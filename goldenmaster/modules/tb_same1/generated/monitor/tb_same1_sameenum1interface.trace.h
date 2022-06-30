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
#include "generated/core/tb_same1_sameenum1interface.decorator.h"

namespace ApiGear { namespace PocoImpl { class Tracer; } }

namespace Test {
namespace TbSame1 {

class SameEnum1InterfaceTracer;

class TEST_TB_SAME1_EXPORT SameEnum1InterfaceTracerDecorator : public AbstractSameEnum1InterfaceDecorator
{
protected:
    explicit SameEnum1InterfaceTracerDecorator(ISameEnum1Interface* impl, ApiGear::PocoImpl::Tracer* tracer);
public:
    static SameEnum1InterfaceTracerDecorator* connect(ISameEnum1Interface* impl, ApiGear::PocoImpl::Tracer* tracer);
    virtual ~SameEnum1InterfaceTracerDecorator();

    // operations
    Enum1Enum func1(const Enum1Enum& param1) override;
    std::future<Enum1Enum> func1Async(const Enum1Enum& param1) override;
public: // ISameEnum1InterfaceSubscriber interface
    void OnSig1(const Enum1Enum& param1) override;
    void OnProp1Changed(const Enum1Enum& Value) override;
private:
    std::unique_ptr<SameEnum1InterfaceTracer> m_tracer;
};
} // namespace TbSame1
} // namespace Test
