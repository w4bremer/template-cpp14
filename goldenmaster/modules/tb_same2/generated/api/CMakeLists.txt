set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set (SOURCES
    tb_same2_datastructs.api.cpp
)
add_library(tb_same2-api SHARED ${SOURCES})
add_library(tb_same2::tb_same2-api ALIAS tb_same2-api)
target_include_directories(tb_same2-api
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include/tb_same2>
)
# ensure maximum compiler support
if(NOT MSVC)
  target_compile_options(tb_same2-api PRIVATE -Wall -Wextra -Wpedantic -Werror -fvisibility=hidden)
else()
  target_compile_options(tb_same2-api PRIVATE /W4 /WX /wd4251)
endif()

# install binary files
install(TARGETS tb_same2-api
        EXPORT Tb_same2ApiTargets
        RUNTIME DESTINATION bin                 COMPONENT Runtime
        LIBRARY DESTINATION lib                 COMPONENT Runtime
        ARCHIVE DESTINATION lib/tb_same2   COMPONENT Development)
# install includes
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} DESTINATION include/tb_same2/generated FILES_MATCHING PATTERN "*.h")

export(EXPORT Tb_same2ApiTargets
  NAMESPACE tb_same2::
)

install(EXPORT Tb_same2ApiTargets
  FILE Tb_same2ApiTargets.cmake
  DESTINATION ${InstallDir}
  NAMESPACE tb_same2::
)
