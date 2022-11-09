{{- /* Copyright (c) ApiGear UG 2020 */ -}}

{{- $interfaceName := Camel .Interface.Name  }}
{{- $class := printf "I%s" $interfaceName }}
{{- $sub_class := printf "%sSubscriber" $class }}
{{- $pub_class := printf "%sPublisher" $interfaceName }}

#include "{{snake .Module.Name}}/generated/core/{{lower (camel .Interface.Name)}}.publisher.h"
#include <algorithm>
{{ nl }}
using namespace {{ Camel .System.Name }}::{{ Camel .Module.Name }};

void {{$pub_class}}::subscribeToAllChanges({{$sub_class}}& subscriber)
{
    auto found = std::find_if(m_allChangesSubscribers.begin(), m_allChangesSubscribers.end(),
                        [&subscriber](const auto element){return &(element.get()) == &subscriber;});
    if (found == m_allChangesSubscribers.end())
    {
        m_allChangesSubscribers.push_back(std::reference_wrapper<{{$sub_class}}>(subscriber));
    }
}
{{- nl }}
void {{$pub_class}}::unsubscribeFromAllChanges({{$sub_class}}& subscriber)
{
    auto found = std::find_if(m_allChangesSubscribers.begin(), m_allChangesSubscribers.end(),
                        [&subscriber](const auto element){return &(element.get()) == &subscriber;});
    if (found != m_allChangesSubscribers.end())
    {
        m_allChangesSubscribers.erase(found);
    }
}
{{- nl }}
{{- range .Interface.Properties}}
{{- $property := . }}
{{- $camelProperty := Camel .Name }}
long {{$pub_class}}::subscribeTo{{$camelProperty}}Changed({{$interfaceName}}{{$camelProperty}}PropertyCb callback)
{
    auto handleId = m_{{lower1 $camelProperty}}ChangedCallbackNextId++;
    m_{{lower1 $camelProperty}}Callbacks[handleId] = callback;
    return handleId;
}
{{- nl }}
void {{$pub_class}}::unsubscribeFrom{{$camelProperty}}Changed(long handleId)
{
    m_{{lower1 $camelProperty}}Callbacks.erase(handleId);
}
{{- nl }}
void {{$pub_class}}::publish{{$camelProperty}}Changed({{cppParam "" $property}}) const
{
    for(const auto& subscriber: m_allChangesSubscribers)
    {
        subscriber.get().on{{$camelProperty}}Changed({{$property.Name}});
    }
    for(const auto& callbackEntry: m_{{lower1 $camelProperty}}Callbacks)
    {
        {{- /* TODO clean up subscriber if subscriber is not valid anymore */}}
        if(callbackEntry.second)
        {
            callbackEntry.second({{$property.Name}});
        }
    }
}
{{- nl }}
{{- end }}

{{- range .Interface.Signals}}
{{- $signal := . }}
{{- $camelSignal := Camel .Name }}
long {{$pub_class}}::subscribeTo{{$camelSignal}}({{$interfaceName}}{{$camelSignal}}SignalCb callback)
{
    // this is a short term workaround - we need a better solution for unique handle identifiers
    auto handleId = m_{{lower1 $camelSignal}}SignalCallbackNextId++;
    m_{{lower1 $camelSignal}}Callbacks[handleId] = callback;
    return handleId;
}
{{- nl }}
void {{$pub_class}}::unsubscribeFrom{{$camelSignal}}(long handleId)
{
    m_{{lower1 $camelSignal}}Callbacks.erase(handleId);
}
{{- nl }}
void {{$pub_class}}::publish{{$camelSignal}}({{cppParams "" $signal.Params}}) const
{
    for(const auto& subscriber: m_allChangesSubscribers)
    {
        subscriber.get().on{{$camelSignal}}({{cppVars $signal.Params}});
    }
    for(const auto& callbackEntry: m_{{lower1 $camelSignal}}Callbacks)
    {
        {{- /* TODO clean up subscriber if subscriber is not valid anymore */}}
        if(callbackEntry.second)
        {
            callbackEntry.second({{cppVars $signal.Params}});
        }
    }
}
{{- nl }}
{{- end }}
