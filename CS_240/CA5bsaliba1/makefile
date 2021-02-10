all:	main

main:	main.o Graph.cpp Node.cpp Edge.cpp Time.cpp 
	g++ main.o -o main

main.o:	main.cpp
	g++ -c main.cpp


test:	test.o
	g++ test.o -o test

test.o:	test.cpp Time.cpp
	g++ -c test.cpp

clean:
	rm -f *.o main 
