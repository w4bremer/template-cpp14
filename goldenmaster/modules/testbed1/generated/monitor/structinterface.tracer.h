#pragma once

#include "testbed1/generated/api/testbed1.h"

namespace ApiGear { namespace PocoImpl { class Tracer; } }

namespace Test {
namespace Testbed1 {

/**
* A helper class for tracing.
* Builds the trace info with state and operations specific for StructInterface and pass to PocoImpl::Tracer.
*/
class StructInterfaceTracer
{
public:
  /**
  * ctor
  * @param tracer A tracer object to which the information about the state and operations is put.
  */
  StructInterfaceTracer(ApiGear::PocoImpl::Tracer& tracer);
  /** dtor */
  virtual ~StructInterfaceTracer() = default;
  /**
  * Prepares the StructInterface object state in a nlohmann::json format and puts to a tracer.
  * @param The StructInterface object to trace.
  */
  void capture_state(IStructInterface* obj);
  /**
  * Prepares information about the funcBool call in a nlohmann::json format and puts to a tracer.
  * @param The StructInterface object to trace.
  */
  void trace_funcBool(const StructBool& paramBool);
  /**
  * Prepares information about the funcInt call in a nlohmann::json format and puts to a tracer.
  * @param The StructInterface object to trace.
  */
  void trace_funcInt(const StructInt& paramInt);
  /**
  * Prepares information about the funcFloat call in a nlohmann::json format and puts to a tracer.
  * @param The StructInterface object to trace.
  */
  void trace_funcFloat(const StructFloat& paramFloat);
  /**
  * Prepares information about the funcString call in a nlohmann::json format and puts to a tracer.
  * @param The StructInterface object to trace.
  */
  void trace_funcString(const StructString& paramString);
  /**
  * Prepares information about the sigBool call in a nlohmann::json format and puts to a tracer.
  * @param The StructInterface object to trace.
  */
  void trace_sigBool(const StructBool& paramBool);
  /**
  * Prepares information about the sigInt call in a nlohmann::json format and puts to a tracer.
  * @param The StructInterface object to trace.
  */
  void trace_sigInt(const StructInt& paramInt);
  /**
  * Prepares information about the sigFloat call in a nlohmann::json format and puts to a tracer.
  * @param The StructInterface object to trace.
  */
  void trace_sigFloat(const StructFloat& paramFloat);
  /**
  * Prepares information about the sigString call in a nlohmann::json format and puts to a tracer.
  * @param The StructInterface object to trace.
  */
  void trace_sigString(const StructString& paramString);
private:
  /**
  * A tracer object to which the information about the state and operations is put.
  */
  ApiGear::PocoImpl::Tracer& m_tracer;
};

} // namespace Testbed1
} // namespace Test
