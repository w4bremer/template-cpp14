find_package(apigear OPTIONAL_COMPONENTS paho-mqtt)
set (SOURCES_MQTT
    enuminterfaceservice.cpp
    enuminterfaceclient.cpp
)
add_library(tb_enum-mqtt SHARED ${SOURCES_MQTT})
add_library(tb_enum::tb_enum-mqtt ALIAS tb_enum-mqtt)
target_include_directories(tb_enum-mqtt
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../../>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../../../modules>
    $<INSTALL_INTERFACE:include/tb_enum>
)
target_link_libraries(tb_enum-mqtt
    tb_enum::tb_enum-core
    apigear::paho-mqtt
)
# ensure maximum compiler support
if(NOT MSVC)
  target_compile_options(tb_enum-mqtt PRIVATE -Wall -Wextra -Wpedantic -Werror -fvisibility=hidden)
else()
  target_compile_options(tb_enum-mqtt PRIVATE /W4 /WX /wd4251)
endif()

install(TARGETS tb_enum-mqtt
        EXPORT Tb_enumMqttTargets)
# install includes
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} DESTINATION include/tb_enum/generated FILES_MATCHING PATTERN "*.h")

export(EXPORT Tb_enumMqttTargets
  NAMESPACE tb_enum::
)

install(EXPORT Tb_enumMqttTargets
  FILE Tb_enumMqttTargets.cmake
  DESTINATION ${InstallDir}
  NAMESPACE tb_enum::
)
