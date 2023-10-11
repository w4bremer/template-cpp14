set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

set (SOURCES_CORE_IMPL
    names.cpp
)
add_library(tb_names-implementation SHARED ${SOURCES_CORE_IMPL})
add_library(tb_names::tb_names-implementation ALIAS tb_names-implementation)
target_include_directories(tb_names-implementation
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../../modules>
    $<INSTALL_INTERFACE:include/tb_names>
)
target_link_libraries(tb_names-implementation PUBLIC tb_names::tb_names-api tb_names::tb_names-core Threads::Threads)
# ensure maximum compiler support
if(NOT MSVC)
  target_compile_options(tb_names-implementation PRIVATE -Wall -Wextra -Wpedantic -Werror -fvisibility=hidden)
else()
  target_compile_options(tb_names-implementation PRIVATE /W4 /WX /wd4251)
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

set (SOURCES_TEST
    ${CMAKE_CURRENT_SOURCE_DIR}/../generated/core/tb_names.test.cpp
    names.test.cpp
)
add_executable(test_tb_names
    ${SOURCES_TEST}
)
target_link_libraries(test_tb_names tb_names::tb_names-implementation Catch2::Catch2)
target_include_directories(test_tb_names PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# ensure maximum compiler support
if(NOT MSVC)
  target_compile_options(test_tb_names PRIVATE -Wall -Wextra -Wpedantic -Werror -fvisibility=hidden)
else()
  target_compile_options(test_tb_names PRIVATE /W4 /WX /wd4251)
endif()

add_test(NAME test_tb_names COMMAND $<TARGET_FILE:test_tb_names>)
endif(BUILD_TESTING)

install(TARGETS tb_names-implementation
        EXPORT Tb_namesImplementationTargets
        RUNTIME DESTINATION bin                 COMPONENT Runtime
        LIBRARY DESTINATION lib                 COMPONENT Runtime
        ARCHIVE DESTINATION lib/tb_names   COMPONENT Development)
# install includes
FILE(GLOB Tb_names_INCLUDES *.h)
install(FILES ${Tb_names_INCLUDES}
        DESTINATION include/tb_names)

export(EXPORT Tb_namesImplementationTargets
  NAMESPACE tb_names::
)

install(EXPORT Tb_namesImplementationTargets
  FILE Tb_namesImplementationTargets.cmake
  DESTINATION ${InstallDir}
  NAMESPACE tb_names::
)
