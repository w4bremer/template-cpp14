cmake_minimum_required(VERSION 3.20)
project(AppThreadSafe)

# append local binary directory for conan packages to be found
list(APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set (SOURCES
    main.cpp
)
add_executable(appthreadsafe
    ${SOURCES}
)

# ensure maximum compiler support
if(NOT MSVC)
  target_compile_options(appthreadsafe PRIVATE -Wall -Wextra -Wpedantic -Werror -fvisibility=hidden)
else()
  target_compile_options(appthreadsafe PRIVATE /W4 /WX /wd4251)
endif()

find_package(testbed2 QUIET COMPONENTS testbed2-core testbed2-implementation)
find_package(tb_enum QUIET COMPONENTS tb_enum-core tb_enum-implementation)
find_package(tb_same1 QUIET COMPONENTS tb_same1-core tb_same1-implementation)
find_package(tb_same2 QUIET COMPONENTS tb_same2-core tb_same2-implementation)
find_package(tb_simple QUIET COMPONENTS tb_simple-core tb_simple-implementation)
find_package(testbed1 QUIET COMPONENTS testbed1-core testbed1-implementation)
find_package(tb_names QUIET COMPONENTS tb_names-core tb_names-implementation)
target_link_libraries(appthreadsafe
    testbed2::testbed2-core
    testbed2::testbed2-implementation
    tb_enum::tb_enum-core
    tb_enum::tb_enum-implementation
    tb_same1::tb_same1-core
    tb_same1::tb_same1-implementation
    tb_same2::tb_same2-core
    tb_same2::tb_same2-implementation
    tb_simple::tb_simple-core
    tb_simple::tb_simple-implementation
    testbed1::testbed1-core
    testbed1::testbed1-implementation
    tb_names::tb_names-core
    tb_names::tb_names-implementation
)

install(TARGETS appthreadsafe
        RUNTIME DESTINATION bin COMPONENT Runtime)
