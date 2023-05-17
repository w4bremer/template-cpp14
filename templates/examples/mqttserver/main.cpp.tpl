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
#include "apigear/utilities/logger.h"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <random>

using namespace {{ Camel .System.Name }};

ApiGear::Utilities::WriteLogFunc getLogging(){

    ApiGear::Utilities::WriteLogFunc logConsoleFunc = nullptr;
    ApiGear::Utilities::LogLevel logLevel = ApiGear::Utilities::LogLevel::Warning;

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
    auto logConsoleFunc = getLogging();
    std::mt19937 randomNumberGenerator (std::random_device{}());
    std::uniform_int_distribution<> distribution (0, 100000);

    auto randomId = distribution(randomNumberGenerator);
    // MQTT clients need to have unique identifiers
    auto mqttclient = std::make_shared<ApiGear::MQTT::Client>("testServer"+std::to_string(randomId));
    mqttclient->connectToHost("");

{{- range .System.Modules }}
{{- $module := . }}
{{- range $module.Interfaces }}
{{- $interface := . }}
    {{- $class := Camel $interface.Name }}
    std::shared_ptr<{{ Camel $module.Name }}::I{{$class}}> test{{ Camel $module.Name }}{{$class}} = std::make_shared<{{ Camel $module.Name }}::{{$class}}>();
    {{ Camel $module.Name }}::MQTT::{{$interface.Name}}Service test{{ Camel $module.Name }}{{$class}}Service(test{{ Camel $module.Name }}{{$class}}, mqttclient);
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
