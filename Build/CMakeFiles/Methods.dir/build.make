# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/anessivan/Drives/700Gb/GitProjects/Numeral_Methods/res

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/anessivan/Drives/700Gb/GitProjects/Numeral_Methods/Build

# Include any dependencies generated for this target.
include CMakeFiles/Methods.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Methods.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Methods.dir/flags.make

CMakeFiles/Methods.dir/Methods.cpp.o: CMakeFiles/Methods.dir/flags.make
CMakeFiles/Methods.dir/Methods.cpp.o: /home/anessivan/Drives/700Gb/GitProjects/Numeral_Methods/res/Methods.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/anessivan/Drives/700Gb/GitProjects/Numeral_Methods/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Methods.dir/Methods.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Methods.dir/Methods.cpp.o -c /home/anessivan/Drives/700Gb/GitProjects/Numeral_Methods/res/Methods.cpp

CMakeFiles/Methods.dir/Methods.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Methods.dir/Methods.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anessivan/Drives/700Gb/GitProjects/Numeral_Methods/res/Methods.cpp > CMakeFiles/Methods.dir/Methods.cpp.i

CMakeFiles/Methods.dir/Methods.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Methods.dir/Methods.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anessivan/Drives/700Gb/GitProjects/Numeral_Methods/res/Methods.cpp -o CMakeFiles/Methods.dir/Methods.cpp.s

# Object files for target Methods
Methods_OBJECTS = \
"CMakeFiles/Methods.dir/Methods.cpp.o"

# External object files for target Methods
Methods_EXTERNAL_OBJECTS =

libMethods.a: CMakeFiles/Methods.dir/Methods.cpp.o
libMethods.a: CMakeFiles/Methods.dir/build.make
libMethods.a: CMakeFiles/Methods.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/anessivan/Drives/700Gb/GitProjects/Numeral_Methods/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libMethods.a"
	$(CMAKE_COMMAND) -P CMakeFiles/Methods.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Methods.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Methods.dir/build: libMethods.a

.PHONY : CMakeFiles/Methods.dir/build

CMakeFiles/Methods.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Methods.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Methods.dir/clean

CMakeFiles/Methods.dir/depend:
	cd /home/anessivan/Drives/700Gb/GitProjects/Numeral_Methods/Build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/anessivan/Drives/700Gb/GitProjects/Numeral_Methods/res /home/anessivan/Drives/700Gb/GitProjects/Numeral_Methods/res /home/anessivan/Drives/700Gb/GitProjects/Numeral_Methods/Build /home/anessivan/Drives/700Gb/GitProjects/Numeral_Methods/Build /home/anessivan/Drives/700Gb/GitProjects/Numeral_Methods/Build/CMakeFiles/Methods.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Methods.dir/depend

