//
// Created by Tanner on 2/21/2017.
//

#include <iostream>
#include "DeckTester.h"
#include "../Deck.h"

void DeckTester::testConstructorAndGetters() {
    std::cout << std::endl << "Test Suite: DeckTester::testConstructorAndGetters" << std::endl;

    int numMax = 100;
    int cSize = 5;
    int numCards = 20;

    Deck deck(cSize, numCards, numMax);

    if (deck.getNumberMax() != numMax){
        std::cout << "Error in constructing Deck, getNumberMax() should be " << numMax << std::endl;
    }

    if (deck.getCardSize() != cSize){
        std::cout << "Error in constructing Deck, getCardSize() should be " << cSize << std::endl;
    }

    if (deck.getCardCount() != numCards){
        std::cout << "Error in constructing Deck, getCardSize() should be " << numCards << std::endl;
    }
}