cmake_minimum_required(VERSION 3.20)
project(poco-olink)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

include(FetchContent)

find_package(olink_core QUIET)
if(NOT olink_core_FOUND)
  # disable olink core tests
  set(BUILD_TESTING OFF)
  # pull olink_core as dependency
  message(STATUS "olink_core NOT FOUND, fetching the git repository")
  FetchContent_Declare(olink-core
      GIT_REPOSITORY https://github.com/apigear-io/objectlink-core-cpp.git
      GIT_TAG v0.2.6
      GIT_SHALLOW TRUE
      EXCLUDE_FROM_ALL FALSE
  )
  FetchContent_MakeAvailable(olink-core)
endif()

find_package(nlohmann_json QUIET)
if(NOT nlohmann_json_FOUND)
  # pull nlohmann json as dependency
  message(STATUS "nlohmann_json NOT FOUND, fetching the release package")
  set(JSON_Install ON)
  FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.10.5/json.tar.xz)
  FetchContent_MakeAvailable(json)
endif()

find_package(Poco REQUIRED Foundation Net Util)

set (SOURCES
    olinkhost.cpp
    olinkconnection.cpp
    private/olinkremote.cpp
    private/olinkwebsockethandler.cpp
    private/requesthandlerfactory.cpp
    private/connectionstorage.cpp
    private/socketwrapper.cpp
)
add_library(poco-olink SHARED ${SOURCES})
add_library(apigear::poco-olink ALIAS poco-olink)
target_include_directories(poco-olink
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(poco-olink PUBLIC Poco::Net Poco::Util olink_core apigear::utilities)


# install binary files
install(TARGETS poco-olink
        EXPORT ApiGearPocoOlinkTargets)
# install includes
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} DESTINATION include/apigear FILES_MATCHING PATTERN "*.h")

export(EXPORT ApiGearPocoOlinkTargets
  NAMESPACE apigear::
)

install(EXPORT ApiGearPocoOlinkTargets
  FILE ApiGearPocoOlinkTargets.cmake
  DESTINATION ${InstallDir}
  NAMESPACE apigear::
)

add_subdirectory (tests)
