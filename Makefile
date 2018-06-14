
#Define some compilation flags
CPPFLAGS += -isystem $(GTEST_DIR)/include
CXXFLAGS += -Wall -Wextra -pthread


GTEST_HEADERS = $(GTEST_DIR)/include/gtest*.h $(GTEST_DIR)/include/gtest/internal/*.h


all: 





all: source tests
	g++ -isystem ${GTEST_DIR}/include -pthread 
source: src/main.o
	g++ src/main.o LinuxTutor



LinuxTutor: src/main.o
	g++ src/main.o -o LinuxTutor

main.o: src/main.cpp
	g++ src/main.cpp -c
