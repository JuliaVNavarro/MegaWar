#ifndef Game_h
#define Game_h
#include "CardPile.h"
#include "Deck.h"
#include "Player.h"
#include "MegaDeck.h"
#include "WarPile.h"
#include "LostFound.h"

class Game{

  private:
    vector<Player> allPlayers; //vector to contain all the players in the game
    MegaDeck d1; //deck for the game
    LostFound lost; //lost and found pile for the game
    int deckSize; //returns the game deck size
     
  public:
    Game(int d, int p); //game constructor that takes the parameters of the # of decks and # of players for the game
    void mega(); //display's the deck
    void showPlayers(); //displays the players and their stats
    void distribute(); //distributes cards evenly to each player. if there are extra cards in the pile that can't distribute to all players evenly, it will be placed in the lost and found pile
    void playGame(); //when all players play the game
    int battle(vector<int> t); //when players with matching cards go to war
    bool gameOver(); //returns true if the game is over or false if there is no winner yet
};

#endif