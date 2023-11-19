CC = g++	# use g++ for compiling c++ code
CFLAGS = -g -Wall -std=c++11		# compilation flags: -g for debugging. Change to -O or -O2 for optimized code.
SRCS = linkedlist.cpp test1.cpp test2.cpp test3.cpp
DEPS = $(SRCS:.cpp=.d)
all: test1 test2 test3


.cpp.o:
	$(CC) -c $(CFLAGS) $< -o $@

test1: test1.o linkedlist.o
	$(CC) test1.o linkedlist.o -o test1
	
test2: test2.o linkedlist.o
	$(CC) test2.o linkedlist.o -o test2

test3: test3.o linkedlist.o
	$(CC) test3.o linkedlist.o -o test3

clean:
	rm *.o test1 test2 test3
