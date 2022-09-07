find_package(apigear OPTIONAL_COMPONENTS paho-mqtt)
set (SOURCES_MQTT
    voidinterfaceservice.cpp
    voidinterfaceclient.cpp
    simpleinterfaceservice.cpp
    simpleinterfaceclient.cpp
    simplearrayinterfaceservice.cpp
    simplearrayinterfaceclient.cpp
    nopropertiesinterfaceservice.cpp
    nopropertiesinterfaceclient.cpp
    nooperationsinterfaceservice.cpp
    nooperationsinterfaceclient.cpp
    nosignalsinterfaceservice.cpp
    nosignalsinterfaceclient.cpp
)
add_library(tb_simple-mqtt SHARED ${SOURCES_MQTT})
add_library(tb_simple::tb_simple-mqtt ALIAS tb_simple-mqtt)
target_include_directories(tb_simple-mqtt PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/../)
target_link_libraries(tb_simple-mqtt
    tb_simple::tb_simple-core
    apigear::paho-mqtt
)
# ensure maximum compiler support
if(NOT MSVC)
  target_compile_options(tb_simple-mqtt PRIVATE -Wall -Wextra -Wpedantic -Werror -fvisibility=hidden)
else()
  target_compile_options(tb_simple-mqtt PRIVATE /W4 /WX /wd4251)
endif()
