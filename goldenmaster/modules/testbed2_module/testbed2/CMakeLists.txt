cmake_minimum_required(VERSION 3.20)
project(testbed2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(INCLUDE_INSTALL_DIR include/testbed2/ CACHE FILEPATH "")
set(LIB_INSTALL_DIR lib/ CACHE FILEPATH "")
set(InstallDir ${LIB_INSTALL_DIR}/cmake/testbed2)

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
configure_package_config_file(Testbed2Config.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/testbed2Config.cmake
  INSTALL_DESTINATION ${InstallDir}
  PATH_VARS INCLUDE_INSTALL_DIR LIB_INSTALL_DIR)
write_basic_package_version_file(
  ${CMAKE_CURRENT_BINARY_DIR}/testbed2ConfigVersion.cmake
  VERSION 1.0.0
  COMPATIBILITY SameMinorVersion )
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/testbed2Config.cmake
              ${CMAKE_CURRENT_BINARY_DIR}/testbed2ConfigVersion.cmake
        DESTINATION ${InstallDir} )
