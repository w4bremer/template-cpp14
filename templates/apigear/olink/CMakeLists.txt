

find_package(objectlink-core-cpp QUIET)
if(NOT objectlink-core-cpp_FOUND)
  # pull objectlink-core-cpp as dependency
  message(STATUS "objectlink-core-cpp NOT FOUND, fetching the git repository")
  include(FetchContent)
  FetchContent_Declare(objectlink-core-cpp
      GIT_REPOSITORY https://github.com/apigear-io/objectlink-core-cpp
      GIT_TAG v0.1.4
      GIT_SHALLOW TRUE
      EXCLUDE_FROM_ALL FALSE
  )
  FetchContent_MakeAvailable(objectlink-core-cpp)
endif()

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
# workaround for broken poco conan package
# can hopefully be removed with later verions than 1.11.1
IF (TARGET PCRE::PCRE)
  add_library(Pcre::Pcre ALIAS PCRE::PCRE)
ENDIF()

set (SOURCES
    olinkhost.cpp
    olinkclient.cpp
)
add_library(poco-olink SHARED ${SOURCES})
add_library(apigear::poco-olink ALIAS poco-olink)
target_include_directories(poco-olink
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../>
    $<INSTALL_INTERFACE:include>
)
target_link_libraries(poco-olink PUBLIC Poco::Net Poco::Util olink_core)

# install binary files
install(TARGETS poco-olink
        EXPORT ApiGearPocoOlinkTargets
        RUNTIME DESTINATION bin           COMPONENT Runtime
        LIBRARY DESTINATION lib           COMPONENT Runtime
        ARCHIVE DESTINATION lib/apigear   COMPONENT Development)
# install includes
FILE(GLOB APIGEAR_INCLUDES *.h)
install(FILES ${APIGEAR_INCLUDES}
        DESTINATION include/apigear/olink)

export(EXPORT ApiGearPocoOlinkTargets
  NAMESPACE apigear::
)

install(EXPORT ApiGearPocoOlinkTargets
  FILE ApiGearPocoOlinkTargets.cmake
  DESTINATION ${InstallDir}
  NAMESPACE apigear::
)
