cmake_minimum_required(VERSION 3.20)
project(testbed1)

# needed to access CMAKE_INSTALL_LIBDIR
include(GNUInstallDirs)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(InstallDir ${CMAKE_INSTALL_LIBDIR}/cmake/testbed1)

# enable testing
if(BUILD_TESTING)
include(CTest)
enable_testing()
endif(BUILD_TESTING)

add_subdirectory(generated/api)
add_subdirectory(generated/core)
add_subdirectory(implementation)
add_subdirectory(generated/monitor)
add_subdirectory(generated/olink)
add_subdirectory(generated/mqtt)

include(CMakePackageConfigHelpers)
configure_package_config_file(Testbed1Config.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/testbed1Config.cmake
  INSTALL_DESTINATION ${InstallDir})
write_basic_package_version_file(
  ${CMAKE_CURRENT_BINARY_DIR}/testbed1ConfigVersion.cmake
  VERSION 1.0.0
  COMPATIBILITY SameMinorVersion )
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/testbed1Config.cmake
              ${CMAKE_CURRENT_BINARY_DIR}/testbed1ConfigVersion.cmake
        DESTINATION ${InstallDir} )
