{{- range .System.Modules }}
{{- $module := . }}
{{- range $module.Interfaces }}
{{- $interface := . }}
#include "{{snake $module.Name}}/implementation/{{ lower ( camel $interface.Name) }}.h"
#include "{{snake $module.Name}}/generated/olink/{{ lower ( camel $interface.Name) }}service.h"
{{- end }}
{{- end }}

#include "apigear/olink/olinklogadapter.h"
#include "olink/remoteregistry.h"
#include "apigear/olink/olinkhost.h"

#include <iostream>

using namespace {{ Camel .System.Name }};

int main(){
    ApiGear::ObjectLink::RemoteRegistry registry;
    registry.onLog(ApiGear::Utilities::logAdapter(ApiGear::Utilities::getConsoleLogFunc(ApiGear::Utilities::Debug)));
    
    ApiGear::PocoImpl::OLinkHost testserver(registry);

{{- range .System.Modules }}
{{- $module := . }}
{{- range $module.Interfaces }}
{{- $interface := . }}
    {{- $class := Camel $interface.Name }}
    {{- $modulePrefix := lower1 (Camel $module.Name)}}
    {{- $instanceName := printf "%s%s"  $modulePrefix $class }}
    {{- $serviceInstanceName := printf "%sOlink%sService" $modulePrefix $class }}
    auto {{$instanceName}} = std::make_shared<{{ Camel $module.Name }}::{{$class}}>();
    auto {{$serviceInstanceName}} = std::make_shared<{{ Camel $module.Name }}::olink::{{$interface.Name}}Service>({{$instanceName}}, registry);
    registry.addSource({{$serviceInstanceName}});
{{- end }}
{{- end }}

    testserver.listen(8000);

    bool keepRunning = true;
    std::string cmd;
    do {
        std::cout << "Enter command:" << std::endl;
        getline (std::cin, cmd);

        if(cmd == "quit"){
            testserver.close();
            keepRunning = false;
        }
    } while(keepRunning);

{{- range .System.Modules }}
{{- $module := . }}
{{- range $module.Interfaces }}
{{- $interface := . }}
    {{- $class := Camel $interface.Name }}
    {{- $modulePrefix := lower1 (Camel $module.Name)}}
    {{- $serviceInstanceName := printf "%sOlink%sService" $modulePrefix $class }}
    registry.removeSource({{$serviceInstanceName}}->olinkObjectName());
{{- end }}
{{- end }}
    
    return 0;
}
