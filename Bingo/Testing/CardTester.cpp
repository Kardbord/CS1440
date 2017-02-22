//
// Created by Tanner on 2/21/2017.
//

#include <iostream>
#include "CardTester.h"
#include "../Card.h"

// TODO: Implement
void CardTester::testConstructor() {
    std::cout << std::endl << "Test Suite: CardTester::testConstructor" << std::endl;

    int size = 5;
    int max = 100;

    Card card(size, max);

    if (card.getCardSize() != size) {
        std::cout << "Error in getCardSize(): should be size" << std::endl;
    }

    if (card.getNumberMax() != max) {
        std::cout << "Error in getNumberMax(): should be max" << std::endl;
    }

    if (card.getCells().size() != size * size) {
        std::cout << "Error in constructor: getCells().getSize() should be size * size" << std::endl;
    }

    if (card.getPossNums().size() != max - 1) {
        std::cout << "Error in constructor: getPossNums().size() should be max - 1" << std::endl;
    }
}
