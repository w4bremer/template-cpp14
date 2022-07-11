SET DIR=%~dp0
echo %DIR:~0,-1%
cd %DIR:~0,-1%
@RD /S /Q "%DIR:~0,-1%/build/"
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
if not exist build mkdir build
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
cd build
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
@REM Building and testing apigear module
conan remove "apigear" -b -f
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
if not exist apigear mkdir apigear
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
pushd apigear
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan source ../../apigear
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan install --build missing ../../apigear -g=virtualenv
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan build ../../apigear
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
cmake ../../apigear
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
cmake --build . 
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
CALL activate.bat
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
cmake --build . --target check
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
CALL deactivate.bat
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan install --build missing ../../apigear
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan create ../../apigear
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
popd
@REM Building and testing testbed2 module
conan remove "testbed2" -b -f
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
if not exist modules\testbed2 mkdir modules\testbed2
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
pushd modules\testbed2
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan source ../../../modules/testbed2
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan install --build missing ../../../modules/testbed2 -g=virtualenv
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan build ../../../modules/testbed2
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
cmake ../../../modules/testbed2
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
cmake --build .
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
CALL activate.bat
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
cmake --build . --target check
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
CALL deactivate.bat
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan install --build missing ../../../modules/testbed2
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan create ../../../modules/testbed2
popd
@REM Building and testing tb_enum module
conan remove "tb_enum" -b -f
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
if not exist modules\tb_enum mkdir modules\tb_enum
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
pushd modules\tb_enum
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan source ../../../modules/tb_enum
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan install --build missing ../../../modules/tb_enum -g=virtualenv
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan build ../../../modules/tb_enum
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
cmake ../../../modules/tb_enum
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
cmake --build .
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
CALL activate.bat
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
cmake --build . --target check
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
CALL deactivate.bat
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan install --build missing ../../../modules/tb_enum
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan create ../../../modules/tb_enum
popd
@REM Building and testing tb_same1 module
conan remove "tb_same1" -b -f
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
if not exist modules\tb_same1 mkdir modules\tb_same1
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
pushd modules\tb_same1
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan source ../../../modules/tb_same1
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan install --build missing ../../../modules/tb_same1 -g=virtualenv
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan build ../../../modules/tb_same1
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
cmake ../../../modules/tb_same1
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
cmake --build .
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
CALL activate.bat
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
cmake --build . --target check
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
CALL deactivate.bat
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan install --build missing ../../../modules/tb_same1
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan create ../../../modules/tb_same1
popd
@REM Building and testing tb_same2 module
conan remove "tb_same2" -b -f
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
if not exist modules\tb_same2 mkdir modules\tb_same2
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
pushd modules\tb_same2
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan source ../../../modules/tb_same2
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan install --build missing ../../../modules/tb_same2 -g=virtualenv
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan build ../../../modules/tb_same2
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
cmake ../../../modules/tb_same2
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
cmake --build .
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
CALL activate.bat
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
cmake --build . --target check
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
CALL deactivate.bat
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan install --build missing ../../../modules/tb_same2
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan create ../../../modules/tb_same2
popd
@REM Building and testing tb_simple module
conan remove "tb_simple" -b -f
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
if not exist modules\tb_simple mkdir modules\tb_simple
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
pushd modules\tb_simple
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan source ../../../modules/tb_simple
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan install --build missing ../../../modules/tb_simple -g=virtualenv
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan build ../../../modules/tb_simple
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
cmake ../../../modules/tb_simple
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
cmake --build .
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
CALL activate.bat
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
cmake --build . --target check
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
CALL deactivate.bat
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan install --build missing ../../../modules/tb_simple
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan create ../../../modules/tb_simple
popd
@REM Building and testing testbed1 module
conan remove "testbed1" -b -f
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
if not exist modules\testbed1 mkdir modules\testbed1
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
pushd modules\testbed1
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan source ../../../modules/testbed1
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan install --build missing ../../../modules/testbed1 -g=virtualenv
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan build ../../../modules/testbed1
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
cmake ../../../modules/testbed1
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
cmake --build .
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
CALL activate.bat
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
cmake --build . --target check
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
CALL deactivate.bat
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan install --build missing ../../../modules/testbed1
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan create ../../../modules/testbed1
popd
@REM Building examples app
if not exist examples\app mkdir examples\app
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
pushd examples\app
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan install --build missing ../../../examples/app -g=virtualenv
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
cmake ../../../examples/app
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
CALL activate.bat
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
cmake --build .
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
CALL deactivate.bat
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
popd
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
if not exist examples\olinkserver mkdir examples\olinkserver
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
pushd examples\olinkserver
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan install --build missing ../../../examples/olinkserver -g=virtualenv
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
cmake ../../../examples/olinkserver
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
CALL activate.bat
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
cmake --build .
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
CALL deactivate.bat
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
popd
if not exist examples\olinkclient mkdir examples\olinkclient
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
pushd examples\olinkclient
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan install --build missing ../../../examples/olinkclient -g=virtualenv
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
cmake ../../../examples/olinkclient
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
CALL activate.bat
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
cmake --build .
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
CALL deactivate.bat
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
popd
cd ..
