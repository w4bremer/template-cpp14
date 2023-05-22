{{- /* Copyright (c) ApiGear UG 2020 */ -}}
{{- $class := printf "%sService" .Interface.Name }}
{{- $interface := .Interface.Name -}}
#include "{{snake .Module.Name}}/generated/mqtt/{{lower (camel .Interface.Name)}}service.h"
#include "{{snake .Module.Name}}/generated/core/{{snake .Module.Name}}.json.adapter.h"
#include <iostream>

using namespace {{ Camel .System.Name }}::{{ Camel .Module.Name }};
using namespace {{ Camel .System.Name }}::{{ Camel .Module.Name }}::MQTT;

{{$class}}::{{$class}}(std::shared_ptr<I{{$interface}}> impl, std::shared_ptr<ApiGear::MQTT::Client> client)
    : m_impl(impl)
    , m_client(client)
{
    m_impl->_getPublisher().subscribeToAllChanges(*this);

    m_connectionStatusRegistrationID = m_client->subscribeToConnectionStatus(std::bind(&{{$class}}::onConnectionStatusChanged, this, std::placeholders::_1));
    // subscribe to all property change request methods
{{- range .Interface.Properties}}
{{- $property := . }}
    m_client->subscribeTopic(ApiGear::MQTT::Topic("{{$.Module.Name}}","{{$interface}}",ApiGear::MQTT::Topic::TopicType::Operation,"_set{{$property}}"), this);
{{- end }}
{{- range .Interface.Operations}}
{{- $operation := . }}
    m_client->subscribeTopic(ApiGear::MQTT::Topic("{{$.Module.Name}}","{{$interface}}",ApiGear::MQTT::Topic::TopicType::Operation,"{{$operation}}"), this);
{{- end }}

}

{{$class}}::~{{$class}}()
{
    m_impl->_getPublisher().unsubscribeFromAllChanges(*this);

    m_client->unsubscribeToConnectionStatus(m_connectionStatusRegistrationID);

{{- range .Interface.Properties}}
{{- $property := . }}
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("{{$.Module.Name}}","{{$interface}}",ApiGear::MQTT::Topic::TopicType::Operation,"_set{{$property}}"), this);
{{- end }}
{{- range .Interface.Operations}}
{{- $operation := . }}
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("{{$.Module.Name}}","{{$interface}}",ApiGear::MQTT::Topic::TopicType::Operation,"{{$operation}}"), this);
{{- end }}
}

void {{$class}}::onConnectionStatusChanged(bool connectionStatus)
{
    if(!connectionStatus)
    {
        return;
    }

    // send current values
{{- range .Interface.Properties}}
{{- $property := . }}
    on{{Camel $property.Name}}Changed(m_impl->get{{Camel $property.Name}}());
{{- end }}
}

void {{$class}}::onInvoke(const ApiGear::MQTT::Topic& topic, const std::string& args, const ApiGear::MQTT::Topic& responseTopic, const std::string& correlationData)
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    const std::string& name = topic.getEntityName();
{{- range .Interface.Properties}}
{{- $property := . }}
    if(name == "_set{{$property}}") {
        auto {{$property}} = json_args.get<{{cppType "" $property}}>();
        m_impl->set{{Camel $property.Name}}({{$property}});
        return;
    }
{{- end }}

{{- nl }}
{{- /* check whether any operation has a return value */}}
{{- $returnValueNeeded := false}}
{{- range .Interface.Operations }}
{{- $operation := . }}
    {{- if not ( eq (cppReturn "" $operation.Return) "void") }}{{ $returnValueNeeded = true }}{{- break }}{{- end }}
{{- end }}
{{- if not $returnValueNeeded}}
    // no operations with return value {{- /* we generate anyway for consistency */}}
    (void) responseTopic;
    (void) correlationData;
{{- end }}
{{- nl }}

{{- range .Interface.Operations}}
{{- $operation := . }}
    if(name == "{{$operation}}") {
{{- range $idx, $elem := $operation.Params }}
{{- $param := . }}
        const {{cppType "" $param}}& {{$param}} = json_args.at({{$idx}}).get<{{cppType "" $param}}>();
{{- end }}
    {{- if ( eq (cppReturn "" $operation.Return) "void") }}
        m_impl->{{lower1 $operation.Name}}({{ cppVars $operation.Params }});
    {{- else }}
        auto result = m_impl->{{lower1 $operation.Name}}({{ cppVars $operation.Params }});
        m_client->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
    {{- end}}
        return;
    }
{{- end }}
}

{{- range .Interface.Signals}}
{{- $signal := . }}
void {{$class}}::on{{Camel $signal.Name}}({{cppParams "" $signal.Params}})
{
    if(m_client != nullptr) {
        const nlohmann::json& args = { {{ cppVars $signal.Params}} };
        static const auto topic = ApiGear::MQTT::Topic("{{$.Module.Name}}","{{$interface}}",ApiGear::MQTT::Topic::TopicType::Signal,"{{$signal}}");
        m_client->notifySignal(topic, nlohmann::json(args).dump());
    }
}
{{- end }}

{{- range .Interface.Properties}}
{{- $property := . }}
void {{$class}}::on{{Camel $property.Name}}Changed({{cppParam "" $property}})
{
    if(m_client != nullptr) {
        static const auto topic = ApiGear::MQTT::Topic("{{$.Module.Name}}","{{$interface}}",ApiGear::MQTT::Topic::TopicType::Property,"{{$property}}");
        m_client->notifyPropertyChange(topic, nlohmann::json({{$property}}).dump());
    }
}
{{- end }}
