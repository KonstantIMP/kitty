# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_SOURCE_DIR = /home/kimp/Projects/kitty

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kimp/Projects/kitty

# Include any dependencies generated for this target.
include CMakeFiles/kitty.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/kitty.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/kitty.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/kitty.dir/flags.make

CMakeFiles/kitty.dir/src/main.cpp.o: CMakeFiles/kitty.dir/flags.make
CMakeFiles/kitty.dir/src/main.cpp.o: src/main.cpp
CMakeFiles/kitty.dir/src/main.cpp.o: CMakeFiles/kitty.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kimp/Projects/kitty/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/kitty.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/kitty.dir/src/main.cpp.o -MF CMakeFiles/kitty.dir/src/main.cpp.o.d -o CMakeFiles/kitty.dir/src/main.cpp.o -c /home/kimp/Projects/kitty/src/main.cpp

CMakeFiles/kitty.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/kitty.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kimp/Projects/kitty/src/main.cpp > CMakeFiles/kitty.dir/src/main.cpp.i

CMakeFiles/kitty.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/kitty.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kimp/Projects/kitty/src/main.cpp -o CMakeFiles/kitty.dir/src/main.cpp.s

CMakeFiles/kitty.dir/src/password_generator.cpp.o: CMakeFiles/kitty.dir/flags.make
CMakeFiles/kitty.dir/src/password_generator.cpp.o: src/password_generator.cpp
CMakeFiles/kitty.dir/src/password_generator.cpp.o: CMakeFiles/kitty.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kimp/Projects/kitty/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/kitty.dir/src/password_generator.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/kitty.dir/src/password_generator.cpp.o -MF CMakeFiles/kitty.dir/src/password_generator.cpp.o.d -o CMakeFiles/kitty.dir/src/password_generator.cpp.o -c /home/kimp/Projects/kitty/src/password_generator.cpp

CMakeFiles/kitty.dir/src/password_generator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/kitty.dir/src/password_generator.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kimp/Projects/kitty/src/password_generator.cpp > CMakeFiles/kitty.dir/src/password_generator.cpp.i

CMakeFiles/kitty.dir/src/password_generator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/kitty.dir/src/password_generator.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kimp/Projects/kitty/src/password_generator.cpp -o CMakeFiles/kitty.dir/src/password_generator.cpp.s

CMakeFiles/kitty.dir/src/kitty.cpp.o: CMakeFiles/kitty.dir/flags.make
CMakeFiles/kitty.dir/src/kitty.cpp.o: src/kitty.cpp
CMakeFiles/kitty.dir/src/kitty.cpp.o: CMakeFiles/kitty.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kimp/Projects/kitty/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/kitty.dir/src/kitty.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/kitty.dir/src/kitty.cpp.o -MF CMakeFiles/kitty.dir/src/kitty.cpp.o.d -o CMakeFiles/kitty.dir/src/kitty.cpp.o -c /home/kimp/Projects/kitty/src/kitty.cpp

CMakeFiles/kitty.dir/src/kitty.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/kitty.dir/src/kitty.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kimp/Projects/kitty/src/kitty.cpp > CMakeFiles/kitty.dir/src/kitty.cpp.i

CMakeFiles/kitty.dir/src/kitty.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/kitty.dir/src/kitty.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kimp/Projects/kitty/src/kitty.cpp -o CMakeFiles/kitty.dir/src/kitty.cpp.s

# Object files for target kitty
kitty_OBJECTS = \
"CMakeFiles/kitty.dir/src/main.cpp.o" \
"CMakeFiles/kitty.dir/src/password_generator.cpp.o" \
"CMakeFiles/kitty.dir/src/kitty.cpp.o"

# External object files for target kitty
kitty_EXTERNAL_OBJECTS =

kitty: CMakeFiles/kitty.dir/src/main.cpp.o
kitty: CMakeFiles/kitty.dir/src/password_generator.cpp.o
kitty: CMakeFiles/kitty.dir/src/kitty.cpp.o
kitty: CMakeFiles/kitty.dir/build.make
kitty: CMakeFiles/kitty.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kimp/Projects/kitty/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable kitty"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/kitty.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/kitty.dir/build: kitty
.PHONY : CMakeFiles/kitty.dir/build

CMakeFiles/kitty.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/kitty.dir/cmake_clean.cmake
.PHONY : CMakeFiles/kitty.dir/clean

CMakeFiles/kitty.dir/depend:
	cd /home/kimp/Projects/kitty && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kimp/Projects/kitty /home/kimp/Projects/kitty /home/kimp/Projects/kitty /home/kimp/Projects/kitty /home/kimp/Projects/kitty/CMakeFiles/kitty.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/kitty.dir/depend
