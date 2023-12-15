cmake_minimum_required(VERSION 3.20)
project(MQTTClient)

# append local binary directory for conan packages to be found
set(CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR} ${CMAKE_MODULE_PATH})

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set (SOURCES
    main.cpp
)
add_executable(MQTTClient
    ${SOURCES}
)

find_package(apigear QUIET COMPONENTS utilities)
{{- range .System.Modules }}
{{- $module_id := snake .Name }}
find_package({{$module_id}} QUIET COMPONENTS {{$module_id}}-core {{$module_id}}-mqtt)
{{- end }}
target_link_libraries(MQTTClient
    apigear::utilities
{{- range .System.Modules }}
{{- $module_id := snake .Name }}
    {{$module_id}}::{{$module_id}}-core
    {{$module_id}}::{{$module_id}}-mqtt
{{- end }}
)

# we assume that the examples are built together with the libraries and thus ignore this warning
if(MSVC)
  target_compile_options(MQTTClient PRIVATE /wd4251)
endif()

install(TARGETS MQTTClient
        RUNTIME DESTINATION bin COMPONENT Runtime)
