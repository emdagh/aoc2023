# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/c/Users/EDam/git/aoc2023

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/EDam/git/aoc2023/build

# Include any dependencies generated for this target.
include day2/CMakeFiles/day2.dir/depend.make

# Include the progress variables for this target.
include day2/CMakeFiles/day2.dir/progress.make

# Include the compile flags for this target's objects.
include day2/CMakeFiles/day2.dir/flags.make

day2/CMakeFiles/day2.dir/main.cpp.o: day2/CMakeFiles/day2.dir/flags.make
day2/CMakeFiles/day2.dir/main.cpp.o: ../day2/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/EDam/git/aoc2023/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object day2/CMakeFiles/day2.dir/main.cpp.o"
	cd /mnt/c/Users/EDam/git/aoc2023/build/day2 && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/day2.dir/main.cpp.o -c /mnt/c/Users/EDam/git/aoc2023/day2/main.cpp

day2/CMakeFiles/day2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/day2.dir/main.cpp.i"
	cd /mnt/c/Users/EDam/git/aoc2023/build/day2 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/EDam/git/aoc2023/day2/main.cpp > CMakeFiles/day2.dir/main.cpp.i

day2/CMakeFiles/day2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/day2.dir/main.cpp.s"
	cd /mnt/c/Users/EDam/git/aoc2023/build/day2 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/EDam/git/aoc2023/day2/main.cpp -o CMakeFiles/day2.dir/main.cpp.s

day2/CMakeFiles/day2.dir/main.cpp.o.requires:

.PHONY : day2/CMakeFiles/day2.dir/main.cpp.o.requires

day2/CMakeFiles/day2.dir/main.cpp.o.provides: day2/CMakeFiles/day2.dir/main.cpp.o.requires
	$(MAKE) -f day2/CMakeFiles/day2.dir/build.make day2/CMakeFiles/day2.dir/main.cpp.o.provides.build
.PHONY : day2/CMakeFiles/day2.dir/main.cpp.o.provides

day2/CMakeFiles/day2.dir/main.cpp.o.provides.build: day2/CMakeFiles/day2.dir/main.cpp.o


# Object files for target day2
day2_OBJECTS = \
"CMakeFiles/day2.dir/main.cpp.o"

# External object files for target day2
day2_EXTERNAL_OBJECTS =

day2/day2: day2/CMakeFiles/day2.dir/main.cpp.o
day2/day2: day2/CMakeFiles/day2.dir/build.make
day2/day2: day2/CMakeFiles/day2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/EDam/git/aoc2023/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable day2"
	cd /mnt/c/Users/EDam/git/aoc2023/build/day2 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/day2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
day2/CMakeFiles/day2.dir/build: day2/day2

.PHONY : day2/CMakeFiles/day2.dir/build

day2/CMakeFiles/day2.dir/requires: day2/CMakeFiles/day2.dir/main.cpp.o.requires

.PHONY : day2/CMakeFiles/day2.dir/requires

day2/CMakeFiles/day2.dir/clean:
	cd /mnt/c/Users/EDam/git/aoc2023/build/day2 && $(CMAKE_COMMAND) -P CMakeFiles/day2.dir/cmake_clean.cmake
.PHONY : day2/CMakeFiles/day2.dir/clean

day2/CMakeFiles/day2.dir/depend:
	cd /mnt/c/Users/EDam/git/aoc2023/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/EDam/git/aoc2023 /mnt/c/Users/EDam/git/aoc2023/day2 /mnt/c/Users/EDam/git/aoc2023/build /mnt/c/Users/EDam/git/aoc2023/build/day2 /mnt/c/Users/EDam/git/aoc2023/build/day2/CMakeFiles/day2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : day2/CMakeFiles/day2.dir/depend

