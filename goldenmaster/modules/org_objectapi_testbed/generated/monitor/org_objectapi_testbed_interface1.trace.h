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
#include "generated/api/org_objectapi_testbed.h"
#include "generated/api/org_objectapi_testbed_common.h"
#include "generated/core/org_objectapi_testbed_interface1.decorator.h"

namespace ApiGear { namespace PocoImpl { class Tracer; } }

namespace Test {
namespace OrgObjectapiTestbed {

class Interface1Tracer;

class TEST_ORG_OBJECTAPI_TESTBED_EXPORT Interface1TracerDecorator : public AbstractInterface1Decorator
{
protected:
    explicit Interface1TracerDecorator(IInterface1* impl, ApiGear::PocoImpl::Tracer* tracer);
public:
    static Interface1TracerDecorator* connect(IInterface1* impl, ApiGear::PocoImpl::Tracer* tracer);
    virtual ~Interface1TracerDecorator();

    // operations
    void op1() override;
    std::future<void> op1Async() override;
    void op2(int step) override;
    std::future<void> op2Async(int step) override;
    int op3() override;
    std::future<int> op3Async() override;
public: // IInterface1Subscriber interface
    void OnSig1() override;
    void OnSig2(int step) override;
    void OnSig3() override;
    void OnProp1Changed(bool Value) override;
    void OnProp2Changed(int Value) override;
    void OnProp3Changed(float Value) override;
    void OnProp4Changed(std::string Value) override;
    void OnProp5Changed(const std::list<int>& Value) override;
    void OnProp6Changed(const Struct1& Value) override;
    void OnProp7Changed(int Value) override;
    void OnProp10Changed(const std::list<int>& Value) override;
    void OnProp11Changed(const std::list<Struct1>& Value) override;
    void OnProp12Changed(const std::list<Enum1Enum>& Value) override;
    void OnProp14Changed(const std::list<Struct1>& Value) override;
private:
    std::unique_ptr<Interface1Tracer> m_tracer;
};
} // namespace OrgObjectapiTestbed
} // namespace Test
