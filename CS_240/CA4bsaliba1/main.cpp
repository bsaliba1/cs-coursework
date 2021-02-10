#include <fstream>
#include <string>
#include <stdio.h>
#include <iostream>
#include "PlayingCard.h"
#include "LLC.h"
#include "Player.cpp"
#include "Game.cpp"
#include "Tournament.cpp"
#include <vector>

using namespace std;

int main(int argc, char* argv[]){

	string i;
	string o;
	vector<Player*>* list = new vector<Player*>();
	if(argc==3){
		i = argv[1];
		o = argv[2];

		ifstream istream;
		istream.open(i);
		if(istream.is_open()){
			string name;
			while(!istream.eof()){
				istream>>name;
				Player *player = new Player(name);
				list->push_back(player);			
			}
			istream.close();
			list->pop_back();

			ofstream ostream;
			ostream.open(o);
			Tournament tourn = Tournament(list,&ostream);
			ostream.close();	
		}else{
			cout<<"Input file doesn't exit"<<endl;
		}
	}
}
