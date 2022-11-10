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
conan source ../apigear
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
pushd apigear
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan install --build missing ../../apigear -g=virtualenv
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan build ../../apigear
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan create ../../apigear
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
popd
{{- range .System.Modules }}
@REM Building and testing {{snake .Name}} module
conan remove "{{snake .Name}}" -b -f
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
if not exist modules\{{snake .Name}}_module mkdir modules\{{snake .Name}}_module
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
pushd modules\{{snake .Name}}_module
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan source ../../../modules/{{snake .Name}}_module
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan install --build missing ../../../modules/{{snake .Name}}_module -g=virtualenv
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan build ../../../modules/{{snake .Name}}_module
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan create ../../../modules/{{snake .Name}}_module
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
popd
{{- end }}
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
@REM Building examples appthreadsafe
if not exist examples\appthreadsafe mkdir examples\appthreadsafe
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
pushd examples\appthreadsafe
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan install --build missing ../../../examples/appthreadsafe -g=virtualenv
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
cmake ../../../examples/appthreadsafe
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
