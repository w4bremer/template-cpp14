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
#include "generated/core/org_objectapi_testbed_interface2.decorator.h"

namespace ApiGear { namespace PocoImpl { class Tracer; } }

namespace Test {
namespace OrgObjectapiTestbed {

class Interface2Tracer;

class TEST_ORG_OBJECTAPI_TESTBED_EXPORT Interface2TracerDecorator : public AbstractInterface2Decorator
{
protected:
    explicit Interface2TracerDecorator(IInterface2* impl, ApiGear::PocoImpl::Tracer* tracer);
public:
    static Interface2TracerDecorator* connect(IInterface2* impl, ApiGear::PocoImpl::Tracer* tracer);
    virtual ~Interface2TracerDecorator();

    // operations
public: // IInterface2Subscriber interface
    void OnProp200Changed(int Value) override;
    void OnProp201Changed(int Value) override;
    void OnProp202Changed(int Value) override;
    void OnProp203Changed(float Value) override;
    void OnProp204Changed(float Value) override;
    void OnProp205Changed(std::string Value) override;
private:
    std::unique_ptr<Interface2Tracer> m_tracer;
};
} // namespace OrgObjectapiTestbed
} // namespace Test
