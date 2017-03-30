//
// Created by Tanner on 3/27/2017.
//

#include <iostream>
#include "DictionaryTester.h"
#include "../Dictionary.h"

// TODO: finish me
void DictionaryTester::testConstructor(std::ostream &out) {
    out << "DictionaryTester::testConstructor" << std::endl;

    // No way to test that allocation is working properly without breaking encapsulation
    // Use debugger to step thru constructor and see that it is working properly
    Dictionary<int, int> dictionary;
    Dictionary<int, int> dictionary1(20);
    Dictionary<int, int> dictionary2(1);
    Dictionary<int, int> dictionary3(200);
    Dictionary<int, int> dictionary4(0);

    if (dictionary.getSize() != 0) {
        out << "Failure in DictionaryTester::testConstructor -- size should be 0" << std::endl;
    }
    if (dictionary1.getSize() != 0) {
        out << "Failure in DictionaryTester::testConstructor -- size should be 0" << std::endl;
    }
    if (dictionary2.getSize() != 0) {
        out << "Failure in DictionaryTester::testConstructor -- size should be 0" << std::endl;
    }
    if (dictionary3.getSize() != 0) {
        out << "Failure in DictionaryTester::testConstructor -- size should be 0" << std::endl;
    }
}

void DictionaryTester::testAddKeyValue(std::ostream &out) {
    out << "DictionaryTester::testAddKeyValue" << std::endl;

    Dictionary<int, int> dictionary;
    if (!dictionary.addKeyValue(6, 6)) {
        out << "Failure in DictionaryTester::testAddKeyValue with (6,6)" << std::endl;
        return;
    }
    if (!dictionary.addKeyValue(5, 5)) {
        out << "Failure in DictionaryTester::testAddKeyValue with (5,5)" << std::endl;
        return;
    }
    if (!dictionary.addKeyValue(4, 4)) {
        out << "Failure in DictionaryTester::testAddKeyValue with (4,4)" << std::endl;
        return;
    }
    if (!dictionary.addKeyValue(3, 3)) {
        out << "Failure in DictionaryTester::testAddKeyValue with (3,3)" << std::endl;
        return;
    }
    if (!dictionary.addKeyValue(2, 2)) {
        out << "Failure in DictionaryTester::testAddKeyValue with (2,2)" << std::endl;
        return;
    }
    if (!dictionary.addKeyValue(1, 1)) {
        out << "Failure in DictionaryTester::testAddKeyValue with (1,1)" << std::endl;
        return;
    }
    if (!dictionary.addKeyValue(0, 0)) {
        out << "Failure in DictionaryTester::testAddKeyValue with (0,0)" << std::endl;
        return;
    }
    if (!dictionary.addKeyValue(-1, -1)) {
        out << "Failure in DictionaryTester::testAddKeyValue with (-1,-1)" << std::endl;
        return;
    }
    if (!dictionary.addKeyValue(-2, 100)) {
        out << "Failure in DictionaryTester::testAddKeyValue with (-2,100)" << std::endl;
        return;
    }
    // This should cause dictionary.reAlloc()
    // Not really any way to write test cases for this without breaking encapsulation. Step thru with the debugger
    // to see that it works. I have and it does, pinky swear. :)
    if (!dictionary.addKeyValue(7, 100)) {
        out << "Failure in DictionaryTester::testAddKeyValue with (7,100)" << std::endl;
        return;
    }
    if (!dictionary.addKeyValue(8, 6)) {
        out << "Failure in DictionaryTester::testAddKeyValue with (8,6)" << std::endl;
        return;
    }
    if (dictionary.addKeyValue(8, 6)) {
        out << "Failure in DictionaryTester::testAddKeyValue, (8,6) - no duplicate keys should be allowed" << std::endl;
        return;
    }
    if (dictionary.addKeyValue(8, 40)) {
        out << "Failure in DictionaryTester::testAddKeyValue, (8,40) - no duplicate keys should be allowed"
            << std::endl;
        return;
    }
    if (dictionary.addKeyValue(-2, 100)) {
        out << "Failure in DictionaryTester::testAddKeyValue with (-2,300) - no duplicate keys should be allowed"
            << std::endl;
        return;
    }

    Dictionary<int, int> dictionary1(0);

    if (dictionary1.getSize() != 0) {
        out << "Failure in DictionaryTester::testAddKeyValue -- dictionary1.size should be 0" << std::endl;
    }
    if (!dictionary1.addKeyValue(1, 1)) {
        out << "Failure in DictionaryTester::testAddKeyValue dictionary1 with (1,1)" << std::endl;
    }
}
