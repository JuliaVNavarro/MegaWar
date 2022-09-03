#include "MegaDeck.h"
#include "Deck.h"
#include "Card.h"

void MegaDeck::add(int n){

  int count = 1;
  while(count <= n){
    Deck tempD;
    for(int i = 0; i < 52; i++){
      addCard(tempD.getDeck()[i]);
    }
    count += 1;
    
  }  

}

Card MegaDeck::dealMegaDeck(){

  return removeCard();

}

//return the mega deck 
vector<Card> MegaDeck::getMegaDeck(){

  return this->pile;

}