#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include "card.h"
#include "deck.h"
#include "player.h"
#define SPADE 0
#define HEART 1
#define DIAMOND 2
#define CLUB 3


using namespace std;

void dealHand(Deck &d, Player &p, int numCards)
{
   for (int i=0; i < numCards; i++)
      p.addCard(d.dealCard());
}
   


int main( )
{
    int numCards = 7;
    
    
    
    Player p1("Austin");
    Player p2("Justin");

    Player* players[2];

    players[0] = &p1;
    players[1] = &p2;

    ofstream myFile("textLog.txt");


    int playerIndex = 0;
    
    Deck d;  //create a deck of cards
    d.shuffle();

    
    
    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);

    myFile << "Start Game" << endl;

       
    // cout << p1.getName() <<" has : " << p1.showHand() << endl;
       myFile << p1.getName() <<" has : " << p1.showHand() << endl;

   //  cout << p2.getName() <<" has : " << p2.showHand() << endl;
       myFile << p2.getName() <<" has : " << p2.showHand() << endl;
    
    do {
        // main driver for go fish
          Player* playerUp = players[playerIndex];
          Player* otherPlayer = players[(playerIndex + 1)%2];
        // check for matches & go into book



        // ask other player for cards & based on that we go into the next turn same player could go in a row

        Card c1;
        Card c2;

       // cout << playerUp->getName() << " hand: " << playerUp->showHand() << endl;
       myFile << playerUp->getName() << " hand: " << playerUp->showHand() << endl;

        while (playerUp->checkHandForBook(c1, c2) == true) {
            playerUp->removeCardFromHand(c1);
            playerUp->removeCardFromHand(c2);
            // cout << playerUp->getName() << " puts " << c1.toString() << " and " << c2.toString() << " in his book" << endl;
            myFile << playerUp->getName() << " puts " << c1.toString() << " and " << c2.toString() << " in his book" << endl;
            playerUp->bookCards(c1, c2);
        }

        
 
        if (playerUp->getHandSize() == 0) {
            if (otherPlayer->getHandSize() == 0) {
             //  cout << "Both players have no cards left, game over" << endl;
             myFile << "Both players have no cards left, game over" << endl;
                break;
            }

           // cout << playerUp->getName() << " hand is empty" << endl;

            myFile << playerUp->getName() << " hand is empty" << endl;

            if (d.size() > 0) {
                Card newDraw = d.dealCard();
                playerUp->addCard(newDraw);
                //cout << playerUp->getName() << " draws " << newDraw.toString() << endl;
                myFile << playerUp->getName() << " draws " << newDraw.toString() << endl;
            }

            playerIndex = (playerIndex + 1)%2;
            continue;
        }
        
         Card chosen = playerUp->chooseCardFromHand();

         // cout << playerUp->getName() << " asks if you have a " << chosen.getRank() << endl;
         myFile << playerUp->getName() << " asks if you have a " << chosen.getRank() << endl;

        

        if (otherPlayer->rankInHand(chosen) == true) {
            // that player gives them all of that hand
            for (int suit = 0; suit < 4; suit++) {
                Card rankedCard(chosen.getRank(), (Card::Suit) suit);
                if (otherPlayer->cardInHand(rankedCard)) {

                    otherPlayer->removeCardFromHand(rankedCard);
                    playerUp->addCard(rankedCard);

                   // cout << otherPlayer->getName() << " gives " << playerUp->getName() << " a " << rankedCard.toString() << endl;
                    myFile << otherPlayer->getName() << " gives " << playerUp->getName() << " a " << rankedCard.toString() << endl;

                }
            }

            

            
        } else {
           // cout << otherPlayer->getName() << " says Go Fish" << endl;
            myFile << otherPlayer->getName() << " says Go Fish" << endl;
            // go fish, playerUp draws a card
            if (d.size() > 0) {
                Card newCard = d.dealCard();
                playerUp->addCard(newCard);
                // cout << playerUp->getName() << " draws a " << newCard.toString() << endl;
                myFile << playerUp->getName() << " draws a " << newCard.toString() << endl;
            } else {
               // cout << "There are no cards left, moving on to " << otherPlayer->getName() << "'s turn" << endl;   
                myFile << "There are no cards left, moving on to " << otherPlayer->getName() << "'s turn" << endl;
                         
            }
            

            // switch players
            playerIndex = (playerIndex + 1)%2;
            
        }


        



       







    } while (true);
    if (p1.getBookSize() > p2.getBookSize()) {

       // cout << p1.getName() << " wins by " << (p1.getBookSize() - p2.getBookSize())/2 << " books" << endl;
        myFile << p1.getName() << " wins by " << (p1.getBookSize() - p2.getBookSize())/2 << " books" << endl;

    } else if (p1.getBookSize() < p2.getBookSize()) {
        // cout << p2.getName() << " wins by " << (p2.getBookSize() - p1.getBookSize())/2 << " books" << endl;
        myFile << p2.getName() << " wins by " << (p2.getBookSize() - p1.getBookSize())/2 << " books" << endl;

    } else {
        // its a tie!

      //  cout << "Both players had 13 books, it's a tie!" << endl;
        myFile << "Both players had 13 books, it's a tie!" << endl;
    }



    


    
    return EXIT_SUCCESS;  
}



