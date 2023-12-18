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
conan remove "apigear/*" -b -f --packages
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
if not exist apigear mkdir apigear
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
pushd apigear
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan source ../../../apigear
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan install --build missing ../../../apigear -g=virtualenv
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan build ../../../apigear
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan create ../../../apigear
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
popd
@REM Building and testing testbed2 module
conan remove "testbed2/*" -b -f --packages
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
if not exist modules\testbed2_module mkdir modules\testbed2_module
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
pushd modules\testbed2_module
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan source ../../../../modules/testbed2_module
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan install --build missing ../../../../modules/testbed2_module -g=virtualenv
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan build ../../../../modules/testbed2_module
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan create ../../../../modules/testbed2_module
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
popd
@REM Building and testing tb_enum module
conan remove "tb_enum/*" -b -f --packages
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
if not exist modules\tb_enum_module mkdir modules\tb_enum_module
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
pushd modules\tb_enum_module
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan source ../../../../modules/tb_enum_module
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan install --build missing ../../../../modules/tb_enum_module -g=virtualenv
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan build ../../../../modules/tb_enum_module
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan create ../../../../modules/tb_enum_module
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
popd
@REM Building and testing tb_same1 module
conan remove "tb_same1/*" -b -f --packages
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
if not exist modules\tb_same1_module mkdir modules\tb_same1_module
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
pushd modules\tb_same1_module
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan source ../../../../modules/tb_same1_module
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan install --build missing ../../../../modules/tb_same1_module -g=virtualenv
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan build ../../../../modules/tb_same1_module
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan create ../../../../modules/tb_same1_module
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
popd
@REM Building and testing tb_same2 module
conan remove "tb_same2/*" -b -f --packages
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
if not exist modules\tb_same2_module mkdir modules\tb_same2_module
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
pushd modules\tb_same2_module
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan source ../../../../modules/tb_same2_module
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan install --build missing ../../../../modules/tb_same2_module -g=virtualenv
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan build ../../../../modules/tb_same2_module
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan create ../../../../modules/tb_same2_module
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
popd
@REM Building and testing tb_simple module
conan remove "tb_simple/*" -b -f --packages
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
if not exist modules\tb_simple_module mkdir modules\tb_simple_module
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
pushd modules\tb_simple_module
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan source ../../../../modules/tb_simple_module
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan install --build missing ../../../../modules/tb_simple_module -g=virtualenv
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan build ../../../../modules/tb_simple_module
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan create ../../../../modules/tb_simple_module
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
popd
@REM Building and testing testbed1 module
conan remove "testbed1/*" -b -f --packages
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
if not exist modules\testbed1_module mkdir modules\testbed1_module
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
pushd modules\testbed1_module
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan source ../../../../modules/testbed1_module
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan install --build missing ../../../../modules/testbed1_module -g=virtualenv
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan build ../../../../modules/testbed1_module
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan create ../../../../modules/testbed1_module
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
popd
@REM Building and testing tb_names module
conan remove "tb_names/*" -b -f --packages
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
if not exist modules\tb_names_module mkdir modules\tb_names_module
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
pushd modules\tb_names_module
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan source ../../../../modules/tb_names_module
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan install --build missing ../../../../modules/tb_names_module -g=virtualenv
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan build ../../../../modules/tb_names_module
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan create ../../../../modules/tb_names_module
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
popd
@REM Leave build folder
cd ..
@REM Building examples app
if not exist build\examples\app mkdir build\examples\app
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
pushd ..\examples\app
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan install --build missing . --install-folder ../../build/examples/app -g=virtualenv
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
cmake -S . -B ../../build/examples/app --preset default
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
CALL ../../build/examples/app/activate.bat
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
cmake --build ../../build/examples/app
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
CALL ../../build/examples/app/deactivate.bat
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
popd
@REM Building examples appthreadsafe
if not exist build\examples\appthreadsafe mkdir build\examples\appthreadsafe
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
pushd ..\examples\appthreadsafe
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan install --build missing . --install-folder ../../build/examples/appthreadsafe -g=virtualenv
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
cmake -S . -B ../../build/examples/appthreadsafe --preset default
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
CALL ../../build/examples/appthreadsafe/activate.bat
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
cmake --build ../../build/examples/appthreadsafe
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
CALL ../../build/examples/appthreadsafe/deactivate.bat
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
popd
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
if not exist build\examples\olinkserver mkdir build\examples\olinkserver
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
pushd ..\examples\olinkserver
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan install --build missing . --install-folder ../../build/examples/olinkserver -g=virtualenv
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
cmake -S . -B ../../build/examples/olinkserver --preset default
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
CALL ../../build/examples/olinkserver/activate.bat
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
cmake --build ../../build/examples/olinkserver
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
CALL ../../build/examples/olinkserver/deactivate.bat
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
popd
if not exist build\examples\olinkclient mkdir build\examples\olinkclient
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
pushd ..\examples\olinkclient
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan install --build missing . --install-folder ../../build/examples/olinkclient -g=virtualenv
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
cmake -S . -B ../../build/examples/olinkclient --preset default
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
CALL ../../build/examples/olinkclient/activate.bat
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
cmake --build ../../build/examples/olinkclient
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
CALL ../../build/examples/olinkclient/deactivate.bat
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
popd
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
if not exist build\examples\mqttserver mkdir build\examples\mqttserver
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
pushd ..\examples\mqttserver
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan install --build missing . --install-folder ../../build/examples/mqttserver -g=virtualenv
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
cmake -S . -B ../../build/examples/mqttserver --preset default
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
CALL ../../build/examples/mqttserver/activate.bat
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
cmake --build ../../build/examples/mqttserver
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
CALL ../../build/examples/mqttserver/deactivate.bat
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
popd
if not exist examples\mqttclient mkdir examples\mqttclient
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
pushd ..\examples\mqttclient
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan install --build missing . --install-folder ../../build/examples/mqttclient -g=virtualenv
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
cmake -S . -B ../../build/examples/mqttclient --preset default
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
CALL ../../build/examples/mqttclient/activate.bat
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
cmake --build ../../build/examples/mqttclient
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
CALL ../../build/examples/mqttclient/deactivate.bat
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
popd
cd ..
