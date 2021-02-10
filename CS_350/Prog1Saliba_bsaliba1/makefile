all:	prog1sorter	prog1generator
prog1sorter.o:	prog1sorter.c
	gcc -c prog1sorter.c
prog1sorter:	prog1sorter.o
	gcc -Wall prog1sorter.o -o prog1sorter
prog1sorter.o:	prog1sorter.c
	gcc -c prog1sorter.c
prog1generator:	prog1generator.o
	gcc -Wall prog1generator.o -o prog1generator
clean:
	rm prog1sorter prog1generator
	rm *.o	
