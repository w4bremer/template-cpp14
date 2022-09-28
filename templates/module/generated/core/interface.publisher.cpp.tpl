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
    std::unique_lock<std::shared_timed_mutex> lock(m_allChangesSubscribersMutex);
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
    std::unique_lock<std::shared_timed_mutex> lock(m_allChangesSubscribersMutex);
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
    // this is a short term workaround - we need a better solution for unique handle identifiers
    auto handleId = m_{{lower1 $camelProperty}}ChangedCallbackNextId++;
    std::unique_lock<std::shared_timed_mutex> lock(m_{{lower1 $camelProperty}}CallbacksMutex);
    m_{{lower1 $camelProperty}}Callbacks[handleId] = callback;
    return handleId;
}
{{- nl }}
void {{$pub_class}}::unsubscribeFrom{{$camelProperty}}Changed(long handleId)
{
    std::unique_lock<std::shared_timed_mutex> lock(m_{{lower1 $camelProperty}}CallbacksMutex);
    m_{{lower1 $camelProperty}}Callbacks.erase(handleId);
}
{{- nl }}
void {{$pub_class}}::publish{{$camelProperty}}Changed({{cppParam "" $property}}) const
{
    std::shared_lock<std::shared_timed_mutex> allChangesSubscribersLock(m_allChangesSubscribersMutex);
    const auto allChangesSubscribers = m_allChangesSubscribers;
    allChangesSubscribersLock.unlock();
    for(const auto& subscriber: allChangesSubscribers)
    {
        subscriber.get().on{{$camelProperty}}Changed({{$property.Name}});
    }
    std::shared_lock<std::shared_timed_mutex> {{lower1 $camelProperty}}CallbacksLock(m_{{lower1 $camelProperty}}CallbacksMutex);
    const auto {{lower1 $camelProperty}}Callbacks = m_{{lower1 $camelProperty}}Callbacks;
    {{lower1 $camelProperty}}CallbacksLock.unlock();
    for(const auto& callbackEntry: {{lower1 $camelProperty}}Callbacks)
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
    std::unique_lock<std::shared_timed_mutex> lock(m_{{lower1 $camelSignal}}CallbacksMutex);
    m_{{lower1 $camelSignal}}Callbacks[handleId] = callback;
    return handleId;
}
{{- nl }}
void {{$pub_class}}::unsubscribeFrom{{$camelSignal}}(long handleId)
{
    std::unique_lock<std::shared_timed_mutex> lock(m_{{lower1 $camelSignal}}CallbacksMutex);
    m_{{lower1 $camelSignal}}Callbacks.erase(handleId);
}
{{- nl }}
void {{$pub_class}}::publish{{$camelSignal}}({{cppParams "" $signal.Params}}) const
{
    std::shared_lock<std::shared_timed_mutex> allChangesSubscribersLock(m_allChangesSubscribersMutex);
    const auto allChangesSubscribers = m_allChangesSubscribers;
    allChangesSubscribersLock.unlock();
    for(const auto& subscriber: allChangesSubscribers)
    {
        subscriber.get().on{{$camelSignal}}({{cppVars $signal.Params}});
    }
    std::shared_lock<std::shared_timed_mutex> {{lower1 $camelSignal}}CallbacksLock(m_{{lower1 $camelSignal}}CallbacksMutex);
    const auto {{lower1 $camelSignal}}Callbacks = m_{{lower1 $camelSignal}}Callbacks;
    {{lower1 $camelSignal}}CallbacksLock.unlock();
    for(const auto& callbackEntry: {{lower1 $camelSignal}}Callbacks)
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
