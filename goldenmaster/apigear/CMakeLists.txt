cmake_minimum_required(VERSION 3.20)
project(apigear)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(apigear_COMPONENTS "")

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_BINARY_DIR})
set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_BINARY_DIR}/package)
set(INCLUDE_INSTALL_DIR include/apigear/ CACHE FILEPATH "")
set(LIB_INSTALL_DIR ${CMAKE_CURRENT_BINARY_DIR}/lib/ CACHE FILEPATH "")
set(InstallDir ${LIB_INSTALL_DIR}/cmake/apigear)

option(BUILD_TESTING "Enable this option to build the test targets" OFF)
option(APIGEAR_BUILD_WITH_OLINK "Enables the build of the OLINK backend" OFF)
option(APIGEAR_BUILD_WITH_MONITOR "Enables the build of the monitoring support library" OFF)
option(APIGEAR_BUILD_WITH_MQTT "Enables the build of the MQTT backend" OFF)

# enable testing
if(BUILD_TESTING)
include(CTest)
enable_testing()
endif(BUILD_TESTING)

add_subdirectory(utilities)
list(APPEND apigear_COMPONENTS "utilities")

if(APIGEAR_BUILD_WITH_MONITOR)
add_subdirectory(tracer)
list(APPEND apigear_COMPONENTS "tracer")
endif()

if(APIGEAR_BUILD_WITH_OLINK)
add_subdirectory(olink)
list(APPEND apigear_COMPONENTS "olink")
endif()

if(APIGEAR_BUILD_WITH_MQTT)
add_subdirectory(mqtt)
list(APPEND apigear_COMPONENTS "mqtt")
endif()

include(CMakePackageConfigHelpers)
configure_package_config_file(ApigearConfig.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/apigearConfig.cmake
  INSTALL_DESTINATION ${InstallDir}
  PATH_VARS INCLUDE_INSTALL_DIR LIB_INSTALL_DIR APIGEAR_BUILD_WITH_MONITOR APIGEAR_BUILD_WITH_OLINK APIGEAR_BUILD_WITH_MQTT)
write_basic_package_version_file(
  ${CMAKE_CURRENT_BINARY_DIR}/apigearConfigVersion.cmake
  VERSION 0.1.0
  COMPATIBILITY SameMinorVersion )
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/apigearConfig.cmake
              ${CMAKE_CURRENT_BINARY_DIR}/apigearConfigVersion.cmake
        DESTINATION ${InstallDir} )
