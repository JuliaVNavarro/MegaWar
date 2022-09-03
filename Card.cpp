#include "Card.h"
#include <iostream>
#include <string>
using namespace std;

//default contructor
Card::Card(){

  r = BLANK1;
  s = BLANK2;

}

//constructor with rank and suit parameters
Card::Card(Rank ra, Suit su){

  r = ra;
  s = su;
  
}

//less than operator to compare two cards
bool Card::operator <(Card right){

  return this->r<right.r?true:false;

}

//equal to operator to comapre two cards
bool Card::operator ==(Card right){

  return this->r==right.r?true:false;

}

//greater than operator to comapre two cards
bool Card::operator >(Card right){

  return this->r>right.r?true:false;

}

//set a card's rank and Suit
void Card::setCard(Rank ra, Suit su){

  r = ra;
  s = su;

}

//get the int value of a card
int Card::getValue(){

  return r;

}

//display the card's rank and suit
void Card::display(){
  
  switch(r){
    case BLANK1: 
      cout << "Blank";
      break;
    case ACE:
      cout << 'A';
      break;
    case TWO:
      cout << '2';
      break;
    case THREE:
      cout << '3';
      break;
    case FOUR:
      cout << '4';
      break;
    case FIVE:
      cout << '5';
      break;
    case SIX:
      cout << '6';
      break;
    case SEVEN:
      cout << '7';
      break;
    case EIGHT:
      cout << '8';
      break;
    case NINE:
      cout << '9';
      break;
    case TEN:
      cout << "10";
      break;
    case JACK:
      cout << 'J';
      break;
    case QUEEN:
      cout << 'Q';
      break;
    case KING:
      cout << 'K';
      break;
  }

  switch(s){
    case BLANK2:
      cout << "Blank";
      break;
    case SPADE:
      cout << 'S';
      break;
    case HEART:
      cout << 'H';
      break;
    case DIAMOND:
      cout << 'D';
      break;
    case CLUBS:
      cout << 'C';
      break;
  }
  cout << " ";

}