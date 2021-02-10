#include "PlayingCard.h"

PlayingCard::PlayingCard(SUIT aSuit, int val){
	suit=aSuit;
	value = val;
}
PlayingCard::PlayingCard(){

}
bool operator<(const PlayingCard& card1, const PlayingCard& card2){
	if(card2.value>card1.value){
		return true;
	}else{
		return false;
	}
}
bool operator>(const PlayingCard& card1, const PlayingCard& card2){
	if(card2.value<card1.value){
		return true;
	}else{
		return false;
	}
}
bool operator==(const PlayingCard& card1,const PlayingCard& card2){
	if(card1.suit == card2.suit and card2.value == card1.value){
		return true;
	}else{
		return false;
	}
}
ostream& operator<<(ostream& stream, const PlayingCard& card){
	switch(card.value){
		case 10: stream<<"T";
			 break;
		case 11: stream<<"J";
			 break;
		case 12: stream<<"Q";
			 break;
		case 13: stream<<"K";
			break;
		case 14: stream<<"A";
			 break;
		default: stream<<card.value;
			 break;
	}
	switch(card.suit){
		case 1: stream<<"D";
			break;
		case 2: stream<<"H";
			break;
		case 3: stream<<"S";
			break;
		case 4: stream<<"C";
			break;
	}
	return stream;
}
PlayingCard::PlayingCard(PlayingCard* card){
	suit = card->suit;
	value = card->value;
}
