cmake_minimum_required(VERSION 3.1)
project(org_objectapi_testbed)

include(CTest)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# checks are workaround until generator support feature check properly
IF( IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/generated/api" )
add_subdirectory(generated/api)
ENDIF()
IF( IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/generated/core" )
add_subdirectory(generated/core)
ENDIF()
# implementation target
add_subdirectory(implementation)
IF( IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/generated/monitor" )
add_subdirectory(generated/monitor)
ENDIF()
IF( IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/generated/olink" )
add_subdirectory(generated/olink)
ENDIF()

set(INCLUDE_INSTALL_DIR include/org_objectapi_testbed/ CACHE FILEPATH "")
set(LIB_INSTALL_DIR lib/ CACHE FILEPATH "")

include(CMakePackageConfigHelpers)
configure_package_config_file(Org_objectapi_testbedConfig.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/Org_objectapi_testbedConfig.cmake
  INSTALL_DESTINATION ${LIB_INSTALL_DIR}/org_objectapi_testbed/cmake
  PATH_VARS INCLUDE_INSTALL_DIR SYSCONFIG_INSTALL_DIR)
write_basic_package_version_file(
  ${CMAKE_CURRENT_BINARY_DIR}/Org_objectapi_testbedConfigVersion.cmake
  VERSION 1.0
  COMPATIBILITY SameMinorVersion )
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/Org_objectapi_testbedConfig.cmake
              ${CMAKE_CURRENT_BINARY_DIR}/Org_objectapi_testbedConfigVersion.cmake
        DESTINATION ${LIB_INSTALL_DIR}/org_objectapi_testbed/cmake )
