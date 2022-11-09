#pragma once

#include "tb_same1/generated/api/tb_same1.h"

namespace ApiGear { namespace PocoImpl { class Tracer; } }

namespace Test {
namespace TbSame1 {

/**
* A helper class for tracing.
* Builds the trace info with state and operations specific for SameStruct2Interface and pass to PocoImpl::Tracer.
*/
class SameStruct2InterfaceTracer
{
public:
  /**
  * ctor
  * @param tracer A tracer object to which the information about the state and operations is put.
  */
  SameStruct2InterfaceTracer(ApiGear::PocoImpl::Tracer& tracer);
  /** dtor */
  virtual ~SameStruct2InterfaceTracer() = default;
  /**
  * Prepares the SameStruct2Interface object state in a nlohmann::json format and puts to a tracer.
  * @param The SameStruct2Interface object to trace.
  */
  void capture_state(ISameStruct2Interface* obj);
  /**
  * Prepares information about the func1 call in a nlohmann::json format and puts to a tracer.
  * @param The SameStruct2Interface object to trace.
  */
  void trace_func1(const Struct1& param1);
  /**
  * Prepares information about the func2 call in a nlohmann::json format and puts to a tracer.
  * @param The SameStruct2Interface object to trace.
  */
  void trace_func2(const Struct1& param1, const Struct2& param2);
  /**
  * Prepares information about the sig1 call in a nlohmann::json format and puts to a tracer.
  * @param The SameStruct2Interface object to trace.
  */
  void trace_sig1(const Struct1& param1);
  /**
  * Prepares information about the sig2 call in a nlohmann::json format and puts to a tracer.
  * @param The SameStruct2Interface object to trace.
  */
  void trace_sig2(const Struct1& param1, const Struct2& param2);
private:
  /**
  * A tracer object to which the information about the state and operations is put.
  */
  ApiGear::PocoImpl::Tracer& m_tracer;
};

} // namespace TbSame1
} // namespace Test
