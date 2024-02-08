#pragma once

#include "tb_simple/generated/api/tb_simple.h"

namespace ApiGear { namespace PocoImpl { class Tracer; } }

namespace Test {
namespace TbSimple {

/**
* A helper class for tracing.
* Builds the trace info with state and operations specific for VoidInterface and pass to PocoImpl::Tracer.
*/
class VoidInterfaceTracer
{
public:
  /**
  * ctor
  * @param tracer A tracer object to which the information about the state and operations is put.
  */
  VoidInterfaceTracer(ApiGear::PocoImpl::Tracer& tracer);
  /** dtor */
  virtual ~VoidInterfaceTracer() = default;
  /**
  * Prepares the VoidInterface object state in a nlohmann::json format and puts to a tracer.
  * @param The VoidInterface object to trace.
  */
  void capture_state(IVoidInterface* obj);
  /**
  * Prepares information about the funcVoid call in a nlohmann::json format and puts to a tracer.
  * @param The VoidInterface object to trace.
  */
  void trace_funcVoid();
  /**
  * Prepares information about the sigVoid call in a nlohmann::json format and puts to a tracer.
  * @param The VoidInterface object to trace.
  */
  void trace_sigVoid();
private:
  /**
  * A tracer object to which the information about the state and operations is put.
  */
  ApiGear::PocoImpl::Tracer& m_tracer;
};

} // namespace TbSimple
} // namespace Test
