set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

set (SOURCES_CORE_IMPL
    tb_simple_simpleinterface.cpp
    tb_simple_simplearrayinterface.cpp
)
add_library(tb_simple-implementation STATIC ${SOURCES_CORE_IMPL})
add_library(tb_simple::tb_simple-implementation ALIAS tb_simple-implementation)
target_include_directories(tb_simple-implementation
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include/tb_simple>
)
target_link_libraries(tb_simple-implementation PUBLIC tb_simple::tb_simple-api tb_simple::tb_simple-core Threads::Threads)
# ensure maximum compiler support
if(NOT MSVC)
  target_compile_options(tb_simple-implementation PRIVATE -Wall -Wextra -Wpedantic -Werror -fvisibility=hidden)
else()
  target_compile_options(tb_simple-implementation PRIVATE /W4 /WX /wd4251)
endif()

# add test cases
if(BUILD_TESTING)
find_package(Catch2 REQUIRED)
set(CMAKE_CTEST_COMMAND ctest -V)

if(NOT TARGET check)
add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND})
endif()

set (SOURCES_TEST
    ${CMAKE_CURRENT_SOURCE_DIR}/../generated/core/tb_simple.test.cpp
    simpleinterface.test.cpp
    simplearrayinterface.test.cpp
)
add_executable(test_tb_simple EXCLUDE_FROM_ALL
    ${SOURCES_TEST}
)
target_link_libraries(test_tb_simple tb_simple::tb_simple-implementation Catch2::Catch2)
target_include_directories(test_tb_simple PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})


add_test(test_tb_simple test_tb_simple)
add_dependencies(check test_tb_simple)
endif(BUILD_TESTING)

install(TARGETS tb_simple-implementation
        EXPORT Tb_simpleImplementationTargets
        RUNTIME DESTINATION bin                 COMPONENT Runtime
        LIBRARY DESTINATION lib                 COMPONENT Runtime
        ARCHIVE DESTINATION lib/tb_simple   COMPONENT Development)
# install includes
FILE(GLOB Tb_simple_INCLUDES *.h)
install(FILES ${Tb_simple_INCLUDES}
        DESTINATION include/tb_simple)

export(EXPORT Tb_simpleImplementationTargets
  NAMESPACE tb_simple::
)

install(EXPORT Tb_simpleImplementationTargets
  FILE Tb_simpleImplementationTargets.cmake
  DESTINATION ${InstallDir}
  NAMESPACE tb_simple::
)