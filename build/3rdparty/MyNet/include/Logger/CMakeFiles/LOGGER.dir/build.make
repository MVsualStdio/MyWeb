# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/ubuntu/MyWeb

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ubuntu/MyWeb/build

# Include any dependencies generated for this target.
include 3rdparty/MyNet/include/Logger/CMakeFiles/LOGGER.dir/depend.make

# Include the progress variables for this target.
include 3rdparty/MyNet/include/Logger/CMakeFiles/LOGGER.dir/progress.make

# Include the compile flags for this target's objects.
include 3rdparty/MyNet/include/Logger/CMakeFiles/LOGGER.dir/flags.make

3rdparty/MyNet/include/Logger/CMakeFiles/LOGGER.dir/Logger.cc.o: 3rdparty/MyNet/include/Logger/CMakeFiles/LOGGER.dir/flags.make
3rdparty/MyNet/include/Logger/CMakeFiles/LOGGER.dir/Logger.cc.o: ../3rdparty/MyNet/include/Logger/Logger.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/MyWeb/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object 3rdparty/MyNet/include/Logger/CMakeFiles/LOGGER.dir/Logger.cc.o"
	cd /home/ubuntu/MyWeb/build/3rdparty/MyNet/include/Logger && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LOGGER.dir/Logger.cc.o -c /home/ubuntu/MyWeb/3rdparty/MyNet/include/Logger/Logger.cc

3rdparty/MyNet/include/Logger/CMakeFiles/LOGGER.dir/Logger.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LOGGER.dir/Logger.cc.i"
	cd /home/ubuntu/MyWeb/build/3rdparty/MyNet/include/Logger && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/MyWeb/3rdparty/MyNet/include/Logger/Logger.cc > CMakeFiles/LOGGER.dir/Logger.cc.i

3rdparty/MyNet/include/Logger/CMakeFiles/LOGGER.dir/Logger.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LOGGER.dir/Logger.cc.s"
	cd /home/ubuntu/MyWeb/build/3rdparty/MyNet/include/Logger && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/MyWeb/3rdparty/MyNet/include/Logger/Logger.cc -o CMakeFiles/LOGGER.dir/Logger.cc.s

3rdparty/MyNet/include/Logger/CMakeFiles/LOGGER.dir/LoggerStream.cc.o: 3rdparty/MyNet/include/Logger/CMakeFiles/LOGGER.dir/flags.make
3rdparty/MyNet/include/Logger/CMakeFiles/LOGGER.dir/LoggerStream.cc.o: ../3rdparty/MyNet/include/Logger/LoggerStream.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/MyWeb/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object 3rdparty/MyNet/include/Logger/CMakeFiles/LOGGER.dir/LoggerStream.cc.o"
	cd /home/ubuntu/MyWeb/build/3rdparty/MyNet/include/Logger && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LOGGER.dir/LoggerStream.cc.o -c /home/ubuntu/MyWeb/3rdparty/MyNet/include/Logger/LoggerStream.cc

3rdparty/MyNet/include/Logger/CMakeFiles/LOGGER.dir/LoggerStream.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LOGGER.dir/LoggerStream.cc.i"
	cd /home/ubuntu/MyWeb/build/3rdparty/MyNet/include/Logger && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/MyWeb/3rdparty/MyNet/include/Logger/LoggerStream.cc > CMakeFiles/LOGGER.dir/LoggerStream.cc.i

3rdparty/MyNet/include/Logger/CMakeFiles/LOGGER.dir/LoggerStream.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LOGGER.dir/LoggerStream.cc.s"
	cd /home/ubuntu/MyWeb/build/3rdparty/MyNet/include/Logger && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/MyWeb/3rdparty/MyNet/include/Logger/LoggerStream.cc -o CMakeFiles/LOGGER.dir/LoggerStream.cc.s

# Object files for target LOGGER
LOGGER_OBJECTS = \
"CMakeFiles/LOGGER.dir/Logger.cc.o" \
"CMakeFiles/LOGGER.dir/LoggerStream.cc.o"

# External object files for target LOGGER
LOGGER_EXTERNAL_OBJECTS =

3rdparty/MyNet/include/Logger/libLOGGER.a: 3rdparty/MyNet/include/Logger/CMakeFiles/LOGGER.dir/Logger.cc.o
3rdparty/MyNet/include/Logger/libLOGGER.a: 3rdparty/MyNet/include/Logger/CMakeFiles/LOGGER.dir/LoggerStream.cc.o
3rdparty/MyNet/include/Logger/libLOGGER.a: 3rdparty/MyNet/include/Logger/CMakeFiles/LOGGER.dir/build.make
3rdparty/MyNet/include/Logger/libLOGGER.a: 3rdparty/MyNet/include/Logger/CMakeFiles/LOGGER.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/MyWeb/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libLOGGER.a"
	cd /home/ubuntu/MyWeb/build/3rdparty/MyNet/include/Logger && $(CMAKE_COMMAND) -P CMakeFiles/LOGGER.dir/cmake_clean_target.cmake
	cd /home/ubuntu/MyWeb/build/3rdparty/MyNet/include/Logger && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LOGGER.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
3rdparty/MyNet/include/Logger/CMakeFiles/LOGGER.dir/build: 3rdparty/MyNet/include/Logger/libLOGGER.a

.PHONY : 3rdparty/MyNet/include/Logger/CMakeFiles/LOGGER.dir/build

3rdparty/MyNet/include/Logger/CMakeFiles/LOGGER.dir/clean:
	cd /home/ubuntu/MyWeb/build/3rdparty/MyNet/include/Logger && $(CMAKE_COMMAND) -P CMakeFiles/LOGGER.dir/cmake_clean.cmake
.PHONY : 3rdparty/MyNet/include/Logger/CMakeFiles/LOGGER.dir/clean

3rdparty/MyNet/include/Logger/CMakeFiles/LOGGER.dir/depend:
	cd /home/ubuntu/MyWeb/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/MyWeb /home/ubuntu/MyWeb/3rdparty/MyNet/include/Logger /home/ubuntu/MyWeb/build /home/ubuntu/MyWeb/build/3rdparty/MyNet/include/Logger /home/ubuntu/MyWeb/build/3rdparty/MyNet/include/Logger/CMakeFiles/LOGGER.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : 3rdparty/MyNet/include/Logger/CMakeFiles/LOGGER.dir/depend

