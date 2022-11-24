#pragma once

#include "tb_simple/generated/api/tb_simple.h"

namespace ApiGear { namespace PocoImpl { class Tracer; } }

namespace Test {
namespace TbSimple {

/**
* A helper class for tracing.
* Builds the trace info with state and operations specific for SimpleInterface and pass to PocoImpl::Tracer.
*/
class SimpleInterfaceTracer
{
public:
  /**
  * ctor
  * @param tracer A tracer object to which the information about the state and operations is put.
  */
  SimpleInterfaceTracer(ApiGear::PocoImpl::Tracer& tracer);
  /** dtor */
  virtual ~SimpleInterfaceTracer() = default;
  /**
  * Prepares the SimpleInterface object state in a nlohmann::json format and puts to a tracer.
  * @param The SimpleInterface object to trace.
  */
  void capture_state(ISimpleInterface* obj);
  /**
  * Prepares information about the funcVoid call in a nlohmann::json format and puts to a tracer.
  * @param The SimpleInterface object to trace.
  */
  void trace_funcVoid();
  /**
  * Prepares information about the funcBool call in a nlohmann::json format and puts to a tracer.
  * @param The SimpleInterface object to trace.
  */
  void trace_funcBool(bool paramBool);
  /**
  * Prepares information about the funcInt call in a nlohmann::json format and puts to a tracer.
  * @param The SimpleInterface object to trace.
  */
  void trace_funcInt(int paramInt);
  /**
  * Prepares information about the funcFloat call in a nlohmann::json format and puts to a tracer.
  * @param The SimpleInterface object to trace.
  */
  void trace_funcFloat(float paramFloat);
  /**
  * Prepares information about the funcString call in a nlohmann::json format and puts to a tracer.
  * @param The SimpleInterface object to trace.
  */
  void trace_funcString(const std::string& paramString);
  /**
  * Prepares information about the sigBool call in a nlohmann::json format and puts to a tracer.
  * @param The SimpleInterface object to trace.
  */
  void trace_sigBool(bool paramBool);
  /**
  * Prepares information about the sigInt call in a nlohmann::json format and puts to a tracer.
  * @param The SimpleInterface object to trace.
  */
  void trace_sigInt(int paramInt);
  /**
  * Prepares information about the sigFloat call in a nlohmann::json format and puts to a tracer.
  * @param The SimpleInterface object to trace.
  */
  void trace_sigFloat(float paramFloat);
  /**
  * Prepares information about the sigString call in a nlohmann::json format and puts to a tracer.
  * @param The SimpleInterface object to trace.
  */
  void trace_sigString(const std::string& paramString);
private:
  /**
  * A tracer object to which the information about the state and operations is put.
  */
  ApiGear::PocoImpl::Tracer& m_tracer;
};

} // namespace TbSimple
} // namespace Test
