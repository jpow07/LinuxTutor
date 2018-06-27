# -*- Makefile -*-

#Path to google test directory
GTEST_DIR = gtest/googletest/googletest

#compiler being used
COMPILER = g++

#include headers
GTEST_FLAGS = -isystem ${GTEST_DIR}/include -pthread
GTEST_LIBRARY = gtest/libgtest.a
DEBUGFLAGS = -Wall -Wextra -g -pedantic-errors

#path to src directory
SRC_DIR = src

#tell make to look in these paths if file does not exist in the current directory
VPATH = tests: gtest:${GTEST_DIR}:${GTEST_DIR}/src:${SRC_DIR} 

#run the tests and the main code
all : libgtest.a unit-tests debug 

# Release version that will support compiler optimization
#release : 


#create the program
debug : ${SRC_DIR}/main.o
	@${COMPILER} $^ -o exe/$@ ${DEBUGFLAGS}

#create object files 
main.o : main.cpp
	@${COMPILER} $^ -c -o ${SRC_DIR}/$@




#Generate libgtest.a
libgtest.a : gtest-all.o
	@ar -rv gtest/libgtest.a gtest/gtest-all.o
	@echo Build Successful!

#generate object file that is required for building library
gtest-all.o: gtest-all.cc
	@${CXX} -isystem ${GTEST_DIR}/include -I${GTEST_DIR} -pthread -c $^ -o gtest/$@



#create the unit-tests and declare it phony so it will compile everytime its ran
.PHONY : unit-tests
unit-tests : test.cpp
	@${COMPILER} ${GTEST_FLAGS} $^ ${GTEST_LIBRARY} -o exe/$@
	@exe/$@

#clean the directory and clear the terminal
.PHONY : clean
clean :
	@rm exe/unit-tests exe/debug ${SRC_DIR}/*.o -f
	@clear






