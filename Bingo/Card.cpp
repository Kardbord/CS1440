//
// Created by Tanner on 2/21/2017.
//

#include <algorithm>
#include "Card.h"

Card::Card(int const &cardSize, int const &numberMax) : m_cardSize(cardSize), m_numberMax(numberMax) {

    for (int i = 1; i <= m_numberMax; ++i) {
        m_possNums.push_back(i);
    }

    std::random_shuffle(m_possNums.begin(), m_possNums.end());

    int totCells = m_cardSize * m_cardSize;
    for (int i = 0; i < totCells; ++i) {
        m_cells.push_back(CardCell(m_possNums[i]));
    }
}

Card::~Card() {
    m_cells.clear();
    m_cells.shrink_to_fit();
    m_possNums.clear();
    m_possNums.shrink_to_fit();
}
