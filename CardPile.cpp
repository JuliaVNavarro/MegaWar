#include "CardPile.h"
using namespace std;

//add a card to the card pile
void CardPile::addCard(Card c){

  pile.push_back(c);

}

//remove a card from the card pile & return it
Card CardPile::removeCard(){

  Card temp = pile[pile.size() - 1];
  pile.pop_back();
  return temp;

}

//display the cards in the pile
void CardPile::display(){

  if(pile.size() > 0){
    for(int i = 0; i < pile.size(); i++){
      pile[i].display();
      cout << " ";
    }
    cout << "\nsize: " << pile.size() << endl; //for debugging purposes!!!
  } else {
    cout << "Deck is empty!" << endl;
  }
  

}

//shuffle the cards in the pile
void CardPile::shuffle(){

  srand(time(0));
  random_shuffle(pile.begin(), pile.end());

}

//sort the cards in the pile
void CardPile::sort(){
  
  std::sort(pile.begin(), pile.end());
  
}

//returns the pile
vector<Card> CardPile::getPile(){
  return this->pile;
}