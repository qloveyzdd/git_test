# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = D:\cmake-3.17.0-rc3-win64-x64\bin\cmake.exe

# The command to remove a file.
RM = D:\cmake-3.17.0-rc3-win64-x64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\git_test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\git_test\build

# Include any dependencies generated for this target.
include main_core/CMakeFiles/main_core.dir/depend.make

# Include the progress variables for this target.
include main_core/CMakeFiles/main_core.dir/progress.make

# Include the compile flags for this target's objects.
include main_core/CMakeFiles/main_core.dir/flags.make

main_core/CMakeFiles/main_core.dir/Private/git.obj: main_core/CMakeFiles/main_core.dir/flags.make
main_core/CMakeFiles/main_core.dir/Private/git.obj: ../main_core/Private/git.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\git_test\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object main_core/CMakeFiles/main_core.dir/Private/git.obj"
	cd /d D:\git_test\build\main_core && D:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\main_core.dir\Private\git.obj   -c D:\git_test\main_core\Private\git.c

main_core/CMakeFiles/main_core.dir/Private/git.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main_core.dir/Private/git.i"
	cd /d D:\git_test\build\main_core && D:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\git_test\main_core\Private\git.c > CMakeFiles\main_core.dir\Private\git.i

main_core/CMakeFiles/main_core.dir/Private/git.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main_core.dir/Private/git.s"
	cd /d D:\git_test\build\main_core && D:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\git_test\main_core\Private\git.c -o CMakeFiles\main_core.dir\Private\git.s

main_core/CMakeFiles/main_core.dir/Private/log.obj: main_core/CMakeFiles/main_core.dir/flags.make
main_core/CMakeFiles/main_core.dir/Private/log.obj: ../main_core/Private/log.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\git_test\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object main_core/CMakeFiles/main_core.dir/Private/log.obj"
	cd /d D:\git_test\build\main_core && D:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\main_core.dir\Private\log.obj   -c D:\git_test\main_core\Private\log.c

main_core/CMakeFiles/main_core.dir/Private/log.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main_core.dir/Private/log.i"
	cd /d D:\git_test\build\main_core && D:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\git_test\main_core\Private\log.c > CMakeFiles\main_core.dir\Private\log.i

main_core/CMakeFiles/main_core.dir/Private/log.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main_core.dir/Private/log.s"
	cd /d D:\git_test\build\main_core && D:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\git_test\main_core\Private\log.c -o CMakeFiles\main_core.dir\Private\log.s

main_core/CMakeFiles/main_core.dir/Private/main_core.obj: main_core/CMakeFiles/main_core.dir/flags.make
main_core/CMakeFiles/main_core.dir/Private/main_core.obj: ../main_core/Private/main_core.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\git_test\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object main_core/CMakeFiles/main_core.dir/Private/main_core.obj"
	cd /d D:\git_test\build\main_core && D:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\main_core.dir\Private\main_core.obj   -c D:\git_test\main_core\Private\main_core.c

main_core/CMakeFiles/main_core.dir/Private/main_core.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main_core.dir/Private/main_core.i"
	cd /d D:\git_test\build\main_core && D:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\git_test\main_core\Private\main_core.c > CMakeFiles\main_core.dir\Private\main_core.i

main_core/CMakeFiles/main_core.dir/Private/main_core.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main_core.dir/Private/main_core.s"
	cd /d D:\git_test\build\main_core && D:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\git_test\main_core\Private\main_core.c -o CMakeFiles\main_core.dir\Private\main_core.s

# Object files for target main_core
main_core_OBJECTS = \
"CMakeFiles/main_core.dir/Private/git.obj" \
"CMakeFiles/main_core.dir/Private/log.obj" \
"CMakeFiles/main_core.dir/Private/main_core.obj"

# External object files for target main_core
main_core_EXTERNAL_OBJECTS =

lib/libmain_core.dll: main_core/CMakeFiles/main_core.dir/Private/git.obj
lib/libmain_core.dll: main_core/CMakeFiles/main_core.dir/Private/log.obj
lib/libmain_core.dll: main_core/CMakeFiles/main_core.dir/Private/main_core.obj
lib/libmain_core.dll: main_core/CMakeFiles/main_core.dir/build.make
lib/libmain_core.dll: lib/libsimple_c_guid.dll.a
lib/libmain_core.dll: simple_c_array/libsimple_c_array.a
lib/libmain_core.dll: main_core/CMakeFiles/main_core.dir/linklibs.rsp
lib/libmain_core.dll: main_core/CMakeFiles/main_core.dir/objects1.rsp
lib/libmain_core.dll: main_core/CMakeFiles/main_core.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\git_test\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C shared library ..\lib\libmain_core.dll"
	cd /d D:\git_test\build\main_core && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\main_core.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
main_core/CMakeFiles/main_core.dir/build: lib/libmain_core.dll

.PHONY : main_core/CMakeFiles/main_core.dir/build

main_core/CMakeFiles/main_core.dir/clean:
	cd /d D:\git_test\build\main_core && $(CMAKE_COMMAND) -P CMakeFiles\main_core.dir\cmake_clean.cmake
.PHONY : main_core/CMakeFiles/main_core.dir/clean

main_core/CMakeFiles/main_core.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\git_test D:\git_test\main_core D:\git_test\build D:\git_test\build\main_core D:\git_test\build\main_core\CMakeFiles\main_core.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : main_core/CMakeFiles/main_core.dir/depend

