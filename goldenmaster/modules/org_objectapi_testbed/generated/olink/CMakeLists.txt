set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(apigear QUIET COMPONENTS poco-olink)
set (SOURCES_OLINK
    org_objectapi_testbed_interface1adapter.cpp
    org_objectapi_testbed_interface1interface.cpp
    org_objectapi_testbed_interface2adapter.cpp
    org_objectapi_testbed_interface2interface.cpp
)
add_library(org_objectapi_testbed-olink SHARED ${SOURCES_OLINK})
add_library(org_objectapi_testbed::org_objectapi_testbed-olink ALIAS org_objectapi_testbed-olink)
target_include_directories(org_objectapi_testbed-olink
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include/org_objectapi_testbed>
)
target_link_libraries(org_objectapi_testbed-olink 
    org_objectapi_testbed::org_objectapi_testbed-core
    apigear::poco-olink
)

# ensure maximum compiler support
if(NOT MSVC)
  target_compile_options(org_objectapi_testbed-olink PRIVATE -Wall -Wextra -Wpedantic -Werror -fvisibility=hidden)
else()
  target_compile_options(org_objectapi_testbed-olink PRIVATE /W4 /WX /wd4251)
endif()

install(TARGETS org_objectapi_testbed-olink
        EXPORT Org_objectapi_testbedOLinkTargets
        RUNTIME DESTINATION bin                 COMPONENT Runtime
        LIBRARY DESTINATION lib                 COMPONENT Runtime
        ARCHIVE DESTINATION lib/org_objectapi_testbed   COMPONENT Development)
# install includes
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} DESTINATION include/org_objectapi_testbed/generated FILES_MATCHING PATTERN "*.h")

export(EXPORT Org_objectapi_testbedOLinkTargets
  NAMESPACE org_objectapi_testbed::
)

install(EXPORT Org_objectapi_testbedOLinkTargets
  FILE Org_objectapi_testbedOLinkTargets.cmake
  DESTINATION ${InstallDir}
  NAMESPACE org_objectapi_testbed::
)
