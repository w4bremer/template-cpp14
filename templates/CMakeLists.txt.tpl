cmake_minimum_required(VERSION 3.1)
project({{lower1 (camel .System.Name)}})

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# on Windows it is helpful to have all binary files next to each other
# it is intentionally not set as part of BUILD_TESTING to have a consistent behavior
# this can be removed once there is a better option than modifying the PATH env for unit testing
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

option(BUILD_TESTING "Enable this option to build the test targets" OFF)

# enable testing
if(BUILD_TESTING)
include(CTest)
enable_testing()
endif(BUILD_TESTING)

# checks are workaround until generator support feature check properly
{{- if .Features.apigear }}
find_package(apigear QUIET)
if(NOT apigear_FOUND)
  # pull apigear as dependency
  message(STATUS "apigear NOT FOUND, building from source folder")
  include(FetchContent)
  FetchContent_Declare(apigear
    SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/apigear"
  )
  FetchContent_MakeAvailable(apigear)
endif()
{{- end }}

{{- range .System.Modules }}
{{- $module_id := snake .Name}}
find_package({{$module_id}} QUIET)
if(NOT {{$module_id}}_FOUND)
  # pull {{$module_id}} as dependency
  message(STATUS "{{$module_id}} NOT FOUND, building from source folder")
  include(FetchContent)
  FetchContent_Declare({{$module_id}}
    SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/modules/{{$module_id}}_module/{{$module_id}}"
  )
  FetchContent_MakeAvailable({{$module_id}})
endif()
{{- end }}

{{- if .Features.examples }}
add_subdirectory(examples/app)
add_subdirectory(examples/appthreadsafe)
{{- end }}
{{- if .Features.examples_olink }}
add_subdirectory(examples/olinkserver)
add_subdirectory(examples/olinkclient)
{{- end }}
