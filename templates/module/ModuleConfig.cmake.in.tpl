{{- $module_id := snake .Module.Name -}}
{{- $module_idCamel := Camel .Module.Name -}}
{{- $module_id_up := SNAKE .Module.Name -}}
{{- $module_idFirstUpper := upper1 $module_id -}}
set({{$module_id_up}}_VERSION {{$.Module.Version}})
@PACKAGE_INIT@
INCLUDE("${CMAKE_CURRENT_LIST_DIR}/{{$module_idFirstUpper}}ApiTargets.cmake")
INCLUDE("${CMAKE_CURRENT_LIST_DIR}/{{$module_idFirstUpper}}CoreTargets.cmake")
INCLUDE("${CMAKE_CURRENT_LIST_DIR}/{{$module_idFirstUpper}}MonitorTargets.cmake")
INCLUDE("${CMAKE_CURRENT_LIST_DIR}/{{$module_idFirstUpper}}OLinkTargets.cmake")
INCLUDE("${CMAKE_CURRENT_LIST_DIR}/{{$module_idFirstUpper}}ImplementationTargets.cmake")
set_and_check({{$module_id_up}}_INCLUDE_DIR "@PACKAGE_INCLUDE_INSTALL_DIR@")

# make sure we have all needed dependencies
include(CMakeFindDependencyMacro)
find_dependency(Threads REQUIRED)
find_dependency(apigear COMPONENTS poco-tracer poco-olink REQUIRED)

check_required_components({{$module_idCamel}}-api {{$module_idCamel}}-core {{$module_idCamel}}-monitor {{$module_idCamel}}-olink {{$module_idCamel}}-implementation)
