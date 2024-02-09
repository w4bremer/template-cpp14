{{- $features := .Features -}}
SET DIR=%~dp0..
echo %DIR:~0,-1%
cd %DIR:~0,-1%
@RD /S /Q "%DIR:~0,-1%/build/"
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
if not exist build mkdir build
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
cd build
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
{{ if $features.apigear }}
@REM Building and testing apigear module
call :build_and_test_apigear "apigear" "../../../apigear"
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
{{- end }}
{{- range .System.Modules }}
@REM Building and testing {{snake .Name}} module
call :build_and_test_module "{{snake .Name}}" "../../../modules/{{snake .Name}}/conan"
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
{{- end }}

@REM Leave build folder
cd ..
{{ if $features.examples }}
call :build_example_app "..\examples\app"
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
call :build_example_app "..\examples\appthreadsafe"
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
{{- end}}
{{- if $features.examples_olink }}
call :build_example_app "..\examples\olinkserver"
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
call :build_example_app "..\examples\olinkclient"
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
{{- end}}
{{- if $features.examples_mqtt }}
call :build_example_app "..\examples\mqttserver"
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
call :build_example_app "..\examples\mqttclient"
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
{{- end}}

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
