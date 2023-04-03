set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(apigear QUIET COMPONENTS poco-tracer)
set (SOURCES_MONITOR
    voidinterface.tracedecorator.cpp
    voidinterface.tracer.cpp
    simpleinterface.tracedecorator.cpp
    simpleinterface.tracer.cpp
    simplearrayinterface.tracedecorator.cpp
    simplearrayinterface.tracer.cpp
    nopropertiesinterface.tracedecorator.cpp
    nopropertiesinterface.tracer.cpp
    nooperationsinterface.tracedecorator.cpp
    nooperationsinterface.tracer.cpp
    nosignalsinterface.tracedecorator.cpp
    nosignalsinterface.tracer.cpp
)
add_library(tb_simple-monitor SHARED ${SOURCES_MONITOR})
add_library(tb_simple::tb_simple-monitor ALIAS tb_simple-monitor)
target_include_directories(tb_simple-monitor
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../../>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../../../modules>
    $<INSTALL_INTERFACE:include/tb_simple>
)
target_link_libraries(tb_simple-monitor PUBLIC
    tb_simple::tb_simple-core
    apigear::poco-tracer
)
# ensure maximum compiler support
if(NOT MSVC)
  target_compile_options(tb_simple-monitor PRIVATE -Wall -Wextra -Wpedantic -Werror -fvisibility=hidden)
else()
  target_compile_options(tb_simple-monitor PRIVATE /W4 /WX /wd4251)
endif()

install(TARGETS tb_simple-monitor
        EXPORT Tb_simpleMonitorTargets
        RUNTIME DESTINATION bin                 COMPONENT Runtime
        LIBRARY DESTINATION lib                 COMPONENT Runtime
        ARCHIVE DESTINATION lib/tb_simple   COMPONENT Development)
# install includes
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} DESTINATION include/tb_simple/generated FILES_MATCHING PATTERN "*.h")

export(EXPORT Tb_simpleMonitorTargets
  NAMESPACE tb_simple::
)

install(EXPORT Tb_simpleMonitorTargets
  FILE Tb_simpleMonitorTargets.cmake
  DESTINATION ${InstallDir}
  NAMESPACE tb_simple::
)
