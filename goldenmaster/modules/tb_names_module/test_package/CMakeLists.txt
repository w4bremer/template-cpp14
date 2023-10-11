project(Testtb_names)
cmake_minimum_required(VERSION 3.1)
include(CTest)
find_package(tb_names REQUIRED)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# add test for tb_names
set (SOURCES_TEST
    main.cpp
)
add_executable(test_tb_names
    ${SOURCES_TEST}
)
target_link_libraries(test_tb_names tb_names::tb_names-implementation)
add_test(NAME test_tb_names COMMAND $<TARGET_FILE:test_tb_names>)
# ensure maximum compiler support
if(NOT MSVC)
  target_compile_options(test_tb_names PRIVATE -Wall -Wextra -Wpedantic -Werror)
else()
  target_compile_options(test_tb_names PRIVATE /W4 /WX /wd4251)
endif()
