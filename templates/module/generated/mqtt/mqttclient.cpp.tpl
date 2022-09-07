{{- /* Copyright (c) ApiGear UG 2020 */ -}}
{{- $interfaceName := Camel .Interface.Name  }}
{{- $class := printf "%sClient" .Interface.Name }}
{{- $pub_interface := printf "I%sPublisher" $interfaceName }}
{{- $pub_class := printf "%sPublisher" $interfaceName -}}
#include "{{snake .Module.Name}}/generated/mqtt/{{lower (camel .Interface.Name)}}client.h"
#include "{{snake .Module.Name}}/generated/core/{{lower (camel .Interface.Name)}}.publisher.h"
#include "{{snake .Module.Name}}/generated/core/{{snake .Module.Name}}.json.adapter.h"

using namespace {{ Camel .System.Name }}::{{ Camel .Module.Name }};
using namespace {{ Camel .System.Name }}::{{ Camel .Module.Name }}::mqtt;

{{$class}}::{{$class}}(std::shared_ptr<ApiGear::MQTTImpl::Client> client)
    : m_isReady(false)
    , m_client(client)
    , m_publisher(std::make_unique<{{$pub_class}}>())
{
{{- range .Interface.Properties}}
{{- $property := . }}
    m_client->subscribeTopic(ApiGear::MQTTImpl::Topic("{{$.Module.Name}}","{{$interfaceName}}",ApiGear::MQTTImpl::Topic::TopicType::Property,"{{$property}}"), this);
{{- end }}
{{- range .Interface.Signals}}
{{- $signal := . }}
    m_client->subscribeTopic(ApiGear::MQTTImpl::Topic("{{$.Module.Name}}","{{$interfaceName}}",ApiGear::MQTTImpl::Topic::TopicType::Signal,"{{$signal}}"), this);
{{- end }}
{{- range .Interface.Operations}}
{{- $operation := . }}
    m_client->subscribeTopic(ApiGear::MQTTImpl::Topic("{{$.Module.Name}}","{{$interfaceName}}",ApiGear::MQTTImpl::Topic::TopicType::Operation,"{{$operation}}",m_client->getClientId()+"/result"), nullptr);
{{- end }}
}

{{$class}}::~{{$class}}()
{
{{- range .Interface.Properties}}
{{- $property := . }}
    m_client->unsubscribeTopic(ApiGear::MQTTImpl::Topic("{{$.Module.Name}}","{{$interfaceName}}",ApiGear::MQTTImpl::Topic::TopicType::Property,"{{$property}}"), this);
{{- end }}
{{- range .Interface.Signals}}
{{- $signal := . }}
    m_client->unsubscribeTopic(ApiGear::MQTTImpl::Topic("{{$.Module.Name}}","{{$interfaceName}}",ApiGear::MQTTImpl::Topic::TopicType::Signal,"{{$signal}}"), this);
{{- end }}
{{- range .Interface.Operations}}
{{- $operation := . }}
    m_client->unsubscribeTopic(ApiGear::MQTTImpl::Topic("{{$.Module.Name}}","{{$interfaceName}}",ApiGear::MQTTImpl::Topic::TopicType::Operation,"{{$operation}}",m_client->getClientId()+"/result"), nullptr);
{{- end }}
}

void {{$class}}::applyState(const nlohmann::json& fields) 
{
{{- range .Interface.Properties}}
{{- $property := . }}
    if(fields.contains("{{$property.Name}}")) {
        set{{Camel $property.Name}}Local(fields["{{$property.Name}}"].get<{{cppType "" $property}}>());
    }
{{- else -}}
    // no properties to apply state {{- /* we generate anyway for consistency */}}
    (void) fields;
{{- end }}
}

{{- range .Interface.Properties}}
{{- $property := . }}
{{- $name := $property.Name }}

void {{$class}}::set{{Camel $name}}({{cppParam "" $property}})
{
    if(m_client == nullptr) {
        return;
    }
    static const auto topic = ApiGear::MQTTImpl::Topic("{{.Module.Name}}","{{$interfaceName}}",ApiGear::MQTTImpl::Topic::TopicType::Operation,"_set{{$property}}");
    m_client->setRemoteProperty(topic, nlohmann::json({{$property}}).dump());
}

void {{$class}}::set{{Camel $name}}Local({{cppParam "" $property }})
{
    if (m_data.m_{{$name}} != {{$name}}) {
        m_data.m_{{$name}} = {{$name}};
        m_publisher->publish{{Camel $name}}Changed({{$name}});
    }
}

{{cppTypeRef "" $property}} {{$class}}::get{{Camel $name}}() const
{
    return m_data.m_{{$name}};
}

{{- end }}

{{- range .Interface.Operations}}
{{- $operation := . }}
{{- $returnType := cppReturn "" $operation.Return }}

{{$returnType}} {{$class}}::{{lower1 $operation.Name}}({{cppParams "" $operation.Params}})
{
    if(m_client == nullptr) {
        {{- if not ( eq (cppReturn "" $operation.Return) "void") }}
        return {{cppDefault "" $operation.Return}};
        {{- else }}
        return;
        {{- end }}
    }
    {{- if ( eq (cppReturn "" $operation.Return) "void") }}
    {{- else }}
    {{$returnType}} value({{lower1 $operation.Name}}Async({{ cppVars $operation.Params }}).get());
    return value;
    {{- end }}
}

std::future<{{$returnType}}> {{$class}}::{{lower1 $operation.Name}}Async({{cppParams "" $operation.Params}})
{
    if(m_client == nullptr) {
        throw std::runtime_error("Client is not initialized");
    }
    return std::async(std::launch::async, [this{{- range $operation.Params -}},
                    {{.Name}}
                {{- end -}}]()
        {
            std::promise<{{$returnType}}> resultPromise;
            static const auto topic = ApiGear::MQTTImpl::Topic("{{$.Module.Name}}","{{$interfaceName}}",ApiGear::MQTTImpl::Topic::TopicType::Operation,"{{$operation}}");
            m_client->invokeRemote(topic,
                nlohmann::json::array({ {{- cppVars $operation.Params -}} }).dump(), [&resultPromise](ApiGear::MQTTImpl::InvokeReplyArg arg) {
                    {{- if ( eq (cppReturn "" $operation.Return) "void") }}
                    (void) arg;
                    resultPromise.set_value();
                    {{- else }}
                    const {{$returnType}}& value = arg.value.get<{{$returnType}}>();
                    resultPromise.set_value(value);
                    {{- end }}
                });
            return resultPromise.get_future().get();
        }
    );
}

{{- end }}

void {{$class}}::onSignal(const ApiGear::MQTTImpl::Topic& topic, const std::string& args)
{
    nlohmann::json json_args = nlohmann::json::parse(args);
{{- range .Interface.Signals}}
{{- $signal := . }}
    if(topic.getEntityName() == "{{$signal}}") {
        m_publisher->publish{{Camel $signal.Name }}(
{{- range $idx, $elem := $signal.Params }}
{{- $param := . -}}
        {{- if $idx }},{{- end -}}
        json_args[{{$idx}}].get<{{cppType "" $param}}>()
{{- end -}}
        );
        return;
    }
{{- else }}
    (void) args;
    (void) topic;
{{- end }}
}

void {{$class}}::onPropertyChanged(const ApiGear::MQTTImpl::Topic& topic, const std::string& args)
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    const std::string& name = topic.getEntityName();
    applyState({ {name, json_args} });
    return;
}

bool {{$class}}::isReady() const
{
    return m_isReady;
}

{{$pub_interface}}& {{$class}}::_getPublisher() const
{
    return *m_publisher;
}
