//
// Created by Tanner on 2/21/2017.
//

#ifndef BINGO_CARD_H
#define BINGO_CARD_H


#include <vector>
#include "CardCell.h"

class Card {

public:
    Card(int const & cardSize, int const & numberMax);

    int getCardSize() { return m_cardSize; }

    int getNumberMax() { return m_numberMax; }

private:
    int m_cardSize;
    int m_numberMax;
    std::vector<CardCell> m_cells;
    std::vector<int> m_possNums;
};


#endif //BINGO_CARD_H
