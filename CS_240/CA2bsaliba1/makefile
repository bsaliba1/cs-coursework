# Specifiy the target
all:	Voter

# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
Voter: 	Voter.o VoterDB.o Voter2.o
	g++ Voter.o VoterDB.o Voter2.o -o Voter.exe
Voter2.o:	Voter2.cpp
	g++ -c Voter2.cpp
Voter.o:	Voter.cpp Voter.h 
	g++ -c Voter.cpp
VoterDB.o: VoterDB.cpp
	g++ -c VoterDB.cpp
clean: 
	rm -f *.o Voter.exe
