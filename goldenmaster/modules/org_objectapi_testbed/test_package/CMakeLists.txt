project(Testorg_objectapi_testbed)
cmake_minimum_required(VERSION 3.1)
include(CTest)
find_package(org_objectapi_testbed REQUIRED)

set(CMAKE_CTEST_COMMAND ctest -V)
add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND})

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# add test for org_objectapi_testbed
set (SOURCES_TEST
    main.cpp
)
add_executable(test_org_objectapi_testbed #EXCLUDE_FROM_ALL
    ${SOURCES_TEST}
)
target_link_libraries(test_org_objectapi_testbed org_objectapi_testbed::org_objectapi_testbed-implementation)
add_test(test_org_objectapi_testbed test_org_objectapi_testbed)
add_dependencies(check test_org_objectapi_testbed)
# ensure maximum compiler support
if(NOT MSVC)
  target_compile_options(test_org_objectapi_testbed PRIVATE -Wall -Wextra -Wpedantic -Werror)
else()
  target_compile_options(test_org_objectapi_testbed PRIVATE /W4 /WX /wd4251)
endif()
