#pragma once

#include "tb_same1/generated/api/tb_same1.h"

namespace ApiGear { namespace PocoImpl { class Tracer; } }

namespace Test {
namespace TbSame1 {

/**
* A helper class for tracing.
* Builds the trace info with state and operations specific for SameStruct1Interface and pass to PocoImpl::Tracer.
*/
class SameStruct1InterfaceTracer
{
public:
  /**
  * ctor
  * @param tracer A tracer object to which the information about the state and operations is put.
  */
  SameStruct1InterfaceTracer(ApiGear::PocoImpl::Tracer& tracer);
  /** dtor */
  virtual ~SameStruct1InterfaceTracer() = default;
  /**
  * Prepares the SameStruct1Interface object state in a nlohmann::json format and puts to a tracer.
  * @param The SameStruct1Interface object to trace.
  */
  void capture_state(ISameStruct1Interface* obj);
  /**
  * Prepares information about the func1 call in a nlohmann::json format and puts to a tracer.
  * @param The SameStruct1Interface object to trace.
  */
  void trace_func1(const Struct1& param1);
  /**
  * Prepares information about the sig1 call in a nlohmann::json format and puts to a tracer.
  * @param The SameStruct1Interface object to trace.
  */
  void trace_sig1(const Struct1& param1);
private:
  /**
  * A tracer object to which the information about the state and operations is put.
  */
  ApiGear::PocoImpl::Tracer& m_tracer;
};

} // namespace TbSame1
} // namespace Test
