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
mkdir -p modules/testbed2_module;
pushd modules/testbed2_module;
conan source ../../../modules/testbed2_module &&\
conan install --build missing ../../../modules/testbed2_module -g=virtualenv &&\
conan build ../../../modules/testbed2_module &&\
cmake ../../../modules/testbed2_module/testbed2 &&\
cmake --build . &&\
source activate.sh &&\
cmake --build . --target check &&\
source deactivate.sh &&\
conan install --build missing ../../../modules/testbed2_module &&\
conan create ../../../modules/testbed2_module
if [ $? -ne 0 ]; then exit 1; fi;
popd
conan remove "tb_enum" -b -f
mkdir -p modules/tb_enum_module;
pushd modules/tb_enum_module;
conan source ../../../modules/tb_enum_module &&\
conan install --build missing ../../../modules/tb_enum_module -g=virtualenv &&\
conan build ../../../modules/tb_enum_module &&\
cmake ../../../modules/tb_enum_module/tb_enum &&\
cmake --build . &&\
source activate.sh &&\
cmake --build . --target check &&\
source deactivate.sh &&\
conan install --build missing ../../../modules/tb_enum_module &&\
conan create ../../../modules/tb_enum_module
if [ $? -ne 0 ]; then exit 1; fi;
popd
conan remove "tb_same1" -b -f
mkdir -p modules/tb_same1_module;
pushd modules/tb_same1_module;
conan source ../../../modules/tb_same1_module &&\
conan install --build missing ../../../modules/tb_same1_module -g=virtualenv &&\
conan build ../../../modules/tb_same1_module &&\
cmake ../../../modules/tb_same1_module/tb_same1 &&\
cmake --build . &&\
source activate.sh &&\
cmake --build . --target check &&\
source deactivate.sh &&\
conan install --build missing ../../../modules/tb_same1_module &&\
conan create ../../../modules/tb_same1_module
if [ $? -ne 0 ]; then exit 1; fi;
popd
conan remove "tb_same2" -b -f
mkdir -p modules/tb_same2_module;
pushd modules/tb_same2_module;
conan source ../../../modules/tb_same2_module &&\
conan install --build missing ../../../modules/tb_same2_module -g=virtualenv &&\
conan build ../../../modules/tb_same2_module &&\
cmake ../../../modules/tb_same2_module/tb_same2 &&\
cmake --build . &&\
source activate.sh &&\
cmake --build . --target check &&\
source deactivate.sh &&\
conan install --build missing ../../../modules/tb_same2_module &&\
conan create ../../../modules/tb_same2_module
if [ $? -ne 0 ]; then exit 1; fi;
popd
conan remove "tb_simple" -b -f
mkdir -p modules/tb_simple_module;
pushd modules/tb_simple_module;
conan source ../../../modules/tb_simple_module &&\
conan install --build missing ../../../modules/tb_simple_module -g=virtualenv &&\
conan build ../../../modules/tb_simple_module &&\
cmake ../../../modules/tb_simple_module/tb_simple &&\
cmake --build . &&\
source activate.sh &&\
cmake --build . --target check &&\
source deactivate.sh &&\
conan install --build missing ../../../modules/tb_simple_module &&\
conan create ../../../modules/tb_simple_module
if [ $? -ne 0 ]; then exit 1; fi;
popd
conan remove "testbed1" -b -f
mkdir -p modules/testbed1_module;
pushd modules/testbed1_module;
conan source ../../../modules/testbed1_module &&\
conan install --build missing ../../../modules/testbed1_module -g=virtualenv &&\
conan build ../../../modules/testbed1_module &&\
cmake ../../../modules/testbed1_module/testbed1 &&\
cmake --build . &&\
source activate.sh &&\
cmake --build . --target check &&\
source deactivate.sh &&\
conan install --build missing ../../../modules/testbed1_module &&\
conan create ../../../modules/testbed1_module
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
