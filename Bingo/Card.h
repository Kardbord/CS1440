//
// Created by Tanner on 2/21/2017.
//

#ifndef BINGO_CARD_H
#define BINGO_CARD_H


#include <vector>
#include "CardCell.h"

class Card {

public:
    Card(int const &cardSize, int const &numberMax);

    int getCardSize() const { return m_cardSize; }

    int getNumberMax() const { return m_numberMax; }

    std::vector<int> getPossNums() const { return m_possNums; }

    std::vector<CardCell> getCells() const { return m_cells; }

private:
    int m_cardSize;
    int m_numberMax;
    std::vector<CardCell> m_cells;
    std::vector<int> m_possNums;
};


#endif //BINGO_CARD_H
