#pragma once

#include "tb_simple/generated/api/tb_simple.h"

namespace ApiGear { namespace PocoImpl { class Tracer; } }

namespace Test {
namespace TbSimple {

/**
* A helper class for tracing.
* Builds the trace info with state and operations specific for SimpleArrayInterface and pass to PocoImpl::Tracer.
*/
class SimpleArrayInterfaceTracer
{
public:
  /**
  * ctor
  * @param tracer A tracer object to which the information about the state and operations is put.
  */
  SimpleArrayInterfaceTracer(ApiGear::PocoImpl::Tracer& tracer);
  /** dtor */
  virtual ~SimpleArrayInterfaceTracer() = default;
  /**
  * Prepares the SimpleArrayInterface object state in a nlohmann::json format and puts to a tracer.
  * @param The SimpleArrayInterface object to trace.
  */
  void capture_state(ISimpleArrayInterface* obj);
  /**
  * Prepares information about the funcBool call in a nlohmann::json format and puts to a tracer.
  * @param The SimpleArrayInterface object to trace.
  */
  void trace_funcBool(const std::list<bool>& paramBool);
  /**
  * Prepares information about the funcInt call in a nlohmann::json format and puts to a tracer.
  * @param The SimpleArrayInterface object to trace.
  */
  void trace_funcInt(const std::list<int>& paramInt);
  /**
  * Prepares information about the funcInt32 call in a nlohmann::json format and puts to a tracer.
  * @param The SimpleArrayInterface object to trace.
  */
  void trace_funcInt32(const std::list<int32_t>& paramInt32);
  /**
  * Prepares information about the funcInt64 call in a nlohmann::json format and puts to a tracer.
  * @param The SimpleArrayInterface object to trace.
  */
  void trace_funcInt64(const std::list<int64_t>& paramInt64);
  /**
  * Prepares information about the funcFloat call in a nlohmann::json format and puts to a tracer.
  * @param The SimpleArrayInterface object to trace.
  */
  void trace_funcFloat(const std::list<float>& paramFloat);
  /**
  * Prepares information about the funcFloat32 call in a nlohmann::json format and puts to a tracer.
  * @param The SimpleArrayInterface object to trace.
  */
  void trace_funcFloat32(const std::list<float>& paramFloat32);
  /**
  * Prepares information about the funcFloat64 call in a nlohmann::json format and puts to a tracer.
  * @param The SimpleArrayInterface object to trace.
  */
  void trace_funcFloat64(const std::list<double>& paramFloat);
  /**
  * Prepares information about the funcString call in a nlohmann::json format and puts to a tracer.
  * @param The SimpleArrayInterface object to trace.
  */
  void trace_funcString(const std::list<std::string>& paramString);
  /**
  * Prepares information about the sigBool call in a nlohmann::json format and puts to a tracer.
  * @param The SimpleArrayInterface object to trace.
  */
  void trace_sigBool(const std::list<bool>& paramBool);
  /**
  * Prepares information about the sigInt call in a nlohmann::json format and puts to a tracer.
  * @param The SimpleArrayInterface object to trace.
  */
  void trace_sigInt(const std::list<int>& paramInt);
  /**
  * Prepares information about the sigInt32 call in a nlohmann::json format and puts to a tracer.
  * @param The SimpleArrayInterface object to trace.
  */
  void trace_sigInt32(const std::list<int32_t>& paramInt32);
  /**
  * Prepares information about the sigInt64 call in a nlohmann::json format and puts to a tracer.
  * @param The SimpleArrayInterface object to trace.
  */
  void trace_sigInt64(const std::list<int64_t>& paramInt64);
  /**
  * Prepares information about the sigFloat call in a nlohmann::json format and puts to a tracer.
  * @param The SimpleArrayInterface object to trace.
  */
  void trace_sigFloat(const std::list<float>& paramFloat);
  /**
  * Prepares information about the sigFloat32 call in a nlohmann::json format and puts to a tracer.
  * @param The SimpleArrayInterface object to trace.
  */
  void trace_sigFloat32(const std::list<float>& paramFloa32);
  /**
  * Prepares information about the sigFloat64 call in a nlohmann::json format and puts to a tracer.
  * @param The SimpleArrayInterface object to trace.
  */
  void trace_sigFloat64(const std::list<double>& paramFloat64);
  /**
  * Prepares information about the sigString call in a nlohmann::json format and puts to a tracer.
  * @param The SimpleArrayInterface object to trace.
  */
  void trace_sigString(const std::list<std::string>& paramString);
private:
  /**
  * A tracer object to which the information about the state and operations is put.
  */
  ApiGear::PocoImpl::Tracer& m_tracer;
};

} // namespace TbSimple
} // namespace Test
