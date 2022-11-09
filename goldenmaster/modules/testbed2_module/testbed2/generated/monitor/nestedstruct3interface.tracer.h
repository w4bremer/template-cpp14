#pragma once

#include "testbed2/generated/api/testbed2.h"

namespace ApiGear { namespace PocoImpl { class Tracer; } }

namespace Test {
namespace Testbed2 {

/**
* A helper class for tracing.
* Builds the trace info with state and operations specific for NestedStruct3Interface and pass to PocoImpl::Tracer.
*/
class NestedStruct3InterfaceTracer
{
public:
  /**
  * ctor
  * @param tracer A tracer object to which the information about the state and operations is put.
  */
  NestedStruct3InterfaceTracer(ApiGear::PocoImpl::Tracer& tracer);
  /** dtor */
  virtual ~NestedStruct3InterfaceTracer() = default;
  /**
  * Prepares the NestedStruct3Interface object state in a nlohmann::json format and puts to a tracer.
  * @param The NestedStruct3Interface object to trace.
  */
  void capture_state(INestedStruct3Interface* obj);
  /**
  * Prepares information about the func1 call in a nlohmann::json format and puts to a tracer.
  * @param The NestedStruct3Interface object to trace.
  */
  void trace_func1(const NestedStruct1& param1);
  /**
  * Prepares information about the func2 call in a nlohmann::json format and puts to a tracer.
  * @param The NestedStruct3Interface object to trace.
  */
  void trace_func2(const NestedStruct1& param1, const NestedStruct2& param2);
  /**
  * Prepares information about the func3 call in a nlohmann::json format and puts to a tracer.
  * @param The NestedStruct3Interface object to trace.
  */
  void trace_func3(const NestedStruct1& param1, const NestedStruct2& param2, const NestedStruct3& param3);
  /**
  * Prepares information about the sig1 call in a nlohmann::json format and puts to a tracer.
  * @param The NestedStruct3Interface object to trace.
  */
  void trace_sig1(const NestedStruct1& param1);
  /**
  * Prepares information about the sig2 call in a nlohmann::json format and puts to a tracer.
  * @param The NestedStruct3Interface object to trace.
  */
  void trace_sig2(const NestedStruct1& param1, const NestedStruct2& param2);
  /**
  * Prepares information about the sig3 call in a nlohmann::json format and puts to a tracer.
  * @param The NestedStruct3Interface object to trace.
  */
  void trace_sig3(const NestedStruct1& param1, const NestedStruct2& param2, const NestedStruct3& param3);
private:
  /**
  * A tracer object to which the information about the state and operations is put.
  */
  ApiGear::PocoImpl::Tracer& m_tracer;
};

} // namespace Testbed2
} // namespace Test
