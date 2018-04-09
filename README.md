# EthMeter

Measure your current up- and download rate in kB/s.

Built for Windows and is an exercise in keeping the footprint of a simple application small at the cost of development speed and developer convenience.

## Build

Set up your build environment by getting:

- [Tiny C Compiler](https://bellard.org/tcc/) and unpacking it in \<project\>/bin/tcc/
- [GoRes.exe](http://www.godevtool.com/) and putting the binary in \<project\>/bin/
- [sed.exe](http://www.pement.org/sed/gsed407x.zip) and putting the binary in \<project\>/bin/

**Note:** make sure you get a sed binary prepared to edit binary files. Some binaries floating around mangle the binary files they edit. This can result in TCC throwing the error "res/dialog.o: error: unrecognized file type".

Your \<project\> directory structure should look something like this:

```
<project>/bin/tcc/tcc.exe
<project>/bin/tcc/{libtcc.dll,include,lib}... (rest of the TCC package)
<project>/bin/GoRC.exe
<project>/bin/sed.exe
<project>/main.c
<project>/build.bat
```

Now run "build.bat" in the project directory:

```
C:\ethmeter> build.bat
```

This should result in an ethmeter.exe binary in the project directory.
Run it and in the top right corner of the screen the main window is displayed.

Closing the application can be done by double clicking the window or the system tray icon.

## Peculiarities

Forget developer convenience, this project is an exercise in:

- creating a simple utility application for Windows using C
  - leveraging many low-level Windows API calls which have been around for 20 years or more
- using a small, portable development environment which can run on (almost) any Windows system
  - composed of free software (TCC and sed as in speech, GoRes as in beer)
- foregoing the fact that hardware is cheap compared to a developer's time

This results in:

- an extremely low footprint compilation environment (\<1mb on disk, see below)
- extremely fast C source compilation, due to compiling against a handpicked subset of the winapi functions
- extremely slow development of the program, due to the custom winapi header files
- extremely small binary (~8kb) and runtime resource consumption (~3mb RAM, almost no CPU time)

### Build environment

Instead of using the Microsoft Visual C development environment, ethmeter is meant to be built with a more bare bones environment:

- compile the C code with [Tiny C Compiler](https://bellard.org/tcc/) for Windows
- compile the resource script using
  - [GoRes.exe](http://www.godevtool.com/) (.rc to .obj)
  - [sed.exe](http://www.pement.org/sed/gsed407x.zip) (rename the ".rsrc$01" section to ".rsrc")
- use batch (.bat) files to drive the build tools, instead of makefiles and a make clone

This results in a build environment with a footprint of ~700kb (not counting TCC's include files).

**Note:** The GoRC generated object file is not compatible with the format TCC accepts. GoRC compiles the resource script to a ".rsrc$01" named COFF section, like Microsoft's cvtres.exe does. TCC only accepts resource COFF objects with a ".rsrc" named section, as created by windres.exe of the MinGW project.

### Include files (winapi headers)

This application uses a small subset of the Windows API. The code is so small, it doesn't warrant parsing the full stack of winapi header files every time the program is recompiled.

Quite painstakingly, all winapi functions, structs and constants required by the program have been extracted from the full winapi header files and gathered in the include/ subdirectory. This handpicked subset of the full winapi header files is distributed with the source code.

### AppStruct global variable and modularity

The AppStruct global variable is the place where all modules store their runtime state.

The program was built with modularity in mind, but it did not turn out as expected.

Most notably, when plugging in a new module the AppStruct global needs to be modified to accommodate the runtime state of the new module.
Additionally, each module needs to know about the application level AppStruct global to set and retrieve it's state.

These things break proper separation of concerns and data encapsulation.

## License

All code is licensed under the Mozilla Public License Version 2.0
