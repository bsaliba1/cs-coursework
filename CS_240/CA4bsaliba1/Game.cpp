#include <string>

using namespace std;

class Game{
	public:
		LLC<PlayingCard>* pot= new LLC<PlayingCard>();
		LLC<PlayingCard>* deck;
		LLC<PlayingCard>* p1_deck;
		LLC<PlayingCard>* p2_deck;
		int numB=0;
		int numW=0;
		ofstream* ostream;

		//returns true if P1 wins and false if P2 wins
		bool PlayGame(Player* player1, Player* player2){
			createDeck();
			dealCards();

			int rounds = 0;
			numB = 1;
			numW = 1;
			while(rounds<1000){
				bool w = round(player1->getName(),player2->getName(),numB,numW);	
				
				if(w){
					numB++;
				}else{
					numW++;
					numB++;
				}

				if(p1_deck->len()==0){
					player2->incrementWins();
					return false;
				}if(p2_deck->len()==0){
					player1->incrementWins();
					return true;
				}	
				rounds++;
			}
			if(p1_deck->len()>p2_deck->len()){
				player1->incrementWins();
				return true;
			}else if(p2_deck->len()>p1_deck->len()){
				player2->incrementWins();
				return false;
			}else{
				int ran = rand()%2;
				if(ran==1){
					player2->incrementWins();
					return false;
				}else{
					player1->incrementWins();
					return true;
				}
			}
				
		}
		void createDeck(){
			LLC<PlayingCard>* tempDeck = new LLC<PlayingCard>();
			for(int i=2; i<15;i++){
				SUIT arr[] = {DIAMOND,HEART,SPADE,CLUB}; 
				for(int j=0;j<4;j++){
					PlayingCard card = PlayingCard(arr[j],i);
					tempDeck->insert(card);
				}
			}
			tempDeck->shuffle();
			deck = tempDeck; 	
		}
		void dealCards(){
			p2_deck = new LLC<PlayingCard>();
			p1_deck = new LLC<PlayingCard>();
			p2_deck->first = deck->first;
			p2_deck->numNodes = 26;
			for(int i=0;i<25;i++){
				deck->first = deck->first->next;
			}
			p2_deck->last = deck->first;
			p1_deck->first =deck->first->next;
			p2_deck->last->next = nullptr;
			p1_deck->numNodes=26;
			p1_deck->last=deck->last;
		}
		bool round(string p1,string p2,int battles,int wars){
			PlayingCard* card1 = new PlayingCard(p1_deck->first->data);
			PlayingCard* card2 = new PlayingCard(p2_deck->first->data);

			pot->insert(*card1);
			pot->insert(*card2);
			
			p1_deck->remove(*card1);
			p2_deck->remove(*card2);
			
			if(*card1>*card2){
				p1_deck->join(*pot);
				pot->remove(*card1);
				pot->remove(*card2);
				
				LLC<PlayingCard>* temp2 = new LLC<PlayingCard>(p1_deck);
				p1_deck = temp2;
				*ostream<<"\tBattle "<<battles<<": "<<p1<<"("<<*card1<<") defeated "<<p2<<"("<<*card2<<"): "<<
					p1<<" "<<p1_deck->len()<<", "<<p2<<" "<<p2_deck->len()<<endl;
				return true;
			}
			else if(*card2>*card1){	
				p2_deck->join(*pot);
				pot->remove(*card1);
				pot->remove(*card2);
				
				LLC<PlayingCard>* temp2 = new LLC<PlayingCard>(p2_deck);
				p2_deck = temp2;
				*ostream<<"\tBattle "<<battles<<": "<<p2<<"("<<*card2<<") defeated "<<p1<<"("<<*card1<<"): "<<
					p1<<" "<<p1_deck->len()<<", "<<p2<<" "<<p2_deck->len()<<endl;	
				return true;
			}else{
				*ostream<<"\tBattle "<<battles<<": "<<p1<<"("<<*card1<<") tied "<<p2<<"("<<*card2<<")" <<endl;
				war(p1, p2, wars);
				return false;
			}
			
		}
		void war(string p1,string p2,int wars){
			PlayingCard* card1 = new PlayingCard();
			PlayingCard* card2 = new PlayingCard();
			int minCards = 4;
			if(p1_deck->len()<4){
				minCards = p1_deck->len();
			}if(p2_deck->len()<4){
				minCards = p2_deck->len();
			}
			if(minCards!=0){
				for(int i=0;i<minCards;i++){
					card1 = new PlayingCard(p1_deck->first->data);
					card2 = new PlayingCard(p2_deck->first->data);
					

					pot->insert(*card1);
					pot->insert(*card2);
					
					p1_deck->remove(*card1);
					p2_deck->remove(*card2);	
				}
				if(*card1>*card2){
					p1_deck->join(*pot);
					int q = pot->len();
					for(int i=0;i<q;i++){
						pot->remove(pot->first->data);
					}
					*ostream<<"\tWar "<<wars<<": "<<p1<<"("<<*card1<<") defeated "<<p2<<"("<<*card2<<"): " 
						<<p1<<" "<<p1_deck->len()<<", "<<p2<<" "<<p2_deck->len()<<endl;
				}
				else if(*card2>*card1){
					p2_deck->join(*pot);
					int q = pot->len();
					for(int i=0;i<q;i++){
						pot->remove(pot->first->data);
					}
					*ostream<<"\tWar "<<wars<<": "<<p2<<"("<<*card2<<") defeated "<<p1<<"("<<*card1<<"): " 
						<<p1<<" "<<p1_deck->len()<<", "<<p2<<" "<<p2_deck->len()<<endl;
				}else{
					war(p1,p2,wars);
				}
			}else{
				if(p1_deck->len()==0){
					p2_deck->join(*pot);
					pot->remove(card1);
					pot->remove(card2);
				}
				else{
					p1_deck->join(*pot);
					pot->remove(card1);
					pot->remove(card2);
				}
			}
		}
		Game(ofstream* o){
			ostream = o;
		}
};
