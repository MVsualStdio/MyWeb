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
include CMakeFiles/WEBLIB.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/WEBLIB.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/WEBLIB.dir/flags.make

CMakeFiles/WEBLIB.dir/src/Config.cc.o: CMakeFiles/WEBLIB.dir/flags.make
CMakeFiles/WEBLIB.dir/src/Config.cc.o: ../src/Config.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/MyWeb/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/WEBLIB.dir/src/Config.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/WEBLIB.dir/src/Config.cc.o -c /home/ubuntu/MyWeb/src/Config.cc

CMakeFiles/WEBLIB.dir/src/Config.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WEBLIB.dir/src/Config.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/MyWeb/src/Config.cc > CMakeFiles/WEBLIB.dir/src/Config.cc.i

CMakeFiles/WEBLIB.dir/src/Config.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WEBLIB.dir/src/Config.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/MyWeb/src/Config.cc -o CMakeFiles/WEBLIB.dir/src/Config.cc.s

CMakeFiles/WEBLIB.dir/src/MysqlCon.cc.o: CMakeFiles/WEBLIB.dir/flags.make
CMakeFiles/WEBLIB.dir/src/MysqlCon.cc.o: ../src/MysqlCon.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/MyWeb/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/WEBLIB.dir/src/MysqlCon.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/WEBLIB.dir/src/MysqlCon.cc.o -c /home/ubuntu/MyWeb/src/MysqlCon.cc

CMakeFiles/WEBLIB.dir/src/MysqlCon.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WEBLIB.dir/src/MysqlCon.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/MyWeb/src/MysqlCon.cc > CMakeFiles/WEBLIB.dir/src/MysqlCon.cc.i

CMakeFiles/WEBLIB.dir/src/MysqlCon.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WEBLIB.dir/src/MysqlCon.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/MyWeb/src/MysqlCon.cc -o CMakeFiles/WEBLIB.dir/src/MysqlCon.cc.s

CMakeFiles/WEBLIB.dir/src/MysqlPool.cc.o: CMakeFiles/WEBLIB.dir/flags.make
CMakeFiles/WEBLIB.dir/src/MysqlPool.cc.o: ../src/MysqlPool.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/MyWeb/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/WEBLIB.dir/src/MysqlPool.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/WEBLIB.dir/src/MysqlPool.cc.o -c /home/ubuntu/MyWeb/src/MysqlPool.cc

CMakeFiles/WEBLIB.dir/src/MysqlPool.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WEBLIB.dir/src/MysqlPool.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/MyWeb/src/MysqlPool.cc > CMakeFiles/WEBLIB.dir/src/MysqlPool.cc.i

CMakeFiles/WEBLIB.dir/src/MysqlPool.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WEBLIB.dir/src/MysqlPool.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/MyWeb/src/MysqlPool.cc -o CMakeFiles/WEBLIB.dir/src/MysqlPool.cc.s

CMakeFiles/WEBLIB.dir/src/Render.cc.o: CMakeFiles/WEBLIB.dir/flags.make
CMakeFiles/WEBLIB.dir/src/Render.cc.o: ../src/Render.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/MyWeb/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/WEBLIB.dir/src/Render.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/WEBLIB.dir/src/Render.cc.o -c /home/ubuntu/MyWeb/src/Render.cc

CMakeFiles/WEBLIB.dir/src/Render.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WEBLIB.dir/src/Render.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/MyWeb/src/Render.cc > CMakeFiles/WEBLIB.dir/src/Render.cc.i

CMakeFiles/WEBLIB.dir/src/Render.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WEBLIB.dir/src/Render.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/MyWeb/src/Render.cc -o CMakeFiles/WEBLIB.dir/src/Render.cc.s

CMakeFiles/WEBLIB.dir/src/RenderPool.cc.o: CMakeFiles/WEBLIB.dir/flags.make
CMakeFiles/WEBLIB.dir/src/RenderPool.cc.o: ../src/RenderPool.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/MyWeb/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/WEBLIB.dir/src/RenderPool.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/WEBLIB.dir/src/RenderPool.cc.o -c /home/ubuntu/MyWeb/src/RenderPool.cc

CMakeFiles/WEBLIB.dir/src/RenderPool.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WEBLIB.dir/src/RenderPool.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/MyWeb/src/RenderPool.cc > CMakeFiles/WEBLIB.dir/src/RenderPool.cc.i

CMakeFiles/WEBLIB.dir/src/RenderPool.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WEBLIB.dir/src/RenderPool.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/MyWeb/src/RenderPool.cc -o CMakeFiles/WEBLIB.dir/src/RenderPool.cc.s

CMakeFiles/WEBLIB.dir/src/Response.cc.o: CMakeFiles/WEBLIB.dir/flags.make
CMakeFiles/WEBLIB.dir/src/Response.cc.o: ../src/Response.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/MyWeb/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/WEBLIB.dir/src/Response.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/WEBLIB.dir/src/Response.cc.o -c /home/ubuntu/MyWeb/src/Response.cc

CMakeFiles/WEBLIB.dir/src/Response.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WEBLIB.dir/src/Response.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/MyWeb/src/Response.cc > CMakeFiles/WEBLIB.dir/src/Response.cc.i

CMakeFiles/WEBLIB.dir/src/Response.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WEBLIB.dir/src/Response.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/MyWeb/src/Response.cc -o CMakeFiles/WEBLIB.dir/src/Response.cc.s

CMakeFiles/WEBLIB.dir/src/Route.cc.o: CMakeFiles/WEBLIB.dir/flags.make
CMakeFiles/WEBLIB.dir/src/Route.cc.o: ../src/Route.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/MyWeb/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/WEBLIB.dir/src/Route.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/WEBLIB.dir/src/Route.cc.o -c /home/ubuntu/MyWeb/src/Route.cc

CMakeFiles/WEBLIB.dir/src/Route.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WEBLIB.dir/src/Route.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/MyWeb/src/Route.cc > CMakeFiles/WEBLIB.dir/src/Route.cc.i

CMakeFiles/WEBLIB.dir/src/Route.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WEBLIB.dir/src/Route.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/MyWeb/src/Route.cc -o CMakeFiles/WEBLIB.dir/src/Route.cc.s

# Object files for target WEBLIB
WEBLIB_OBJECTS = \
"CMakeFiles/WEBLIB.dir/src/Config.cc.o" \
"CMakeFiles/WEBLIB.dir/src/MysqlCon.cc.o" \
"CMakeFiles/WEBLIB.dir/src/MysqlPool.cc.o" \
"CMakeFiles/WEBLIB.dir/src/Render.cc.o" \
"CMakeFiles/WEBLIB.dir/src/RenderPool.cc.o" \
"CMakeFiles/WEBLIB.dir/src/Response.cc.o" \
"CMakeFiles/WEBLIB.dir/src/Route.cc.o"

# External object files for target WEBLIB
WEBLIB_EXTERNAL_OBJECTS =

libWEBLIB.a: CMakeFiles/WEBLIB.dir/src/Config.cc.o
libWEBLIB.a: CMakeFiles/WEBLIB.dir/src/MysqlCon.cc.o
libWEBLIB.a: CMakeFiles/WEBLIB.dir/src/MysqlPool.cc.o
libWEBLIB.a: CMakeFiles/WEBLIB.dir/src/Render.cc.o
libWEBLIB.a: CMakeFiles/WEBLIB.dir/src/RenderPool.cc.o
libWEBLIB.a: CMakeFiles/WEBLIB.dir/src/Response.cc.o
libWEBLIB.a: CMakeFiles/WEBLIB.dir/src/Route.cc.o
libWEBLIB.a: CMakeFiles/WEBLIB.dir/build.make
libWEBLIB.a: CMakeFiles/WEBLIB.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/MyWeb/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX static library libWEBLIB.a"
	$(CMAKE_COMMAND) -P CMakeFiles/WEBLIB.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/WEBLIB.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/WEBLIB.dir/build: libWEBLIB.a

.PHONY : CMakeFiles/WEBLIB.dir/build

CMakeFiles/WEBLIB.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/WEBLIB.dir/cmake_clean.cmake
.PHONY : CMakeFiles/WEBLIB.dir/clean

CMakeFiles/WEBLIB.dir/depend:
	cd /home/ubuntu/MyWeb/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/MyWeb /home/ubuntu/MyWeb /home/ubuntu/MyWeb/build /home/ubuntu/MyWeb/build /home/ubuntu/MyWeb/build/CMakeFiles/WEBLIB.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/WEBLIB.dir/depend

