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
include simple_c_path/CMakeFiles/simple_c_path.dir/depend.make

# Include the progress variables for this target.
include simple_c_path/CMakeFiles/simple_c_path.dir/progress.make

# Include the compile flags for this target's objects.
include simple_c_path/CMakeFiles/simple_c_path.dir/flags.make

simple_c_path/CMakeFiles/simple_c_path.dir/Private/simple_path.obj: simple_c_path/CMakeFiles/simple_c_path.dir/flags.make
simple_c_path/CMakeFiles/simple_c_path.dir/Private/simple_path.obj: ../simple_c_path/Private/simple_path.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\git_test\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object simple_c_path/CMakeFiles/simple_c_path.dir/Private/simple_path.obj"
	cd /d D:\git_test\build\simple_c_path && D:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\simple_c_path.dir\Private\simple_path.obj   -c D:\git_test\simple_c_path\Private\simple_path.c

simple_c_path/CMakeFiles/simple_c_path.dir/Private/simple_path.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/simple_c_path.dir/Private/simple_path.i"
	cd /d D:\git_test\build\simple_c_path && D:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\git_test\simple_c_path\Private\simple_path.c > CMakeFiles\simple_c_path.dir\Private\simple_path.i

simple_c_path/CMakeFiles/simple_c_path.dir/Private/simple_path.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/simple_c_path.dir/Private/simple_path.s"
	cd /d D:\git_test\build\simple_c_path && D:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\git_test\simple_c_path\Private\simple_path.c -o CMakeFiles\simple_c_path.dir\Private\simple_path.s

# Object files for target simple_c_path
simple_c_path_OBJECTS = \
"CMakeFiles/simple_c_path.dir/Private/simple_path.obj"

# External object files for target simple_c_path
simple_c_path_EXTERNAL_OBJECTS =

lib/libsimple_c_path.dll: simple_c_path/CMakeFiles/simple_c_path.dir/Private/simple_path.obj
lib/libsimple_c_path.dll: simple_c_path/CMakeFiles/simple_c_path.dir/build.make
lib/libsimple_c_path.dll: simple_c_array/libsimple_c_array.a
lib/libsimple_c_path.dll: simple_c_string_algorithm/libsimple_c_string_algorithm.a
lib/libsimple_c_path.dll: simple_c_path/CMakeFiles/simple_c_path.dir/linklibs.rsp
lib/libsimple_c_path.dll: simple_c_path/CMakeFiles/simple_c_path.dir/objects1.rsp
lib/libsimple_c_path.dll: simple_c_path/CMakeFiles/simple_c_path.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\git_test\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C shared library ..\lib\libsimple_c_path.dll"
	cd /d D:\git_test\build\simple_c_path && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\simple_c_path.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
simple_c_path/CMakeFiles/simple_c_path.dir/build: lib/libsimple_c_path.dll

.PHONY : simple_c_path/CMakeFiles/simple_c_path.dir/build

simple_c_path/CMakeFiles/simple_c_path.dir/clean:
	cd /d D:\git_test\build\simple_c_path && $(CMAKE_COMMAND) -P CMakeFiles\simple_c_path.dir\cmake_clean.cmake
.PHONY : simple_c_path/CMakeFiles/simple_c_path.dir/clean

simple_c_path/CMakeFiles/simple_c_path.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\git_test D:\git_test\simple_c_path D:\git_test\build D:\git_test\build\simple_c_path D:\git_test\build\simple_c_path\CMakeFiles\simple_c_path.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : simple_c_path/CMakeFiles/simple_c_path.dir/depend
