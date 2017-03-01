//
// Created by Stephen Clyde on 2/16/17.
//

#ifndef BINGO_DECK_H
#define BINGO_DECK_H

#include <ostream>
#include <vector>
#include "Card.h"

class Deck {

public:
    Deck(int const &cardSize, int const &cardCount, int const &numberMax);

    ~Deck();

    void print(std::ostream &out) const;

    void print(std::ostream &out, int cardIndex) const;

    int getCardSize() const { return m_cardSize; }

    int getCardCount() const { return m_cardCount; }

    int getNumberMax() const { return m_numberMax; }

    std::vector<Card> getCards() const { return m_cards; }

private:

    int m_cardSize;
    int m_cardCount;
    int m_numberMax;

    /**
     * m_charsPerCell is the amount of monospace characters needed to represent the biggest cell
     * we need to deal with, for example, a number consisting of no more than 3
     * digits can be displayed as follows:
     *
     * a space (to look pretty), +1 monospace character
     * the number, which is at most 3 digits wide, +3 monospace characters
     * another space for prettiness, +1 monospace character
     * a '|' to separate the cell from its neighbor, +1 monospace character
     *
     * This gives us 6 monospace characters for a cell if m_numberMax < 1000
     *
     * Note: when printing we, also have to take into account the need for a '|' at the
     * beginning of a line, but this is left out of the character count for a cell as it leads to
     * incorrect arithmetic. It is easier to just hard code it in, which is done in printHelper
     */
    int m_charsPerCell;

    std::vector<Card> m_cards;

    // Private member functions

    void printHelper(std::ostream &out, bool isFirst, bool isLast, bool isSpacer) const;
};

#endif //BINGO_DECK_H
