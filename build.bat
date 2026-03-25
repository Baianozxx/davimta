@echo off
setlocal enabledelayedexpansion
call vcvars64.bat
mkdir build
cd build
cmake .. -G "Visual Studio 17 2022" -A x64
cmake --build . --config Release
echo Build completed successfully!