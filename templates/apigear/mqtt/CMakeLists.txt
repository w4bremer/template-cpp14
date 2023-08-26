find_package(nlohmann_json QUIET)
if(NOT nlohmann_json_FOUND)
  # pull nlohmann json as dependency
  message(STATUS "nlohmann_json NOT FOUND, fetching the release package")
  include(FetchContent)
  set(JSON_Install ON)
  FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.10.5/json.tar.xz)
  FetchContent_MakeAvailable(json)
endif()

find_package(eclipse-paho-mqtt-c REQUIRED paho-mqtt3as-static)
find_package(OpenSSL REQUIRED SSL Crypto)

set (SOURCES
  private/mqttcwrapper.cpp
  mqttclient.cpp
  mqttservice.cpp
)
add_library(paho-mqtt SHARED ${SOURCES})
add_library(apigear::paho-mqtt ALIAS paho-mqtt)
target_include_directories(paho-mqtt PUBLIC 
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../>
    $<INSTALL_INTERFACE:include>
)
target_link_libraries(paho-mqtt PRIVATE eclipse-paho-mqtt-c::paho-mqtt3as-static PUBLIC nlohmann_json::nlohmann_json utilities)

if(NOT MSVC)
  target_compile_options(paho-mqtt PRIVATE -Wall -Wextra -Wpedantic -Werror -fvisibility=hidden -Wno-unknown-pragmas)
else()
  target_compile_options(paho-mqtt PRIVATE /W4 /WX /wd4251)
endif()

# add test cases
if(BUILD_TESTING)
enable_testing()
find_package(Catch2 REQUIRED)

set (SOURCES_TEST
    ../apigear.test.cpp
)
add_executable(test_mqtt ${SOURCES_TEST})
target_include_directories(test_mqtt PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(test_mqtt paho-mqtt Catch2::Catch2)

add_test(NAME test_mqtt COMMAND $<TARGET_FILE:test_mqtt>)
endif(BUILD_TESTING)

# install binary files
install(TARGETS paho-mqtt
        EXPORT ApiGearPahoMQTTTargets
        RUNTIME DESTINATION bin           COMPONENT Runtime
        LIBRARY DESTINATION lib           COMPONENT Runtime
        ARCHIVE DESTINATION lib/apigear   COMPONENT Development)
# install includes
FILE(GLOB APIGEAR_INCLUDES *.h)
install(FILES ${APIGEAR_INCLUDES}
        DESTINATION include/apigear/mqtt)

export(EXPORT ApiGearPahoMQTTTargets
  NAMESPACE apigear::
)

install(EXPORT ApiGearPahoMQTTTargets
  FILE ApiGearPahoMQTTTargets.cmake
  DESTINATION ${InstallDir}
  NAMESPACE apigear::
)
