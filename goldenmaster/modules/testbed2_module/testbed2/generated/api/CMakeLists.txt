set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set (SOURCES
    datastructs.api.cpp
)
add_library(testbed2-api SHARED ${SOURCES})
add_library(testbed2::testbed2-api ALIAS testbed2-api)
target_include_directories(testbed2-api
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../../>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../../../modules>
    $<INSTALL_INTERFACE:include/testbed2>
)
# ensure maximum compiler support
if(NOT MSVC)
  target_compile_options(testbed2-api PRIVATE -Wall -Wextra -Wpedantic -Werror -fvisibility=hidden)
else()
  target_compile_options(testbed2-api PRIVATE /W4 /WX /wd4251)
endif()

# install binary files
install(TARGETS testbed2-api
        EXPORT Testbed2ApiTargets
        RUNTIME DESTINATION bin                 COMPONENT Runtime
        LIBRARY DESTINATION lib                 COMPONENT Runtime
        ARCHIVE DESTINATION lib/testbed2   COMPONENT Development)
# install includes
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} DESTINATION include/testbed2/generated FILES_MATCHING PATTERN "*.h")

export(EXPORT Testbed2ApiTargets
  NAMESPACE testbed2::
)

install(EXPORT Testbed2ApiTargets
  FILE Testbed2ApiTargets.cmake
  DESTINATION ${InstallDir}
  NAMESPACE testbed2::
)
