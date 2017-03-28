//
// Created by Tanner on 3/27/2017.
//

#ifndef GENERICDICTIONARY_DICTIONARY_H
#define GENERICDICTIONARY_DICTIONARY_H

#include <vector>
#include <cassert>
#include <algorithm>
#include "KeyValue.h"

template<typename Comparable, typename ValType>
class Dictionary {
public:
    Dictionary(unsigned int const &size = 10);

    ~Dictionary();

    bool addKeyValue(Comparable const &key, ValType const &value);

    unsigned long long int getSize() { return m_numKeyVals; }

    //KeyValue getByKey(Comparable const &key);

private:
    KeyValue<Comparable, ValType> **m_keyValPairs;
    unsigned int m_sizeAlloc;
    unsigned int m_numKeyVals;
    unsigned int m_nextEmpty;

    void reAlloc();

    void sortKeyValPairs();

    bool comparePointers(KeyValue<Comparable, ValType> *a, KeyValue<Comparable, ValType> *b) const;
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
Dictionary<Comparable, ValType>::~Dictionary() {
    for (int i = 0; i < m_sizeAlloc; ++i) {
        delete m_keyValPairs[i];
        m_keyValPairs[i] = nullptr;
    }
    delete[] m_keyValPairs;
    m_keyValPairs = nullptr;
}

// TODO: test me
template<typename Comparable, typename ValType>
bool Dictionary<Comparable, ValType>::addKeyValue(const Comparable &key, const ValType &value) {
    if (m_nextEmpty + 1 == m_sizeAlloc) reAlloc();

    // TODO: check if key exists already - if so return false

    assert(m_keyValPairs[m_nextEmpty] == nullptr);
    m_keyValPairs[m_nextEmpty++] = new KeyValue<Comparable, ValType>(key, value);
    sortKeyValPairs();
    ++m_numKeyVals;

    return true;
}

// TODO: test me
template<typename Comparable, typename ValType>
void Dictionary<Comparable, ValType>::reAlloc() {
    auto temp = m_keyValPairs;
    m_sizeAlloc *= m_sizeAlloc;
    m_keyValPairs = new KeyValue<Comparable, ValType> *[m_sizeAlloc];
    for (int i = 0; i < m_sizeAlloc; ++i) {
        m_keyValPairs[i] = nullptr;
        if (i < m_numKeyVals && temp[i] != nullptr) {
            m_keyValPairs[i] = temp[i];
        }
    }
}

// TODO: test me
template<typename Comparable, typename ValType>
void Dictionary<Comparable, ValType>::sortKeyValPairs() {

    // place all KeyValues pointers into a vector for sorting
    std::vector<KeyValue<Comparable, ValType> *> myVector(m_keyValPairs, m_keyValPairs + m_numKeyVals);

    // sort the vector
    std::sort(myVector.begin(), myVector.end(), comparePointers); // TODO: it doesn't like comparePointers...

    for (int i = 0; i < m_numKeyVals; ++i) {
        m_keyValPairs[i] = myVector[i];
    }
}

template<typename Comparable, typename ValType>
bool Dictionary<Comparable, ValType>::comparePointers(KeyValue<Comparable, ValType> *a,
                                                      KeyValue<Comparable, ValType> *b) const {
    return *a < *b;
}


#endif //GENERICDICTIONARY_DICTIONARY_H
