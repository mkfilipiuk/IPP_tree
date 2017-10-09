CC=gcc
CFLAGS=-c -Wall -Wextra 

solution: solution.o tree.o 
	$(CC) -Wall -Wextra -o solution solution.o tree.o 
tree.o: tree.c tree.h
	$(CC) $(CFLAGS) tree.c
solution.o: solution.c tree.h
	$(CC) $(CFLAGS) solution.c
dtree.o: tree.c tree.h
	$(CC) $(CFLAGS) -g tree.c -o dtree.o
dsolution.o: solution.c tree.h
	$(CC) $(CFLAGS) -g solution.c -o dsolution.o
debug: dsolution.o dtree.o
	$(CC) -Wall -Wextra -g -o solution.dbg dsolution.o dtree.o
clean:
	rm -f *.o
	rm -f *.dbg
	rm -f solution
.PHONY: clean