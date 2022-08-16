set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(apigear QUIET COMPONENTS poco-tracer)
set (SOURCES_MONITOR
    enuminterface.tracedecorator.cpp
    enuminterface.tracer.cpp
)
add_library(tb_enum-monitor SHARED ${SOURCES_MONITOR})
add_library(tb_enum::tb_enum-monitor ALIAS tb_enum-monitor)
target_include_directories(tb_enum-monitor
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../../>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../../../modules>
    $<INSTALL_INTERFACE:include/tb_enum>
)
target_link_libraries(tb_enum-monitor PUBLIC
    tb_enum::tb_enum-core
    apigear::poco-tracer
)
# ensure maximum compiler support
if(NOT MSVC)
  target_compile_options(tb_enum-monitor PRIVATE -Wall -Wextra -Wpedantic -Werror -fvisibility=hidden)
else()
  target_compile_options(tb_enum-monitor PRIVATE /W4 /WX /wd4251)
endif()

install(TARGETS tb_enum-monitor
        EXPORT Tb_enumMonitorTargets
        RUNTIME DESTINATION bin                 COMPONENT Runtime
        LIBRARY DESTINATION lib                 COMPONENT Runtime
        ARCHIVE DESTINATION lib/tb_enum   COMPONENT Development)
# install includes
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} DESTINATION include/tb_enum/generated FILES_MATCHING PATTERN "*.h")

export(EXPORT Tb_enumMonitorTargets
  NAMESPACE tb_enum::
)

install(EXPORT Tb_enumMonitorTargets
  FILE Tb_enumMonitorTargets.cmake
  DESTINATION ${InstallDir}
  NAMESPACE tb_enum::
)
