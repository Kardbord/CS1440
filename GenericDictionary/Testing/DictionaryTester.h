//
// Created by Tanner on 3/27/2017.
//

#ifndef GENERICDICTIONARY_DICTIONARYTESTER_H
#define GENERICDICTIONARY_DICTIONARYTESTER_H


#include <ostream>

class DictionaryTester {
public:
    DictionaryTester() {}

    void testConstructor(std::ostream &out);

    void testAddKeyValue(std::ostream &out);

    void testGetByKey(std::ostream &out);

    void testGetByIndex(std::ostream &out);

    void testRemoveByKey(std::ostream &out);

    void testRemoveByIndex(std::ostream &out);

    void testCopyConstructor(std::ostream &out);

private:
};


#endif //GENERICDICTIONARY_DICTIONARYTESTER_H
