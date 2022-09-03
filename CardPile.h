#ifndef CardPile_h
#define CardPile_h
#include "Card.h"
#include <vector>
#include <algorithm>
#include <ctime>
#include <random>
using namespace std;

class CardPile{

  protected: //using protected vs private so that CardPile can be used for inheritance 

    vector<Card> pile; //vector to hold the card's pile

  public:

    void addCard(Card c); //add a card to the card pile
    Card removeCard(); //remove a card from the card pile & return it
    void display(); //display the cards in the pile
    void shuffle(); //shuffle the cards in the pile
    void sort(); //sort the cards in the pile
    vector<Card> getPile(); //returns the pile
    
  };

#endif

