#!/bin/bash
set -x;
export DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )";
cd $DIR;
rm -rf build/ && mkdir -p build && cd build;
conan remove "apigear" -b -f
mkdir -p apigear;
pushd apigear;
conan source ../../apigear && conan install --build missing ../../apigear -g=virtualenv && conan build ../../apigear && cmake ../../apigear && cmake --build . && source activate.sh && cmake --build . --target check && \
conan install --build missing ../../apigear && conan create ../../apigear
if [ $? -ne 0 ]; then exit 1; fi;
popd
{% for module in system.modules %}
conan remove "{{module.name|identifier}}" -b -f
mkdir -p modules/{{module.name|identifier}}_module;
pushd modules/{{module.name|identifier}}_module;
conan source ../../../modules/{{module.name|identifier}}_module &&\
conan install --build missing ../../../modules/{{module.name|identifier}}_module -g=virtualenv &&\
conan build ../../../modules/{{module.name|identifier}}_module &&\
cmake ../../../modules/{{module.name|identifier}}_module/{{module.name|identifier}} &&\
cmake --build . &&\
source activate.sh &&\
cmake --build . --target check &&\
source deactivate.sh &&\
conan install --build missing ../../../modules/{{module.name|identifier}}_module &&\
conan create ../../../modules/{{module.name|identifier}}_module
if [ $? -ne 0 ]; then exit 1; fi;
popd
{% endfor %}
# examples app
mkdir -p examples/app;
pushd examples/app;
conan install --build missing ../../../examples/app -g=virtualenv && cmake ../../../examples/app && cmake --build .
if [ $? -ne 0 ]; then exit 1; fi;
popd
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
