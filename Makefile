CC = g++
OF = -o
CF = -c

all: test_g countingStar

test_g: test_g.o
	$(CC) $(OF) test_g test_g.o

countingStar: countingStar.o 
	$(CC) $(OF) countingStar countingStar.o

countingStar.o: countingStar.cpp graph.h graph.cpp
	$(CC) $(CF) countingStar.cpp

test_g.o: test_g.cpp graph.h graph.cpp
	$(CC) $(CF) test_g.cpp
