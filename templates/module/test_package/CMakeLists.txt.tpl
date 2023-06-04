{{- $module_id := snake .Module.Name -}}
project(Test{{$module_id}})
cmake_minimum_required(VERSION 3.1)
include(CTest)
find_package({{$module_id}} REQUIRED)

set(CMAKE_CTEST_COMMAND ctest -V)
add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND})

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# add test for {{$module_id}}
set (SOURCES_TEST
    main.cpp
)
add_executable(test_{{$module_id}} #EXCLUDE_FROM_ALL
    ${SOURCES_TEST}
)
target_link_libraries(test_{{$module_id}} {{$module_id}}::{{$module_id}}-implementation)
add_test(NAME test_{{$module_id}} COMMAND $<TARGET_FILE:test_{{$module_id}}>)
add_dependencies(check test_{{$module_id}})
# ensure maximum compiler support
if(NOT MSVC)
  target_compile_options(test_{{$module_id}} PRIVATE -Wall -Wextra -Wpedantic -Werror)
else()
  target_compile_options(test_{{$module_id}} PRIVATE /W4 /WX /wd4251)
endif()
