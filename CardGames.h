/*
 * CardGames.h
 *
 *  Created on: May 8, 2014
 *      Author: Cameron Stuart
 */

#ifndef CARDGAMES_H_
#define CARDGAMES_H_

#include "deck.h"
#include "Player.h"
//#include "Go_fish.h"
//#include "Poker.h"
//#include "card.h"

using namespace std;



class Card_Games {
public:
	Card_Games();
	virtual ~Card_Games();

	virtual void play()  =0;  //Pure virtual in card games

protected:
	 int dcount;
	 int numoplayers;
	 Player *players;
	 deck deckset;


};

#endif /* CARDGAMES_H_ */
