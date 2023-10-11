find_package(apigear OPTIONAL_COMPONENTS paho-mqtt)
set (SOURCES_MQTT
    namesservice.cpp
    namesclient.cpp
)
add_library(tb_names-mqtt SHARED ${SOURCES_MQTT})
add_library(tb_names::tb_names-mqtt ALIAS tb_names-mqtt)
target_include_directories(tb_names-mqtt PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/../)
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
