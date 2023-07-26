cmake_minimum_required(VERSION 3.1)
project(MQTTServer)

# append local binary directory for conan packages to be found
set(CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR} ${CMAKE_MODULE_PATH})

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set (SOURCES
    main.cpp
)
add_executable(MQTTServer
    ${SOURCES}
)

find_package(apigear QUIET COMPONENTS utilities)
{{- range .System.Modules }}
{{- $module_id := snake .Name }}
find_package({{$module_id}} QUIET COMPONENTS {{$module_id}}-core {{$module_id}}-implementation {{$module_id}}-mqtt)
{{- end }}
target_link_libraries(MQTTServer
    apigear::utilities
{{- range .System.Modules }}
{{- $module_id := snake .Name }}
    {{$module_id}}::{{$module_id}}-core
    {{$module_id}}::{{$module_id}}-implementation
    {{$module_id}}::{{$module_id}}-mqtt
{{- end }}
)

# we assume that the examples are built together with the libraries and thus ignore this warning
if(MSVC)
  target_compile_options(MQTTServer PRIVATE /wd4251)
endif()

install(TARGETS MQTTServer
        RUNTIME DESTINATION bin COMPONENT Runtime)
