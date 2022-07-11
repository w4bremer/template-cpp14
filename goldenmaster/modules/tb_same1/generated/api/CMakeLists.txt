set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set (SOURCES
    tb_same1_datastructs.api.cpp
)
add_library(tb_same1-api STATIC ${SOURCES})
add_library(tb_same1::tb_same1-api ALIAS tb_same1-api)
target_include_directories(tb_same1-api
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include/tb_same1>
)
# ensure maximum compiler support
if(NOT MSVC)
  target_compile_options(tb_same1-api PRIVATE -Wall -Wextra -Wpedantic -Werror -fvisibility=hidden)
else()
  target_compile_options(tb_same1-api PRIVATE /W4 /WX /wd4251)
endif()

# install binary files
install(TARGETS tb_same1-api
        EXPORT Tb_same1ApiTargets
        RUNTIME DESTINATION bin                 COMPONENT Runtime
        LIBRARY DESTINATION lib                 COMPONENT Runtime
        ARCHIVE DESTINATION lib/tb_same1   COMPONENT Development)
# install includes
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} DESTINATION include/tb_same1/generated FILES_MATCHING PATTERN "*.h")

export(EXPORT Tb_same1ApiTargets
  NAMESPACE tb_same1::
)

install(EXPORT Tb_same1ApiTargets
  FILE Tb_same1ApiTargets.cmake
  DESTINATION ${InstallDir}
  NAMESPACE tb_same1::
)
