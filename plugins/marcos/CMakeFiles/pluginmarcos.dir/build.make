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
include plugins/marcos/CMakeFiles/pluginmarcos.dir/depend.make

# Include the progress variables for this target.
include plugins/marcos/CMakeFiles/pluginmarcos.dir/progress.make

# Include the compile flags for this target's objects.
include plugins/marcos/CMakeFiles/pluginmarcos.dir/flags.make

plugins/marcos/CMakeFiles/pluginmarcos.dir/depend.make.mark: plugins/marcos/CMakeFiles/pluginmarcos.dir/flags.make
plugins/marcos/CMakeFiles/pluginmarcos.dir/depend.make.mark: plugins/marcos/plugin_marcos.cpp

plugins/marcos/CMakeFiles/pluginmarcos.dir/plugin_marcos.o: plugins/marcos/CMakeFiles/pluginmarcos.dir/flags.make
plugins/marcos/CMakeFiles/pluginmarcos.dir/plugin_marcos.o: plugins/marcos/plugin_marcos.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /proyect/rxwebcam_beta/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object plugins/marcos/CMakeFiles/pluginmarcos.dir/plugin_marcos.o"
	/usr/bin/c++   $(CXX_FLAGS) -o plugins/marcos/CMakeFiles/pluginmarcos.dir/plugin_marcos.o -c /proyect/rxwebcam_beta/plugins/marcos/plugin_marcos.cpp

plugins/marcos/CMakeFiles/pluginmarcos.dir/plugin_marcos.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to plugins/marcos/CMakeFiles/pluginmarcos.dir/plugin_marcos.i"
	/usr/bin/c++  $(CXX_FLAGS) -E /proyect/rxwebcam_beta/plugins/marcos/plugin_marcos.cpp > plugins/marcos/CMakeFiles/pluginmarcos.dir/plugin_marcos.i

plugins/marcos/CMakeFiles/pluginmarcos.dir/plugin_marcos.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly plugins/marcos/CMakeFiles/pluginmarcos.dir/plugin_marcos.s"
	/usr/bin/c++  $(CXX_FLAGS) -S /proyect/rxwebcam_beta/plugins/marcos/plugin_marcos.cpp -o plugins/marcos/CMakeFiles/pluginmarcos.dir/plugin_marcos.s

plugins/marcos/CMakeFiles/pluginmarcos.dir/plugin_marcos.o.requires:

plugins/marcos/CMakeFiles/pluginmarcos.dir/plugin_marcos.o.provides: plugins/marcos/CMakeFiles/pluginmarcos.dir/plugin_marcos.o.requires
	$(MAKE) -f plugins/marcos/CMakeFiles/pluginmarcos.dir/build.make plugins/marcos/CMakeFiles/pluginmarcos.dir/plugin_marcos.o.provides.build

plugins/marcos/CMakeFiles/pluginmarcos.dir/plugin_marcos.o.provides.build: plugins/marcos/CMakeFiles/pluginmarcos.dir/plugin_marcos.o

plugins/marcos/CMakeFiles/pluginmarcos.dir/depend.make.mark: plugins/marcos/CMakeFiles/pluginmarcos.dir/flags.make
plugins/marcos/CMakeFiles/pluginmarcos.dir/depend.make.mark: plugins/marcos/ui_interfaces/ConfigPluginImp.cpp

plugins/marcos/CMakeFiles/pluginmarcos.dir/ui_interfaces/ConfigPluginImp.o: plugins/marcos/CMakeFiles/pluginmarcos.dir/flags.make
plugins/marcos/CMakeFiles/pluginmarcos.dir/ui_interfaces/ConfigPluginImp.o: plugins/marcos/ui_interfaces/ConfigPluginImp.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /proyect/rxwebcam_beta/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object plugins/marcos/CMakeFiles/pluginmarcos.dir/ui_interfaces/ConfigPluginImp.o"
	/usr/bin/c++   $(CXX_FLAGS) -o plugins/marcos/CMakeFiles/pluginmarcos.dir/ui_interfaces/ConfigPluginImp.o -c /proyect/rxwebcam_beta/plugins/marcos/ui_interfaces/ConfigPluginImp.cpp

plugins/marcos/CMakeFiles/pluginmarcos.dir/ui_interfaces/ConfigPluginImp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to plugins/marcos/CMakeFiles/pluginmarcos.dir/ui_interfaces/ConfigPluginImp.i"
	/usr/bin/c++  $(CXX_FLAGS) -E /proyect/rxwebcam_beta/plugins/marcos/ui_interfaces/ConfigPluginImp.cpp > plugins/marcos/CMakeFiles/pluginmarcos.dir/ui_interfaces/ConfigPluginImp.i

plugins/marcos/CMakeFiles/pluginmarcos.dir/ui_interfaces/ConfigPluginImp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly plugins/marcos/CMakeFiles/pluginmarcos.dir/ui_interfaces/ConfigPluginImp.s"
	/usr/bin/c++  $(CXX_FLAGS) -S /proyect/rxwebcam_beta/plugins/marcos/ui_interfaces/ConfigPluginImp.cpp -o plugins/marcos/CMakeFiles/pluginmarcos.dir/ui_interfaces/ConfigPluginImp.s

plugins/marcos/CMakeFiles/pluginmarcos.dir/ui_interfaces/ConfigPluginImp.o.requires:

plugins/marcos/CMakeFiles/pluginmarcos.dir/ui_interfaces/ConfigPluginImp.o.provides: plugins/marcos/CMakeFiles/pluginmarcos.dir/ui_interfaces/ConfigPluginImp.o.requires
	$(MAKE) -f plugins/marcos/CMakeFiles/pluginmarcos.dir/build.make plugins/marcos/CMakeFiles/pluginmarcos.dir/ui_interfaces/ConfigPluginImp.o.provides.build

plugins/marcos/CMakeFiles/pluginmarcos.dir/ui_interfaces/ConfigPluginImp.o.provides.build: plugins/marcos/CMakeFiles/pluginmarcos.dir/ui_interfaces/ConfigPluginImp.o

plugins/marcos/CMakeFiles/pluginmarcos.dir/depend.make.mark: plugins/marcos/CMakeFiles/pluginmarcos.dir/flags.make
plugins/marcos/CMakeFiles/pluginmarcos.dir/depend.make.mark: plugins/marcos/moc_plugin_marcos.cxx

plugins/marcos/CMakeFiles/pluginmarcos.dir/moc_plugin_marcos.o: plugins/marcos/CMakeFiles/pluginmarcos.dir/flags.make
plugins/marcos/CMakeFiles/pluginmarcos.dir/moc_plugin_marcos.o: plugins/marcos/moc_plugin_marcos.cxx
	$(CMAKE_COMMAND) -E cmake_progress_report /proyect/rxwebcam_beta/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object plugins/marcos/CMakeFiles/pluginmarcos.dir/moc_plugin_marcos.o"
	/usr/bin/c++   $(CXX_FLAGS) -o plugins/marcos/CMakeFiles/pluginmarcos.dir/moc_plugin_marcos.o -c /proyect/rxwebcam_beta/plugins/marcos/moc_plugin_marcos.cxx

plugins/marcos/CMakeFiles/pluginmarcos.dir/moc_plugin_marcos.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to plugins/marcos/CMakeFiles/pluginmarcos.dir/moc_plugin_marcos.i"
	/usr/bin/c++  $(CXX_FLAGS) -E /proyect/rxwebcam_beta/plugins/marcos/moc_plugin_marcos.cxx > plugins/marcos/CMakeFiles/pluginmarcos.dir/moc_plugin_marcos.i

plugins/marcos/CMakeFiles/pluginmarcos.dir/moc_plugin_marcos.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly plugins/marcos/CMakeFiles/pluginmarcos.dir/moc_plugin_marcos.s"
	/usr/bin/c++  $(CXX_FLAGS) -S /proyect/rxwebcam_beta/plugins/marcos/moc_plugin_marcos.cxx -o plugins/marcos/CMakeFiles/pluginmarcos.dir/moc_plugin_marcos.s

plugins/marcos/CMakeFiles/pluginmarcos.dir/moc_plugin_marcos.o.requires:

plugins/marcos/CMakeFiles/pluginmarcos.dir/moc_plugin_marcos.o.provides: plugins/marcos/CMakeFiles/pluginmarcos.dir/moc_plugin_marcos.o.requires
	$(MAKE) -f plugins/marcos/CMakeFiles/pluginmarcos.dir/build.make plugins/marcos/CMakeFiles/pluginmarcos.dir/moc_plugin_marcos.o.provides.build

plugins/marcos/CMakeFiles/pluginmarcos.dir/moc_plugin_marcos.o.provides.build: plugins/marcos/CMakeFiles/pluginmarcos.dir/moc_plugin_marcos.o

plugins/marcos/CMakeFiles/pluginmarcos.dir/depend.make.mark: plugins/marcos/CMakeFiles/pluginmarcos.dir/flags.make
plugins/marcos/CMakeFiles/pluginmarcos.dir/depend.make.mark: plugins/marcos/moc_ConfigPluginImp.cxx

plugins/marcos/CMakeFiles/pluginmarcos.dir/moc_ConfigPluginImp.o: plugins/marcos/CMakeFiles/pluginmarcos.dir/flags.make
plugins/marcos/CMakeFiles/pluginmarcos.dir/moc_ConfigPluginImp.o: plugins/marcos/moc_ConfigPluginImp.cxx
	$(CMAKE_COMMAND) -E cmake_progress_report /proyect/rxwebcam_beta/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object plugins/marcos/CMakeFiles/pluginmarcos.dir/moc_ConfigPluginImp.o"
	/usr/bin/c++   $(CXX_FLAGS) -o plugins/marcos/CMakeFiles/pluginmarcos.dir/moc_ConfigPluginImp.o -c /proyect/rxwebcam_beta/plugins/marcos/moc_ConfigPluginImp.cxx

plugins/marcos/CMakeFiles/pluginmarcos.dir/moc_ConfigPluginImp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to plugins/marcos/CMakeFiles/pluginmarcos.dir/moc_ConfigPluginImp.i"
	/usr/bin/c++  $(CXX_FLAGS) -E /proyect/rxwebcam_beta/plugins/marcos/moc_ConfigPluginImp.cxx > plugins/marcos/CMakeFiles/pluginmarcos.dir/moc_ConfigPluginImp.i

plugins/marcos/CMakeFiles/pluginmarcos.dir/moc_ConfigPluginImp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly plugins/marcos/CMakeFiles/pluginmarcos.dir/moc_ConfigPluginImp.s"
	/usr/bin/c++  $(CXX_FLAGS) -S /proyect/rxwebcam_beta/plugins/marcos/moc_ConfigPluginImp.cxx -o plugins/marcos/CMakeFiles/pluginmarcos.dir/moc_ConfigPluginImp.s

plugins/marcos/CMakeFiles/pluginmarcos.dir/moc_ConfigPluginImp.o.requires:

plugins/marcos/CMakeFiles/pluginmarcos.dir/moc_ConfigPluginImp.o.provides: plugins/marcos/CMakeFiles/pluginmarcos.dir/moc_ConfigPluginImp.o.requires
	$(MAKE) -f plugins/marcos/CMakeFiles/pluginmarcos.dir/build.make plugins/marcos/CMakeFiles/pluginmarcos.dir/moc_ConfigPluginImp.o.provides.build

plugins/marcos/CMakeFiles/pluginmarcos.dir/moc_ConfigPluginImp.o.provides.build: plugins/marcos/CMakeFiles/pluginmarcos.dir/moc_ConfigPluginImp.o

plugins/marcos/moc_plugin_marcos.cxx: plugins/marcos/plugin_marcos.h
	$(CMAKE_COMMAND) -E cmake_progress_report /proyect/rxwebcam_beta/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating moc_plugin_marcos.cxx"
	cd /proyect/rxwebcam_beta/plugins/marcos && /usr/lib/qt-4.4.1/bin/moc -I /usr/lib/qt-4.4.1/include -I /usr/lib/qt-4.4.1/include/QtGui -I /usr/lib/qt-4.4.1/include/QtCore -I /proyect/rxwebcam_beta/plugins/marcos -o /proyect/rxwebcam_beta/plugins/marcos/moc_plugin_marcos.cxx /proyect/rxwebcam_beta/plugins/marcos/plugin_marcos.h

plugins/marcos/moc_ConfigPluginImp.cxx: plugins/marcos/ui_interfaces/ConfigPluginImp.h
	$(CMAKE_COMMAND) -E cmake_progress_report /proyect/rxwebcam_beta/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating moc_ConfigPluginImp.cxx"
	cd /proyect/rxwebcam_beta/plugins/marcos && /usr/lib/qt-4.4.1/bin/moc -I /usr/lib/qt-4.4.1/include -I /usr/lib/qt-4.4.1/include/QtGui -I /usr/lib/qt-4.4.1/include/QtCore -I /proyect/rxwebcam_beta/plugins/marcos -o /proyect/rxwebcam_beta/plugins/marcos/moc_ConfigPluginImp.cxx /proyect/rxwebcam_beta/plugins/marcos/ui_interfaces/ConfigPluginImp.h

plugins/marcos/ui_configplugin.h: plugins/marcos/ui_interfaces/configplugin.ui
	$(CMAKE_COMMAND) -E cmake_progress_report /proyect/rxwebcam_beta/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating ui_configplugin.h"
	cd /proyect/rxwebcam_beta/plugins/marcos && /usr/lib/qt-4.4.1/bin/uic -o /proyect/rxwebcam_beta/plugins/marcos/ui_configplugin.h /proyect/rxwebcam_beta/plugins/marcos/ui_interfaces/configplugin.ui

plugins/marcos/CMakeFiles/pluginmarcos.dir/depend: plugins/marcos/CMakeFiles/pluginmarcos.dir/depend.make.mark

plugins/marcos/CMakeFiles/pluginmarcos.dir/depend.make.mark: plugins/marcos/moc_plugin_marcos.cxx
plugins/marcos/CMakeFiles/pluginmarcos.dir/depend.make.mark: plugins/marcos/moc_ConfigPluginImp.cxx
plugins/marcos/CMakeFiles/pluginmarcos.dir/depend.make.mark: plugins/marcos/ui_configplugin.h
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --magenta --bold "Scanning dependencies of target pluginmarcos"
	cd /proyect/rxwebcam_beta && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /proyect/rxwebcam_beta /proyect/rxwebcam_beta/plugins/marcos /proyect/rxwebcam_beta /proyect/rxwebcam_beta/plugins/marcos /proyect/rxwebcam_beta/plugins/marcos/CMakeFiles/pluginmarcos.dir/DependInfo.cmake

# Object files for target pluginmarcos
pluginmarcos_OBJECTS = \
"CMakeFiles/pluginmarcos.dir/plugin_marcos.o" \
"CMakeFiles/pluginmarcos.dir/ui_interfaces/ConfigPluginImp.o" \
"CMakeFiles/pluginmarcos.dir/moc_plugin_marcos.o" \
"CMakeFiles/pluginmarcos.dir/moc_ConfigPluginImp.o"

# External object files for target pluginmarcos
pluginmarcos_EXTERNAL_OBJECTS =

plugins/marcos/libpluginmarcos.so: plugins/marcos/CMakeFiles/pluginmarcos.dir/plugin_marcos.o
plugins/marcos/libpluginmarcos.so: plugins/marcos/CMakeFiles/pluginmarcos.dir/ui_interfaces/ConfigPluginImp.o
plugins/marcos/libpluginmarcos.so: plugins/marcos/CMakeFiles/pluginmarcos.dir/moc_plugin_marcos.o
plugins/marcos/libpluginmarcos.so: plugins/marcos/CMakeFiles/pluginmarcos.dir/moc_ConfigPluginImp.o
plugins/marcos/libpluginmarcos.so: /usr/lib/qt-4.4.1/lib/libQtGui.so
plugins/marcos/libpluginmarcos.so: /usr/lib/libpng.so
plugins/marcos/libpluginmarcos.so: /usr/lib/libSM.so
plugins/marcos/libpluginmarcos.so: /usr/lib/libICE.so
plugins/marcos/libpluginmarcos.so: /usr/lib/libXi.so
plugins/marcos/libpluginmarcos.so: /usr/lib/libXrender.so
plugins/marcos/libpluginmarcos.so: /usr/lib/libXrandr.so
plugins/marcos/libpluginmarcos.so: /usr/lib/libfreetype.so
plugins/marcos/libpluginmarcos.so: /usr/lib/libfontconfig.so
plugins/marcos/libpluginmarcos.so: /usr/lib/libXext.so
plugins/marcos/libpluginmarcos.so: /usr/lib/libX11.so
plugins/marcos/libpluginmarcos.so: /usr/lib/libm.so
plugins/marcos/libpluginmarcos.so: /usr/lib/qt-4.4.1/lib/libQtCore.so
plugins/marcos/libpluginmarcos.so: /usr/lib/libz.so
plugins/marcos/libpluginmarcos.so: plugins/marcos/CMakeFiles/pluginmarcos.dir/build.make
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared library libpluginmarcos.so"
	cd /proyect/rxwebcam_beta/plugins/marcos && $(CMAKE_COMMAND) -P CMakeFiles/pluginmarcos.dir/cmake_clean_target.cmake
	cd /proyect/rxwebcam_beta/plugins/marcos && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pluginmarcos.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
plugins/marcos/CMakeFiles/pluginmarcos.dir/build: plugins/marcos/libpluginmarcos.so

# Object files for target pluginmarcos
pluginmarcos_OBJECTS = \
"CMakeFiles/pluginmarcos.dir/plugin_marcos.o" \
"CMakeFiles/pluginmarcos.dir/ui_interfaces/ConfigPluginImp.o" \
"CMakeFiles/pluginmarcos.dir/moc_plugin_marcos.o" \
"CMakeFiles/pluginmarcos.dir/moc_ConfigPluginImp.o"

# External object files for target pluginmarcos
pluginmarcos_EXTERNAL_OBJECTS =

plugins/marcos/CMakeFiles/CMakeRelink.dir/libpluginmarcos.so: plugins/marcos/CMakeFiles/pluginmarcos.dir/plugin_marcos.o
plugins/marcos/CMakeFiles/CMakeRelink.dir/libpluginmarcos.so: plugins/marcos/CMakeFiles/pluginmarcos.dir/ui_interfaces/ConfigPluginImp.o
plugins/marcos/CMakeFiles/CMakeRelink.dir/libpluginmarcos.so: plugins/marcos/CMakeFiles/pluginmarcos.dir/moc_plugin_marcos.o
plugins/marcos/CMakeFiles/CMakeRelink.dir/libpluginmarcos.so: plugins/marcos/CMakeFiles/pluginmarcos.dir/moc_ConfigPluginImp.o
plugins/marcos/CMakeFiles/CMakeRelink.dir/libpluginmarcos.so: /usr/lib/qt-4.4.1/lib/libQtGui.so
plugins/marcos/CMakeFiles/CMakeRelink.dir/libpluginmarcos.so: /usr/lib/libpng.so
plugins/marcos/CMakeFiles/CMakeRelink.dir/libpluginmarcos.so: /usr/lib/libSM.so
plugins/marcos/CMakeFiles/CMakeRelink.dir/libpluginmarcos.so: /usr/lib/libICE.so
plugins/marcos/CMakeFiles/CMakeRelink.dir/libpluginmarcos.so: /usr/lib/libXi.so
plugins/marcos/CMakeFiles/CMakeRelink.dir/libpluginmarcos.so: /usr/lib/libXrender.so
plugins/marcos/CMakeFiles/CMakeRelink.dir/libpluginmarcos.so: /usr/lib/libXrandr.so
plugins/marcos/CMakeFiles/CMakeRelink.dir/libpluginmarcos.so: /usr/lib/libfreetype.so
plugins/marcos/CMakeFiles/CMakeRelink.dir/libpluginmarcos.so: /usr/lib/libfontconfig.so
plugins/marcos/CMakeFiles/CMakeRelink.dir/libpluginmarcos.so: /usr/lib/libXext.so
plugins/marcos/CMakeFiles/CMakeRelink.dir/libpluginmarcos.so: /usr/lib/libX11.so
plugins/marcos/CMakeFiles/CMakeRelink.dir/libpluginmarcos.so: /usr/lib/libm.so
plugins/marcos/CMakeFiles/CMakeRelink.dir/libpluginmarcos.so: /usr/lib/qt-4.4.1/lib/libQtCore.so
plugins/marcos/CMakeFiles/CMakeRelink.dir/libpluginmarcos.so: /usr/lib/libz.so
plugins/marcos/CMakeFiles/CMakeRelink.dir/libpluginmarcos.so: plugins/marcos/CMakeFiles/pluginmarcos.dir/build.make
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared library CMakeFiles/CMakeRelink.dir/libpluginmarcos.so"
	cd /proyect/rxwebcam_beta/plugins/marcos && $(CMAKE_COMMAND) -P CMakeFiles/pluginmarcos.dir/cmake_clean_target.cmake
	cd /proyect/rxwebcam_beta/plugins/marcos && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pluginmarcos.dir/relink.txt --verbose=$(VERBOSE)

# Rule to relink during preinstall.
plugins/marcos/CMakeFiles/pluginmarcos.dir/preinstall: plugins/marcos/CMakeFiles/CMakeRelink.dir/libpluginmarcos.so

plugins/marcos/CMakeFiles/pluginmarcos.dir/requires: plugins/marcos/CMakeFiles/pluginmarcos.dir/plugin_marcos.o.requires
plugins/marcos/CMakeFiles/pluginmarcos.dir/requires: plugins/marcos/CMakeFiles/pluginmarcos.dir/ui_interfaces/ConfigPluginImp.o.requires
plugins/marcos/CMakeFiles/pluginmarcos.dir/requires: plugins/marcos/CMakeFiles/pluginmarcos.dir/moc_plugin_marcos.o.requires
plugins/marcos/CMakeFiles/pluginmarcos.dir/requires: plugins/marcos/CMakeFiles/pluginmarcos.dir/moc_ConfigPluginImp.o.requires

plugins/marcos/CMakeFiles/pluginmarcos.dir/clean:
	cd /proyect/rxwebcam_beta/plugins/marcos && $(CMAKE_COMMAND) -P CMakeFiles/pluginmarcos.dir/cmake_clean.cmake

