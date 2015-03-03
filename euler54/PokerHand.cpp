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

//int cards[5];


PokerHand::PokerHand(int* cardsInHand) {
    sumAll = 0;
    compareVal = -1;
    for(int i = 0; i < 5; i++){
        cards[i] = cardsInHand[i];
    }
    card1 = cardsInHand[0];
    card2 = cardsInHand[1];
    card3 = cardsInHand[2];
    card4 = cardsInHand[3];
    card5 = cardsInHand[4];
    for(int i = 0; i < 5; i++)
        sumAll += cardsInHand[i];
    
}

void PokerHand::printHand(){
    //cout << card1 << ", " << card2 << ", " << card3 << ", " << card4 << ", " << card5 << endl;
    cout << cards[0] << ", " << cards[1] << ", " << cards[2] << ", " << cards[3] << ", " << cards[4] << endl;
    //cout << sumAll << endl;
}

int PokerHand::rankHand(){
    if(royalFlush())
        return 9;
    else if(straightFlush())
        return 8;
    else if(fourOfKind())
        return 7;
    else if(fullHouse())
        return 6;
    else if(straight())
        return 5;
    else if(flush())
        return 4;
    else if(threeOfKind())
        return 3;
    else if(twoPair())
        return 2;
    else if(pair())
        return 1;
    else
        compareVal = 0;
        return 0;
}

int PokerHand::getHighest(){
    return card1;
}

int PokerHand::getCard(int index){
    return cards[index];
}

int PokerHand::getCompare(){
    return compareVal;
}

bool PokerHand::royalFlush(){
    if((sumAll == (31 * card1 - 26) || sumAll == (31 * card1 - 52) ||
            sumAll == (31 * card1 - 104) || sumAll == (31 * card1 - 208)) && card1 < 25){
        return true;
    }
    else
        return false;
}//royalFlush works

bool PokerHand::straightFlush(){
    if(sumAll == (31 * card1 - 26) || sumAll == (31 * card1 - 52) ||
            sumAll == (31 * card1 - 104) || sumAll == (31 * card1 - 208)){
        compareVal = 0;
        return true;
    }
    else
        return false;
}//straightFlush works

bool PokerHand::fourOfKind(){
    if(((sumAll - card1) == (4 * card1 + 11)|| (sumAll - card1) == (4 * card5 -17)) ||
            ((sumAll - card5) == (4 * card1 + 11)|| (sumAll - card5) == (4 * card5 -17))){
        compareVal = 3;
        return true;
    }
    else
        return false;
    
}//fourOfKind works


bool PokerHand::fullHouse(){
    if((card2-card1 <= 7 && card5-card3 <= 7) || (card3-card1 <= 7 && card5-card4 <= 7)){
        compareVal = 2;
        return true;
    }
    else
        return false;
}//fullHouse works

bool PokerHand::straight(){
    bool straight = false;
    //int i = 0;
    for(int i = 0; i < 4; i++){
        if((cards[i+1] - (cards[i]*2-8) <=14 && cards[i+1] - (cards[i]*2-8) >= -7) && 
                (cards[i+1] - (cards[i]*2-1) <= 7 && cards[i+1] - (cards[i]*2-1) >= -14)){
            compareVal = 0;
            straight = true;
        }
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
    if(value != 0){
        compareVal = 0;
        return true;
    }
    else
        return false;
}//flush works

bool PokerHand::threeOfKind(){
    if((card3-card2 <7 && card2-card1 < card3-card2)||
            (card5-card4 <7 && card4-card2 < card5-card4)||
                (card3-card1 <=7 || card5-card3 <=7)){
        compareVal = 2;
        return true;
    }
    else
        return false;
}//threeOfKind works

bool PokerHand::twoPair(){
    if((card2-card1 <= 7 && (card5-card4 <= 7 || card4-card3 <=7))||
            card5-card4 <=7 && (card3-card2 <=7)){
        compareVal = 3;
        return true;
    }
    else
        return false;
}//twoPair works

bool PokerHand::pair(){
    for(int i = 0; i < 4; i++){
        if(cards[i+1] - cards[i] <=7){
            compareVal = i;
            return true;            
        }

    }
    return false;
}//pair works


