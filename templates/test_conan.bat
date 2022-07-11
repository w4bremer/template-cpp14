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
{% for module in system.modules %}
@REM Building and testing {{module.name|identifier}} module
conan remove "{{module.name|identifier}}" -b -f
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
if not exist modules\{{module.name|identifier}} mkdir modules\{{module.name|identifier}}
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
pushd modules\{{module.name|identifier}}
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan source ../../../modules/{{module.name|identifier}}
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan install --build missing ../../../modules/{{module.name|identifier}} -g=virtualenv
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan build ../../../modules/{{module.name|identifier}}
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
cmake ../../../modules/{{module.name|identifier}}
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
cmake --build .
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
CALL activate.bat
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
cmake --build . --target check
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
CALL deactivate.bat
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan install --build missing ../../../modules/{{module.name|identifier}}
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
conan create ../../../modules/{{module.name|identifier}}
popd
{% endfor %}
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
