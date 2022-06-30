set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(apigear QUIET COMPONENTS poco-tracer)
set (SOURCES_MONITOR
    testbed2.trace.cpp
    testbed2_manyparaminterface.trace.cpp
    testbed2_nestedstruct1interface.trace.cpp
    testbed2_nestedstruct2interface.trace.cpp
    testbed2_nestedstruct3interface.trace.cpp
)
add_library(testbed2-monitor SHARED ${SOURCES_MONITOR})
add_library(testbed2::testbed2-monitor ALIAS testbed2-monitor)
target_include_directories(testbed2-monitor
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include/testbed2>
)
target_link_libraries(testbed2-monitor PUBLIC
    testbed2::testbed2-core
    apigear::poco-tracer
)
# ensure maximum compiler support
if(NOT MSVC)
  target_compile_options(testbed2-monitor PRIVATE -Wall -Wextra -Wpedantic -Werror -fvisibility=hidden)
else()
  target_compile_options(testbed2-monitor PRIVATE /W4 /WX /wd4251)
endif()

install(TARGETS testbed2-monitor
        EXPORT Testbed2MonitorTargets
        RUNTIME DESTINATION bin                 COMPONENT Runtime
        LIBRARY DESTINATION lib                 COMPONENT Runtime
        ARCHIVE DESTINATION lib/testbed2   COMPONENT Development)
# install includes
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} DESTINATION include/testbed2/generated FILES_MATCHING PATTERN "*.h")

export(EXPORT Testbed2MonitorTargets
  NAMESPACE testbed2::
)

install(EXPORT Testbed2MonitorTargets
  FILE Testbed2MonitorTargets.cmake
  DESTINATION ${InstallDir}
  NAMESPACE testbed2::
)
