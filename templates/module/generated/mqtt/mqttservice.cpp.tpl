{{- /* Copyright (c) ApiGear UG 2020 */ -}}
{{- $class := printf "%sService" .Interface.Name }}
{{- $interface := .Interface.Name -}}
#include "{{snake .Module.Name}}/generated/mqtt/{{lower (camel .Interface.Name)}}service.h"
#include "{{snake .Module.Name}}/generated/core/{{snake .Module.Name}}.json.adapter.h"
#include <iostream>

using namespace {{ Camel .System.Name }}::{{ Camel .Module.Name }};
using namespace {{ Camel .System.Name }}::{{ Camel .Module.Name }}::MQTT;

{{$class}}::{{$class}}(std::shared_ptr<I{{$interface}}> impl, std::shared_ptr<ApiGear::MQTT::Service> service)
    : m_impl(impl)
    , m_service(service)
    , m_topics(createTopicMap())
{
    m_impl->_getPublisher().subscribeToAllChanges(*this);

    m_connectionStatusRegistrationID = m_service->subscribeToConnectionStatus([this](bool connectionStatus){ onConnectionStatusChanged(connectionStatus); });
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

std::map<std::string, ApiGear::MQTT::CallbackFunction> {{$class}}::createTopicMap()
{
    return {
    {{- range .Interface.Properties}}
    {{- $property := . }}
        {std::string("{{$.Module.Name}}/{{$interface}}/set/{{$property}}"), [this](const std::string& args, const std::string&, const std::string&){ this->onSet{{Camel $property.Name}}(args); } },
    {{- end }}
    {{- range .Interface.Operations}}
    {{- $operation := . }}
        {std::string("{{$.Module.Name}}/{{$interface}}/rpc/{{$operation}}"), [this](const std::string& args, const std::string& responseTopic, const std::string& correlationData) { this->onInvoke{{ Camel $operation.Name }}(args, responseTopic, correlationData); } },
    {{- end }}
    };
}

void {{$class}}::onConnectionStatusChanged(bool connectionStatus)
{
    if(!connectionStatus)
    {
        return;
    }

    for (const auto& topic: m_topics)
    {
        m_service->subscribeTopic(topic. first, topic.second);
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

{{- range .Interface.Operations}}
{{- $operation := . }}
void {{$class}}::onInvoke{{ Camel $operation.Name }}(const std::string& args, const std::string& responseTopic, const std::string& correlationData) const
{
    nlohmann::json json_args = nlohmann::json::parse(args);

{{- if .Return.IsVoid }}
    (void) responseTopic;
    (void) correlationData;
{{- else }}
    std::string responseTopicReturn = responseTopic;
    if (responseTopicReturn.empty())
    {
        responseTopicReturn = std::string("{{$.Module.Name}}/{{$interface}}/rpc/{{$operation}}/" + json_args.at(1).get<std::string>() + "/result");
    }
    int responseId = 0;
    if (correlationData.empty())
    {
        responseId = json_args.at(0).get<int>();
    }
    else
    {
        responseId = std::stoi(correlationData);
    }
{{- end }}

{{- if len $operation.Params }}
    nlohmann::json payload = json_args.at(2);
{{- end }}
{{- range $idx, $elem := $operation.Params }}
{{- $param := . }}
    const {{cppType "" $param}}& {{$param}} = payload.at({{$idx}}).get<{{cppType "" $param}}>();
{{- end }}
{{- if .Return.IsVoid }}
    m_impl->{{lower1 $operation.Name}}({{ cppVars $operation.Params }});
{{- else }}
    auto result = m_impl->{{lower1 $operation.Name}}({{ cppVars $operation.Params }});
    m_service->notifyInvokeResponse(responseTopicReturn, nlohmann::json::array({responseId, result}).dump(), std::to_string(responseId));
{{- end }}
}
{{- end }}

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
