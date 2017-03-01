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

    std::cout << "\nTest individual card prints:" << std::endl << std::endl;

    int numMax = 100;
    int cSize = 5;
    int numCards = 5;

    Deck deck(cSize, numCards, numMax);

    std::cout << "5x5" << std::endl;
    deck.print(std::cout, 0);

    numMax = 900;
    cSize = 15;
    numCards = 6;

    std::cout << std::endl << std::endl;

    Deck deck2(cSize, numCards, numMax);

    std::cout << "15x15" << std::endl;
    deck2.print(std::cout, 0);


    std::cout << "\nTest deck prints:" << std::endl << std::endl;

    std::cout << "Deck 1 (Size " << deck.getCards().size() << "):" << std::endl;

    deck.print(std::cout);

    std::cout << std::endl << std::endl << "Deck 2 (Size " << deck2.getCards().size() << "):" << std::endl;

    deck2.print(std::cout);

    std::cout << "\nScroll up to see all test cases" << std::endl;
}