#include <string>
#include <iostream>
#include "deck.h"

using namespace std;

Deck::Deck() {
    myIndex = 0;
    int constructorIndex = 0;
    unsigned int currentTime = (unsigned)time(0);
    srand(currentTime);

    for (int i = 0; i < 4 ; i++) {
        for (int j = 1; j <= 13; j++) {
            Card c(j, (Card::Suit) i);
            myCards[constructorIndex] = c;
            constructorIndex++;

        }
    }

}

void Deck::shuffle() {


    for (int i = 0; i < 300 ; i++) {
        int rand1 = rand()%52;
        int rand2 = rand()%52;

        myCards[rand1].swap(myCards[rand2]);

        

        
    }
    




}

Card Deck::dealCard() {
    Card c = myCards[myIndex];

    myIndex++;

    return c;
}

int  Deck::size() const {
    return (52 - myIndex);
}