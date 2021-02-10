#include "VoterDB.h"
#include <iostream>
#include <string.h>

using namespace std;

//VoterDB class -> array of all voters
//Voter class -> object with voter information

int main(int argc, char* argv[]){
	int MAX;
	string inpfile;
	if(argc>3){
		cout<<"Too many args"<<endl;
	}
	if(argc==2){
		MAX=atoi(argv[1]);
	} 
	if(argc==3){
		MAX=atoi(argv[1]);
		inpfile=argv[2];
	}
	VoterDB *voters = new VoterDB(MAX);
	voters->execute_outer();
}
