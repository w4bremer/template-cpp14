{{- $features := .Features -}}
#!/bin/bash
set -x;
export DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )";
cd $DIR;
rm -rf build/ && mkdir -p build && cd build;
{{- if $features.apigear }}
conan remove "apigear" -b -f
mkdir -p apigear;
pushd apigear;
conan source ../../apigear && conan install --build missing ../../apigear -g=virtualenv && conan build ../../apigear && cmake ../../apigear && cmake --build . && source activate.sh && cmake --build . --target check && \
conan install --build missing ../../apigear && conan create ../../apigear
if [ $? -ne 0 ]; then exit 1; fi;
popd
{{- end}}
{{- range .System.Modules }}
conan remove "{{ snake .Name }}" -b -f
mkdir -p modules/{{ snake .Name }}_module;
pushd modules/{{ snake .Name }}_module;
conan source ../../../modules/{{ snake .Name }}_module &&\
conan install --build missing ../../../modules/{{ snake .Name }}_module -g=virtualenv &&\
conan build ../../../modules/{{ snake .Name }}_module &&\
cmake ../../../modules/{{ snake .Name }}_module/{{ snake .Name }} &&\
cmake --build . &&\
source activate.sh &&\
cmake --build . --target check &&\
source deactivate.sh &&\
conan install --build missing ../../../modules/{{ snake .Name }}_module &&\
conan create ../../../modules/{{ snake .Name }}_module
if [ $? -ne 0 ]; then exit 1; fi;
popd
{{- end }}
{{- if $features.examples }}
# examples app
mkdir -p examples/app;
pushd examples/app;
conan install --build missing ../../../examples/app -g=virtualenv && cmake ../../../examples/app && cmake --build .
if [ $? -ne 0 ]; then exit 1; fi;
popd
# examples appthreadsafe
mkdir -p examples/appthreadsafe;
pushd examples/appthreadsafe;
conan install --build missing ../../../examples/appthreadsafe -g=virtualenv && cmake ../../../examples/appthreadsafe && cmake --build .
if [ $? -ne 0 ]; then exit 1; fi;
popd
{{- end}}
{{- if $features.examples_olink }}
mkdir -p examples/olinkserver;
pushd examples/olinkserver;
conan install --build missing ../../../examples/olinkserver -g=virtualenv && cmake ../../../examples/olinkserver && cmake --build .
if [ $? -ne 0 ]; then exit 1; fi;
popd
mkdir -p examples/olinkclient;
pushd examples/olinkclient;
conan install --build missing ../../../examples/olinkclient -g=virtualenv && cmake ../../../examples/olinkclient && cmake --build .
if [ $? -ne 0 ]; then exit 1; fi;
popd
{{- end}}
