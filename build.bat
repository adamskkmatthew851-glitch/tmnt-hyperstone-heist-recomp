@echo off
set PATH=%~dp0cmake\bin;%~dp0mingw\bin;%PATH%
cmake -S . -B build -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release
if errorlevel 1 pause & exit /b 1
cmake --build build -j4
pause
