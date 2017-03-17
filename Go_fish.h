using namespace std;

//#include "deck.h"
//#include "Player.h"
#include <cstdlib>
#include <iostream>
#include "CardGames.h"


class Go_fish : public Card_Games
{
   public:

      /*********************************************************************
       *Function:Go_fish()
       *Description: Constructor which initializes and starts "Gofish"
       *Parameters: none
       *Pre-Conditions: none
       *Post-Conditions:Go fish is played 
       ********************************************************************/ 
      Go_fish();			//Must fix constructor and game play

     virtual void play();

   private:


      /*********************************************************************
       *Function:void menu_print
       *Description: Prints opening menu for "Gofish"
       *Parameters: None
       *Pre-Conditions: None
       *Post-Conditions:Menu is printed
       ********************************************************************/ 
      void menu_print();

      /*********************************************************************
       *Function:void plyrfill
       *Description: Initializes and fills initial player hands (w/ 7 cards)
       *Parameters: int num
       *Pre-Conditions: num is an int between 2 and 6 (# of players)
       *Post-Conditions: num is unchanged and each players hand is made
       ********************************************************************/ 
      void plyrfill(int num);

      /*********************************************************************
       *Function:void game
       *Description: Initializes and starts game of gofish
       *Parameters: int num 
       *Pre-Conditions: num is the number of players in the game
       *Post-Conditions: Num is unchanged and game is played
       ********************************************************************/ 
      void game(int num); 	

      /*********************************************************************
       *Function:void seehand
       *Description: Prints a players hand at the start of their turn
       *Parameters: int plyr
       *Pre-Conditions: plyr is the number for whose turn it is
       *Post-Conditions: plyr unchanged and hand is printed
       ********************************************************************/ 
      void seehand(int plyr);

      /*********************************************************************
       *Function:void pcheck
       *Description: Checks target player input for validity
       *Parameters: int ply,x, and num
       *Pre-Conditions: x is the player's turn and ply is their input
       *Post-Conditions:ply is changed if it was invalid input
       ********************************************************************/ 
      void pcheck(int &ply, int x, int num);

      /*********************************************************************
       *Function:void inputcheck
       *Description: Checks input for card rank for validity
       *Parameters: string &choice
       *Pre-Conditions: choice is the a string containing the rank selected
       *Post-Conditions: choice is changed if previously invalid
       ********************************************************************/ 
      void inputcheck(string &choice);

      /*********************************************************************
       *Function:void spaces
       *Description: Prints spaces between turns
       *Parameters: None
       *Pre-Conditions: No parameters
       *Post-Conditions: Screen is "cleared" for next players turn
       ********************************************************************/ 
      void spaces();

      /*********************************************************************
       *Function:void gofish
       *Description: Starts process for gofish with selected input
       *Parameters: int targetp, win, and pturn and string choice
       *Pre-Conditions: targetp,choice are plyr input, win=0
       *Post-Conditions:Card draw, sets, etc. started, win = 1 for winner
       ********************************************************************/ 
      void gofish(int targetp, string choice, int &win, int pturn);

      /*********************************************************************
       *Function:int phcheck
       *Description: Checks target player's hand for target rank
       *Parameters: int targetp and count , and string ch
       *Pre-Conditions: targetp amd ch are player input and count = 0
       *Post-Conditions:number of target rank in hand is returned
       ********************************************************************/ 
      int phcheck(int targetp, string ch, int &count);

      /*********************************************************************
       *Function:void counter
       *Description: Checks target player's hand for target rank
       *Parameters: int targetp and count , and string ch
       *Pre-Conditions: targetp amd ch are player input and count = 0
       *Post-Conditions: count variable is set to # of target card
       ********************************************************************/ 
      void counter(int targetp, string ch, int &count);

      /*********************************************************************
       *Function:void draw
       *Description: "Draws" card for a player
       *Parameters: int turn
       *Pre-Conditions: turn is the current player's turn
       *Post-Conditions: Player who's turn it is has hand increase by one 
       ********************************************************************/ 
      void draw(int turn);

      /*********************************************************************
       *Function:void take
       *Description: Takes target rank from target player
       *Parameters: int targetp, turn, count, and win, and string ch
       *Pre-Conditions: targetp = targetplayer and ch = target rank
       *Post-Conditions:Win is changed if a player's handsize hits 0
       ********************************************************************/ 
      void take(int targetp, string ch, int turn, int count,  int &win);

      /*********************************************************************
       *Function:void take1
       *Description: Takes target rank from target player
       *Parameters: int targetp, turn, count, and win, and string ch
       *Pre-Conditions: targetp = targetplayer and ch = target rank
       *Post-Conditions:Win is changed if a player's handsize hits 0
       ********************************************************************/ 
      void take1(int targetp, string ch, int turn, int count,  int &win);

      /*********************************************************************
       *Function:void take2
       *Description: Takes target rank from target player
       *Parameters: int targetp, turn, count, and win, and string ch
       *Pre-Conditions: targetp = targetplayer and ch = target rank
       *Post-Conditions:Win is changed if a player's handsize hits 0
       ********************************************************************/ 
      void take2(int targetp, string ch, int turn, int count,  int &win);

      /*********************************************************************
       *Function:void setcheck
       *Description: Checks if player has a set of four of a kind
       *Parameters: int player, win
       *Pre-Conditions: player is player being checked and win = 0
       *Post-Conditions:win is set to 1 if player has no cards left
       ********************************************************************/ 
      void setcheck(int player, int &win);

      /*********************************************************************
       *Function:void settake
       *Description: set of four is taken from player passed to function
       *Parameters: ints player and win, string set
       *Pre-Conditions: set is uninitialized before, win = 0
       *Post-Conditions:Win is set to 1 if player has no cards left
       ********************************************************************/ 
      void settake(int player, string set, int &win);

      /*********************************************************************
       *Function:void winnerch
       *Description: Checks to see if win=1 or player has no cards left
       *Parameters: int win and player
       *Pre-Conditions: win = 0 if no winner found yet, player is checked
       *Post-Conditions:win changed to 1 if player has no cards left
       ********************************************************************/ 
      void winnerch(int &win, int player);


};
