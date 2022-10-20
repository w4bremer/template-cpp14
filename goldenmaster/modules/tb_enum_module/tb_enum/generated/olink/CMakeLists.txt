set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(apigear QUIET COMPONENTS poco-olink)
set (SOURCES_OLINK
    enuminterfaceservice.cpp
    remoteenuminterface.cpp
)
add_library(tb_enum-olink SHARED ${SOURCES_OLINK})
add_library(tb_enum::tb_enum-olink ALIAS tb_enum-olink)
target_include_directories(tb_enum-olink
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../../>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../../../modules>
    $<INSTALL_INTERFACE:include/tb_enum>
)
target_link_libraries(tb_enum-olink 
    tb_enum::tb_enum-core
    apigear::poco-olink
)

# ensure maximum compiler support
if(NOT MSVC)
  target_compile_options(tb_enum-olink PRIVATE -Wall -Wextra -Wpedantic -Werror -fvisibility=hidden)
else()
  target_compile_options(tb_enum-olink PRIVATE /W4 /WX /wd4251)
endif()

install(TARGETS tb_enum-olink
        EXPORT Tb_enumOLinkTargets
        RUNTIME DESTINATION bin                 COMPONENT Runtime
        LIBRARY DESTINATION lib                 COMPONENT Runtime
        ARCHIVE DESTINATION lib/tb_enum   COMPONENT Development)
# install includes
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} DESTINATION include/tb_enum/generated FILES_MATCHING PATTERN "*.h")

export(EXPORT Tb_enumOLinkTargets
  NAMESPACE tb_enum::
)

install(EXPORT Tb_enumOLinkTargets
  FILE Tb_enumOLinkTargets.cmake
  DESTINATION ${InstallDir}
  NAMESPACE tb_enum::
)
