#pragma once

#include "tb_same1/generated/api/tb_same1.h"

namespace ApiGear { namespace PocoImpl { class Tracer; } }

namespace Test {
namespace TbSame1 {

/**
* A helper class for tracing.
* Builds the trace info with state and operations specific for SameEnum2Interface and pass to PocoImpl::Tracer.
*/
class SameEnum2InterfaceTracer
{
public:
  /**
  * ctor
  * @param tracer A tracer object to which the information about the state and operations is put.
  */
  SameEnum2InterfaceTracer(ApiGear::PocoImpl::Tracer& tracer);
  /** dtor */
  virtual ~SameEnum2InterfaceTracer() = default;
  /**
  * Prepares the SameEnum2Interface object state in a nlohmann::json format and puts to a tracer.
  * @param The SameEnum2Interface object to trace.
  */
  void capture_state(ISameEnum2Interface* obj);
  /**
  * Prepares information about the func1 call in a nlohmann::json format and puts to a tracer.
  * @param The SameEnum2Interface object to trace.
  */
  void trace_func1(Enum1Enum param1);
  /**
  * Prepares information about the func2 call in a nlohmann::json format and puts to a tracer.
  * @param The SameEnum2Interface object to trace.
  */
  void trace_func2(Enum1Enum param1, Enum2Enum param2);
  /**
  * Prepares information about the sig1 call in a nlohmann::json format and puts to a tracer.
  * @param The SameEnum2Interface object to trace.
  */
  void trace_sig1(Enum1Enum param1);
  /**
  * Prepares information about the sig2 call in a nlohmann::json format and puts to a tracer.
  * @param The SameEnum2Interface object to trace.
  */
  void trace_sig2(Enum1Enum param1, Enum2Enum param2);
private:
  /**
  * A tracer object to which the information about the state and operations is put.
  */
  ApiGear::PocoImpl::Tracer& m_tracer;
};

} // namespace TbSame1
} // namespace Test
