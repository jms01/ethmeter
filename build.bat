
rem build resource object first
cd res && call build.bat && cd ..

set THISDIR=%~dp0
set BINDIR=%THISDIR%bin

%BINDIR%\tcc\tcc.exe -Wall -Wunusupported -I%THISDIR%\include -lshell32 -ladvapi32 -o ethmeter.exe main.c res\dialog.o
