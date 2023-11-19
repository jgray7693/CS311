CC = g++	# use g++ for compiling c++ code
CFLAGS = -g -Wall -std=c++17		# compilation flags: -g for debugging. Change to -O or -O2 for optimized code.
SRCS = heap.cpp test.cpp
DEPS = $(SRCS:.cpp=.d)
all: test

.cpp.o:
	$(CC) -c $(CFLAGS) $< -o $@

test: test.o heap.o
	$(CC) test.o heap.o -o test
	
clean:
	rm *.o test
