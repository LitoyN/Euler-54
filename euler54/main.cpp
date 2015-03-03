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

//char value;
//char suit;
ifstream allHands("poker.txt");
char valsSuits[17] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A', 'C', 'D', 'H', 'S'};
bool card[17];
int cardDec;

int player1Wins = 0;
int player2 = 0;
int handsPlayed = 0;



int* parseFromFile(ifstream& pokerFile){
    
    char value;
    char suit;
    int hand[5];
    
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

int checkWinner(PokerHand hand1, PokerHand hand2){
    int hand1Val = hand1.rankHand();
    int hand2Val = hand2.rankHand();
    if(hand1Val > hand2Val){
        player1Wins++;
        /**cout<< "Player 1 Wins: " << player1Wins << endl << "Player 1: ";
            hand1.printHand();
            cout<< "Player 2: ";
            hand2.printHand();
            cout<<"Value: "<<hand1Val<<endl << "Hand: " << handsPlayed << endl;**/
    }

    else if(hand1Val == hand2Val){
        if(hand1Val == 0){
            for(int i = 0; i < 5; i++){
                if(hand2.getCard(i) < hand1.getCard(i) && hand1.getCard(i)-hand2.getCard(i) > 7){
                    break;
                    }
                if(hand2.getCard(i) > hand1.getCard(i) && hand2.getCard(i)-hand1.getCard(i) > 7){
                    player1Wins++;
                    cout<< "Player 1 Wins: " << player1Wins << endl << "Player 1: ";
                    hand1.printHand();
                    cout<< "Player 2: ";
                    hand2.printHand();
                    cout<<"Value: "<<hand1Val<<endl << "Hand: " << handsPlayed << endl;
                    break;
                }
            }
        }
        else if(hand2.getCard(hand2.getCompare()) - hand1.getCard(hand1.getCompare()) > 7){
            player1Wins++;
            cout<< "Player 1 Wins: " << player1Wins << endl << "Player 1: ";
            hand1.printHand();
            cout<< "Player 2: ";
            hand2.printHand();
            cout<<"Value: "<<hand1Val<<endl << "Hand: " << handsPlayed << endl;
        }
    }
}

/*
 * 
 */
int main(int argc, char** argv) {

    //PokerHand hand1(hand);
    while(!allHands.eof()){
        //parseFromFile(allHands);
        handsPlayed++;
        PokerHand hand1(parseFromFile(allHands));
        PokerHand hand2(parseFromFile(allHands));
        //hand1.printHand();
        //hand2.printHand();

        checkWinner(hand1, hand2);
        
        
    }
    cout<<"Player 1 wins: " << player1Wins<< endl;
    cout<<"Player 2 wins: " << player2<< endl;

    return 0;
}

