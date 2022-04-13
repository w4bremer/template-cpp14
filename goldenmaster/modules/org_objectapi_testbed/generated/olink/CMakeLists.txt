set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(apigear OPTIONAL_COMPONENTS poco-olink)
set (SOURCES_OLINK
    org_objectapi_testbed_interface1adapter.cpp
    org_objectapi_testbed_interface1interface.cpp
    org_objectapi_testbed_interface2adapter.cpp
    org_objectapi_testbed_interface2interface.cpp
)
add_library(org_objectapi_testbed-olink SHARED ${SOURCES_OLINK})
add_library(org_objectapi_testbed::olink ALIAS org_objectapi_testbed-olink)
target_include_directories(org_objectapi_testbed-olink PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${INCLUDES_OLINK})
target_link_libraries(org_objectapi_testbed-olink 
    org_objectapi_testbed::core
    apigear::poco-olink
    olink_core
)
# ensure maximum compiler support
if(NOT MSVC)
  target_compile_options(org_objectapi_testbed-olink PRIVATE -Wall -Wextra -Wpedantic -Werror -fvisibility=hidden)
else()
  target_compile_options(org_objectapi_testbed-olink PRIVATE /W4 /WX /wd4251)
endif()

install(TARGETS org_objectapi_testbed-olink
        RUNTIME DESTINATION bin                 COMPONENT Runtime
        LIBRARY DESTINATION lib                 COMPONENT Runtime
        ARCHIVE DESTINATION lib/org_objectapi_testbed   COMPONENT Development)
# install includes
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} DESTINATION include/org_objectapi_testbed/generated FILES_MATCHING PATTERN "*.h")
