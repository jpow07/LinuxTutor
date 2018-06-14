#! /bin/bash

#build gtest library

#Create a variable that holds the path to the googletest directory
GTEST_DIR=$(pwd)/googletest/googletest
#Compile the Libraries into an object  file
g++ -isystem ${GTEST_DIR}/include -I${GTEST_DIR} -pthread -c ${GTEST_DIR}/src/gtest-all.cc

#Convert the object file to an archive file
ar -rv libgtest.a gtest-all.o
