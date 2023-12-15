cmake_minimum_required(VERSION 3.20)
project(tb_names)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(INCLUDE_INSTALL_DIR include/tb_names/ CACHE FILEPATH "")
set(LIB_INSTALL_DIR lib/ CACHE FILEPATH "")
set(InstallDir ${LIB_INSTALL_DIR}/cmake/tb_names)

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
configure_package_config_file(Tb_namesConfig.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/tb_namesConfig.cmake
  INSTALL_DESTINATION ${InstallDir}
  PATH_VARS INCLUDE_INSTALL_DIR LIB_INSTALL_DIR)
write_basic_package_version_file(
  ${CMAKE_CURRENT_BINARY_DIR}/tb_namesConfigVersion.cmake
  VERSION 1.0.0
  COMPATIBILITY SameMinorVersion )
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/tb_namesConfig.cmake
              ${CMAKE_CURRENT_BINARY_DIR}/tb_namesConfigVersion.cmake
        DESTINATION ${InstallDir} )
