{{- /* Copyright (c) ApiGear UG 2020 */}}
{{- $class := printf "%sService" .Interface.Name  }}
{{- $interface := .Interface.Name  -}}
#pragma once

#include "{{snake .Module.Name}}/generated/api/{{snake .Module.Name}}.h"
#include "{{snake .Module.Name}}/generated/api/common.h"
#include "apigear/mqtt/mqttservice.h"

namespace {{ Camel .System.Name }} {
namespace {{ Camel .Module.Name }} {
namespace MQTT {
class {{ SNAKE .System.Name  }}_{{ SNAKE .Module.Name  }}_EXPORT {{$class}} : public I{{$interface}}Subscriber
{
public:
    explicit {{$class}}(std::shared_ptr<I{{$interface}}> impl, std::shared_ptr<ApiGear::MQTT::Service> service);
    virtual ~{{$class}}() override;

    void onConnectionStatusChanged(bool connectionStatus);

    void onInvoke(const ApiGear::MQTT::Topic& topic, const std::string& args, const ApiGear::MQTT::Topic& responseTopic, const std::string& correlationData);

    // I{{$interface}}Subscriber interface
{{- range .Interface.Signals}}
{{- $signal := . }}
    void on{{Camel $signal.Name}}({{cppParams "" $signal.Params}}) override;
{{- end }}

{{- range .Interface.Properties}}
{{- $property := . }}
    void on{{Camel $property.Name}}Changed({{cppParam "" $property}}) override;
{{- end }}

private:
    std::shared_ptr<I{{$interface}}> m_impl;
    std::shared_ptr<ApiGear::MQTT::Service> m_service;
    // id for connection status registration
    int m_connectionStatusRegistrationID;
};
} // namespace MQTT
} // namespace {{ Camel .Module.Name }}
} // namespace {{ Camel .System.Name }}
