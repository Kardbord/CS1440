//
// Created by Tanner on 3/27/2017.
//

#include <iostream>
#include "KeyValueTester.h"
#include "../KeyValue.h"

void KeyValueTester::testConstructorAndGetters(std::ostream &out) {
    out << "KeyValueTester::testConstructorAndGetters" << std::endl;

    KeyValue<std::string, int> keyValue("one", 1);

    if (keyValue.getKey() != "one") {
        out << "Failure in keyValue.getKey -- should be \"one\"" << std::endl;
        return;
    }

    if (keyValue.getValue() != 1) {
        out << "Failure in keyValue.getValue -- should be '1'" << std::endl;
        return;
    }

    KeyValue<int, char> keyValue1(1, '1');

    if (keyValue1.getKey() != 1) {
        out << "Failure in keyValue1.getKey -- should be \"one\"" << std::endl;
        return;
    }

    if (keyValue1.getValue() != '1') {
        out << "Failure in keyValue1.getValue -- should be '1'" << std::endl;
        return;
    }
}

void KeyValueTester::testCopyConstructor(std::ostream &out) {
    out << "KeyValueTester::testCopyConstructor" << std::endl;

    KeyValue<std::string, char> keyValue("one", '1');

    KeyValue<std::string, char> keyValue1(keyValue);

    if (keyValue1.getKey() != "one") {
        out << "Failure in keyValue1.getKey -- should be \"one\"" << std::endl;
        return;
    }

    if (keyValue1.getValue() != '1') {
        out << "Failure in keyValue1.getValue -- should be '1'" << std::endl;
        return;
    }
}
