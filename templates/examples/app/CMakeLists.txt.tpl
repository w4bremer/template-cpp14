project(App)
cmake_minimum_required(VERSION 3.1)

# append local binary directory for conan packages to be found
set(CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR} ${CMAKE_MODULE_PATH})

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set (SOURCES
    main.cpp
)
add_executable(app
    ${SOURCES}
)
{{- $features := .Features}}
{{- range .System.Modules }}
{{- $module_id := snake .Name }}
find_package({{$module_id}} QUIET COMPONENTS {{$module_id}}-core {{$module_id}}-implementation {{ if $features.monitor }}{{$module_id}}-monitor {{- end}})
{{- end }}
target_link_libraries(app
{{- range .System.Modules }}
{{- $module_id := snake .Name }}
    {{$module_id}}::{{$module_id}}-core
    {{$module_id}}::{{$module_id}}-implementation
    {{ if $features.monitor }}{{$module_id}}::{{$module_id}}-monitor {{- end}}
{{- end }}
)

install(TARGETS app
        RUNTIME DESTINATION bin COMPONENT Runtime)
