#ifndef WarPile_h
#define WarPile_h
#include "CardPile.h"
#include "Card.h"

class WarPile : public CardPile{
  
  public:

    void add1(Card c); //adds card to the war pile 
    Card dealWarPile(); //removes all the cards from the war pile
    vector<Card> getWarPile(); //returns the piles's vector

};

#endif