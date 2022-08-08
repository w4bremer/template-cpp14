project(Testtb_same1)
cmake_minimum_required(VERSION 3.1)
include(CTest)
find_package(tb_same1 REQUIRED)

set(CMAKE_CTEST_COMMAND ctest -V)
add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND})

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# add test for tb_same1
set (SOURCES_TEST
    main.cpp
)
add_executable(test_tb_same1 #EXCLUDE_FROM_ALL
    ${SOURCES_TEST}
)
target_link_libraries(test_tb_same1 tb_same1::tb_same1-implementation)
add_test(test_tb_same1 test_tb_same1)
add_dependencies(check test_tb_same1)
# ensure maximum compiler support
if(NOT MSVC)
  target_compile_options(test_tb_same1 PRIVATE -Wall -Wextra -Wpedantic -Werror)
else()
  target_compile_options(test_tb_same1 PRIVATE /W4 /WX /wd4251)
endif()
