#include <string>
#include <iostream>
#include "card.h"

using namespace std;

Card::Card() {
    myRank = 1;
    mySuit = spades;

}


Card::Card(int rank, Suit s) {
    myRank = rank;
    mySuit = s;
}

int Card::getRank() const {
    return (myRank);
}

string Card::suitString(Suit s) const {

    switch (mySuit) {
        case spades:
            return "s";
        case hearts:
            return "h";
        case clubs: 
            return "c";
        case diamonds:
            return "d";

    }

}






string Card::rankString(int r) const {
    switch (myRank) {
        case (1):
            return "A";
        case (11):
            return "J";
        case (12):
            return "Q";
        case (13): 
            return "K";
        default:
            return (to_string(myRank));

    }
}

string Card::toString() const {
    string card = this->rankString(myRank) + this->suitString(mySuit);

    return card;


}


bool Card::sameSuitAs(const Card& c) const {
    if (this->mySuit == c.mySuit) {
        return true;
    } else {
        return false;
    }
}

void Card::swap(Card &c) {
    Suit tempSuit = c.mySuit;
    int tempRank = c.getRank();

    c.mySuit = this->mySuit;
    c.myRank = this->getRank();

    this->mySuit = tempSuit;
    this->myRank = tempRank;

}

bool Card::operator== (const Card &rhs) const {
    if (sameSuitAs(rhs) && this->myRank == rhs.myRank) {
        return true;
    } else {
        return false;
    }
}

bool Card::operator!= (const Card &rhs) const {
    if (sameSuitAs(rhs) && this->myRank == rhs.myRank) {
        return false;
    } else {
        return true;
    }
}

ostream& operator << (ostream& out, const Card& c) {
    out << c.toString() << endl;
    return out;
}

