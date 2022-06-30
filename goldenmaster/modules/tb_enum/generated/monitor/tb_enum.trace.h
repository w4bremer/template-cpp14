#pragma once

#include "generated/api/tb_enum.h"

namespace ApiGear { namespace PocoImpl { class Tracer; } }

namespace Test {
namespace TbEnum {

class EnumInterfaceTracer
{
public:
  EnumInterfaceTracer(ApiGear::PocoImpl::Tracer* tracer);
  virtual ~EnumInterfaceTracer() = default;
  
  void capture_state(IEnumInterface* obj);
  void trace_func0(const Enum0Enum& param0);
  void trace_func1(const Enum1Enum& param1);
  void trace_func2(const Enum2Enum& param2);
  void trace_func3(const Enum3Enum& param3);
private:
  ApiGear::PocoImpl::Tracer* m_tracer;
};
} // namespace TbEnum
} // namespace Test
