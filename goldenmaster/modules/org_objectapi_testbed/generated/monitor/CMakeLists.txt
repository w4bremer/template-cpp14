set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(apigear QUIET COMPONENTS poco-tracer)
set (SOURCES_MONITOR
    org_objectapi_testbed.trace.cpp
    org_objectapi_testbed_interface1.trace.cpp
    org_objectapi_testbed_interface2.trace.cpp
)
add_library(org_objectapi_testbed-monitor SHARED ${SOURCES_MONITOR})
add_library(org_objectapi_testbed::org_objectapi_testbed-monitor ALIAS org_objectapi_testbed-monitor)
target_include_directories(org_objectapi_testbed-monitor
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include/org_objectapi_testbed>
)
target_link_libraries(org_objectapi_testbed-monitor PUBLIC
    org_objectapi_testbed::org_objectapi_testbed-core
    apigear::poco-tracer
)
# ensure maximum compiler support
if(NOT MSVC)
  target_compile_options(org_objectapi_testbed-monitor PRIVATE -Wall -Wextra -Wpedantic -Werror -fvisibility=hidden)
else()
  target_compile_options(org_objectapi_testbed-monitor PRIVATE /W4 /WX /wd4251)
endif()

install(TARGETS org_objectapi_testbed-monitor
        EXPORT Org_objectapi_testbedMonitorTargets
        RUNTIME DESTINATION bin                 COMPONENT Runtime
        LIBRARY DESTINATION lib                 COMPONENT Runtime
        ARCHIVE DESTINATION lib/org_objectapi_testbed   COMPONENT Development)
# install includes
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} DESTINATION include/org_objectapi_testbed/generated FILES_MATCHING PATTERN "*.h")

export(EXPORT Org_objectapi_testbedMonitorTargets
  NAMESPACE org_objectapi_testbed::
)

install(EXPORT Org_objectapi_testbedMonitorTargets
  FILE Org_objectapi_testbedMonitorTargets.cmake
  DESTINATION ${InstallDir}
  NAMESPACE org_objectapi_testbed::
)
