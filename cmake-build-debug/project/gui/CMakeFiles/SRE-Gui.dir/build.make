# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Produce verbose output by default.
VERBOSE = 1

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/jonas2.0/MyDocuments/ITU/GP/RenderEngineFork/SimpleRenderEngineProjectFork

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/jonas2.0/MyDocuments/ITU/GP/RenderEngineFork/SimpleRenderEngineProjectFork/cmake-build-debug

# Include any dependencies generated for this target.
include project/gui/CMakeFiles/SRE-Gui.dir/depend.make

# Include the progress variables for this target.
include project/gui/CMakeFiles/SRE-Gui.dir/progress.make

# Include the compile flags for this target's objects.
include project/gui/CMakeFiles/SRE-Gui.dir/flags.make

project/gui/CMakeFiles/SRE-Gui.dir/CameraComponent.cpp.o: project/gui/CMakeFiles/SRE-Gui.dir/flags.make
project/gui/CMakeFiles/SRE-Gui.dir/CameraComponent.cpp.o: ../project/gui/CameraComponent.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jonas2.0/MyDocuments/ITU/GP/RenderEngineFork/SimpleRenderEngineProjectFork/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object project/gui/CMakeFiles/SRE-Gui.dir/CameraComponent.cpp.o"
	cd /Users/jonas2.0/MyDocuments/ITU/GP/RenderEngineFork/SimpleRenderEngineProjectFork/cmake-build-debug/project/gui && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SRE-Gui.dir/CameraComponent.cpp.o -c /Users/jonas2.0/MyDocuments/ITU/GP/RenderEngineFork/SimpleRenderEngineProjectFork/project/gui/CameraComponent.cpp

project/gui/CMakeFiles/SRE-Gui.dir/CameraComponent.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SRE-Gui.dir/CameraComponent.cpp.i"
	cd /Users/jonas2.0/MyDocuments/ITU/GP/RenderEngineFork/SimpleRenderEngineProjectFork/cmake-build-debug/project/gui && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jonas2.0/MyDocuments/ITU/GP/RenderEngineFork/SimpleRenderEngineProjectFork/project/gui/CameraComponent.cpp > CMakeFiles/SRE-Gui.dir/CameraComponent.cpp.i

project/gui/CMakeFiles/SRE-Gui.dir/CameraComponent.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SRE-Gui.dir/CameraComponent.cpp.s"
	cd /Users/jonas2.0/MyDocuments/ITU/GP/RenderEngineFork/SimpleRenderEngineProjectFork/cmake-build-debug/project/gui && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jonas2.0/MyDocuments/ITU/GP/RenderEngineFork/SimpleRenderEngineProjectFork/project/gui/CameraComponent.cpp -o CMakeFiles/SRE-Gui.dir/CameraComponent.cpp.s

project/gui/CMakeFiles/SRE-Gui.dir/Component.cpp.o: project/gui/CMakeFiles/SRE-Gui.dir/flags.make
project/gui/CMakeFiles/SRE-Gui.dir/Component.cpp.o: ../project/gui/Component.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jonas2.0/MyDocuments/ITU/GP/RenderEngineFork/SimpleRenderEngineProjectFork/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object project/gui/CMakeFiles/SRE-Gui.dir/Component.cpp.o"
	cd /Users/jonas2.0/MyDocuments/ITU/GP/RenderEngineFork/SimpleRenderEngineProjectFork/cmake-build-debug/project/gui && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SRE-Gui.dir/Component.cpp.o -c /Users/jonas2.0/MyDocuments/ITU/GP/RenderEngineFork/SimpleRenderEngineProjectFork/project/gui/Component.cpp

project/gui/CMakeFiles/SRE-Gui.dir/Component.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SRE-Gui.dir/Component.cpp.i"
	cd /Users/jonas2.0/MyDocuments/ITU/GP/RenderEngineFork/SimpleRenderEngineProjectFork/cmake-build-debug/project/gui && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jonas2.0/MyDocuments/ITU/GP/RenderEngineFork/SimpleRenderEngineProjectFork/project/gui/Component.cpp > CMakeFiles/SRE-Gui.dir/Component.cpp.i

project/gui/CMakeFiles/SRE-Gui.dir/Component.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SRE-Gui.dir/Component.cpp.s"
	cd /Users/jonas2.0/MyDocuments/ITU/GP/RenderEngineFork/SimpleRenderEngineProjectFork/cmake-build-debug/project/gui && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jonas2.0/MyDocuments/ITU/GP/RenderEngineFork/SimpleRenderEngineProjectFork/project/gui/Component.cpp -o CMakeFiles/SRE-Gui.dir/Component.cpp.s

project/gui/CMakeFiles/SRE-Gui.dir/GameObject.cpp.o: project/gui/CMakeFiles/SRE-Gui.dir/flags.make
project/gui/CMakeFiles/SRE-Gui.dir/GameObject.cpp.o: ../project/gui/GameObject.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jonas2.0/MyDocuments/ITU/GP/RenderEngineFork/SimpleRenderEngineProjectFork/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object project/gui/CMakeFiles/SRE-Gui.dir/GameObject.cpp.o"
	cd /Users/jonas2.0/MyDocuments/ITU/GP/RenderEngineFork/SimpleRenderEngineProjectFork/cmake-build-debug/project/gui && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SRE-Gui.dir/GameObject.cpp.o -c /Users/jonas2.0/MyDocuments/ITU/GP/RenderEngineFork/SimpleRenderEngineProjectFork/project/gui/GameObject.cpp

project/gui/CMakeFiles/SRE-Gui.dir/GameObject.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SRE-Gui.dir/GameObject.cpp.i"
	cd /Users/jonas2.0/MyDocuments/ITU/GP/RenderEngineFork/SimpleRenderEngineProjectFork/cmake-build-debug/project/gui && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jonas2.0/MyDocuments/ITU/GP/RenderEngineFork/SimpleRenderEngineProjectFork/project/gui/GameObject.cpp > CMakeFiles/SRE-Gui.dir/GameObject.cpp.i

project/gui/CMakeFiles/SRE-Gui.dir/GameObject.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SRE-Gui.dir/GameObject.cpp.s"
	cd /Users/jonas2.0/MyDocuments/ITU/GP/RenderEngineFork/SimpleRenderEngineProjectFork/cmake-build-debug/project/gui && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jonas2.0/MyDocuments/ITU/GP/RenderEngineFork/SimpleRenderEngineProjectFork/project/gui/GameObject.cpp -o CMakeFiles/SRE-Gui.dir/GameObject.cpp.s

project/gui/CMakeFiles/SRE-Gui.dir/Hero.cpp.o: project/gui/CMakeFiles/SRE-Gui.dir/flags.make
project/gui/CMakeFiles/SRE-Gui.dir/Hero.cpp.o: ../project/gui/Hero.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jonas2.0/MyDocuments/ITU/GP/RenderEngineFork/SimpleRenderEngineProjectFork/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object project/gui/CMakeFiles/SRE-Gui.dir/Hero.cpp.o"
	cd /Users/jonas2.0/MyDocuments/ITU/GP/RenderEngineFork/SimpleRenderEngineProjectFork/cmake-build-debug/project/gui && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SRE-Gui.dir/Hero.cpp.o -c /Users/jonas2.0/MyDocuments/ITU/GP/RenderEngineFork/SimpleRenderEngineProjectFork/project/gui/Hero.cpp

project/gui/CMakeFiles/SRE-Gui.dir/Hero.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SRE-Gui.dir/Hero.cpp.i"
	cd /Users/jonas2.0/MyDocuments/ITU/GP/RenderEngineFork/SimpleRenderEngineProjectFork/cmake-build-debug/project/gui && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jonas2.0/MyDocuments/ITU/GP/RenderEngineFork/SimpleRenderEngineProjectFork/project/gui/Hero.cpp > CMakeFiles/SRE-Gui.dir/Hero.cpp.i

project/gui/CMakeFiles/SRE-Gui.dir/Hero.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SRE-Gui.dir/Hero.cpp.s"
	cd /Users/jonas2.0/MyDocuments/ITU/GP/RenderEngineFork/SimpleRenderEngineProjectFork/cmake-build-debug/project/gui && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jonas2.0/MyDocuments/ITU/GP/RenderEngineFork/SimpleRenderEngineProjectFork/project/gui/Hero.cpp -o CMakeFiles/SRE-Gui.dir/Hero.cpp.s

project/gui/CMakeFiles/SRE-Gui.dir/MainMenuComponent.cpp.o: project/gui/CMakeFiles/SRE-Gui.dir/flags.make
project/gui/CMakeFiles/SRE-Gui.dir/MainMenuComponent.cpp.o: ../project/gui/MainMenuComponent.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jonas2.0/MyDocuments/ITU/GP/RenderEngineFork/SimpleRenderEngineProjectFork/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object project/gui/CMakeFiles/SRE-Gui.dir/MainMenuComponent.cpp.o"
	cd /Users/jonas2.0/MyDocuments/ITU/GP/RenderEngineFork/SimpleRenderEngineProjectFork/cmake-build-debug/project/gui && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SRE-Gui.dir/MainMenuComponent.cpp.o -c /Users/jonas2.0/MyDocuments/ITU/GP/RenderEngineFork/SimpleRenderEngineProjectFork/project/gui/MainMenuComponent.cpp

project/gui/CMakeFiles/SRE-Gui.dir/MainMenuComponent.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SRE-Gui.dir/MainMenuComponent.cpp.i"
	cd /Users/jonas2.0/MyDocuments/ITU/GP/RenderEngineFork/SimpleRenderEngineProjectFork/cmake-build-debug/project/gui && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jonas2.0/MyDocuments/ITU/GP/RenderEngineFork/SimpleRenderEngineProjectFork/project/gui/MainMenuComponent.cpp > CMakeFiles/SRE-Gui.dir/MainMenuComponent.cpp.i

project/gui/CMakeFiles/SRE-Gui.dir/MainMenuComponent.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SRE-Gui.dir/MainMenuComponent.cpp.s"
	cd /Users/jonas2.0/MyDocuments/ITU/GP/RenderEngineFork/SimpleRenderEngineProjectFork/cmake-build-debug/project/gui && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jonas2.0/MyDocuments/ITU/GP/RenderEngineFork/SimpleRenderEngineProjectFork/project/gui/MainMenuComponent.cpp -o CMakeFiles/SRE-Gui.dir/MainMenuComponent.cpp.s

project/gui/CMakeFiles/SRE-Gui.dir/RPG.cpp.o: project/gui/CMakeFiles/SRE-Gui.dir/flags.make
project/gui/CMakeFiles/SRE-Gui.dir/RPG.cpp.o: ../project/gui/RPG.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jonas2.0/MyDocuments/ITU/GP/RenderEngineFork/SimpleRenderEngineProjectFork/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object project/gui/CMakeFiles/SRE-Gui.dir/RPG.cpp.o"
	cd /Users/jonas2.0/MyDocuments/ITU/GP/RenderEngineFork/SimpleRenderEngineProjectFork/cmake-build-debug/project/gui && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SRE-Gui.dir/RPG.cpp.o -c /Users/jonas2.0/MyDocuments/ITU/GP/RenderEngineFork/SimpleRenderEngineProjectFork/project/gui/RPG.cpp

project/gui/CMakeFiles/SRE-Gui.dir/RPG.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SRE-Gui.dir/RPG.cpp.i"
	cd /Users/jonas2.0/MyDocuments/ITU/GP/RenderEngineFork/SimpleRenderEngineProjectFork/cmake-build-debug/project/gui && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jonas2.0/MyDocuments/ITU/GP/RenderEngineFork/SimpleRenderEngineProjectFork/project/gui/RPG.cpp > CMakeFiles/SRE-Gui.dir/RPG.cpp.i

project/gui/CMakeFiles/SRE-Gui.dir/RPG.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SRE-Gui.dir/RPG.cpp.s"
	cd /Users/jonas2.0/MyDocuments/ITU/GP/RenderEngineFork/SimpleRenderEngineProjectFork/cmake-build-debug/project/gui && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jonas2.0/MyDocuments/ITU/GP/RenderEngineFork/SimpleRenderEngineProjectFork/project/gui/RPG.cpp -o CMakeFiles/SRE-Gui.dir/RPG.cpp.s

project/gui/CMakeFiles/SRE-Gui.dir/Scene.cpp.o: project/gui/CMakeFiles/SRE-Gui.dir/flags.make
project/gui/CMakeFiles/SRE-Gui.dir/Scene.cpp.o: ../project/gui/Scene.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jonas2.0/MyDocuments/ITU/GP/RenderEngineFork/SimpleRenderEngineProjectFork/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object project/gui/CMakeFiles/SRE-Gui.dir/Scene.cpp.o"
	cd /Users/jonas2.0/MyDocuments/ITU/GP/RenderEngineFork/SimpleRenderEngineProjectFork/cmake-build-debug/project/gui && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SRE-Gui.dir/Scene.cpp.o -c /Users/jonas2.0/MyDocuments/ITU/GP/RenderEngineFork/SimpleRenderEngineProjectFork/project/gui/Scene.cpp

project/gui/CMakeFiles/SRE-Gui.dir/Scene.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SRE-Gui.dir/Scene.cpp.i"
	cd /Users/jonas2.0/MyDocuments/ITU/GP/RenderEngineFork/SimpleRenderEngineProjectFork/cmake-build-debug/project/gui && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jonas2.0/MyDocuments/ITU/GP/RenderEngineFork/SimpleRenderEngineProjectFork/project/gui/Scene.cpp > CMakeFiles/SRE-Gui.dir/Scene.cpp.i

project/gui/CMakeFiles/SRE-Gui.dir/Scene.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SRE-Gui.dir/Scene.cpp.s"
	cd /Users/jonas2.0/MyDocuments/ITU/GP/RenderEngineFork/SimpleRenderEngineProjectFork/cmake-build-debug/project/gui && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jonas2.0/MyDocuments/ITU/GP/RenderEngineFork/SimpleRenderEngineProjectFork/project/gui/Scene.cpp -o CMakeFiles/SRE-Gui.dir/Scene.cpp.s

project/gui/CMakeFiles/SRE-Gui.dir/SpriteComponent.cpp.o: project/gui/CMakeFiles/SRE-Gui.dir/flags.make
project/gui/CMakeFiles/SRE-Gui.dir/SpriteComponent.cpp.o: ../project/gui/SpriteComponent.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jonas2.0/MyDocuments/ITU/GP/RenderEngineFork/SimpleRenderEngineProjectFork/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object project/gui/CMakeFiles/SRE-Gui.dir/SpriteComponent.cpp.o"
	cd /Users/jonas2.0/MyDocuments/ITU/GP/RenderEngineFork/SimpleRenderEngineProjectFork/cmake-build-debug/project/gui && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SRE-Gui.dir/SpriteComponent.cpp.o -c /Users/jonas2.0/MyDocuments/ITU/GP/RenderEngineFork/SimpleRenderEngineProjectFork/project/gui/SpriteComponent.cpp

project/gui/CMakeFiles/SRE-Gui.dir/SpriteComponent.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SRE-Gui.dir/SpriteComponent.cpp.i"
	cd /Users/jonas2.0/MyDocuments/ITU/GP/RenderEngineFork/SimpleRenderEngineProjectFork/cmake-build-debug/project/gui && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jonas2.0/MyDocuments/ITU/GP/RenderEngineFork/SimpleRenderEngineProjectFork/project/gui/SpriteComponent.cpp > CMakeFiles/SRE-Gui.dir/SpriteComponent.cpp.i

project/gui/CMakeFiles/SRE-Gui.dir/SpriteComponent.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SRE-Gui.dir/SpriteComponent.cpp.s"
	cd /Users/jonas2.0/MyDocuments/ITU/GP/RenderEngineFork/SimpleRenderEngineProjectFork/cmake-build-debug/project/gui && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jonas2.0/MyDocuments/ITU/GP/RenderEngineFork/SimpleRenderEngineProjectFork/project/gui/SpriteComponent.cpp -o CMakeFiles/SRE-Gui.dir/SpriteComponent.cpp.s

# Object files for target SRE-Gui
SRE__Gui_OBJECTS = \
"CMakeFiles/SRE-Gui.dir/CameraComponent.cpp.o" \
"CMakeFiles/SRE-Gui.dir/Component.cpp.o" \
"CMakeFiles/SRE-Gui.dir/GameObject.cpp.o" \
"CMakeFiles/SRE-Gui.dir/Hero.cpp.o" \
"CMakeFiles/SRE-Gui.dir/MainMenuComponent.cpp.o" \
"CMakeFiles/SRE-Gui.dir/RPG.cpp.o" \
"CMakeFiles/SRE-Gui.dir/Scene.cpp.o" \
"CMakeFiles/SRE-Gui.dir/SpriteComponent.cpp.o"

# External object files for target SRE-Gui
SRE__Gui_EXTERNAL_OBJECTS =

project/gui/SRE-Gui: project/gui/CMakeFiles/SRE-Gui.dir/CameraComponent.cpp.o
project/gui/SRE-Gui: project/gui/CMakeFiles/SRE-Gui.dir/Component.cpp.o
project/gui/SRE-Gui: project/gui/CMakeFiles/SRE-Gui.dir/GameObject.cpp.o
project/gui/SRE-Gui: project/gui/CMakeFiles/SRE-Gui.dir/Hero.cpp.o
project/gui/SRE-Gui: project/gui/CMakeFiles/SRE-Gui.dir/MainMenuComponent.cpp.o
project/gui/SRE-Gui: project/gui/CMakeFiles/SRE-Gui.dir/RPG.cpp.o
project/gui/SRE-Gui: project/gui/CMakeFiles/SRE-Gui.dir/Scene.cpp.o
project/gui/SRE-Gui: project/gui/CMakeFiles/SRE-Gui.dir/SpriteComponent.cpp.o
project/gui/SRE-Gui: project/gui/CMakeFiles/SRE-Gui.dir/build.make
project/gui/SRE-Gui: ../thirdparty/macOS/Lua/lib/liblua.a
project/gui/SRE-Gui: submodules/SimpleRenderEngine/src/libSRE.a
project/gui/SRE-Gui: ../thirdparty/macOS/Box2D/lib/libBox2D.a
project/gui/SRE-Gui: project/gui/CMakeFiles/SRE-Gui.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/jonas2.0/MyDocuments/ITU/GP/RenderEngineFork/SimpleRenderEngineProjectFork/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable SRE-Gui"
	cd /Users/jonas2.0/MyDocuments/ITU/GP/RenderEngineFork/SimpleRenderEngineProjectFork/cmake-build-debug/project/gui && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SRE-Gui.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
project/gui/CMakeFiles/SRE-Gui.dir/build: project/gui/SRE-Gui

.PHONY : project/gui/CMakeFiles/SRE-Gui.dir/build

project/gui/CMakeFiles/SRE-Gui.dir/clean:
	cd /Users/jonas2.0/MyDocuments/ITU/GP/RenderEngineFork/SimpleRenderEngineProjectFork/cmake-build-debug/project/gui && $(CMAKE_COMMAND) -P CMakeFiles/SRE-Gui.dir/cmake_clean.cmake
.PHONY : project/gui/CMakeFiles/SRE-Gui.dir/clean

project/gui/CMakeFiles/SRE-Gui.dir/depend:
	cd /Users/jonas2.0/MyDocuments/ITU/GP/RenderEngineFork/SimpleRenderEngineProjectFork/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jonas2.0/MyDocuments/ITU/GP/RenderEngineFork/SimpleRenderEngineProjectFork /Users/jonas2.0/MyDocuments/ITU/GP/RenderEngineFork/SimpleRenderEngineProjectFork/project/gui /Users/jonas2.0/MyDocuments/ITU/GP/RenderEngineFork/SimpleRenderEngineProjectFork/cmake-build-debug /Users/jonas2.0/MyDocuments/ITU/GP/RenderEngineFork/SimpleRenderEngineProjectFork/cmake-build-debug/project/gui /Users/jonas2.0/MyDocuments/ITU/GP/RenderEngineFork/SimpleRenderEngineProjectFork/cmake-build-debug/project/gui/CMakeFiles/SRE-Gui.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : project/gui/CMakeFiles/SRE-Gui.dir/depend

