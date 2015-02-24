/* 
 * File:   PokerHand.h
 * Author: elliot
 *
 * Created on February 22, 2015, 4:46 PM
 */

#ifndef POKERHAND_H
#define	POKERHAND_H

class PokerHand {
    
    
public:
    PokerHand(int* array);
    void printHand();
    int rankHand();
    
    
private:
    bool royalFlush();
    bool straightFlush();
    bool fourOfKind();
    bool fullHouse();
    bool straight();
    bool flush();
    bool threeOfKind();
    bool twoPair();
    bool pair();

};

#endif	/* POKERHAND_H */

