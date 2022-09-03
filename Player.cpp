#include"Player.h"
#include "Card.h"
#include <iomanip>

//each player is constructed with a fierceness of 0, no battles played, and no battles won
Player::Player(){
  fierce = 0;
  battleP = 0;
  battleW = 0;
}

//a card is added to the player's hand
void Player::add(Card c){

  addCard(c);

}

//the player removes a card from their hand when they play a card
Card Player::play(){
  
  return removeCard();

}

//return the player's total cards in their hand
int Player::cardTotal(){
  
  return pile.size();

}

//return the players fierceness of their current cards
float Player::fierceness(){
  fierce = 0;
  int s = pile.size();
  float f = 0.0;
  if(s == 0){
    fierce = 0;
  } else {
      for(int i = 0; i < s; i++){
        f += pile[i].getValue();
      }
      
      fierce = f/s;
  }
  return fierce;

}

void Player::playedBattle(){

  battleP += 1;

}

//return player's total battles played
int Player::battlesPlayed(){

  return battleP;

}

//adds 1 to the player's total battles won
void Player::wonBattle(){

  battleW += 1;

}

//return player's total battles that they have won
int Player::battlesWon(){

  return battleW;

}

//display the player's name, fierceness, total number of cards in their hand, total number of battles, and total number of battles won
void Player::stats(){

  cout << "Fierceness = " << fierceness() << setw(10) << "Cards = " << cardTotal() << setw(13) << "Battles = " << battleP << setw(10) << "Won = " << battleW << endl;
  

}

void Player::showCards(){

  for(int i = 0; i < pile.size(); i++){
    this->pile[i].display();
    cout << " ";
  }
  cout << endl;

}