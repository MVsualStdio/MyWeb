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
include CMakeFiles/testResponse.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/testResponse.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/testResponse.dir/flags.make

CMakeFiles/testResponse.dir/test/testResponse.cc.o: CMakeFiles/testResponse.dir/flags.make
CMakeFiles/testResponse.dir/test/testResponse.cc.o: ../test/testResponse.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/MyWeb/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/testResponse.dir/test/testResponse.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/testResponse.dir/test/testResponse.cc.o -c /home/ubuntu/MyWeb/test/testResponse.cc

CMakeFiles/testResponse.dir/test/testResponse.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testResponse.dir/test/testResponse.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/MyWeb/test/testResponse.cc > CMakeFiles/testResponse.dir/test/testResponse.cc.i

CMakeFiles/testResponse.dir/test/testResponse.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testResponse.dir/test/testResponse.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/MyWeb/test/testResponse.cc -o CMakeFiles/testResponse.dir/test/testResponse.cc.s

# Object files for target testResponse
testResponse_OBJECTS = \
"CMakeFiles/testResponse.dir/test/testResponse.cc.o"

# External object files for target testResponse
testResponse_EXTERNAL_OBJECTS =

../testResponse: CMakeFiles/testResponse.dir/test/testResponse.cc.o
../testResponse: CMakeFiles/testResponse.dir/build.make
../testResponse: ../3rdparty/mysql-connector-c++-8.0.31/lib64/libmysqlcppconn8.so
../testResponse: 3rdparty/MyNet/include/Logger/libLOGGER.a
../testResponse: 3rdparty/MyNet/include/ThreadPool/libTHREADPOOL.a
../testResponse: 3rdparty/MyNet/include/Socket/libMYSOCKET.a
../testResponse: 3rdparty/MyNet/include/Buffer/libBUFFER.a
../testResponse: 3rdparty/MyNet/include/Http/libHTTP.a
../testResponse: libWEBLIB.a
../testResponse: 3rdparty/MyNet/include/Socket/libMYSOCKET.a
../testResponse: 3rdparty/MyNet/include/Logger/libLOGGER.a
../testResponse: 3rdparty/MyNet/include/ThreadPool/libTHREADPOOL.a
../testResponse: 3rdparty/MyNet/include/Buffer/libBUFFER.a
../testResponse: ../3rdparty/mysql-connector-c++-8.0.31/lib64/libmysqlcppconn8.so
../testResponse: CMakeFiles/testResponse.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/MyWeb/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../testResponse"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testResponse.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/testResponse.dir/build: ../testResponse

.PHONY : CMakeFiles/testResponse.dir/build

CMakeFiles/testResponse.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/testResponse.dir/cmake_clean.cmake
.PHONY : CMakeFiles/testResponse.dir/clean

CMakeFiles/testResponse.dir/depend:
	cd /home/ubuntu/MyWeb/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/MyWeb /home/ubuntu/MyWeb /home/ubuntu/MyWeb/build /home/ubuntu/MyWeb/build /home/ubuntu/MyWeb/build/CMakeFiles/testResponse.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/testResponse.dir/depend

