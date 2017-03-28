//
// Created by Tanner on 3/27/2017.
//

#ifndef GENERICDICTIONARY_KEYVALUE_H
#define GENERICDICTIONARY_KEYVALUE_H

template<typename Comparable, typename ValType>
class KeyValue {
public:
    KeyValue(Comparable const &key, ValType const &value);

private:
    Comparable m_key;
    ValType m_value;
};

template<typename Comparable, typename ValType>
KeyValue<Comparable, ValType>::KeyValue(Comparable const &key, ValType const &value): m_key(key), m_value(value) {};


#endif //GENERICDICTIONARY_KEYVALUE_H
