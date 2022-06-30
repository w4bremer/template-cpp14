set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(apigear QUIET COMPONENTS poco-olink)
set (SOURCES_OLINK
    tb_simple_simpleinterfaceadapter.cpp
    tb_simple_simpleinterfaceinterface.cpp
    tb_simple_simplearrayinterfaceadapter.cpp
    tb_simple_simplearrayinterfaceinterface.cpp
)
add_library(tb_simple-olink SHARED ${SOURCES_OLINK})
add_library(tb_simple::tb_simple-olink ALIAS tb_simple-olink)
target_include_directories(tb_simple-olink
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include/tb_simple>
)
target_link_libraries(tb_simple-olink 
    tb_simple::tb_simple-core
    apigear::poco-olink
)

# ensure maximum compiler support
if(NOT MSVC)
  target_compile_options(tb_simple-olink PRIVATE -Wall -Wextra -Wpedantic -Werror -fvisibility=hidden)
else()
  target_compile_options(tb_simple-olink PRIVATE /W4 /WX /wd4251)
endif()

install(TARGETS tb_simple-olink
        EXPORT Tb_simpleOLinkTargets
        RUNTIME DESTINATION bin                 COMPONENT Runtime
        LIBRARY DESTINATION lib                 COMPONENT Runtime
        ARCHIVE DESTINATION lib/tb_simple   COMPONENT Development)
# install includes
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} DESTINATION include/tb_simple/generated FILES_MATCHING PATTERN "*.h")

export(EXPORT Tb_simpleOLinkTargets
  NAMESPACE tb_simple::
)

install(EXPORT Tb_simpleOLinkTargets
  FILE Tb_simpleOLinkTargets.cmake
  DESTINATION ${InstallDir}
  NAMESPACE tb_simple::
)
