{{- $module_id := snake .Module.Name -}}
{{- $module_idFirstUpper := upper1 $module_id -}}
{{- $SOURCES := printf "%s_SOURCES" $module_id -}}

find_package(apigear OPTIONAL_COMPONENTS paho-mqtt)
set (SOURCES_MQTT
{{- range .Module.Interfaces }}
{{- $interface:= . }}
    {{lower (camel $interface.Name)}}service.cpp
    {{lower (camel $interface.Name)}}client.cpp
{{- end }}
)
add_library({{$module_id}}-mqtt SHARED ${SOURCES_MQTT})
add_library({{$module_id}}::{{$module_id}}-mqtt ALIAS {{$module_id}}-mqtt)
target_include_directories({{$module_id}}-mqtt
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../../>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../../../modules>
    $<INSTALL_INTERFACE:include>
)
target_link_libraries({{$module_id}}-mqtt
    {{$module_id}}::{{$module_id}}-core
    apigear::paho-mqtt
)
# ensure maximum compiler support
if(NOT MSVC)
  target_compile_options({{$module_id}}-mqtt PRIVATE -Wall -Wextra -Wpedantic -Werror -fvisibility=hidden)
else()
  target_compile_options({{$module_id}}-mqtt PRIVATE /W4 /WX /wd4251)
endif()

install(TARGETS {{$module_id}}-mqtt
        EXPORT {{$module_idFirstUpper}}MqttTargets)
# install includes
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} DESTINATION include/{{$module_id}}/generated FILES_MATCHING PATTERN "*.h")

export(EXPORT {{$module_idFirstUpper}}MqttTargets
  NAMESPACE {{$module_id}}::
)

install(EXPORT {{$module_idFirstUpper}}MqttTargets
  FILE {{$module_idFirstUpper}}MqttTargets.cmake
  DESTINATION ${InstallDir}
  NAMESPACE {{$module_id }}::
)
