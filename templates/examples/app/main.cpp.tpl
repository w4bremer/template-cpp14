{{- range .System.Modules }}
{{- $module := . }}
{{- range $module.Interfaces }}
{{- $interface := . }}
#include "{{snake $module.Name}}/implementation/{{ lower ( camel $interface.Name) }}.h"
#include "{{snake $module.Name}}/generated/monitor/{{ lower ( camel $interface.Name) }}.tracedecorator.h"
{{- end }}
{{- end }}
#include "apigear/tracer/tracer.h"

using namespace {{ Camel .System.Name }};

int main(){
    ApiGear::PocoImpl::Tracer tracer;
    tracer.connect("http://localhost:5555", "testExampleApp");
{{- range .System.Modules }}
{{- $module := . }}
{{- range $module.Interfaces }}
{{- $interface := . }}
    {{- $class := Camel $interface.Name }}
    {{- $tracer_class := printf "%sTraceDecorator" $class }}
    std::unique_ptr<{{ Camel $module.Name }}::I{{$class}}> test{{ Camel $module.Name }}{{$class}} = std::make_unique<{{ Camel $module.Name }}::{{$class}}>();
    std::unique_ptr<{{ Camel $module.Name }}::I{{$class}}> test{{ Camel $module.Name }}{{$tracer_class}} = {{ Camel $module.Name }}::{{$tracer_class}}::connect(*test{{ Camel $module.Name }}{{$class}}, tracer);
{{- end }}
{{- end }}

    return 0;
}
