//
// Created by Tanner on 2/21/2017.
//

#include <cstdlib>
#include "Card.h"

Card::Card(int const & cardSize, int const & numberMax) : m_cardSize(cardSize), m_numberMax(numberMax) {
    int totCells = m_cardSize * m_cardSize;
    for (int i = 0; i < totCells; ++i){
        m_cells.push_back(CardCell(std::rand() % m_numberMax));
    }
}