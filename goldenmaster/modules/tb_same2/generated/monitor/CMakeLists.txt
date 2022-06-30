set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(apigear QUIET COMPONENTS poco-tracer)
set (SOURCES_MONITOR
    tb_same2.trace.cpp
    tb_same2_samestruct1interface.trace.cpp
    tb_same2_samestruct2interface.trace.cpp
    tb_same2_sameenum1interface.trace.cpp
    tb_same2_sameenum2interface.trace.cpp
)
add_library(tb_same2-monitor SHARED ${SOURCES_MONITOR})
add_library(tb_same2::tb_same2-monitor ALIAS tb_same2-monitor)
target_include_directories(tb_same2-monitor
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include/tb_same2>
)
target_link_libraries(tb_same2-monitor PUBLIC
    tb_same2::tb_same2-core
    apigear::poco-tracer
)
# ensure maximum compiler support
if(NOT MSVC)
  target_compile_options(tb_same2-monitor PRIVATE -Wall -Wextra -Wpedantic -Werror -fvisibility=hidden)
else()
  target_compile_options(tb_same2-monitor PRIVATE /W4 /WX /wd4251)
endif()

install(TARGETS tb_same2-monitor
        EXPORT Tb_same2MonitorTargets
        RUNTIME DESTINATION bin                 COMPONENT Runtime
        LIBRARY DESTINATION lib                 COMPONENT Runtime
        ARCHIVE DESTINATION lib/tb_same2   COMPONENT Development)
# install includes
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} DESTINATION include/tb_same2/generated FILES_MATCHING PATTERN "*.h")

export(EXPORT Tb_same2MonitorTargets
  NAMESPACE tb_same2::
)

install(EXPORT Tb_same2MonitorTargets
  FILE Tb_same2MonitorTargets.cmake
  DESTINATION ${InstallDir}
  NAMESPACE tb_same2::
)
