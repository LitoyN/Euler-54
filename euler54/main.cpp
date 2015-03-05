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

ifstream allHands("poker.txt");
char valsSuits[17] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A', 'C', 'D', 'H', 'S'};
int player1Wins = 0;


/**
 * 
 * @param pokerFile: the in-file stream that is reading from the poker.txt file
 * @return: the decimal value that is unique to each card in the deck, based on the boolean array representation
 */
int* parseFromFile(ifstream& pokerFile){
    
    bool card[17];
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

/**
 * This function is given a 17 index boolean array, interprets its contents as a binary number, and converts it to decimal
 * 
 * @param cardArray: the 17 index array that represents each individual card.
 * @return: an int value that is equivalent to the binary that makes up the boolean array
 */
int boolToDec(bool cardArray[]){
    int cardDec = 0;
    for(int i = 0; i < 17; i++){
        if(cardArray[i])
            cardDec += pow(2, 17-i);
    }
    return cardDec/2;
}

/**
 * This takes 2 hands and runs the rankHand function to determine what kind of play each hand has.
 * player1Wins is increased by 1 if player 1 has a higher value hand. It performs a few secondary checks if the hands are ranked equally,
 * to check value of certain individual cards such as highest value card in hand, or value of card involved in relevant play.
 * eg, if both hands have a pair, the secondary check will compare the values of the cards that make up the pairs
 * 
 * @param hand1: first hand to be compared
 * @param hand2: second hand to be compared
 */
void checkWinner(PokerHand hand1, PokerHand hand2){
    int hand1Val = hand1.rankHand();
    int hand2Val = hand2.rankHand();
    if(hand1Val > hand2Val){
        player1Wins++;
    }
    else if(hand1Val == hand2Val){
        if(hand1Val == 0){
            for(int i = 0; i < 5; i++){
                if(hand2.getCard(i) < hand1.getCard(i) && hand1.getCard(i)-hand2.getCard(i) > 7){
                    break;
                    }
                if(hand2.getCard(i) > hand1.getCard(i) && hand2.getCard(i)-hand1.getCard(i) > 7){
                    player1Wins++;
                    break;
                }
            }
        }
        else if(hand2.getCard(hand2.getCompare()) - hand1.getCard(hand1.getCompare()) > 7){
            player1Wins++;
        }
    }
}

/*
 * 
 */
int main(int argc, char** argv) {

    int handsPlayed = 0;
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

    return 0;
}

