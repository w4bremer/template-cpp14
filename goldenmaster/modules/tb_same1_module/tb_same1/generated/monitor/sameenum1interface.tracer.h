#pragma once

#include "tb_same1/generated/api/tb_same1.h"

namespace ApiGear { namespace PocoImpl { class Tracer; } }

namespace Test {
namespace TbSame1 {

class SameEnum1InterfaceTracer
{
public:
  SameEnum1InterfaceTracer(ApiGear::PocoImpl::Tracer* tracer);
  virtual ~SameEnum1InterfaceTracer() = default;
  
  void capture_state(ISameEnum1Interface* obj);
  void trace_func1(const Enum1Enum& param1);
private:
  ApiGear::PocoImpl::Tracer* m_tracer;
};

} // namespace TbSame1
} // namespace Test