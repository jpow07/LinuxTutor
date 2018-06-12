LinuxTutor: src/main.o
	g++ src/main.o -o LinuxTutor

myprogram: src/main.cpp
	g++ src/main.cpp -c
