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
CMAKE_COMMAND = "/Users/gustavo/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/183.4284.156/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/gustavo/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/183.4284.156/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/gustavo/Documents/workspace/udesc/comp/TrabalhoCOMP

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/gustavo/Documents/workspace/udesc/comp/TrabalhoCOMP/cmake-build-release

# Include any dependencies generated for this target.
include CMakeFiles/main.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main.dir/flags.make

../gram.tab.c:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/gustavo/Documents/workspace/udesc/comp/TrabalhoCOMP/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "BISON: Criando gram.tab.c"
	/usr/bin/bison -d --output=/Users/gustavo/Documents/workspace/udesc/comp/TrabalhoCOMP/gram.tab.c /Users/gustavo/Documents/workspace/udesc/comp/TrabalhoCOMP/gram.y

CMakeFiles/main.dir/Initializers.c.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/Initializers.c.o: ../Initializers.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gustavo/Documents/workspace/udesc/comp/TrabalhoCOMP/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/main.dir/Initializers.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/main.dir/Initializers.c.o   -c /Users/gustavo/Documents/workspace/udesc/comp/TrabalhoCOMP/Initializers.c

CMakeFiles/main.dir/Initializers.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main.dir/Initializers.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/gustavo/Documents/workspace/udesc/comp/TrabalhoCOMP/Initializers.c > CMakeFiles/main.dir/Initializers.c.i

CMakeFiles/main.dir/Initializers.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main.dir/Initializers.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/gustavo/Documents/workspace/udesc/comp/TrabalhoCOMP/Initializers.c -o CMakeFiles/main.dir/Initializers.c.s

CMakeFiles/main.dir/Boolean.c.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/Boolean.c.o: ../Boolean.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gustavo/Documents/workspace/udesc/comp/TrabalhoCOMP/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/main.dir/Boolean.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/main.dir/Boolean.c.o   -c /Users/gustavo/Documents/workspace/udesc/comp/TrabalhoCOMP/Boolean.c

CMakeFiles/main.dir/Boolean.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main.dir/Boolean.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/gustavo/Documents/workspace/udesc/comp/TrabalhoCOMP/Boolean.c > CMakeFiles/main.dir/Boolean.c.i

CMakeFiles/main.dir/Boolean.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main.dir/Boolean.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/gustavo/Documents/workspace/udesc/comp/TrabalhoCOMP/Boolean.c -o CMakeFiles/main.dir/Boolean.c.s

CMakeFiles/main.dir/Helpers.c.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/Helpers.c.o: ../Helpers.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gustavo/Documents/workspace/udesc/comp/TrabalhoCOMP/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/main.dir/Helpers.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/main.dir/Helpers.c.o   -c /Users/gustavo/Documents/workspace/udesc/comp/TrabalhoCOMP/Helpers.c

CMakeFiles/main.dir/Helpers.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main.dir/Helpers.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/gustavo/Documents/workspace/udesc/comp/TrabalhoCOMP/Helpers.c > CMakeFiles/main.dir/Helpers.c.i

CMakeFiles/main.dir/Helpers.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main.dir/Helpers.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/gustavo/Documents/workspace/udesc/comp/TrabalhoCOMP/Helpers.c -o CMakeFiles/main.dir/Helpers.c.s

CMakeFiles/main.dir/gram.c.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/gram.c.o: ../gram.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gustavo/Documents/workspace/udesc/comp/TrabalhoCOMP/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/main.dir/gram.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/main.dir/gram.c.o   -c /Users/gustavo/Documents/workspace/udesc/comp/TrabalhoCOMP/gram.c

CMakeFiles/main.dir/gram.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main.dir/gram.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/gustavo/Documents/workspace/udesc/comp/TrabalhoCOMP/gram.c > CMakeFiles/main.dir/gram.c.i

CMakeFiles/main.dir/gram.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main.dir/gram.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/gustavo/Documents/workspace/udesc/comp/TrabalhoCOMP/gram.c -o CMakeFiles/main.dir/gram.c.s

CMakeFiles/main.dir/gram.tab.c.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/gram.tab.c.o: ../gram.tab.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gustavo/Documents/workspace/udesc/comp/TrabalhoCOMP/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/main.dir/gram.tab.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/main.dir/gram.tab.c.o   -c /Users/gustavo/Documents/workspace/udesc/comp/TrabalhoCOMP/gram.tab.c

CMakeFiles/main.dir/gram.tab.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main.dir/gram.tab.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/gustavo/Documents/workspace/udesc/comp/TrabalhoCOMP/gram.tab.c > CMakeFiles/main.dir/gram.tab.c.i

CMakeFiles/main.dir/gram.tab.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main.dir/gram.tab.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/gustavo/Documents/workspace/udesc/comp/TrabalhoCOMP/gram.tab.c -o CMakeFiles/main.dir/gram.tab.c.s

# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/Initializers.c.o" \
"CMakeFiles/main.dir/Boolean.c.o" \
"CMakeFiles/main.dir/Helpers.c.o" \
"CMakeFiles/main.dir/gram.c.o" \
"CMakeFiles/main.dir/gram.tab.c.o"

# External object files for target main
main_EXTERNAL_OBJECTS =

main: CMakeFiles/main.dir/Initializers.c.o
main: CMakeFiles/main.dir/Boolean.c.o
main: CMakeFiles/main.dir/Helpers.c.o
main: CMakeFiles/main.dir/gram.c.o
main: CMakeFiles/main.dir/gram.tab.c.o
main: CMakeFiles/main.dir/build.make
main: CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/gustavo/Documents/workspace/udesc/comp/TrabalhoCOMP/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking C executable main"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main.dir/build: main

.PHONY : CMakeFiles/main.dir/build

CMakeFiles/main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main.dir/clean

CMakeFiles/main.dir/depend: ../gram.tab.c
	cd /Users/gustavo/Documents/workspace/udesc/comp/TrabalhoCOMP/cmake-build-release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/gustavo/Documents/workspace/udesc/comp/TrabalhoCOMP /Users/gustavo/Documents/workspace/udesc/comp/TrabalhoCOMP /Users/gustavo/Documents/workspace/udesc/comp/TrabalhoCOMP/cmake-build-release /Users/gustavo/Documents/workspace/udesc/comp/TrabalhoCOMP/cmake-build-release /Users/gustavo/Documents/workspace/udesc/comp/TrabalhoCOMP/cmake-build-release/CMakeFiles/main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/main.dir/depend

