# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

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
CMAKE_COMMAND = /home/book/apps/cmake-3.24.0-linux-x86_64/bin/cmake

# The command to remove a file.
RM = /home/book/apps/cmake-3.24.0-linux-x86_64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /tmp/tmp.EOQTpyeBN6

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /tmp/tmp.EOQTpyeBN6/cmake-build-debug-remote-host

# Include any dependencies generated for this target.
include CMakeFiles/CPPThreadPool.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/CPPThreadPool.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/CPPThreadPool.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CPPThreadPool.dir/flags.make

CMakeFiles/CPPThreadPool.dir/Src/main.cpp.o: CMakeFiles/CPPThreadPool.dir/flags.make
CMakeFiles/CPPThreadPool.dir/Src/main.cpp.o: /tmp/tmp.EOQTpyeBN6/Src/main.cpp
CMakeFiles/CPPThreadPool.dir/Src/main.cpp.o: CMakeFiles/CPPThreadPool.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.EOQTpyeBN6/cmake-build-debug-remote-host/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CPPThreadPool.dir/Src/main.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CPPThreadPool.dir/Src/main.cpp.o -MF CMakeFiles/CPPThreadPool.dir/Src/main.cpp.o.d -o CMakeFiles/CPPThreadPool.dir/Src/main.cpp.o -c /tmp/tmp.EOQTpyeBN6/Src/main.cpp

CMakeFiles/CPPThreadPool.dir/Src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CPPThreadPool.dir/Src/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /tmp/tmp.EOQTpyeBN6/Src/main.cpp > CMakeFiles/CPPThreadPool.dir/Src/main.cpp.i

CMakeFiles/CPPThreadPool.dir/Src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CPPThreadPool.dir/Src/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /tmp/tmp.EOQTpyeBN6/Src/main.cpp -o CMakeFiles/CPPThreadPool.dir/Src/main.cpp.s

CMakeFiles/CPPThreadPool.dir/Src/TaskQueue.cpp.o: CMakeFiles/CPPThreadPool.dir/flags.make
CMakeFiles/CPPThreadPool.dir/Src/TaskQueue.cpp.o: /tmp/tmp.EOQTpyeBN6/Src/TaskQueue.cpp
CMakeFiles/CPPThreadPool.dir/Src/TaskQueue.cpp.o: CMakeFiles/CPPThreadPool.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.EOQTpyeBN6/cmake-build-debug-remote-host/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/CPPThreadPool.dir/Src/TaskQueue.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CPPThreadPool.dir/Src/TaskQueue.cpp.o -MF CMakeFiles/CPPThreadPool.dir/Src/TaskQueue.cpp.o.d -o CMakeFiles/CPPThreadPool.dir/Src/TaskQueue.cpp.o -c /tmp/tmp.EOQTpyeBN6/Src/TaskQueue.cpp

CMakeFiles/CPPThreadPool.dir/Src/TaskQueue.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CPPThreadPool.dir/Src/TaskQueue.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /tmp/tmp.EOQTpyeBN6/Src/TaskQueue.cpp > CMakeFiles/CPPThreadPool.dir/Src/TaskQueue.cpp.i

CMakeFiles/CPPThreadPool.dir/Src/TaskQueue.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CPPThreadPool.dir/Src/TaskQueue.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /tmp/tmp.EOQTpyeBN6/Src/TaskQueue.cpp -o CMakeFiles/CPPThreadPool.dir/Src/TaskQueue.cpp.s

CMakeFiles/CPPThreadPool.dir/Src/ThreadPool.cpp.o: CMakeFiles/CPPThreadPool.dir/flags.make
CMakeFiles/CPPThreadPool.dir/Src/ThreadPool.cpp.o: /tmp/tmp.EOQTpyeBN6/Src/ThreadPool.cpp
CMakeFiles/CPPThreadPool.dir/Src/ThreadPool.cpp.o: CMakeFiles/CPPThreadPool.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.EOQTpyeBN6/cmake-build-debug-remote-host/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/CPPThreadPool.dir/Src/ThreadPool.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CPPThreadPool.dir/Src/ThreadPool.cpp.o -MF CMakeFiles/CPPThreadPool.dir/Src/ThreadPool.cpp.o.d -o CMakeFiles/CPPThreadPool.dir/Src/ThreadPool.cpp.o -c /tmp/tmp.EOQTpyeBN6/Src/ThreadPool.cpp

CMakeFiles/CPPThreadPool.dir/Src/ThreadPool.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CPPThreadPool.dir/Src/ThreadPool.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /tmp/tmp.EOQTpyeBN6/Src/ThreadPool.cpp > CMakeFiles/CPPThreadPool.dir/Src/ThreadPool.cpp.i

CMakeFiles/CPPThreadPool.dir/Src/ThreadPool.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CPPThreadPool.dir/Src/ThreadPool.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /tmp/tmp.EOQTpyeBN6/Src/ThreadPool.cpp -o CMakeFiles/CPPThreadPool.dir/Src/ThreadPool.cpp.s

# Object files for target CPPThreadPool
CPPThreadPool_OBJECTS = \
"CMakeFiles/CPPThreadPool.dir/Src/main.cpp.o" \
"CMakeFiles/CPPThreadPool.dir/Src/TaskQueue.cpp.o" \
"CMakeFiles/CPPThreadPool.dir/Src/ThreadPool.cpp.o"

# External object files for target CPPThreadPool
CPPThreadPool_EXTERNAL_OBJECTS =

CPPThreadPool: CMakeFiles/CPPThreadPool.dir/Src/main.cpp.o
CPPThreadPool: CMakeFiles/CPPThreadPool.dir/Src/TaskQueue.cpp.o
CPPThreadPool: CMakeFiles/CPPThreadPool.dir/Src/ThreadPool.cpp.o
CPPThreadPool: CMakeFiles/CPPThreadPool.dir/build.make
CPPThreadPool: CMakeFiles/CPPThreadPool.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/tmp/tmp.EOQTpyeBN6/cmake-build-debug-remote-host/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable CPPThreadPool"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CPPThreadPool.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CPPThreadPool.dir/build: CPPThreadPool
.PHONY : CMakeFiles/CPPThreadPool.dir/build

CMakeFiles/CPPThreadPool.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CPPThreadPool.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CPPThreadPool.dir/clean

CMakeFiles/CPPThreadPool.dir/depend:
	cd /tmp/tmp.EOQTpyeBN6/cmake-build-debug-remote-host && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /tmp/tmp.EOQTpyeBN6 /tmp/tmp.EOQTpyeBN6 /tmp/tmp.EOQTpyeBN6/cmake-build-debug-remote-host /tmp/tmp.EOQTpyeBN6/cmake-build-debug-remote-host /tmp/tmp.EOQTpyeBN6/cmake-build-debug-remote-host/CMakeFiles/CPPThreadPool.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CPPThreadPool.dir/depend

