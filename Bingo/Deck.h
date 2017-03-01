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
    Deck(int const &cardSize, int const &cardCount, int const &numberMax);

    ~Deck();

    void print(std::ostream &out) const;

    void print(std::ostream &out, int cardIndex) const;

    int getCardSize() const { return m_cardSize; }

    int getCardCount() const { return m_cardCount; }

    int getNumberMax() const { return m_numberMax; }

    std::vector<Card> getCards() { return m_cards; }

private:

    int m_cardSize;
    int m_cardCount;
    int m_numberMax;

    /**
     * m_charsPerCell is the amount of monospace characters needed to represent the biggest cell
     * we need to deal with, in this case, a number consisting of no more than 3
     * digits plus a space on either side and a '|' on either side needs 7 spaces
     */
    int m_charsPerCell;

    std::vector<Card> m_cards;

    // Private member functions

    void printHelper(std::ostream &out, bool isFirst, bool isLast, bool isSpacer) const;
};

#endif //BINGO_DECK_H
