#include "Deck.h"
#include "Card.h"

//default constructor
Deck::Deck(){
  
  for(int i = SPADE; i <= CLUBS; i++){
    for(int j = ACE; j <= KING; j++){
      pile.push_back(Card(Rank(j), Suit(i)));
    }
  }
  
}

//deals a card by removing it from the deck and returning it
Card Deck::dealDeck(){

  return removeCard();
  
}

//returns the deck's vector
vector<Card> Deck::getDeck(){

  return this->pile;
  
}