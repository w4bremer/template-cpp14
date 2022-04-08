project(App)
cmake_minimum_required(VERSION 3.1)

# append local binary directory for conan packages to be found
set(CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR} ${CMAKE_MODULE_PATH})

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set (SOURCES
    main.cpp
)
add_executable(app
    ${SOURCES}
)
find_package(org_objectapi_testbed OPTIONAL_COMPONENTS core implementation monitor)
target_link_libraries(app
    org_objectapi_testbed::core
    org_objectapi_testbed::implementation
    org_objectapi_testbed::monitor
)

install(TARGETS app
        RUNTIME DESTINATION bin COMPONENT Runtime)
