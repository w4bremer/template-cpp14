#pragma once

#include "tb_simple/generated/api/tb_simple.h"

namespace ApiGear { namespace PocoImpl { class Tracer; } }

namespace Test {
namespace TbSimple {

class SimpleArrayInterfaceTracer
{
public:
  SimpleArrayInterfaceTracer(ApiGear::PocoImpl::Tracer* tracer);
  virtual ~SimpleArrayInterfaceTracer() = default;
  
  void capture_state(ISimpleArrayInterface* obj);
  void trace_funcBool(const std::list<bool>& paramBool);
  void trace_funcInt(const std::list<int>& paramInt);
  void trace_funcFloat(const std::list<float>& paramFloat);
  void trace_funcString(const std::list<std::string>& paramString);
private:
  ApiGear::PocoImpl::Tracer* m_tracer;
};

} // namespace TbSimple
} // namespace Test
