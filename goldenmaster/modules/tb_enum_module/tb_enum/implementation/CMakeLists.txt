set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

set (SOURCES_CORE_IMPL
    enuminterface.cpp
)
add_library(tb_enum-implementation SHARED ${SOURCES_CORE_IMPL})
add_library(tb_enum::tb_enum-implementation ALIAS tb_enum-implementation)
target_include_directories(tb_enum-implementation
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../../modules>
    $<INSTALL_INTERFACE:include/tb_enum>
)
target_link_libraries(tb_enum-implementation PUBLIC tb_enum::tb_enum-api tb_enum::tb_enum-core Threads::Threads)
# ensure maximum compiler support
if(NOT MSVC)
  target_compile_options(tb_enum-implementation PRIVATE -Wall -Wextra -Wpedantic -Werror -fvisibility=hidden)
else()
  target_compile_options(tb_enum-implementation PRIVATE /W4 /WX /wd4251)
endif()

# add test cases
if(BUILD_TESTING)
if (NOT Catch2_Found)
include(FetchContent)
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG        v2.13.8
    GIT_SHALLOW    TRUE
    FIND_PACKAGE_ARGS)
FetchContent_MakeAvailable(Catch2)
endif()
set(CMAKE_CTEST_COMMAND ctest -V)

if(NOT TARGET check)
add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND})
endif()

set (SOURCES_TEST
    ${CMAKE_CURRENT_SOURCE_DIR}/../generated/core/tb_enum.test.cpp
    enuminterface.test.cpp
)
add_executable(test_tb_enum
    ${SOURCES_TEST}
)
target_link_libraries(test_tb_enum tb_enum::tb_enum-implementation Catch2::Catch2)
target_include_directories(test_tb_enum PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})


add_test(NAME test_tb_enum COMMAND $<TARGET_FILE:test_tb_enum>)
add_dependencies(check test_tb_enum)
endif(BUILD_TESTING)

install(TARGETS tb_enum-implementation
        EXPORT Tb_enumImplementationTargets
        RUNTIME DESTINATION bin                 COMPONENT Runtime
        LIBRARY DESTINATION lib                 COMPONENT Runtime
        ARCHIVE DESTINATION lib/tb_enum   COMPONENT Development)
# install includes
FILE(GLOB Tb_enum_INCLUDES *.h)
install(FILES ${Tb_enum_INCLUDES}
        DESTINATION include/tb_enum)

export(EXPORT Tb_enumImplementationTargets
  NAMESPACE tb_enum::
)

install(EXPORT Tb_enumImplementationTargets
  FILE Tb_enumImplementationTargets.cmake
  DESTINATION ${InstallDir}
  NAMESPACE tb_enum::
)
