// Tanner Kvarfordt
// A02052217

//
// Created by Tanner on 3/27/2017.
//

#include <iostream>
#include "DictionaryTester.h"

int main() {
    DictionaryTester dictionaryTester;
    dictionaryTester.testConstructor(std::cout);
    dictionaryTester.testAddKeyValue(std::cout);
    return EXIT_SUCCESS;
}