#pragma once

#include "tb_names/generated/api/tb_names.h"

namespace ApiGear { namespace PocoImpl { class Tracer; } }

namespace Test {
namespace TbNames {

/**
* A helper class for tracing.
* Builds the trace info with state and operations specific for Names and pass to PocoImpl::Tracer.
*/
class NamesTracer
{
public:
  /**
  * ctor
  * @param tracer A tracer object to which the information about the state and operations is put.
  */
  NamesTracer(ApiGear::PocoImpl::Tracer& tracer);
  /** dtor */
  virtual ~NamesTracer() = default;
  /**
  * Prepares the Names object state in a nlohmann::json format and puts to a tracer.
  * @param The Names object to trace.
  */
  void capture_state(INames* obj);
private:
  /**
  * A tracer object to which the information about the state and operations is put.
  */
  ApiGear::PocoImpl::Tracer& m_tracer;
};

} // namespace TbNames
} // namespace Test
