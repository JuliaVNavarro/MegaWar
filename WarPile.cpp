#include "WarPile.h"
#include "Deck.h"
//#include "Card.h"

//adds card to the war pile 
void WarPile::add1(Card c){

  addCard(c);
  

}

//removes all the cards from the war pile
Card WarPile::dealWarPile(){

  return removeCard();

}

//returns the piles's vector
vector<Card> WarPile::getWarPile(){

  return this->pile;

}


