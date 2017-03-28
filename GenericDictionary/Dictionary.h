//
// Created by Tanner on 3/27/2017.
//

#ifndef GENERICDICTIONARY_DICTIONARY_H
#define GENERICDICTIONARY_DICTIONARY_H

#include <vector>
#include <cassert>
#include "KeyValue.h"

template<typename Comparable, typename ValType>
class Dictionary {
public:
    Dictionary(unsigned int const &size = 10);

    ~Dictionary();

    bool addKeyValue(Comparable const &key, ValType const &value);

    unsigned long long int getSize() { return m_numKeyVals; }

    KeyValue getByKey(Comparable const & key);

private:
    KeyValue<Comparable, ValType> **m_keyValPairs;
    unsigned int m_sizeAlloc;
    unsigned int m_numKeyVals;
    unsigned int m_nextEmpty;

    void reAlloc();
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
    delete [] m_keyValPairs;
    m_keyValPairs = nullptr;
}

// TODO: test me
template<typename Comparable, typename ValType>
bool Dictionary<Comparable, ValType>::addKeyValue(const Comparable &key, const ValType &value) {
    if (m_nextEmpty + 1 == m_sizeAlloc) reAlloc();

    // TODO: check if key exists already - if so return false

    assert(m_keyValPairs[m_nextEmpty] == nullptr);
    m_keyValPairs[m_nextEmpty++] = new KeyValue<Comparable, ValType>(key, value);

    return true;
}

// TODO: test me
template<typename Comparable, typename ValType>
void Dictionary::reAlloc() {
    auto temp = m_keyValPairs;
    m_sizeAlloc *= 2;
    m_keyValPairs = new KeyValue<Comparable, ValType> *[m_sizeAlloc];
    for (int i = 0; i < m_sizeAlloc; ++i) {
        m_keyValPairs[i] = nullptr;
        if (i < m_numKeyVals && temp[i] != nullptr) {
            m_keyValPairs[i] = temp[i];
        }
    }
    // TODO: figure out if I need to delete temp and its contents
    // I don't think I do... because it's a pointer to an array of pointers that is also pointed to by m_keyValPairs
}


#endif //GENERICDICTIONARY_DICTIONARY_H
