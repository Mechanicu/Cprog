sources = *.c ../AdjList/graph.c ../common/stack.c
target = cpath
CC = gcc
CCFLAG = -g -Wall -fsanitize=address

all:
	$(CC) $(CCFLAG) $(sources) -o $(target)

clean:
	rm -f $(target)