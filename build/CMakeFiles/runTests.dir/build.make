# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.30.2/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.30.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/lucyhadden/COSC345

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/lucyhadden/COSC345/build

# Include any dependencies generated for this target.
include CMakeFiles/runTests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/runTests.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/runTests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/runTests.dir/flags.make

CMakeFiles/runTests.dir/Test/AsciiArtTest.cpp.o: CMakeFiles/runTests.dir/flags.make
CMakeFiles/runTests.dir/Test/AsciiArtTest.cpp.o: /Users/lucyhadden/COSC345/Test/AsciiArtTest.cpp
CMakeFiles/runTests.dir/Test/AsciiArtTest.cpp.o: CMakeFiles/runTests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/lucyhadden/COSC345/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/runTests.dir/Test/AsciiArtTest.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/runTests.dir/Test/AsciiArtTest.cpp.o -MF CMakeFiles/runTests.dir/Test/AsciiArtTest.cpp.o.d -o CMakeFiles/runTests.dir/Test/AsciiArtTest.cpp.o -c /Users/lucyhadden/COSC345/Test/AsciiArtTest.cpp

CMakeFiles/runTests.dir/Test/AsciiArtTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/runTests.dir/Test/AsciiArtTest.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lucyhadden/COSC345/Test/AsciiArtTest.cpp > CMakeFiles/runTests.dir/Test/AsciiArtTest.cpp.i

CMakeFiles/runTests.dir/Test/AsciiArtTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/runTests.dir/Test/AsciiArtTest.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lucyhadden/COSC345/Test/AsciiArtTest.cpp -o CMakeFiles/runTests.dir/Test/AsciiArtTest.cpp.s

CMakeFiles/runTests.dir/Test/EndScreenTest.cpp.o: CMakeFiles/runTests.dir/flags.make
CMakeFiles/runTests.dir/Test/EndScreenTest.cpp.o: /Users/lucyhadden/COSC345/Test/EndScreenTest.cpp
CMakeFiles/runTests.dir/Test/EndScreenTest.cpp.o: CMakeFiles/runTests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/lucyhadden/COSC345/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/runTests.dir/Test/EndScreenTest.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/runTests.dir/Test/EndScreenTest.cpp.o -MF CMakeFiles/runTests.dir/Test/EndScreenTest.cpp.o.d -o CMakeFiles/runTests.dir/Test/EndScreenTest.cpp.o -c /Users/lucyhadden/COSC345/Test/EndScreenTest.cpp

CMakeFiles/runTests.dir/Test/EndScreenTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/runTests.dir/Test/EndScreenTest.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lucyhadden/COSC345/Test/EndScreenTest.cpp > CMakeFiles/runTests.dir/Test/EndScreenTest.cpp.i

CMakeFiles/runTests.dir/Test/EndScreenTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/runTests.dir/Test/EndScreenTest.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lucyhadden/COSC345/Test/EndScreenTest.cpp -o CMakeFiles/runTests.dir/Test/EndScreenTest.cpp.s

CMakeFiles/runTests.dir/Test/InteractionsTest.cpp.o: CMakeFiles/runTests.dir/flags.make
CMakeFiles/runTests.dir/Test/InteractionsTest.cpp.o: /Users/lucyhadden/COSC345/Test/InteractionsTest.cpp
CMakeFiles/runTests.dir/Test/InteractionsTest.cpp.o: CMakeFiles/runTests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/lucyhadden/COSC345/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/runTests.dir/Test/InteractionsTest.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/runTests.dir/Test/InteractionsTest.cpp.o -MF CMakeFiles/runTests.dir/Test/InteractionsTest.cpp.o.d -o CMakeFiles/runTests.dir/Test/InteractionsTest.cpp.o -c /Users/lucyhadden/COSC345/Test/InteractionsTest.cpp

CMakeFiles/runTests.dir/Test/InteractionsTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/runTests.dir/Test/InteractionsTest.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lucyhadden/COSC345/Test/InteractionsTest.cpp > CMakeFiles/runTests.dir/Test/InteractionsTest.cpp.i

CMakeFiles/runTests.dir/Test/InteractionsTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/runTests.dir/Test/InteractionsTest.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lucyhadden/COSC345/Test/InteractionsTest.cpp -o CMakeFiles/runTests.dir/Test/InteractionsTest.cpp.s

CMakeFiles/runTests.dir/Test/ItemTest.cpp.o: CMakeFiles/runTests.dir/flags.make
CMakeFiles/runTests.dir/Test/ItemTest.cpp.o: /Users/lucyhadden/COSC345/Test/ItemTest.cpp
CMakeFiles/runTests.dir/Test/ItemTest.cpp.o: CMakeFiles/runTests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/lucyhadden/COSC345/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/runTests.dir/Test/ItemTest.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/runTests.dir/Test/ItemTest.cpp.o -MF CMakeFiles/runTests.dir/Test/ItemTest.cpp.o.d -o CMakeFiles/runTests.dir/Test/ItemTest.cpp.o -c /Users/lucyhadden/COSC345/Test/ItemTest.cpp

CMakeFiles/runTests.dir/Test/ItemTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/runTests.dir/Test/ItemTest.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lucyhadden/COSC345/Test/ItemTest.cpp > CMakeFiles/runTests.dir/Test/ItemTest.cpp.i

CMakeFiles/runTests.dir/Test/ItemTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/runTests.dir/Test/ItemTest.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lucyhadden/COSC345/Test/ItemTest.cpp -o CMakeFiles/runTests.dir/Test/ItemTest.cpp.s

CMakeFiles/runTests.dir/Test/PlayerTest.cpp.o: CMakeFiles/runTests.dir/flags.make
CMakeFiles/runTests.dir/Test/PlayerTest.cpp.o: /Users/lucyhadden/COSC345/Test/PlayerTest.cpp
CMakeFiles/runTests.dir/Test/PlayerTest.cpp.o: CMakeFiles/runTests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/lucyhadden/COSC345/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/runTests.dir/Test/PlayerTest.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/runTests.dir/Test/PlayerTest.cpp.o -MF CMakeFiles/runTests.dir/Test/PlayerTest.cpp.o.d -o CMakeFiles/runTests.dir/Test/PlayerTest.cpp.o -c /Users/lucyhadden/COSC345/Test/PlayerTest.cpp

CMakeFiles/runTests.dir/Test/PlayerTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/runTests.dir/Test/PlayerTest.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lucyhadden/COSC345/Test/PlayerTest.cpp > CMakeFiles/runTests.dir/Test/PlayerTest.cpp.i

CMakeFiles/runTests.dir/Test/PlayerTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/runTests.dir/Test/PlayerTest.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lucyhadden/COSC345/Test/PlayerTest.cpp -o CMakeFiles/runTests.dir/Test/PlayerTest.cpp.s

# Object files for target runTests
runTests_OBJECTS = \
"CMakeFiles/runTests.dir/Test/AsciiArtTest.cpp.o" \
"CMakeFiles/runTests.dir/Test/EndScreenTest.cpp.o" \
"CMakeFiles/runTests.dir/Test/InteractionsTest.cpp.o" \
"CMakeFiles/runTests.dir/Test/ItemTest.cpp.o" \
"CMakeFiles/runTests.dir/Test/PlayerTest.cpp.o"

# External object files for target runTests
runTests_EXTERNAL_OBJECTS =

runTests: CMakeFiles/runTests.dir/Test/AsciiArtTest.cpp.o
runTests: CMakeFiles/runTests.dir/Test/EndScreenTest.cpp.o
runTests: CMakeFiles/runTests.dir/Test/InteractionsTest.cpp.o
runTests: CMakeFiles/runTests.dir/Test/ItemTest.cpp.o
runTests: CMakeFiles/runTests.dir/Test/PlayerTest.cpp.o
runTests: CMakeFiles/runTests.dir/build.make
runTests: lib/libgtest_main.a
runTests: lib/libgtest.a
runTests: CMakeFiles/runTests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/lucyhadden/COSC345/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable runTests"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/runTests.dir/link.txt --verbose=$(VERBOSE)
	/opt/homebrew/Cellar/cmake/3.30.2/bin/cmake -D TEST_TARGET=runTests -D TEST_EXECUTABLE=/Users/lucyhadden/COSC345/build/runTests -D TEST_EXECUTOR= -D TEST_WORKING_DIR=/Users/lucyhadden/COSC345/build -D TEST_EXTRA_ARGS= -D TEST_PROPERTIES= -D TEST_PREFIX= -D TEST_SUFFIX= -D TEST_FILTER= -D NO_PRETTY_TYPES=FALSE -D NO_PRETTY_VALUES=FALSE -D TEST_LIST=runTests_TESTS -D CTEST_FILE=/Users/lucyhadden/COSC345/build/runTests[1]_tests.cmake -D TEST_DISCOVERY_TIMEOUT=5 -D TEST_XML_OUTPUT_DIR= -P /opt/homebrew/Cellar/cmake/3.30.2/share/cmake/Modules/GoogleTestAddTests.cmake

# Rule to build all files generated by this target.
CMakeFiles/runTests.dir/build: runTests
.PHONY : CMakeFiles/runTests.dir/build

CMakeFiles/runTests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/runTests.dir/cmake_clean.cmake
.PHONY : CMakeFiles/runTests.dir/clean

CMakeFiles/runTests.dir/depend:
	cd /Users/lucyhadden/COSC345/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/lucyhadden/COSC345 /Users/lucyhadden/COSC345 /Users/lucyhadden/COSC345/build /Users/lucyhadden/COSC345/build /Users/lucyhadden/COSC345/build/CMakeFiles/runTests.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/runTests.dir/depend

