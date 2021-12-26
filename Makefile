# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_SOURCE_DIR = /home/einar/skole/swapk-exam

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/einar/skole/swapk-exam

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/einar/skole/swapk-exam/CMakeFiles /home/einar/skole/swapk-exam/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/einar/skole/swapk-exam/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named swapk_exam

# Build rule for target.
swapk_exam: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 swapk_exam
.PHONY : swapk_exam

# fast build rule for target.
swapk_exam/fast:
	$(MAKE) -f CMakeFiles/swapk_exam.dir/build.make CMakeFiles/swapk_exam.dir/build
.PHONY : swapk_exam/fast

RESTBuilder.o: RESTBuilder.cpp.o

.PHONY : RESTBuilder.o

# target to build an object file
RESTBuilder.cpp.o:
	$(MAKE) -f CMakeFiles/swapk_exam.dir/build.make CMakeFiles/swapk_exam.dir/RESTBuilder.cpp.o
.PHONY : RESTBuilder.cpp.o

RESTBuilder.i: RESTBuilder.cpp.i

.PHONY : RESTBuilder.i

# target to preprocess a source file
RESTBuilder.cpp.i:
	$(MAKE) -f CMakeFiles/swapk_exam.dir/build.make CMakeFiles/swapk_exam.dir/RESTBuilder.cpp.i
.PHONY : RESTBuilder.cpp.i

RESTBuilder.s: RESTBuilder.cpp.s

.PHONY : RESTBuilder.s

# target to generate assembly for a file
RESTBuilder.cpp.s:
	$(MAKE) -f CMakeFiles/swapk_exam.dir/build.make CMakeFiles/swapk_exam.dir/RESTBuilder.cpp.s
.PHONY : RESTBuilder.cpp.s

controller-examples/WeatherController.o: controller-examples/WeatherController.cpp.o

.PHONY : controller-examples/WeatherController.o

# target to build an object file
controller-examples/WeatherController.cpp.o:
	$(MAKE) -f CMakeFiles/swapk_exam.dir/build.make CMakeFiles/swapk_exam.dir/controller-examples/WeatherController.cpp.o
.PHONY : controller-examples/WeatherController.cpp.o

controller-examples/WeatherController.i: controller-examples/WeatherController.cpp.i

.PHONY : controller-examples/WeatherController.i

# target to preprocess a source file
controller-examples/WeatherController.cpp.i:
	$(MAKE) -f CMakeFiles/swapk_exam.dir/build.make CMakeFiles/swapk_exam.dir/controller-examples/WeatherController.cpp.i
.PHONY : controller-examples/WeatherController.cpp.i

controller-examples/WeatherController.s: controller-examples/WeatherController.cpp.s

.PHONY : controller-examples/WeatherController.s

# target to generate assembly for a file
controller-examples/WeatherController.cpp.s:
	$(MAKE) -f CMakeFiles/swapk_exam.dir/build.make CMakeFiles/swapk_exam.dir/controller-examples/WeatherController.cpp.s
.PHONY : controller-examples/WeatherController.cpp.s

dispatch/Dispatcher.o: dispatch/Dispatcher.cpp.o

.PHONY : dispatch/Dispatcher.o

# target to build an object file
dispatch/Dispatcher.cpp.o:
	$(MAKE) -f CMakeFiles/swapk_exam.dir/build.make CMakeFiles/swapk_exam.dir/dispatch/Dispatcher.cpp.o
.PHONY : dispatch/Dispatcher.cpp.o

dispatch/Dispatcher.i: dispatch/Dispatcher.cpp.i

.PHONY : dispatch/Dispatcher.i

# target to preprocess a source file
dispatch/Dispatcher.cpp.i:
	$(MAKE) -f CMakeFiles/swapk_exam.dir/build.make CMakeFiles/swapk_exam.dir/dispatch/Dispatcher.cpp.i
.PHONY : dispatch/Dispatcher.cpp.i

dispatch/Dispatcher.s: dispatch/Dispatcher.cpp.s

.PHONY : dispatch/Dispatcher.s

# target to generate assembly for a file
dispatch/Dispatcher.cpp.s:
	$(MAKE) -f CMakeFiles/swapk_exam.dir/build.make CMakeFiles/swapk_exam.dir/dispatch/Dispatcher.cpp.s
.PHONY : dispatch/Dispatcher.cpp.s

exception/ExceptionHandler.o: exception/ExceptionHandler.cpp.o

.PHONY : exception/ExceptionHandler.o

# target to build an object file
exception/ExceptionHandler.cpp.o:
	$(MAKE) -f CMakeFiles/swapk_exam.dir/build.make CMakeFiles/swapk_exam.dir/exception/ExceptionHandler.cpp.o
.PHONY : exception/ExceptionHandler.cpp.o

exception/ExceptionHandler.i: exception/ExceptionHandler.cpp.i

.PHONY : exception/ExceptionHandler.i

# target to preprocess a source file
exception/ExceptionHandler.cpp.i:
	$(MAKE) -f CMakeFiles/swapk_exam.dir/build.make CMakeFiles/swapk_exam.dir/exception/ExceptionHandler.cpp.i
.PHONY : exception/ExceptionHandler.cpp.i

exception/ExceptionHandler.s: exception/ExceptionHandler.cpp.s

.PHONY : exception/ExceptionHandler.s

# target to generate assembly for a file
exception/ExceptionHandler.cpp.s:
	$(MAKE) -f CMakeFiles/swapk_exam.dir/build.make CMakeFiles/swapk_exam.dir/exception/ExceptionHandler.cpp.s
.PHONY : exception/ExceptionHandler.cpp.s

exception/defaults/endpoint_not_found_exception.o: exception/defaults/endpoint_not_found_exception.cpp.o

.PHONY : exception/defaults/endpoint_not_found_exception.o

# target to build an object file
exception/defaults/endpoint_not_found_exception.cpp.o:
	$(MAKE) -f CMakeFiles/swapk_exam.dir/build.make CMakeFiles/swapk_exam.dir/exception/defaults/endpoint_not_found_exception.cpp.o
.PHONY : exception/defaults/endpoint_not_found_exception.cpp.o

exception/defaults/endpoint_not_found_exception.i: exception/defaults/endpoint_not_found_exception.cpp.i

.PHONY : exception/defaults/endpoint_not_found_exception.i

# target to preprocess a source file
exception/defaults/endpoint_not_found_exception.cpp.i:
	$(MAKE) -f CMakeFiles/swapk_exam.dir/build.make CMakeFiles/swapk_exam.dir/exception/defaults/endpoint_not_found_exception.cpp.i
.PHONY : exception/defaults/endpoint_not_found_exception.cpp.i

exception/defaults/endpoint_not_found_exception.s: exception/defaults/endpoint_not_found_exception.cpp.s

.PHONY : exception/defaults/endpoint_not_found_exception.s

# target to generate assembly for a file
exception/defaults/endpoint_not_found_exception.cpp.s:
	$(MAKE) -f CMakeFiles/swapk_exam.dir/build.make CMakeFiles/swapk_exam.dir/exception/defaults/endpoint_not_found_exception.cpp.s
.PHONY : exception/defaults/endpoint_not_found_exception.cpp.s

exception/defaults/method_not_allowed_exception.o: exception/defaults/method_not_allowed_exception.cpp.o

.PHONY : exception/defaults/method_not_allowed_exception.o

# target to build an object file
exception/defaults/method_not_allowed_exception.cpp.o:
	$(MAKE) -f CMakeFiles/swapk_exam.dir/build.make CMakeFiles/swapk_exam.dir/exception/defaults/method_not_allowed_exception.cpp.o
.PHONY : exception/defaults/method_not_allowed_exception.cpp.o

exception/defaults/method_not_allowed_exception.i: exception/defaults/method_not_allowed_exception.cpp.i

.PHONY : exception/defaults/method_not_allowed_exception.i

# target to preprocess a source file
exception/defaults/method_not_allowed_exception.cpp.i:
	$(MAKE) -f CMakeFiles/swapk_exam.dir/build.make CMakeFiles/swapk_exam.dir/exception/defaults/method_not_allowed_exception.cpp.i
.PHONY : exception/defaults/method_not_allowed_exception.cpp.i

exception/defaults/method_not_allowed_exception.s: exception/defaults/method_not_allowed_exception.cpp.s

.PHONY : exception/defaults/method_not_allowed_exception.s

# target to generate assembly for a file
exception/defaults/method_not_allowed_exception.cpp.s:
	$(MAKE) -f CMakeFiles/swapk_exam.dir/build.make CMakeFiles/swapk_exam.dir/exception/defaults/method_not_allowed_exception.cpp.s
.PHONY : exception/defaults/method_not_allowed_exception.cpp.s

exception/defaults/parse_failure_exception.o: exception/defaults/parse_failure_exception.cpp.o

.PHONY : exception/defaults/parse_failure_exception.o

# target to build an object file
exception/defaults/parse_failure_exception.cpp.o:
	$(MAKE) -f CMakeFiles/swapk_exam.dir/build.make CMakeFiles/swapk_exam.dir/exception/defaults/parse_failure_exception.cpp.o
.PHONY : exception/defaults/parse_failure_exception.cpp.o

exception/defaults/parse_failure_exception.i: exception/defaults/parse_failure_exception.cpp.i

.PHONY : exception/defaults/parse_failure_exception.i

# target to preprocess a source file
exception/defaults/parse_failure_exception.cpp.i:
	$(MAKE) -f CMakeFiles/swapk_exam.dir/build.make CMakeFiles/swapk_exam.dir/exception/defaults/parse_failure_exception.cpp.i
.PHONY : exception/defaults/parse_failure_exception.cpp.i

exception/defaults/parse_failure_exception.s: exception/defaults/parse_failure_exception.cpp.s

.PHONY : exception/defaults/parse_failure_exception.s

# target to generate assembly for a file
exception/defaults/parse_failure_exception.cpp.s:
	$(MAKE) -f CMakeFiles/swapk_exam.dir/build.make CMakeFiles/swapk_exam.dir/exception/defaults/parse_failure_exception.cpp.s
.PHONY : exception/defaults/parse_failure_exception.cpp.s

http/HTTPCallParser.o: http/HTTPCallParser.cpp.o

.PHONY : http/HTTPCallParser.o

# target to build an object file
http/HTTPCallParser.cpp.o:
	$(MAKE) -f CMakeFiles/swapk_exam.dir/build.make CMakeFiles/swapk_exam.dir/http/HTTPCallParser.cpp.o
.PHONY : http/HTTPCallParser.cpp.o

http/HTTPCallParser.i: http/HTTPCallParser.cpp.i

.PHONY : http/HTTPCallParser.i

# target to preprocess a source file
http/HTTPCallParser.cpp.i:
	$(MAKE) -f CMakeFiles/swapk_exam.dir/build.make CMakeFiles/swapk_exam.dir/http/HTTPCallParser.cpp.i
.PHONY : http/HTTPCallParser.cpp.i

http/HTTPCallParser.s: http/HTTPCallParser.cpp.s

.PHONY : http/HTTPCallParser.s

# target to generate assembly for a file
http/HTTPCallParser.cpp.s:
	$(MAKE) -f CMakeFiles/swapk_exam.dir/build.make CMakeFiles/swapk_exam.dir/http/HTTPCallParser.cpp.s
.PHONY : http/HTTPCallParser.cpp.s

http/HTTPEnums.o: http/HTTPEnums.cpp.o

.PHONY : http/HTTPEnums.o

# target to build an object file
http/HTTPEnums.cpp.o:
	$(MAKE) -f CMakeFiles/swapk_exam.dir/build.make CMakeFiles/swapk_exam.dir/http/HTTPEnums.cpp.o
.PHONY : http/HTTPEnums.cpp.o

http/HTTPEnums.i: http/HTTPEnums.cpp.i

.PHONY : http/HTTPEnums.i

# target to preprocess a source file
http/HTTPEnums.cpp.i:
	$(MAKE) -f CMakeFiles/swapk_exam.dir/build.make CMakeFiles/swapk_exam.dir/http/HTTPEnums.cpp.i
.PHONY : http/HTTPEnums.cpp.i

http/HTTPEnums.s: http/HTTPEnums.cpp.s

.PHONY : http/HTTPEnums.s

# target to generate assembly for a file
http/HTTPEnums.cpp.s:
	$(MAKE) -f CMakeFiles/swapk_exam.dir/build.make CMakeFiles/swapk_exam.dir/http/HTTPEnums.cpp.s
.PHONY : http/HTTPEnums.cpp.s

http/details/HTTPCallHandler.o: http/details/HTTPCallHandler.cpp.o

.PHONY : http/details/HTTPCallHandler.o

# target to build an object file
http/details/HTTPCallHandler.cpp.o:
	$(MAKE) -f CMakeFiles/swapk_exam.dir/build.make CMakeFiles/swapk_exam.dir/http/details/HTTPCallHandler.cpp.o
.PHONY : http/details/HTTPCallHandler.cpp.o

http/details/HTTPCallHandler.i: http/details/HTTPCallHandler.cpp.i

.PHONY : http/details/HTTPCallHandler.i

# target to preprocess a source file
http/details/HTTPCallHandler.cpp.i:
	$(MAKE) -f CMakeFiles/swapk_exam.dir/build.make CMakeFiles/swapk_exam.dir/http/details/HTTPCallHandler.cpp.i
.PHONY : http/details/HTTPCallHandler.cpp.i

http/details/HTTPCallHandler.s: http/details/HTTPCallHandler.cpp.s

.PHONY : http/details/HTTPCallHandler.s

# target to generate assembly for a file
http/details/HTTPCallHandler.cpp.s:
	$(MAKE) -f CMakeFiles/swapk_exam.dir/build.make CMakeFiles/swapk_exam.dir/http/details/HTTPCallHandler.cpp.s
.PHONY : http/details/HTTPCallHandler.cpp.s

main.o: main.cpp.o

.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) -f CMakeFiles/swapk_exam.dir/build.make CMakeFiles/swapk_exam.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i

.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) -f CMakeFiles/swapk_exam.dir/build.make CMakeFiles/swapk_exam.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s

.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) -f CMakeFiles/swapk_exam.dir/build.make CMakeFiles/swapk_exam.dir/main.cpp.s
.PHONY : main.cpp.s

socket/SocketConnection.o: socket/SocketConnection.cpp.o

.PHONY : socket/SocketConnection.o

# target to build an object file
socket/SocketConnection.cpp.o:
	$(MAKE) -f CMakeFiles/swapk_exam.dir/build.make CMakeFiles/swapk_exam.dir/socket/SocketConnection.cpp.o
.PHONY : socket/SocketConnection.cpp.o

socket/SocketConnection.i: socket/SocketConnection.cpp.i

.PHONY : socket/SocketConnection.i

# target to preprocess a source file
socket/SocketConnection.cpp.i:
	$(MAKE) -f CMakeFiles/swapk_exam.dir/build.make CMakeFiles/swapk_exam.dir/socket/SocketConnection.cpp.i
.PHONY : socket/SocketConnection.cpp.i

socket/SocketConnection.s: socket/SocketConnection.cpp.s

.PHONY : socket/SocketConnection.s

# target to generate assembly for a file
socket/SocketConnection.cpp.s:
	$(MAKE) -f CMakeFiles/swapk_exam.dir/build.make CMakeFiles/swapk_exam.dir/socket/SocketConnection.cpp.s
.PHONY : socket/SocketConnection.cpp.s

socket/SocketListener.o: socket/SocketListener.cpp.o

.PHONY : socket/SocketListener.o

# target to build an object file
socket/SocketListener.cpp.o:
	$(MAKE) -f CMakeFiles/swapk_exam.dir/build.make CMakeFiles/swapk_exam.dir/socket/SocketListener.cpp.o
.PHONY : socket/SocketListener.cpp.o

socket/SocketListener.i: socket/SocketListener.cpp.i

.PHONY : socket/SocketListener.i

# target to preprocess a source file
socket/SocketListener.cpp.i:
	$(MAKE) -f CMakeFiles/swapk_exam.dir/build.make CMakeFiles/swapk_exam.dir/socket/SocketListener.cpp.i
.PHONY : socket/SocketListener.cpp.i

socket/SocketListener.s: socket/SocketListener.cpp.s

.PHONY : socket/SocketListener.s

# target to generate assembly for a file
socket/SocketListener.cpp.s:
	$(MAKE) -f CMakeFiles/swapk_exam.dir/build.make CMakeFiles/swapk_exam.dir/socket/SocketListener.cpp.s
.PHONY : socket/SocketListener.cpp.s

socket/SocketManager.o: socket/SocketManager.cpp.o

.PHONY : socket/SocketManager.o

# target to build an object file
socket/SocketManager.cpp.o:
	$(MAKE) -f CMakeFiles/swapk_exam.dir/build.make CMakeFiles/swapk_exam.dir/socket/SocketManager.cpp.o
.PHONY : socket/SocketManager.cpp.o

socket/SocketManager.i: socket/SocketManager.cpp.i

.PHONY : socket/SocketManager.i

# target to preprocess a source file
socket/SocketManager.cpp.i:
	$(MAKE) -f CMakeFiles/swapk_exam.dir/build.make CMakeFiles/swapk_exam.dir/socket/SocketManager.cpp.i
.PHONY : socket/SocketManager.cpp.i

socket/SocketManager.s: socket/SocketManager.cpp.s

.PHONY : socket/SocketManager.s

# target to generate assembly for a file
socket/SocketManager.cpp.s:
	$(MAKE) -f CMakeFiles/swapk_exam.dir/build.make CMakeFiles/swapk_exam.dir/socket/SocketManager.cpp.s
.PHONY : socket/SocketManager.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... swapk_exam"
	@echo "... RESTBuilder.o"
	@echo "... RESTBuilder.i"
	@echo "... RESTBuilder.s"
	@echo "... controller-examples/WeatherController.o"
	@echo "... controller-examples/WeatherController.i"
	@echo "... controller-examples/WeatherController.s"
	@echo "... dispatch/Dispatcher.o"
	@echo "... dispatch/Dispatcher.i"
	@echo "... dispatch/Dispatcher.s"
	@echo "... exception/ExceptionHandler.o"
	@echo "... exception/ExceptionHandler.i"
	@echo "... exception/ExceptionHandler.s"
	@echo "... exception/defaults/endpoint_not_found_exception.o"
	@echo "... exception/defaults/endpoint_not_found_exception.i"
	@echo "... exception/defaults/endpoint_not_found_exception.s"
	@echo "... exception/defaults/method_not_allowed_exception.o"
	@echo "... exception/defaults/method_not_allowed_exception.i"
	@echo "... exception/defaults/method_not_allowed_exception.s"
	@echo "... exception/defaults/parse_failure_exception.o"
	@echo "... exception/defaults/parse_failure_exception.i"
	@echo "... exception/defaults/parse_failure_exception.s"
	@echo "... http/HTTPCallParser.o"
	@echo "... http/HTTPCallParser.i"
	@echo "... http/HTTPCallParser.s"
	@echo "... http/HTTPEnums.o"
	@echo "... http/HTTPEnums.i"
	@echo "... http/HTTPEnums.s"
	@echo "... http/details/HTTPCallHandler.o"
	@echo "... http/details/HTTPCallHandler.i"
	@echo "... http/details/HTTPCallHandler.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
	@echo "... socket/SocketConnection.o"
	@echo "... socket/SocketConnection.i"
	@echo "... socket/SocketConnection.s"
	@echo "... socket/SocketListener.o"
	@echo "... socket/SocketListener.i"
	@echo "... socket/SocketListener.s"
	@echo "... socket/SocketManager.o"
	@echo "... socket/SocketManager.i"
	@echo "... socket/SocketManager.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

