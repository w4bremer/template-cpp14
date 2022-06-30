set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

set (SOURCES
    tb_simple_datastructs.api.cpp
)
add_library(tb_simple-api STATIC ${SOURCES})
add_library(tb_simple::tb_simple-api ALIAS tb_simple-api)
target_include_directories(tb_simple-api
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include/tb_simple>
)
target_link_libraries(tb_simple-api PUBLIC Threads::Threads)
# ensure maximum compiler support
if(NOT MSVC)
  target_compile_options(tb_simple-api PRIVATE -Wall -Wextra -Wpedantic -Werror -fvisibility=hidden)
else()
  target_compile_options(tb_simple-api PRIVATE /W4 /WX /wd4251)
endif()

# install binary files
install(TARGETS tb_simple-api
        EXPORT Tb_simpleApiTargets
        RUNTIME DESTINATION bin                 COMPONENT Runtime
        LIBRARY DESTINATION lib                 COMPONENT Runtime
        ARCHIVE DESTINATION lib/tb_simple   COMPONENT Development)
# install includes
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} DESTINATION include/tb_simple/generated FILES_MATCHING PATTERN "*.h")

export(EXPORT Tb_simpleApiTargets
  NAMESPACE tb_simple::
)

install(EXPORT Tb_simpleApiTargets
  FILE Tb_simpleApiTargets.cmake
  DESTINATION ${InstallDir}
  NAMESPACE tb_simple::
)
