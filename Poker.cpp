/***************************************************************************
 *Program Filename: Poker.cpp
 *Author: Cameron Stuart
 *Date: 5/8/14
 *Description: Functions for Poker
 **************************************************************************/ 
#include "Poker.h"

using namespace std;

Poker::Poker() {
   // TODO Auto-generated constructor stub

}

Poker::~Poker() {
   // TODO Auto-generated destructor stub
}
void Poker::play(){

   int num;
   do{
      cout << "Please Select a number of players between 2 and 6" << endl;
      cin >> num;
      if(cin.fail()) {
	 cin.clear();
	 cin.ignore();
	 continue;
      }

   }while((num <= 1) || (num > 6));
   players = new Player[num];
   deckset.mkdeck(deckset.Deck, deckset.build);
   numoplayers = num;
   for(int i = 0; i < 6; i++)
      points[i] = 0;

   menu_print();
}

void Poker::menu_print(){
   int num;
   cout << "Welcome to the game of poker-ish" << endl;
   cout << "This is essentially poker except without betting a few different rules" << endl;
   cout << "Before the game starts you select how many hands you'll want to play through" << endl;
   cout << "For each hand, each player will be dealt five cards" << endl;
   cout << "You will then be able to discard up to four cards and draw four more" << endl;
   cout << "The whole point of discarding and drawing is to make the traditional poker sets" << endl;
   cout << "Depending on the rarity of the set, a player will receive more or less points" << endl;
   cout << endl;
   cout << "Now type in the number of hands you want to play (more than 0)" << endl;
   cin >> num;
   gameplay(num);
}

void Poker::gameplay(int n){
   if(n <= 0){
      checkwinner();
      return;
   }
   else{
      make_hands();

      for(int i = 0; i < numoplayers; i++){
	 print_hand(i);
	 discard_get(i);

	 setchecks(i);
      }
      DESTROY_ALL_HANDS();
      gameplay(n-1);

   }
}

void Poker::make_hands(){
   for(int i=0; i < numoplayers; i++){
      players[i].hand = new card[5];
   }
   for(int i = 0; i < numoplayers; i++){
      for(int j = 0; j < 5; j++){
	 players[i].hand[j] = deckset.Deck[dcount];
	 dcount += 1;
	 players[i].hsize = 5;
      }
   }



}



void Poker::print_hand(int who){
   for(int i = 0; i < 5; i++){
      cout << i+1<< ".) Rank = " << players[who].hand[i].rank << " Suite = " << players[who].hand[i].suite << endl;
   }
}


void Poker::discard_get(int who){
   int num,temp, which[4];
   cout << "Select how many cards to discard" << endl;
   cin >> num;
   if(num == 0)
      return;
   else if((num < 0) || (num > 4)){
      cout << "Invalid number of cards, must be between 0-4" << endl;
      discard_get(who);
   }
   else{
      cout << "Now select which cards specifically to get rid of" << endl;
      cout << "(Hint: Cards are numbered on display, enter in numbers one at a time and press enter after each one)" << endl;
      for(int i = 0; i < num; i++){
	 cin >> temp;
	 cardcheck(temp);
	 which[i] = temp - 1;
      }
      doingit(who,num,which);


   }

}

void Poker::cardcheck(int &card){
   if((card > 0) && (card < 6)){
      return;
   }
   else{
      cout << "Invalid card choice try again" << endl;
      cin >> card;
      cardcheck(card);
   }
}


void Poker::doingit(int who, int num, int which[4]){
   for(int i = 0; i < num; i++){
      players[who].hand[which[i]] = deckset.Deck[dcount];
      dcount +=1;

   }



}


void Poker::setchecks(int who){
   int original = points[who];
   check5(who);

   if(points[who] == original)
      check4(who);

   if(points[who] == original)
      check1(who);

   if(points[who] == original)
      check6(who);

   if(points[who] == original)
      check2(who);

   if(points[who] == original)
      check3(who);

}

void Poker::check1(int who){

   int count = 0;
   for(int j = 0; j < 13; j++){
      count = 0;
      for(int i = 0; i < 5; i++){
	 if(players[who].hand[i].rank == deckset.build[j].rank){
	    count +=1;

	    if(count == 3){
	       points[who]+=10;


	    }
	 }
      }
   }
}

void Poker::check2(int who){
   int count = 0;
   string check;
   for(int i = 0; i < 5; i++){
      players[who].hand[i].rank == check;
      for(int j = 0; j < 13; j++){
	 count = 0;
	 if(deckset.build[j].rank == check){
	    if(count == 5){
	       points[who] = 15;
	       return;
	    }
	    else{
	       for(int x = 0; x < 5; x++){
		  if(players[who].hand[x].rank == deckset.build[j].rank){
		     count +=1;
		  }
		  else if(players[who].hand[x].rank == deckset.build[j+1].rank){
		     count +=1;
		  }
		  else if(players[who].hand[x].rank == deckset.build[j+2].rank){
		     count +=1;
		  }
		  else if(players[who].hand[x].rank == deckset.build[j+3].rank){
		     count +=1;
		  }
		  else if(players[who].hand[x].rank == deckset.build[j+4].rank){
		     count +=1;
		  }
	       } }
	 }
      }
   }
}


void Poker::check3(int who){

   int count = 0;
   for(int j = 0; j < 13; j++){
      count = 0;
      for(int i = 0; i < 5; i++){
	 if(players[who].hand[i].suite == deckset.build[j].suite){
	    count +=1;

	    if(count == 5){
	       points[who]+=20;


	    }
	 }
      }
   }
}

void Poker::check4(int who){
   string set;
   int count = 0;
   int count2 = 0;
   for(int j = 0; j < 13; j++){
      count = 0;
      for(int i = 0; i < 5; i++){
	 if(players[who].hand[i].rank == deckset.build[j].rank){
	    count +=1;
	    if(count == 3){
	       set = deckset.build[j].rank;
	       for(int x = 0; x < 13; x++){
		  count2 = 0;
		  for(int y = 0; y < 5; y++){
		     if(players[who].hand[y].rank == deckset.build[x].rank){
			if(players[who].hand[y].rank != set){
			   count2 +=1;}

			if(count2 == 2){
			   points[who] +=25;
			   return;
			}
		     }
		  }
	       }
	       //divide
	    }
	 }
      }
   }
}

void Poker::check5(int who){

   int count = 0;
   for(int j = 0; j < 13; j++){
      count = 0;
      for(int i = 0; i < 5; i++){
	 if(players[who].hand[i].rank == deckset.build[j].rank){
	    count +=1;

	    if(count == 4){
	       points[who]+=10;


	    }
	 }
      }
   }
}

void Poker::check6(int who){
   int count = 0;
   string check, suite;
   for(int i = 0; i < 5; i++){
      players[who].hand[i].rank == check;
      players[who].hand[i].suite == suite;
      for(int j = 0; j < 13; j++){
	 count = 0;
	 if(deckset.build[j].rank == check){
	    if(count == 5){
	       points[who] = 15;
	       return;
	    }
	    else{
	       for(int x = 0; x < 5; x++){
		  if((players[who].hand[x].rank == deckset.build[j].rank) && (players[who].hand[x].suite == suite)){
		     count +=1;
		  }
		  else if((players[who].hand[x].rank == deckset.build[j+1].rank) && (players[who].hand[x].suite == suite)){
		     count +=1;
		  }
		  else if((players[who].hand[x].rank == deckset.build[j+2].rank) && (players[who].hand[x].suite == suite)){
		     count +=1;
		  }
		  else if((players[who].hand[x].rank == deckset.build[j+3].rank) && (players[who].hand[x].suite == suite)){
		     count +=1;
		  }
		  else if((players[who].hand[x].rank == deckset.build[j+4].rank) && (players[who].hand[x].suite == suite)){
		     count +=1;
		  }
	       } }
	 }
      }
   }

}



void Poker::DESTROY_ALL_HANDS(){
   //I DESTROYED ALL OF YOUR HANDS
   for(int i = 0; i < numoplayers; i++){
      delete [] players[i].hand;
   }
}

void Poker::checkwinner(){
   int max = 0;
   int who;
   for(int i = 0; i < numoplayers; i++){
      cout << "Player " << i+1 << " had " << points[i] << " points." << endl;
      if(points[i] > max){
	 max = points[i];
	 who = i+1;
      }
   }
   for(int i = 0; i < numoplayers; i++){
      for(int j = 0; j < numoplayers; j++){
	 if(points[i] == points[j]){
	    cout << "There was a tie!" << endl;
	    cout << "Player " << who << " wins with " << points[who-1] << " points!" << endl;
	    return;
	 }
      }
   }
   cout << "Player " << who << " wins with " << points[who-1] << " points!" << endl;
}

