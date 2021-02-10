#include <vector>

using namespace std;

class Tournament{
	public:
	ofstream* ostream;
	vector<Player*> *pList;
	int initSize;
	int numBattles =0;
	int largestBattles = 0;
	Tournament(vector<Player*>* list, ofstream* o){
		//make sure list->size() is power of 2
		double x = (double) list->size();
		while(x>2){
			x=x/2;
		}
		if(x<2){
			cout<<"List size is not a power of two"<<endl;
		}else{
			pList = list;
			initSize=list->size();
			ostream = o;
			playTournament();
			printResults();	
		}
	}
	bool  playTournament(){
		if(pList->size()==1){		
			*ostream<<"==="<<endl;
			*ostream<<"MATCH STATS"<<endl;
			*ostream<<"Winner: "<<pList->at(0)->getName()<<endl;
		}else{
			for(int i=0;i<pList->size();i++){
				Game* game = new Game(ostream);
				*ostream<<"==="<<endl;
				*ostream<<pList->at(i)->getName()<<" V. "<<pList->at(i+1)->getName()<<endl;
			       	bool winner = game->PlayGame(pList->at(i),pList->at(i+1));
				if(winner==true){
					*ostream<<pList->at(i)->getName()<<"("<<pList->at(i)->getNumWins()<<")  DEFEATED "<<pList->at(i+1)->getName()<<
						" in "<<game->numB-1<< " Battles and "<<game->numW-1<< " Wars"<<endl;
					if(game->numB>largestBattles){
						largestBattles = game->numB;
					}
					numBattles=numBattles+game->numB;
					pList->erase(pList->begin()+i+1);
				}else if(winner==false){
					*ostream<<pList->at(i+1)->getName()<<"("<<pList->at(i+1)->getNumWins()<<")  DEFEATED "<<pList->at(i)->getName()<<
						" in "<<game->numB-1<< " Battles and "<<game->numW-1<< " Wars"<<endl;
					if(game->numB>largestBattles){
						largestBattles = game->numB-1;
					}
					numBattles=numBattles+game->numB-1;
					pList->erase(pList->begin()+i);
				}	
			}
			playTournament();
		}	
	}
	void printResults(){
		*ostream<<"Average number of battles: "<<numBattles/(initSize/2)<<endl;
		*ostream<<"Largest number of battles: "<<largestBattles<<endl;
	}	
};	
