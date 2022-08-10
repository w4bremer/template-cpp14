#pragma once

#include "tb_same2/generated/api/tb_same2.h"

namespace ApiGear { namespace PocoImpl { class Tracer; } }

namespace Test {
namespace TbSame2 {

/**
* A helper class for tracing.
* Builds the trace info with state and operations specific for SameEnum1Interface and pass to PocoImpl::Tracer.
*/
class SameEnum1InterfaceTracer
{
public:
  /**
  * ctor
  * @param tracer A tracer object to which the information about the state and operations is put.
  */
  SameEnum1InterfaceTracer(ApiGear::PocoImpl::Tracer& tracer);
  /** dtor */
  virtual ~SameEnum1InterfaceTracer() = default;
  /**
  * Prepares the SameEnum1Interface object state in a nlohmann::json format and puts to a tracer.
  * @param The SameEnum1Interface object to trace.
  */
  void capture_state(ISameEnum1Interface* obj);
  /**
  * Prepares information about the func1 call in a nlohmann::json format and puts to a tracer.
  * @param The SameEnum1Interface object to trace.
  */
  void trace_func1(const Enum1Enum& param1);
  /**
  * Prepares information about the sig1 call in a nlohmann::json format and puts to a tracer.
  * @param The SameEnum1Interface object to trace.
  */
  void trace_sig1(const Enum1Enum& param1);
private:
  /**
  * A tracer object to which the information about the state and operations is put.
  */
  ApiGear::PocoImpl::Tracer& m_tracer;
};

} // namespace TbSame2
} // namespace Test
