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
#include "generated/api/testbed2.h"
#include "generated/api/testbed2_common.h"

namespace Test {
namespace Testbed2 {

class TEST_TESTBED2_EXPORT ManyParamInterface : public IManyParamInterface
{
public:
    explicit ManyParamInterface();
    ~ManyParamInterface();
public:
    // property prop1
    void setProp1(int prop1) override;
    int prop1() const override;
    
    // property prop2
    void setProp2(int prop2) override;
    int prop2() const override;
    
    // property prop3
    void setProp3(int prop3) override;
    int prop3() const override;
    
    // property prop4
    void setProp4(int prop4) override;
    int prop4() const override;
    
    // operations
    int func1(int param1) override;
    std::future<int> func1Async(int param1) override;
    int func2(int param1, int param2) override;
    std::future<int> func2Async(int param1, int param2) override;
    int func3(int param1, int param2, int param3) override;
    std::future<int> func3Async(int param1, int param2, int param3) override;
    int func4(int param1, int param2, int param3, int param4) override;
    std::future<int> func4Async(int param1, int param2, int param3, int param4) override;

    IManyParamInterfacePublisher* _getPublisher() const override;
private:
    struct ManyParamInterfaceData;
    std::unique_ptr<ManyParamInterfaceData> d_ptr;
};
} // namespace Testbed2
} // namespace Test
