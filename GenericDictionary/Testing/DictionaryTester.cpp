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

    } catch (std::exception e) {
        out << e.what() << std::endl;
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
        out << e.what() << std::endl;
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

void DictionaryTester::testRemoveByKey(std::ostream &out) {
    out << "DictionaryTester::testRemoveByKey" << std::endl;

    Dictionary<int, char> dictionary(26);

    char c = 'a';
    for (int i = 0; i < 26; ++i, ++c) {
        dictionary.addKeyValue(i, c);
    }

    try {
        dictionary.removeByKey(0);
    } catch (std::exception e) {
        out << e.what() << std::endl;
        out << "Failure in dictionary.removeByKey(0) -- threw an exception" << std::endl;
        return;
    }

    try {
        dictionary.getByKey(0);
        out << "Failure in dictionary.removeByKey(0), 0 was found after removal" << std::endl;
        return;
    } catch (std::exception e) {}

    try {
        dictionary.removeByKey(24);
    } catch (std::exception e) {
        out << e.what() << std::endl;
        out << "Failure in dictionary.removeByKey(24) -- threw an exception" << std::endl;
        return;
    }

    try {
        dictionary.getByKey(24);
        out << "Failure in dictionary.removeByKey(24), 24 was found after removal" << std::endl;
        return;
    } catch (std::exception e) {}

    try {
        dictionary.removeByKey(10);
    } catch (std::exception e) {
        out << e.what() << std::endl;
        out << "Failure in dictionary.removeByKey(10) -- threw an exception" << std::endl;
        return;
    }

    try {
        dictionary.getByKey(10);
        out << "Failure in dictionary.removeByKey(10), 10 was found after removal" << std::endl;
        return;
    } catch (std::exception e) {}

    try {
        dictionary.removeByKey(50);
        out << "Failure in dictionary.removeByKey(50), 50 was \"removed\" but never existed" << std::endl;
        return;
    } catch (std::exception e) {}

    try {
        dictionary.removeByKey(-1);
        out << "Failure in dictionary.removeByKey(-1), -1 was \"removed\" but never existed" << std::endl;
        return;
    } catch (std::exception e) {}

    try {
        dictionary.removeByKey(-50);
        out << "Failure in dictionary.removeByKey(-50), -50 was \"removed\" but never existed" << std::endl;
        return;
    } catch (std::exception e) {}

    try {
        dictionary.removeByKey(26);
        out << "Failure in dictionary.removeByKey(26), 26 was \"removed\" but never existed" << std::endl;
        return;
    } catch (std::exception e) {}

}

void DictionaryTester::testRemoveByIndex(std::ostream &out) {
    out << "DictionaryTester::testRemoveByIndex" << std::endl;

    Dictionary<int, char> dictionary(26);

    char c = 'a';
    for (int i = 0; i < 26; ++i, ++c) {
        dictionary.addKeyValue(i, c);
    }

    try {
        dictionary.removeByIndex(0);
    } catch (std::exception e) {
        out << e.what() << std::endl;
        out << "Failure in dictionary.removeByIndex(0) -- threw an exception" << std::endl;
        return;
    }

    try {
        dictionary.getByIndex(0);
    } catch (std::exception e) {
        out << "Failure in dictionary.removeByIndex(10), 10 should have been found after removal (due to shifting)"
            << std::endl;
        return;
    }

    try {
        dictionary.removeByIndex(24);
    } catch (std::exception e) {
        out << e.what() << std::endl;
        out << "Failure in dictionary.removeByIndex(24) -- threw an exception" << std::endl;
        return;
    }

    try {
        dictionary.getByIndex(24);
        out << "Failure in dictionary.removeByIndex(24), 24 (end of container) was found after removal" << std::endl;
        return;
    } catch (std::exception e) {}

    try {
        dictionary.removeByIndex(10);
    } catch (std::exception e) {
        out << e.what() << std::endl;
        out << "Failure in dictionary.removeByIndex(10) -- threw an exception" << std::endl;
        return;
    }

    try {
        dictionary.getByIndex(10);
    } catch (std::exception e) {
        out << "Failure in dictionary.removeByIndex(10), 10 should have been found after removal (due to shifting)"
            << std::endl;
        return;
    }

    try {
        dictionary.removeByIndex(50);
        out << "Failure in dictionary.removeByIndex(50), 50 was \"removed\" but never existed" << std::endl;
        return;
    } catch (std::exception e) {}

    try {
        dictionary.removeByIndex(-1);
        out << "Failure in dictionary.removeByIndex(-1), -1 was \"removed\" but never existed" << std::endl;
        return;
    } catch (std::exception e) {}

    try {
        dictionary.removeByIndex(-50);
        out << "Failure in dictionary.removeByIndex(-50), -50 was \"removed\" but never existed" << std::endl;
        return;
    } catch (std::exception e) {}

    try {
        dictionary.removeByIndex(26);
        out << "Failure in dictionary.removeByIndex(26), 26 was \"removed\" but never existed" << std::endl;
        return;
    } catch (std::exception e) {}
}

void DictionaryTester::testCopyConstructor(std::ostream &out) {
    out << "DictionaryTester::testCopyConstructor" << std::endl;

    // A scope for some test cases
    {
        Dictionary<int, char> dictionary(26);

        char c = 'a';
        for (int i = 0; i < 26; ++i, ++c) {
            dictionary.addKeyValue(i, c);
        }

        Dictionary<int, char> dictionary1(dictionary);

        c = 'a';
        for (int i = 0; i < dictionary.getSize(); ++i, ++c) {
            try {
                if (dictionary.getByIndex(i) != dictionary1.getByIndex(i) ||
                    dictionary.getByIndex(i).getValue() != dictionary1.getByIndex(i).getValue()) {
                    out << "Failure in copy constructor, the new dictionary should be identical to the constructed one"
                        << std::endl;
                    return;
                }
            } catch (std::exception e) {
                out << e.what() << std::endl;
                out << "Failure in copy constructor -- not all KeyVals were copied" << std::endl;
                return;
            }
        }

        c = 'a';
        dictionary.addKeyValue(26, '$');
        for (int i = 0; i < dictionary.getSize(); ++i, ++c) {
            try {
                if (i == 26 && dictionary.getByIndex(i) == dictionary1.getByIndex(i)) {
                    out << "Failure! Dictionaries are identical after adding KeyVal to only one." << std::endl;
                    return;
                } else if (dictionary.getByIndex(i) != dictionary1.getByIndex(i) ||
                           dictionary.getByIndex(i).getValue() != dictionary1.getByIndex(i).getValue()) {
                    out << "Failure in copy constructor, the new dictionary should be identical to the constructed one"
                        << std::endl;
                    return;
                }
            } catch (std::exception e) {}
        }
    }

    // Another scope for more test cases
    {
        Dictionary<std::string, int> dictionary(1);
        Dictionary<std::string, int> dictionary1(dictionary);

        for (int i = 0; i < dictionary.getSize(); ++i) {
            try {
                if (dictionary.getByIndex(i) != dictionary1.getByIndex(i) ||
                    dictionary.getByIndex(i).getValue() != dictionary1.getByIndex(i).getValue()) {
                    out << "Failure in copy constructor, the comparison shouldn't be able to be made"
                        << std::endl;
                    return;
                }
            } catch (std::exception e) {}
        }

        dictionary.addKeyValue("one", 1);
        Dictionary<std::string, int> dictionary2(dictionary);

        for (int i = 0; i < dictionary.getSize(); ++i) {
            try {
                if (dictionary.getByIndex(i) != dictionary2.getByIndex(i) ||
                    dictionary.getByIndex(i).getValue() != dictionary2.getByIndex(i).getValue()) {
                    out << "Failure in copy constructor, the new dictionary should be identical to the constructed one"
                        << std::endl;
                    return;
                }
            } catch (std::exception e) {
                out << e.what() << std::endl;
                out << "Failure in copy constructor -- not all KeyVals were copied" << std::endl;
                return;
            }
        }
    }
}
