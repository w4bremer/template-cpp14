#pragma once

#include "tb_enum/generated/api/tb_enum.h"

namespace ApiGear { namespace PocoImpl { class Tracer; } }

namespace Test {
namespace TbEnum {

/**
* A helper class for tracing.
* Builds the trace info with state and operations specific for EnumInterface and pass to PocoImpl::Tracer.
*/
class EnumInterfaceTracer
{
public:
  /**
  * ctor
  * @param tracer A tracer object to which the information about the state and operations is put.
  */
  EnumInterfaceTracer(ApiGear::PocoImpl::Tracer& tracer);
  /** dtor */
  virtual ~EnumInterfaceTracer() = default;
  /**
  * Prepares the EnumInterface object state in a nlohmann::json format and puts to a tracer.
  * @param The EnumInterface object to trace.
  */
  void capture_state(IEnumInterface* obj);
  /**
  * Prepares information about the func0 call in a nlohmann::json format and puts to a tracer.
  * @param The EnumInterface object to trace.
  */
  void trace_func0(const Enum0Enum& param0);
  /**
  * Prepares information about the func1 call in a nlohmann::json format and puts to a tracer.
  * @param The EnumInterface object to trace.
  */
  void trace_func1(const Enum1Enum& param1);
  /**
  * Prepares information about the func2 call in a nlohmann::json format and puts to a tracer.
  * @param The EnumInterface object to trace.
  */
  void trace_func2(const Enum2Enum& param2);
  /**
  * Prepares information about the func3 call in a nlohmann::json format and puts to a tracer.
  * @param The EnumInterface object to trace.
  */
  void trace_func3(const Enum3Enum& param3);
  /**
  * Prepares information about the sig0 call in a nlohmann::json format and puts to a tracer.
  * @param The EnumInterface object to trace.
  */
  void trace_sig0(const Enum0Enum& param0);
  /**
  * Prepares information about the sig1 call in a nlohmann::json format and puts to a tracer.
  * @param The EnumInterface object to trace.
  */
  void trace_sig1(const Enum1Enum& param1);
  /**
  * Prepares information about the sig2 call in a nlohmann::json format and puts to a tracer.
  * @param The EnumInterface object to trace.
  */
  void trace_sig2(const Enum2Enum& param2);
  /**
  * Prepares information about the sig3 call in a nlohmann::json format and puts to a tracer.
  * @param The EnumInterface object to trace.
  */
  void trace_sig3(const Enum3Enum& param3);
private:
  /**
  * A tracer object to which the information about the state and operations is put.
  */
  ApiGear::PocoImpl::Tracer& m_tracer;
};

} // namespace TbEnum
} // namespace Test
