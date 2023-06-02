{{- /* Copyright (c) ApiGear UG 2020 */ -}}
#pragma once

#include "{{snake .Module.Name}}/generated/api/{{snake .Module.Name}}.h"

namespace ApiGear { namespace PocoImpl { class Tracer; } }

namespace {{ Camel .System.Name }} {
namespace {{ Camel .Module.Name }} {

{{ $class := printf "%sTracer" .Interface.Name  }}
{{- $interfaceNameOriginal := .Interface.Name  }}
{{- $interfaceName := Camel .Interface.Name  }}
{{- $interfaceClass := printf "I%s" $interfaceName -}}
/**
* A helper class for tracing.
* Builds the trace info with state and operations specific for {{.Interface.Name}} and pass to PocoImpl::Tracer.
*/
class {{$class}}
{
public:
  /**
  * ctor
  * @param tracer A tracer object to which the information about the state and operations is put.
  */
  {{$class}}(ApiGear::PocoImpl::Tracer& tracer);
  /** dtor */
  virtual ~{{$class}}() = default;
  /**
  * Prepares the {{.Interface.Name}} object state in a nlohmann::json format and puts to a tracer.
  * @param The {{.Interface.Name}} object to trace.
  */
  void capture_state({{$interfaceClass}}* obj);
{{- range .Interface.Operations}}
{{- $operation := . }}
  /**
  * Prepares information about the {{$operation.Name}} call in a nlohmann::json format and puts to a tracer.
  * @param The {{$interfaceNameOriginal}} object to trace.
  */
  void trace_{{$operation.Name}}({{cppParams "" $operation.Params}});
{{- end }}
{{- range .Interface.Signals}}
{{- $signal := . }}
  /**
  * Prepares information about the {{$signal.Name}} call in a nlohmann::json format and puts to a tracer.
  * @param The {{$interfaceNameOriginal}} object to trace.
  */
  void trace_{{$signal.Name}}({{ cppParams "" $signal.Params }});
{{- end }}
private:
  /**
  * A tracer object to which the information about the state and operations is put.
  */
  ApiGear::PocoImpl::Tracer& m_tracer;
};

} // namespace {{ Camel .Module.Name }}
} // namespace {{ Camel .System.Name }}
