cmake_minimum_required(VERSION 3.1)
project(test)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# this target is a dummy for subprojects to add their dependencies
if(BUILD_TESTING)
set(CMAKE_CTEST_COMMAND ctest -V)

if(NOT TARGET check)
add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND})
endif()

endif(BUILD_TESTING)

# checks are workaround until generator support feature check properly
IF( IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/apigear" )
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
ENDIF()
find_package(org_objectapi_testbed QUIET)
if(NOT org_objectapi_testbed_FOUND)
  # pull org_objectapi_testbed as dependency
  message(STATUS "org_objectapi_testbed NOT FOUND, building from source folder")
  include(FetchContent)
  FetchContent_Declare(org_objectapi_testbed
    SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/modules/org_objectapi_testbed"
  )
  FetchContent_MakeAvailable(org_objectapi_testbed)
endif()
IF( IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/examples" )
add_subdirectory(examples/app)
IF( IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/examples/olinkserver" )
add_subdirectory(examples/olinkserver)
add_subdirectory(examples/olinkclient)
ENDIF()
ENDIF()
