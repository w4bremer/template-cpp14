#pragma once

#include "generated/api/testbed2.h"

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

class NestedStruct1InterfaceTracer
{
public:
  NestedStruct1InterfaceTracer(ApiGear::PocoImpl::Tracer* tracer);
  virtual ~NestedStruct1InterfaceTracer() = default;
  
  void capture_state(INestedStruct1Interface* obj);
  void trace_func1(const NestedStruct1& param1);
private:
  ApiGear::PocoImpl::Tracer* m_tracer;
};

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

class NestedStruct3InterfaceTracer
{
public:
  NestedStruct3InterfaceTracer(ApiGear::PocoImpl::Tracer* tracer);
  virtual ~NestedStruct3InterfaceTracer() = default;
  
  void capture_state(INestedStruct3Interface* obj);
  void trace_func1(const NestedStruct1& param1);
  void trace_func2(const NestedStruct1& param1, const NestedStruct2& param2);
  void trace_func3(const NestedStruct1& param1, const NestedStruct2& param2, const NestedStruct3& param3);
private:
  ApiGear::PocoImpl::Tracer* m_tracer;
};
} // namespace Testbed2
} // namespace Test
