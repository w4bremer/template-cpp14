{{- /* Copyright (c) ApiGear UG 2020 */}}
{{- $class := printf "%sService" .Interface.Name  }}
{{- $interface := .Interface.Name  -}}
#pragma once

#include "{{snake .Module.Name}}/generated/api/{{snake .Module.Name}}.h"
#include "{{snake .Module.Name}}/generated/api/common.h"
#include "apigear/mqtt/mqttcppclient.h"
#include "mqttisink.h"

namespace {{ Camel .System.Name }} {
namespace {{ Camel .Module.Name }} {
namespace MQTT {
class {{ SNAKE .System.Name  }}_{{ SNAKE .Module.Name  }}_EXPORT {{$class}} : public virtual ApiGear::MQTT::ISink, public I{{$interface}}Subscriber
{
public:
    explicit {{$class}}(std::shared_ptr<I{{$interface}}> impl, std::shared_ptr<ApiGear::MQTT::Client> client);
    virtual ~{{$class}}() override;

    // sink interface
    void onConnected() override;
    void onSignal(const ApiGear::MQTT::Topic&, const std::string&) override {};
    void onPropertyChanged(const ApiGear::MQTT::Topic&, const std::string&) override {};
    void onInvoke(const ApiGear::MQTT::Topic& topic, const std::string& args, const ApiGear::MQTT::Topic& responseTopic, const std::string& correlationData) override;

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
    std::shared_ptr<ApiGear::MQTT::Client> m_client;
};
} // namespace MQTT
} // namespace {{ Camel .Module.Name }}
} // namespace {{ Camel .System.Name }}
