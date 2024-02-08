#pragma once

#include "testbed2/generated/api/testbed2.h"

namespace ApiGear { namespace PocoImpl { class Tracer; } }

namespace Test {
namespace Testbed2 {

/**
* A helper class for tracing.
* Builds the trace info with state and operations specific for ManyParamInterface and pass to PocoImpl::Tracer.
*/
class ManyParamInterfaceTracer
{
public:
  /**
  * ctor
  * @param tracer A tracer object to which the information about the state and operations is put.
  */
  ManyParamInterfaceTracer(ApiGear::PocoImpl::Tracer& tracer);
  /** dtor */
  virtual ~ManyParamInterfaceTracer() = default;
  /**
  * Prepares the ManyParamInterface object state in a nlohmann::json format and puts to a tracer.
  * @param The ManyParamInterface object to trace.
  */
  void capture_state(IManyParamInterface* obj);
  /**
  * Prepares information about the func1 call in a nlohmann::json format and puts to a tracer.
  * @param The ManyParamInterface object to trace.
  */
  void trace_func1(int param1);
  /**
  * Prepares information about the func2 call in a nlohmann::json format and puts to a tracer.
  * @param The ManyParamInterface object to trace.
  */
  void trace_func2(int param1, int param2);
  /**
  * Prepares information about the func3 call in a nlohmann::json format and puts to a tracer.
  * @param The ManyParamInterface object to trace.
  */
  void trace_func3(int param1, int param2, int param3);
  /**
  * Prepares information about the func4 call in a nlohmann::json format and puts to a tracer.
  * @param The ManyParamInterface object to trace.
  */
  void trace_func4(int param1, int param2, int param3, int param4);
  /**
  * Prepares information about the sig1 call in a nlohmann::json format and puts to a tracer.
  * @param The ManyParamInterface object to trace.
  */
  void trace_sig1(int param1);
  /**
  * Prepares information about the sig2 call in a nlohmann::json format and puts to a tracer.
  * @param The ManyParamInterface object to trace.
  */
  void trace_sig2(int param1, int param2);
  /**
  * Prepares information about the sig3 call in a nlohmann::json format and puts to a tracer.
  * @param The ManyParamInterface object to trace.
  */
  void trace_sig3(int param1, int param2, int param3);
  /**
  * Prepares information about the sig4 call in a nlohmann::json format and puts to a tracer.
  * @param The ManyParamInterface object to trace.
  */
  void trace_sig4(int param1, int param2, int param3, int param4);
private:
  /**
  * A tracer object to which the information about the state and operations is put.
  */
  ApiGear::PocoImpl::Tracer& m_tracer;
};

} // namespace Testbed2
} // namespace Test
