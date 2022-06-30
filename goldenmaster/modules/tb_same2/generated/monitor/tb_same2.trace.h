#pragma once

#include "generated/api/tb_same2.h"

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

class SameEnum2InterfaceTracer
{
public:
  SameEnum2InterfaceTracer(ApiGear::PocoImpl::Tracer* tracer);
  virtual ~SameEnum2InterfaceTracer() = default;
  
  void capture_state(ISameEnum2Interface* obj);
  void trace_func1(const Enum1Enum& param1);
  void trace_func2(const Enum1Enum& param1, const Enum2Enum& param2);
private:
  ApiGear::PocoImpl::Tracer* m_tracer;
};
} // namespace TbSame2
} // namespace Test
