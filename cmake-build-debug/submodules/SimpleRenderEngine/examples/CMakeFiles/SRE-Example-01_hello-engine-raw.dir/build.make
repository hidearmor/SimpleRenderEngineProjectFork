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
include submodules/SimpleRenderEngine/examples/CMakeFiles/SRE-Example-01_hello-engine-raw.dir/depend.make

# Include the progress variables for this target.
include submodules/SimpleRenderEngine/examples/CMakeFiles/SRE-Example-01_hello-engine-raw.dir/progress.make

# Include the compile flags for this target's objects.
include submodules/SimpleRenderEngine/examples/CMakeFiles/SRE-Example-01_hello-engine-raw.dir/flags.make

submodules/SimpleRenderEngine/examples/CMakeFiles/SRE-Example-01_hello-engine-raw.dir/01_hello-engine-raw.cpp.o: submodules/SimpleRenderEngine/examples/CMakeFiles/SRE-Example-01_hello-engine-raw.dir/flags.make
submodules/SimpleRenderEngine/examples/CMakeFiles/SRE-Example-01_hello-engine-raw.dir/01_hello-engine-raw.cpp.o: ../submodules/SimpleRenderEngine/examples/01_hello-engine-raw.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jonas2.0/MyDocuments/ITU/GP/RenderEngineFork/SimpleRenderEngineProjectFork/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object submodules/SimpleRenderEngine/examples/CMakeFiles/SRE-Example-01_hello-engine-raw.dir/01_hello-engine-raw.cpp.o"
	cd /Users/jonas2.0/MyDocuments/ITU/GP/RenderEngineFork/SimpleRenderEngineProjectFork/cmake-build-debug/submodules/SimpleRenderEngine/examples && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SRE-Example-01_hello-engine-raw.dir/01_hello-engine-raw.cpp.o -c /Users/jonas2.0/MyDocuments/ITU/GP/RenderEngineFork/SimpleRenderEngineProjectFork/submodules/SimpleRenderEngine/examples/01_hello-engine-raw.cpp

submodules/SimpleRenderEngine/examples/CMakeFiles/SRE-Example-01_hello-engine-raw.dir/01_hello-engine-raw.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SRE-Example-01_hello-engine-raw.dir/01_hello-engine-raw.cpp.i"
	cd /Users/jonas2.0/MyDocuments/ITU/GP/RenderEngineFork/SimpleRenderEngineProjectFork/cmake-build-debug/submodules/SimpleRenderEngine/examples && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jonas2.0/MyDocuments/ITU/GP/RenderEngineFork/SimpleRenderEngineProjectFork/submodules/SimpleRenderEngine/examples/01_hello-engine-raw.cpp > CMakeFiles/SRE-Example-01_hello-engine-raw.dir/01_hello-engine-raw.cpp.i

submodules/SimpleRenderEngine/examples/CMakeFiles/SRE-Example-01_hello-engine-raw.dir/01_hello-engine-raw.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SRE-Example-01_hello-engine-raw.dir/01_hello-engine-raw.cpp.s"
	cd /Users/jonas2.0/MyDocuments/ITU/GP/RenderEngineFork/SimpleRenderEngineProjectFork/cmake-build-debug/submodules/SimpleRenderEngine/examples && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jonas2.0/MyDocuments/ITU/GP/RenderEngineFork/SimpleRenderEngineProjectFork/submodules/SimpleRenderEngine/examples/01_hello-engine-raw.cpp -o CMakeFiles/SRE-Example-01_hello-engine-raw.dir/01_hello-engine-raw.cpp.s

# Object files for target SRE-Example-01_hello-engine-raw
SRE__Example__01_hello__engine__raw_OBJECTS = \
"CMakeFiles/SRE-Example-01_hello-engine-raw.dir/01_hello-engine-raw.cpp.o"

# External object files for target SRE-Example-01_hello-engine-raw
SRE__Example__01_hello__engine__raw_EXTERNAL_OBJECTS =

submodules/SimpleRenderEngine/examples/SRE-Example-01_hello-engine-raw: submodules/SimpleRenderEngine/examples/CMakeFiles/SRE-Example-01_hello-engine-raw.dir/01_hello-engine-raw.cpp.o
submodules/SimpleRenderEngine/examples/SRE-Example-01_hello-engine-raw: submodules/SimpleRenderEngine/examples/CMakeFiles/SRE-Example-01_hello-engine-raw.dir/build.make
submodules/SimpleRenderEngine/examples/SRE-Example-01_hello-engine-raw: submodules/SimpleRenderEngine/src/libSRE.a
submodules/SimpleRenderEngine/examples/SRE-Example-01_hello-engine-raw: submodules/SimpleRenderEngine/examples/CMakeFiles/SRE-Example-01_hello-engine-raw.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/jonas2.0/MyDocuments/ITU/GP/RenderEngineFork/SimpleRenderEngineProjectFork/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable SRE-Example-01_hello-engine-raw"
	cd /Users/jonas2.0/MyDocuments/ITU/GP/RenderEngineFork/SimpleRenderEngineProjectFork/cmake-build-debug/submodules/SimpleRenderEngine/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SRE-Example-01_hello-engine-raw.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
submodules/SimpleRenderEngine/examples/CMakeFiles/SRE-Example-01_hello-engine-raw.dir/build: submodules/SimpleRenderEngine/examples/SRE-Example-01_hello-engine-raw

.PHONY : submodules/SimpleRenderEngine/examples/CMakeFiles/SRE-Example-01_hello-engine-raw.dir/build

submodules/SimpleRenderEngine/examples/CMakeFiles/SRE-Example-01_hello-engine-raw.dir/clean:
	cd /Users/jonas2.0/MyDocuments/ITU/GP/RenderEngineFork/SimpleRenderEngineProjectFork/cmake-build-debug/submodules/SimpleRenderEngine/examples && $(CMAKE_COMMAND) -P CMakeFiles/SRE-Example-01_hello-engine-raw.dir/cmake_clean.cmake
.PHONY : submodules/SimpleRenderEngine/examples/CMakeFiles/SRE-Example-01_hello-engine-raw.dir/clean

submodules/SimpleRenderEngine/examples/CMakeFiles/SRE-Example-01_hello-engine-raw.dir/depend:
	cd /Users/jonas2.0/MyDocuments/ITU/GP/RenderEngineFork/SimpleRenderEngineProjectFork/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jonas2.0/MyDocuments/ITU/GP/RenderEngineFork/SimpleRenderEngineProjectFork /Users/jonas2.0/MyDocuments/ITU/GP/RenderEngineFork/SimpleRenderEngineProjectFork/submodules/SimpleRenderEngine/examples /Users/jonas2.0/MyDocuments/ITU/GP/RenderEngineFork/SimpleRenderEngineProjectFork/cmake-build-debug /Users/jonas2.0/MyDocuments/ITU/GP/RenderEngineFork/SimpleRenderEngineProjectFork/cmake-build-debug/submodules/SimpleRenderEngine/examples /Users/jonas2.0/MyDocuments/ITU/GP/RenderEngineFork/SimpleRenderEngineProjectFork/cmake-build-debug/submodules/SimpleRenderEngine/examples/CMakeFiles/SRE-Example-01_hello-engine-raw.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : submodules/SimpleRenderEngine/examples/CMakeFiles/SRE-Example-01_hello-engine-raw.dir/depend

