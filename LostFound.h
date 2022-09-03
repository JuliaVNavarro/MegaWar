#ifndef LostFound_h
#define LostFound_h
#include "CardPile.h"
//#include "Card.h"

class LostFound : public CardPile{

  public:
    void add(Card c); //adds card to the lost and found pile
    Card dealLostFound(); //removes a card from the lost and found pile
    vector<Card> getLostFound(); //returns the lost and found pile 

};

#endif