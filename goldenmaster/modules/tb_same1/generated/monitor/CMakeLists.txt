set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(apigear QUIET COMPONENTS poco-tracer)
set (SOURCES_MONITOR
    tb_same1.trace.cpp
    tb_same1_samestruct1interface.trace.cpp
    tb_same1_samestruct2interface.trace.cpp
    tb_same1_sameenum1interface.trace.cpp
    tb_same1_sameenum2interface.trace.cpp
)
add_library(tb_same1-monitor SHARED ${SOURCES_MONITOR})
add_library(tb_same1::tb_same1-monitor ALIAS tb_same1-monitor)
target_include_directories(tb_same1-monitor
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include/tb_same1>
)
target_link_libraries(tb_same1-monitor PUBLIC
    tb_same1::tb_same1-core
    apigear::poco-tracer
)
# ensure maximum compiler support
if(NOT MSVC)
  target_compile_options(tb_same1-monitor PRIVATE -Wall -Wextra -Wpedantic -Werror -fvisibility=hidden)
else()
  target_compile_options(tb_same1-monitor PRIVATE /W4 /WX /wd4251)
endif()

install(TARGETS tb_same1-monitor
        EXPORT Tb_same1MonitorTargets
        RUNTIME DESTINATION bin                 COMPONENT Runtime
        LIBRARY DESTINATION lib                 COMPONENT Runtime
        ARCHIVE DESTINATION lib/tb_same1   COMPONENT Development)
# install includes
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} DESTINATION include/tb_same1/generated FILES_MATCHING PATTERN "*.h")

export(EXPORT Tb_same1MonitorTargets
  NAMESPACE tb_same1::
)

install(EXPORT Tb_same1MonitorTargets
  FILE Tb_same1MonitorTargets.cmake
  DESTINATION ${InstallDir}
  NAMESPACE tb_same1::
)
