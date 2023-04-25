cmake_minimum_required(VERSION 3.1)
project(OLinkServer)

# append local binary directory for conan packages to be found
set(CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR} ${CMAKE_MODULE_PATH})

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set (SOURCES
    main.cpp
)
add_executable(OLinkServer
    ${SOURCES}
)
find_package(testbed2 QUIET COMPONENTS testbed2-core testbed2-implementation testbed2-olink)
find_package(tb_enum QUIET COMPONENTS tb_enum-core tb_enum-implementation tb_enum-olink)
find_package(tb_same1 QUIET COMPONENTS tb_same1-core tb_same1-implementation tb_same1-olink)
find_package(tb_same2 QUIET COMPONENTS tb_same2-core tb_same2-implementation tb_same2-olink)
find_package(tb_simple QUIET COMPONENTS tb_simple-core tb_simple-implementation tb_simple-olink)
find_package(testbed1 QUIET COMPONENTS testbed1-core testbed1-implementation testbed1-olink)
target_link_libraries(OLinkServer
    testbed2::testbed2-core
    testbed2::testbed2-implementation
    testbed2::testbed2-olink
    tb_enum::tb_enum-core
    tb_enum::tb_enum-implementation
    tb_enum::tb_enum-olink
    tb_same1::tb_same1-core
    tb_same1::tb_same1-implementation
    tb_same1::tb_same1-olink
    tb_same2::tb_same2-core
    tb_same2::tb_same2-implementation
    tb_same2::tb_same2-olink
    tb_simple::tb_simple-core
    tb_simple::tb_simple-implementation
    tb_simple::tb_simple-olink
    testbed1::testbed1-core
    testbed1::testbed1-implementation
    testbed1::testbed1-olink
)

install(TARGETS OLinkServer
        RUNTIME DESTINATION bin COMPONENT Runtime)
