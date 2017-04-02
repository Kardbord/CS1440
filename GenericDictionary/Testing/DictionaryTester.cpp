//
// Created by Tanner on 3/27/2017.
//

#include <iostream>
#include "DictionaryTester.h"
#include "../Dictionary.h"

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

void DictionaryTester::testGetByKey(std::ostream &out) {

    out << "DictionaryTester::testGetByKey" << std::endl;

    Dictionary<int, char> dictionary(26);

    try {
        char c = 'a';
        for (int i = 0; i < 26; ++i, ++c) {
            dictionary.addKeyValue((const int &) (25 - i), c);
        }

        c = 'z';
        for (int i = 0; i < dictionary.getSize(); ++i, --c) {
            if (dictionary.getByKey(i).getValue() != c) {
                out << "Failure in DictionaryTester::testGetByKey, dictionary.getByKey(" << i << ").getValue()="
                    << dictionary.getByKey(i).getValue() << " should be " << c << std::endl;
                return;
            }
        }

        dictionary.addKeyValue(-1, '!');
        if (dictionary.getByKey(-1).getValue() != '!') {
            out << "Failure in DictionaryTester::testGetByKey, dictionary.getByKey(-1).getValue()="
                << dictionary.getByKey(-1).getValue() << " should be " << '!' << std::endl;
        }

        dictionary.addKeyValue(100, '@');
        if (dictionary.getByKey(100).getValue() != '@') {
            out << "Failure in DictionaryTester::testGetByKey, dictionary.getByKey(100).getValue()="
                << dictionary.getByKey(100).getValue() << " should be " << '@' << std::endl;
        }

        dictionary.addKeyValue(-100, '#');
        if (dictionary.getByKey(-100).getValue() != '#') {
            out << "Failure in DictionaryTester::testGetByKey, dictionary.getByKey(-1).getValue()="
                << dictionary.getByKey(-100).getValue() << " should be " << '#' << std::endl;
        }

        auto keyval = dictionary.getByKey(25);
        if (keyval.getValue() != 'a') {
            out << "Failure in DictionaryTester::testGetByKey, dictionary.getByKey(25).getValue()='"
                << keyval.getValue() << "' should be " << "'a'" << std::endl;
        }

    } catch (const char *msg) {
        std::cerr << msg << std::endl;
        out << "Failure in DictionaryTester::testGetByKey, threw an exception." << std::endl;
    }

}

void DictionaryTester::testGetByIndex(std::ostream &out) {
    out << "DictionaryTester::testGetByIndex" << std::endl;

    Dictionary<int, char> dictionary(26);

    char c = 'a';
    for (int i = 0; i < 26; ++i, ++c) {
        dictionary.addKeyValue(i, c);
    }

    c = 'a';
    try {
        for (int i = 0; i < dictionary.getSize(); ++i, ++c) {
            if (dictionary.getByIndex(i).getValue() != c) {
                out << "Failure in DictionaryTester::testGetByIndex, dictionary.getByIndex(" << i << ").getValue()="
                    << dictionary.getByIndex(i).getValue() << " should be " << c << std::endl;
            }
        }
    } catch (std::out_of_range e) {
        std::cerr << e.what() << std::endl;
        out << "Failure in DictionaryTester::testGetByKey, threw an exception." << std::endl;
    }

    try {
        dictionary.getByIndex(30); // this line should throw an exception
        out << "Failure in DictionaryTester::testGetByIndex, dictionary.getByIndex(30) should have thrown out_of_range"
            << std::endl;
        return;
    } catch (std::out_of_range) {}

    try {
        dictionary.getByIndex(-20); // this line should throw an exception
        out << "Failure in DictionaryTester::testGetByIndex, dictionary.getByIndex(-20) should have thrown out_of_range"
            << std::endl;
        return;
    } catch (std::out_of_range) {}

    try {
        dictionary.getByIndex(-1); // this line should throw an exception
        out << "Failure in DictionaryTester::testGetByIndex, dictionary.getByIndex(-1) should have thrown out_of_range"
            << std::endl;
        return;
    } catch (std::out_of_range) {}

    try {
        dictionary.getByIndex(27); // this line should throw an exception
        out << "Failure in DictionaryTester::testGetByIndex, dictionary.getByIndex(27) should have thrown out_of_range"
            << std::endl;
    } catch (std::out_of_range) {}

}
