//
// Created by Tanner on 3/27/2017.
//

#ifndef GENERICDICTIONARY_KEYVALUE_H
#define GENERICDICTIONARY_KEYVALUE_H

// TODO: test operator overloads (they work, but write test cases)
// TODO: test copy constructor
template<typename Comparable, typename ValType>
class KeyValue {
public:
    KeyValue(Comparable const &key, ValType const &value);

    KeyValue(KeyValue const &k);

    Comparable getKey() const { return m_key; }

    ValType getValue() const { return m_value; }

    /**
     * Compares based on m_key
     *
     * @param rhs is the other KeyValue to be compared with this
     * @return true if this.m_key < rhs.m_key, false otherwise
     */
    bool operator<(KeyValue<Comparable, ValType> const &rhs) const;

    bool operator<=(KeyValue<Comparable, ValType> const &rhs) const;

    bool operator>(KeyValue<Comparable, ValType> const &rhs) const;

    bool operator>=(KeyValue<Comparable, ValType> const &rhs) const;

    bool operator==(KeyValue<Comparable, ValType> const &rhs) const;

    bool operator!=(KeyValue<Comparable, ValType> const &rhs) const;

    bool operator<(Comparable const &key) const;

    bool operator>(Comparable const &key) const;

    bool operator==(Comparable const &key) const;

    bool operator<=(Comparable const &key) const;

    bool operator>=(Comparable const &key) const;

    bool operator!=(Comparable const &key) const;

    void operator=(KeyValue<Comparable, ValType> const &rhs) const;

private:
    Comparable m_key;
    ValType m_value;
};

template<typename Comparable, typename ValType>
KeyValue<Comparable, ValType>::KeyValue(Comparable const &key, ValType const &value): m_key(key), m_value(value) {}

template<typename Comparable, typename ValType>
KeyValue<Comparable, ValType>::KeyValue(KeyValue const &k): m_key(k.getKey()), m_value(k.getValue()) {}

template<typename Comparable, typename ValType>
bool KeyValue<Comparable, ValType>::operator<(KeyValue<Comparable, ValType> const &rhs) const {
    return this->getKey() < rhs.getKey();
}

template<typename Comparable, typename ValType>
bool KeyValue<Comparable, ValType>::operator>(KeyValue<Comparable, ValType> const &rhs) const {
    return this->getKey() > rhs.getKey();
}

template<typename Comparable, typename ValType>
bool KeyValue<Comparable, ValType>::operator<=(KeyValue<Comparable, ValType> const &rhs) const {
    return (this->getKey() <= rhs.getKey());
}

template<typename Comparable, typename ValType>
bool KeyValue<Comparable, ValType>::operator>=(KeyValue<Comparable, ValType> const &rhs) const {
    return (this->getKey() >= rhs.getKey());
}

template<typename Comparable, typename ValType>
bool KeyValue<Comparable, ValType>::operator==(KeyValue<Comparable, ValType> const &rhs) const {
    return (this->getKey() == rhs.getKey());
}

template<typename Comparable, typename ValType>
void KeyValue<Comparable, ValType>::operator=(KeyValue<Comparable, ValType> const &rhs) const {
    m_key = rhs.getKey();
    m_value = rhs.getValue();
}

template<typename Comparable, typename ValType>
bool KeyValue<Comparable, ValType>::operator!=(KeyValue<Comparable, ValType> const &rhs) const {
    return this->getKey() != rhs.getKey();
}

template<typename Comparable, typename ValType>
bool KeyValue<Comparable, ValType>::operator<(const Comparable &key) const {
    return this->getKey() < key;
}

template<typename Comparable, typename ValType>
bool KeyValue<Comparable, ValType>::operator>(const Comparable &key) const {
    return this->getKey() > key;
}

template<typename Comparable, typename ValType>
bool KeyValue<Comparable, ValType>::operator==(const Comparable &key) const {
    return this->getKey() == key;
}

template<typename Comparable, typename ValType>
bool KeyValue<Comparable, ValType>::operator<=(const Comparable &key) const {
    return this->getKey() <= key;
}

template<typename Comparable, typename ValType>
bool KeyValue<Comparable, ValType>::operator>=(const Comparable &key) const {
    return this->getKey() >= key;
}

template<typename Comparable, typename ValType>
bool KeyValue<Comparable, ValType>::operator!=(const Comparable &key) const {
    return this->getKey() != key;
}


#endif //GENERICDICTIONARY_KEYVALUE_H
