#pragma once

#include "tb_names/generated/api/tb_names.h"

namespace ApiGear { namespace PocoImpl { class Tracer; } }

namespace Test {
namespace TbNames {

/**
* A helper class for tracing.
* Builds the trace info with state and operations specific for Nam_Es and pass to PocoImpl::Tracer.
*/
class Nam_EsTracer
{
public:
  /**
  * ctor
  * @param tracer A tracer object to which the information about the state and operations is put.
  */
  Nam_EsTracer(ApiGear::PocoImpl::Tracer& tracer);
  /** dtor */
  virtual ~Nam_EsTracer() = default;
  /**
  * Prepares the Nam_Es object state in a nlohmann::json format and puts to a tracer.
  * @param The Nam_Es object to trace.
  */
  void capture_state(INamEs* obj);
  /**
  * Prepares information about the SOME_FUNCTION call in a nlohmann::json format and puts to a tracer.
  * @param The Nam_Es object to trace.
  */
  void trace_SOME_FUNCTION(bool SOME_PARAM);
  /**
  * Prepares information about the Some_Function2 call in a nlohmann::json format and puts to a tracer.
  * @param The Nam_Es object to trace.
  */
  void trace_Some_Function2(bool Some_Param);
  /**
  * Prepares information about the SOME_SIGNAL call in a nlohmann::json format and puts to a tracer.
  * @param The Nam_Es object to trace.
  */
  void trace_SOME_SIGNAL(bool SOME_PARAM);
  /**
  * Prepares information about the Some_Signal2 call in a nlohmann::json format and puts to a tracer.
  * @param The Nam_Es object to trace.
  */
  void trace_Some_Signal2(bool Some_Param);
private:
  /**
  * A tracer object to which the information about the state and operations is put.
  */
  ApiGear::PocoImpl::Tracer& m_tracer;
};

} // namespace TbNames
} // namespace Test
