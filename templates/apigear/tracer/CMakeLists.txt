include(CTest)

find_package(nlohmann_json QUIET)
if(NOT nlohmann_json_FOUND)
  # pull nlohmann json as dependency
  message(STATUS "nlohmann_json NOT FOUND, fetching the release package")
  include(FetchContent)
  set(JSON_Install ON)
  FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.10.5/json.tar.xz)
  FetchContent_MakeAvailable(json)
endif()

find_package(Poco REQUIRED Foundation Net Util)

set (SOURCES
    tracer.cpp
)
add_library(poco-tracer SHARED ${SOURCES})
add_library(apigear::poco-tracer ALIAS poco-tracer)
target_include_directories(poco-tracer
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../>
    $<INSTALL_INTERFACE:include>)
target_link_libraries(poco-tracer Poco::Net Poco::Util nlohmann_json::nlohmann_json)

# add test cases
if(BUILD_TESTING)
find_package(Catch2 REQUIRED)
set(CMAKE_CTEST_COMMAND ctest -V)

if(NOT TARGET check)
add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND})
endif()

set (SOURCES_TEST
    ../apigear.test.cpp
    tracer.test.cpp
)
add_executable(test_tracer EXCLUDE_FROM_ALL
    ${SOURCES_TEST}
)
target_include_directories(test_tracer PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(test_tracer apigear::poco-tracer Poco::Net Poco::Util Catch2::Catch2)

add_test(test_tracer test_tracer)
add_dependencies(check test_tracer)
endif(BUILD_TESTING)

# install binary files
install(TARGETS poco-tracer
        EXPORT ApiGearPocoTracerTargets
        RUNTIME DESTINATION bin           COMPONENT Runtime
        LIBRARY DESTINATION lib           COMPONENT Runtime
        ARCHIVE DESTINATION lib/apigear   COMPONENT Development)
# install includes
FILE(GLOB APIGEAR_INCLUDES *.h)
install(FILES ${APIGEAR_INCLUDES}
        DESTINATION include/apigear/tracer)

export(EXPORT ApiGearPocoTracerTargets
    NAMESPACE apigear::
)

install(EXPORT ApiGearPocoTracerTargets
    FILE ApiGearPocoTracerTargets.cmake
    DESTINATION ${InstallDir}
    NAMESPACE apigear::
)
