//
// Created by Tanner on 3/27/2017.
//

#ifndef GENERICDICTIONARY_DICTIONARY_H
#define GENERICDICTIONARY_DICTIONARY_H

#include <vector>
#include "KeyValue.h"

template <typename Comparable, typename ValType>
class Dictionary {
public:
    Dictionary(int const &size = 10);

    unsigned long long int getSize() { return m_keyValPairs.size(); }
private:
    std::vector<KeyValue<Comparable, ValType>> m_keyValPairs;
};

// TODO: eliminate the silly requirement that the vector memory be allocated right off the bat
template <typename Comparable, typename ValType>
Dictionary<Comparable, ValType>::Dictionary(int const &size): m_keyValPairs((unsigned long long int) size) {}


#endif //GENERICDICTIONARY_DICTIONARY_H
