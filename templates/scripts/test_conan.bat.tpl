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
{{- if $features.apigear }}
@REM Building and testing apigear module
conan remove "apigear" -b -f
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
{{- end }}
{{- range .System.Modules }}
@REM Building and testing {{snake .Name}} module
conan remove "{{snake .Name}}" -b -f
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
if not exist modules\{{snake .Name}}_module mkdir modules\{{snake .Name}}_module
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
pushd modules\{{snake .Name}}_module
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan source ../../../../modules/{{snake .Name}}_module
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan install --build missing ../../../../modules/{{snake .Name}}_module -g=virtualenv
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan build ../../../../modules/{{snake .Name}}_module
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan create ../../../../modules/{{snake .Name}}_module
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
popd
{{- end }}
@REM Leave build folder
cd ..
{{- if $features.examples }}
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
{{- end}}
{{- if $features.examples_olink }}
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
{{- end}}
{{- if $features.examples_mqtt }}
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
{{- end}}
