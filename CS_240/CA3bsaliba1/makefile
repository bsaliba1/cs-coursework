all: main

main:	LLC.o main.o
	g++ LLC.o main.o -o main

main.o:	main.cpp
	g++ -c main.cpp

LLC.o: 	LLC.cpp LLC.h
	g++ -c LLC.cpp
clean: 
	rm -f *.o main 
