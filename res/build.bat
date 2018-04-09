
set THISDIR=%~dp0
set BINDIR=%THISDIR%..\bin

%BINDIR%\gorc /ni /o dialog.rc

rem rename ".rsrc$01" GoRC section name to *nix COFF ".rsrc"
%BINDIR%\sed "s/.rsrc$01/.rsrc\x0\x0\x0/g" dialog.obj > dialog.o
