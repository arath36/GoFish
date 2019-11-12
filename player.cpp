#include <iostream>
#include <string>
#include <vector>
#include "player.h"
using namespace std;


Player::Player() {
    myName = "Default";
    unsigned int currentTime = (unsigned)time(0);
    srand(currentTime);
}

void Player::addCard(Card c) {
    myHand.push_back(c);
}


void Player::bookCards(Card c1, Card c2) {
    myBook.push_back(c1);
    myBook.push_back(c2);
}

 int Player::getHandSize() const {
     return myHand.size();

 }
 int Player::getBookSize() const {
     return myBook.size();
 } 

  bool Player::checkHandForBook(Card &c1, Card &c2) {
      if (myHand.size() <= 1) {
          return false;
      }
      for (int i = 0; i<myHand.size(); i++) {
          for (int j = 0; j < myHand.size(); j++) {
              if (i == j) {
                  // doesn't compare same cards
                  continue;
              }

              if (myHand[i].getRank() == myHand[j].getRank()) {
                  c1 = myHand[i];
                  c2 = myHand[j];

                  return true;
              }


          }
      }




      return false;
  }


bool Player::rankInHand(Card c) const {
    for (int i = 0; i < myHand.size(); i++) {
        if (myHand[i].getRank() == c.getRank()) {
            return true;
        }
    }
    // if we get here, then nothing matched
    return false;
}


Card Player::chooseCardFromHand() const {
    int index = rand()%myHand.size();

    return myHand[index];

}


bool Player::cardInHand(Card c) const {
    for (int i = 0; i<myHand.size(); i++) {
        if (c == myHand[i]) {
            return true;
        }
    }

    return false;

}

string Player::showHand() const {
    string hand = "";
    for (int i = 0; i < myHand.size(); i++) {
        string cardString = myHand[i].toString() + " ";    
        hand = hand + cardString;
        
    }

    return hand;


}
string Player::showBooks() const {
    string book = "";
    for (int i = 0; i < myBook.size(); i++) {
        string bookString = myBook[i].toString() + " ";    
        book = book + bookString;
        
    }

    return book;



} 

Card Player::removeCardFromHand(Card c) {
    // this function is guaranteed to delete a card bc we know it exists in our hand
    for (int i = 0; i<myHand.size(); i++) {
        if (myHand[i] == c) {
            myHand.erase(myHand.begin() + i);
        }
    }

    return c;

}