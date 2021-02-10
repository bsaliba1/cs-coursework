#include <string>
#include "Voter.h"
#include <iostream>

using namespace std;

class VoterDB{
	public:
		int numvoters;
		Voter *voterdb;
		void execute_outer();
	
		string getInput_outer();
	
		VoterDB(int maxsize);
		
		int Login();
		void New();
		void Report();
		void Save();
		void Load();
		void Quit();
};
	
