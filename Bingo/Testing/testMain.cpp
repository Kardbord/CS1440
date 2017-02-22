//
// Created by Stephen Clyde on 2/20/17.
//

#include <iostream>
#include <ctime>

#include "MenuOptionTester.h"
#include "MenuTester.h"
#include "CardCellTester.h"
#include "CardTester.h"
#include "DeckTester.h"

int main() {

    // Initialize the random number generator
    unsigned int seed = (unsigned int) time(NULL);
    srand(seed);

    // TODO: Test your components

    CardCellTester cellTester;
    cellTester.testGetVal();

    CardTester cardTester;
    cardTester.testConstructorAndGetters();

    DeckTester deckTester;
    deckTester.testConstructorAndGetters();

    MenuOptionTester menuOptionTester;
    menuOptionTester.testConstructorAndGetter();

    MenuTester menuTester;
    menuTester.testConstructorAndGetter();
}