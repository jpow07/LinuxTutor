# -*- Makefile -*-
#Path to google test directory
GTEST_DIR = gtest/googletest/googletest

GTEST_HEADERS = ${GTEST_DIR}/include
CPPFLAGS = -isystem ${GTEST_HEADERS}
CXXFLAGS = -pthread
DEBUGFLAGS = -Wall -Wextra -g

VPATH = src:tests

all : run-tests release
	@./run-tests
	@./release

release : main.o
	@g++ $^ -o $@ ${DEBUGFLAGS}

main.o : main.cpp
	@g++ $^ -c

run-tests : test.cpp
	@g++ ${CPPFLAGS} ${CXXFLAGS} $^ gtest/libgtest.a -o $@

.PHONY : clean
clean :
	@rm run-tests release *.o -f 
