set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

set (SOURCES_CORE_IMPL
    tb_same2_samestruct1interface.cpp
    tb_same2_samestruct2interface.cpp
    tb_same2_sameenum1interface.cpp
    tb_same2_sameenum2interface.cpp
)
add_library(tb_same2-implementation SHARED ${SOURCES_CORE_IMPL})
add_library(tb_same2::tb_same2-implementation ALIAS tb_same2-implementation)
target_include_directories(tb_same2-implementation
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include/tb_same2>
)
target_link_libraries(tb_same2-implementation PUBLIC tb_same2::tb_same2-api tb_same2::tb_same2-core Threads::Threads)
# ensure maximum compiler support
if(NOT MSVC)
  target_compile_options(tb_same2-implementation PRIVATE -Wall -Wextra -Wpedantic -Werror -fvisibility=hidden)
else()
  target_compile_options(tb_same2-implementation PRIVATE /W4 /WX /wd4251)
endif()

# add test cases
if(BUILD_TESTING)
find_package(Catch2 REQUIRED)
set(CMAKE_CTEST_COMMAND ctest -V)

if(NOT TARGET check)
add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND})
endif()

set (SOURCES_TEST
    ${CMAKE_CURRENT_SOURCE_DIR}/../generated/core/tb_same2.test.cpp
    samestruct1interface.test.cpp
    samestruct2interface.test.cpp
    sameenum1interface.test.cpp
    sameenum2interface.test.cpp
)
add_executable(test_tb_same2 EXCLUDE_FROM_ALL
    ${SOURCES_TEST}
)
target_link_libraries(test_tb_same2 tb_same2::tb_same2-implementation Catch2::Catch2)
target_include_directories(test_tb_same2 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})


add_test(test_tb_same2 test_tb_same2)
add_dependencies(check test_tb_same2)
endif(BUILD_TESTING)

install(TARGETS tb_same2-implementation
        EXPORT Tb_same2ImplementationTargets
        RUNTIME DESTINATION bin                 COMPONENT Runtime
        LIBRARY DESTINATION lib                 COMPONENT Runtime
        ARCHIVE DESTINATION lib/tb_same2   COMPONENT Development)
# install includes
FILE(GLOB Tb_same2_INCLUDES *.h)
install(FILES ${Tb_same2_INCLUDES}
        DESTINATION include/tb_same2)

export(EXPORT Tb_same2ImplementationTargets
  NAMESPACE tb_same2::
)

install(EXPORT Tb_same2ImplementationTargets
  FILE Tb_same2ImplementationTargets.cmake
  DESTINATION ${InstallDir}
  NAMESPACE tb_same2::
)