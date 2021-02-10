all:	prog2tree
prog2tree:	prog2tree.o
	gcc -Wall prog2tree.o -o prog2tree
prog2tree.o:	prog2tree.c
	gcc -c prog2tree.c
clean:
	rm prog2tree
	rm *.o
