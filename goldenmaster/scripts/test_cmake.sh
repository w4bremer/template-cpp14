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
buildCMakeModule "apigear" $source_root "-DAPIGEAR_BUILD_WITH_OLINK=ON -DAPIGEAR_BUILD_WITH_MONITOR=ON -DAPIGEAR_BUILD_WITH_MQTT=ON"
if [ $buildresult -ne 0 ]; then exit 1; fi;
buildCMakeModule "modules/testbed2_module/testbed2" $source_root
if [ $buildresult -ne 0 ]; then exit 1; fi;
buildCMakeModule "modules/tb_enum_module/tb_enum" $source_root
if [ $buildresult -ne 0 ]; then exit 1; fi;
buildCMakeModule "modules/tb_same1_module/tb_same1" $source_root
if [ $buildresult -ne 0 ]; then exit 1; fi;
buildCMakeModule "modules/tb_same2_module/tb_same2" $source_root
if [ $buildresult -ne 0 ]; then exit 1; fi;
buildCMakeModule "modules/tb_simple_module/tb_simple" $source_root
if [ $buildresult -ne 0 ]; then exit 1; fi;
buildCMakeModule "modules/testbed1_module/testbed1" $source_root
if [ $buildresult -ne 0 ]; then exit 1; fi;
buildCMakeModule "modules/tb_names_module/tb_names" $source_root
if [ $buildresult -ne 0 ]; then exit 1; fi;
# examples app
buildCMakeBinary "examples/app" $source_root
if [ $buildresult -ne 0 ]; then exit 1; fi;
# examples appthreadsafe
buildCMakeBinary "examples/appthreadsafe" $source_root
if [ $buildresult -ne 0 ]; then exit 1; fi;
buildCMakeBinary "examples/olinkserver" $source_root
if [ $buildresult -ne 0 ]; then exit 1; fi;
buildCMakeBinary "examples/olinkclient" $source_root
if [ $buildresult -ne 0 ]; then exit 1; fi;
buildCMakeBinary "examples/mqttserver" $source_root
if [ $buildresult -ne 0 ]; then exit 1; fi;
buildCMakeBinary "examples/mqttclient" $source_root
if [ $buildresult -ne 0 ]; then exit 1; fi;
