set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set (SOURCES_CORE_IMPL
    org_objectapi_testbed_interface1.cpp
    org_objectapi_testbed_interface2.cpp
)
add_library(org_objectapi_testbed-implementation STATIC ${SOURCES_CORE_IMPL})
add_library(org_objectapi_testbed::implementation ALIAS org_objectapi_testbed-implementation)
target_include_directories(org_objectapi_testbed-implementation PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/../)
target_link_libraries(org_objectapi_testbed-implementation PUBLIC org_objectapi_testbed::api org_objectapi_testbed::core)
# ensure maximum compiler support
if(NOT MSVC)
  target_compile_options(org_objectapi_testbed-implementation PRIVATE -Wall -Wextra -Wpedantic -Werror -fvisibility=hidden)
else()
  target_compile_options(org_objectapi_testbed-implementation PRIVATE /W4 /WX /wd4251)
endif()

# add test cases
if(BUILD_TESTING)
find_package(Catch2 REQUIRED)
set(CMAKE_CTEST_COMMAND ctest -V)

if(NOT TARGET check)
add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND})
endif()

set (SOURCES_TEST
    ${CMAKE_CURRENT_SOURCE_DIR}/../generated/core/org_objectapi_testbed.test.cpp
    interface1.test.cpp
    interface2.test.cpp
)
add_executable(test_org_objectapi_testbed EXCLUDE_FROM_ALL
    ${SOURCES_TEST}
)
target_link_libraries(test_org_objectapi_testbed org_objectapi_testbed::implementation Catch2::Catch2)
target_include_directories(test_org_objectapi_testbed PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

add_test(test_org_objectapi_testbed test_org_objectapi_testbed)
add_dependencies(check test_org_objectapi_testbed)
endif(BUILD_TESTING)

install(TARGETS org_objectapi_testbed-implementation
        RUNTIME DESTINATION bin                 COMPONENT Runtime
        LIBRARY DESTINATION lib                 COMPONENT Runtime
        ARCHIVE DESTINATION lib/org_objectapi_testbed   COMPONENT Development)
# install includes
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} DESTINATION include FILES_MATCHING PATTERN "*.h")
