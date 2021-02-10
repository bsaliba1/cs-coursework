all:	main

main:	main.o PlayingCard.o 
	g++ PlayingCard.o main.o -o main

main.o:	main.cpp
	g++ -c main.cpp

PlayingCard.o:	PlayingCard.cpp PlayingCard.h
	g++ -c PlayingCard.cpp

clean:
	rm -f *.o main 
