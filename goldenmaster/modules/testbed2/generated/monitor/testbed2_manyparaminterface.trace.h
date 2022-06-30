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
#include "generated/core/testbed2_manyparaminterface.decorator.h"

namespace ApiGear { namespace PocoImpl { class Tracer; } }

namespace Test {
namespace Testbed2 {

class ManyParamInterfaceTracer;

class TEST_TESTBED2_EXPORT ManyParamInterfaceTracerDecorator : public AbstractManyParamInterfaceDecorator
{
protected:
    explicit ManyParamInterfaceTracerDecorator(IManyParamInterface* impl, ApiGear::PocoImpl::Tracer* tracer);
public:
    static ManyParamInterfaceTracerDecorator* connect(IManyParamInterface* impl, ApiGear::PocoImpl::Tracer* tracer);
    virtual ~ManyParamInterfaceTracerDecorator();

    // operations
    int func1(int param1) override;
    std::future<int> func1Async(int param1) override;
    int func2(int param1, int param2) override;
    std::future<int> func2Async(int param1, int param2) override;
    int func3(int param1, int param2, int param3) override;
    std::future<int> func3Async(int param1, int param2, int param3) override;
    int func4(int param1, int param2, int param3, int param4) override;
    std::future<int> func4Async(int param1, int param2, int param3, int param4) override;
public: // IManyParamInterfaceSubscriber interface
    void OnSig1(int param1) override;
    void OnSig2(int param1,int param2) override;
    void OnSig3(int param1,int param2,int param3) override;
    void OnSig4(int param1,int param2,int param3,int param4) override;
    void OnProp1Changed(int Value) override;
    void OnProp2Changed(int Value) override;
    void OnProp3Changed(int Value) override;
    void OnProp4Changed(int Value) override;
private:
    std::unique_ptr<ManyParamInterfaceTracer> m_tracer;
};
} // namespace Testbed2
} // namespace Test
