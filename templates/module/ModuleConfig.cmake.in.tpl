{{- $module_id := snake .Module.Name -}}
{{- $module_idCamel := Camel .Module.Name -}}
{{- $module_id_up := SNAKE .Module.Name -}}
{{- $module_idFirstUpper := upper1 $module_id -}}
{{- $features := .Features -}}
set({{$module_id_up}}_VERSION {{$.Module.Version}})
@PACKAGE_INIT@

# make sure we have all needed dependencies
include(CMakeFindDependencyMacro)
find_dependency(Threads REQUIRED)
{{- if $features.core }}
find_dependency(nlohmann_json REQUIRED)
{{- end}}
{{- if $features.monitor }}
find_dependency(apigear COMPONENTS poco-tracer REQUIRED)
{{- end}}
{{- if $features.olink }}
find_dependency(apigear COMPONENTS poco-olink REQUIRED)
{{- end}}
{{- if $features.mqtt }}
find_dependency(apigear COMPONENTS paho-mqtt REQUIRED)
{{- end}}

INCLUDE("${CMAKE_CURRENT_LIST_DIR}/{{$module_idFirstUpper}}ApiTargets.cmake")
{{- if $features.core }}
INCLUDE("${CMAKE_CURRENT_LIST_DIR}/{{$module_idFirstUpper}}CoreTargets.cmake")
{{- end}}
{{- if $features.monitor }}
INCLUDE("${CMAKE_CURRENT_LIST_DIR}/{{$module_idFirstUpper}}MonitorTargets.cmake")
{{- end}}
{{- if $features.olink }}
INCLUDE("${CMAKE_CURRENT_LIST_DIR}/{{$module_idFirstUpper}}OLinkTargets.cmake")
{{- end}}
{{- if $features.mqtt }}
INCLUDE("${CMAKE_CURRENT_LIST_DIR}/{{$module_idFirstUpper}}MqttTargets.cmake")
{{- end}}
{{- if $features.stubs }}
INCLUDE("${CMAKE_CURRENT_LIST_DIR}/{{$module_idFirstUpper}}ImplementationTargets.cmake")
{{- end}}

check_required_components(
{{$module_idCamel}}-api
{{if $features.core }}{{$module_idCamel}}-core {{- end}}
{{if $features.monitor }}{{$module_idCamel}}-monitor {{- end}}
{{if $features.olink }}{{$module_idCamel}}-olink {{- end}}
{{if $features.mqtt }}{{$module_idCamel}}-mqtt {{- end}}
{{if $features.stubs }}{{$module_idCamel}}-implementation {{- end}}
)
