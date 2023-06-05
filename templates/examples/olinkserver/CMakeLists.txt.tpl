cmake_minimum_required(VERSION 3.1)
project(OLinkServer)

# append local binary directory for conan packages to be found
list(APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set (SOURCES
    main.cpp
)
add_executable(OLinkServer
    ${SOURCES}
)

# ensure maximum compiler support
if(NOT MSVC)
  target_compile_options(OLinkServer PRIVATE -Wall -Wextra -Wpedantic -Werror -fvisibility=hidden)
else()
  target_compile_options(OLinkServer PRIVATE /W4 /WX /wd4251)
endif()
{{- nl }}

{{- range .System.Modules }}
{{- $module_id := snake .Name }}
find_package({{$module_id}} QUIET COMPONENTS {{$module_id}}-core {{$module_id}}-implementation {{$module_id}}-olink)
{{- end }}
target_link_libraries(OLinkServer
{{- range .System.Modules }}
{{- $module_id := snake .Name }}
    {{$module_id}}::{{$module_id}}-core
    {{$module_id}}::{{$module_id}}-implementation
    {{$module_id}}::{{$module_id}}-olink
{{- end }}
)

install(TARGETS OLinkServer
        RUNTIME DESTINATION bin COMPONENT Runtime)
