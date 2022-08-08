#pragma once

#include "tb_simple/generated/api/tb_simple.h"

namespace ApiGear { namespace PocoImpl { class Tracer; } }

namespace Test {
namespace TbSimple {

class SimpleInterfaceTracer
{
public:
  SimpleInterfaceTracer(ApiGear::PocoImpl::Tracer* tracer);
  virtual ~SimpleInterfaceTracer() = default;
  
  void capture_state(ISimpleInterface* obj);
  void trace_funcBool(bool paramBool);
  void trace_funcInt(int paramInt);
  void trace_funcFloat(float paramFloat);
  void trace_funcString(const std::string& paramString);
private:
  ApiGear::PocoImpl::Tracer* m_tracer;
};

} // namespace TbSimple
} // namespace Test
