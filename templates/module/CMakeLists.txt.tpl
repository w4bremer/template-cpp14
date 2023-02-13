{{- $module_id := snake .Module.Name -}}
{{- $module_idFirstUpper := upper1 $module_id -}}
{{- $features := .Features -}}
cmake_minimum_required(VERSION 3.1)
project({{$module_id}})

include(CTest)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(INCLUDE_INSTALL_DIR include/{{$module_id}}/ CACHE FILEPATH "")
set(LIB_INSTALL_DIR lib/ CACHE FILEPATH "")
set(InstallDir ${LIB_INSTALL_DIR}/cmake/{{$module_id}})

add_subdirectory(generated/api)
{{- if $features.core }}
add_subdirectory(generated/core)
{{- end}}
{{- if $features.stubs }}
add_subdirectory(implementation)
{{- end}}
{{- if $features.monitor }}
add_subdirectory(generated/monitor)
{{- end}}
{{- if $features.olink }}
add_subdirectory(generated/olink)
{{- end}}

include(CMakePackageConfigHelpers)
configure_package_config_file({{$module_idFirstUpper}}Config.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/{{$module_id}}Config.cmake
  INSTALL_DESTINATION ${InstallDir}
  PATH_VARS INCLUDE_INSTALL_DIR LIB_INSTALL_DIR)
write_basic_package_version_file(
  ${CMAKE_CURRENT_BINARY_DIR}/{{snake .Module.Name}}ConfigVersion.cmake
  VERSION {{.Module.Version}}
  COMPATIBILITY SameMinorVersion )
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/{{snake .Module.Name}}Config.cmake
              ${CMAKE_CURRENT_BINARY_DIR}/{{snake .Module.Name}}ConfigVersion.cmake
        DESTINATION ${InstallDir} )
