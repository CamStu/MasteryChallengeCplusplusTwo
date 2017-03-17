/***************************************************************************
 *Program Filename:Game.cpp
 *Author:Cameron Stuart
 *Date:4/25/2014
 *Description:Contains functions for "Game" and plays "Gofish"
 *Input:None
 *Output:Game
 ***************************************************************************/


#include <iostream>
#include <string>
#include "Go_fish.h"
#include <cstdlib>

using namespace std;

Go_fish::Go_fish(){
   menu_print();
   int num;
   dcount = 0;
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
   plyrfill(num);
   game(num);


}

void Go_fish::play(){
	 menu_print();
	   int num;
	   dcount = 0;
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
	   plyrfill(num);
	   game(num);



}





void Go_fish::menu_print(){
   cout << "Welcome to GoFish, prepare to have loads of fun" << endl;
   cout << endl;
   cout << "The game is played with 2-6 players with a 52 card deck" << endl;
   cout << "Each player starts with seven cards in their hand." << endl;
   cout << "Each turn a player asks another if they have cards of a certain rank" << endl;
   cout << "If asked player has cards of that rank, they give them all to asking player" << endl;
   cout << "If asked player doesn't have those cards then asking player will GoFish and draw a card instead." << endl;
   cout << "If a player has four cards of the same rank they can make a set." << endl;
   cout << "When a set is made that player removes those four cards from their hand, then when that player has no cards left in their hand, they win" << endl;

}

void Go_fish::plyrfill(int num){
   for(int i=0; i < num; i++){
      players[i].hand = new card[7];
   }
   for(int i = 0; i < num; i++){
      for(int j = 0; j < 7; j++){
	 players[i].hand[j] = deckset.Deck[dcount];
	 dcount += 1;
	 players[i].hsize = 7;
      }
   }

}

void Go_fish::game(int num){
   string choose;
   int i, win, ply;
   do{
      for(i = 0; i < num; i++){
	 spaces();
	 cout << "It is now Player" << i+1 << "'s turn." << endl;
	 seehand(i);
	 cout << "Choose a player to ask for cards." << endl;
	 cin >> ply;

	 pcheck(ply,i,num);
	 cout << "Now enter in a rank to ask for, rank MUST be in form = Ace" << endl;
	 cin >> choose;
	 inputcheck(choose);
	 gofish(ply-1,choose,win,i);//Player ask,carddraw,etc.
	 if(win == 1)
	    break;
      }
   }while(win != 1);

   cout << "Congratulations, player " << i+1 << " wins!" << endl;

}

void Go_fish::seehand(int plyr){
   cout << "Your hand:    " << endl;
   for(int i = 0; i < players[plyr].hsize; i++){
      cout << players[plyr].hand[i].rank << " of " << players[plyr].hand[i].suite << endl;
      cout << endl;
   }


}

void Go_fish::pcheck(int &ply, int x, int num){
   int self = x+1;
   if(ply == self){
      cout << "You cannot choose yourself, try again" << endl;
      cin >> ply;
      pcheck(ply,x,num);
   }
   else if((ply < 1) || (ply > num)){
      cout << "Invalid player choice, try again" << endl;
      cin >> ply;   
      pcheck(ply,x,num);
   }


}

void Go_fish::inputcheck(string &choice){
   int i,bloop;
   bloop = 1;
   for(i = 0; i < 52; i++){
      if(choice == deckset.build[i].rank){
	 bloop = 2;
	 break;
      }
      else{
	 bloop = 1;
      }
   }
   if(bloop != 2){
      cout << "Incorrect Rank entered, make sure it is uppercase ex = Two" << endl;
      cout << "Enter in a valid card rank" << endl;
      cin >> choice;
      inputcheck(choice);
   }
   else
      return;


}

void Go_fish::spaces(){
   for(int i = 0; i < 50; i ++){
      cout << endl;
   }
}

void Go_fish::gofish(int targetp, string choice, int &win, int pturn){
   win = 0;
   int count = 0;
   if(phcheck(targetp, choice,count) == 0){
      cout << "GOOOOOOOOOOOOOOOOOOO FIIIIIIIIIIISSSSHHHHHHHH" << endl;
      draw(pturn);	}
   else{
      cout << "Player " << targetp+1 << " had " << count << " " << choice << "s" << endl;
      take(targetp,choice,pturn,count,win);
   }

   setcheck(targetp,win);
   if(win != 1){
      setcheck(pturn,win);
   }
   int cont;
   do{
      cout << "Press one to continue" << endl;
      cin >> cont;
   }while(cont != 1);

}

int Go_fish::phcheck(int targetp, string ch, int &count){
   counter(targetp,ch,count);

   return(count);
}

void Go_fish::counter(int targetp, string ch, int &count){
   for(int i = 0; i < players[targetp].hsize; i++){
      if(players[targetp].hand[i].rank == ch){
	 count += 1;
      }

   }  

}

void Go_fish::draw(int turn){

   int nsize = players[turn].hsize + 1;
   card *temp = new card[nsize];
   for(int i = 0; i < players[turn].hsize; i++){ //Assignment not working
      temp[i] = players[turn].hand[i];
   }
   temp[nsize - 1] = deckset.Deck[dcount];
   dcount += 1;
   delete [] players[turn].hand;
   players[turn].hand = new card[nsize];
   for(int i = 0; i < nsize; i++){
      players[turn].hand[i] = temp[i];
   }
   delete [] temp;
   players[turn].hsize = nsize;
}

void Go_fish::take(int targetp, string ch, int turn, int count, int &win){
   take1(targetp,ch,turn,count,win);
   take2(targetp,ch,turn,count,win);
}


void Go_fish::take1(int targetp, string ch, int turn, int count,int &win){
   int nsize = players[turn].hsize + count;
   card *temp = new card[nsize];		//card array?
   for(int i = 0; i < players[turn].hsize; i++){
      temp[i] = players[turn].hand[i];
   }
   int j = players[turn].hsize;
   for(int x = 0; x < players[targetp].hsize; x++){
      if(players[targetp].hand[x].rank == ch){
	 temp[j] = players[targetp].hand[x];
	 j++;
      }
   }
   delete [] players[turn].hand;
   players[turn].hand = new card[nsize];
   for(int i = 0; i < nsize; i++){
      players[turn].hand[i] = temp[i];
   }
   delete [] temp;
   players[turn].hsize = nsize;

}

void Go_fish::take2(int targetp, string ch, int turn, int count, int &win){
   int nsize= players[targetp].hsize - count;
   if(nsize > 0){
      card *temp = new card[nsize];
      int j=0;
      for(int i = 0; i < players[targetp].hsize; i++){
	 if(players[targetp].hand[i].rank != ch){
	    temp[j] = players[targetp].hand[i];
	    j++;
	 }
      }
      delete [] players[targetp].hand;
      players[targetp].hand = new card[nsize];
      for(int i = 0; i < nsize; i++){
	 players[targetp].hand[i] = temp[i];
      }
      delete [] temp;
      players[targetp].hsize = nsize;

   }
   else
      win = 1;


}

void Go_fish::setcheck(int player, int &win){
   string set; 
   int count = 0;
   for(int j = 0; j < 13; j++){
      count = 0;
      for(int i = 0; i < players[player].hsize; i++){

	 if(players[player].hand[i].rank == deckset.build[j].rank){
	    count +=1;

	    if(count == 4){
	       set = deckset.build[j].rank;
	       settake(player,set,win);
	       cout << "Player " << player+1 << " had four " << set  << "s" << endl;
	       break;
	    }
	 }
      }
   }
   winnerch(win,player);
}

void Go_fish::settake(int player, string set,int &win){
   int nsize = players[player].hsize - 4;


   if(nsize > 0){
      card *temp = new card[nsize]; 
      int j = 0;
      for(int i = 0; i < players[player].hsize; i++){
	 if(players[player].hand[i].rank != set){
	    temp[j] = players[player].hand[i];
	    j++;
	 }
      }
      delete [] players[player].hand;
      players[player].hand = new card[nsize];


      for(int i = 0; i < nsize; i++){
	 players[player].hand[i] = temp[i];
      }
      delete [] temp;
      players[player].hsize = nsize;
   }
   else
      win = 1;	

}

void Go_fish::winnerch(int &win, int player){
   if(players[player].hsize == 0){
      win = 1;
      cout << "Congratulations, player " << player << " wins!" << endl;
   }
}






