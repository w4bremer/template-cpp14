#!/bin/bash
set -x;

#
# function implementations
#
build_apigear()
{
    conan remove "apigear/*" -b -f --packages
    mkdir -p apigear;
    pushd apigear;
    conan source ../../apigear && conan install --build missing ../../apigear -g=virtualenv && conan build ../../apigear && cmake -DBUILD_TESTING=ON ../../apigear && cmake --build . && source activate.sh && cmake --build . --target test && \
    conan install --build missing ../../apigear && conan create ../../apigear
    if [ $? -ne 0 ]; then exit 1; fi;
    popd
}

build_module()
{
    conan remove "$1/*" -b -f --packages
    mkdir -p modules/$1_module;
    pushd modules/$1_module;
    conan source ../../../modules/$1_module &&\
    conan install --build missing ../../../modules/$1_module -g=virtualenv &&\
    conan build ../../../modules/$1_module &&\
    cmake -DBUILD_TESTING=ON ../../../modules/$1_module/$1 &&\
    cmake --build . &&\
    source activate.sh &&\
    cmake --build . --target test &&\
    source deactivate.sh &&\
    conan install --build missing ../../../modules/$1_module &&\
    conan create ../../../modules/$1_module
    buildresult=$?
    popd
    if [ $buildresult -ne 0 ]; then exit 1; fi;
}

build_example()
{
    mkdir -p $1 &&\
    pushd $1 &&\
    cp -a ../../../$1/* . &&\
    conan install --build missing . -g=virtualenv &&\
    cmake -S . --preset release &&\
    cmake --build .
    buildresult=$?
    popd
    if [ $buildresult -ne 0 ]; then exit 1; fi;
}

#
# main
#
export DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )/..";
cd $DIR;
rm -rf build/ && mkdir -p build && cd build;
if [ $? -ne 0 ]; then exit 1; fi;
build_apigear
# Building and testing Testbed2 module
build_module "testbed2"
# Building and testing TbEnum module
build_module "tb_enum"
# Building and testing TbSame1 module
build_module "tb_same1"
# Building and testing TbSame2 module
build_module "tb_same2"
# Building and testing TbSimple module
build_module "tb_simple"
# Building and testing Testbed1 module
build_module "testbed1"
# Building and testing TbNames module
build_module "tb_names"
build_example "examples/app"
build_example "examples/appthreadsafe"
build_example "examples/olinkserver"
build_example "examples/olinkclient"
build_example "examples/mqttserver"
build_example "examples/mqttclient"
# leave build directory
cd ..
