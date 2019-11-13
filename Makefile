CC = g++
OF = -o
CF = -c

all: test_g

test_g: test_g.o
	$(CC) $(OF) test_g test_g.o

test_g.o: test_g.cpp graph.h graph.cpp
	$(CC) $(CF) test_g.cpp
