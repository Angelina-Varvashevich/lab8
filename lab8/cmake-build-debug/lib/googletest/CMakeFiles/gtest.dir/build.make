# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\clion\lab8

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\clion\lab8\cmake-build-debug

# Include any dependencies generated for this target.
include lib\googletest\CMakeFiles\gtest.dir\depend.make
# Include the progress variables for this target.
include lib\googletest\CMakeFiles\gtest.dir\progress.make

# Include the compile flags for this target's objects.
include lib\googletest\CMakeFiles\gtest.dir\flags.make

lib\googletest\CMakeFiles\gtest.dir\src\gtest-all.cc.obj: lib\googletest\CMakeFiles\gtest.dir\flags.make
lib\googletest\CMakeFiles\gtest.dir\src\gtest-all.cc.obj: ..\lib\googletest\src\gtest-all.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\clion\lab8\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.obj"
	cd D:\clion\lab8\cmake-build-debug\lib\googletest
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\gtest.dir\src\gtest-all.cc.obj /Fd..\..\bin\gtestd.pdb /FS -c D:\clion\lab8\lib\googletest\src\gtest-all.cc
<<
	cd D:\clion\lab8\cmake-build-debug

lib\googletest\CMakeFiles\gtest.dir\src\gtest-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtest.dir/src/gtest-all.cc.i"
	cd D:\clion\lab8\cmake-build-debug\lib\googletest
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe > CMakeFiles\gtest.dir\src\gtest-all.cc.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\clion\lab8\lib\googletest\src\gtest-all.cc
<<
	cd D:\clion\lab8\cmake-build-debug

lib\googletest\CMakeFiles\gtest.dir\src\gtest-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtest.dir/src/gtest-all.cc.s"
	cd D:\clion\lab8\cmake-build-debug\lib\googletest
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\gtest.dir\src\gtest-all.cc.s /c D:\clion\lab8\lib\googletest\src\gtest-all.cc
<<
	cd D:\clion\lab8\cmake-build-debug

# Object files for target gtest
gtest_OBJECTS = \
"CMakeFiles\gtest.dir\src\gtest-all.cc.obj"

# External object files for target gtest
gtest_EXTERNAL_OBJECTS =

lib\gtestd.lib: lib\googletest\CMakeFiles\gtest.dir\src\gtest-all.cc.obj
lib\gtestd.lib: lib\googletest\CMakeFiles\gtest.dir\build.make
lib\gtestd.lib: lib\googletest\CMakeFiles\gtest.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\clion\lab8\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ..\gtestd.lib"
	cd D:\clion\lab8\cmake-build-debug\lib\googletest
	$(CMAKE_COMMAND) -P CMakeFiles\gtest.dir\cmake_clean_target.cmake
	cd D:\clion\lab8\cmake-build-debug
	cd D:\clion\lab8\cmake-build-debug\lib\googletest
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\lib.exe /nologo /machine:X86 /out:..\gtestd.lib @CMakeFiles\gtest.dir\objects1.rsp 
	cd D:\clion\lab8\cmake-build-debug

# Rule to build all files generated by this target.
lib\googletest\CMakeFiles\gtest.dir\build: lib\gtestd.lib
.PHONY : lib\googletest\CMakeFiles\gtest.dir\build

lib\googletest\CMakeFiles\gtest.dir\clean:
	cd D:\clion\lab8\cmake-build-debug\lib\googletest
	$(CMAKE_COMMAND) -P CMakeFiles\gtest.dir\cmake_clean.cmake
	cd D:\clion\lab8\cmake-build-debug
.PHONY : lib\googletest\CMakeFiles\gtest.dir\clean

lib\googletest\CMakeFiles\gtest.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" D:\clion\lab8 D:\clion\lab8\lib\googletest D:\clion\lab8\cmake-build-debug D:\clion\lab8\cmake-build-debug\lib\googletest D:\clion\lab8\cmake-build-debug\lib\googletest\CMakeFiles\gtest.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : lib\googletest\CMakeFiles\gtest.dir\depend

