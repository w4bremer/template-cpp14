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
popd
conan remove "org_objectapi_testbed" -b -f
mkdir -p modules/org_objectapi_testbed;
pushd modules/org_objectapi_testbed;
conan source ../../../modules/org_objectapi_testbed && conan install --build missing ../../../modules/org_objectapi_testbed -g=virtualenv && conan build ../../../modules/org_objectapi_testbed && cmake ../../../modules/org_objectapi_testbed && cmake --build . && source activate.sh && cmake --build . --target check && source deactivate.sh &&\
conan install --build missing ../../../modules/org_objectapi_testbed && conan create ../../../modules/org_objectapi_testbed
popd
# examples app
mkdir -p examples/app;
pushd examples/app;
conan install --build missing ../../../examples/app -g=virtualenv && cmake ../../../examples/app && cmake --build .
popd
mkdir -p examples/olinkserver;
pushd examples/olinkserver;
conan install --build missing ../../../examples/olinkserver -g=virtualenv && cmake ../../../examples/olinkserver && cmake --build .
popd
mkdir -p examples/olinkclient;
pushd examples/olinkclient;
conan install --build missing ../../../examples/olinkclient -g=virtualenv && cmake ../../../examples/olinkclient && cmake --build .
popd
