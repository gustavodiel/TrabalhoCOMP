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
CMAKE_COMMAND = "/Users/gustavo/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/182.4505.18/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/gustavo/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/182.4505.18/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/gustavo/Documents/workspace/udesc/comp/TrabalhoCOMP

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/gustavo/Documents/workspace/udesc/comp/TrabalhoCOMP/cmake-build-debug

# Utility rule file for clearBisonAndFlex.

# Include the progress variables for this target.
include CMakeFiles/clearBisonAndFlex.dir/progress.make

CMakeFiles/clearBisonAndFlex:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/gustavo/Documents/workspace/udesc/comp/TrabalhoCOMP/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Cleaning Bison and Flex files"
	rm -f /Users/gustavo/Documents/workspace/udesc/comp/TrabalhoCOMP/lex.yy.c /Users/gustavo/Documents/workspace/udesc/comp/TrabalhoCOMP/gram.tab.c

clearBisonAndFlex: CMakeFiles/clearBisonAndFlex
clearBisonAndFlex: CMakeFiles/clearBisonAndFlex.dir/build.make

.PHONY : clearBisonAndFlex

# Rule to build all files generated by this target.
CMakeFiles/clearBisonAndFlex.dir/build: clearBisonAndFlex

.PHONY : CMakeFiles/clearBisonAndFlex.dir/build

CMakeFiles/clearBisonAndFlex.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/clearBisonAndFlex.dir/cmake_clean.cmake
.PHONY : CMakeFiles/clearBisonAndFlex.dir/clean

CMakeFiles/clearBisonAndFlex.dir/depend:
	cd /Users/gustavo/Documents/workspace/udesc/comp/TrabalhoCOMP/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/gustavo/Documents/workspace/udesc/comp/TrabalhoCOMP /Users/gustavo/Documents/workspace/udesc/comp/TrabalhoCOMP /Users/gustavo/Documents/workspace/udesc/comp/TrabalhoCOMP/cmake-build-debug /Users/gustavo/Documents/workspace/udesc/comp/TrabalhoCOMP/cmake-build-debug /Users/gustavo/Documents/workspace/udesc/comp/TrabalhoCOMP/cmake-build-debug/CMakeFiles/clearBisonAndFlex.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/clearBisonAndFlex.dir/depend

