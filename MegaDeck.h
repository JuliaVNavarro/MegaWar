#ifndef MegaDeck_h
#define MegaDeck_h
#include "CardPile.h"
//#include "Card.h"

class MegaDeck : public CardPile{

  public:

    void add(int n); //adds card to the mega deck
    Card dealMegaDeck(); //deals a card from the mega deck
    vector<Card> getMegaDeck(); //return the mega deck 
};

#endif