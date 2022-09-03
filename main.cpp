#include <iostream>
#include "Card.h"
#include "CardPile.h"
#include "Deck.h"
#include "Player.h"
#include "MegaDeck.h"
#include "Game.h"

int main() {
  
  cout << "Welcome to MEGA WAR!!!\nEnter the number of PLAYERS for this game: ";
  int p;
  cin >> p;
  cout << "\nEnter the number of DECKS for this game: ";
  int d;
  cin >> d;
  
  Game g(d, p);
  g.distribute();
  g.showPlayers();

  int count = 0;
  bool game = g.gameOver();
  while(game == false){
  
    game = g.gameOver();
    if(game == true){
      cout << "\nGAME OVER!!!";
      break;
    }
    cout << "Battle " << count << " stats:\n" << endl;
    g.playGame();
    g.showPlayers();
    
    count += 1;
  }
  
} 