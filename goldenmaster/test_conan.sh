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
conan remove "testbed2" -b -f
mkdir -p modules/testbed2;
pushd modules/testbed2;
conan source ../../../modules/testbed2 && conan install --build missing ../../../modules/testbed2 -g=virtualenv && conan build ../../../modules/testbed2 && cmake ../../../modules/testbed2 && cmake --build . && source activate.sh && cmake --build . --target check && source deactivate.sh &&\
conan install --build missing ../../../modules/testbed2 && conan create ../../../modules/testbed2
if [ $? -ne 0 ]; then exit 1; fi;
popd
conan remove "tb_enum" -b -f
mkdir -p modules/tb_enum;
pushd modules/tb_enum;
conan source ../../../modules/tb_enum && conan install --build missing ../../../modules/tb_enum -g=virtualenv && conan build ../../../modules/tb_enum && cmake ../../../modules/tb_enum && cmake --build . && source activate.sh && cmake --build . --target check && source deactivate.sh &&\
conan install --build missing ../../../modules/tb_enum && conan create ../../../modules/tb_enum
if [ $? -ne 0 ]; then exit 1; fi;
popd
conan remove "tb_same1" -b -f
mkdir -p modules/tb_same1;
pushd modules/tb_same1;
conan source ../../../modules/tb_same1 && conan install --build missing ../../../modules/tb_same1 -g=virtualenv && conan build ../../../modules/tb_same1 && cmake ../../../modules/tb_same1 && cmake --build . && source activate.sh && cmake --build . --target check && source deactivate.sh &&\
conan install --build missing ../../../modules/tb_same1 && conan create ../../../modules/tb_same1
if [ $? -ne 0 ]; then exit 1; fi;
popd
conan remove "tb_same2" -b -f
mkdir -p modules/tb_same2;
pushd modules/tb_same2;
conan source ../../../modules/tb_same2 && conan install --build missing ../../../modules/tb_same2 -g=virtualenv && conan build ../../../modules/tb_same2 && cmake ../../../modules/tb_same2 && cmake --build . && source activate.sh && cmake --build . --target check && source deactivate.sh &&\
conan install --build missing ../../../modules/tb_same2 && conan create ../../../modules/tb_same2
if [ $? -ne 0 ]; then exit 1; fi;
popd
conan remove "tb_simple" -b -f
mkdir -p modules/tb_simple;
pushd modules/tb_simple;
conan source ../../../modules/tb_simple && conan install --build missing ../../../modules/tb_simple -g=virtualenv && conan build ../../../modules/tb_simple && cmake ../../../modules/tb_simple && cmake --build . && source activate.sh && cmake --build . --target check && source deactivate.sh &&\
conan install --build missing ../../../modules/tb_simple && conan create ../../../modules/tb_simple
if [ $? -ne 0 ]; then exit 1; fi;
popd
conan remove "testbed1" -b -f
mkdir -p modules/testbed1;
pushd modules/testbed1;
conan source ../../../modules/testbed1 && conan install --build missing ../../../modules/testbed1 -g=virtualenv && conan build ../../../modules/testbed1 && cmake ../../../modules/testbed1 && cmake --build . && source activate.sh && cmake --build . --target check && source deactivate.sh &&\
conan install --build missing ../../../modules/testbed1 && conan create ../../../modules/testbed1
if [ $? -ne 0 ]; then exit 1; fi;
popd
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
