using namespace std;
#include <iostream>
#include "card.h"
#include <cstdlib>

class deck{
   public:
      card build[52];
      card Deck[52];

      /*********************************************************************
       *Function:void mkdeck
       *Description: Initializes empty card arrays contained in deck class
       *Parameters: card Deck[52] card Build[52]
       *Pre-Conditions: Both card arrays are uninitialized
       *Post-Conditions:One deck with  suits+ranks in order, another random
       ********************************************************************/ 
      void mkdeck(card Deck[52],card Build[52]);

   private:

      /*********************************************************************
       *Function:void fbuild
       *Description: Fills the "build" deck w/ suits+ranks in order
       *Parameters:card Build[52]
       *Pre-Conditions:Card array uninitialized
       *Post-Conditions:Ordered card array filled
       ********************************************************************/ 
      void fbuild(card Build[52]);

      /*********************************************************************
       *Function:void rank1
       *Description:Assigns rank to cards
       *Parameters:ints y and x, and card bu[52]
       *Pre-Conditions:y is the placeholder in the deck, x is for rank
       *Post-Conditions: Rank for bu[y] is initialized
       ********************************************************************/ 
      void rank1(int y, int &x, card bu[52]);

      /*********************************************************************
       *Function:void rank2
       *Description:Assigns rank to cards
       *Parameters:ints y and x, and card bu[52]
       *Pre-Conditions:y is the placeholder in the deck, x is for rank
       *Post-Conditions: Rank for bu[y] is initialized
       ********************************************************************/ 
      void rank2(int y, int &x, card bu[52]);

      /*********************************************************************
       *Function:void rank3
       *Description:Assigns rank to cards
       *Parameters:ints y and x, and card bu[52]
       *Pre-Conditions:y is the placeholder in the deck, x is for rank
       *Post-Conditions: Rank for bu[y] is initialized
       ********************************************************************/ 
      void rank3(int y, int &x, card bu[52]);


};
