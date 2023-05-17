{{- /* Copyright (c) ApiGear UG 2020 */ -}}
{{- $interfaceName := Camel .Interface.Name  }}
{{- $interfaceNameOriginal := .Interface.Name  }}
{{- $interfaceClass := printf "I%s" $interfaceName }}
{{- $class := printf "%sClient" .Interface.Name }}
{{- $sub_class := printf "I%sSubscriber" $interfaceName }}
{{- $pub_class := printf "I%sPublisher" $interfaceName -}}
#pragma once

#include <future>
#include "{{snake .Module.Name}}/generated/api/common.h"
#include "{{snake .Module.Name}}/generated/api/{{snake .Module.Name}}.h"
#include "{{snake .Module.Name}}/generated/core/{{lower $interfaceName}}.data.h"
#include "apigear/mqtt/mqttcppclient.h"

namespace {{ Camel .System.Name }} {
namespace {{ Camel .Module.Name }} {
namespace MQTT {
class {{ SNAKE .System.Name  }}_{{ SNAKE .Module.Name  }}_EXPORT {{$class}} : public {{$interfaceClass}}, public virtual ApiGear::MQTT::ISink
{
public:
    explicit {{$class}}(std::shared_ptr<ApiGear::MQTT::Client> client);
    virtual ~{{$class}}() override;

{{- range .Interface.Properties}}
{{- $property := . }}
    {{cppTypeRef "" $property}} get{{Camel $property.Name}}() const override;
    void set{{Camel $property.Name}}({{cppParam "" $property}}) override;
{{- end }}

{{- range .Interface.Operations}}
{{- $operation := . }}
    {{cppReturn "" $operation.Return}} {{lower1 $operation.Name}}({{cppParams "" $operation.Params}}) override;
    std::future<{{cppReturn "" $operation.Return}}> {{lower1 $operation.Name}}Async({{cppParams "" $operation.Params}}) override;
{{- end }}
    {{$pub_class}}& _getPublisher() const override;

    bool isReady() const;

    void onConnected() override {};
    void onSignal(const ApiGear::MQTT::Topic& topic, const std::string& args) override;
    void onPropertyChanged(const ApiGear::MQTT::Topic& topic, const std::string& args) override;
    void onInvoke(const ApiGear::MQTT::Topic&, const std::string&, const ApiGear::MQTT::Topic&, const std::string&) override {};

private:
{{- range .Interface.Properties}}
{{- $property := . }}
    void set{{Camel $property.Name}}Local({{cppParam "" $property}});
{{- end }}

    void applyState(const nlohmann::json& fields);

    bool m_isReady;
{{- if len .Interface.Properties}}
    /** Local storage for properties values. */
    {{$interfaceName}}Data m_data;
{{- end }}
    std::shared_ptr<ApiGear::MQTT::Client> m_client;

    /** The publisher for {{$interfaceName}} */
    std::unique_ptr<{{$pub_class}}> m_publisher;
};
} // namespace MQTT
} // namespace {{ Camel .Module.Name }}
} // namespace {{ Camel .System.Name }}
