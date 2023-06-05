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
conan source ../../apigear && conan install --build missing ../../apigear -g=virtualenv && conan build ../../apigear && cmake -DBUILD_TESTING=ON ../../apigear && cmake --build . && source activate.sh && cmake --build . --target test && \
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
cmake -DBUILD_TESTING=ON ../../../modules/{{ snake .Name }}_module/{{ snake .Name }} &&\
cmake --build . &&\
source activate.sh &&\
cmake --build . --target test &&\
source deactivate.sh &&\
conan install --build missing ../../../modules/{{ snake .Name }}_module &&\
conan create ../../../modules/{{ snake .Name }}_module
if [ $? -ne 0 ]; then exit 1; fi;
popd
{{- end }}
# leave build directory
cd ..
{{- if $features.examples }}
# examples app
mkdir -p build/examples/app;
pushd examples/app;
conan install --build missing . --install-folder ../../build/examples/app -g=virtualenv && cmake -S . -B ../../build/examples/app --preset release && cmake --build ../../build/examples/app
if [ $? -ne 0 ]; then exit 1; fi;
popd
# examples appthreadsafe
mkdir -p build/examples/appthreadsafe;
pushd examples/appthreadsafe;
conan install --build missing . --install-folder ../../build/examples/appthreadsafe -g=virtualenv && cmake  -S . -B ../../build/examples/appthreadsafe --preset release && cmake --build ../../build/examples/appthreadsafe
if [ $? -ne 0 ]; then exit 1; fi;
popd
{{- end}}
{{- if $features.examples_olink }}
mkdir -p build/examples/olinkserver;
pushd examples/olinkserver;
conan install --build missing . --install-folder ../../build/examples/olinkserver -g=virtualenv && cmake -S . -B ../../build/examples/olinkserver --preset release && cmake --build ../../build/examples/olinkserver
if [ $? -ne 0 ]; then exit 1; fi;
popd
mkdir -p build/examples/olinkclient;
pushd examples/olinkclient;
conan install --build missing . --install-folder ../../build/examples/olinkclient -g=virtualenv && cmake -S . -B ../../build/examples/olinkclient --preset release && cmake --build ../../build/examples/olinkclient
if [ $? -ne 0 ]; then exit 1; fi;
popd
{{- end}}
