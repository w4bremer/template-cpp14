cmake_minimum_required(VERSION 3.14)
project(apigear)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(apigear_COMPONENTS "")

add_subdirectory(tracer)
list(APPEND apigear_COMPONENTS "tracer")

add_subdirectory(olink)
list(APPEND apigear_COMPONENTS "olink")

set(INCLUDE_INSTALL_DIR include/apigear/ CACHE FILEPATH "")
set(LIB_INSTALL_DIR lib/ CACHE FILEPATH "")

include(CMakePackageConfigHelpers)
configure_package_config_file(ApigearConfig.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/ApigearConfig.cmake
  INSTALL_DESTINATION ${LIB_INSTALL_DIR}/apigear/cmake
  PATH_VARS INCLUDE_INSTALL_DIR SYSCONFIG_INSTALL_DIR)
write_basic_package_version_file(
  ${CMAKE_CURRENT_BINARY_DIR}/ApigearConfigVersion.cmake
  VERSION 0.1.0
  COMPATIBILITY SameMinorVersion )
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/ApigearConfig.cmake
              ${CMAKE_CURRENT_BINARY_DIR}/ApigearConfigVersion.cmake
        DESTINATION ${LIB_INSTALL_DIR}/apigear/cmake )
