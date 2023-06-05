cmake_minimum_required(VERSION 3.1)
project(test)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# on Windows it is helpful to have all binary files next to each other
# it is intentionally not set as part of BUILD_TESTING to have a consistent behavior
# this can be removed once there is a better option than modifying the PATH env for unit testing
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

option(BUILD_TESTING "Enable this option to build the test targets" OFF)

# this target is a dummy for subprojects to add their dependencies
if(BUILD_TESTING)
include(CTest)
enable_testing()
set(CMAKE_CTEST_COMMAND ctest -V)

if(NOT TARGET check)
add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND})
endif()

endif(BUILD_TESTING)

# checks are workaround until generator support feature check properly
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
find_package(testbed2 QUIET)
if(NOT testbed2_FOUND)
  # pull testbed2 as dependency
  message(STATUS "testbed2 NOT FOUND, building from source folder")
  include(FetchContent)
  FetchContent_Declare(testbed2
    SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/modules/testbed2_module/testbed2"
  )
  FetchContent_MakeAvailable(testbed2)
endif()
find_package(tb_enum QUIET)
if(NOT tb_enum_FOUND)
  # pull tb_enum as dependency
  message(STATUS "tb_enum NOT FOUND, building from source folder")
  include(FetchContent)
  FetchContent_Declare(tb_enum
    SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/modules/tb_enum_module/tb_enum"
  )
  FetchContent_MakeAvailable(tb_enum)
endif()
find_package(tb_same1 QUIET)
if(NOT tb_same1_FOUND)
  # pull tb_same1 as dependency
  message(STATUS "tb_same1 NOT FOUND, building from source folder")
  include(FetchContent)
  FetchContent_Declare(tb_same1
    SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/modules/tb_same1_module/tb_same1"
  )
  FetchContent_MakeAvailable(tb_same1)
endif()
find_package(tb_same2 QUIET)
if(NOT tb_same2_FOUND)
  # pull tb_same2 as dependency
  message(STATUS "tb_same2 NOT FOUND, building from source folder")
  include(FetchContent)
  FetchContent_Declare(tb_same2
    SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/modules/tb_same2_module/tb_same2"
  )
  FetchContent_MakeAvailable(tb_same2)
endif()
find_package(tb_simple QUIET)
if(NOT tb_simple_FOUND)
  # pull tb_simple as dependency
  message(STATUS "tb_simple NOT FOUND, building from source folder")
  include(FetchContent)
  FetchContent_Declare(tb_simple
    SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/modules/tb_simple_module/tb_simple"
  )
  FetchContent_MakeAvailable(tb_simple)
endif()
find_package(testbed1 QUIET)
if(NOT testbed1_FOUND)
  # pull testbed1 as dependency
  message(STATUS "testbed1 NOT FOUND, building from source folder")
  include(FetchContent)
  FetchContent_Declare(testbed1
    SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/modules/testbed1_module/testbed1"
  )
  FetchContent_MakeAvailable(testbed1)
endif()
add_subdirectory(examples/app)
add_subdirectory(examples/appthreadsafe)
add_subdirectory(examples/olinkserver)
add_subdirectory(examples/olinkclient)
