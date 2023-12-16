{{- $features := .Features -}}
#!/bin/bash
set -x;
export source_root="$( cd "$( dirname "${BASH_SOURCE[0]}" )/../" >/dev/null 2>&1 && pwd )";
echo source root is in $source_root

#
# function implementations
#

# build cmake module
buildCMakeModule()
{
    cmake -B"$2/build_cmake/$1" -DCMAKE_INSTALL_PREFIX="$2/tmp" -DBUILD_TESTING=ON $3 -S"$2/$1" && cmake --build "$2/build_cmake/$1" && cmake --build "$2/build_cmake/$1" --target test && cmake --build "$2/build_cmake/$1" --target install
    buildresult=$?
}

# build cmake binary
buildCMakeBinary()
{
    cmake -B"$2/build_cmake/$1" -DCMAKE_INSTALL_PREFIX="$2/tmp" $3 -S"$2/$1" && cmake --build "$2/build_cmake/$1" && cmake --build "$2/build_cmake/$1" --target install
    buildresult=$?
}

cd $source_root;
rm -rf build_cmake/ && mkdir -p build_cmake;
if [ $? -ne 0 ]; then exit 1; fi;
{{- if $features.apigear }}
buildCMakeModule "apigear" $source_root "{{ if $features.olink }}-DAPIGEAR_BUILD_WITH_OLINK=ON {{ end }}{{ if $features.monitor }}-DAPIGEAR_BUILD_WITH_MONITOR=ON {{ end }}{{ if $features.mqtt }}-DAPIGEAR_BUILD_WITH_MQTT=ON{{ end }}"
if [ $buildresult -ne 0 ]; then exit 1; fi;
{{- end}}
{{- range .System.Modules }}
buildCMakeModule "modules/{{ snake .Name }}_module/{{ snake .Name }}" $source_root
if [ $buildresult -ne 0 ]; then exit 1; fi;
{{- end }}
{{- if $features.examples }}
# examples app
buildCMakeBinary "examples/app" $source_root
if [ $buildresult -ne 0 ]; then exit 1; fi;
# examples appthreadsafe
buildCMakeBinary "examples/appthreadsafe" $source_root
if [ $buildresult -ne 0 ]; then exit 1; fi;
{{- end}}
{{- if $features.examples_olink }}
buildCMakeBinary "examples/olinkserver" $source_root
if [ $buildresult -ne 0 ]; then exit 1; fi;
buildCMakeBinary "examples/olinkclient" $source_root
if [ $buildresult -ne 0 ]; then exit 1; fi;
{{- end}}
{{- if $features.examples_mqtt }}
buildCMakeBinary "examples/mqttserver" $source_root
if [ $buildresult -ne 0 ]; then exit 1; fi;
buildCMakeBinary "examples/mqttclient" $source_root
if [ $buildresult -ne 0 ]; then exit 1; fi;
{{- end}}
