#pragma once

#include "generated/api/org_objectapi_testbed.h"

namespace ApiGear { namespace PocoImpl { class Tracer; } }

namespace Test {
namespace OrgObjectapiTestbed {

class Interface1Tracer
{
public:
  Interface1Tracer(ApiGear::PocoImpl::Tracer* tracer);
  virtual ~Interface1Tracer() = default;
  
  void capture_state(IInterface1* obj);
  void trace_op1();
  void trace_op2(int step);
  void trace_op3();
private:
  ApiGear::PocoImpl::Tracer* m_tracer;
};

class Interface2Tracer
{
public:
  Interface2Tracer(ApiGear::PocoImpl::Tracer* tracer);
  virtual ~Interface2Tracer() = default;
  
  void capture_state(IInterface2* obj);
private:
  ApiGear::PocoImpl::Tracer* m_tracer;
};
} // namespace OrgObjectapiTestbed
} // namespace Test
