set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(apigear QUIET COMPONENTS poco-tracer)
set (SOURCES_MONITOR
    names.tracedecorator.cpp
    names.tracer.cpp
)
add_library(tb_names-monitor SHARED ${SOURCES_MONITOR})
add_library(tb_names::tb_names-monitor ALIAS tb_names-monitor)
target_include_directories(tb_names-monitor
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../../>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../../../modules>
    $<INSTALL_INTERFACE:include/tb_names>
)
target_link_libraries(tb_names-monitor PUBLIC
    tb_names::tb_names-core
    apigear::poco-tracer
)
# ensure maximum compiler support
if(NOT MSVC)
  target_compile_options(tb_names-monitor PRIVATE -Wall -Wextra -Wpedantic -Werror -fvisibility=hidden)
else()
  target_compile_options(tb_names-monitor PRIVATE /W4 /WX /wd4251)
endif()

install(TARGETS tb_names-monitor
        EXPORT Tb_namesMonitorTargets)
# install includes
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} DESTINATION include/tb_names/generated FILES_MATCHING PATTERN "*.h")

export(EXPORT Tb_namesMonitorTargets
  NAMESPACE tb_names::
)

install(EXPORT Tb_namesMonitorTargets
  FILE Tb_namesMonitorTargets.cmake
  DESTINATION ${InstallDir}
  NAMESPACE tb_names::
)
