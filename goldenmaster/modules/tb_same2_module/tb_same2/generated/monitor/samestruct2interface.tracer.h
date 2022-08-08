#pragma once

#include "tb_same2/generated/api/tb_same2.h"

namespace ApiGear { namespace PocoImpl { class Tracer; } }

namespace Test {
namespace TbSame2 {

class SameStruct2InterfaceTracer
{
public:
  SameStruct2InterfaceTracer(ApiGear::PocoImpl::Tracer* tracer);
  virtual ~SameStruct2InterfaceTracer() = default;
  
  void capture_state(ISameStruct2Interface* obj);
  void trace_func1(const Struct1& param1);
  void trace_func2(const Struct1& param1, const Struct2& param2);
private:
  ApiGear::PocoImpl::Tracer* m_tracer;
};

} // namespace TbSame2
} // namespace Test
