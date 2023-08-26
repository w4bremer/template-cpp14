{{- /* Copyright (c) ApiGear UG 2020 */ -}}
{{- $class := printf "%sService" .Interface.Name }}
{{- $interface := .Interface.Name -}}
#include "{{snake .Module.Name}}/generated/mqtt/{{lower (camel .Interface.Name)}}service.h"
#include "{{snake .Module.Name}}/generated/core/{{snake .Module.Name}}.json.adapter.h"
#include "apigear/mqtt/mqtttopic.h"
#include <iostream>

using namespace {{ Camel .System.Name }}::{{ Camel .Module.Name }};
using namespace {{ Camel .System.Name }}::{{ Camel .Module.Name }}::MQTT;

namespace {
    std::map<std::string, ApiGear::MQTT::CallbackFunction> createTopicMap({{$class}}* service)
    {
        return {
        {{- range .Interface.Properties}}
        {{- $property := . }}
            {std::string("{{$.Module.Name}}/{{$interface}}/set/{{$property}}"), [service](const std::string&, const std::string& args, const std::string&, const std::string&){ service->onSet{{Camel $property.Name}}(args); } },
        {{- end }}
        {{- range .Interface.Operations}}
        {{- $operation := . }}
            {std::string("{{$.Module.Name}}/{{$interface}}/rpc/{{$operation}}"), [service](const std::string& topic, const std::string& args, const std::string& responseTopic, const std::string& correlationData) { service->onInvoke(topic, args, responseTopic, correlationData); } },
        {{- end }}
        };
    };
}

{{$class}}::{{$class}}(std::shared_ptr<I{{$interface}}> impl, std::shared_ptr<ApiGear::MQTT::Service> service)
    : m_impl(impl)
    , m_service(service)
    , m_topics(createTopicMap(this))
{
    m_impl->_getPublisher().subscribeToAllChanges(*this);

    m_connectionStatusRegistrationID = m_service->subscribeToConnectionStatus([this](bool connectionStatus){ onConnectionStatusChanged(connectionStatus); });

    for (const auto& topic: m_topics)
    {
        m_service->subscribeTopic(topic. first, topic.second);
    }
}

{{$class}}::~{{$class}}()
{
    m_impl->_getPublisher().unsubscribeFromAllChanges(*this);

    m_service->unsubscribeToConnectionStatus(m_connectionStatusRegistrationID);

    for (const auto& topic: m_topics)
    {
        m_service->unsubscribeTopic(topic. first);
    }
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

{{- range .Interface.Properties}}
{{- $property := . }}
void {{$class}}::onSet{{Camel $property.Name}}(const std::string& args) const
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    if (json_args.empty())
    {
        return;
    }

    auto {{$property}} = json_args.get<{{cppType "" $property}}>();
    m_impl->set{{Camel $property.Name}}({{$property}});
}
{{- end }}

void {{$class}}::onInvoke(const std::string& topic, const std::string& args, const std::string& responseTopic, const std::string& correlationData)
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    const std::string& name = ApiGear::MQTT::Topic(topic).getEntityName();

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
    (void) name;
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
        m_service->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
    {{- end}}
        return;
    }
{{- end }}
}

{{- range .Interface.Signals}}
{{- $signal := . }}
void {{$class}}::on{{Camel $signal.Name}}({{cppParams "" $signal.Params}})
{
    if(m_service != nullptr) {
        const nlohmann::json& args = { {{ cppVars $signal.Params}} };
        static const auto topic = std::string("{{$.Module.Name}}/{{$interface}}/sig/{{$signal}}");
        m_service->notifySignal(topic, nlohmann::json(args).dump());
    }
}
{{- end }}

{{- range .Interface.Properties}}
{{- $property := . }}
void {{$class}}::on{{Camel $property.Name}}Changed({{cppParam "" $property}})
{
    if(m_service != nullptr) {
        static const auto topic = std::string("{{$.Module.Name}}/{{$interface}}/prop/{{$property}}");
        m_service->notifyPropertyChange(topic, nlohmann::json({{$property}}).dump());
    }
}
{{- end }}
