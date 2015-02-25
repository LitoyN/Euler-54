/* 
 * File:   main.cpp
 * Author: elliot
 *
 * Created on February 19, 2015, 9:45 PM
 */


#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include "PokerHand.h"

using namespace std;

int boolToDec(bool array[]);

char value;
char suit;
ifstream allHands("poker2.txt");
char valsSuits[17] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A', 'C', 'D', 'H', 'S'};
bool card[17];
int cardDec;
int hand[5];
//PokerHand hand1;
//PokerHand hand2;



int* parseFromFile(ifstream& pokerFile){
    
    //int sum = 0;
    for(int i = 0; i < 5; i++){
        pokerFile >> value;
        pokerFile >> suit;
        for(int j = 0; j < 17; j++){
            if (value == valsSuits[j] || suit == valsSuits[j])
                card[j] = true;
            else
                card[j] = false;
        }
        hand[i] = boolToDec(card);
        //cout << hand[i] << ", ";
        //sum += hand[i];
    }
    sort(hand, hand+5);
    //cout<<endl << sum<<endl;
    return hand;
}

int boolToDec(bool cardArray[]){
    cardDec = 0;
    for(int i = 0; i < 17; i++){
        if(cardArray[i])
            cardDec += pow(2, 17-i);
    }
    return cardDec/2;
    
}

/*
 * 
 */
int main(int argc, char** argv) {

    //PokerHand hand1(hand);
    while(allHands){
        //parseFromFile(allHands);
        PokerHand hand1(parseFromFile(allHands));
        hand1.printHand();
        //if(hand1.rankHand() == 666)
            //hand1.printHand();
        //PokerHand hand2(parseFromFile(allHands));
        //hand2.printHand();
    }

    return 0;
}

