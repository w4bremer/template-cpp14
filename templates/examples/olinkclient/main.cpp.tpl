#include <iostream>
{{- range .System.Modules }}
{{- $module := . }}
{{- range $module.Interfaces }}
{{- $interface := . }}
#include "{{snake $module.Name}}/generated/olink/{{ lower ( camel $interface.Name) }}client.h"
#include "{{snake $module.Name}}/generated/monitor/{{ lower ( camel $interface.Name) }}.tracedecorator.h"
{{- end }}
{{- end }}

#include "apigear/olink/olinkconnection.h"
#include "apigear/tracer/tracer.h"
#include "olink/consolelogger.h"
#include "olink/clientregistry.h"

using namespace {{ Camel .System.Name }};

int main(){
    ApiGear::PocoImpl::Tracer tracer;
    tracer.connect("http://localhost:5555", "testExampleOLinkApp");
    ApiGear::ObjectLink::ClientRegistry registry;
    ApiGear::ObjectLink::ConsoleLogger logger;
    registry.onLog(logger.logFunc());
    ApiGear::PocoImpl::OlinkConnection clientNetworkEndpoint(registry);
    clientNetworkEndpoint.node()->onLog(logger.logFunc());
{{- range .System.Modules }}
{{- $module := . }}
{{- range $module.Interfaces }}
{{- $interface := . }}
    {{- $class := Camel $interface.Name }}
    {{- $modulePrefix := lower1 (Camel $module.Name)}}
    {{- $clientClassName := printf "%s%s"  $modulePrefix $class }}
    {{- $tracer_class := printf "%sTraceDecorator" $class }}
    {{- $tracer_className := printf "%sTraced" $clientClassName }}
    auto {{$clientClassName}} = std::make_shared<{{ Camel $module.Name }}::olink::{{$interface.Name}}Client>();
    clientNetworkEndpoint.connectAndLinkObject({{$clientClassName}});
    std::unique_ptr<{{Camel $module.Name}}::I{{$class}}> {{$tracer_className}} = {{ Camel $module.Name}}::{{$tracer_class}}::connect(*{{$clientClassName}}, tracer);
{{- end }}
{{- end }}
    
    clientNetworkEndpoint.connectToHost(Poco::URI("ws://localhost:8000"));

    bool keepRunning = true;
    std::string cmd;
    do {
        std::cout << "Enter command:" << std::endl;
        getline (std::cin, cmd);

        if(cmd == "quit"){
            keepRunning = false;
            clientNetworkEndpoint.disconnect();
        }
    } while(keepRunning);
{{- range .System.Modules }}
{{- $module := . }}
{{- range $module.Interfaces }}
{{- $interface := . }}
    {{- $class := Camel $interface.Name }}
    {{- $modulePrefix := lower1 (Camel $module.Name)}}
    {{- $clientClassName := printf "%s%s"  $modulePrefix $class }}
    clientNetworkEndpoint.disconnectAndUnlink({{$clientClassName}}->olinkObjectName());
{{- end }}
{{- end }}

    return 0;
}
