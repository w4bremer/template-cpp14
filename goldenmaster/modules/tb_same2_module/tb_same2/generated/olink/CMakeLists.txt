set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(apigear QUIET COMPONENTS poco-olink)
set (SOURCES_OLINK
    samestruct1interfaceservice.cpp
    remotesamestruct1interface.cpp
    samestruct2interfaceservice.cpp
    remotesamestruct2interface.cpp
    sameenum1interfaceservice.cpp
    remotesameenum1interface.cpp
    sameenum2interfaceservice.cpp
    remotesameenum2interface.cpp
)
add_library(tb_same2-olink SHARED ${SOURCES_OLINK})
add_library(tb_same2::tb_same2-olink ALIAS tb_same2-olink)
target_include_directories(tb_same2-olink
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../../>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../../../modules>
    $<INSTALL_INTERFACE:include/tb_same2>
)
target_link_libraries(tb_same2-olink 
    tb_same2::tb_same2-core
    apigear::poco-olink
)

# ensure maximum compiler support
if(NOT MSVC)
  target_compile_options(tb_same2-olink PRIVATE -Wall -Wextra -Wpedantic -Werror -fvisibility=hidden)
else()
  target_compile_options(tb_same2-olink PRIVATE /W4 /WX /wd4251)
endif()

install(TARGETS tb_same2-olink
        EXPORT Tb_same2OLinkTargets
        RUNTIME DESTINATION bin                 COMPONENT Runtime
        LIBRARY DESTINATION lib                 COMPONENT Runtime
        ARCHIVE DESTINATION lib/tb_same2   COMPONENT Development)
# install includes
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} DESTINATION include/tb_same2/generated FILES_MATCHING PATTERN "*.h")

export(EXPORT Tb_same2OLinkTargets
  NAMESPACE tb_same2::
)

install(EXPORT Tb_same2OLinkTargets
  FILE Tb_same2OLinkTargets.cmake
  DESTINATION ${InstallDir}
  NAMESPACE tb_same2::
)
