#include <stdio.h>
#include <string>
#include <iostream>
#include <ostream>

using namespace std;

enum SUIT {DIAMOND = 1,HEART=2,SPADE=3,CLUB=4}; 

class PlayingCard{
	public:
	SUIT suit;
	int value;
	
	PlayingCard();
	PlayingCard(SUIT aSuit, int val);
	PlayingCard(PlayingCard *card);
	friend bool operator<(const PlayingCard& card1, const PlayingCard& card2);
	friend bool operator>(const PlayingCard& card1, const PlayingCard& card2);
	friend ostream& operator<<(ostream& stream, const PlayingCard& card);
	friend bool operator==(const PlayingCard& card1, const PlayingCard& card2);
};
