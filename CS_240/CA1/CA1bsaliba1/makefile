# Specifiy the target
all:	Voter

# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
Voter: 	Voter.o VoterDB.o
	g++  Voter.o VoterDB.o -o Voter.exe
Voter.o:	Voter.cpp 
	g++ -c Voter.cpp
VoterDB.o: VoterDB.cpp
	g++ -c VoterDB.cpp
