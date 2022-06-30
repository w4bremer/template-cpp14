cmake_minimum_required(VERSION 3.1)
project(testbed1)

include(CTest)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(INCLUDE_INSTALL_DIR include/testbed1/ CACHE FILEPATH "")
set(LIB_INSTALL_DIR lib/ CACHE FILEPATH "")
set(InstallDir ${LIB_INSTALL_DIR}/cmake/testbed1)

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

include(CMakePackageConfigHelpers)
configure_package_config_file(Testbed1Config.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/testbed1Config.cmake
  INSTALL_DESTINATION ${InstallDir}
  PATH_VARS INCLUDE_INSTALL_DIR LIB_INSTALL_DIR)
write_basic_package_version_file(
  ${CMAKE_CURRENT_BINARY_DIR}/testbed1ConfigVersion.cmake
  VERSION 1.0
  COMPATIBILITY SameMinorVersion )
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/testbed1Config.cmake
              ${CMAKE_CURRENT_BINARY_DIR}/testbed1ConfigVersion.cmake
        DESTINATION ${InstallDir} )
