include(CTest)

find_package(Poco REQUIRED Foundation Net Util)
# workaround for broken poco conan package
# can hopefully be removed with later verions than 1.11.1
IF (TARGET PCRE::PCRE)
  set_target_properties(PCRE::PCRE PROPERTIES IMPORTED_GLOBAL TRUE)
  add_library(Pcre::Pcre ALIAS PCRE::PCRE)
ENDIF()
find_package(nlohmann_json REQUIRED)

set (SOURCES
    tracer.cpp
)
add_library(apigear-poco-tracer SHARED ${SOURCES})
add_library(apigear::poco-tracer ALIAS apigear-poco-tracer)
target_include_directories(apigear-poco-tracer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(apigear-poco-tracer Poco::Net Poco::Util nlohmann_json::nlohmann_json)

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
install(TARGETS apigear-poco-tracer
        RUNTIME DESTINATION bin           COMPONENT Runtime
        LIBRARY DESTINATION lib           COMPONENT Runtime
        ARCHIVE DESTINATION lib/apigear   COMPONENT Development)
# install includes
FILE(GLOB APIGEAR_INCLUDES *.h)
install(FILES ${APIGEAR_INCLUDES}
        DESTINATION include/apigear)
