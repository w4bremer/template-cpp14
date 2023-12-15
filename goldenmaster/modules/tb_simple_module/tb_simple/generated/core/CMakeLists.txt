set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(nlohmann_json QUIET)
if(NOT nlohmann_json_FOUND)
  # pull nlohmann json as dependency
  message(STATUS "nlohmann_json NOT FOUND, fetching the release package")
  include(FetchContent)
  set(JSON_Install ON)
  FetchContent_Declare(json
  GIT_REPOSITORY https://github.com/nlohmann/json
  GIT_TAG v3.7.3)
  FetchContent_MakeAvailable(json)
endif()

set (SOURCES_CORE_SUPPORT
    tb_simple.json.adapter.cpp
    voidinterface.publisher.cpp
    voidinterface.threadsafedecorator.cpp
    simpleinterface.publisher.cpp
    simpleinterface.threadsafedecorator.cpp
    simplearrayinterface.publisher.cpp
    simplearrayinterface.threadsafedecorator.cpp
    nopropertiesinterface.publisher.cpp
    nopropertiesinterface.threadsafedecorator.cpp
    nooperationsinterface.publisher.cpp
    nooperationsinterface.threadsafedecorator.cpp
    nosignalsinterface.publisher.cpp
    nosignalsinterface.threadsafedecorator.cpp
)
add_library(tb_simple-core SHARED ${SOURCES_CORE_SUPPORT})
add_library(tb_simple::tb_simple-core ALIAS tb_simple-core)
target_include_directories(tb_simple-core
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../../>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../../../modules>
    $<INSTALL_INTERFACE:include/tb_simple>
)
target_link_libraries(tb_simple-core PUBLIC tb_simple::tb_simple-api nlohmann_json::nlohmann_json)
# ensure maximum compiler support
if(NOT MSVC)
  target_compile_options(tb_simple-core PRIVATE -Wall -Wextra -Wpedantic -Werror -fvisibility=hidden)
else()
  target_compile_options(tb_simple-core PRIVATE /W4 /WX /wd4251)
endif()

install(TARGETS tb_simple-core
        EXPORT Tb_simpleCoreTargets)
# install includes
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} DESTINATION include/tb_simple/generated FILES_MATCHING PATTERN "*.h")

export(EXPORT Tb_simpleCoreTargets
  NAMESPACE tb_simple::
)

install(EXPORT Tb_simpleCoreTargets
  FILE Tb_simpleCoreTargets.cmake
  DESTINATION ${InstallDir}
  NAMESPACE tb_simple::
)
