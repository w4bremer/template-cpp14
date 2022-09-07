find_package(apigear OPTIONAL_COMPONENTS paho-mqtt)
set (SOURCES_MQTT
    manyparaminterfaceservice.cpp
    manyparaminterfaceclient.cpp
    nestedstruct1interfaceservice.cpp
    nestedstruct1interfaceclient.cpp
    nestedstruct2interfaceservice.cpp
    nestedstruct2interfaceclient.cpp
    nestedstruct3interfaceservice.cpp
    nestedstruct3interfaceclient.cpp
)
add_library(testbed2-mqtt SHARED ${SOURCES_MQTT})
add_library(testbed2::testbed2-mqtt ALIAS testbed2-mqtt)
target_include_directories(testbed2-mqtt PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/../)
target_link_libraries(testbed2-mqtt
    testbed2::testbed2-core
    apigear::paho-mqtt
)
# ensure maximum compiler support
if(NOT MSVC)
  target_compile_options(testbed2-mqtt PRIVATE -Wall -Wextra -Wpedantic -Werror -fvisibility=hidden)
else()
  target_compile_options(testbed2-mqtt PRIVATE /W4 /WX /wd4251)
endif()
