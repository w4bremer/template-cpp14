{{- $module_id := snake .Module.Name}}
{{- $module_idFirstUpper := upper1 $module_id}}
{{- $isApiHeaderOnly := and (eq (len .Module.Enums) 0) (eq (len .Module.Structs) 0) -}}
{{- $SOURCES := printf "%s_SOURCES" $module_id -}}
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
{{ if (eq $isApiHeaderOnly false) }}
set (SOURCES
    datastructs.api.cpp
)
add_library({{$module_id}}-api SHARED ${SOURCES})
add_library({{$module_id}}::{{$module_id}}-api ALIAS {{$module_id}}-api)
target_include_directories({{$module_id}}-api
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../../>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../../../modules>
    $<INSTALL_INTERFACE:include/{{$module_id}}>
)
# ensure maximum compiler support
if(NOT MSVC)
  target_compile_options({{$module_id}}-api PRIVATE -Wall -Wextra -Wpedantic -Werror -fvisibility=hidden)
else()
  target_compile_options({{$module_id}}-api PRIVATE /W4 /WX /wd4251)
endif()
{{- else -}}
add_library({{$module_id}}-api INTERFACE)
add_library({{$module_id}}::{{$module_id}}-api ALIAS {{$module_id}}-api)
target_include_directories({{$module_id}}-api
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../../>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../../../modules>
    $<INSTALL_INTERFACE:include/{{$module_id}}>
)
{{- end}}

# install binary files
install(TARGETS {{$module_id}}-api
        EXPORT {{$module_idFirstUpper}}ApiTargets
        RUNTIME DESTINATION bin                 COMPONENT Runtime
        LIBRARY DESTINATION lib                 COMPONENT Runtime
        ARCHIVE DESTINATION lib/{{$module_id}}   COMPONENT Development)
# install includes
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} DESTINATION include/{{$module_id}}/generated FILES_MATCHING PATTERN "*.h")

export(EXPORT {{$module_idFirstUpper}}ApiTargets
  NAMESPACE {{snake .Module.Name}}::
)

install(EXPORT {{$module_idFirstUpper}}ApiTargets
  FILE {{$module_idFirstUpper}}ApiTargets.cmake
  DESTINATION ${InstallDir}
  NAMESPACE {{snake .Module.Name}}::
)