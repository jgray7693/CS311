CC = g++	# use g++ for compiling c++ code
CFLAGS = -g -Wall -std=c++11		# compilation flags: -g for debugging. Change to -O or -O2 for optimized code.

all: test1 test2 test3
SRCS = test1.cpp test2.cpp test3.cpp eval_expr.cpp
DEPS = $(SRCS:.cpp=.d)

.cpp.o:
	$(CC) -c $(CFLAGS) $< -o $@

test1: test1.o 
	$(CC) test1.o  -o test1
	
test2: test2.o eval_expr.o
	$(CC) test2.o eval_expr.o -o test2

test3: test3.o eval_expr.o
	$(CC) test3.o eval_expr.o -o test3

clean:
	rm *.o test1 test2 test3