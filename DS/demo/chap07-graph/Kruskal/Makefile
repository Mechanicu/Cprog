sources = *.c ../AdjMatrix/graph.c
target = krus
CC = gcc
CCFLAG = -g -Wall -fsanitize=address

all:
	$(CC) $(CCFLAG) $(sources) -o $(target)

clean:
	rm -f $(target)