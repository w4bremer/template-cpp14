SET DIR=%~dp0..
echo %DIR:~0,-1%
cd %DIR:~0,-1%
@RD /S /Q "%DIR:~0,-1%/build/"
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
if not exist build mkdir build
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
cd build
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%

@REM Building and testing apigear module
call :build_and_test_apigear "apigear" "../../../apigear"
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
@REM Building and testing testbed2 module
call :build_and_test_module "testbed2" "../../../modules/testbed2/conan"
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
@REM Building and testing tb_enum module
call :build_and_test_module "tb_enum" "../../../modules/tb_enum/conan"
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
@REM Building and testing tb_same1 module
call :build_and_test_module "tb_same1" "../../../modules/tb_same1/conan"
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
@REM Building and testing tb_same2 module
call :build_and_test_module "tb_same2" "../../../modules/tb_same2/conan"
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
@REM Building and testing tb_simple module
call :build_and_test_module "tb_simple" "../../../modules/tb_simple/conan"
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
@REM Building and testing testbed1 module
call :build_and_test_module "testbed1" "../../../modules/testbed1/conan"
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
@REM Building and testing tb_names module
call :build_and_test_module "tb_names" "../../../modules/tb_names/conan"
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%

@REM Leave build folder
cd ..

call :build_example_app "..\examples\app"
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
call :build_example_app "..\examples\appthreadsafe"
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
call :build_example_app "..\examples\olinkserver"
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
call :build_example_app "..\examples\olinkclient"
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
call :build_example_app "..\examples\mqttserver"
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
call :build_example_app "..\examples\mqttclient"
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%

exit /b

:build_and_test_apigear
conan remove "%~1/*" -b -f --packages
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
if not exist %~1 mkdir %~1
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
pushd %~1
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan source %~2
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan install --build missing . -g=virtualenv
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan build .
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan create %~2 --build missing
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
popd
exit /b

:build_and_test_module
conan remove "%~1/*" -b -f --packages
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
if not exist modules\%~1 mkdir modules\%~1
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
pushd modules
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan source %~2
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
pushd %~1
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan install --build missing conan -g=virtualenv
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan build conan
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
popd
conan create %~2 --build missing
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
popd
exit /b

:build_example_app
if not exist build\examples\%~1 mkdir build\examples\%~1
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
pushd ..\examples\%~1
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan install --build missing . --install-folder ../../build/examples/%~1 -g=virtualenv
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
cmake -S . -B ../../build/examples/%~1 --preset default
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
CALL ../../build/examples/%~1/activate.bat
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
cmake --build ../../build/examples/%~1
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
CALL ../../build/examples/%~1/deactivate.bat
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
popd
exit /b
