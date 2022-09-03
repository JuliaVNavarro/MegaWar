#include "Card.h"
#include "CardPile.h"
#include "Deck.h"
#include "Player.h"
#include "MegaDeck.h"
#include "WarPile.h"
#include "LostFound.h"
#include "Game.h"

//game constructor that takes the parameters of the # of decks and # of players for the game
Game::Game(int d, int p){
  
  for(int i = 1; i <= p; i++){
    Player tempP;
    allPlayers.push_back(tempP);
  }

  d1.add(d);
  d1.shuffle();
  deckSize = d1.getMegaDeck().size();

}

//display's the game's deck
void Game::mega(){

  cout << "\nHere is your MegaDeck: " << endl;
  d1.display();
  
}

//displays the players and their stats
void Game::showPlayers(){

  for(int i = 0; i < allPlayers.size(); i++){
    cout << "Player " << i + 1 << ": ";
    allPlayers[i].stats();
     cout << endl;
  }

}

//distributes cards evenly to each player. if there are extra cards in the pile that can't distribute to all players evenly, it will be placed in the lost and found pile
void Game::distribute(){

  int numberCards = floor(d1.getMegaDeck().size()/allPlayers.size()); //find the number of cards each player will get using floor division
  //distribute the cards to each player
  for(int i = 0; i < allPlayers.size(); i++){
    for(int j = 1; j <= numberCards; j++){
      allPlayers[i].add(d1.dealMegaDeck());
    }
  }
  //if there are extra cards the the deck that can't be distributed evenly, they will be placed in the lost and found pile
  if(d1.getMegaDeck().size() > 0){
    for(int k = 0; k < d1.getMegaDeck().size(); k++){
      lost.add(d1.getMegaDeck()[k]);
    }
  }
  //for debugging purposes!!!
 /* cout << "\nLost and Found pile: ";
  lost.display();

  for(int k = 0; k < allPlayers.size(); k++){
    cout << "Player " << k + 1 << "'s cards: ";
    allPlayers[k].showCards();
  }*/

}

//when all players play the game
void Game::playGame(){

  CardPile gamePile;
  Card highCard;

  //check to see if the players have enough cards to play one round
  for(int i = 0; i < allPlayers.size(); i++){
    if(allPlayers[i].cardTotal() > 0){
      allPlayers[i].playedBattle();
      gamePile.addCard(allPlayers[i].play());
    } else {
      Card c;
      gamePile.addCard(c);
    }
  }

  //for debugging purposes
  //gamePile.display();

  //find the highest card played
  highCard = gamePile.getPile()[0];
  for(int m = 1; m < gamePile.getPile().size(); m++){
    if(gamePile.getPile()[m] > highCard){
      highCard = gamePile.getPile()[m];
    }
    
  }
  /*cout << "Highest Card: ";
  highCard.display();*/

  //check to see if there are more than 1 high card
  vector<int> temp;
  for(int j = 0; j < gamePile.getPile().size(); j++){
      if(gamePile.getPile()[j] == highCard){
        temp.push_back(j);
      }  
  }

  /*cout << "\nPlayers with matching cards: <";
  for(int l = 0; l < temp.size(); l++){
    cout <<"Player "<< temp[l] + 1 << " ";
  }
  cout << ">" << endl;*/

  //if there is only one high card, that player is the winner and gets all the cards
  if(temp.size() == 1){
    while(gamePile.getPile().size() > 0){
      Card t;
      t = gamePile.removeCard();
      if(t.getValue() > 0){
        allPlayers[temp[0]].add(t);
      }
      
    }
    allPlayers[temp[0]].wonBattle();
  //otherwise, players with matching cards go to war to determine the winner
  } else {
    int win = battle(temp);
    allPlayers[win].wonBattle();
    while(gamePile.getPile().size() > 0){
      Card t;
      t = gamePile.removeCard();
      if(t.getValue() > 0){
        allPlayers[win].add(t);
      }
    }
  }

  
  //for debugging purposes
  /*cout << "\nLost and Found pile: ";
  lost.display();

  for(int k = 0; k < allPlayers.size(); k++){
    cout << "Player " << k + 1 << "'s cards: ";
    allPlayers[k].showCards();
  }*/
  
}

//returns the index the war's winner
int Game::battle(vector<int> t){
  //for debugging purposes
  //cout << "\nLETS GO TO WAR!!" << endl;

  //create 1 war pile where players will place 2 cards each, 1 war pile where players will place their card that will be used for battle
  WarPile war1;
  WarPile war2;
  Card highCard; //used to keep track of the highest card
  int index = 0; //the soon to be winning index

  //place the cards into the war piles if the player runs out of cards, then a blank card will be placed for them
  for(int i = 0; i < t.size(); i ++){
    Card b(BLANK1, BLANK2);
    allPlayers[t[i]].playedBattle();
    if(allPlayers[t[i]].cardTotal() >= 4){
      war1.addCard(allPlayers[t[i]].play());
      war1.addCard(allPlayers[t[i]].play());
      war1.addCard(allPlayers[t[i]].play());
      war2.addCard(allPlayers[t[i]].play());
    } else {
      for(int j = 0; j < allPlayers[t[i]].cardTotal(); j++){
        war1.addCard(allPlayers[t[i]].play());
      }
      war2.addCard(b);
    }
  }

  //for debugging purposes
  /*cout << "War1: ";
  war1.display();
  cout << "War2: ";
  war2.display();*/

  //find the highest card in the 2nd war pile (the battle pile)
  highCard = war2.getPile()[0];
  for(int m = 1; m < war2.getPile().size(); m++){
    
    if(war2.getPile()[m] > highCard){
      highCard = war2.getPile()[m];
    }
    
  }

  //for debugging purposes
  /*cout << "Highest Card: ";
  highCard.display();*/

  //if there are no cards in the battle it is because all players didn't have enough
  if(highCard.getValue() == 0){
    while(war1.getPile().size() > 0){
      lost.add(war1.removeCard());
    }

  //otherwise check to see which has the highest card/which have highest matching cards
  } else {
    vector<int> temp;
    for(int k = 0; k < war2.getPile().size(); k++){
      if(war2.getPile()[k] == highCard){
        temp.push_back(t[k]);
      }  
    }

    //for debugging purposes
    /*cout << "\nPlayers with matching cards in battle: <";
    for(int l = 0; l < temp.size(); l++){
      cout <<"Player "<< temp[l] + 1 << " ";
    }
    cout << ">" << endl;*/

    //if there is a winner, give them all of the non empty war pile cards and lost and found cards
    if(temp.size() == 1){
      index = temp[0]; //set the winner's index
      while(war1.getPile().size() > 0){
        Card c = war1.removeCard();
        if(c.getValue() > 0){
          allPlayers[temp[0]].add(c);
        }
      }
      while(war2.getPile().size() > 0){
        Card c = war2.removeCard();
        if(c.getValue() > 0){
          allPlayers[temp[0]].add(c);
        }
      }
      while(lost.getPile().size() > 0){
        allPlayers[temp[0]].add(lost.removeCard());
      }
    //if there are two matching highest cards, then the players go to war again and the winner gets their war piles, this war piles, and the lost and found cards
    } else{
      int win = battle(temp);
      index = win; //set winner's index
      while(war1.getPile().size() > 0){
        Card c = war1.removeCard();
        if(c.getValue() > 0){
          allPlayers[win].add(c);
        }
      }
      while(war2.getPile().size() > 0){
        Card c = war2.removeCard();
        if(c.getValue() > 0){
          allPlayers[win].add(c);
        }
      }
      while(lost.getPile().size() > 0){
        allPlayers[win].add(lost.removeCard());
      }
    }
  }
  return index;
}

//returns true if the game is over or false if there is no winner yet
bool Game::gameOver(){
  bool game = false;
  for(int i = 0; i < allPlayers.size(); i++){
    if(allPlayers[i].cardTotal() == deckSize){
      game = true;
    }
  }
  return game;
}