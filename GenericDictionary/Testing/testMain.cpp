// Tanner Kvarfordt
// A02052217

//
// Created by Tanner on 3/27/2017.
//

#include <iostream>
#include "DictionaryTester.h"
#include "KeyValueTester.h"

int main() {
    KeyValueTester keyValueTester;
    keyValueTester.testConstructorAndGetters(std::cout);
    keyValueTester.testCopyConstructor(std::cout);
    keyValueTester.testOperatorOverloads(std::cout);

    DictionaryTester dictionaryTester;
    dictionaryTester.testConstructor(std::cout);
    dictionaryTester.testAddKeyValue(std::cout);
    dictionaryTester.testGetByKey(std::cout);
    dictionaryTester.testGetByIndex(std::cout);
    dictionaryTester.testRemoveByKey(std::cout);
    dictionaryTester.testRemoveByIndex(std::cout);
    dictionaryTester.testCopyConstructor(std::cout);
    return EXIT_SUCCESS;
}