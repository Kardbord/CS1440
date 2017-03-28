//
// Created by Tanner on 3/27/2017.
//

#include <iostream>
#include "DictionaryTester.h"
#include "../Dictionary.h"

void DictionaryTester::testConstructor(std::ostream &out) {
    Dictionary<int, int> dictionary;
    dictionary.addKeyValue(0, 0);
    dictionary.addKeyValue(1, 1);
    dictionary.addKeyValue(2, 2);
    dictionary.addKeyValue(3, 3);
    dictionary.addKeyValue(4, 4);
    dictionary.addKeyValue(5, 5);
    dictionary.addKeyValue(6, 6);
}
