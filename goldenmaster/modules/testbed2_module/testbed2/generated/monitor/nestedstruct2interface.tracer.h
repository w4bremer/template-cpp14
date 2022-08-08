#pragma once

#include "testbed2/generated/api/testbed2.h"

namespace ApiGear { namespace PocoImpl { class Tracer; } }

namespace Test {
namespace Testbed2 {

class NestedStruct2InterfaceTracer
{
public:
  NestedStruct2InterfaceTracer(ApiGear::PocoImpl::Tracer* tracer);
  virtual ~NestedStruct2InterfaceTracer() = default;
  
  void capture_state(INestedStruct2Interface* obj);
  void trace_func1(const NestedStruct1& param1);
  void trace_func2(const NestedStruct1& param1, const NestedStruct2& param2);
private:
  ApiGear::PocoImpl::Tracer* m_tracer;
};

} // namespace Testbed2
} // namespace Test
