//
// Created by Stephen Clyde on 2/16/17.
//

#ifndef BINGO_DECK_H
#define BINGO_DECK_H

#include <ostream>
#include <vector>
#include "Card.h"

// TODO: Extend this definition as you see fit

class Deck {

public:
    Deck(int cardSize, int cardCount, int numberMax);

    ~Deck();

    void print(std::ostream &out) const;

    void print(std::ostream &out, int cardIndex) const;

    int getCardSize() const { return m_cardSize; }

    int getCardCount() const { return m_cardCount; }

    int getNumberMax() const { return m_numberMax; }

private:
    int m_cardSize;
    int m_cardCount;
    int m_numberMax;

    std::vector<Card> m_cards;
};

#endif //BINGO_DECK_H
