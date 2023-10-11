#!/bin/bash
set -x;
export DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )";
cd $DIR;
rm -rf build/ && mkdir -p build && cd build;
conan remove "apigear" -b -f
mkdir -p apigear;
pushd apigear;
conan source ../../apigear && conan install --build missing ../../apigear -g=virtualenv && conan build ../../apigear && cmake -DBUILD_TESTING=ON ../../apigear && cmake --build . && source activate.sh && cmake --build . --target test && \
conan install --build missing ../../apigear && conan create ../../apigear
if [ $? -ne 0 ]; then exit 1; fi;
popd
conan remove "testbed2" -b -f
mkdir -p modules/testbed2_module;
pushd modules/testbed2_module;
conan source ../../../modules/testbed2_module &&\
conan install --build missing ../../../modules/testbed2_module -g=virtualenv &&\
conan build ../../../modules/testbed2_module &&\
cmake -DBUILD_TESTING=ON ../../../modules/testbed2_module/testbed2 &&\
cmake --build . &&\
source activate.sh &&\
cmake --build . --target test &&\
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
cmake -DBUILD_TESTING=ON ../../../modules/tb_enum_module/tb_enum &&\
cmake --build . &&\
source activate.sh &&\
cmake --build . --target test &&\
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
cmake -DBUILD_TESTING=ON ../../../modules/tb_same1_module/tb_same1 &&\
cmake --build . &&\
source activate.sh &&\
cmake --build . --target test &&\
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
cmake -DBUILD_TESTING=ON ../../../modules/tb_same2_module/tb_same2 &&\
cmake --build . &&\
source activate.sh &&\
cmake --build . --target test &&\
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
cmake -DBUILD_TESTING=ON ../../../modules/tb_simple_module/tb_simple &&\
cmake --build . &&\
source activate.sh &&\
cmake --build . --target test &&\
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
cmake -DBUILD_TESTING=ON ../../../modules/testbed1_module/testbed1 &&\
cmake --build . &&\
source activate.sh &&\
cmake --build . --target test &&\
source deactivate.sh &&\
conan install --build missing ../../../modules/testbed1_module &&\
conan create ../../../modules/testbed1_module
if [ $? -ne 0 ]; then exit 1; fi;
popd
conan remove "tb_names" -b -f
mkdir -p modules/tb_names_module;
pushd modules/tb_names_module;
conan source ../../../modules/tb_names_module &&\
conan install --build missing ../../../modules/tb_names_module -g=virtualenv &&\
conan build ../../../modules/tb_names_module &&\
cmake -DBUILD_TESTING=ON ../../../modules/tb_names_module/tb_names &&\
cmake --build . &&\
source activate.sh &&\
cmake --build . --target test &&\
source deactivate.sh &&\
conan install --build missing ../../../modules/tb_names_module &&\
conan create ../../../modules/tb_names_module
if [ $? -ne 0 ]; then exit 1; fi;
popd
# leave build directory
cd ..
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
mkdir -p build/examples/mqttserver;
pushd examples/mqttserver;
conan install --build missing . --install-folder ../../build/examples/mqttserver -g=virtualenv && cmake -S . -B ../../build/examples/mqttserver --preset release && cmake --build ../../build/examples/mqttserver
if [ $? -ne 0 ]; then exit 1; fi;
popd
mkdir -p build/examples/mqttclient;
pushd examples/mqttclient;
conan install --build missing . --install-folder ../../build/examples/mqttclient -g=virtualenv && cmake -S . -B ../../build/examples/mqttclient --preset release && cmake --build ../../build/examples/mqttclient
if [ $? -ne 0 ]; then exit 1; fi;
popd
