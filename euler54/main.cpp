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

using namespace std;

int boolToDec(bool array[]);

char value;
char suit;
ifstream allHands("poker.txt");
char valsSuits[17] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A', 'C', 'D', 'H', 'S'};
bool card[17];
int cardDec;
int hand[5];
//PokerHand hand1;
//PokerHand hand2;



void parseFromFile(ifstream& pokerFile){
    
    
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
    }
    sort(hand, hand+5);
    
    for(int i = 0; i < 5; i++){
       cout<< hand[i] << ", ";
    }
    cout<<endl;
}

int boolToDec(bool cardArray[]){
    cardDec = 0;
    for(int i = 0; i < 17; i++){
        if(cardArray[i])
            cardDec += pow(2, 16-i);
    }
    return cardDec;
    
}

/*
 * 
 */
int main(int argc, char** argv) {

    while(allHands){
        parseFromFile(allHands);
        //hand1(parseFromFile(allHands));
        //hand2(parseFromFile(allHands));
    }

    return 0;
}

