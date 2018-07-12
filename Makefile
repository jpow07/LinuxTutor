# -*- Makefile -*-

#Path to google test directory
GTEST_DIR = googletest/googletest

#compiler being used
COMPILER = g++

#include headers
GTEST_FLAGS = -isystem ${GTEST_DIR}/include -pthread
GTEST_LIBRARY = gtest/libgtest.a
DEBUGFLAGS = -Wall -Wextra -g -pedantic-errors

#path to src directory
SRC_DIR = src

#tell make to look in these paths if file does not exist in the current directory
VPATH = tests:${GTEST_DIR}:${GTEST_DIR}/src:${SRC_DIR} 

#run the tests and the main code
all : libgtest.a unit-tests debug 

# Release version that will support compiler optimization
#release : 


#create the program
debug : ${SRC_DIR}/main.o
	@${COMPILER} $^ -o $@ ${DEBUGFLAGS}

#create object files 
main.o : main.cpp
	@${COMPILER} $^ -c -o ${SRC_DIR}/$@


#build library target
.PHONY : build_libraries
build_libraries : libgtest.a

#Generate libgtest.a
libgtest.a : gtest-all.o
	@ar -rv ${GTEST_DIR}/libgtest.a ${GTEST_DIR}/gtest-all.o
	@echo Build Successful!

#generate object file that is required for building library
gtest-all.o: ${GTEST_DIR}/src/gtest-all.cc
	@${CXX} -isystem ${GTEST_DIR}/include -I${GTEST_DIR} -pthread -c $^ -o ${GTEST_DIR}/$@



#create the unit-tests and declare it phony so it will compile everytime its ran
.PHONY : unit-tests
unit-tests : test.cpp
	@${COMPILER} ${GTEST_FLAGS} $^ ${GTEST_LIBRARY} -o $@

#clean the directory and clear the terminal
.PHONY : clean
clean :
	@rm unit-tests debug ${SRC_DIR}/*.o -f
	@clear






