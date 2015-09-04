# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dhruva/Documents/mlab/autonomous-racing/VanishingPoint/code

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dhruva/Documents/mlab/autonomous-racing/VanishingPoint/code

# Include any dependencies generated for this target.
include CMakeFiles/vp.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/vp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/vp.dir/flags.make

CMakeFiles/vp.dir/vanishing_point_video.cpp.o: CMakeFiles/vp.dir/flags.make
CMakeFiles/vp.dir/vanishing_point_video.cpp.o: vanishing_point_video.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/dhruva/Documents/mlab/autonomous-racing/VanishingPoint/code/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/vp.dir/vanishing_point_video.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/vp.dir/vanishing_point_video.cpp.o -c /home/dhruva/Documents/mlab/autonomous-racing/VanishingPoint/code/vanishing_point_video.cpp

CMakeFiles/vp.dir/vanishing_point_video.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vp.dir/vanishing_point_video.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/dhruva/Documents/mlab/autonomous-racing/VanishingPoint/code/vanishing_point_video.cpp > CMakeFiles/vp.dir/vanishing_point_video.cpp.i

CMakeFiles/vp.dir/vanishing_point_video.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vp.dir/vanishing_point_video.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/dhruva/Documents/mlab/autonomous-racing/VanishingPoint/code/vanishing_point_video.cpp -o CMakeFiles/vp.dir/vanishing_point_video.cpp.s

CMakeFiles/vp.dir/vanishing_point_video.cpp.o.requires:
.PHONY : CMakeFiles/vp.dir/vanishing_point_video.cpp.o.requires

CMakeFiles/vp.dir/vanishing_point_video.cpp.o.provides: CMakeFiles/vp.dir/vanishing_point_video.cpp.o.requires
	$(MAKE) -f CMakeFiles/vp.dir/build.make CMakeFiles/vp.dir/vanishing_point_video.cpp.o.provides.build
.PHONY : CMakeFiles/vp.dir/vanishing_point_video.cpp.o.provides

CMakeFiles/vp.dir/vanishing_point_video.cpp.o.provides.build: CMakeFiles/vp.dir/vanishing_point_video.cpp.o

# Object files for target vp
vp_OBJECTS = \
"CMakeFiles/vp.dir/vanishing_point_video.cpp.o"

# External object files for target vp
vp_EXTERNAL_OBJECTS =

vp: CMakeFiles/vp.dir/vanishing_point_video.cpp.o
vp: /usr/lib/libopencv_calib3d.so
vp: /usr/lib/libopencv_contrib.so
vp: /usr/lib/libopencv_core.so
vp: /usr/lib/libopencv_features2d.so
vp: /usr/lib/libopencv_flann.so
vp: /usr/lib/libopencv_gpu.so
vp: /usr/lib/libopencv_highgui.so
vp: /usr/lib/libopencv_imgproc.so
vp: /usr/lib/libopencv_legacy.so
vp: /usr/lib/libopencv_ml.so
vp: /usr/lib/libopencv_nonfree.so
vp: /usr/lib/libopencv_objdetect.so
vp: /usr/lib/libopencv_photo.so
vp: /usr/lib/libopencv_stitching.so
vp: /usr/lib/libopencv_ts.so
vp: /usr/lib/libopencv_video.so
vp: /usr/lib/libopencv_videostab.so
vp: CMakeFiles/vp.dir/build.make
vp: CMakeFiles/vp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable vp"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/vp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/vp.dir/build: vp
.PHONY : CMakeFiles/vp.dir/build

CMakeFiles/vp.dir/requires: CMakeFiles/vp.dir/vanishing_point_video.cpp.o.requires
.PHONY : CMakeFiles/vp.dir/requires

CMakeFiles/vp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/vp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/vp.dir/clean

CMakeFiles/vp.dir/depend:
	cd /home/dhruva/Documents/mlab/autonomous-racing/VanishingPoint/code && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dhruva/Documents/mlab/autonomous-racing/VanishingPoint/code /home/dhruva/Documents/mlab/autonomous-racing/VanishingPoint/code /home/dhruva/Documents/mlab/autonomous-racing/VanishingPoint/code /home/dhruva/Documents/mlab/autonomous-racing/VanishingPoint/code /home/dhruva/Documents/mlab/autonomous-racing/VanishingPoint/code/CMakeFiles/vp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/vp.dir/depend
