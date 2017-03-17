/***************************************************************************
 * Program Filename: main.cpp
 * Author: Cameron Stuart
 * Date: May 8, 2014
 * Description: starts process for player to choose two games
 * Input: game choice
 * Output: game is played
 **************************************************************************/


#include <iostream>
#include "CardGames.h"
#include "Go_fish.h"
#include "Poker.h"

using namespace std;

/***************************************************************************
 *Function: choose_game()
 *Description: Allows for player game choice
 *Parameters: none
 *Pre-Conditions: none
 *Post-Conditions: Game char is returned
 * ************************************************************************/
char choose_game();


int main(){
   Card_Games *game;
   char game_choice;

   game_choice = choose_game();

   if(game_choice == 'p')
      game = new Poker;
   else if(game_choice == 'g')
      game = new Go_fish;

   game -> play();



   return 0;
}


char choose_game(){
   char choice;
   cout << "Please choose which game you would like to play" << endl;
   cout << "To play Go Fish type the letter g, or to play poker the letter p" << endl;
   cin >> choice;
   if((choice != 'p') && (choice != 'g')){
      cout << "Error, invalid game choice please try again" << endl;
      choose_game();
   }

   return (choice);

}



