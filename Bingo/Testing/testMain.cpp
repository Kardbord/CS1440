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
#include "../Deck.h"

int main() {

    // Initialize the random number generator
    unsigned int seed = (unsigned int) time(NULL);
    srand(seed);

    // TODO: Test your components

    CardCellTester cellTester;
    cellTester.testGetVal();
    cellTester.testOperatorOverloads();

    CardTester cardTester;
    cardTester.testConstructorAndGetters();

    DeckTester deckTester;
    deckTester.testConstructorAndGetters();

    MenuOptionTester menuOptionTester;
    menuOptionTester.testConstructorAndGetter();

    MenuTester menuTester;
    menuTester.testConstructorAndGetter();

    int numMax = 100;
    int cSize = 5;
    int numCards = 20;

    Deck deck(cSize, numCards, numMax);

    deck.print(std::cout, 0);
}