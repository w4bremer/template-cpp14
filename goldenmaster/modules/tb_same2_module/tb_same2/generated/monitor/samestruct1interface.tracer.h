#pragma once

#include "tb_same2/generated/api/tb_same2.h"

namespace ApiGear { namespace PocoImpl { class Tracer; } }

namespace Test {
namespace TbSame2 {

class SameStruct1InterfaceTracer
{
public:
  SameStruct1InterfaceTracer(ApiGear::PocoImpl::Tracer* tracer);
  virtual ~SameStruct1InterfaceTracer() = default;
  
  void capture_state(ISameStruct1Interface* obj);
  void trace_func1(const Struct1& param1);
private:
  ApiGear::PocoImpl::Tracer* m_tracer;
};

} // namespace TbSame2
} // namespace Test
