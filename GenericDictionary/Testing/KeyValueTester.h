//
// Created by Tanner on 3/27/2017.
//

#ifndef GENERICDICTIONARY_KEYVALUETESTER_H
#define GENERICDICTIONARY_KEYVALUETESTER_H


#include <iosfwd>

class KeyValueTester {
public:
    KeyValueTester() {}

    void testConstructorAndGetters(std::ostream &out);

    void testCopyConstructor(std::ostream &out);
};


#endif //GENERICDICTIONARY_KEYVALUETESTER_H
