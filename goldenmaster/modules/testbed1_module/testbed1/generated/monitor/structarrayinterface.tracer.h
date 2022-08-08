#pragma once

#include "testbed1/generated/api/testbed1.h"

namespace ApiGear { namespace PocoImpl { class Tracer; } }

namespace Test {
namespace Testbed1 {

class StructArrayInterfaceTracer
{
public:
  StructArrayInterfaceTracer(ApiGear::PocoImpl::Tracer* tracer);
  virtual ~StructArrayInterfaceTracer() = default;
  
  void capture_state(IStructArrayInterface* obj);
  void trace_funcBool(const std::list<StructBool>& paramBool);
  void trace_funcInt(const std::list<StructInt>& paramInt);
  void trace_funcFloat(const std::list<StructFloat>& paramFloat);
  void trace_funcString(const std::list<StructString>& paramString);
private:
  ApiGear::PocoImpl::Tracer* m_tracer;
};

} // namespace Testbed1
} // namespace Test
