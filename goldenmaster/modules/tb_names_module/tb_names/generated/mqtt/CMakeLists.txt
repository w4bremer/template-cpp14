find_package(apigear OPTIONAL_COMPONENTS paho-mqtt)
set (SOURCES_MQTT
    namesservice.cpp
    namesclient.cpp
)
add_library(tb_names-mqtt SHARED ${SOURCES_MQTT})
add_library(tb_names::tb_names-mqtt ALIAS tb_names-mqtt)
target_include_directories(tb_names-mqtt
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../../>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../../../modules>
    $<INSTALL_INTERFACE:include/tb_names>
)
target_link_libraries(tb_names-mqtt
    tb_names::tb_names-core
    apigear::paho-mqtt
)
# ensure maximum compiler support
if(NOT MSVC)
  target_compile_options(tb_names-mqtt PRIVATE -Wall -Wextra -Wpedantic -Werror -fvisibility=hidden)
else()
  target_compile_options(tb_names-mqtt PRIVATE /W4 /WX /wd4251)
endif()

install(TARGETS tb_names-mqtt
        EXPORT Tb_namesMqttTargets
        RUNTIME DESTINATION bin                 COMPONENT Runtime
        LIBRARY DESTINATION lib                 COMPONENT Runtime
        ARCHIVE DESTINATION lib/tb_names   COMPONENT Development)
# install includes
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} DESTINATION include/tb_names/generated FILES_MATCHING PATTERN "*.h")

export(EXPORT Tb_namesMqttTargets
  NAMESPACE tb_names::
)

install(EXPORT Tb_namesMqttTargets
  FILE Tb_namesMqttTargets.cmake
  DESTINATION ${InstallDir}
  NAMESPACE tb_names::
)
