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

    unsigned long long int getSize() const { return m_validKeys.size(); }

    KeyValue<Comparable, ValType> getByKey(Comparable const &key) const;

private:
    KeyValue<Comparable, ValType> **m_keyValPairs;
    unsigned int m_sizeAlloc;
    unsigned int m_nextEmpty;
    std::vector<Comparable> m_validKeys;

    void reAlloc();

    void sortKeyValPairs();

    KeyValue<Comparable, ValType> binaryFindByKey(int const &start, int const &end, Comparable const &key) const;
};

template<typename Comparable, typename ValType>
Dictionary<Comparable, ValType>::Dictionary(unsigned int const &size) : m_sizeAlloc(size), m_nextEmpty(0),
                                                                        m_validKeys() {
    m_keyValPairs = new KeyValue<Comparable, ValType> *[m_sizeAlloc];
    for (int i = 0; i < m_sizeAlloc; ++i) {
        m_keyValPairs[i] = nullptr;
    }
}

// TODO: delete any dynamically allocated memory
template<typename Comparable, typename ValType>
Dictionary<Comparable, ValType>::~Dictionary() {
    for (int i = 0; i < m_sizeAlloc; ++i) {
        if (m_keyValPairs[i] != nullptr) {
            delete m_keyValPairs[i];
            m_keyValPairs[i] = nullptr;
        }
    }
    delete[] m_keyValPairs;
    m_keyValPairs = nullptr;
}

// TODO: test me
template<typename Comparable, typename ValType>
bool Dictionary<Comparable, ValType>::addKeyValue(const Comparable &key, const ValType &value) {

    // Check if key exists already - if so return false
    if (std::find(m_validKeys.begin(), m_validKeys.end(), key) != m_validKeys.end()) {
        return false;
    }

    if (m_nextEmpty + 1 == m_sizeAlloc) reAlloc();

    assert(m_keyValPairs[m_nextEmpty] == nullptr);
    m_validKeys.push_back(key);
    m_keyValPairs[m_nextEmpty++] = new KeyValue<Comparable, ValType>(key, value);
    sortKeyValPairs();

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
        if (i < m_validKeys.size() && temp[i] != nullptr) {
            m_keyValPairs[i] = temp[i];
        }
    }
}

// TODO: test me
template<typename Comparable, typename ValType>
void Dictionary<Comparable, ValType>::sortKeyValPairs() {

    // place all KeyValues pointers into a vector for sorting
    std::vector<KeyValue<Comparable, ValType> *> myVector(m_keyValPairs, m_keyValPairs + m_validKeys.size() + 1);

    // sort the vector
    std::sort(myVector.begin(), myVector.end(), [](KeyValue<Comparable, ValType> *a, KeyValue<Comparable, ValType> *b) {
        if (!a || !b) return false;
        return *a < *b;
    });

    // TODO: is there a better way to do this?
    for (int i = 0; i < m_validKeys.size() + 1; ++i) {
        m_keyValPairs[i] = myVector[i];
    }
}

template<typename Comparable, typename ValType>
KeyValue<Comparable, ValType> Dictionary<Comparable, ValType>::getByKey(const Comparable &key) const {

    if (std::find(m_validKeys.begin(), m_validKeys.end(), key) == m_validKeys.end()) {
        throw "Invalid Key";
    }

    return binaryFindByKey(0, (const int &) m_validKeys.size(), key);
}

// TODO: test me
template<typename Comparable, typename ValType>
KeyValue<Comparable, ValType>
Dictionary<Comparable, ValType>::binaryFindByKey(int const &start, int const &end, const Comparable &key) const {
    if (end < start || start < 0) throw "Key not found";
    if (end >= m_validKeys.size() || start < 0) throw "Invalid boundaries";

    int mid = ((end - start) / 2) + start;

    if (m_keyValPairs[mid] == nullptr) throw "Hit nullptr";

    // Found target KeyValue
    if (*m_keyValPairs[mid] == key) return *m_keyValPairs[mid];

    // Target KeyValue is larger than m_keyValPairs[mid]
    if (key > *m_keyValPairs[mid]) return binaryFindByKey(mid + 1, end, key);

    // Target KeyValue is smaller than m_keyValPairs[mid]
    else return binaryFindByKey(start, mid - 1, key);
}


#endif //GENERICDICTIONARY_DICTIONARY_H
