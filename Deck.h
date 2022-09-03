#ifndef Deck_h
#define Deck_h
#include "CardPile.h"
#include "Card.h"

class Deck : public CardPile{

  public:

  Deck(); //default constructor
  Card dealDeck(); //deals a card by removing it from the deck and returning it
  vector<Card> getDeck(); //returns the deck's vector
  
};

#endif