# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.22

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Programmes\CLion 2021.3.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Programmes\CLion 2021.3.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Projects\ClionProjects\sfml

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Projects\ClionProjects\sfml\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/sfml.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/sfml.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/sfml.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sfml.dir/flags.make

CMakeFiles/sfml.dir/main.cpp.obj: CMakeFiles/sfml.dir/flags.make
CMakeFiles/sfml.dir/main.cpp.obj: CMakeFiles/sfml.dir/includes_CXX.rsp
CMakeFiles/sfml.dir/main.cpp.obj: ../main.cpp
CMakeFiles/sfml.dir/main.cpp.obj: CMakeFiles/sfml.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Projects\ClionProjects\sfml\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sfml.dir/main.cpp.obj"
	D:\Programmes\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sfml.dir/main.cpp.obj -MF CMakeFiles\sfml.dir\main.cpp.obj.d -o CMakeFiles\sfml.dir\main.cpp.obj -c D:\Projects\ClionProjects\sfml\main.cpp

CMakeFiles/sfml.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfml.dir/main.cpp.i"
	D:\Programmes\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Projects\ClionProjects\sfml\main.cpp > CMakeFiles\sfml.dir\main.cpp.i

CMakeFiles/sfml.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfml.dir/main.cpp.s"
	D:\Programmes\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Projects\ClionProjects\sfml\main.cpp -o CMakeFiles\sfml.dir\main.cpp.s

CMakeFiles/sfml.dir/Button.cpp.obj: CMakeFiles/sfml.dir/flags.make
CMakeFiles/sfml.dir/Button.cpp.obj: CMakeFiles/sfml.dir/includes_CXX.rsp
CMakeFiles/sfml.dir/Button.cpp.obj: ../Button.cpp
CMakeFiles/sfml.dir/Button.cpp.obj: CMakeFiles/sfml.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Projects\ClionProjects\sfml\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/sfml.dir/Button.cpp.obj"
	D:\Programmes\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sfml.dir/Button.cpp.obj -MF CMakeFiles\sfml.dir\Button.cpp.obj.d -o CMakeFiles\sfml.dir\Button.cpp.obj -c D:\Projects\ClionProjects\sfml\Button.cpp

CMakeFiles/sfml.dir/Button.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfml.dir/Button.cpp.i"
	D:\Programmes\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Projects\ClionProjects\sfml\Button.cpp > CMakeFiles\sfml.dir\Button.cpp.i

CMakeFiles/sfml.dir/Button.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfml.dir/Button.cpp.s"
	D:\Programmes\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Projects\ClionProjects\sfml\Button.cpp -o CMakeFiles\sfml.dir\Button.cpp.s

CMakeFiles/sfml.dir/Scroll.cpp.obj: CMakeFiles/sfml.dir/flags.make
CMakeFiles/sfml.dir/Scroll.cpp.obj: CMakeFiles/sfml.dir/includes_CXX.rsp
CMakeFiles/sfml.dir/Scroll.cpp.obj: ../Scroll.cpp
CMakeFiles/sfml.dir/Scroll.cpp.obj: CMakeFiles/sfml.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Projects\ClionProjects\sfml\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/sfml.dir/Scroll.cpp.obj"
	D:\Programmes\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sfml.dir/Scroll.cpp.obj -MF CMakeFiles\sfml.dir\Scroll.cpp.obj.d -o CMakeFiles\sfml.dir\Scroll.cpp.obj -c D:\Projects\ClionProjects\sfml\Scroll.cpp

CMakeFiles/sfml.dir/Scroll.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfml.dir/Scroll.cpp.i"
	D:\Programmes\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Projects\ClionProjects\sfml\Scroll.cpp > CMakeFiles\sfml.dir\Scroll.cpp.i

CMakeFiles/sfml.dir/Scroll.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfml.dir/Scroll.cpp.s"
	D:\Programmes\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Projects\ClionProjects\sfml\Scroll.cpp -o CMakeFiles\sfml.dir\Scroll.cpp.s

CMakeFiles/sfml.dir/Game.cpp.obj: CMakeFiles/sfml.dir/flags.make
CMakeFiles/sfml.dir/Game.cpp.obj: CMakeFiles/sfml.dir/includes_CXX.rsp
CMakeFiles/sfml.dir/Game.cpp.obj: ../Game.cpp
CMakeFiles/sfml.dir/Game.cpp.obj: CMakeFiles/sfml.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Projects\ClionProjects\sfml\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/sfml.dir/Game.cpp.obj"
	D:\Programmes\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sfml.dir/Game.cpp.obj -MF CMakeFiles\sfml.dir\Game.cpp.obj.d -o CMakeFiles\sfml.dir\Game.cpp.obj -c D:\Projects\ClionProjects\sfml\Game.cpp

CMakeFiles/sfml.dir/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfml.dir/Game.cpp.i"
	D:\Programmes\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Projects\ClionProjects\sfml\Game.cpp > CMakeFiles\sfml.dir\Game.cpp.i

CMakeFiles/sfml.dir/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfml.dir/Game.cpp.s"
	D:\Programmes\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Projects\ClionProjects\sfml\Game.cpp -o CMakeFiles\sfml.dir\Game.cpp.s

CMakeFiles/sfml.dir/GameState.cpp.obj: CMakeFiles/sfml.dir/flags.make
CMakeFiles/sfml.dir/GameState.cpp.obj: CMakeFiles/sfml.dir/includes_CXX.rsp
CMakeFiles/sfml.dir/GameState.cpp.obj: ../GameState.cpp
CMakeFiles/sfml.dir/GameState.cpp.obj: CMakeFiles/sfml.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Projects\ClionProjects\sfml\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/sfml.dir/GameState.cpp.obj"
	D:\Programmes\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sfml.dir/GameState.cpp.obj -MF CMakeFiles\sfml.dir\GameState.cpp.obj.d -o CMakeFiles\sfml.dir\GameState.cpp.obj -c D:\Projects\ClionProjects\sfml\GameState.cpp

CMakeFiles/sfml.dir/GameState.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfml.dir/GameState.cpp.i"
	D:\Programmes\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Projects\ClionProjects\sfml\GameState.cpp > CMakeFiles\sfml.dir\GameState.cpp.i

CMakeFiles/sfml.dir/GameState.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfml.dir/GameState.cpp.s"
	D:\Programmes\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Projects\ClionProjects\sfml\GameState.cpp -o CMakeFiles\sfml.dir\GameState.cpp.s

# Object files for target sfml
sfml_OBJECTS = \
"CMakeFiles/sfml.dir/main.cpp.obj" \
"CMakeFiles/sfml.dir/Button.cpp.obj" \
"CMakeFiles/sfml.dir/Scroll.cpp.obj" \
"CMakeFiles/sfml.dir/Game.cpp.obj" \
"CMakeFiles/sfml.dir/GameState.cpp.obj"

# External object files for target sfml
sfml_EXTERNAL_OBJECTS =

sfml.exe: CMakeFiles/sfml.dir/main.cpp.obj
sfml.exe: CMakeFiles/sfml.dir/Button.cpp.obj
sfml.exe: CMakeFiles/sfml.dir/Scroll.cpp.obj
sfml.exe: CMakeFiles/sfml.dir/Game.cpp.obj
sfml.exe: CMakeFiles/sfml.dir/GameState.cpp.obj
sfml.exe: CMakeFiles/sfml.dir/build.make
sfml.exe: D:/Programmes/SFML/lib/libsfml-graphics-s-d.a
sfml.exe: D:/Programmes/SFML/lib/libsfml-window-s-d.a
sfml.exe: D:/Programmes/SFML/lib/libsfml-system-s-d.a
sfml.exe: D:/Programmes/SFML/lib/libfreetype.a
sfml.exe: CMakeFiles/sfml.dir/linklibs.rsp
sfml.exe: CMakeFiles/sfml.dir/objects1.rsp
sfml.exe: CMakeFiles/sfml.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Projects\ClionProjects\sfml\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable sfml.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\sfml.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sfml.dir/build: sfml.exe
.PHONY : CMakeFiles/sfml.dir/build

CMakeFiles/sfml.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\sfml.dir\cmake_clean.cmake
.PHONY : CMakeFiles/sfml.dir/clean

CMakeFiles/sfml.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Projects\ClionProjects\sfml D:\Projects\ClionProjects\sfml D:\Projects\ClionProjects\sfml\cmake-build-debug D:\Projects\ClionProjects\sfml\cmake-build-debug D:\Projects\ClionProjects\sfml\cmake-build-debug\CMakeFiles\sfml.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sfml.dir/depend

