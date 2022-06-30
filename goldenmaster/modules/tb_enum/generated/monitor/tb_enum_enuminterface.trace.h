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
#include "generated/api/tb_enum.h"
#include "generated/api/tb_enum_common.h"
#include "generated/core/tb_enum_enuminterface.decorator.h"

namespace ApiGear { namespace PocoImpl { class Tracer; } }

namespace Test {
namespace TbEnum {

class EnumInterfaceTracer;

class TEST_TB_ENUM_EXPORT EnumInterfaceTracerDecorator : public AbstractEnumInterfaceDecorator
{
protected:
    explicit EnumInterfaceTracerDecorator(IEnumInterface* impl, ApiGear::PocoImpl::Tracer* tracer);
public:
    static EnumInterfaceTracerDecorator* connect(IEnumInterface* impl, ApiGear::PocoImpl::Tracer* tracer);
    virtual ~EnumInterfaceTracerDecorator();

    // operations
    Enum0Enum func0(const Enum0Enum& param0) override;
    std::future<Enum0Enum> func0Async(const Enum0Enum& param0) override;
    Enum1Enum func1(const Enum1Enum& param1) override;
    std::future<Enum1Enum> func1Async(const Enum1Enum& param1) override;
    Enum2Enum func2(const Enum2Enum& param2) override;
    std::future<Enum2Enum> func2Async(const Enum2Enum& param2) override;
    Enum3Enum func3(const Enum3Enum& param3) override;
    std::future<Enum3Enum> func3Async(const Enum3Enum& param3) override;
public: // IEnumInterfaceSubscriber interface
    void OnSig0(const Enum0Enum& param0) override;
    void OnSig1(const Enum1Enum& param1) override;
    void OnSig2(const Enum2Enum& param2) override;
    void OnSig3(const Enum3Enum& param3) override;
    void OnProp0Changed(const Enum0Enum& Value) override;
    void OnProp1Changed(const Enum1Enum& Value) override;
    void OnProp2Changed(const Enum2Enum& Value) override;
    void OnProp3Changed(const Enum3Enum& Value) override;
private:
    std::unique_ptr<EnumInterfaceTracer> m_tracer;
};
} // namespace TbEnum
} // namespace Test
