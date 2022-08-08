set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(apigear QUIET COMPONENTS poco-olink)
set (SOURCES_OLINK
    samestruct1interfaceadapter.cpp
    samestruct1interfaceinterface.cpp
    samestruct2interfaceadapter.cpp
    samestruct2interfaceinterface.cpp
    sameenum1interfaceadapter.cpp
    sameenum1interfaceinterface.cpp
    sameenum2interfaceadapter.cpp
    sameenum2interfaceinterface.cpp
)
add_library(tb_same1-olink SHARED ${SOURCES_OLINK})
add_library(tb_same1::tb_same1-olink ALIAS tb_same1-olink)
target_include_directories(tb_same1-olink
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../../>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../../../modules>
    $<INSTALL_INTERFACE:include/tb_same1>
)
target_link_libraries(tb_same1-olink 
    tb_same1::tb_same1-core
    apigear::poco-olink
)

# ensure maximum compiler support
if(NOT MSVC)
  target_compile_options(tb_same1-olink PRIVATE -Wall -Wextra -Wpedantic -Werror -fvisibility=hidden)
else()
  target_compile_options(tb_same1-olink PRIVATE /W4 /WX /wd4251)
endif()

install(TARGETS tb_same1-olink
        EXPORT Tb_same1OLinkTargets
        RUNTIME DESTINATION bin                 COMPONENT Runtime
        LIBRARY DESTINATION lib                 COMPONENT Runtime
        ARCHIVE DESTINATION lib/tb_same1   COMPONENT Development)
# install includes
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} DESTINATION include/tb_same1/generated FILES_MATCHING PATTERN "*.h")

export(EXPORT Tb_same1OLinkTargets
  NAMESPACE tb_same1::
)

install(EXPORT Tb_same1OLinkTargets
  FILE Tb_same1OLinkTargets.cmake
  DESTINATION ${InstallDir}
  NAMESPACE tb_same1::
)
