# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.4

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canoncical targets will work.
.SUFFIXES:

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /proyect/rxwebcam_beta

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /proyect/rxwebcam_beta

# Include any dependencies generated for this target.
include plugins/photo_server/CMakeFiles/pluginphotoserver.dir/depend.make

# Include the progress variables for this target.
include plugins/photo_server/CMakeFiles/pluginphotoserver.dir/progress.make

# Include the compile flags for this target's objects.
include plugins/photo_server/CMakeFiles/pluginphotoserver.dir/flags.make

plugins/photo_server/CMakeFiles/pluginphotoserver.dir/depend.make.mark: plugins/photo_server/CMakeFiles/pluginphotoserver.dir/flags.make
plugins/photo_server/CMakeFiles/pluginphotoserver.dir/depend.make.mark: plugins/photo_server/thread_server.cpp

plugins/photo_server/CMakeFiles/pluginphotoserver.dir/thread_server.o: plugins/photo_server/CMakeFiles/pluginphotoserver.dir/flags.make
plugins/photo_server/CMakeFiles/pluginphotoserver.dir/thread_server.o: plugins/photo_server/thread_server.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /proyect/rxwebcam_beta/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object plugins/photo_server/CMakeFiles/pluginphotoserver.dir/thread_server.o"
	/usr/bin/c++   $(CXX_FLAGS) -o plugins/photo_server/CMakeFiles/pluginphotoserver.dir/thread_server.o -c /proyect/rxwebcam_beta/plugins/photo_server/thread_server.cpp

plugins/photo_server/CMakeFiles/pluginphotoserver.dir/thread_server.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to plugins/photo_server/CMakeFiles/pluginphotoserver.dir/thread_server.i"
	/usr/bin/c++  $(CXX_FLAGS) -E /proyect/rxwebcam_beta/plugins/photo_server/thread_server.cpp > plugins/photo_server/CMakeFiles/pluginphotoserver.dir/thread_server.i

plugins/photo_server/CMakeFiles/pluginphotoserver.dir/thread_server.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly plugins/photo_server/CMakeFiles/pluginphotoserver.dir/thread_server.s"
	/usr/bin/c++  $(CXX_FLAGS) -S /proyect/rxwebcam_beta/plugins/photo_server/thread_server.cpp -o plugins/photo_server/CMakeFiles/pluginphotoserver.dir/thread_server.s

plugins/photo_server/CMakeFiles/pluginphotoserver.dir/thread_server.o.requires:

plugins/photo_server/CMakeFiles/pluginphotoserver.dir/thread_server.o.provides: plugins/photo_server/CMakeFiles/pluginphotoserver.dir/thread_server.o.requires
	$(MAKE) -f plugins/photo_server/CMakeFiles/pluginphotoserver.dir/build.make plugins/photo_server/CMakeFiles/pluginphotoserver.dir/thread_server.o.provides.build

plugins/photo_server/CMakeFiles/pluginphotoserver.dir/thread_server.o.provides.build: plugins/photo_server/CMakeFiles/pluginphotoserver.dir/thread_server.o

plugins/photo_server/CMakeFiles/pluginphotoserver.dir/depend.make.mark: plugins/photo_server/CMakeFiles/pluginphotoserver.dir/flags.make
plugins/photo_server/CMakeFiles/pluginphotoserver.dir/depend.make.mark: plugins/photo_server/plugin_photo_server.cpp

plugins/photo_server/CMakeFiles/pluginphotoserver.dir/plugin_photo_server.o: plugins/photo_server/CMakeFiles/pluginphotoserver.dir/flags.make
plugins/photo_server/CMakeFiles/pluginphotoserver.dir/plugin_photo_server.o: plugins/photo_server/plugin_photo_server.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /proyect/rxwebcam_beta/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object plugins/photo_server/CMakeFiles/pluginphotoserver.dir/plugin_photo_server.o"
	/usr/bin/c++   $(CXX_FLAGS) -o plugins/photo_server/CMakeFiles/pluginphotoserver.dir/plugin_photo_server.o -c /proyect/rxwebcam_beta/plugins/photo_server/plugin_photo_server.cpp

plugins/photo_server/CMakeFiles/pluginphotoserver.dir/plugin_photo_server.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to plugins/photo_server/CMakeFiles/pluginphotoserver.dir/plugin_photo_server.i"
	/usr/bin/c++  $(CXX_FLAGS) -E /proyect/rxwebcam_beta/plugins/photo_server/plugin_photo_server.cpp > plugins/photo_server/CMakeFiles/pluginphotoserver.dir/plugin_photo_server.i

plugins/photo_server/CMakeFiles/pluginphotoserver.dir/plugin_photo_server.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly plugins/photo_server/CMakeFiles/pluginphotoserver.dir/plugin_photo_server.s"
	/usr/bin/c++  $(CXX_FLAGS) -S /proyect/rxwebcam_beta/plugins/photo_server/plugin_photo_server.cpp -o plugins/photo_server/CMakeFiles/pluginphotoserver.dir/plugin_photo_server.s

plugins/photo_server/CMakeFiles/pluginphotoserver.dir/plugin_photo_server.o.requires:

plugins/photo_server/CMakeFiles/pluginphotoserver.dir/plugin_photo_server.o.provides: plugins/photo_server/CMakeFiles/pluginphotoserver.dir/plugin_photo_server.o.requires
	$(MAKE) -f plugins/photo_server/CMakeFiles/pluginphotoserver.dir/build.make plugins/photo_server/CMakeFiles/pluginphotoserver.dir/plugin_photo_server.o.provides.build

plugins/photo_server/CMakeFiles/pluginphotoserver.dir/plugin_photo_server.o.provides.build: plugins/photo_server/CMakeFiles/pluginphotoserver.dir/plugin_photo_server.o

plugins/photo_server/CMakeFiles/pluginphotoserver.dir/depend.make.mark: plugins/photo_server/CMakeFiles/pluginphotoserver.dir/flags.make
plugins/photo_server/CMakeFiles/pluginphotoserver.dir/depend.make.mark: plugins/photo_server/simple_server.cpp

plugins/photo_server/CMakeFiles/pluginphotoserver.dir/simple_server.o: plugins/photo_server/CMakeFiles/pluginphotoserver.dir/flags.make
plugins/photo_server/CMakeFiles/pluginphotoserver.dir/simple_server.o: plugins/photo_server/simple_server.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /proyect/rxwebcam_beta/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object plugins/photo_server/CMakeFiles/pluginphotoserver.dir/simple_server.o"
	/usr/bin/c++   $(CXX_FLAGS) -o plugins/photo_server/CMakeFiles/pluginphotoserver.dir/simple_server.o -c /proyect/rxwebcam_beta/plugins/photo_server/simple_server.cpp

plugins/photo_server/CMakeFiles/pluginphotoserver.dir/simple_server.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to plugins/photo_server/CMakeFiles/pluginphotoserver.dir/simple_server.i"
	/usr/bin/c++  $(CXX_FLAGS) -E /proyect/rxwebcam_beta/plugins/photo_server/simple_server.cpp > plugins/photo_server/CMakeFiles/pluginphotoserver.dir/simple_server.i

plugins/photo_server/CMakeFiles/pluginphotoserver.dir/simple_server.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly plugins/photo_server/CMakeFiles/pluginphotoserver.dir/simple_server.s"
	/usr/bin/c++  $(CXX_FLAGS) -S /proyect/rxwebcam_beta/plugins/photo_server/simple_server.cpp -o plugins/photo_server/CMakeFiles/pluginphotoserver.dir/simple_server.s

plugins/photo_server/CMakeFiles/pluginphotoserver.dir/simple_server.o.requires:

plugins/photo_server/CMakeFiles/pluginphotoserver.dir/simple_server.o.provides: plugins/photo_server/CMakeFiles/pluginphotoserver.dir/simple_server.o.requires
	$(MAKE) -f plugins/photo_server/CMakeFiles/pluginphotoserver.dir/build.make plugins/photo_server/CMakeFiles/pluginphotoserver.dir/simple_server.o.provides.build

plugins/photo_server/CMakeFiles/pluginphotoserver.dir/simple_server.o.provides.build: plugins/photo_server/CMakeFiles/pluginphotoserver.dir/simple_server.o

plugins/photo_server/CMakeFiles/pluginphotoserver.dir/depend.make.mark: plugins/photo_server/CMakeFiles/pluginphotoserver.dir/flags.make
plugins/photo_server/CMakeFiles/pluginphotoserver.dir/depend.make.mark: plugins/photo_server/ui_interfaces/ConfigPluginImp.cpp

plugins/photo_server/CMakeFiles/pluginphotoserver.dir/ui_interfaces/ConfigPluginImp.o: plugins/photo_server/CMakeFiles/pluginphotoserver.dir/flags.make
plugins/photo_server/CMakeFiles/pluginphotoserver.dir/ui_interfaces/ConfigPluginImp.o: plugins/photo_server/ui_interfaces/ConfigPluginImp.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /proyect/rxwebcam_beta/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object plugins/photo_server/CMakeFiles/pluginphotoserver.dir/ui_interfaces/ConfigPluginImp.o"
	/usr/bin/c++   $(CXX_FLAGS) -o plugins/photo_server/CMakeFiles/pluginphotoserver.dir/ui_interfaces/ConfigPluginImp.o -c /proyect/rxwebcam_beta/plugins/photo_server/ui_interfaces/ConfigPluginImp.cpp

plugins/photo_server/CMakeFiles/pluginphotoserver.dir/ui_interfaces/ConfigPluginImp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to plugins/photo_server/CMakeFiles/pluginphotoserver.dir/ui_interfaces/ConfigPluginImp.i"
	/usr/bin/c++  $(CXX_FLAGS) -E /proyect/rxwebcam_beta/plugins/photo_server/ui_interfaces/ConfigPluginImp.cpp > plugins/photo_server/CMakeFiles/pluginphotoserver.dir/ui_interfaces/ConfigPluginImp.i

plugins/photo_server/CMakeFiles/pluginphotoserver.dir/ui_interfaces/ConfigPluginImp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly plugins/photo_server/CMakeFiles/pluginphotoserver.dir/ui_interfaces/ConfigPluginImp.s"
	/usr/bin/c++  $(CXX_FLAGS) -S /proyect/rxwebcam_beta/plugins/photo_server/ui_interfaces/ConfigPluginImp.cpp -o plugins/photo_server/CMakeFiles/pluginphotoserver.dir/ui_interfaces/ConfigPluginImp.s

plugins/photo_server/CMakeFiles/pluginphotoserver.dir/ui_interfaces/ConfigPluginImp.o.requires:

plugins/photo_server/CMakeFiles/pluginphotoserver.dir/ui_interfaces/ConfigPluginImp.o.provides: plugins/photo_server/CMakeFiles/pluginphotoserver.dir/ui_interfaces/ConfigPluginImp.o.requires
	$(MAKE) -f plugins/photo_server/CMakeFiles/pluginphotoserver.dir/build.make plugins/photo_server/CMakeFiles/pluginphotoserver.dir/ui_interfaces/ConfigPluginImp.o.provides.build

plugins/photo_server/CMakeFiles/pluginphotoserver.dir/ui_interfaces/ConfigPluginImp.o.provides.build: plugins/photo_server/CMakeFiles/pluginphotoserver.dir/ui_interfaces/ConfigPluginImp.o

plugins/photo_server/CMakeFiles/pluginphotoserver.dir/depend.make.mark: plugins/photo_server/CMakeFiles/pluginphotoserver.dir/flags.make
plugins/photo_server/CMakeFiles/pluginphotoserver.dir/depend.make.mark: plugins/photo_server/ui_interfaces/ValidateIp.cpp

plugins/photo_server/CMakeFiles/pluginphotoserver.dir/ui_interfaces/ValidateIp.o: plugins/photo_server/CMakeFiles/pluginphotoserver.dir/flags.make
plugins/photo_server/CMakeFiles/pluginphotoserver.dir/ui_interfaces/ValidateIp.o: plugins/photo_server/ui_interfaces/ValidateIp.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /proyect/rxwebcam_beta/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object plugins/photo_server/CMakeFiles/pluginphotoserver.dir/ui_interfaces/ValidateIp.o"
	/usr/bin/c++   $(CXX_FLAGS) -o plugins/photo_server/CMakeFiles/pluginphotoserver.dir/ui_interfaces/ValidateIp.o -c /proyect/rxwebcam_beta/plugins/photo_server/ui_interfaces/ValidateIp.cpp

plugins/photo_server/CMakeFiles/pluginphotoserver.dir/ui_interfaces/ValidateIp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to plugins/photo_server/CMakeFiles/pluginphotoserver.dir/ui_interfaces/ValidateIp.i"
	/usr/bin/c++  $(CXX_FLAGS) -E /proyect/rxwebcam_beta/plugins/photo_server/ui_interfaces/ValidateIp.cpp > plugins/photo_server/CMakeFiles/pluginphotoserver.dir/ui_interfaces/ValidateIp.i

plugins/photo_server/CMakeFiles/pluginphotoserver.dir/ui_interfaces/ValidateIp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly plugins/photo_server/CMakeFiles/pluginphotoserver.dir/ui_interfaces/ValidateIp.s"
	/usr/bin/c++  $(CXX_FLAGS) -S /proyect/rxwebcam_beta/plugins/photo_server/ui_interfaces/ValidateIp.cpp -o plugins/photo_server/CMakeFiles/pluginphotoserver.dir/ui_interfaces/ValidateIp.s

plugins/photo_server/CMakeFiles/pluginphotoserver.dir/ui_interfaces/ValidateIp.o.requires:

plugins/photo_server/CMakeFiles/pluginphotoserver.dir/ui_interfaces/ValidateIp.o.provides: plugins/photo_server/CMakeFiles/pluginphotoserver.dir/ui_interfaces/ValidateIp.o.requires
	$(MAKE) -f plugins/photo_server/CMakeFiles/pluginphotoserver.dir/build.make plugins/photo_server/CMakeFiles/pluginphotoserver.dir/ui_interfaces/ValidateIp.o.provides.build

plugins/photo_server/CMakeFiles/pluginphotoserver.dir/ui_interfaces/ValidateIp.o.provides.build: plugins/photo_server/CMakeFiles/pluginphotoserver.dir/ui_interfaces/ValidateIp.o

plugins/photo_server/CMakeFiles/pluginphotoserver.dir/depend.make.mark: plugins/photo_server/CMakeFiles/pluginphotoserver.dir/flags.make
plugins/photo_server/CMakeFiles/pluginphotoserver.dir/depend.make.mark: plugins/photo_server/moc_plugin_photo_server.cxx

plugins/photo_server/CMakeFiles/pluginphotoserver.dir/moc_plugin_photo_server.o: plugins/photo_server/CMakeFiles/pluginphotoserver.dir/flags.make
plugins/photo_server/CMakeFiles/pluginphotoserver.dir/moc_plugin_photo_server.o: plugins/photo_server/moc_plugin_photo_server.cxx
	$(CMAKE_COMMAND) -E cmake_progress_report /proyect/rxwebcam_beta/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object plugins/photo_server/CMakeFiles/pluginphotoserver.dir/moc_plugin_photo_server.o"
	/usr/bin/c++   $(CXX_FLAGS) -o plugins/photo_server/CMakeFiles/pluginphotoserver.dir/moc_plugin_photo_server.o -c /proyect/rxwebcam_beta/plugins/photo_server/moc_plugin_photo_server.cxx

plugins/photo_server/CMakeFiles/pluginphotoserver.dir/moc_plugin_photo_server.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to plugins/photo_server/CMakeFiles/pluginphotoserver.dir/moc_plugin_photo_server.i"
	/usr/bin/c++  $(CXX_FLAGS) -E /proyect/rxwebcam_beta/plugins/photo_server/moc_plugin_photo_server.cxx > plugins/photo_server/CMakeFiles/pluginphotoserver.dir/moc_plugin_photo_server.i

plugins/photo_server/CMakeFiles/pluginphotoserver.dir/moc_plugin_photo_server.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly plugins/photo_server/CMakeFiles/pluginphotoserver.dir/moc_plugin_photo_server.s"
	/usr/bin/c++  $(CXX_FLAGS) -S /proyect/rxwebcam_beta/plugins/photo_server/moc_plugin_photo_server.cxx -o plugins/photo_server/CMakeFiles/pluginphotoserver.dir/moc_plugin_photo_server.s

plugins/photo_server/CMakeFiles/pluginphotoserver.dir/moc_plugin_photo_server.o.requires:

plugins/photo_server/CMakeFiles/pluginphotoserver.dir/moc_plugin_photo_server.o.provides: plugins/photo_server/CMakeFiles/pluginphotoserver.dir/moc_plugin_photo_server.o.requires
	$(MAKE) -f plugins/photo_server/CMakeFiles/pluginphotoserver.dir/build.make plugins/photo_server/CMakeFiles/pluginphotoserver.dir/moc_plugin_photo_server.o.provides.build

plugins/photo_server/CMakeFiles/pluginphotoserver.dir/moc_plugin_photo_server.o.provides.build: plugins/photo_server/CMakeFiles/pluginphotoserver.dir/moc_plugin_photo_server.o

plugins/photo_server/CMakeFiles/pluginphotoserver.dir/depend.make.mark: plugins/photo_server/CMakeFiles/pluginphotoserver.dir/flags.make
plugins/photo_server/CMakeFiles/pluginphotoserver.dir/depend.make.mark: plugins/photo_server/moc_simple_server.cxx

plugins/photo_server/CMakeFiles/pluginphotoserver.dir/moc_simple_server.o: plugins/photo_server/CMakeFiles/pluginphotoserver.dir/flags.make
plugins/photo_server/CMakeFiles/pluginphotoserver.dir/moc_simple_server.o: plugins/photo_server/moc_simple_server.cxx
	$(CMAKE_COMMAND) -E cmake_progress_report /proyect/rxwebcam_beta/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object plugins/photo_server/CMakeFiles/pluginphotoserver.dir/moc_simple_server.o"
	/usr/bin/c++   $(CXX_FLAGS) -o plugins/photo_server/CMakeFiles/pluginphotoserver.dir/moc_simple_server.o -c /proyect/rxwebcam_beta/plugins/photo_server/moc_simple_server.cxx

plugins/photo_server/CMakeFiles/pluginphotoserver.dir/moc_simple_server.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to plugins/photo_server/CMakeFiles/pluginphotoserver.dir/moc_simple_server.i"
	/usr/bin/c++  $(CXX_FLAGS) -E /proyect/rxwebcam_beta/plugins/photo_server/moc_simple_server.cxx > plugins/photo_server/CMakeFiles/pluginphotoserver.dir/moc_simple_server.i

plugins/photo_server/CMakeFiles/pluginphotoserver.dir/moc_simple_server.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly plugins/photo_server/CMakeFiles/pluginphotoserver.dir/moc_simple_server.s"
	/usr/bin/c++  $(CXX_FLAGS) -S /proyect/rxwebcam_beta/plugins/photo_server/moc_simple_server.cxx -o plugins/photo_server/CMakeFiles/pluginphotoserver.dir/moc_simple_server.s

plugins/photo_server/CMakeFiles/pluginphotoserver.dir/moc_simple_server.o.requires:

plugins/photo_server/CMakeFiles/pluginphotoserver.dir/moc_simple_server.o.provides: plugins/photo_server/CMakeFiles/pluginphotoserver.dir/moc_simple_server.o.requires
	$(MAKE) -f plugins/photo_server/CMakeFiles/pluginphotoserver.dir/build.make plugins/photo_server/CMakeFiles/pluginphotoserver.dir/moc_simple_server.o.provides.build

plugins/photo_server/CMakeFiles/pluginphotoserver.dir/moc_simple_server.o.provides.build: plugins/photo_server/CMakeFiles/pluginphotoserver.dir/moc_simple_server.o

plugins/photo_server/CMakeFiles/pluginphotoserver.dir/depend.make.mark: plugins/photo_server/CMakeFiles/pluginphotoserver.dir/flags.make
plugins/photo_server/CMakeFiles/pluginphotoserver.dir/depend.make.mark: plugins/photo_server/moc_ConfigPluginImp.cxx

plugins/photo_server/CMakeFiles/pluginphotoserver.dir/moc_ConfigPluginImp.o: plugins/photo_server/CMakeFiles/pluginphotoserver.dir/flags.make
plugins/photo_server/CMakeFiles/pluginphotoserver.dir/moc_ConfigPluginImp.o: plugins/photo_server/moc_ConfigPluginImp.cxx
	$(CMAKE_COMMAND) -E cmake_progress_report /proyect/rxwebcam_beta/CMakeFiles $(CMAKE_PROGRESS_8)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object plugins/photo_server/CMakeFiles/pluginphotoserver.dir/moc_ConfigPluginImp.o"
	/usr/bin/c++   $(CXX_FLAGS) -o plugins/photo_server/CMakeFiles/pluginphotoserver.dir/moc_ConfigPluginImp.o -c /proyect/rxwebcam_beta/plugins/photo_server/moc_ConfigPluginImp.cxx

plugins/photo_server/CMakeFiles/pluginphotoserver.dir/moc_ConfigPluginImp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to plugins/photo_server/CMakeFiles/pluginphotoserver.dir/moc_ConfigPluginImp.i"
	/usr/bin/c++  $(CXX_FLAGS) -E /proyect/rxwebcam_beta/plugins/photo_server/moc_ConfigPluginImp.cxx > plugins/photo_server/CMakeFiles/pluginphotoserver.dir/moc_ConfigPluginImp.i

plugins/photo_server/CMakeFiles/pluginphotoserver.dir/moc_ConfigPluginImp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly plugins/photo_server/CMakeFiles/pluginphotoserver.dir/moc_ConfigPluginImp.s"
	/usr/bin/c++  $(CXX_FLAGS) -S /proyect/rxwebcam_beta/plugins/photo_server/moc_ConfigPluginImp.cxx -o plugins/photo_server/CMakeFiles/pluginphotoserver.dir/moc_ConfigPluginImp.s

plugins/photo_server/CMakeFiles/pluginphotoserver.dir/moc_ConfigPluginImp.o.requires:

plugins/photo_server/CMakeFiles/pluginphotoserver.dir/moc_ConfigPluginImp.o.provides: plugins/photo_server/CMakeFiles/pluginphotoserver.dir/moc_ConfigPluginImp.o.requires
	$(MAKE) -f plugins/photo_server/CMakeFiles/pluginphotoserver.dir/build.make plugins/photo_server/CMakeFiles/pluginphotoserver.dir/moc_ConfigPluginImp.o.provides.build

plugins/photo_server/CMakeFiles/pluginphotoserver.dir/moc_ConfigPluginImp.o.provides.build: plugins/photo_server/CMakeFiles/pluginphotoserver.dir/moc_ConfigPluginImp.o

plugins/photo_server/moc_plugin_photo_server.cxx: plugins/photo_server/plugin_photo_server.h
	$(CMAKE_COMMAND) -E cmake_progress_report /proyect/rxwebcam_beta/CMakeFiles $(CMAKE_PROGRESS_9)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating moc_plugin_photo_server.cxx"
	cd /proyect/rxwebcam_beta/plugins/photo_server && /usr/lib/qt-4.4.1/bin/moc -I /usr/lib/qt-4.4.1/include -I /usr/lib/qt-4.4.1/include/QtGui -I /usr/lib/qt-4.4.1/include/QtCore -I /proyect/rxwebcam_beta/plugins/photo_server -I /usr/lib/qt-4.4.1/include/QtNetwork -o /proyect/rxwebcam_beta/plugins/photo_server/moc_plugin_photo_server.cxx /proyect/rxwebcam_beta/plugins/photo_server/plugin_photo_server.h

plugins/photo_server/moc_simple_server.cxx: plugins/photo_server/simple_server.h
	$(CMAKE_COMMAND) -E cmake_progress_report /proyect/rxwebcam_beta/CMakeFiles $(CMAKE_PROGRESS_10)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating moc_simple_server.cxx"
	cd /proyect/rxwebcam_beta/plugins/photo_server && /usr/lib/qt-4.4.1/bin/moc -I /usr/lib/qt-4.4.1/include -I /usr/lib/qt-4.4.1/include/QtGui -I /usr/lib/qt-4.4.1/include/QtCore -I /proyect/rxwebcam_beta/plugins/photo_server -I /usr/lib/qt-4.4.1/include/QtNetwork -o /proyect/rxwebcam_beta/plugins/photo_server/moc_simple_server.cxx /proyect/rxwebcam_beta/plugins/photo_server/simple_server.h

plugins/photo_server/moc_ConfigPluginImp.cxx: plugins/photo_server/ui_interfaces/ConfigPluginImp.h
	$(CMAKE_COMMAND) -E cmake_progress_report /proyect/rxwebcam_beta/CMakeFiles $(CMAKE_PROGRESS_11)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating moc_ConfigPluginImp.cxx"
	cd /proyect/rxwebcam_beta/plugins/photo_server && /usr/lib/qt-4.4.1/bin/moc -I /usr/lib/qt-4.4.1/include -I /usr/lib/qt-4.4.1/include/QtGui -I /usr/lib/qt-4.4.1/include/QtCore -I /proyect/rxwebcam_beta/plugins/photo_server -I /usr/lib/qt-4.4.1/include/QtNetwork -o /proyect/rxwebcam_beta/plugins/photo_server/moc_ConfigPluginImp.cxx /proyect/rxwebcam_beta/plugins/photo_server/ui_interfaces/ConfigPluginImp.h

plugins/photo_server/ui_configplugin.h: plugins/photo_server/ui_interfaces/configplugin.ui
	$(CMAKE_COMMAND) -E cmake_progress_report /proyect/rxwebcam_beta/CMakeFiles $(CMAKE_PROGRESS_12)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating ui_configplugin.h"
	cd /proyect/rxwebcam_beta/plugins/photo_server && /usr/lib/qt-4.4.1/bin/uic -o /proyect/rxwebcam_beta/plugins/photo_server/ui_configplugin.h /proyect/rxwebcam_beta/plugins/photo_server/ui_interfaces/configplugin.ui

plugins/photo_server/CMakeFiles/pluginphotoserver.dir/depend: plugins/photo_server/CMakeFiles/pluginphotoserver.dir/depend.make.mark

plugins/photo_server/CMakeFiles/pluginphotoserver.dir/depend.make.mark: plugins/photo_server/moc_plugin_photo_server.cxx
plugins/photo_server/CMakeFiles/pluginphotoserver.dir/depend.make.mark: plugins/photo_server/moc_simple_server.cxx
plugins/photo_server/CMakeFiles/pluginphotoserver.dir/depend.make.mark: plugins/photo_server/moc_ConfigPluginImp.cxx
plugins/photo_server/CMakeFiles/pluginphotoserver.dir/depend.make.mark: plugins/photo_server/ui_configplugin.h
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --magenta --bold "Scanning dependencies of target pluginphotoserver"
	cd /proyect/rxwebcam_beta && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /proyect/rxwebcam_beta /proyect/rxwebcam_beta/plugins/photo_server /proyect/rxwebcam_beta /proyect/rxwebcam_beta/plugins/photo_server /proyect/rxwebcam_beta/plugins/photo_server/CMakeFiles/pluginphotoserver.dir/DependInfo.cmake

# Object files for target pluginphotoserver
pluginphotoserver_OBJECTS = \
"CMakeFiles/pluginphotoserver.dir/thread_server.o" \
"CMakeFiles/pluginphotoserver.dir/plugin_photo_server.o" \
"CMakeFiles/pluginphotoserver.dir/simple_server.o" \
"CMakeFiles/pluginphotoserver.dir/ui_interfaces/ConfigPluginImp.o" \
"CMakeFiles/pluginphotoserver.dir/ui_interfaces/ValidateIp.o" \
"CMakeFiles/pluginphotoserver.dir/moc_plugin_photo_server.o" \
"CMakeFiles/pluginphotoserver.dir/moc_simple_server.o" \
"CMakeFiles/pluginphotoserver.dir/moc_ConfigPluginImp.o"

# External object files for target pluginphotoserver
pluginphotoserver_EXTERNAL_OBJECTS =

plugins/photo_server/libpluginphotoserver.so: plugins/photo_server/CMakeFiles/pluginphotoserver.dir/thread_server.o
plugins/photo_server/libpluginphotoserver.so: plugins/photo_server/CMakeFiles/pluginphotoserver.dir/plugin_photo_server.o
plugins/photo_server/libpluginphotoserver.so: plugins/photo_server/CMakeFiles/pluginphotoserver.dir/simple_server.o
plugins/photo_server/libpluginphotoserver.so: plugins/photo_server/CMakeFiles/pluginphotoserver.dir/ui_interfaces/ConfigPluginImp.o
plugins/photo_server/libpluginphotoserver.so: plugins/photo_server/CMakeFiles/pluginphotoserver.dir/ui_interfaces/ValidateIp.o
plugins/photo_server/libpluginphotoserver.so: plugins/photo_server/CMakeFiles/pluginphotoserver.dir/moc_plugin_photo_server.o
plugins/photo_server/libpluginphotoserver.so: plugins/photo_server/CMakeFiles/pluginphotoserver.dir/moc_simple_server.o
plugins/photo_server/libpluginphotoserver.so: plugins/photo_server/CMakeFiles/pluginphotoserver.dir/moc_ConfigPluginImp.o
plugins/photo_server/libpluginphotoserver.so: /usr/lib/qt-4.4.1/lib/libQtGui.so
plugins/photo_server/libpluginphotoserver.so: /usr/lib/libpng.so
plugins/photo_server/libpluginphotoserver.so: /usr/lib/libSM.so
plugins/photo_server/libpluginphotoserver.so: /usr/lib/libICE.so
plugins/photo_server/libpluginphotoserver.so: /usr/lib/libXi.so
plugins/photo_server/libpluginphotoserver.so: /usr/lib/libXrender.so
plugins/photo_server/libpluginphotoserver.so: /usr/lib/libXrandr.so
plugins/photo_server/libpluginphotoserver.so: /usr/lib/libfreetype.so
plugins/photo_server/libpluginphotoserver.so: /usr/lib/libfontconfig.so
plugins/photo_server/libpluginphotoserver.so: /usr/lib/libXext.so
plugins/photo_server/libpluginphotoserver.so: /usr/lib/libX11.so
plugins/photo_server/libpluginphotoserver.so: /usr/lib/libm.so
plugins/photo_server/libpluginphotoserver.so: /usr/lib/qt-4.4.1/lib/libQtCore.so
plugins/photo_server/libpluginphotoserver.so: /usr/lib/libz.so
plugins/photo_server/libpluginphotoserver.so: /usr/lib/qt-4.4.1/lib/libQtNetwork.so
plugins/photo_server/libpluginphotoserver.so: plugins/photo_server/CMakeFiles/pluginphotoserver.dir/build.make
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared library libpluginphotoserver.so"
	cd /proyect/rxwebcam_beta/plugins/photo_server && $(CMAKE_COMMAND) -P CMakeFiles/pluginphotoserver.dir/cmake_clean_target.cmake
	cd /proyect/rxwebcam_beta/plugins/photo_server && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pluginphotoserver.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
plugins/photo_server/CMakeFiles/pluginphotoserver.dir/build: plugins/photo_server/libpluginphotoserver.so

# Object files for target pluginphotoserver
pluginphotoserver_OBJECTS = \
"CMakeFiles/pluginphotoserver.dir/thread_server.o" \
"CMakeFiles/pluginphotoserver.dir/plugin_photo_server.o" \
"CMakeFiles/pluginphotoserver.dir/simple_server.o" \
"CMakeFiles/pluginphotoserver.dir/ui_interfaces/ConfigPluginImp.o" \
"CMakeFiles/pluginphotoserver.dir/ui_interfaces/ValidateIp.o" \
"CMakeFiles/pluginphotoserver.dir/moc_plugin_photo_server.o" \
"CMakeFiles/pluginphotoserver.dir/moc_simple_server.o" \
"CMakeFiles/pluginphotoserver.dir/moc_ConfigPluginImp.o"

# External object files for target pluginphotoserver
pluginphotoserver_EXTERNAL_OBJECTS =

plugins/photo_server/CMakeFiles/CMakeRelink.dir/libpluginphotoserver.so: plugins/photo_server/CMakeFiles/pluginphotoserver.dir/thread_server.o
plugins/photo_server/CMakeFiles/CMakeRelink.dir/libpluginphotoserver.so: plugins/photo_server/CMakeFiles/pluginphotoserver.dir/plugin_photo_server.o
plugins/photo_server/CMakeFiles/CMakeRelink.dir/libpluginphotoserver.so: plugins/photo_server/CMakeFiles/pluginphotoserver.dir/simple_server.o
plugins/photo_server/CMakeFiles/CMakeRelink.dir/libpluginphotoserver.so: plugins/photo_server/CMakeFiles/pluginphotoserver.dir/ui_interfaces/ConfigPluginImp.o
plugins/photo_server/CMakeFiles/CMakeRelink.dir/libpluginphotoserver.so: plugins/photo_server/CMakeFiles/pluginphotoserver.dir/ui_interfaces/ValidateIp.o
plugins/photo_server/CMakeFiles/CMakeRelink.dir/libpluginphotoserver.so: plugins/photo_server/CMakeFiles/pluginphotoserver.dir/moc_plugin_photo_server.o
plugins/photo_server/CMakeFiles/CMakeRelink.dir/libpluginphotoserver.so: plugins/photo_server/CMakeFiles/pluginphotoserver.dir/moc_simple_server.o
plugins/photo_server/CMakeFiles/CMakeRelink.dir/libpluginphotoserver.so: plugins/photo_server/CMakeFiles/pluginphotoserver.dir/moc_ConfigPluginImp.o
plugins/photo_server/CMakeFiles/CMakeRelink.dir/libpluginphotoserver.so: /usr/lib/qt-4.4.1/lib/libQtGui.so
plugins/photo_server/CMakeFiles/CMakeRelink.dir/libpluginphotoserver.so: /usr/lib/libpng.so
plugins/photo_server/CMakeFiles/CMakeRelink.dir/libpluginphotoserver.so: /usr/lib/libSM.so
plugins/photo_server/CMakeFiles/CMakeRelink.dir/libpluginphotoserver.so: /usr/lib/libICE.so
plugins/photo_server/CMakeFiles/CMakeRelink.dir/libpluginphotoserver.so: /usr/lib/libXi.so
plugins/photo_server/CMakeFiles/CMakeRelink.dir/libpluginphotoserver.so: /usr/lib/libXrender.so
plugins/photo_server/CMakeFiles/CMakeRelink.dir/libpluginphotoserver.so: /usr/lib/libXrandr.so
plugins/photo_server/CMakeFiles/CMakeRelink.dir/libpluginphotoserver.so: /usr/lib/libfreetype.so
plugins/photo_server/CMakeFiles/CMakeRelink.dir/libpluginphotoserver.so: /usr/lib/libfontconfig.so
plugins/photo_server/CMakeFiles/CMakeRelink.dir/libpluginphotoserver.so: /usr/lib/libXext.so
plugins/photo_server/CMakeFiles/CMakeRelink.dir/libpluginphotoserver.so: /usr/lib/libX11.so
plugins/photo_server/CMakeFiles/CMakeRelink.dir/libpluginphotoserver.so: /usr/lib/libm.so
plugins/photo_server/CMakeFiles/CMakeRelink.dir/libpluginphotoserver.so: /usr/lib/qt-4.4.1/lib/libQtCore.so
plugins/photo_server/CMakeFiles/CMakeRelink.dir/libpluginphotoserver.so: /usr/lib/libz.so
plugins/photo_server/CMakeFiles/CMakeRelink.dir/libpluginphotoserver.so: /usr/lib/qt-4.4.1/lib/libQtNetwork.so
plugins/photo_server/CMakeFiles/CMakeRelink.dir/libpluginphotoserver.so: plugins/photo_server/CMakeFiles/pluginphotoserver.dir/build.make
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared library CMakeFiles/CMakeRelink.dir/libpluginphotoserver.so"
	cd /proyect/rxwebcam_beta/plugins/photo_server && $(CMAKE_COMMAND) -P CMakeFiles/pluginphotoserver.dir/cmake_clean_target.cmake
	cd /proyect/rxwebcam_beta/plugins/photo_server && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pluginphotoserver.dir/relink.txt --verbose=$(VERBOSE)

# Rule to relink during preinstall.
plugins/photo_server/CMakeFiles/pluginphotoserver.dir/preinstall: plugins/photo_server/CMakeFiles/CMakeRelink.dir/libpluginphotoserver.so

plugins/photo_server/CMakeFiles/pluginphotoserver.dir/requires: plugins/photo_server/CMakeFiles/pluginphotoserver.dir/thread_server.o.requires
plugins/photo_server/CMakeFiles/pluginphotoserver.dir/requires: plugins/photo_server/CMakeFiles/pluginphotoserver.dir/plugin_photo_server.o.requires
plugins/photo_server/CMakeFiles/pluginphotoserver.dir/requires: plugins/photo_server/CMakeFiles/pluginphotoserver.dir/simple_server.o.requires
plugins/photo_server/CMakeFiles/pluginphotoserver.dir/requires: plugins/photo_server/CMakeFiles/pluginphotoserver.dir/ui_interfaces/ConfigPluginImp.o.requires
plugins/photo_server/CMakeFiles/pluginphotoserver.dir/requires: plugins/photo_server/CMakeFiles/pluginphotoserver.dir/ui_interfaces/ValidateIp.o.requires
plugins/photo_server/CMakeFiles/pluginphotoserver.dir/requires: plugins/photo_server/CMakeFiles/pluginphotoserver.dir/moc_plugin_photo_server.o.requires
plugins/photo_server/CMakeFiles/pluginphotoserver.dir/requires: plugins/photo_server/CMakeFiles/pluginphotoserver.dir/moc_simple_server.o.requires
plugins/photo_server/CMakeFiles/pluginphotoserver.dir/requires: plugins/photo_server/CMakeFiles/pluginphotoserver.dir/moc_ConfigPluginImp.o.requires

plugins/photo_server/CMakeFiles/pluginphotoserver.dir/clean:
	cd /proyect/rxwebcam_beta/plugins/photo_server && $(CMAKE_COMMAND) -P CMakeFiles/pluginphotoserver.dir/cmake_clean.cmake

