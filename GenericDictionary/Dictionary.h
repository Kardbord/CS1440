//
// Created by Tanner on 3/27/2017.
//

#ifndef GENERICDICTIONARY_DICTIONARY_H
#define GENERICDICTIONARY_DICTIONARY_H

#include <vector>
#include <cassert>
#include <stdexcept>
#include <algorithm>
#include "KeyValue.h"

// TODO: Make sure I'm always throwing something from std::exception
template<typename Comparable, typename ValType>
class Dictionary {
public:
    Dictionary(unsigned int const &size = 10);

    ~Dictionary();

    bool addKeyValue(Comparable const &key, ValType const &value);

    unsigned long long int getSize() const { return m_validKeys.size(); }

    KeyValue<Comparable, ValType> getByKey(Comparable const &key) const;

    KeyValue<Comparable, ValType> getByIndex(int const &index) const;

    void removeByKey(Comparable const &key);

    void removeByIndex(int const &index);

private:
    KeyValue<Comparable, ValType> **m_keyValPairs;
    unsigned int m_sizeAlloc;
    unsigned int m_nextEmpty;
    std::vector<Comparable> m_validKeys;

    void reAlloc();

    void sortKeyValPairs();

    KeyValue<Comparable, ValType> *binaryFindByKey(int const &start, int const &end, Comparable const &key) const;

    int binaryFindIndex(int const &start, int const &end, Comparable const &key);

    void pushNullOut(int const &nullIndex);
};

template<typename Comparable, typename ValType>
Dictionary<Comparable, ValType>::Dictionary(unsigned int const &size) : m_sizeAlloc(size), m_nextEmpty(0),
                                                                        m_validKeys() {
    if (m_sizeAlloc < 1) m_sizeAlloc = 1; // in case an invalid value is specified
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

template<typename Comparable, typename ValType>
bool Dictionary<Comparable, ValType>::addKeyValue(const Comparable &key, const ValType &value) {

    // Check if key exists already - if so return false
    if (std::find(m_validKeys.begin(), m_validKeys.end(), key) != m_validKeys.end()) {
        return false;
    }

    if (m_nextEmpty + 1 >= m_sizeAlloc) reAlloc();

    assert(m_keyValPairs[m_nextEmpty] == nullptr);
    m_validKeys.push_back(key);
    m_keyValPairs[m_nextEmpty++] = new KeyValue<Comparable, ValType>(key, value);
    sortKeyValPairs();

    return true;

}

template<typename Comparable, typename ValType>
void Dictionary<Comparable, ValType>::reAlloc() {
    auto temp = m_keyValPairs;
    if (m_sizeAlloc < 3) m_sizeAlloc = 10;
    else m_sizeAlloc *= m_sizeAlloc;
    m_keyValPairs = new KeyValue<Comparable, ValType> *[m_sizeAlloc];
    for (int i = 0; i < m_sizeAlloc; ++i) {
        m_keyValPairs[i] = nullptr;
        if (i < m_validKeys.size() && temp[i] != nullptr) {
            m_keyValPairs[i] = temp[i];
        }
    }
}

template<typename Comparable, typename ValType>
void Dictionary<Comparable, ValType>::sortKeyValPairs() {

    // place all KeyValues pointers into a vector for sorting
    std::vector<KeyValue<Comparable, ValType> *> myVector(m_keyValPairs, m_keyValPairs + m_validKeys.size());

    // sort the vector
    std::sort(myVector.begin(), myVector.end(), [](KeyValue<Comparable, ValType> *a, KeyValue<Comparable, ValType> *b) {
        return !(!a || !b) && *a < *b;
    });

    // TODO: is there a better way to do this?
    for (int i = 0; i < m_validKeys.size(); ++i) {
        m_keyValPairs[i] = myVector[i];
    }
}

template<typename Comparable, typename ValType>
KeyValue<Comparable, ValType> Dictionary<Comparable, ValType>::getByKey(const Comparable &key) const {

    if (std::find(m_validKeys.begin(), m_validKeys.end(), key) == m_validKeys.end()) {
        throw std::invalid_argument("Invalid Key");
    }

    return *binaryFindByKey(0, (const int &) m_validKeys.size() - 1, key);
}

template<typename Comparable, typename ValType>
KeyValue<Comparable, ValType> *
Dictionary<Comparable, ValType>::binaryFindByKey(int const &start, int const &end, const Comparable &key) const {
    if (end < start || start < 0) {
        throw std::runtime_error("Key not found");
    }
    if (end >= m_validKeys.size() || start < -1) {
        throw std::out_of_range("Invalid boundaries while searching for key");
    }

    int mid = ((end - start) / 2) + start;

    if (m_keyValPairs[mid] == nullptr) throw std::runtime_error("Hit nullptr while searching for key");

    // Found target KeyValue
    if (*m_keyValPairs[mid] == key) return m_keyValPairs[mid];

    // Target KeyValue is larger than m_keyValPairs[mid]
    if (*m_keyValPairs[mid] < key) return binaryFindByKey(mid + 1, end, key);

        // Target KeyValue is smaller than m_keyValPairs[mid]
    else return binaryFindByKey(start, mid - 1, key);
}

template<typename Comparable, typename ValType>
KeyValue<Comparable, ValType> Dictionary<Comparable, ValType>::getByIndex(int const &index) const {
    if (index < 0 || index >= m_validKeys.size()) {
        throw std::out_of_range(index + " is an invalid index");
    }

    return *m_keyValPairs[index];
}

template<typename Comparable, typename ValType>
void Dictionary<Comparable, ValType>::removeByKey(const Comparable &key) {
    // This compiles fine (gcc), it is a bug with CLion
    auto position = std::find(m_validKeys.begin(), m_validKeys.end(), key);

    // 'position' variable is the position in m_validKeys of the Key which we are trying to delete.
    // if it is equal to m_validKeys.end(), then it was not found and is an invalid key.

    if (position == m_validKeys.end()) {
        throw std::invalid_argument("Invalid Key");
    }

    int keyValIndex;

    keyValIndex = binaryFindIndex(0, (const int &) m_validKeys.size() - 1, key);

    // Remove the key from the list of valid keys
    m_validKeys.erase(position); // This compiles fine (gcc), it is a bug with CLion

    // Call delete on the found keyValue, assign it to be a nullptr, and then remove that null from m_keyValPairs
    delete m_keyValPairs[keyValIndex];
    m_keyValPairs[keyValIndex] = nullptr;

    pushNullOut(keyValIndex);

    return;

}

template<typename Comparable, typename ValType>
int Dictionary<Comparable, ValType>::binaryFindIndex(int const &start, int const &end, const Comparable &key) {
    if (end < start || start < 0) {
        throw std::runtime_error("Key not found");
    }
    if (end >= m_validKeys.size() || start < -1) {
        throw std::out_of_range("Invalid boundaries while searching for key");
    }

    int mid = ((end - start) / 2) + start;

    if (m_keyValPairs[mid] == nullptr) throw std::runtime_error("Hit nullptr while searching for key");

    // Found target KeyValue
    if (*m_keyValPairs[mid] == key) return mid;

    // Target KeyValue is larger than m_keyValPairs[mid]
    if (*m_keyValPairs[mid] < key) return binaryFindIndex(mid + 1, end, key);

        // Target KeyValue is smaller than m_keyValPairs[mid]
    else return binaryFindIndex(start, mid - 1, key);
}

template<typename Comparable, typename ValType>
void Dictionary<Comparable, ValType>::removeByIndex(int const &index) {
    if (index < 0 || index >= m_validKeys.size()) {
        throw std::out_of_range(index + " is an invalid index");
    }

    if (m_keyValPairs[index] == nullptr) {
        throw std::invalid_argument("Cannot remove KeyValue -- specified index follows nullptr");
    }

    auto key = m_keyValPairs[index]->getKey();

    // Remove the key from the list of valid keys
    // This says it's an error but compiles fine (gcc)
    auto foundKey = std::find(m_validKeys.begin(), m_validKeys.end(), key);
    m_validKeys.erase(foundKey);

    // Remove the KeyValue at the specified index
    delete m_keyValPairs[index];
    m_keyValPairs[index] = nullptr;

    pushNullOut(index);

    return;
}

template<typename Comparable, typename ValType>
void Dictionary<Comparable, ValType>::pushNullOut(int const &nullIndex) {
    for (int i = nullIndex; m_keyValPairs[i + 1] != nullptr; ++i) {
        auto temp = m_keyValPairs[i + 1];
        m_keyValPairs[i + 1] = m_keyValPairs[i];
        m_keyValPairs[i] = temp;
    }
}


#endif //GENERICDICTIONARY_DICTIONARY_H
