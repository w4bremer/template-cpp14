#include <iostream>
{{- $features := .Features}}
{{- range .System.Modules }}
{{- $module := . }}
{{- range $module.Interfaces }}
{{- $interface := . }}
#include "{{snake $module.Name}}/generated/olink/{{ lower ( camel $interface.Name) }}client.h"
{{- if $features.monitor }}
#include "{{snake $module.Name}}/generated/monitor/{{ lower ( camel $interface.Name) }}.tracedecorator.h"
{{- end}}
{{- end }}
{{- end }}

#include "apigear/olink/olinkconnection.h"
{{- if $features.monitor }}
#include "apigear/tracer/tracer.h"
{{- end}}
#include "apigear/olink/olinklogadapter.h"
#include "olink/clientregistry.h"
#include <sstream>
#include <cstdlib>

ApiGear::Utilities::WriteLogFunc getLogging(){

    ApiGear::Utilities::WriteLogFunc logConsoleFunc = nullptr;
    ApiGear::Utilities::LogLevel logLevel = ApiGear::Utilities::LogLevel::Debug;

    // check whether logging level is set via env
    if (const char* envLogLevel = std::getenv("LOG_LEVEL"))
    {
        int logLevelNumber = 255;
        std::stringstream(envLogLevel) >> logLevelNumber;
        logLevel = static_cast<ApiGear::Utilities::LogLevel>(logLevelNumber);
    }

    logConsoleFunc = ApiGear::Utilities::getConsoleLogFunc(logLevel);
    // check whether logging was disabled
    if (logLevel > ApiGear::Utilities::LogLevel::Error) {
        logConsoleFunc = nullptr;
    }

    // set global log function
    ApiGear::Utilities::setLog(logConsoleFunc);

    return logConsoleFunc;
}

using namespace {{ Camel .System.Name }};

int main(){

{{- if $features.monitor }}
    ApiGear::PocoImpl::Tracer tracer;
    tracer.connect("http://localhost:5555", "testExampleOLinkApp");
{{- end}}
    ApiGear::ObjectLink::ClientRegistry registry;
    auto logConsoleFunc = getLogging();
    registry.onLog(ApiGear::Utilities::logAdapter(logConsoleFunc));
    ApiGear::PocoImpl::OlinkConnection clientNetworkEndpoint(registry);
    clientNetworkEndpoint.node()->onLog(ApiGear::Utilities::logAdapter(logConsoleFunc));
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
    {{- if $features.monitor }}
    std::unique_ptr<{{Camel $module.Name}}::I{{$class}}> {{$tracer_className}} = {{ Camel $module.Name}}::{{$tracer_class}}::connect(*{{$clientClassName}}, tracer);
    {{- end}}
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
