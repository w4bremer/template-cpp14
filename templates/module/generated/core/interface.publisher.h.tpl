{{- /* Copyright (c) ApiGear UG 2020 */ -}}
#pragma once

#include "{{snake .Module.Name}}/generated/api/datastructs.api.h"
#include "{{snake .Module.Name}}/generated/api/{{lower (camel .Interface.Name)}}.api.h"
#include "{{snake .Module.Name}}/generated/api/common.h"

#include <vector>
#include <map>
#include <functional>

{{- $interfaceName := Camel .Interface.Name  }}
{{- $class := printf "I%s" $interfaceName }}
{{- $sub_class := printf "%sSubscriber" $class }}
{{- $pub_interface := printf "%sPublisher" $class }}
{{- $pub_class := printf "%sPublisher" $interfaceName }}

namespace {{ Camel .System.Name }} {
namespace {{ Camel .Module.Name }} {

/**
 * The implementation of a {{$pub_class}}.
 * Use this class to store clients of the {{.Interface.Name}} and inform them about the change
 * on call of the appropriate publish function.
 */
class {{ SNAKE .System.Name  }}_{{ SNAKE .Module.Name  }}_EXPORT {{$pub_class}} : public {{$pub_interface}}
{
public:
    /**
    * Implementation of {{$pub_interface}}::subscribeToAllChanges
    */
    void subscribeToAllChanges({{$sub_class}}& subscriber) override;
    /**
    * Implementation of {{$pub_interface}}::unsubscribeFromAllChanges
    */
    void unsubscribeFromAllChanges({{$sub_class}}& subscriber) override;
{{- nl}}
{{- range .Interface.Properties}}
{{- $property := . }}
    /**
    * Implementation of {{$pub_interface}}::subscribeTo{{Camel $property.Name}}Changed
    */
    long subscribeTo{{Camel $property.Name}}Changed({{$interfaceName}}{{Camel $property.Name}}PropertyCb callback) override;
    /**
    * Implementation of {{$pub_interface}}::subscribeTo{{Camel $property.Name}}Changed
    */
    void unsubscribeFrom{{Camel $property.Name}}Changed(long handleId) override;
{{- nl}}
{{- end }}
{{- range .Interface.Signals}}
{{- $signal := . }}
    /**
    * Implementation of {{$pub_interface}}::subscribeTo{{Camel $signal.Name}}
    */
    long subscribeTo{{Camel $signal.Name}}({{$interfaceName}}{{Camel $signal.Name}}SignalCb callback) override;
    /**
    * Implementation of {{$pub_interface}}::unsubscribeFrom{{Camel $signal.Name}}
    */
    void unsubscribeFrom{{Camel $signal.Name}}(long handleId) override;
{{- nl}}
{{- end }}
{{- range .Interface.Properties}}
{{- $property := . }}
    /**
    * Implementation of {{$pub_interface}}::publish{{Camel $property.Name}}Changed
    */
    void publish{{Camel $property.Name}}Changed({{cppParam "" $property}}) const override;
{{- end }}
{{- range .Interface.Signals}}
{{- $signal := . }}
    /**
    * Implementation of {{$pub_interface}}::publish{{Camel $signal.Name}}
    */
    void publish{{Camel $signal.Name}}({{cppParams "" $signal.Params}}) const override;
{{- end }}
private:
    // Subscribers informed about any property change or singal emited in {{.Interface.Name}}
    std::vector<std::reference_wrapper<{{$sub_class}}>> m_allChangesSubscribers;
{{- range .Interface.Properties}}
{{- $property := . }}
    // Next free unique identifier to subscribe for the {{Camel $property.Name}} change.
    long m_{{lower1 (Camel $property.Name)}}ChangedCallbackNextId = 0;
    // Subscribed callbacks for the {{Camel $property.Name}} change.
    std::map<long, {{$interfaceName}}{{Camel $property.Name}}PropertyCb> m_{{lower1 (Camel $property.Name)}}Callbacks;
{{- end }}
{{- range .Interface.Signals}}
{{- $signal := . }}
    // Next free unique identifier to subscribe for the {{Camel $signal.Name}} emission.
    long m_{{lower1 (Camel $signal.Name)}}SignalCallbackNextId = 0;
    // Subscribed callbacks for the {{Camel $signal.Name}} emission.
    std::map<long, {{$interfaceName}}{{Camel $signal.Name}}SignalCb > m_{{lower1 (Camel $signal.Name)}}Callbacks;
{{- end }}
};
{{- nl}}
} // namespace {{ Camel .Module.Name }}
} // namespace {{ Camel .System.Name }}
