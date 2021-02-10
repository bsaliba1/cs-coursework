all: 	saliba_p1

saliba_p1:	Node.o	saliba_p1.o
	g++ Node.o saliba_p1.o -o saliba_p1 -g
saliba_p1.o:	saliba_p1.cpp
	g++ -c saliba_p1.cpp -g
Node.o:	Node.cpp
	g++ -c Node.cpp	-g
clean:
	rm -f *.o saliba_p1
