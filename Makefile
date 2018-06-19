# -*- Makefile -*-
#Path to google test directory
GTEST_DIR = gtest/googletest/googletest

#compiler being used
COMPILER = g++

#include headers
GTEST_FLAGS = -isystem ${GTEST_DIR}/include -pthread
GTEST_LIBRARY = gtest/libgtest.a
DEBUGFLAGS = -Wall -Wextra -g

#path to src directory
SRC_DIR = src

#tell make to look in these paths if file does not exist in the current directory
VPATH = tests

#run the tests and the main code
all : unit-tests release

#create the program
release : src/main.o
	@${COMPILER} $^ -o $@ ${DEBUGFLAGS}
	@./$@

#create object files 
main.o : main.cpp
	@${COMPILER} $^ -c -o ${SRC_DIR}/$@

#create the unit-tests
unit-tests : test.cpp
	@${COMPILER} ${GTEST_FLAGS} $^ ${GTEST_LIBRARY} -o $@
	@./$@

#clean the directory and clear the terminal
.PHONY : clean
clean :
	@rm unit-tests release ${SRC_DIR}/*.o -f 
	@clear
