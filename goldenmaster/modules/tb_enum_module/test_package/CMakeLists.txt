project(Testtb_enum)
cmake_minimum_required(VERSION 3.1)
include(CTest)
find_package(tb_enum REQUIRED)

set(CMAKE_CTEST_COMMAND ctest -V)
add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND})

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# add test for tb_enum
set (SOURCES_TEST
    main.cpp
)
add_executable(test_tb_enum #EXCLUDE_FROM_ALL
    ${SOURCES_TEST}
)
target_link_libraries(test_tb_enum tb_enum::tb_enum-implementation)
add_test(NAME test_tb_enum COMMAND $<TARGET_FILE:test_tb_enum>)
add_dependencies(check test_tb_enum)
# ensure maximum compiler support
if(NOT MSVC)
  target_compile_options(test_tb_enum PRIVATE -Wall -Wextra -Wpedantic -Werror)
else()
  target_compile_options(test_tb_enum PRIVATE /W4 /WX /wd4251)
endif()
