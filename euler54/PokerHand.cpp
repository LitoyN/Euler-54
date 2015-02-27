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

int *cards;
int card1;
int card2;
int card3;
int card4;
int card5;
int sumAll;
bool royalFlush();

PokerHand::PokerHand(int* cardsInHand) {
    sumAll = 0;
    cards = cardsInHand;
    card1 = cards[0];
    card2 = cards[1];
    card3 = cards[2];
    card4 = cards[3];
    card5 = cards[4];
    for(int i = 0; i < 5; i++)
        sumAll += cards[i];
    
}

void PokerHand::printHand(){
    cout << card1 << ", " << card2 << ", " << card3 << ", " << card4 << ", " << card5 << endl;
    cout << sumAll << endl;
}

int PokerHand::rankHand(){
    if(straight())
        return 666;
    else
        return 141414;
}

bool PokerHand::royalFlush(){
    if((sumAll == (31 * card1 - 26) || sumAll == (31 * card1 - 52) ||
            sumAll == (31 * card1 - 104) || sumAll == (31 * card1 - 208)) && card1 < 25)
        return true;
    else
        return false;
}//royalFlush works

bool PokerHand::straightFlush(){
    if(sumAll == (31 * card1 - 26) || sumAll == (31 * card1 - 52) ||
            sumAll == (31 * card1 - 104) || sumAll == (31 * card1 - 208))
        return true;
    else
        return false;
}//straightFlush works

bool PokerHand::fourOfKind(){
    if(((sumAll - card1) == (4 * card1 + 11)|| (sumAll - card1) == (4 * card5 -17)) ||
            ((sumAll - card5) == (4 * card1 + 11)|| (sumAll - card5) == (4 * card5 -17)))
        return true;
    else
        return false;
    
}//fourOfKind works


bool PokerHand::fullHouse(){
    if((card2-card1 <= 7 && card5-card3 <= 7) || (card3-card1 <= 7 && card5-card4 <= 7))
        return true;
    else
        return false;
}//fullHouse works

bool PokerHand::straight(){
    bool straight = false;
    //int i = 0;
    for(int i = 0; i < 4; i++){
        if((cards[i+1] - (cards[i]*2-8) <=14 && cards[i+1] - (cards[i]*2-8) >= -7) && 
                (cards[i+1] - (cards[i]*2-1) <= 7 && cards[i+1] - (cards[i]*2-1) >= -14))
            straight = true;
        else
            return false;
    }
    return straight;
} 

bool PokerHand::flush(){
    int value = 15;
    for(int i = 0; i < 5; i++){
        value = value&cards[i];
    }
    if(value != 0)
        return true;
    else
        return false;
}//flush works

bool PokerHand::threeOfKind(){
    if((card3-card2 <7 && card2-card1 < card3-card2)||
            (card5-card4 <7 && card4-card2 < card5-card4)||
                (card3-card1 <=7 || card5-card3 <=7))
        return true;
    else
        return false;
}//threeOfKind works

bool PokerHand::twoPair(){
    if((card2-card1 <= 7 && (card5-card4 <= 7 || card4-card3 <=7))||
            card5-card4 <=7 && (card3-card2 <=7))
        return true;
    else
        return false;
}//twoPair works

bool PokerHand::pair(){
    for(int i = 0; i < 4; i++){
        if(cards[i+1] - cards[i] <=7)
            return true;
    }
    return false;
}//pair works


