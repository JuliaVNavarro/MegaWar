#ifndef Player_h
#define Player_h
#include "CardPile.h"
//#include "Card.h"

//Player class that is inheriting CardPile class
class Player : public CardPile{

  private:

    float fierce; //player's fierceness
    int battleP; //player's battles played
    int battleW; //player's battles won


  public:

    Player(); //each player is constructed with a fierceness of 0, no battles played, and no battles won
    void add(Card c); //a card is added to the player's hand
    Card play(); //the player removes a card from their hand when they play a card
    int cardTotal(); //return the player's total cards in their hand
    float fierceness(); //return the players fierceness of their current cards
    void playedBattle(); //adds 1 to a player's total battles played
    int battlesPlayed(); //returns the player's total battles played
    void wonBattle(); //adds 1 to the player's total battles won
    int battlesWon(); //return player's total battles that they have won
    void stats();
    void showCards();
    
  
};

#endif