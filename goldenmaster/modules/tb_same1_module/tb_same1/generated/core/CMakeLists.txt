set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(nlohmann_json REQUIRED)

set (SOURCES_CORE_SUPPORT
    tb_same1.json.adapter.cpp
    samestruct1interface.publisher.cpp
    samestruct2interface.publisher.cpp
    sameenum1interface.publisher.cpp
    sameenum2interface.publisher.cpp
)
add_library(tb_same1-core SHARED ${SOURCES_CORE_SUPPORT})
add_library(tb_same1::tb_same1-core ALIAS tb_same1-core)
target_include_directories(tb_same1-core
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../../>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../../../modules>
    $<INSTALL_INTERFACE:include/tb_same1>
)
target_link_libraries(tb_same1-core PUBLIC tb_same1::tb_same1-api nlohmann_json::nlohmann_json)
# ensure maximum compiler support
if(NOT MSVC)
  target_compile_options(tb_same1-core PRIVATE -Wall -Wextra -Wpedantic -Werror -fvisibility=hidden)
else()
  target_compile_options(tb_same1-core PRIVATE /W4 /WX /wd4251)
endif()

install(TARGETS tb_same1-core
        EXPORT Tb_same1CoreTargets
        RUNTIME DESTINATION bin                 COMPONENT Runtime
        LIBRARY DESTINATION lib                 COMPONENT Runtime
        ARCHIVE DESTINATION lib/tb_same1   COMPONENT Development)
# install includes
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} DESTINATION include/tb_same1/generated FILES_MATCHING PATTERN "*.h")

export(EXPORT Tb_same1CoreTargets
  NAMESPACE tb_same1::
)

install(EXPORT Tb_same1CoreTargets
  FILE Tb_same1CoreTargets.cmake
  DESTINATION ${InstallDir}
  NAMESPACE tb_same1::
)
