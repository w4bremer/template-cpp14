project(Testtb_simple)
cmake_minimum_required(VERSION 3.1)
include(CTest)
find_package(tb_simple REQUIRED)

set(CMAKE_CTEST_COMMAND ctest -V)
add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND})

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# add test for tb_simple
set (SOURCES_TEST
    main.cpp
)
add_executable(test_tb_simple #EXCLUDE_FROM_ALL
    ${SOURCES_TEST}
)
target_link_libraries(test_tb_simple tb_simple::tb_simple-implementation)
add_test(test_tb_simple test_tb_simple)
add_dependencies(check test_tb_simple)
# ensure maximum compiler support
if(NOT MSVC)
  target_compile_options(test_tb_simple PRIVATE -Wall -Wextra -Wpedantic -Werror)
else()
  target_compile_options(test_tb_simple PRIVATE /W4 /WX /wd4251)
endif()
