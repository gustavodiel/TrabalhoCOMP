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
CMAKE_BINARY_DIR = /Users/gustavo/Documents/workspace/udesc/comp/TrabalhoCOMP/cmake-build-minsizerel

# Include any dependencies generated for this target.
include CMakeFiles/TrabalhoFinal.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TrabalhoFinal.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TrabalhoFinal.dir/flags.make

../expr.tab.c:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/gustavo/Documents/workspace/udesc/comp/TrabalhoCOMP/cmake-build-minsizerel/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "BISON: Criando expr.tab.c"
	/usr/bin/bison -d --output=/Users/gustavo/Documents/workspace/udesc/comp/TrabalhoCOMP/expr.tab.c /Users/gustavo/Documents/workspace/udesc/comp/TrabalhoCOMP/expr.y

../lex.yy.c:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/gustavo/Documents/workspace/udesc/comp/TrabalhoCOMP/cmake-build-minsizerel/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "FLEX: Criando lex.yy.c"
	/usr/bin/flex --outfile=/Users/gustavo/Documents/workspace/udesc/comp/TrabalhoCOMP/lex.yy.c /Users/gustavo/Documents/workspace/udesc/comp/TrabalhoCOMP/expr.l

CMakeFiles/TrabalhoFinal.dir/expr.tab.c.o: CMakeFiles/TrabalhoFinal.dir/flags.make
CMakeFiles/TrabalhoFinal.dir/expr.tab.c.o: ../expr.tab.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gustavo/Documents/workspace/udesc/comp/TrabalhoCOMP/cmake-build-minsizerel/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/TrabalhoFinal.dir/expr.tab.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/TrabalhoFinal.dir/expr.tab.c.o   -c /Users/gustavo/Documents/workspace/udesc/comp/TrabalhoCOMP/expr.tab.c

CMakeFiles/TrabalhoFinal.dir/expr.tab.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TrabalhoFinal.dir/expr.tab.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/gustavo/Documents/workspace/udesc/comp/TrabalhoCOMP/expr.tab.c > CMakeFiles/TrabalhoFinal.dir/expr.tab.c.i

CMakeFiles/TrabalhoFinal.dir/expr.tab.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TrabalhoFinal.dir/expr.tab.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/gustavo/Documents/workspace/udesc/comp/TrabalhoCOMP/expr.tab.c -o CMakeFiles/TrabalhoFinal.dir/expr.tab.c.s

CMakeFiles/TrabalhoFinal.dir/lex.yy.c.o: CMakeFiles/TrabalhoFinal.dir/flags.make
CMakeFiles/TrabalhoFinal.dir/lex.yy.c.o: ../lex.yy.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gustavo/Documents/workspace/udesc/comp/TrabalhoCOMP/cmake-build-minsizerel/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/TrabalhoFinal.dir/lex.yy.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/TrabalhoFinal.dir/lex.yy.c.o   -c /Users/gustavo/Documents/workspace/udesc/comp/TrabalhoCOMP/lex.yy.c

CMakeFiles/TrabalhoFinal.dir/lex.yy.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TrabalhoFinal.dir/lex.yy.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/gustavo/Documents/workspace/udesc/comp/TrabalhoCOMP/lex.yy.c > CMakeFiles/TrabalhoFinal.dir/lex.yy.c.i

CMakeFiles/TrabalhoFinal.dir/lex.yy.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TrabalhoFinal.dir/lex.yy.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/gustavo/Documents/workspace/udesc/comp/TrabalhoCOMP/lex.yy.c -o CMakeFiles/TrabalhoFinal.dir/lex.yy.c.s

# Object files for target TrabalhoFinal
TrabalhoFinal_OBJECTS = \
"CMakeFiles/TrabalhoFinal.dir/expr.tab.c.o" \
"CMakeFiles/TrabalhoFinal.dir/lex.yy.c.o"

# External object files for target TrabalhoFinal
TrabalhoFinal_EXTERNAL_OBJECTS =

libTrabalhoFinal.a: CMakeFiles/TrabalhoFinal.dir/expr.tab.c.o
libTrabalhoFinal.a: CMakeFiles/TrabalhoFinal.dir/lex.yy.c.o
libTrabalhoFinal.a: CMakeFiles/TrabalhoFinal.dir/build.make
libTrabalhoFinal.a: CMakeFiles/TrabalhoFinal.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/gustavo/Documents/workspace/udesc/comp/TrabalhoCOMP/cmake-build-minsizerel/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C static library libTrabalhoFinal.a"
	$(CMAKE_COMMAND) -P CMakeFiles/TrabalhoFinal.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TrabalhoFinal.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TrabalhoFinal.dir/build: libTrabalhoFinal.a

.PHONY : CMakeFiles/TrabalhoFinal.dir/build

CMakeFiles/TrabalhoFinal.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TrabalhoFinal.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TrabalhoFinal.dir/clean

CMakeFiles/TrabalhoFinal.dir/depend: ../expr.tab.c
CMakeFiles/TrabalhoFinal.dir/depend: ../lex.yy.c
	cd /Users/gustavo/Documents/workspace/udesc/comp/TrabalhoCOMP/cmake-build-minsizerel && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/gustavo/Documents/workspace/udesc/comp/TrabalhoCOMP /Users/gustavo/Documents/workspace/udesc/comp/TrabalhoCOMP /Users/gustavo/Documents/workspace/udesc/comp/TrabalhoCOMP/cmake-build-minsizerel /Users/gustavo/Documents/workspace/udesc/comp/TrabalhoCOMP/cmake-build-minsizerel /Users/gustavo/Documents/workspace/udesc/comp/TrabalhoCOMP/cmake-build-minsizerel/CMakeFiles/TrabalhoFinal.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TrabalhoFinal.dir/depend

