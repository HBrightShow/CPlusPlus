# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/uos/hml/cplusplus/boost/signals

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/uos/hml/cplusplus/boost/signals/build

# Include any dependencies generated for this target.
include CMakeFiles/signals.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/signals.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/signals.dir/flags.make

CMakeFiles/signals.dir/main.cpp.o: CMakeFiles/signals.dir/flags.make
CMakeFiles/signals.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/uos/hml/cplusplus/boost/signals/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/signals.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/signals.dir/main.cpp.o -c /home/uos/hml/cplusplus/boost/signals/main.cpp

CMakeFiles/signals.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/signals.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/uos/hml/cplusplus/boost/signals/main.cpp > CMakeFiles/signals.dir/main.cpp.i

CMakeFiles/signals.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/signals.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/uos/hml/cplusplus/boost/signals/main.cpp -o CMakeFiles/signals.dir/main.cpp.s

CMakeFiles/signals.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/signals.dir/main.cpp.o.requires

CMakeFiles/signals.dir/main.cpp.o.provides: CMakeFiles/signals.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/signals.dir/build.make CMakeFiles/signals.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/signals.dir/main.cpp.o.provides

CMakeFiles/signals.dir/main.cpp.o.provides.build: CMakeFiles/signals.dir/main.cpp.o


# Object files for target signals
signals_OBJECTS = \
"CMakeFiles/signals.dir/main.cpp.o"

# External object files for target signals
signals_EXTERNAL_OBJECTS =

signals: CMakeFiles/signals.dir/main.cpp.o
signals: CMakeFiles/signals.dir/build.make
signals: CMakeFiles/signals.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/uos/hml/cplusplus/boost/signals/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable signals"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/signals.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/signals.dir/build: signals

.PHONY : CMakeFiles/signals.dir/build

CMakeFiles/signals.dir/requires: CMakeFiles/signals.dir/main.cpp.o.requires

.PHONY : CMakeFiles/signals.dir/requires

CMakeFiles/signals.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/signals.dir/cmake_clean.cmake
.PHONY : CMakeFiles/signals.dir/clean

CMakeFiles/signals.dir/depend:
	cd /home/uos/hml/cplusplus/boost/signals/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/uos/hml/cplusplus/boost/signals /home/uos/hml/cplusplus/boost/signals /home/uos/hml/cplusplus/boost/signals/build /home/uos/hml/cplusplus/boost/signals/build /home/uos/hml/cplusplus/boost/signals/build/CMakeFiles/signals.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/signals.dir/depend

