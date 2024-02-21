cmake_minimum_required(VERSION 3.20)
project(tb_simple)
# this options is only here for the conan build until there is a conan based solution for objectlink-core
option(TB_SIMPLE_FETCH_OLINKCORE "Fetch and build objectlink-core, if not pre-installed" OFF)

if(TB_SIMPLE_FETCH_OLINKCORE)
find_package(olink_core QUIET)
if(NOT olink_core_FOUND)
  # pull olink_core as dependency
  message(STATUS "olink_core NOT FOUND, fetching the git repository")
  include(FetchContent)
  FetchContent_Declare(olink_core
      GIT_REPOSITORY https://github.com/w4bremer/objectlink-core-cpp.git
      GIT_TAG bugfix/ExportCMakeTargets
      GIT_SHALLOW TRUE
      EXCLUDE_FROM_ALL FALSE
      OVERRIDE_FIND_PACKAGE
  )
  FetchContent_MakeAvailable(olink_core)
endif()
endif() # TB_SIMPLE_FETCH_OLINKCORE

# needed to access CMAKE_INSTALL_LIBDIR
include(GNUInstallDirs)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_BINARY_DIR})
set(InstallDir ${CMAKE_INSTALL_LIBDIR}/cmake/tb_simple)

# enable testing
if(BUILD_TESTING)
include(CTest)
enable_testing()
endif(BUILD_TESTING)

# define variable for library include paths
get_filename_component(MODULES_DIR "${CMAKE_CURRENT_SOURCE_DIR}/.." ABSOLUTE)

add_subdirectory(generated/api)
add_subdirectory(generated/core)
add_subdirectory(implementation)
add_subdirectory(generated/monitor)
add_subdirectory(generated/olink)
add_subdirectory(generated/mqtt)

include(CMakePackageConfigHelpers)
configure_package_config_file(Tb_simpleConfig.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/tb_simpleConfig.cmake
  INSTALL_DESTINATION ${InstallDir})
write_basic_package_version_file(
  ${CMAKE_CURRENT_BINARY_DIR}/tb_simpleConfigVersion.cmake
  VERSION 1.0.0
  COMPATIBILITY SameMinorVersion )
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/tb_simpleConfig.cmake
              ${CMAKE_CURRENT_BINARY_DIR}/tb_simpleConfigVersion.cmake
        DESTINATION ${InstallDir} )
