#include "LostFound.h"
#include "Deck.h"
//#include "Card.h"


//adds card to the lost and found pile
void LostFound::add(Card c){

  addCard(c);

}

//removes a card from the lost and found pile
Card LostFound::dealLostFound(){
  
  return removeCard();

}

//returns the lost and found pile 
vector<Card> LostFound::getLostFound(){

  return this->pile;

}