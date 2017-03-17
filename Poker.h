#ifndef POKER_H_
#define POKER_H_

#include "CardGames.h"

using namespace std;

class Poker : public Card_Games
{
public:
	Poker();
	virtual ~Poker();

	virtual void play();

private:
int points[6];


/***************************************************************************
 *Function: menu_print
 *Description: Prints menu
 *Parameters: None
 *Pre-Condtions: None
 *Post-Conditions: Menu is printed
 * ************************************************************************/
void menu_print();

/***************************************************************************
 *Function: gameplay
 *Description: Plays game recursively
 *Parameters: int n
 *Pre-Condtions: n is number of hands to play
 *Post-Conditions: game is played
 * ************************************************************************/
void gameplay(int n);

/***************************************************************************
 *Function: make_hands
 *Description: Creates hands for players
 *Parameters: None
 *Pre-Condtions: None
 *Post-Conditions: Hands are created
 * ************************************************************************/
void make_hands();


/***************************************************************************
 *Function: print_hand
 *Description: Prints hand
 *Parameters: int who
 *Pre-Condtions: who is the player's turn it is
 *Post-Conditions: Player hand is printed
 * ************************************************************************/
void print_hand(int who);


/***************************************************************************
 *Function: discard_get
 *Description: discards cards in players hand and draws new ones
 *Parameters: int who
 *Pre-Condtions: who is the current player's turn(-1) and is within the scope
 *Post-Conditions: Hands are changed
 * ************************************************************************/
void discard_get(int who);

/***************************************************************************
 *Function: cardcheck
 *Description: Prints menu
 *Parameters: None
 *Pre-Condtions: None
 *Post-Conditions: Menu is printed
 * ************************************************************************/
void cardcheck(int &card);

/***************************************************************************
 *Function: doingit
 *Description: Assists is discarding and drawing cards
 *Parameters: who,num,which[4]
 *Pre-Condtions: int is player turn, num # of cards discarding, and which
 * is the specific card being discarded
 *Post-Conditions: Cards discarded and new ones drawn
 * ************************************************************************/
void doingit(int who, int num, int which[4]);

/***************************************************************************
 *Function: setchecks
 *Description: Starts process of checking for sets
 *Parameters: int who
 *Pre-Condtions: who is player turn
 *Post-Conditions: points are awarded
 * ************************************************************************/
void setchecks(int who);

/***************************************************************************
 *Function: check1
 *Description: Checks for a specific set and assigns points
 *Parameters: int who
 *Pre-Condtions: who is player turn
 *Post-Conditions: points are awarded
 * ************************************************************************/
void check1(int who);

/***************************************************************************
 *Function: check2
 *Description: Checks for a specific set and assigns points
 *Parameters: int who
 *Pre-Condtions: who is player turn
 *Post-Conditions: points are awarded
 * ************************************************************************/
void check2(int who);

/***************************************************************************
 *Function: check3
 *Description: Checks for a specific set and assigns points
 *Parameters: int who
 *Pre-Condtions: who is player turn
 *Post-Conditions: points are awarded
 * ************************************************************************/
void check3(int who);

/***************************************************************************
 *Function: check4
 *Description: Checks for a specific set and assigns points
 *Parameters: int who
 *Pre-Condtions: who is player turn
 *Post-Conditions: points are awarded
 * ************************************************************************/
void check4(int who);

/***************************************************************************
 *Function: check5
 *Description: Checks for a specific set and assigns points
 *Parameters: int who
 *Pre-Condtions: who is player turn
 *Post-Conditions: points are awarded
 * ************************************************************************/
void check5(int who);

/***************************************************************************
 *Function: check5
 *Description: Checks for a specific set and assigns points
 *Parameters: int who
 *Pre-Condtions: who is player turn
 *Post-Conditions: points are awarded
 * ************************************************************************/
void check6(int who);


/***************************************************************************
 *Function: DESTROY_ALL_HANDS
 *Description: Destroys hands
 *Parameters: None
 *Pre-Condtions: None
 *Post-Conditions: Hand arrays are destroyed
 * ************************************************************************/
void DESTROY_ALL_HANDS();

/***************************************************************************
 *Function: checkwinner
 *Description: Looks for highest points and displays them
 *Parameters: None
 *Pre-Condtions: None
 *Post-Conditions: Points displayed winner announced
 * ************************************************************************/
void checkwinner();

};

#endif /* POKER_H_ */
