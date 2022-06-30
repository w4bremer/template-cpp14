set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

set (SOURCES
    tb_enum_datastructs.api.cpp
)
add_library(tb_enum-api STATIC ${SOURCES})
add_library(tb_enum::tb_enum-api ALIAS tb_enum-api)
target_include_directories(tb_enum-api
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include/tb_enum>
)
target_link_libraries(tb_enum-api PUBLIC Threads::Threads)
# ensure maximum compiler support
if(NOT MSVC)
  target_compile_options(tb_enum-api PRIVATE -Wall -Wextra -Wpedantic -Werror -fvisibility=hidden)
else()
  target_compile_options(tb_enum-api PRIVATE /W4 /WX /wd4251)
endif()

# install binary files
install(TARGETS tb_enum-api
        EXPORT Tb_enumApiTargets
        RUNTIME DESTINATION bin                 COMPONENT Runtime
        LIBRARY DESTINATION lib                 COMPONENT Runtime
        ARCHIVE DESTINATION lib/tb_enum   COMPONENT Development)
# install includes
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} DESTINATION include/tb_enum/generated FILES_MATCHING PATTERN "*.h")

export(EXPORT Tb_enumApiTargets
  NAMESPACE tb_enum::
)

install(EXPORT Tb_enumApiTargets
  FILE Tb_enumApiTargets.cmake
  DESTINATION ${InstallDir}
  NAMESPACE tb_enum::
)
