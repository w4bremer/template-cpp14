find_package(apigear OPTIONAL_COMPONENTS paho-mqtt)
set (SOURCES_MQTT
    enuminterfaceservice.cpp
    enuminterfaceclient.cpp
)
add_library(tb_enum-mqtt SHARED ${SOURCES_MQTT})
add_library(tb_enum::tb_enum-mqtt ALIAS tb_enum-mqtt)
target_include_directories(tb_enum-mqtt PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/../)
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
