/* 
 * File:   PokerHand.cpp
 * Author: elliot
 * 
 * Created on February 22, 2015, 4:46 PM
 */

#include "PokerHand.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int *cardsInHand;
int card1;
int card2;
int card3;
int card4;
int card5;

PokerHand::PokerHand(int cards[]) {
    //cardsInHand = cards[0];
    card1 = cards[0];
    card2 = cards[1];
    card3 = cards[2];
    card4 = cards[3];
    card5 = cards[4];
}

void PokerHand::printHand(){
    cout << card1 << ", " << card2 << ", " << card3 << ", " << card4 << ", " << card5 << endl;
}


