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
#include <memory>
#include "generated/api/org_objectapi_testbed.h"
#include "generated/api/org_objectapi_testbed_common.h"

namespace Test {
namespace OrgObjectapiTestbed {

class TEST_ORG_OBJECTAPI_TESTBED_EXPORT Interface2 : public IInterface2
{
public:
    explicit Interface2();
    ~Interface2();
public:
    // property prop200
    void setProp200(int prop200) override;
    int prop200() const override;
    
    // property prop201
    void setProp201(int prop201) override;
    int prop201() const override;
    
    // property prop202
    void setProp202(int prop202) override;
    int prop202() const override;
    
    // property prop203
    void setProp203(float prop203) override;
    float prop203() const override;
    
    // property prop204
    void setProp204(float prop204) override;
    float prop204() const override;
    
    // property prop205
    void setProp205(const std::string& prop205) override;
    std::string prop205() const override;
    
    // operations

    IInterface2Publisher* _getPublisher() const override;
private:
    struct Interface2Data;
    std::unique_ptr<Interface2Data> d_ptr;
};
} // namespace OrgObjectapiTestbed
} // namespace Test
