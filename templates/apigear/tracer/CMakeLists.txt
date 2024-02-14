include(CTest)

find_package(nlohmann_json REQUIRED)
find_package(Poco REQUIRED Foundation Net Util)

set (SOURCES
    tracer.cpp
)
add_library(poco-tracer SHARED ${SOURCES})
add_library(apigear::poco-tracer ALIAS poco-tracer)
target_include_directories(poco-tracer
    PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../>
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../>
    $<INSTALL_INTERFACE:include>
)
target_link_libraries(poco-tracer PUBLIC Poco::Net Poco::Util Poco::Foundation nlohmann_json::nlohmann_json PRIVATE apigear::utilities)

# add test cases
if(BUILD_TESTING)
find_package(Catch2 REQUIRED)

set (SOURCES_TEST
    ../apigear.test.cpp
    tracer.test.cpp
)
add_executable(test_tracer
    ${SOURCES_TEST}
)
target_include_directories(test_tracer PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(test_tracer PRIVATE apigear::poco-tracer Catch2::Catch2)

add_test(NAME test_tracer COMMAND $<TARGET_FILE:test_tracer>)
endif(BUILD_TESTING)

# install binary files
install(TARGETS poco-tracer
        EXPORT ApiGearPocoTracerTargets)
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
