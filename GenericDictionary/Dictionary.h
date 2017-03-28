//
// Created by Tanner on 3/27/2017.
//

#ifndef GENERICDICTIONARY_DICTIONARY_H
#define GENERICDICTIONARY_DICTIONARY_H

#include <vector>
#include "KeyValue.h"

template<typename Comparable, typename ValType>
class Dictionary {
public:
    Dictionary(unsigned int const &size = 10);

    ~Dictionary();

    bool addKeyValue(Comparable const &key, ValType const &value);

    unsigned long long int getSize() { return m_numKeyVals; }

private:
    KeyValue<Comparable, ValType> **m_keyValPairs;
    unsigned int m_sizeAlloc;
    unsigned int m_numKeyVals;
    unsigned int m_nextEmpty;
};

template<typename Comparable, typename ValType>
Dictionary<Comparable, ValType>::Dictionary(unsigned int const &size) : m_sizeAlloc(size), m_numKeyVals(0),
                                                                        m_nextEmpty(0) {
    m_keyValPairs = new KeyValue<Comparable, ValType> *[m_sizeAlloc];
    for (int i = 0; i < m_sizeAlloc; ++i) {
        m_keyValPairs[i] = nullptr;
    }
}

// TODO: delete any dynamically allocated memory
template<typename Comparable, typename ValType>
Dictionary::~Dictionary() {
    for (int i = 0; i < m_sizeAlloc; ++i) {
        delete m_keyValPairs[i];
        m_keyValPairs[i] = nullptr;
    }
    delete m_keyValPairs;
    m_keyValPairs = nullptr;
}

template<typename Comparable, typename ValType>
bool Dictionary<Comparable, ValType>::addKeyValue(const Comparable &key, const ValType &value) {
    return false;
}


#endif //GENERICDICTIONARY_DICTIONARY_H
