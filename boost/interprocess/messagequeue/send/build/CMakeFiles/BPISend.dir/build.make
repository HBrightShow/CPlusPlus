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
CMAKE_SOURCE_DIR = /home/uos/hml/cplusplus/boost/interprocess/send

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/uos/hml/cplusplus/boost/interprocess/send/build

# Include any dependencies generated for this target.
include CMakeFiles/BPISend.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/BPISend.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BPISend.dir/flags.make

CMakeFiles/BPISend.dir/main.cpp.o: CMakeFiles/BPISend.dir/flags.make
CMakeFiles/BPISend.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/uos/hml/cplusplus/boost/interprocess/send/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/BPISend.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BPISend.dir/main.cpp.o -c /home/uos/hml/cplusplus/boost/interprocess/send/main.cpp

CMakeFiles/BPISend.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BPISend.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/uos/hml/cplusplus/boost/interprocess/send/main.cpp > CMakeFiles/BPISend.dir/main.cpp.i

CMakeFiles/BPISend.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BPISend.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/uos/hml/cplusplus/boost/interprocess/send/main.cpp -o CMakeFiles/BPISend.dir/main.cpp.s

CMakeFiles/BPISend.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/BPISend.dir/main.cpp.o.requires

CMakeFiles/BPISend.dir/main.cpp.o.provides: CMakeFiles/BPISend.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/BPISend.dir/build.make CMakeFiles/BPISend.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/BPISend.dir/main.cpp.o.provides

CMakeFiles/BPISend.dir/main.cpp.o.provides.build: CMakeFiles/BPISend.dir/main.cpp.o


# Object files for target BPISend
BPISend_OBJECTS = \
"CMakeFiles/BPISend.dir/main.cpp.o"

# External object files for target BPISend
BPISend_EXTERNAL_OBJECTS =

BPISend: CMakeFiles/BPISend.dir/main.cpp.o
BPISend: CMakeFiles/BPISend.dir/build.make
BPISend: CMakeFiles/BPISend.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/uos/hml/cplusplus/boost/interprocess/send/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable BPISend"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/BPISend.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BPISend.dir/build: BPISend

.PHONY : CMakeFiles/BPISend.dir/build

CMakeFiles/BPISend.dir/requires: CMakeFiles/BPISend.dir/main.cpp.o.requires

.PHONY : CMakeFiles/BPISend.dir/requires

CMakeFiles/BPISend.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/BPISend.dir/cmake_clean.cmake
.PHONY : CMakeFiles/BPISend.dir/clean

CMakeFiles/BPISend.dir/depend:
	cd /home/uos/hml/cplusplus/boost/interprocess/send/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/uos/hml/cplusplus/boost/interprocess/send /home/uos/hml/cplusplus/boost/interprocess/send /home/uos/hml/cplusplus/boost/interprocess/send/build /home/uos/hml/cplusplus/boost/interprocess/send/build /home/uos/hml/cplusplus/boost/interprocess/send/build/CMakeFiles/BPISend.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/BPISend.dir/depend

