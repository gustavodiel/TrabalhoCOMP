# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = "/Users/gustavo/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/182.4892.24/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/gustavo/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/182.4892.24/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/gustavo/Documents/workspace/udesc/comp/TrabalhoCOMP

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/gustavo/Documents/workspace/udesc/comp/TrabalhoCOMP/cmake-build-relwithdebinfo

# Utility rule file for run.

# Include the progress variables for this target.
include CMakeFiles/run.dir/progress.make

CMakeFiles/run: ../expr.tab.c


../expr.tab.c:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/gustavo/Documents/workspace/udesc/comp/TrabalhoCOMP/cmake-build-relwithdebinfo/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Criando expr.tab.c"
	/usr/bin/bison -d --output=/Users/gustavo/Documents/workspace/udesc/comp/TrabalhoCOMP/expr.tab.c /Users/gustavo/Documents/workspace/udesc/comp/TrabalhoCOMP/expr.y

run: CMakeFiles/run
run: ../expr.tab.c
run: CMakeFiles/run.dir/build.make

.PHONY : run

# Rule to build all files generated by this target.
CMakeFiles/run.dir/build: run

.PHONY : CMakeFiles/run.dir/build

CMakeFiles/run.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/run.dir/cmake_clean.cmake
.PHONY : CMakeFiles/run.dir/clean

CMakeFiles/run.dir/depend:
	cd /Users/gustavo/Documents/workspace/udesc/comp/TrabalhoCOMP/cmake-build-relwithdebinfo && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/gustavo/Documents/workspace/udesc/comp/TrabalhoCOMP /Users/gustavo/Documents/workspace/udesc/comp/TrabalhoCOMP /Users/gustavo/Documents/workspace/udesc/comp/TrabalhoCOMP/cmake-build-relwithdebinfo /Users/gustavo/Documents/workspace/udesc/comp/TrabalhoCOMP/cmake-build-relwithdebinfo /Users/gustavo/Documents/workspace/udesc/comp/TrabalhoCOMP/cmake-build-relwithdebinfo/CMakeFiles/run.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/run.dir/depend

