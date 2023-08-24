{{- /* Copyright (c) ApiGear UG 2020 */ -}}
{{- $class := printf "%sService" .Interface.Name }}
{{- $interface := .Interface.Name -}}
#include "{{snake .Module.Name}}/generated/mqtt/{{lower (camel .Interface.Name)}}service.h"
#include "{{snake .Module.Name}}/generated/core/{{snake .Module.Name}}.json.adapter.h"
#include "apigear/mqtt/mqtttopic.h"
#include <iostream>

using namespace {{ Camel .System.Name }}::{{ Camel .Module.Name }};
using namespace {{ Camel .System.Name }}::{{ Camel .Module.Name }}::MQTT;

{{$class}}::{{$class}}(std::shared_ptr<I{{$interface}}> impl, std::shared_ptr<ApiGear::MQTT::Service> service)
    : m_impl(impl)
    , m_service(service)
{
    m_impl->_getPublisher().subscribeToAllChanges(*this);

    m_connectionStatusRegistrationID = m_service->subscribeToConnectionStatus(std::bind(&{{$class}}::onConnectionStatusChanged, this, std::placeholders::_1));
    // subscribe to all property change request methods
{{- range .Interface.Properties}}
{{- $property := . }}
    m_service->subscribeTopic(std::string("{{$.Module.Name}}/{{$interface}}/set/{{$property}}"), std::bind(&{{$class}}::onSetProperty, this, std::placeholders::_1, std::placeholders::_2));
{{- end }}
{{- range .Interface.Operations}}
{{- $operation := . }}
    m_service->subscribeTopic(std::string("{{$.Module.Name}}/{{$interface}}/rpc/{{$operation}}"), std::bind(&{{$class}}::onInvoke, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
{{- end }}

}

{{$class}}::~{{$class}}()
{
    m_impl->_getPublisher().unsubscribeFromAllChanges(*this);

    m_service->unsubscribeToConnectionStatus(m_connectionStatusRegistrationID);

{{- range .Interface.Properties}}
{{- $property := . }}
    m_service->unsubscribeTopic(std::string("{{$.Module.Name}}/{{$interface}}/set/{{$property}}"), std::bind(&{{$class}}::onSetProperty, this, std::placeholders::_1, std::placeholders::_2));
{{- end }}
{{- range .Interface.Operations}}
{{- $operation := . }}
    m_service->unsubscribeTopic(std::string("{{$.Module.Name}}/{{$interface}}/rpc/{{$operation}}"), std::bind(&{{$class}}::onInvoke, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
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

void {{$class}}::onSetProperty(const std::string& topic, const std::string& args)
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    const std::string& name = ApiGear::MQTT::Topic(topic).getEntityName();
{{- range .Interface.Properties}}
{{- $property := . }}
    if(name == "{{$property}}") {
        auto {{$property}} = json_args.get<{{cppType "" $property}}>();
        m_impl->set{{Camel $property.Name}}({{$property}});
        return;
    }
{{- else }}
    (void) name;
{{- end }}
}

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
