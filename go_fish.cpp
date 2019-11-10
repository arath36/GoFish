#include <cstdlib>
#include <iostream>
#include "card.h"
#include "deck.h"


using namespace std;


int main(int argc, char *argv[]) {

    Deck d;
    d.shuffle();

    while (d.size() > 0) {
        
        Card c = d.dealCard();
        cout << c;
        



    }


    return 0;

}