{{- /* Copyright (c) ApiGear UG 2020 */ -}}
{{-  $class := Camel .Interface.Name -}}

#pragma once

#include "{{snake .Module.Name}}/generated/api/{{snake .Module.Name}}.h"


namespace {{ Camel .System.Name }}
{
namespace {{ Camel .Module.Name }}
{

/**
* A helper structure for implementations of {{.Interface.Name}}. Stores all the properties.
*/
struct {{$class}}Data
{
{{- range .Interface.Properties }}
{{- $property:= . }}
    {{cppType "" $property}} m_{{$property.Name}};
{{- end }}
};

}
}