sources = *.c ../AdjMatrix/graph.c ../common/llist.c
target = spath
CC = gcc
CCFLAG = -g -Wall -fsanitize=address

all:
	$(CC) $(CCFLAG) $(sources) -o $(target)

clean:
	rm -f $(target)