/***************************************************************************
 *Program Filename:deck.cpp
 *Author:Cameron Stuart
 *Date:4/25/2014
 *Description:Contains functions for "deck" class
 *Input:Unfilled card arrays
 *Output:Filled card arrays
 ***************************************************************************/



using namespace std;

#include <iostream>
#include "deck.h"
#include <string>
#include <cstdlib>
#include <time.h>


void deck::mkdeck(card Deck[52], card Build[52]){
   int x;
   fbuild(Build);
   srand(time( NULL));
   for(int i = 0; i < 52; i++){
      do{
	 int j = (rand( ) % 52 );
	 x = j;
	 if(Deck[x].rank.empty()){
	    Deck[x] = Build[i];
	 }
	 else
	    x = 53;

      }while(x > 51);
   }
}

void deck::fbuild(card Build[52]){
   int a,b,c,d;  
   a = b = c = d = 0;
   for(int i = 0; i < 52; i++ ){
      if((i >= 0) && (i <= 12)){
	 Build[i].suite = "Spades";
	 rank1(i, a, Build);
	 a++;
      }

      else if(( i >= 13 ) && (i <= 25)){
	 Build[i].suite = "Clubs";
	 rank1(i, b, Build);
	 b++;
      }

      else if((i >= 26) && (i <= 38)){
	 Build[i].suite = "Diamonds";
	 rank1(i, c, Build);
	 c++;
      }

      else if((i >= 39) && (i <= 51)){
	 Build[i].suite = "Hearts";
	 rank1(i, d, Build);
	 d++;
      }
   }	
}

void deck::rank1(int y, int &x, card bu[52]){
   if(x == 0){
      bu[y].rank = "Ace";
      return;
   }
   else if(x == 1){
      bu[y].rank = "Two";
      return;
   }
   else if(x ==2){
      bu[y].rank ="Three";
      return;
   }
   else if(x ==3){
      bu[y].rank = "Four";
      return;
   }
   else if(x ==4){
      bu[y].rank = "Five";
      return;
   }
   rank2(y,x,bu);
}
void deck::rank2(int y, int &x, card bu[52]){

   if(x ==5){
      bu[y].rank = "Six";
      return;
   }
   else if(x ==6){
      bu[y].rank = "Seven";
      return;
   }
   else if(x ==7){
      bu[y].rank = "Eight";
      return;
   }
   else if(x ==8){
      bu[y].rank = "Nine";
      return;
   }
   else if(x ==9){
      bu[y].rank = "Ten";
      return;
   }
   rank3(y,x,bu);
}

void deck::rank3(int y, int &x, card bu[52]){

   if(x ==10){
      bu[y].rank = "Jack";
      return;
   }
   else if(x ==11){
      bu[y].rank = "Queen";
      return;
   }
   else if(x ==12){
      bu[y].rank = "King";
      return;
   }


}

