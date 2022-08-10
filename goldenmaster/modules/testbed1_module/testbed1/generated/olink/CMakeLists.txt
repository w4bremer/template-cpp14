set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(apigear QUIET COMPONENTS poco-olink)
set (SOURCES_OLINK
    structinterfaceservice.adapter.cpp
    remotestructinterface.cpp
    structarrayinterfaceservice.adapter.cpp
    remotestructarrayinterface.cpp
)
add_library(testbed1-olink SHARED ${SOURCES_OLINK})
add_library(testbed1::testbed1-olink ALIAS testbed1-olink)
target_include_directories(testbed1-olink
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../../>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../../../modules>
    $<INSTALL_INTERFACE:include/testbed1>
)
target_link_libraries(testbed1-olink 
    testbed1::testbed1-core
    apigear::poco-olink
)

# ensure maximum compiler support
if(NOT MSVC)
  target_compile_options(testbed1-olink PRIVATE -Wall -Wextra -Wpedantic -Werror -fvisibility=hidden)
else()
  target_compile_options(testbed1-olink PRIVATE /W4 /WX /wd4251)
endif()

install(TARGETS testbed1-olink
        EXPORT Testbed1OLinkTargets
        RUNTIME DESTINATION bin                 COMPONENT Runtime
        LIBRARY DESTINATION lib                 COMPONENT Runtime
        ARCHIVE DESTINATION lib/testbed1   COMPONENT Development)
# install includes
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} DESTINATION include/testbed1/generated FILES_MATCHING PATTERN "*.h")

export(EXPORT Testbed1OLinkTargets
  NAMESPACE testbed1::
)

install(EXPORT Testbed1OLinkTargets
  FILE Testbed1OLinkTargets.cmake
  DESTINATION ${InstallDir}
  NAMESPACE testbed1::
)
