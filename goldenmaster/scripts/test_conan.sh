#!/bin/bash
set -x;

#
# function implementations
#
build_apigear()
{
    conan remove "apigear/*" -c
    mkdir -p apigear;
    pushd apigear;
    conan install --build missing ../../apigear -of . -g=VirtualBuildEnv &&\
    conan build ../../apigear -of . &&\
    conan build -b test ../../apigear -of . &&\
    ## build with cmake
    mkdir cmake_build && pushd cmake_build &&
    pwd &&\
    cmake -DCMAKE_BUILD_TYPE=Release -DBUILD_TESTING=ON -DCMAKE_PREFIX_PATH="`pwd`/../build/Release/generators/" -B. -S../../../apigear &&\
    cmake --build . &&\
    source ../build/Release/generators/conanbuild.sh &&\
    cmake --build . --target test &&\
    source ../build/Release/generators/deactivate_conanbuild.sh &&\
    popd &&\
    ## create conan package in cache
    conan create ../../apigear
    if [ $? -ne 0 ]; then exit 1; fi;
    popd
}

build_module()
{
    conan remove "$1/*" -c
    mkdir -p modules/$1;
    pushd modules;
    # install FindXXX.cmake files for dependencies
    pwd && mkdir -p $1 && cd $1 && pwd &&\
    conan install --build missing ../../../modules/$1/conan -of . &&\
    conan build ../../../modules/$1/conan -of . &&\
    conan build -b test ../../../modules/$1/conan -of . &&\
    ## build with cmake
    mkdir cmake_build && pushd cmake_build &&
    pwd &&\
    cmake -DCMAKE_BUILD_TYPE=Release -DBUILD_TESTING=ON -DCMAKE_PREFIX_PATH="`pwd`/../build/Release/generators/" -B. -S../../../../modules/$1 &&\
    cmake --build . &&\
    source ../build/Release/generators/conanbuild.sh &&\
    cmake --build . --target test &&\
    source ../build/Release/generators/deactivate_conanbuild.sh &&\
    popd &&\
    pwd &&\
    ## create conan package in cache
    conan create ../../../modules/$1/conan --build missing
    buildresult=$?
    popd
    if [ $buildresult -ne 0 ]; then exit 1; fi;
}

build_example()
{
    mkdir -p $1 &&\
    pushd $1 &&\
    cp -a ../../../$1/* . &&\
    conan install --build missing . -g=VirtualRunEnv &&\
    cmake -S . --preset conan-release &&\
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
