cmake_minimum_required(VERSION 3.1)
project(OLinkClient)

# append local binary directory for conan packages to be found
list(APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set (SOURCES
    main.cpp
)
add_executable(OLinkClient
    ${SOURCES}
)

# ensure maximum compiler support
if(NOT MSVC)
  target_compile_options(OLinkClient PRIVATE -Wall -Wextra -Wpedantic -Werror -fvisibility=hidden)
else()
  target_compile_options(OLinkClient PRIVATE /W4 /WX /wd4251)
  # disable the warning for getenv - needs better cross platform solution
  target_compile_definitions(OLinkClient PRIVATE -D_CRT_SECURE_NO_WARNINGS)
endif()

find_package(apigear QUIET COMPONENTS utilities)
{{- $features := .Features}}
{{- range .System.Modules }}
{{- $module_id := snake .Name }}
find_package({{$module_id}} QUIET COMPONENTS {{$module_id}}-core {{$module_id}}-implementation 
{{- if $features.monitor }} {{$module_id}}-monitor {{- end }} {{$module_id}}-olink)
{{- end }}
target_link_libraries(OLinkClient
{{- range .System.Modules }}
{{- $module_id := snake .Name }}
    {{$module_id}}::{{$module_id}}-core
    {{$module_id}}::{{$module_id}}-implementation
{{ if $features.monitor }}    {{$module_id}}::{{$module_id}}-monitor {{- end }}
    {{$module_id}}::{{$module_id}}-olink
{{- end }}
)

install(TARGETS OLinkClient
        RUNTIME DESTINATION bin COMPONENT Runtime)
