#ifndef Card_h
#define Card_h
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

//enum types for the card rank
enum Rank{BLANK1, ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};
//enum types for the card suit
enum Suit {BLANK2, SPADE, HEART, DIAMOND, CLUBS};

class Card{

  private:

    Rank r; //card's rank using enum
    Suit s; //card's suit using enum
    int value; //card's int value
  
  public:

    Card(); //default contructor
    Card(Rank ra, Suit su); //constructor with rank and suit parameters
    bool operator <(Card right); //less than operator to compare two cards
    bool operator ==(Card right); //equal to operator to comapre two cards
    bool operator >(Card right); //greater than operator to comapre two cards
    void setCard(Rank ra, Suit su); //set a card's rank and Suit
    int getValue(); //get the int value of a card
    void display(); //display the card's rank and suit

};

#endif