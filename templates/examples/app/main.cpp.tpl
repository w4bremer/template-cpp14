{{- $features := .Features}}
{{- range .System.Modules }}
{{- $module := . }}
{{- range $module.Interfaces }}
{{- $interface := . }}
#include "{{snake $module.Name}}/implementation/{{ lower ( camel $interface.Name) }}.h"
{{- if $features.monitor }}
#include "{{snake $module.Name}}/generated/monitor/{{ lower ( camel $interface.Name) }}.tracedecorator.h"
{{- end}}
{{- end }}
{{- end }}
{{- if $features.monitor }}
#include "apigear/tracer/tracer.h"
{{ end}}
using namespace {{ Camel .System.Name }};

int main(){
{{- if $features.monitor }}
    ApiGear::PocoImpl::Tracer tracer;
    tracer.connect("http://localhost:5555", "testExampleApp");
{{- end}}
{{- range .System.Modules }}
{{- $module := . }}
{{- range $module.Interfaces }}
{{- $interface := . }}
    {{- $class := Camel $interface.Name }}
    {{- $tracer_class := printf "%sTraceDecorator" $class }}
    std::unique_ptr<{{ Camel $module.Name }}::I{{$class}}> test{{ Camel $module.Name }}{{$class}} = std::make_unique<{{ Camel $module.Name }}::{{$class}}>();
    {{ if $features.monitor }}std::unique_ptr<{{ Camel $module.Name }}::I{{$class}}> test{{ Camel $module.Name }}{{$tracer_class}} = {{ Camel $module.Name }}::{{$tracer_class}}::connect(*test{{ Camel $module.Name }}{{$class}}, tracer); {{- end}}
{{- end }}
{{- end }}

    return 0;
}
