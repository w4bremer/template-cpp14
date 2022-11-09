{{- $module_id := snake .Module.Name -}}
{{- $module_idFirstUpper := upper1 $module_id -}}
{{- $SOURCES := printf "%s_SOURCES" $module_id -}}
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

set (SOURCES_CORE_IMPL
{{- range .Module.Interfaces }}
{{- $interface:= . }}
    {{lower (camel $interface.Name)}}.cpp
{{- end }}
)
add_library({{$module_id}}-implementation SHARED ${SOURCES_CORE_IMPL})
add_library({{$module_id}}::{{$module_id}}-implementation ALIAS {{$module_id}}-implementation)
target_include_directories({{$module_id}}-implementation
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../../modules>
    $<INSTALL_INTERFACE:include/{{$module_id}}>
)
target_link_libraries({{$module_id}}-implementation PUBLIC {{$module_id}}::{{$module_id}}-api {{$module_id}}::{{$module_id}}-core Threads::Threads)
# ensure maximum compiler support
if(NOT MSVC)
  target_compile_options({{$module_id}}-implementation PRIVATE -Wall -Wextra -Wpedantic -Werror -fvisibility=hidden)
else()
  target_compile_options({{$module_id}}-implementation PRIVATE /W4 /WX /wd4251)
endif()

# add test cases
if(BUILD_TESTING)
find_package(Catch2 REQUIRED)
set(CMAKE_CTEST_COMMAND ctest -V)

if(NOT TARGET check)
add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND})
endif()

set (SOURCES_TEST
    ${CMAKE_CURRENT_SOURCE_DIR}/../generated/core/{{$module_id}}.test.cpp
{{- range .Module.Interfaces }}
{{- $interface:= . }}
    {{lower (camel $interface.Name)}}.test.cpp
{{- end }}
)
add_executable(test_{{$module_id}}
    ${SOURCES_TEST}
)
target_link_libraries(test_{{$module_id}} {{$module_id}}::{{$module_id}}-implementation Catch2::Catch2)
target_include_directories(test_{{$module_id}} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})


add_test(test_{{$module_id}} test_{{$module_id}})
add_dependencies(check test_{{$module_id}})
endif(BUILD_TESTING)

install(TARGETS {{$module_id}}-implementation
        EXPORT {{$module_idFirstUpper}}ImplementationTargets
        RUNTIME DESTINATION bin                 COMPONENT Runtime
        LIBRARY DESTINATION lib                 COMPONENT Runtime
        ARCHIVE DESTINATION lib/{{$module_id}}   COMPONENT Development)
# install includes
FILE(GLOB {{$module_idFirstUpper}}_INCLUDES *.h)
install(FILES ${ {{- $module_idFirstUpper}}_INCLUDES}
        DESTINATION include/{{$module_id}})

export(EXPORT {{$module_idFirstUpper}}ImplementationTargets
  NAMESPACE {{$module_id}}::
)

install(EXPORT {{$module_idFirstUpper}}ImplementationTargets
  FILE {{$module_idFirstUpper}}ImplementationTargets.cmake
  DESTINATION ${InstallDir}
  NAMESPACE {{$module_id}}::
)