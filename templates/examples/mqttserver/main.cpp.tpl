#include <iostream>
{{- range .System.Modules }}
{{- $module := . }}
{{- range $module.Interfaces }}
{{- $interface := . }}
#include "{{snake $module.Name}}/implementation/{{ lower ( camel $interface.Name) }}.h"
#include "{{snake $module.Name}}/generated/mqtt/{{ lower ( camel $interface.Name) }}service.h"
{{- end }}
{{- end }}
#include "apigear/mqtt/mqttcppclient.h"
#include <random>

using namespace {{ Camel .System.Name }};

int main(){
    std::mt19937 randomNumberGenerator (std::random_device{}());
    std::uniform_int_distribution<> distribution (0, 100000);

    auto randomId = distribution(randomNumberGenerator);
    // MQTT clients need to have unique identifiers
    auto mqttclient = std::make_shared<ApiGear::MQTTImpl::Client>("testServer"+std::to_string(randomId));
    mqttclient->connectToHost("");

{{- range .System.Modules }}
{{- $module := . }}
{{- range $module.Interfaces }}
{{- $interface := . }}
    {{- $class := Camel $interface.Name }}
    std::unique_ptr<{{ Camel $module.Name }}::I{{$class}}> test{{ Camel $module.Name }}{{$class}} = std::make_unique<{{ Camel $module.Name }}::{{$class}}>();
    {{ Camel $module.Name }}::mqtt::{{$interface.Name}}Service test{{ Camel $module.Name }}{{$class}}Service(*test{{ Camel $module.Name }}{{$class}}, mqttclient);
{{- end }}
{{- end }}

    bool keepRunning = true;
    std::string cmd;
    do {
        std::cout << "Enter command:" << std::endl;
        getline (std::cin, cmd);

        if(cmd == "quit"){
            mqttclient->disconnect();
            keepRunning = false;
        } else {
        }
    } while(keepRunning);

    return 0;
}
