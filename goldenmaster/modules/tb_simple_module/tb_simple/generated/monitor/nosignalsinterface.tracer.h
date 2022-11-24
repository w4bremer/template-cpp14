#pragma once

#include "tb_simple/generated/api/tb_simple.h"

namespace ApiGear { namespace PocoImpl { class Tracer; } }

namespace Test {
namespace TbSimple {

/**
* A helper class for tracing.
* Builds the trace info with state and operations specific for NoSignalsInterface and pass to PocoImpl::Tracer.
*/
class NoSignalsInterfaceTracer
{
public:
  /**
  * ctor
  * @param tracer A tracer object to which the information about the state and operations is put.
  */
  NoSignalsInterfaceTracer(ApiGear::PocoImpl::Tracer& tracer);
  /** dtor */
  virtual ~NoSignalsInterfaceTracer() = default;
  /**
  * Prepares the NoSignalsInterface object state in a nlohmann::json format and puts to a tracer.
  * @param The NoSignalsInterface object to trace.
  */
  void capture_state(INoSignalsInterface* obj);
  /**
  * Prepares information about the funcVoid call in a nlohmann::json format and puts to a tracer.
  * @param The NoSignalsInterface object to trace.
  */
  void trace_funcVoid();
  /**
  * Prepares information about the funcBool call in a nlohmann::json format and puts to a tracer.
  * @param The NoSignalsInterface object to trace.
  */
  void trace_funcBool(bool paramBool);
private:
  /**
  * A tracer object to which the information about the state and operations is put.
  */
  ApiGear::PocoImpl::Tracer& m_tracer;
};

} // namespace TbSimple
} // namespace Test
