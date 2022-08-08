#pragma once

#include "testbed2/generated/api/testbed2.h"

namespace ApiGear { namespace PocoImpl { class Tracer; } }

namespace Test {
namespace Testbed2 {

class ManyParamInterfaceTracer
{
public:
  ManyParamInterfaceTracer(ApiGear::PocoImpl::Tracer* tracer);
  virtual ~ManyParamInterfaceTracer() = default;
  
  void capture_state(IManyParamInterface* obj);
  void trace_func1(int param1);
  void trace_func2(int param1, int param2);
  void trace_func3(int param1, int param2, int param3);
  void trace_func4(int param1, int param2, int param3, int param4);
private:
  ApiGear::PocoImpl::Tracer* m_tracer;
};

} // namespace Testbed2
} // namespace Test
