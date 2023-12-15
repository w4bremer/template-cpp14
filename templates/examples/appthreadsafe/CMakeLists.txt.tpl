cmake_minimum_required(VERSION 3.20)
project(AppThreadSafe)

# append local binary directory for conan packages to be found
list(APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set (SOURCES
    main.cpp
)
add_executable(appthreadsafe
    ${SOURCES}
)

# ensure maximum compiler support
if(NOT MSVC)
  target_compile_options(appthreadsafe PRIVATE -Wall -Wextra -Wpedantic -Werror -fvisibility=hidden)
else()
  target_compile_options(appthreadsafe PRIVATE /W4 /WX /wd4251)
endif()
{{- nl }}

{{- range .System.Modules }}
{{- $module_id := snake .Name }}
find_package({{$module_id}} QUIET COMPONENTS {{$module_id}}-core {{$module_id}}-implementation)
{{- end }}
target_link_libraries(appthreadsafe
{{- range .System.Modules }}
{{- $module_id := snake .Name }}
    {{$module_id}}::{{$module_id}}-core
    {{$module_id}}::{{$module_id}}-implementation
{{- end }}
)

install(TARGETS appthreadsafe
        RUNTIME DESTINATION bin COMPONENT Runtime)
